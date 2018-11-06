#include "Chapter1.h"
#include <complex>
#include <numeric>

#include "formulas.h"
#include <set>

void Chapter1::init() {
	chapter_definition = "Problemes de math.";

	exercises_definitions.emplace_back("Somme des entiers divisibles par 3 et 5");
	exercises_definitions.emplace_back("Plus grand denominateur commun entre deux entiers");
	exercises_definitions.emplace_back("Plus petit multiplieur commun entre deux ou plusieurs entiers");
	exercises_definitions.emplace_back("Nombre premier le plus grand, plus petit que le nombre rentre en parametre");
	exercises_definitions.emplace_back("Liste des paires de nombres sexy jusqu'a une valeur donnee");
	exercises_definitions.emplace_back("Nombres abondants et son abondance jusqu'a une valeur donnee");
	exercises_definitions.emplace_back("Nombres amicaux jusqu'a 1 000 000");
	exercises_definitions.emplace_back("Nombre d'Amstrong a 3 chiffres");
	exercises_definitions.emplace_back("Decomposition en nombres premiers");

	exercises_functions.emplace_back(exercice1);
	exercises_functions.emplace_back(exercice2);
	exercises_functions.emplace_back(exercice3);
	exercises_functions.emplace_back(exercice4);
	exercises_functions.emplace_back(exercice5);
	exercises_functions.emplace_back(exercice6);
	exercises_functions.emplace_back(exercice7);
	exercises_functions.emplace_back(exercice8);
	exercises_functions.emplace_back(exercice9);
}

Chapter1::Chapter1() {
	Chapter1::init();
}

void Chapter1::exercice1() {
	std::cout << "Selectionnez un nombre limite : ";

	int limite;
	do {
		std::cin >> limite;

		if(limite < 0) {
			std::cout << "Entrez un nombre superieur a 0." << std::endl;
		}
		
	} while (limite < 0);

	int count = 0;
	for (int i = 0; i <= limite; ++i) {
		if(i % 3 == 0 || i % 5 == 0)
			count += i;
	}

	std::cout << "Somme des entiers = " << count << std::endl;
}

void Chapter1::exercice2() {
	int premier_div = 0;
	std::cout << "Selectionnez un premier nombre positif : ";
	std::cin >> premier_div;

	premier_div = std::abs(premier_div);

	int second_div = 0;
	std::cout << "Selectionnez un second nombre positif : ";
	std::cin >> second_div;

	second_div = std::abs(second_div);

	int result = 0;

	if(premier_div > second_div)	
		result = formulas::gcm(premier_div, second_div);
	else
		result = formulas::gcm(second_div, premier_div);

	std::cout << "Plus grand denominateur commun : " << result << std::endl;
}

void Chapter1::exercice3() {
	int input = 0;

	std::vector<int> entiers;
	do {
		std::cout << "Entrez un entier ou - 1 pour arreter : ";
		std::cin >> input;

		if(input != - 1)
			entiers.push_back(input);

	} while (input != -1);

	/* Première version
	for(unsigned int i = 0 ; i < entiers.size() - 1; i++) {
		entiers[i + 1] = formulas::lcm(entiers[i], entiers[i + 1]);
	}

	std::cout << "Plus petit multiple commun : " + std::to_string(entiers.back()) << std::endl;
	*/

	//Seconde version
	std::cout << "Plus petit multiple commun : " << std::accumulate(entiers.begin() + 1, entiers.end(), entiers.front(), formulas::lcm) << std::endl;

	entiers.clear();
}

void Chapter1::exercice4() {
	int input = 0;

	std::cout << "Entrez un nombre positif : " ;
	std::cin >> input;

	input = std::abs(input);

	if(input % 2 == 0) {
		input--;
	}

	int result = 0;
	for(int i = input ; i > 0 ; i -= 2) {
		if(formulas::is_prime(i)) {
			result = i;
			break;
		}
	}

	std::cout << "Le plus petit nombre premier est " << result << std::endl;
}

void Chapter1::exercice5() {
	int input = 0;
	std::cout << "Entrez un nombre positif : ";
	std::cin >> input;

	std::cout << "Liste des nombres premiers sexy jusqu'a " << input << " : " << std::endl;
	for(int i = 0 ; i <= input ; i++) {
		if(formulas::is_prime(i) && formulas::is_prime(i + 6)) {
			std::cout << "(" << i << "," << i + 6 << ")" << std::endl;
		}
	}
}

void Chapter1::exercice6() {
	int input = 0;
	std::cout << "Entrez un nombre positif : ";
	std::cin >> input;

	if(input < 12) {
		std::cout << "Il n'existe pas de nombre abondants avant 12." << std::endl;
	} else {
		for(int i = 12 ; i <= input ; i++) {
			const int somme = formulas::sum_divisors(i);
			if(somme > i) {
				std::cout << "Nombre abondants " << i << ". Abondance : " << somme - i << std::endl;
			}
		}
	}
}

void Chapter1::exercice7() {
	/* 
	 * https://www.dcode.fr/liste-diviseurs-nombre section "Que sont les nombres amicaux ?"
	 * 220 et 284 sont amicaux :
	 * sum_div(220) = 284 et sum_div(284) = 220
	 */
	constexpr int max = 1000000;
	std::set<int> already_showed;
	for(int i = 1 ; i < max ; i++) {
		const int somme_div_1 = formulas::sum_divisors(i);
		const int somme_div_2 = formulas::sum_divisors(somme_div_1);

		if(somme_div_2 == i && somme_div_1 != somme_div_2) {
			if(already_showed.find(i) == already_showed.end()) {
				already_showed.insert(somme_div_1);
				std::cout << "(" << somme_div_2 << "," << somme_div_1 << ")" << std::endl;
			}
		}
	
	} 
}

void Chapter1::exercice8() {
	for(int i = 1 ; i < 9 ; i++) { //Commencer à 1 car 3 chiffres seulement. Les résultats 0 et 1 sont donc écartés
		for(int j = 0 ; j < 9 ; j++) {
			for (int k = 0 ; k < 9 ; k++) {
				const int ijk = i * 100 + j * 10 + k;
				const int power3_of_ijk = static_cast<int> (std::pow(i,3) + std::pow(j,3) + std::pow(k, 3));
				if(ijk == power3_of_ijk) {
					std::cout << ijk << std::endl;
				}
			}
		}
	}
}

void Chapter1::exercice9() {
	unsigned int input = 0;
	std::cout << "Rentrez un nombre positif : ";
	std::cin >> input;

	std::vector<unsigned int> list = formulas::prime_decomposition(input);

	std::cout << "Formule decomposee en nombres premier : ";
	for(unsigned int i = 0 ; i < list.size() ; i++) {
		std::cout << list[i];
		i == (list.size() - 1) ? std::cout <<  std::endl : std::cout << " x "; 
	}
}