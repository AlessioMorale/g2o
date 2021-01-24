#pragma once

#include <pybind11/pybind11.h>

#include "g2o/core/base_unary_edge.h"

namespace g2o {

template <int D, typename E, typename VertexXiType>
void templatedBaseUnaryEdge(pybind11::module& m, const std::string& suffix) {
  using CLS = BaseUnaryEdge<D, E, VertexXiType>;

  templatedBaseFixedSizedEdge<D, E, VertexXiType>(m, suffix);

  pybind11::class_<CLS, BaseFixedSizedEdge<D, E, VertexXiType>, BaseEdge<D, E>>(
      m, ("BaseUnaryEdge" + suffix).c_str())
      /*
      .def_readwrite("jacobian_oplus_xi",
                     &CLS::template jacobianOplusXn<0>())  // -> JacobianXiOplusType&
      */
      ;
}

}  // end namespace g2o
