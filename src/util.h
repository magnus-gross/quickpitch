#ifndef UTIL_H
#define UTIL_H

#include <cmath>
#include <memory>
#include <algorithm>

namespace Util {
	template<typename T>
	int round(T arg) {
#ifdef ANDROID
		return static_cast<int>(arg + 0.5);
#else
		return std::round(arg);
#endif
}

	template<typename T>
	constexpr T log2(T arg) {
#ifdef ANDROID
		return std::log(arg) / std::log(2.f);
#else
		return std::log2(arg);
#endif
	}

	template<typename Cnt_T, typename UnaryFunction>
	UnaryFunction for_each(Cnt_T &cnt, UnaryFunction f) {
		return std::for_each(std::begin(cnt), std::end(cnt), f);
	}
}

#endif // UTIL_H
