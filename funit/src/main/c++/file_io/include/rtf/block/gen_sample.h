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

#ifndef RTF_BLOCK_SIMPLE_WRITE_H_
#define RTF_BLOCK_SIMPLE_WRITE_H_




#include <string>

#include "rtf/block.h"
#include "rtf/sample.h"

namespace rtf {
namespace block {

/**
 * @brief GenSample function block.
 */
template <typename T>
class GenSample : public FunctionBlock {
 public:
  /**
   * @brief Initialize GenSample function block.
   */
  explicit GenSample(const BlockConfigurator& configurator);

  /**
   * @see FunctionBlock::process()
   * @brief Function block processing function.
   * @details Returns true if the function block has finished processing for given cycle.
   */
  bool process() override;

 private:
  Parameter<int32_t> quality_; //samplequality
  InputPort<T> in_;           //!< Input port example
  OutputPort<Sample<T>> out_;         //!< Output port example
};

template <typename T>
GenSample<T>::GenSample(const BlockConfigurator& configurator) : FunctionBlock(configurator) {

  initParameter("Quality",quality_,configurator,0);
  initInputPort("In", in_, configurator);
  initOutputPort("Out", out_, configurator);
}

template<typename T>
bool GenSample<T>::process() {

  rtf::Sample<T> sample_point;

  switch(quality_){
    case 0:sample_point.setQuality(rtf::SampleQuality::kGood);break;
    case 1:sample_point.setQuality(rtf::SampleQuality::kInvalid);break;
    case 2:sample_point.setQuality(rtf::SampleQuality::kDataIntegrationError);break;
  }
  sample_point.setTimestamp(getTimePoint());
  sample_point.setValue(in_);
  out_=sample_point;

  return true;
}

/**
 * @brief Registers the factory.
 *
 * @param registrar Factory registrar on which to register the factory.
 */
void registerGenSampleFactory(FactoryManager* registrar);

}   //  namespace block
}   //  namespace rtf

#endif  // RTF_BLOCK_SIMPLE_WRITE_H_

