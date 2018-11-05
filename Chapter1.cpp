#include "Chapter1.h"
#include <complex>
#include <ppltasks.h>
#include "math.h"

void Chapter1::init() {
	chapter_definition = "Problemes de math.";

	exercise_definitions.emplace_back("Somme des entiers divisibles par 3 et 5");
	exercise_definitions.emplace_back("Plus grand denominateur commun entre deux entiers");
	exercise_definitions.emplace_back("Plus petit multiplieur commun entre deux ou plusieurs entiers");
	exercise_definitions.emplace_back("Nombre premier le plus grand, plus petit que le nombre rentre en parametre");
	exercise_definitions.emplace_back("Liste des paires de nombres sexy jusqu'a une valeur donnee");

	exercices_functions.emplace_back(exercice1);
	exercices_functions.emplace_back(exercice2);
	exercices_functions.emplace_back(exercice3);
	exercices_functions.emplace_back(exercice4);
	exercices_functions.emplace_back(exercice5);
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

	std::cout << "Somme des entiers = " + std::to_string(count) << std::endl;
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
		result = maths::gcm(premier_div, second_div);
	else
		result = maths::gcm(second_div, premier_div);

	std::cout << "Plus grand denominateur commun : " + std::to_string(result) << std::endl;
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

	for(unsigned int i = 0 ; i < entiers.size() - 1; i++) {
		entiers[i + 1] = maths::lcm(entiers[i], entiers[i + 1]);
	}

	std::cout << "Plus petit multiple commun : " + std::to_string(entiers.back()) << std::endl;

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
		if(maths::is_prime(i)) {
			result = i;
			break;
		}
	}

	std::cout << "Le plus petit nombre premier avant est " + std::to_string(result) << std::endl;
}

void Chapter1::exercice5() {
	int input = 0;
	std::cout << "Entrez un nombre positif : ";
	std::cin >> input;

	std::cout << "Liste des nombres premiers sexy jusqu'a " + std::to_string(input) + " : " << std::endl;
	for(int i = 0 ; i < input ; i++) {
		if(maths::is_prime(i) && maths::is_prime(i + 6)) {
			std::cout << "(" + std::to_string(i) + "," + std::to_string(i + 6) + ")" << std::endl;
		}
	}
}
