#pragma once

namespace maths {
	//https://en.wikipedia.org/wiki/Greatest_common_divisor#Using_Euclid's_algorithm
	/**
	 * \brief Calcul du plus grand diviseur commun
	 */
	inline int gcm(const int a, const int b) {
		return b == 0 ? a : gcm(b, a % b);
	}

	//https://en.wikipedia.org/wiki/Least_common_multiple#Reduction_by_the_greatest_common_divisor
	/**
	 * \brief Calcul du plus petit multiple commun
	 */
	inline int lcm(const int a, const int b) {
		return (a * b) / gcm(a,b);
	}

	//https://en.wikipedia.org/wiki/Primality_test#Pseudocode
	/**
	 * \brief Test pour savoir si un nombe est premier
	 */
	inline bool is_prime(const int p) {
		if(p <= 1) return false;
		if(p <= 3) return true;

		if(p % 2 == 0 || p % 3 == 0) return false;

		int i = 5;
		while( i * i <= p ) {
			if(p % i == 0 || p % (i + 2) == 0)
				return false;

			i += 6;
		}

		return true;
	}
}