/*
 * Project       : Real-Time Framework
 *
 * Description   : GenSample function block implementation
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

#ifndef RTF_BLOCK_PRINT_ARRAY_H_
#define RTF_BLOCK_PRINT_ARRAY_H_




#include <string>

#include "rtf/block.h"
#include "rtf/sample.h"

namespace rtf {
namespace block {

/**
 * @brief GenSample function block.
 */
template <typename T,int Size>
class PrintArray : public FunctionBlock {
 public:
  /**
   * @brief Initialize GenSample function block.
   */
  explicit PrintArray(const BlockConfigurator& configurator);

  /**
   * @see FunctionBlock::process()
   * @brief Function block processing function.
   * @details Returns true if the function block has finished processing for given cycle.
   */
  bool process() override;

 private:
  InputPort<ArraySample<T,Size>> in_;           //!< Input port example
};

template <typename T,int Size>
PrintArray<T,Size>::PrintArray(const BlockConfigurator& configurator) : FunctionBlock(configurator) {
//  initInputPort("In", in_, configurator);
}

template<typename T,int Size>
bool PrintArray<T,Size>::process() {

  (*in_).toStream(std::cout);
  return true;
}

/**
 * @brief Registers the factory.
 *
 * @param registrar Factory registrar on which to register the factory.
 */
void registerPrintArrayFactory(FactoryManager* registrar);

}   //  namespace block
}   //  namespace rtf

#endif  // RTF_BLOCK_SIMPLE_WRITE_H_

