#include <iostream>
using namespace std;

void t1() {
	bool test1(true);
	bool test2(false);
	bool test3(true);

	if (test1 or test2){
		cout << "La" << " ";}
	else{
		cout << "Si" << " ";}
	test1 = not test3;
	if ((not test1 and test2) or test3){
		if (test1 and test3){
			cout << "La" << " ";}
		else{
			cout << "Si" << " ";}
		if (test3){
			cout << "Si" << " ";}
		else{
			cout << "La" << " ";}
	}
	cout << endl;
}

void t2() {
	bool test1(false);
	bool test2(false);
	bool test3(true);

	if (test1 or test2){
		cout << "La" << " ";}
	else{
		cout << "Si" << " ";}
	if ((not test1 and test2) or test3){
		if (test1 and test3){
			cout << "La" << " ";}
		else{
			cout << "Si" << " ";}
		if (test3){
			cout << "Si" << " ";}
		else{
			cout << "La" << " ";}
	}
	cout << endl;
}

void t3() {
	bool test1(false);
	bool test2(false);
	bool test3(true);

	if (test1 or test2){
		cout << "La" << " ";}
	else{
		cout << "Si" << " ";}
	test1 = not test3;
	if ((not test1 and test2) or test3){
		if (test1 and test3){
			cout << "La" << " ";}
		else{
			cout << "Si" << " ";}
		if (test3){
			cout << "Si" << " ";}
		else{
			cout << "La" << " ";}
	}
	cout << endl;
}

void t4() {
	bool test1(true);
	bool test2(false);
	bool test3(true);

	if (test1 or test2){
		cout << "La" << " ";}
	else{
		cout << "Si" << " ";}
	if ((not test1 and test2) or test3){
		if (test1 and test3){
			cout << "La" << " ";}
		else{
			cout << "Si" << " ";}
		if (test3){
			cout << "Si" << " ";}
		else{
			cout << "La" << " ";}
	}
	cout << endl;
}

int main() {
	t1();
	t2();
	t3();
	t4();
}
