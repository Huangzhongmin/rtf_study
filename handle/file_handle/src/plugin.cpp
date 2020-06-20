//
// Project       : Real-Time Framework
//
// Description   : Library plugin implementation
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
///

#include "FileWriter.h"
#include "rtf/factory_manager.h"

namespace rtf {
namespace block {

extern "C"
void registerFactories(FactoryManager* registrar) {
  registerFileWriterFactory(registrar);
}

}  // namespace block
}  // namespace rtf
