/*
 * Project       : Real-Time Framework
 *
 * Description   : ReadSig function block implementation
 *
 * Author        : codac-dev
 *
 * Copyright (c) : 2017-2019 ITER Organization,
 *                 CS 90 046
 *                 13067 St. Paul-lez-Durance Cedex
 *                 France
 *
 * This file is part of ITER CODAC software.
 * For the terms and conditions of redistribution or use of this software
 * refer to the file ITER-LICENSE.TXT located in the top level directory
 * of the distribution package.
 */
#include <mdslib.h>
#include <mdsshr.h>

#define statusOK(status) ((status) & 1)

static int getSize(char* sigName)
{
    int dtype_long=DTYPE_LONG;
    int retSize;
    int lenDescr;
    int null=0;
    int status;
    char expression[1024];

    sprintf(expression,"SIZE(%s)",sigName);
    lenDescr=descr(&dtype_long,&retSize,&null);
    status=MdsValue(expression,&lenDescr,&null,0);

    if(!statusOK(status)){
        fprintf(stderr,"Error getting size of %s.\n",sigName);
        fprintf(stderr,"%s.\n",MdsGetMsg(status));
        return -1;
    }
    return retSize;
}

#ifndef RTF_BLOCK_READ_SIG_H_
#define RTF_BLOCK_READ_SIG_H_

#include <string>

#include "rtf/block.h"

namespace rtf {
namespace block {

/**
 * @brief ReadSig function block.
 */
template <typename T>
class ReadSig : public FunctionBlock {
 public:
  /**
   * @brief Initialize ReadSig function block.
   */
  explicit ReadSig(const BlockConfigurator& configurator);

  /**
   * @see FunctionBlock::process()
   * @brief Function block processing function.
   * @details Returns true if the function block has finished processing for given cycle.
   */
  bool process() override;

 private:
  Parameter<float64_t> gain_; //!< Parameter example
  InputPort<T> in_;           //!< Input port example
  OutputPort<T> out_;         //!< Output port example
  Parameter<std::string> server_;
  Parameter<std::string> sig_name_;
  Parameter<std::string> tree_;
  Parameter<int32_t> shot_;

  int socket;
  int status;
  int size;
  int shot;

  T* data;
  T* timebase;
  int sigDescr;
  int timeDescr;

};

template <typename T>
ReadSig<T>::ReadSig(const BlockConfigurator& configurator) : FunctionBlock(configurator) {
  // Function block initialization example
  initParameter("Gain", gain_, configurator, 2.0);
  initInputPort("In", in_, configurator);
  initOutputPort("Out", out_, configurator);

  const std::string dserver ("202.127.204.12");
  initParameter("Server",server_,configurator,dserver);

  const std::string dtree ("pcs_east");
  initParameter("Tree",tree_,configurator,dtree);

  const std::string dsigname ("\\pcrl01");
  initParameter("SigName",sig_name_,configurator,dsigname);

  initParameter("Shot",shot_,configurator,81561);
  shot=*shot_;

  socket=MdsConnect(const_cast<char*>((*server_).c_str()));
    if(socket==-1)
        std::cerr<<"Error Connecting: "<<*server_<<std::endl;
    else
        std::cout<<"Connected to :"<<*server_<<std::endl;
  status=MdsOpen(const_cast<char*> ((*tree_).c_str()),&shot);
  if(!statusOK(status))
    std::cerr<<"Error Opening "<<shot<<"shot "<<"in tree:"<<*tree_<<std::endl;
  else
    std::cout<<"Opened :"<<shot<<" in "<<*tree_<<std::endl;

  size=getSize(const_cast<char*>((*sig_name_).c_str()));
//std::cout<<size<<std::endl;

  data = (T *)malloc(size*sizeof(T));i
  if(!data)
      std::cerr<<"Error allocating memory for data.";
  timebase = (T *)malloc(size*sizeof(T));
  if(!timebase){
      std::cerr<<"Error allocating memory for timebase.";
      free()(void*)data);
  }

}

template<typename T>
bool ReadSig<T>::process() {
  // Function block processing function example
  *out_ = *in_ * *gain_;
  return true;
}

/**
 * @brief Registers the factory.
 *
 * @param registrar Factory registrar on which to register the factory.
 */
void registerReadSigFactory(FactoryManager* registrar);

}   //  namespace block
}   //  namespace rtf

#endif  // RTF_BLOCK_READ_SIG_H_

