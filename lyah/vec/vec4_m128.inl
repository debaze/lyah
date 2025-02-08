namespace lyah {
	// NOTE: SSE
	template<>
	LYAH_INLINE vec<4, std::float_t>::vec() : m(_mm_setzero_ps()) {}

	// NOTE: SSE
	template<>
	LYAH_INLINE vec<4, std::float_t>::vec(std::float_t x, std::float_t y, std::float_t z, std::float_t w) : m(_mm_set_ps(w, z, y, x)) {}

	template<>
	LYAH_CONSTEXPR LYAH_INLINE vec<4, std::float_t>::vec(__m128 m) : m(m) {}

	// NOTE: SSE
	LYAH_INLINE std::float_t vec<4, std::float_t>::operator [](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 4);

		switch (index) {
			default:
			case 0: return _mm_cvtss_f32(m);
			case 1: return _mm_cvtss_f32(_mm_shuffle_ps(m, m, _MM_SHUFFLE(0, 0, 0, 1)));
			case 2: return _mm_cvtss_f32(_mm_shuffle_ps(m, m, _MM_SHUFFLE(0, 0, 0, 2)));
			case 3: return _mm_cvtss_f32(_mm_shuffle_ps(m, m, _MM_SHUFFLE(0, 0, 0, 3)));
		}
	}
}