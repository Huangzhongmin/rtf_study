/*
 * Project       : Real-Time Framework
 *
 * Description   : RfmSingleWrite function block implementation
 *
 * Author        : zhongmin.huang
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

#ifndef RTF_BLOCK_RFM_SINGLE_WRITE_H_
#define RTF_BLOCK_RFM_SINGLE_WRITE_H_

#include <string>

#include "rtf/block.h"
#include "rfm2g_api.h"

#define TEST_RFM
#ifndef TEST_RFM
#include "east_rfm_index.h"
#else
#include <unordered_map>
unordered_map<std::string,int> east_rfm_index={
{test0,0},
{test1,1}
}
#endif

namespace rtf {
namespace block {

/**
 * @brief RfmSingleWrite function block.
 */
template <typename T>
class RfmSingleWrite : public FunctionBlock {
 public:
  /**
   * @brief Initialize RfmSingleWrite function block.
   */
  explicit RfmSingleWrite(const BlockConfigurator& configurator);

  /**
   * @see FunctionBlock::process()
   * @brief Function block processing function.
   * @details Returns true if the function block has finished processing for given cycle.
   */
  bool process() override;

 private:
  Parameter<std::string> channel_; // name mapping to offset
  InputPort<T> in_;           // number to write to rfm

  RFM2G_HANDLE hndl;
};

template <typename T>
RfmSingleWrite<T>::RfmSingleWrite(const BlockConfigurator& configurator) : FunctionBlock(configurator) {
  // Function block initialization example
  initParameter("Channel", channel_, configurator, std::string("test0"));
  initInputPort("In", in_, configurator);
  
  open
}

template<typename T>
bool RfmSingleWrite<T>::process() {
  // Function block processing function example
  *out_ = *in_ * *gain_;
  return true;
}

/**
 * @brief Registers the factory.
 *
 * @param registrar Factory registrar on which to register the factory.
 */
void registerRfmSingleWriteFactory(FactoryManager* registrar);

}   //  namespace block
}   //  namespace rtf

#endif  // RTF_BLOCK_RFM_SINGLE_WRITE_H_

