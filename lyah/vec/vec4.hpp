// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "vec/vec.hpp"
#include "convert.hpp"
#include "types.hpp"

namespace lyah {
	template<typename T>
	struct vec<4, T> {
		using __m_t = typename internal::vec_t<4, T>::__m_t;

		__m_t m;

		LYAH_NODISCARD vec();
		LYAH_NODISCARD vec(T x, T y, T z, T w);
		LYAH_NODISCARD LYAH_CONSTEXPR explicit vec(__m_t m);

		template<typename U>
		LYAH_NODISCARD explicit vec(vec<4, U> a) : m(internal::convert<typename vec<4, U>::__m_t, __m_t>(a.m)) {}

		LYAH_NODISCARD T LYAH_CALL operator [](std::size_t index) const LYAH_NOEXCEPT;
	};
}

#include "vec/vec4_m128.inl"
#include "vec/vec4_m256d.inl"