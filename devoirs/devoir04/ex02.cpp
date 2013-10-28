#include <iostream>
using namespace std;

/**
 * Exercice 2 – Date de Pâques
 * 
 * Le but de cet exercice est de déterminer la date des Pâques 
 * (chrétiennes grégoriennes) : on demande à l’utilisateur d’entrer une 
 * année et le programme affiche la date de Pâques de l’année 
 * correspondante.
 * 
 * Par exemple :
 * Entrez une annee (1583-4000) : 2006
 * Date de Paques en 2006 : 16 avril
 */

/**
 * Une fonction demander_annee() qui ne prend pas d’argument et retourne
 * un entier ; cette fonction doit :
 * – demander une année à l’utilisateur 
 * (message : « Entrez une annee (1583-4000) : », voir l’exemple 
 * d’affichage ci-dessus) ; tant que l’année entrée n’est pas conforme, 
 * cette fonction devra reposer la question.
 * – vérifier que l’année saisie est bien entre 1583 et 4000 ; 
 * sinon redemander ;
 * – retourner l’année (correcte) saisie.
 */
int demander_annee()
{
	int a(0);
	do {
		cout << "Entrez une annee (1583-4000) : ";
		cin >> a;
	} while (a < 1583 || a > 4000);
	return a;
}

/**
 * Une fonction affiche_date() qui prend deux entiers en paramètres : 
 * une année et un nombre de jours compris entre 22 et 56 ; cette 
 * fonction doit :
 * – afficher le message « Date de Paques en » suivi de l’année reçue
 * en premier paramètre, suivi de « : » comme dans l’exemple d’affichage
 * ci-dessus ;
 * – si le nombre de jours reçu en second paramètre est inférieur ou 
 * égal à 31, afficher le simplement, suivi du mot « mars » ;
 * – si ce nombre de jours est supérieur ou égal à 32, lui retrancher 
 * 31, et l’afficher suivi du mot « avril ».
 */
void affiche_date(int annee, int jours)
{
	cout << "Date de Paques en " << annee << " : ";
	if (jours <= 31)
		cout << jours << " mars";
	else
		cout << (jours - 31) << " avril";
	cout << endl;
}

/**
 * Une fonction date_Paques() qui reçoit une année en paramètre (nombre
 * entier) et retourne un entier entre 22 et 56 indiquant le jour 
 * suivant la convention appliquée dans la fonction affiche_date() ; 
 * cette fonction doit calculer les valeurs suivantes (il s’agit de 
 * l’algorithme de Gauss ; c’est moins compliqué qu’il n’y parait) :
 * 
 * – le siècle. Il suffit de diviser l’année par 100 ;
 * – une valeur p qui vaut 13 plus 8 fois le siècle, le tout divisé par 25 ;
 * – une valeur q, division du siècle par 4 ;
 * – une valeur M valant 15 - p + siecle - q modulo 30 ;
 * – une valeur N valant 4 + siecle - q modulo 7 ;
 * – une valeur d qui vaut M plus 19 fois « l’année modulo 19 », le tout modulo 30 ;
 * – une valeur e qu’il serait trop compliqué de décrire en français et que nous vous donnons directement :
 * (2 * (annee % 4) + 4 * (annee % 7) + 6 * d + N) % 7
 * – le jour (ou presque, voir ci-dessous) : e plus d plus 22.
 * 
 * Toutes les divisions ci-dessus sont des divisions entières, et, pour
 * rappel, « a modulo b » s’écrit « a % b » en C++.
 * 
 * La valeur du jour doit cependant encore être corrigée dans certains 
 * cas particuliers :
 * – si e vaut 6
 * – et que :
 * • d vaut 29
 * • ou d vaut 28 et 11*(M+1) modulo 30 est inférieur à 19, alors 
 * il faut soustraire 7 au jour.
 * 
 * C’est cette valeur (jour) que devra renvoyer la fonction.
 */
int date_Paques(int annee)
{
	
	// le siècle. Il suffit de diviser l’année par 100
	const int siecle(annee / 100);

	// une valeur p qui vaut 13 plus 8 fois le siècle, le tout divisé par 25
	const int p((13 + 8 * siecle) / 25);
 
	// une valeur q, division du siècle par 4
	const int q(siecle / 4);
	
	// une valeur M valant 15 - p + siecle - q modulo 30
	const int M(15 - p + siecle - q % 30);
	
	// une valeur N valant 4 + siecle - q modulo 7
	const int N(4 + siecle - q % 7);
	
	// une valeur d qui vaut M plus 19 fois « l’année modulo 19 », le tout modulo 30
	const int d((M + 19 * (annee % 19)) % 30);
	
	// une valeur e qu’il serait trop compliqué de décrire en français
	const int e((2 * (annee % 4) + 4 * (annee % 7) + 6 * d + N) % 7);
	
	// le jour (ou presque, voir ci-dessous) : e plus d plus 22
	int jour(e + d + 22);
	
	// la valeur du jour doit cependant encore être corrigée
	if (e == 6 && (d == 29 || (d == 28 && (11 * (M + 1)) % 30 < 19)))
		jour -= 7;

	return jour;
}

/*
void tester()
{
	affiche_date(2006, date_Paques(2006));
}
*/

/**
 * Complétez ensuite votre programme en utilisant les trois fonctions
 * précédentes dans le main() de sorte à avoir le comportement décrit au
 * début de cet exercice.
 */
int main()
{
	//tester();
	
	int annee(demander_annee());
	int jours(date_Paques(annee));
	affiche_date(annee, jours);
	
	return 0;
}
