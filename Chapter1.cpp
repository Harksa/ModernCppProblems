#include "Chapter1.h"
#include <complex>
#include <numeric>

#include "formulas.h"
#include <set>
#include <bitset>
#include <iomanip>
#include <map>

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

	exercises_definitions.emplace_back("Affichage d'un nombre en binaire, son code de gray et son code de gray decode");
	exercises_definitions.emplace_back("Ecriture d'un nombre donne en nombre romain");
	exercises_definitions.emplace_back("Plus grande sequence de Collatz jusqu'a 1 million et afficher sa taille");

	exercises_functions.emplace_back(exercice1);
	exercises_functions.emplace_back(exercice2);
	exercises_functions.emplace_back(exercice3);
	exercises_functions.emplace_back(exercice4);
	exercises_functions.emplace_back(exercice5);
	exercises_functions.emplace_back(exercice6);
	exercises_functions.emplace_back(exercice7);
	exercises_functions.emplace_back(exercice8);
	exercises_functions.emplace_back(exercice9);

	exercises_functions.emplace_back(exercice10);
	exercises_functions.emplace_back(exercice11);
	exercises_functions.emplace_back(exercice12);
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

	/* Premi�re version
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
	constexpr int max = 1'000'000;
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
	for(int i = 1 ; i < 9 ; i++) { //Commencer � 1 car 3 chiffres seulement. Les r�sultats 0 et 1 sont donc �cart�s
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

void Chapter1::exercice10() {
	constexpr int max = 32;

	for(int i = 0 ; i < max ; i++) {
		const std::bitset<5> binary = i;

		//https://www.dcode.fr/code-gray
		//Utilisation du ou exclusif et du shift pour obtenir le code de gray
		const auto gray_code = binary ^ (binary >> 1);

		//Decodage
		auto temp_gray_code = gray_code;
		auto decoded_gray_code = temp_gray_code;
		while ( (temp_gray_code >>= 1).count() != 0 ) {
			decoded_gray_code ^= temp_gray_code;
		}

		std::cout << std::setw(2) << i << " : " << binary << " " << gray_code << " " << decoded_gray_code << std::endl;
	}
}

void Chapter1::exercice11() {
	int input = 0;
	std::cout << "Entrez un nombre positif supperieur a 0 : ";
	std::cin >> input;

	//https://www.dcode.fr/chiffres-romains
	std::vector<std::pair<int, std::string>> roman_letters {
		std::make_pair(1000, "M"),   std::make_pair(900, "CM"),
		std::make_pair(500,  "D"),   std::make_pair(400, "CD"),
		std::make_pair(100,  "C"),   std::make_pair(90,  "XC"),
		std::make_pair(50,   "L"),   std::make_pair(40,  "XL"),
		std::make_pair(10,   "X"),   std::make_pair(9,   "IX"),
		std::make_pair(5,    "V"),	 std::make_pair(4,   "IV"),
		std::make_pair(3,    "III"), std::make_pair(2,   "II"),
		std::make_pair(1,    "I")
	};

	std::string result;
	while (input > 0) {
		for (const auto& roman_letter : roman_letters){
			if(input >= roman_letter.first) {
				result += roman_letter.second;
				input -= roman_letter.first;
				break;
			} 
		}
	}

	std::cout << "Conversion en nombre romain : " << result << std::endl;
}

void Chapter1::exercice12() {

	const unsigned int max = 1'000'000;

	std::map<unsigned long long, int> collatz_map{std::make_pair(1,0)};

	int collatz_value = 0, collatz_lenght = 0;
	for(unsigned int i = 2 ; i < max ; i++) {
		unsigned long long n = i;
		unsigned int size = 0;
		auto it = collatz_map.find(n);
		while(it == collatz_map.end()) {
			if (n % 2 == 0)
				n /= 2;
			else
				n = 3 * n + 1;

			size++;
			it = collatz_map.find(n);
		}
		int current_size = it->second + size;
		collatz_map.insert(std::make_pair(i, current_size));

		if(current_size > collatz_lenght) {
			collatz_value = i;
			collatz_lenght = current_size;
		}

	}

	  std::cout << "Sequence de collatz la plus grande : " << collatz_value << " avec une taille de " << collatz_lenght << "." << std::endl;	
}
