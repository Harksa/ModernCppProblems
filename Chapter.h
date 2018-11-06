#pragma once
#include <string>
#include <vector>
#include <functional>
#include <iostream>

/**
 * \brief Un chapitre regroupe différents exercices
 */
class Chapter {
	
public:
	/**
	 * \brief Initialise le chapitre avec les définitions et exercices
	 */
	virtual void init() = 0;

	/**
	 * \brief Appelle un exercice.
	 * \param index L'index de l'exercice
	 */
	void callFunction(int index);

	/**
	 * \brief Affiche la définition du chapitre
	 */
	void displayChapterDefinition() const;

	/**
	 * \brief Affiche les définitions des exercices
	 */
	void displayChapterExercicesDefinition();

	/**
	 * \brief Le nombre d'exercices disponibles
	 */
	int exerciceTotal() const;

	Chapter() = default;
	virtual ~Chapter();

protected:
	/**
	 * \brief La définition de ce chapitre
	 */
	std::string chapter_definition;

	/**
	 * \brief La définitions des exercices
	 */
	std::vector<std::string> exercises_definitions;

	/**
	 * \brief Les exercices regroupés en fonctions
	 */
	std::vector<std::function<void()>> exercises_functions;
};


inline void Chapter::callFunction(const int index) {
	std::cout << std::endl << exercises_definitions[index] << std::endl;
	exercises_functions[index]();
}

inline void Chapter::displayChapterDefinition() const {
	std::cout << chapter_definition << std::endl;
}

inline void Chapter::displayChapterExercicesDefinition() {
	std::cout << "Exercices disponibles : " << std::endl;

	int i = 0;
	for (const auto& exercise_definition : exercises_definitions) {
		std::cout <<  "Exercice " + std::to_string(++i) + " : " + exercise_definition << std::endl;
	}
}

inline int Chapter::exerciceTotal() const {
	return exercises_functions.size();
}

inline Chapter::~Chapter() {
	exercises_definitions.clear();
	exercises_functions.clear();
}
