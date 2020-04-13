/*
 * Project       : Real-Time Framework
 *
 * Description   : Vector function block implementation
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

#ifndef RTF_BLOCK_PVECTOR_H_
#define RTF_BLOCK_PVECTOR_H_

#include <vector>
#include <string>

#include "rtf/block.h"

namespace rtf {
namespace block {

/**
 * @brief Vector function block.
 */
template <typename T>
class Pvector : public FunctionBlock {
 public:
  /**
   * @brief Initialize Vector function block.
   */
  explicit Pvector(const BlockConfigurator& configurator);

  /**
   * @see FunctionBlock::process()
   * @brief Function block processing function.
   * @details Returns true if the function block has finished processing for given cycle.
   */
  bool process() override;

 private:
  Parameter<int32_t> size_;
  InputPortVector<T> in_;           //!< Input port example
  OutputPortVector<T> out_;         //!< Output port example
};

template <typename T>
Pvector<T>::Pvector(const BlockConfigurator& configurator) : FunctionBlock(configurator) {
  // Function block initialization example
  initParameter("Size",size_,configurator,5);
  initInputPortVector("In", in_, *size_,configurator);
  initOutputPortVector("Out", out_, *size_,configurator);
}

template<typename T>
bool Pvector<T>::process() {
  // Function block processing function example
    for(int i=0;i!=*size_;++i){
        std::cout<<*(in_[i])<<std::endl;
        // out_[i]=in_[i];
    }

  // *out_ = *in_ ;
  return true;
}

/**
 * @brief Registers the factory.
 *
 * @param registrar Factory registrar on which to register the factory.
 */
void registerPvectorFactory(FactoryManager* registrar);

}   //  namespace block
}   //  namespace rtf

#endif  // RTF_BLOCK_VECTOR_H_

