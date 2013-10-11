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



  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
