/*
 * Project       : Real-Time Framework
 *
 * Description   : SimpleWrite function block tests
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

#include <gtest/gtest.h>
#include <sstream>

//  RTF includes

#include "rtf/model/service/service_generator.h"
#include "rtf/test/block_configurator_tester.h"
#include "rtf/test/time_provider_tester.h"
#include "rtf/test/signal_configurator_tester.h"

#include "rtf/block/simple_write.h"

using namespace rtf;
using namespace rtf::model;
using namespace rtf::block;
using namespace rtf::model::test;


template<typename Type>
void testSimpleWriteFunction(const std::string type_name, const Type& input, const float64_t& gain, const Type& output) {

  ResourceManager rm;
  FactoryManager fm;
  ServiceGenerator sm(fm);

  BlockConfiguratorTester config("FB_SimpleWrite", "SimpleWrite<" + type_name + ">", "H.P.T", rm, fm, sm);
  config.setParameterConfig("Gain", ParameterConfig(std::to_string(gain), true));
  config.setInputSignalConfig("In", 0, InputSignalConfig("in", ""));
  config.setOutputSignalConfig("Out", 0, "out");

  SimpleWrite simple_write_block(config);
  std::shared_ptr<TypedResource<Type>> input_storage;
  std::shared_ptr<TypedResource<Type>> output_storage;
  rm.requestOutputPortStorage<TypedResource<Type>>(ResourceIdentifier<std::string, std::string, std::string>("H.P.T", "",
  "in"), [&input_storage](std::shared_ptr<Resource> resource) {
    input_storage = std::static_pointer_cast<TypedResource<Type>>(resource);
  });

  rm.requestInputPortStorage<TypedResource<Type>>(ResourceIdentifier<std::string, std::string, std::string>("H.P.T", "",
  "out"), [&output_storage](std::shared_ptr<Resource> resource) {
    output_storage = std::static_pointer_cast<TypedResource<Type>>(resource);
  });

  rm.allocateStorage(SignalConfiguratorProviderTester());

  input_storage->set(input);
  EXPECT_TRUE(simple_write_block.process());
  EXPECT_EQ(output_storage->get(), output);
}

template<typename Type>
void testSimpleWriteSampleFunction(const std::string type_name, const Type& input, const float64_t& gain, const Type& output) {
  testSimpleWriteFunction<Sample<Type>>("Sample<" + type_name + ">",
    Sample<Type>(input, std::chrono::system_clock::now(), SampleQuality::kGood),
    gain,
    Sample<Type>(output, std::chrono::system_clock::now(), SampleQuality::kGood));
}


TEST(SimpleWrite, Basic) {
  testSimpleWriteFunction<float64_t>("float64", 100.0, 0.0, 0.0);
  testSimpleWriteFunction<uint64_t>("uint64", 10, 5, 50);
  testSimpleWriteSampleFunction<float64_t>("float64", -12.0, 0.5, -6.0);
  testSimpleWriteSampleFunction<uint64_t>("uint64", 12, 4, 48);
}

