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
	 * \brief Nombres abondants et son abondance
	 * Un nombre est abondant si la somme de ses diviseurs est supérieur à lui même
	 * Abondance = somme - nombre
	 */
	static void exercice6();

	/**
	 * \brief Nombres amicaux avant 1 000 000
	 * Prenons a et b, deux entiers positifs.
	 * Ils sont dit amicaux si la somme des diviseurs de a = b et si la somme des diviseurs de b = a
	 */
	static void exercice7();

	/**
	 * \brief Les nombres d'Amstrong ou nombres narcissiques à 3 chiffres
	 * 371 est un nombre d'Amstrong car 3^3 + 7^3 + 1^3 = 371
	 */
	static void exercice8();

	/**
	 * \brief Décomposition d'un nombre en nombre premiers
	 * Exemple : 100 = 2 * 2 * 5 * 5
	 */
	static void exercice9();

	/**
	 * \brief Affichage d'un chiffre en binaire, code de gray et en code de gray décodé.
	 */
	static void exercice10();

	/**
	 * \brief Conversion d'un chiffre en binaire en un chiffre romain
	 */
	static void exercice11();

	/**
	 * \brief Calculer la plus grande séquence de Collatz jusqu'a 1 million et afficher sa taille
	 * D'après cette conjecture, on démarre avec un nombre entier positif.
	 * S'il est paire, on divise le nombre par deux
	 * S'il est impaire, on effectue l'opération (3n + 1)
	 * On réutilise à chaque fois le nombre issue des opérations si dessus.
	 * La conjecture indique que l'on finit toujours par retomber sur 1 
	 */
	static void exercice12();

	Chapter1();
	~Chapter1() = default;

};

