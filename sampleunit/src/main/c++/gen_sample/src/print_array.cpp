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

#include "rtf/block/print_array.h"

namespace rtf {
namespace block {

void registerPrintArraFactory(FactoryManager* registrar) {
  registrar->registerFactory(Factory<FunctionBlock, PrintArray<float64_t,10>>("PrintArray<float64,10>"));
}

}   //  namespace block
}   //  namespace rtf

