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

  const double g(9.81);
  double v0(0.0);
  int t0(0);

  double surface(2.0); // la surface du parachutiste
  int t(t0);    // temps
  double h(h0); // altitude
  double v(v0); // vitesse
  double a(g);  // accélération

  // s : la surface du sportif divisée par sa masse
  double s(surface / masse);

  // un « terme »
  double q;

  bool mvs(false); // message de vitesse du son dépassée
  bool mai(false); // message d'accélération est inférieure

  // afficher les caractéristiques du sportif à chaque seconde
  do {

    // l'évolution du sportif en chute libre
    q = exp(-s * (t - t0));
    v = (g / s) * (1 - q) + v0 * q;
    h = h0 - (g / s) * (t - t0) - (v0 - g / s) / s * (1 - q);
    a = g - s * v;

    // dès que la vitesse dépasse la vitesse du son (343 m/s),
    // le programme affiche (en plus, mais qu'une seule fois) un message
    if (!mvs && v > 343) {
      cout << "## Felix depasse la vitesse du son" << endl;
      mvs = true;
    }

    // dès que son accélération est inférieure à 0.5 m/s^2,
    // le programme affiche (en plus, mais qu'une seule fois) un message
    if (!mai && a < 0.5) {
      cout << "## Felix a atteint sa vitesse maximale" << endl;
      mai = true;
    }

    // temps, altitude, vitesse, accélération
    if (h >= 0)
      cout << t++ << ", " << h << ", " << v << ", " << a << endl;

  } while (h >= 0);

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
