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

#include "rtf/block/rfm_single_write.h"

namespace rtf {
namespace block {

void registerRfmSingleWriteFactory(FactoryManager* registrar) {
  registrar->registerFactory(Factory<FunctionBlock, RfmSingleWrite<Sample<float64_t>>>("RfmSingleWrite<Sample<float64>>"));
}

}   //  namespace block
}   //  namespace rtf

