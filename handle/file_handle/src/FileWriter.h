//
// Project       : Real-Time Framework
//
// Description   : FileWriter function block implementation
//
// Author        : bauvirb
//
// Copyright (c) : 2017-2020 ITER Organization,
//                 CS 90 046
//                 13067 St. Paul-lez-Durance Cedex
//                 France
//
// This file is part of ITER CODAC software.
// For the terms and conditions of redistribution or use of this software
// refer to the file ITER-LICENSE.TXT located in the top level directory
// of the distribution package.

#ifndef _FileWriter_h_
#define _FileWriter_h_

#include <fstream>
#include <string>

#include "rtf/block.h"

namespace rtf {
namespace block {
/// @brief FileWriter function block.
/// @detail Outputs the product of all input signals.
template <typename Type> class FileWriter : public FunctionBlock {

 public:
  ////
  /// @brief Initialize FileWriter function block.
  ///
  explicit FileWriter(const BlockConfigurator& configurator);
  virtual ~FileWriter();

  ////
  /// @see FunctionBlock::process()
  /// @brief Function block processing method.
  /// @details Returns true if the function block has finished processing for given cycle.
  ///
  bool process() override;

  void reset() override;

 private:
  ////
  /// @brief Input parameters.
  ///
  Parameter<std::string> file_;  //!< File path

  ////
  /// @brief Inputs.
  ///
  InputPortVector<Type> inp_; //!< Input signal

  ////
  /// @brief Internal parameters.
  ///
  uint32_t num_; //!< Number of input signals
  std::ofstream data_;

};

template <typename Type> FileWriter<Type>::FileWriter(const BlockConfigurator& configurator) : FunctionBlock(configurator) {
  // Parameters
  initParameter("FilePath", file_, configurator, std::string("/tmp/data.log"));

  // Input signals
  initInputPortVector(kDefaultInputPortName, inp_, configurator);

  // Output signals

  num_ = inp_.size();
  logNonTrivial(LogLevel::FINE, "FileWriter<Type>::FileWriter - Number of inputs '", num_, "'.");

  // Acquire resources
  data_.open(file_, { std::ios::out | std::ios::trunc });

}

template<typename Type> FileWriter<Type>::~FileWriter() {
  data_.close();
}

template <typename Type> bool FileWriter<Type>::process() {
  log(LogLevel::FINE, "Writing to file from FileWriter");
  // Algorithm
  uint32_t index; 

  for (index = 0u; index < num_; index += 1u)
    {
      data_ << inp_[index];
    if (index < num_ - 1u)
      data_ << ", ";
    else
      data_ << std::endl;
  }

  return true;
}

template <typename Type>
void FileWriter<Type>::reset() {}
/// @brief Registers the factory.
/// @param registrar Factory registrar on which to register the factory.
void registerFileWriterFactory(FactoryManager* registrar);

}  //  namespace block
}   //  namespace rtf

#endif  // _FileWriter_h_