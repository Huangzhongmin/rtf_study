/*
 * Project       : Real-Time Framework
 *
 * Description   : Mds_io plugin implementation
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

#include "rtf/block/read_sig.h"

#include "rtf/factory_manager.h"

namespace rtf {
namespace block {

extern "C"
void registerFactories(FactoryManager* registrar) {
  registerReadSigFactory(registrar);
}

}  // namespace block
}  // namespace rtf

