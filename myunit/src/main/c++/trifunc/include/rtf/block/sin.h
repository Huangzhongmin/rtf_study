/*
 * Project       : Real-Time Framework
 *
 * Description   : Sin function block implementation
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

#ifndef RTF_BLOCK_SIN_H_
#define RTF_BLOCK_SIN_H_

#include <string>
#include <math.h>

#include "rtf/block.h"

namespace rtf {
namespace block {

/**
 * @brief Sin function block.
 */
template <typename T>
class Sin : public FunctionBlock {
 public:
  /**
   * @brief Initialize Sin function block.
   */
  explicit Sin(const BlockConfigurator& configurator);

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
};

template <typename T>
Sin<T>::Sin(const BlockConfigurator& configurator) : FunctionBlock(configurator) {
  // Function block initialization example
  initParameter("Gain", gain_, configurator, 2.0);
  initInputPort("In", in_, configurator);
  initOutputPort("Out", out_, configurator);
}

template<typename T>
bool Sin<T>::process() {
  // Function block processing function example
  out_ = sin(in_) ;
  return true;
}

/**
 * @brief Registers the factory.
 *
 * @param registrar Factory registrar on which to register the factory.
 */
void registerSinFactory(FactoryManager* registrar);

}   //  namespace block
}   //  namespace rtf

#endif  // RTF_BLOCK_SIN_H_

