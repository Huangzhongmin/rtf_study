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

#include "rtf/block/pvector.h"

namespace rtf {
namespace block {

void registerPvectorFactory(FactoryManager* registrar) {
  registrar->registerFactory(Factory<FunctionBlock, Pvector<float64_t>>("Pvector<float64>"));
}

}   //  namespace block
}   //  namespace rtf

