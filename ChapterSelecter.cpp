#include "ChapterSelecter.h"
#include "Chapter1.h"

void ChapterSelecter::initChapters() {	
	chapters.push_back(new Chapter1());
}

void ChapterSelecter::selectChapter(const int index) {
	
	chapters[index]->displayChapterExercicesDefinition();

	int exercice_selection = 0;
	do {
		std::cout << std::endl << "Choix de l'exercice. Selectionnez 0 pour sortir du chapitre : ";
		std::cin >> exercice_selection;

		if(exercice_selection != 0) {
			if(exercice_selection < 0 || exercice_selection > chapters[index]->exerciceTotal()) {
				std::cout << "Saisie incorrecte." << std::endl;
			} else {
				chapters[index]->callFunction(exercice_selection - 1);
			}
		}
		
	} while(exercice_selection != 0);
}

void ChapterSelecter::displayChapters() {
	std::cout << "Chapitres disponibles : " << std::endl;

	for (unsigned int i = 0 ; i < chapters.size() ; i++) {
		std::cout << "Chapitre " + std::to_string(i+1) + " : "; 
		chapters[i]->displayChapterDefinition();
	}
}

int ChapterSelecter::totalChapters() const {
	return chapters.size();
}

void ChapterSelecter::clear() {
	for (auto chapter : chapters) {
		delete chapter;
	}

	chapters.clear();
	chapter_definition.clear();
}
