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

#include "FileWriter.h"

namespace rtf {
namespace block {

void registerFileWriterFactory(FactoryManager* registrar) {
  registrar->registerFactory(Factory<FunctionBlock, FileWriter<uint32_t>>("FileWriter<uint32>"));
  registrar->registerFactory(Factory<FunctionBlock, FileWriter<float64_t>>("FileWriter<float64>"));
}

}   //  namespace block
}   //  namespace rtf