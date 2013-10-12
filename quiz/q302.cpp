#include <iostream>
using namespace std;

int main() {

	int j(5);
	for (int i(0); i < 5 ; i += 2) {
		for (int i(3); i < 10 ; i *= 2) {
			while (j < 10) {
				int i(10);
				j += 2;
				cout << i << " ";
			}
		}
	}

	// 10 10 10
}
