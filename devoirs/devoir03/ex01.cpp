#include <iostream>
using namespace std;

int main()
{
  int debut;
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin;
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/

  int i = debut;
  do {

    int nom = i;
    int rep = 0;
    do {

      //– si ce nombre est divisible par 3, on lui ajoute 4
      if (nom % 3 == 0)
        nom += 4;
      //– s’il n’est pas divisible par 3 mais divisible par 4, on le divise par 2
      else if (nom % 4 == 0)
        nom /= 2;
      //– s’il n’est divisible ni par 3, ni par 4, on lui soustrait 1
      else
        nom--;

      rep++;
    } while (nom > 0);

    cout << i << " -> " << rep << endl;
  } while (i++ < fin);

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
