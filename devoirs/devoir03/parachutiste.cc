#include <iostream>
#include <cmath>    // pour exp()
using namespace std;

int main()
{
  double masse(80.0);
  do {
    cout << "masse du parachutiste (>= 40) ? ";
    cin >> masse;
  } while (masse < 40.0);

  double h0(39000.0);
  do {
    cout << "hauteur de depart du parachutiste (>= 250) ? ";
    cin >> h0;
  } while (h0 < 250.0);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/



  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
