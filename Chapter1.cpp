#include "Chapter1.h"
#include <complex>
#include <ppltasks.h>

void Chapter1::init() {
	chapter_definition = "Problemes de math.";

	exercise_definitions.push_back("Somme des entiers divisibles par 3 et 5");
	exercise_definitions.push_back("Plus grand denominateur commun entre deux entiers");
	exercise_definitions.push_back("Plus petit multiplieur commun entre deux ou plusieurs entiers");

	exercices_functions.push_back(exercice1);
	exercices_functions.push_back(exercice2);
	exercices_functions.push_back(exercice3);
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

//https://en.wikipedia.org/wiki/Greatest_common_divisor#Using_Euclid's_algorithm
int gcm(const int a, const int b) {
	return b == 0 ? a : gcm(b, a % b);
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
		result = gcm(premier_div, second_div);
	else
		result = gcm(second_div, premier_div);

	std::cout << "Plus grand denominateur commun : " + std::to_string(result) << std::endl;
}

//https://en.wikipedia.org/wiki/Least_common_multiple#Reduction_by_the_greatest_common_divisor
int lcm(const int a, const int b) {
	return (a * b) / gcm(a,b);
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
		entiers[i + 1] = lcm(entiers[i], entiers[i + 1]);
	}

	std::cout << "Plus petit multiple commun : " + std::to_string(entiers.back()) << std::endl;

	entiers.clear();
}
