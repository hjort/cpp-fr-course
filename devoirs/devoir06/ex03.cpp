#include <iostream>
using namespace std;

/**
 * Exercice 3 - codes d'Elias
 * 
 * Cet exercice s'intéresse à construire un code binaire (suite de 0 et 
 * de 1) pour les nombres entiers, de sorte qu'on puisse les transmettre 
 * en séquence de façon non ambiguë. Par exemple :
 * 
 * - si on choisit de coder l'entier 1 par la chaîne binaire "1" et 
 *   l'entier 3 par la chaîne binaire "11", ce code est ambigu : si un 
 *   émetteur envoie la chaîne binaire "11" le récepteur ne sait pas 
 *   s'il doit interpréter cette chaîne comme un seul 3 ou une séquence 
 *   de deux 1 ;
 * - en revanche, si on code 1 par "1" et 3 par "001", cette ambiguïté 
 *   disparaît et ce code est un code non ambigu (au moins pour les 
 *   valeurs 1 et 3).
 * 
 * L'avantage des codes non ambigus est de permettre d'envoyer des 
 * données sous une forme simple à décoder tout en étant concis. Le but 
 * de cet exercice est de vous faire écrire des fonctions pour pouvoir 
 * calculer un tel code, appelé code d'Elias, d'après le nom de son 
 * inventeur.
 * 
 * Nous aurons pour cela besoin de quatre étapes assez simples et vous 
 * demandons de faire cinq fonctions.
 */

/**
 * Fonction convert
 * 
 * La première fonction est simplement utilitaire nous servant à 
 * convertir un int en char suivant la convention suivante :
 * 
 * - si l'entier reçu en paramètre vaut 1, retourner le caractère '1' ;
 * - sinon retourner le caractère '0'.
 * 
 * Ecrivez un programme C++ contenant une fonction convert (respectez 
 * strictement ce nom) qui prend en paramètre un entier et retourne un 
 * caractère suivant la convention expliquée ci-dessus.
 */
 char convert(int n) {
	 return n == 1 ? '1' : '0';
 }

/**
 * Fonction Z0
 * 
 * Le premier code dont nous avons besoin pour construire le code 
 * d'Elias d'un nombre est simplement son code binaire, appelé ici Z0 :
 * 
 *    n 	1	2	3	4	5	6	7	8
 * Z0(n)	1	10	11	100	101	110	111	1000
 * 
 * Pour construire ce code, il faut procéder de façon similaire à ce qui 
 * avait été fait en base 10 dans l'exercice 1 du devoir précédent, 
 * « sommes et produits », mais ici en base 2 :
 * 
 * - tant que n n'est pas nul (réfléchissez si c'est une boucle while, 
 * ou une boucle do-while) ajouter le caractère correspondant à n % 2 
 * (en utilisant la fonction convert), et diviser n par 2.
 * 
 * Créez pour cela une fonction Z0 (respectez strictement ce nom) qui 
 * prend en paramètre un entier n et retourne une chaîne de caractères 
 * correspondant au code binaire de n tel que décrit ci-dessus.
 * 
 * Attention, l'ajout de chaque nouveau symbole (ici, un caractère 
 * retourné par la fonction convert) doit se faire à l'avant de la 
 * chaîne à retourner et non pas à sa fin.
 * 
 * Testez votre fonction avec les valeurs indiquées plus haut.
 */
string Z0(int n) {
	string r;
	do {
		r = convert(n % 2) + r;
		n /= 2;
	} while (n > 0);
	return r;
}

/**
 * Fonction Z0t
 * 
 * On peut remarquer que le code Z0 de n'importe quel entier commence 
 * toujours par un '1' (à gauche). Le code « Z0 tronqué » correspond au 
 * code Z0, sans ce '1' le plus à gauche :
 * 
 * 		n	1	2	3	4	5	6	7	8
 * Z0t(n)	 	0	1	00	01	10	11	000
 * 
 * Notez qu'il est effectivement vide pour la valeur 0.
 * Créez une fonction Z0t (respectez strictement ce nom) qui prend en 
 * paramètre un entier n et retourne une chaîne de caractères 
 * correspondant au code « Z0 tronqué » de n tel que décrit ci-dessus.
 * 
 * Testez votre fonction avec les valeurs indiquées plus haut.
 */
string Z0t(int n) {
	string r = Z0(n);
	return r.substr(1, r.size());
}

/**
 * Fonction Z1
 * 
 * Pour éviter les ambiguïtés du code Z0, la première idée émise par 
 * Elias fut d'ajouter autant de zéros devant Z0(n) que sa longueur 
 * moins 1 :
 * 
 * 		n	1	2	3	4		5		6		7		8
 * Z1(n)	1	010	011	00100	00101	00110	00111	0001000
 * 
 * Par exemple, le code Z0 de 1 est 1 ; sa longueur est donc 1 et sa 
 * longueur moins 1, 0. Donc on n'ajoute rien devant et son code Z1 sera 
 * également 1.
 * 
 * Autre exemple : le code Z0 de 7 est 111 ; sa longueur est donc 3 et 
 * sa longueur moins 1, 2. On ajoute donc deux zéros devant et son code 
 * Z1 sera alors 00111.
 * 
 * Créez une fonction Z1 (respectez strictement ce nom) qui prend en 
 * paramètre un entier n et retourne une chaîne de caractères 
 * correspondant au code Z1 de n tel que décrit ci-dessus. C'est plus 
 * simple à écrire en C++ qu'en français ;-).
 * 
 * Testez votre fonction avec les valeurs indiquées plus haut.
 */
string Z1(int n) {
	string r = Z0(n), z = "";
	size_t l = r.size() - 1;
	while (l > 0) {
		z += "0";
		l--;
	}
	return z + r;
}

/**
 * Fonction Z2
 * 
 * Le code Z1 est non ambigu, cependant il n'est pas très concis. Le 
 * « truc » intelligent utilisé par Elias pour raccourcir le code fut de 
 * changer le codage de la longueur fait par une suite de zéros en le 
 * code Z1 de cette longueur. Le code Z2 de n est ainsi constitué de 
 * l'enchaînement du code Z1 de la longueur de Z0(n) et du code 
 * « Z0 tronqué » de n lui-même.
 * 
 * Par exemple, 7 est codé en 111 par Z0, ayant ainsi une longueur de 3. 
 * Ceci donne le préfixe Z1(3)=011, et le suffixe 11, code 
 * « Z0 tronqué » de 7. Le code Z2 de 7 est alors 011111 (=011,11). 
 * 
 * Voici d'autres exemples :
 * 
 * 	n		1	2		3		4		5		6		7		8
 * Z2(n)	1	0100	0101	01100	01101	01110	01111	00100000
 * 
 * Pour finir, créez une fonction Z2 (respectez strictement ce nom) qui 
 * prend en paramètre un entier n et retourne une chaîne de caractères 
 * correspondant au code Z2 de n tel que décrit ci-dessus. C'est plus 
 * simple à écrire en C++ qu'il n'y paraît !
 * 
 * Testez votre fonction avec les valeurs indiquées plus haut. Pour 
 * information, voici également les codes pour 255 :
 * 
 * Z0  : 11111111
 * Z0t : 1111111
 * Z1  : 000000011111111
 * Z2  : 00010001111111
 */
string Z2(int n) {
	string z0 = Z0(n);
	string z1l = Z1(z0.size());
	string z0t = Z0t(n);
	return z1l + z0t;
}

/**
 * Remarque : pour pouvoir être noté, votre programme devra contenir une 
 * fonction main(), quelqu'elle soit (même vide).
 */
int main()
{
	// Z0
	for (int i = 0; i <= 10; i++)
		cout << "Z0(" << i << ") = " << Z0(i) << endl;
	cout << endl;
	
	// Z0t
	for (int i = 0; i <= 10; i++)
		cout << "Z0t(" << i << ") = " << Z0t(i) << endl;
	cout << endl;
	
	// Z1
	for (int i = 0; i <= 10; i++)
		cout << "Z1(" << i << ") = " << Z1(i) << endl;
	cout << endl;
	
	// Z2
	for (int i = 0; i <= 10; i++)
		cout << "Z2(" << i << ") = " << Z2(i) << endl;
	cout << endl;
	
	// tous
	cout << "Z0  : " << Z0(255) << endl;
	cout << "Z0t : " << Z0t(255) << endl;
	cout << "Z1  : " << Z1(255) << endl;
	cout << "Z2  : " << Z2(255) << endl;
	cout << endl;

	return 0;
}
