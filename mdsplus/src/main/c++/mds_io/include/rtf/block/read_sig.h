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
  Parameter<std::string> server_;
  Parameter<std::string> sig_name_;
  Parameter<std::string> tree_;
  Parameter<int32_t> shot_;

  int shot;
  char server[128];
  char tree[128];
  char signaly[128];
  char signalx[128];

  int socket;
  int status;
  int size;
  T* data;
  T* timebase;
  int sigDesc;
  int timeDesc;
  int dtype_float=DTYPE_FLOAT;
  int null=0;
  int retLen;

};

template <typename T>
ReadSig<T>::ReadSig(const BlockConfigurator& configurator) : FunctionBlock(configurator) {
// initialize parameters
  const std::string dserver ("202.127.204.12");
  initParameter("Server",server_,configurator,dserver);

  const std::string dtree ("pcs_east");
  initParameter("Tree",tree_,configurator,dtree);

  const std::string dsigname ("\\pcrl01");
  initParameter("SigName",sig_name_,configurator,dsigname);

  initParameter("Shot",shot_,configurator,81561);

//convert constant variable
  strcpy(server,(*server_).c_str());
  strcpy(tree,(*tree_).c_str());
  strcpy(signaly,(*sig_name_).c_str());
  //strcpy(signalx,(*sig_name_).c_str());
  sprintf(signalx,"DIM_OF(%s)",signaly);
  shot=*shot_;
;

//connect to server and open tree
  socket=MdsConnect(server);
    if(socket==-1)
        std::cerr<<"Error Connecting: "<<server<<std::endl;
    else
        std::cout<<"Connected to :"<<server<<std::endl;
  status=MdsOpen(tree,&shot);
  if(!statusOK(status))
    std::cerr<<"Error Opening "<<shot<<"shot "<<"in tree:"<<tree<<std::endl;
  else
    std::cout<<"Opened :"<<shot<<" in "<<tree<<std::endl;

//retrieve buffer size
  size=getSize(signaly);

//initialize buffer
  data = (T *)malloc(size*sizeof(T));
  if(!data)
      std::cerr<<"Error allocating memory for data.";

  timebase = (T *)malloc(size*sizeof(T));
  if(!timebase){
      std::cerr<<"Error allocating memory for timebase.";
      free((void*)data);
  }

}

template<typename T>
bool ReadSig<T>::process() {
  // Function block processing function example
  std::cout<<"Retrieve data from "<<*server_<<"..."<<std::endl;
  std::cout<<"Tree: "<<*tree_<<std::endl;
  std::cout<<"Shot: "<<*shot_<<std::endl;
  std::cout<<"Signal: "<<*sig_name_<<std::endl;
  std::cout<<"Total sample points: "<<size<<std::endl;

  sigDesc=descr(&dtype_float,data,&size,&null);
  timeDesc=descr(&dtype_float,timebase,&size,&null);

  status=MdsValue(signaly,&sigDesc,&null,&retLen);
    if(!statusOK(status)){
        std::cerr<<"Error retrieving data:"<<MdsGetMsg(status)<<std::endl;
        free((void*)data);
        return -1;
    }
    status=MdsValue(signalx,&timeDesc,&null,&retLen);
    if(!statusOK(status)){
        std::cerr<<"Error retrieving timebase:"<<MdsGetMsg(status)<<std::endl;
        free((void*)data);
        free((void*)timebase);
        return -1;
    }

    for(retLen=0;retLen!=1000;++retLen)
        std::cout<<data[retLen]<<":"<<timebase[retLen]<<std::endl;
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

