#include <iostream>
#include <vector>

using namespace std;

/**
 * Exercice 4 - Tranches maximales d'un tableau à 2 dimensions
 * 
 * Il s'agit ici d'écrire un programme effectuant un certain nombre de 
 * traitements sur des tableaux dynamiques d'entiers positifs à deux 
 * dimensions. Le but final est de construire le tableau composé des 
 * lignes du tableau de départ qui comportent la plus grande somme 
 * d'éléments non nuls consécutifs.
 */

/**
 * Somme maximale d'éléments consécutifs
 * 
 * Ecrivez un programme C++ contenant une fonction somme_consecutifs_max
 * (respectez strictement ce nom) qui prend en paramètre un tableau 
 * dynamique d'entiers (à une seule dimension) et retourne la plus 
 * grande somme d'éléments non nuls consécutifs.
 */
int somme_consecutifs_max(vector<int> ligne) {
	int somme(0), max(0);
	for (auto elem : ligne) {
		if (elem != 0) {
			somme += elem;
			if (somme > max)
				max = somme;
		} else {
			somme = 0;
		}
	}
	return max;
}

/**
 * Lignes de somme maximale d'éléments consécutifs
 * 
 * Ecrivez ensuite une fonction lignes_max (respectez strictement ce 
 * nom) qui prend en argument un tableau dynamique d'entiers à deux 
 * dimensions et retourne un tableau dynamique de size_t à une seule 
 * dimension.
 * 
 * Le tableau retourné correspond à la liste des numéros de lignes où la 
 * somme maximale d'éléments non nuls consécutifs est atteinte.
 */
vector<size_t> lignes_max(vector<vector<int>> tableau) {
	
	vector<size_t> res;
	vector<int> sommes;
	int max(0);
	
	for (auto ligne : tableau) {
		int somme = somme_consecutifs_max(ligne);
		if (somme > max)
			max = somme;
		sommes.push_back(somme);
	}
	
	for (size_t i = 0; i < sommes.size(); i++) {
		if (sommes[i] == max)
			res.push_back(i);
	}
	
	return res;
}

/**
 * Tranches maximales
 * 
 * Pour finir, écrivez une fonction tranches_max (respectez strictement 
 * ce nom) qui prend en argument un tableau dynamique d'entiers à deux 
 * dimensions et retourne un tableau dynamique d'entiers à deux 
 * dimensions tel qu'expliqué au début de cet exercice.
 */
vector<vector<int>> tranches_max(vector<vector<int>> tableau) {
	
	vector<vector<int>> res;
	vector<size_t> lignes = lignes_max(tableau);
	
	for (size_t i = 0; i < lignes.size(); i++) {
		res.push_back(tableau[lignes[i]]);
	}
	
	return res;
}

/**
 * Pour pouvoir être noté, votre programme devra contenir une fonction 
 * main(), quelqu'elle soit (même vide).
 */
int main()
{
	cout << somme_consecutifs_max({ 0, 2, 2, 0 }) << endl;
	cout << somme_consecutifs_max({ 2, 3, 0, 0, 4 }) << endl;
	cout << somme_consecutifs_max({ 4, 0, 2, 3 }) << endl;
	cout << somme_consecutifs_max({ 0, 0, 0, 0, 0 }) << endl;
	cout << endl;

	vector<vector<int>> tableau = {
		{2, 1, 0, 2},
		{0, 1, 0, 3},
		{1, 3, 0, 0},
		{0, 2, 2, 0}
	};
	vector<size_t> resultant = lignes_max(tableau);
	
	bool virg = false;
	cout << "{";
	for (auto element : resultant) {
		if (virg)
			cout << ", ";
		else
			virg = true;
		cout << element;
	}
	cout << "}" << endl;
	cout << endl;

	tableau = {
		{2, 1, 0, 2, 0, 3, 2},
		{0, 1, 0, 7, 0},
		{1, 0, 1, 3, 2, 0, 3, 0, 4},
		{5, 0, 5},
		{1, 1, 1, 1, 1, 1, 1}
	};
	
	vector<vector<int>> res = tranches_max(tableau);
	for (auto ligne : res) {
		virg = false;
		cout << "{";
		for (auto element : ligne) {
			if (virg)
				cout << ", ";
			else
				virg = true;
			cout << element;
		}
		cout << "}" << endl;
	}
	cout << endl;
	
	return 0;
}
