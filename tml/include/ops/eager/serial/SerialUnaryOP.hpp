#pragma once

#include <algorithm>
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar, typename OP>
			void CustomSerialUnaryOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, OP&& op)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), op);
			}

			template<typename Scalar>
			void SerialAbs(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return std::abs(value); });
			}

			template<typename Scalar>
			void SerialCos(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(std::cos(value)); });
			}

			template<typename Scalar>
			void SerialCosh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(std::cosh(value)); });
			}

			template<typename Scalar>
			void SerialCot(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(1.0 / std::tan(value)); });
			}

			template<typename Scalar>
			void SerialExp(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(std::exp(value)); });
			}

			template<typename Scalar>
			void SerialLog(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(std::log(value)); });
			}

			template<typename Scalar>
			void SerialNeg(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(-value); });
			}

			template<typename Scalar>
			void SerialSin(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(std::sin(value)); });
			}

			template<typename Scalar>
			void SerialSinh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(std::sinh(value)); });
			}

			template<typename Scalar>
			void SerialSqrt(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(std::sqrt(value)); });
			}

			template<typename Scalar>
			void SerialSquare(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(value * value); });
			}

			template<typename Scalar>
			void SerialTan(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(std::tan(value)); });
			}

			template<typename Scalar>
			void SerialTanh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				std::transform(matrix.cbegin(), matrix.cend(), result.begin(), [](Scalar value) { return static_cast<Scalar>(std::tanh(value)); });
			}
		}
	}
}