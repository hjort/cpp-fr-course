#include <iostream>
using namespace std;

int main()
{
	cout << "Pensez a un personnage : Mlle Rose, le Professeur Violet, "
		<< "le Colonel Moutarde," << endl
		<< "le Reverend Olive ou Mme Leblanc." << endl << endl;

	/*    
	Les 5 personnages possibles sont:
	Mlle Rose, le Professeur Violet, le Colonel Moutarde, le Reverend Olive et Mme Leblanc.

	Seul le Colonel Moutarde a des moustaches, tous portent des lunettes sauf Mlle
	Rose, et le Professeur Violet est le seul à avoir un chapeau.
	*/

	/*
	perso		moustaches	chapeau	lunettes	homme
	moutarde	1			0		1			1
	violet		0			1		1			1
	olive		0			0		1			1
	leblanc		0			0		1			0
	rose		0			0		0			0
	*/

	string perso;

	cout << "Est-ce que votre personnage est un homme ? ";
	bool homme;
	cin >> homme;

	if (!homme) {
		
		cout << "Votre personnage porte-t-il des lunettes ? ";
		bool lunettes;
		cin >> lunettes;

		if (!lunettes) {
			perso = "Mlle Rose";

		} else {
			perso = "Mme Leblanc";
		}
		
	} else {
	
		cout << "Votre personnage a-t-il des moustaches (1 : oui, 0 : non) ? ";
		bool moustaches;
		cin >> moustaches;

		if (moustaches) {
			perso = "le Colonel Moutarde";

		} else {

			cout << "Votre personnage porte-t-il un chapeau ? ";
			bool chapeau;
			cin >> chapeau;

			if (chapeau) {
				perso = "le Professeur Violet";

			} else {

				perso = "le Reverend Olive";
			}
		}
	}
	
	cout << "==> Le personnage auquel vous pensez est ";
	cout << perso;

	cout << endl;

	return 0;
}
