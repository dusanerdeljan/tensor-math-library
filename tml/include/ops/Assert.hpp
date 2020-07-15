#pragma once

#ifdef _DEBUG

#include <exception>

#define TML_ASSERT_SHAPE(left, right)\
{\
if (left.get_shape() != right.get_shape())\
{\
throw std::runtime_error("YOU MIXED MATRICES OF DIFFERENT SHAPE.");\
}\
}

#define TML_ASSERT_RESHAPE(matrix, shape)\
{\
if (matrix.get_shape().size != shape.size)/
{\
throw std::runtime_error("RESHAPE ERROR: INCOMPATIBLE SHAPE.");\
}\
}

#define TML_ASSERT_MATMUL(left, right)\
{\
if (left.get_shape().columns != right.get_shape().rows)\
{\
throw std::runtime_error("YOU MIXED MATRICES OF INCOMPATIBLE SHAPES.");\
}\
}

#else
#define TML_ASSERT_SHAPE(left, right)

#define TML_ASSERT_RESHAPE(left, right)

#define TML_ASSERT_MATMUL(left, right)

#endif // _DEBUG