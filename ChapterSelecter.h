#pragma once
#include <vector>
#include "Chapter.h"

/**
 * \brief Selectionne les chapitres
 */
class ChapterSelecter {
public:
	/**
	 * \brief Cr�er les chapitres et remplis les fonctions exercices
	 */
	void initChapters();

	/**
	 * \brief Selectionne un chapitre
	 * \param index Le num�ro du chapitre
	 */
	void selectChapter(int index);

	/**
	 * \brief Affiche les exercices du chapitre
	 */
	void displayChapters();

	/**
	 * \brief Retourne le nombre total de chapitres pris en compte
	 * \return Le nombre total de chapitre pris en compte
	 */
	int totalChapters() const;

	/**
	 * \brief Nettoie le selectioneur de chapitre de la m�moire
	 */
	void clear();

	ChapterSelecter() = default;
	~ChapterSelecter() = default;
	
private:

	/**
	 * \brief Regroupe la d�finition de chaque chapitres
	 */
	std::vector<std::string> chapter_definition;

	/**
	 * \brief Les chapitres contenant les exercices
	 */
	std::vector<Chapter *> chapters;
};

