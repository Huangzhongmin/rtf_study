/*
 * Project       : Real-Time Framework
 *
 * Description   : Matrix function block implementation
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

#ifndef RTF_BLOCK_MATRIX_H_
#define RTF_BLOCK_MATRIX_H_

#include <string>
#include <assert.h>
#include <vector>

#include "rtf/block.h"

namespace rtf {
namespace block {

/**
 * @brief Matrix function block.
 */
class Matrix : public FunctionBlock {
 public:
  /**
   * @brief Initialize Matrix function block.
   */
  explicit Matrix(const BlockConfigurator& configurator);

  /**
   * @see FunctionBlock::process()
   * @brief Function block processing function.
   * @details Returns true if the function block has finished processing for given cycle.
   */
  bool process() override;

 private:
  Parameter<int32_t> rows; //!< Parameter example
  Parameter<int32_t> cols; //!< Parameter example
  InputPort<T> in_;           //!< Input port example
  OutputPort<T> out_;         //!< Output port example

  std::vector<<std::vector<int>> mat;
  std::vector<double> buffer;
};

Matrix::Matrix(const BlockConfigurator& configurator) : FunctionBlock(configurator) {
  // Function block initialization example
  initParameter("Rows", rows, configurator, 2);
  initParameter("Cols", cols, configurator, 2);
  initInputPort("In", in_, configurator);
  initOutputPort("Out", out_, configurator);

  assert(*spacesize==*rows * *cols);

  std::vector<int32_t> size_init_mat(rows);
  mat.resize(cols,size_init_mat);
  buffer.resize(cols*rows,{});

}

bool Matrix::process() {
  // Function block processing function example

    return true;
}

/**
 * @brief Registers the factory.
 *
 * @param registrar Factory registrar on which to register the factory.
 */
void registerMatrixFactory(FactoryManager* registrar);

}   //  namespace block
}   //  namespace rtf

#endif  // RTF_BLOCK_MATRIX_H_

