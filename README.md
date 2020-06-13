# tensor-math-library
Header only lazy evaluation tensor math library with multi-backend parallel eager execution support (TBB, OpenMP, Parallel STL and in the future CUDA and OpenCL). For now, TML only supports matrix math.

## Future improvements

 * CUDA and OpenCL parallel backends
 * Temp-free eager execution
 * Tensor extension with autograd
 * Support for fixed-sized stack allocated matrices and tensors

## Lazy evaluation

Lazy evaluation means that an expression is evaluated as late as possible, meaning an expression will be evaluated when assigned to Matrix object. All the lazy evaluation functions live in ```tml::lazy``` namespace and all the overloaded operators are also lazily evaluated.

```cpp
#include "include/tml.hpp"

int main() 
{
  tml::Matrix<double> m1 = tml::Matrix<double>::Arange(10, 10);
  tml::Matrix<double> m2 = tml::Matrix<double>::Arange(10, 10);
  auto res = m1 + m2 + tml::lazy::Log(2.0 + m1) * tml::lazy::Sin(m2);
  return 0;
}
```
The type of variable `res` is not Matrix, it is ExprOP<double, T> and nothing has been computed. This expression is computed only when you assign it to a Matrix type variable and no temporary objects are created. 

Now the expression is computed:
```cpp
tml::Matrix<double> res = m1 + m2 + tml::lazy::Log(2.0 + m1) * tml::lazy::Sin(m2);
```

To illustrate how the above expression is being evaluated, you can imagine it as a single for loop which is being exucted in parallel (if at least one parallel backend is supported).
```cpp
typedef tml::Matrix<double>::const_iterator iter;
auto resIt = res.begin();
for (iter it1 = m1.cbegin(), it2 = m2.cbegin(); it1 != m1.cend(); ++it1, ++it2, ++resIt)
  *resIt = *it1 + *it2 + std::log(2.0 + *it1) * std::sin(*it2);
```

### Potential errors

All the parameters in lazy expressions are captured by reference so you have to keep an eye on the objects lifetime. For example, consider the following function:

```cpp
template<typename T>
auto WrongExample(const ExprOP<double, T>& expression)
{
	tml::Matrix<double> temp = tml::Matrix<double>::Arange(10, 10);
	return expression + temp;
}
```
The problem with above function is that variable `temp` is destroyed at the end of the function, and is being captued by reference in the `expression + temp` lazy expression object, which can result in undefined behaviour.

## Parallel eager execution

TML also offers the ability to evaluate expressions eagerly. All the eager evaluation functions live in ```tml::eager``` namespace.
When using functions from ```tml::eager``` namespace, user can specify the execution policy (serial or parallel execution), where serial execution is the default option. 

It is important to mention that any lazy expression object that is passed to the eager function will be evaluated in the body of the function, and thus a temporary variable will be created.

### Example usage of eager functions

```cpp
auto res = tml::eager::Matmul(m1, m2, tml::execution::tbb); // now res is of type tml::Matrix<double>
auto res = tml::eager::Matmul(m1, m2, tml::execution::omp); // now res is of type tml::Matrix<double>
auto res = tml::eager::Matmul(m1, m2, tml::execution::stl); // now res is of type tml::Matrix<double>
```

### Combination of lazy and eager functions

```cpp
auto res = tml::eager::Matmul(m1, m2 + 1.0 + tml::lazy::Square(m2), tml::execution::tbb);
```
In the above example expression `m2 + 1.0 + tml::lazy::Square(m2)` is evaluated lazily and the matrix product is then eagerly executed in parallel.

## Compilation

TML has been tested on Windows 10 (MSVC2015 and MSVC2019) and Linux Ubuntu 18.04 and 20.04 operating systems.

### Preprocessor options

 * TML_HAS_TBB - Macro tells TML that Thread Building Blocks library is available
 * TML_HAS_OMP - Macro tells TML that OpenMP support is enabled
 * TML_HAS_CPP17_STL - Macro tells TML that language standard is set to C++ 17

#### MSVC 2015 or above and Intel C++ compiler

 * Make sure to set language standard to C++ 11 or higher (preferably C++ 17)
 * In the preprocessor definitions tab define macros as explained above (if you are compiling in debug then also define _SCL_SECURE_NO_WARNINGS)
 * Enable OpenMP support and enhanced instruction sets (preferably AVX2)
 * Configure optimizations and other options at will
 
#### g++ 9 or above

Example compilation command:
```
 g++ Main.cpp -std=c++17 -ltbb -fopenmp -O3 -D TML_HAS_TBB -D TML_HAS_OMP -D TML_HAS_CPP17_STL
```
