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

#ifndef RTF_BLOCK_READ_SIG_H_
#define RTF_BLOCK_READ_SIG_H_

#include <string>
#include <mdsobjects.h>
#include <cstdlib>

#include "rtf/block.h"

namespace rtf {
namespace block {

/**
 * @brief ReadSig function block.
 */
inline char* s2c(const std::string & s){
    return const_cast<char*>(s.c_str());
}

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

 //MDSplus::Connection *conn;
  int size=-1;
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
/*
  try{
      MDSplus::Connection *con= new MDSplus::Connection(s2c(*server_));
      conn=con;
      conn->openTree(s2c(*tree_),*shot_);
  }
  catch(MDSplus::MdsException *exc){
      std::cerr<<"Error "<<exc->what()<<std::endl;
  }
*/
}

template<typename T>
bool ReadSig<T>::process() {
  // Function block processing function example
  std::cout<<"Retrieve data from "<<*server_<<"..."<<std::endl;
  std::cout<<"Tree: "<<*tree_<<std::endl;
  std::cout<<"Shot: "<<*shot_<<std::endl;
  std::cout<<"Signal: "<<*sig_name_<<std::endl;

  MDSplus::Connection *conn= new MDSplus::Connection("202.127.204.12");
      conn->openTree("pcs_east",81561);
 MDSplus::Data* data=conn->get("\\pcrl01");
  MDSplus::Data* timebase=conn->get("DIM_OF(pcrl01)");

  T* databuf=data->getFloatArray(&size);
  float* timebuf=timebase->getFloatArray(&size);

  deleteData(data);
  deleteData(timebase);
  conn->closeTree(s2c(*tree_),*shot_);

  std::cout<<size<<std::endl;

  delete databuf;
  delete timebuf;

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

