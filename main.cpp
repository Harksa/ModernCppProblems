#include <cstdlib>
#include "ChapterSelecter.h"
#include "Chapter1.h"

int main(int argc, char* argv[]) {

	ChapterSelecter chapter_selecter{};

	chapter_selecter.initChapters();

	chapter_selecter.displayChapters();

	int selection = 0;
	do {
		std::cout << std::endl << "Selectionnez un chapitre ou selectionnez 0 pour quitter l'application : ";

		std::cin >> selection;

		if(selection != 0) {
			if(selection < 0  || selection > chapter_selecter.totalChapters())
				std::cout << "Saisie incorrecte." << std::endl;
			else {
				chapter_selecter.selectChapter(selection - 1);
			}
		}
	} while (selection != 0);

	chapter_selecter.clear();

	#ifdef _WIN32
		system("pause");
	#endif

	return EXIT_SUCCESS;	
}
