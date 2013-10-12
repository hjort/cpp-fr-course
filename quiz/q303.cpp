#include <iostream>
using namespace std;

void t1() {
	for (int i(1); i < 12; i += 2){
		i += 1;
		cout << i << " "; 
	}
	cout << endl;
}

void t2() {
	int i(1);  
	do {
	   cout << i << " ";
	   i += 2;
	} while (i < 12);
	cout << endl;
}

void t3() {
	int i(1);  
	while( i < 11 ){
	  cout << i << " ";
	  i += 2;
	}
	cout << endl;
}

void t4() {
	for (int i(2); i < 12; i += 2){ 
	   cout << i+1 << " ";
	}
	cout << endl;
}

int main() {
	t1();
	t2();
	t3(); // x
	t4();
}
