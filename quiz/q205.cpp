#include <iostream>
using namespace std;

int main() {

	int x(10);
	int y(6);
	int z(8);

	x += z;

	if (x + y > 20){
		cout << "1" << " ";
	}
	else{
		cout << "2" << " ";
	}

	if (z / 2 > 2){
		if (y == z){
			cout << "3" << " ";
		}
		else{
			cout << "4" << " ";
		}
	}
	else{
		cout << "5" << " ";
	}

}
