#pragma once
#include <numeric>

namespace formulas {
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

	/**
	 * \brief Calcul la somme des diviseurs 
	 */
	inline int sum_divisors(int p) {
		/* Version 1 que j'avais fait en premier lieux directement dans l'exercice 7 en pensant qu'il fallait afficher la liste entière des nombres diviseurs
		 * Au final, j'aurais pu faire la somme.
		std::vector<int> number_list;
		for(int j = 1 ; j < p; j++) {
			if(p % j == 0) {
				number_list.emplace_back(j);
			}
		}

		return std::accumulate(number_list.begin(), number_list.end(), 0) ;
		*/

		//Version 2 : https://www.dcode.fr/liste-diviseurs-nombre section "Comment calculer la liste des diviseurs d'un nombre N ?"
		int somme = 1;
		for(int i = 2 ; i <= std::sqrt(p) ; i++) {
			if(p % i == 0) {
				if(sqrt(p) != i) {
					somme += i;
					somme += p / i;
				} else {
					somme += i;
				}
			}
		}

		return somme;
	}
}
