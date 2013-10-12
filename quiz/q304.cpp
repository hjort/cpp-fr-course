#include <iostream>
using namespace std;

int main() {

	int a(2);
	int b(5);
	int c(4);

	while(b < 7){
		if (a < c){
			++a;
		}
		else{
			--c;
		}
		++b;
	}

	if ((a < b) && (a + c > b)){
		cout<<"1"<<" ";
	}
	else{
		cout<<"2"<<" ";
	}
	if (a < c){
		cout<<"3"<<" ";
	}
	else{
		cout<<"4"<<" ";
		if (2*a > b){
			cout<<"5"<<" ";
		}
	}

/*
	int a(4);
	int b(10);
	int c(6);

	for(int i(0); i < 5; i += 2){
		if (a % 2 == 1){
			a += i;
		}
		else{
			--a;
		}
	}

	if(a > b){
		cout << "1" << " ";
	}
	else{
		if(a + c > b){
			cout << "2" << " ";
		}
		else{
			cout << "3" << " ";
		}
	}
	while(a < b){
		cout << b-a << " ";
		a += 2;
	}
*/
	// 2 1
}
