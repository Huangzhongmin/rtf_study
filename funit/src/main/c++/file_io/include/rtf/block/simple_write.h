/*
 * Project       : Real-Time Framework
 *
 * Description   : SimpleWrite function block implementation
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

#ifndef RTF_BLOCK_SIMPLE_WRITE_H_
#define RTF_BLOCK_SIMPLE_WRITE_H_

#include <sstream>
#include <chrono>
#include <time.h>
#include <string>
#include <fstream>

#include "rtf/block.h"

namespace rtf {
namespace block {

/**
 * @brief SimpleWrite function block.
 */
template <typename T>
class SimpleWrite : public FunctionBlock {
 public:
  /**
   * @brief Initialize SimpleWrite function block.
   */
  explicit SimpleWrite(const BlockConfigurator& configurator);

  /**
   * @see FunctionBlock::process()
   * @brief Function block processing function.
   * @details Returns true if the function block has finished processing for given cycle.
   */
  bool process() override;

 private:
  Parameter<std::string> path_; //target file
  Parameter<std::string> mode_;//file writemode
  InputPort<T> in_;           //!< Input port example
  OutputPort<T> out_;         //!< Output port example
};

template <typename T>
SimpleWrite<T>::SimpleWrite(const BlockConfigurator& configurator) : FunctionBlock(configurator) {
  // Function block initialization example

  auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::stringstream ss;
  ss<<std::put_time(std::localtime(&t),"%F-%T.dat");

  const std::string FILE_PATH(ss.str());//use system time as file name
  const std::string IO_MODE("a");//append to file tail

  initParameter("Path", path_, configurator,FILE_PATH);
  initParameter("Mode", mode_, configurator,IO_MODE);
  initInputPort("In", in_, configurator);
  initOutputPort("Out", out_, configurator);
}

template<typename T>
bool SimpleWrite<T>::process() {

 // select io mode
 if (0==mode_->compare("a")){
  std::ofstream fo(path_,std::ios::app);
  fo<<*in_<<std::endl;
  fo.close();
 }
  *out_=*in_;

  return true;
}

/**
 * @brief Registers the factory.
 *
 * @param registrar Factory registrar on which to register the factory.
 */
void registerSimpleWriteFactory(FactoryManager* registrar);

}   //  namespace block
}   //  namespace rtf

#endif  // RTF_BLOCK_SIMPLE_WRITE_H_

