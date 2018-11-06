#pragma once
#include "Chapter.h"

class Chapter1 : public Chapter {
public:
	void init() override;

	/**
	 * \brief Somme des entiers divibles par 3 ou 5.
	 */
	static void exercice1();

	/**
	 * \bief Plus grand diviseur commun
	 */
	static void exercice2();

	/**
	 * \brief Plus petit multiple commun
	 */
	static void exercice3();

	/**
	 * \brief Plus grand nombre premier avant le nombre donnée en paramètre
	 */
	static void exercice4();

	/**
	 * \brief Nombre premiers sexy OwO
	 * Deux nombres premiers sont sexys si la différence entre les deux et de 6.
	 */
	static void exercice5();

	/**
	 * \brief Nombres abondants
	 * Un nombre est abondant si la somme de ses diviseurs est supérieur à lui même
	 */
	static void exercice6();

	Chapter1();
	~Chapter1() = default;

private:

};

