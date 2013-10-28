#include <iostream>
using namespace std;

/**
 * Exercice 1 - Sommes et produits
 * 
 * On s'intéresse ici à trouver des nombres dont la somme des chiffres 
 * est égale à leur produit. 
 * 
 * Par exemple 123 est un tel nombre : 1 + 2 + 3 = 1 × 2 × 3.
 */

/**
 * Ecrivez une fonction appelée somme qui, en appliquant la méthode 
 * décrite ci-dessus, retourne la somme des chiffres du nombre entier 
 * qu'elle reçoit en paramètre. La valeur de retour est donc également 
 * un nombre entier.
 */
int somme(int nombre)
{
	int s(0), d(nombre);

	do {
		s += (d % 10);
		d /= 10;
	} while (d > 0);

	return s;
}

/**
 * Ecrivez ensuite une fonction appelée produit qui retourne le produit 
 * des chiffres d'un nombre passé en paramètre. Par exemple, cette 
 * fonction devra retourner 2 quand 12 est passé en paramètre 1×2=2), 
 * 24 quand 423 est passé en paramètre (4×2×3=24).
 */
int produit(int nombre)
{
	if (nombre == 0)
		return 0;

	int p(1), d(nombre);
	do {
		p *= (d % 10);
		d /= 10;
	} while (d > 0);

	return p;
}

/**
 * Utilisez ensuite vos deux fonctions pour écrire une fonction 
 * somme_produit_egaux qui teste si la somme des chiffres d'un nombre 
 * entier passé en paramètre est égale au produit de ces mêmes chiffres. 
 * Par exemple, somme_produit_egaux(12) devra renvoyer false, 
 * somme_produit_egaux(123) devra renvoyer true.
 */
bool somme_produit_egaux(int nombre)
{
	return somme(nombre) == produit(nombre);
}

void tester()
{
	cout << somme(123) << endl;
	cout << somme(1234) << endl;
	cout << somme(12345) << endl;
	cout << produit(123) << endl;
	cout << produit(1230) << endl;
	cout << produit(1234) << endl;
	cout << produit(12345) << endl;
	cout << somme_produit_egaux(123) << endl;
	cout << somme_produit_egaux(1234) << endl;
}

/**
 * Utilisez enfin cette fonction somme_produit_egaux pour afficher les 
 * 20 premiers nombres entiers plus grands que 10 dont la somme des 
 * chiffres est égale au produit de ces mêmes chiffres. Pour vous aider 
 * à vérifier votre programme, voici les 5 premiers nombres que vous 
 * devriez trouver : 22, 123, 132, 213 et 231.
 */
int main()
{
	//tester();
	
	int q(0), n(10);
	do {
		n++;
		if (somme_produit_egaux(n)) {
			cout << n << ", ";
			q++;
		}
	} while (q < 20);
	cout << endl;
	
	return 0;
}
