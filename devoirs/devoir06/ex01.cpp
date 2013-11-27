#include <iostream>
#include <vector>

using namespace std;

/**
 * Exercice 1 - Fermeture-éclair de tableaux
 * 
 * On s'intéresse ici à écrire un programme permettant d'entrelacer deux
 * tableaux d'entiers, à une dimension.
 * 
 * Cela consiste à créer le tableau dont chaque élément est pris tour à 
 * tour dans un puis dans l'autre des tableaux :
 * - son premier élément sera le premier élément du premier tableau reçu en paramètre ;
 * - son deuxième élément sera le premier élément du second tableau reçu en paramètre ;
 * - son troisième élément sera le deuxième élément du premier tableau reçu ;
 * - etc.
 * 
 * Lorsqu'un des deux tableaux est épuisé, on continue à remplir en ne
 * prenant alors que dans le tableau restant, jusqu'à épuisement de 
 * celui-ci.
 * 
 * Par exemple si le premier tableau est { 1, 2, 3 } et le second 
 * { 4, 5, 6 }, alors le tableau résultant sera { 1, 4, 2, 5, 3, 6 }.
 * 
 * Autre exemple : si le premier tableau est { 1, 2, 3 } et le second 
 * { 4, 5, 6, 7, 8 }, alors le tableau résultant sera 
 * { 1, 4, 2, 5, 3, 6, 7, 8 }.
 * 
 * A noter donc que l'entrelacement avec un tableau vide redonne un 
 * tableau identique. Par exemple si le premier tableau est { 1, 2, 3 } 
 * et que le second est vide, alors le tableau résultant sera { 1, 2, 3 }.
 */

/**
 * Ecrivez un programme C++ contenant une fonction entrelace (respectez 
 * strictement ce nom) qui prend deux tableaux dynamiques d'entiers en 
 * paramètre et retourne un tableau dynamique d'entier, résultat de 
 * l'entrelacement des 2 tableaux reçus, tel que décrit ci-dessus.
 */
vector<int> entrelace(vector<int> tab1, vector<int> tab2) {
	
	if (tab1.empty())
		return tab2;
	else if (tab2.empty())
		return tab1;

	size_t t1 = tab1.size(), t2 = tab2.size();
	size_t taille(t1 + t2);
	//cout << "taille : " << taille << endl;
	
	vector<int> res(taille);

	for (size_t i = 0, j = 0, k = 0; i < taille; ) {
		if (j < t1)
			res[i++] = tab1[j++];
		if (k < t2)
			res[i++] = tab2[k++];
	}
	
	return res;
}

/**
 * Pour pouvoir être noté, votre programme devra contenir une fonction 
 * main(), quelqu'elle soit (même vide).
 */
int main()
{
	
	vector<int> premier = { 1, 2, 3 };
	vector<int> second = { 4, 5, 6, 7, 8 };
	vector<int> resultant;
	bool virg = false;
	
	resultant = entrelace(premier, second);
	
	cout << "resultant = {";
	for (auto element : resultant) {
		if (virg)
			cout << ", ";
		else
			virg = true;
		cout << element;
	}
	cout << "}" << endl;
	
	return 0;
}
