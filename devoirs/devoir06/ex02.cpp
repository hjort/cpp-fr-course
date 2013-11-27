#include <iostream>
using namespace std;

/**
 * Exercice 2 - Cryptage
 * 
 * Jules César utilisait un système de codage très simple, qui consiste 
 * à remplacer chaque lettre d'un message par la lettre placée plusieurs 
 * rangs après dans l'ordre alphabétique. Par exemple, pour un décalage 
 * de 4, A devient E, B devient F, jusque Z qui devient D.
 * 
 * Il s'agit ici d'appliquer cette technique pour coder une chaîne de 
 * caractères. Vous écrirez pour cela un programme qui met en œuvre les 
 * traitements décrits ci-dessous.
 */

char decale(char, char, int);

/**
 * Codage des caractères
 * 
 * Ecrivez un programme C++ contenant une fonction code (respectez 
 * strictement ce nom) qui prend un caractère et un entier en paramètre 
 * et retourne le caractère «décalé» correspondant si c'est une lettre 
 * majuscule ou minuscule, et retourne la même lettre sinon.
 * 
 * Par exemple, avec le décalage de 4 (second paramètre) :
 * - pour 'a', cette fonction retournera 'e' ;
 * - pour 'A', elle retournera 'E' ;
 * - pour 'Z', elle retournera 'D' ;
 * - et pour '!', elle retournera '!' (inchangé).
 * 
 * Soit c le caractère et d le décalage reçus par la fonction code :
 * - si c est supérieur ou égal à 'a' et qu'il est inférieur ou égal à 
 *   'z' (on peut comparer les caractères avec les mêmes opérateurs que 
 *   les nombres), alors renvoyer le résultat de l'appel de decale sur 
 *   c, à partir de 'a' avec le décalage d ;
 * - si c est supérieur ou égal à 'A' et qu'il est inférieur ou égal à
 *   'Z', procédez de même mais en partant de 'A' ;
 * - sinon renvoyez c inchangé.
 */
char code(char c, int d) {
	if (c >= 'a' && c <= 'z')
		return decale(c, 'a', d);
	else if (c >= 'A' && c <= 'Z')
		return decale(c, 'A', d);
	else
		return c;
}

/**
 * Créez une fonction decale (respectez strictement ce nom, sans accent) qui
 * - prend trois paramètres : un caractère c, un caractère debut et un 
 *   entier decalage, tant que le decalage est strictement négatif, lui 
 *   ajouter 26 ;
 * - et retourne un caractère suivant la formule :
 *   debut + (((c - debut) + decalage) % 26)
 * 
 * (Note : ceux qui compilent avec l'option -Wconversion auront ici un 
 * message d'alerte (warning) du compilateur, que l'on peut ignorer).
 */
char decale(char c, char debut, int decalage) {
	while (decalage < 0)
		decalage += 26;
	return debut + (((c - debut) + decalage) % 26);
}

/**
 * Codage des chaînes
 * 
 * Ecrivez ensuite une fonction code (respectez strictement ce nom) qui 
 * prend en paramètres une chaîne de caractères et un entier, et qui 
 * retourne une nouvelle chaîne de caractères en appliquant la fonction 
 * code précédente à chacun des caractères de la chaîne reçue.
 * 
 * Cette fonction retournera par exemple :
 * 
 * Jycid qererxw lorsqu'elle reçoit la chaîne Fuyez manants et un décalage de 4 ;
 * Laekf sgtgtzy pour la même chaîne et un décalage de 6 ;
 * Bquav iwjwjpo pour la même chaîne et un décalage de -4 ;
 * Ezid-zsyw zy qiw 3 glexw ix qiw 2 glmirw ? pour Avez-vous vu mes 3 chats et mes 2 chiens ? et un décalage de 4.
 */
string code(string texte, int decalage) {
	const size_t taille = texte.size();
	string chaine(texte);
	for (size_t i = 0; i < taille; i++)
		chaine[i] = code(chaine[i], decalage);
	return chaine;
}

/**
 * Décodage des chaînes
 * 
 * Ecrivez une fonction decode (respectez strictement ce nom) qui prend 
 * en paramètres une chaîne de caractères et un entier, décode la chaîne 
 * reçue (pour le décalage reçu) et retourne la chaîne ainsi décodée.
 * 
 * Il suffit de remarquer que décoder consiste à coder avec le décalage 
 * opposé. Cela peut donc s'écrire en une seule instruction.
 */
string decode(string texte, int decalage) {
	return code(texte, -decalage);
}

/**
 * Pour pouvoir être noté, votre programme devra contenir une fonction 
 * main(), quelqu'elle soit (même vide).
 * 
 * Et n'oubliez pas de tester vos fonctions...
 */
int main()
{
	// Codage
	cout << code("Fuyez manants", 4) << endl;
	cout << code("Fuyez manants", 6) << endl;
	cout << code("Fuyez manants", -4) << endl;
	cout << code("Avez-vous vu mes 3 chats et mes 2 chiens ?", 4) << endl;
	cout << endl;
	
	// Décodage
	cout << decode("Jycid qererxw", 4) << endl;
	cout << decode("Laekf sgtgtzy", 6) << endl;
	cout << decode("Bquav iwjwjpo", -4) << endl;
	cout << decode("Ezid-zsyw zy qiw 3 glexw ix qiw 2 glmirw ?", 4) << endl;

	return 0;
}
