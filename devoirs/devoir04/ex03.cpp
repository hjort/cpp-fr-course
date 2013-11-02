#include <iostream>
using namespace std;

void espaces(int decalage)
{
  for(int i(0); i < decalage; ++i) {
    cout << ' ';
  }
}

void barre_horizontale(int longueur, int decalage)
{
  espaces(decalage);
  for(int i(0); i < longueur; ++i) {
    cout << '-';
  }
}

void barre_verticale(int decalage)
{
  espaces(decalage);
  cout << '|';
}

void barre_a_droite(int decalage)
{
  espaces(decalage);
  cout << '/';
}

void barre_a_gauche(int decalage)
{
  espaces(decalage);
  /* Attention, cette ligne affiche bien UN SEUL caractere \ !  *
   * En C++, il faut repeter deux fois le caractere \ pour en   *
   * n'afficher qu'un seul.                                     */
  cout << '\\';
}

void fin_ligne()
{
  cout << endl;
}

void affiche_N(int hauteur)
{
  for(int i(0); i < hauteur; ++i) {
    barre_verticale(0);
    barre_a_gauche(i);
    barre_verticale(hauteur-i-1);
    fin_ligne();
  }
}

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/

void affiche_L(int hauteur)
{
	for (int i = 0; i < hauteur - 1; i++) {
		barre_verticale(0);
		fin_ligne();
	}
	barre_horizontale(hauteur, 0);
	fin_ligne();
}

void affiche_O(int hauteur)
{
	barre_horizontale(hauteur - 2, 1);
	fin_ligne();
	for (int i = 1; i < hauteur - 1; i++) {
		barre_verticale(0);
		barre_verticale(hauteur - 2);
		fin_ligne();
	}
	barre_horizontale(hauteur - 2, 1);
	fin_ligne();
}

void affiche_Z(int hauteur)
{
	barre_horizontale(hauteur, 0);
	fin_ligne();
	for (int i = hauteur - 2; i > 0; i--) {
		barre_a_droite(i);
		fin_ligne();
	}
	barre_horizontale(hauteur, 0);
	fin_ligne();
}

void affiche_A(int hauteur)
{
	for (int i = hauteur - 1, j = 0; i >= 0; i--, j+= 2) {
		barre_a_droite(i);
		if (i == hauteur / 2) {
			barre_horizontale(j, 0);
			barre_a_gauche(0);
		} else {
			barre_a_gauche(j);
		}
		fin_ligne();
	}
}

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  const int hauteur(7);
  affiche_L(hauteur);
  fin_ligne();
  affiche_O(hauteur);
  fin_ligne();
  affiche_Z(hauteur);
  fin_ligne();
  affiche_A(hauteur);
  return 0;
}
