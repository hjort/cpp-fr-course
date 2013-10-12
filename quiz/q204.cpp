#include <iostream>
using namespace std;

int main() {
	int i(10);
	if (i < 14){
		int i(20);
		int j(4);
		int k(10);
		cout << i << endl;
		if (i > 10){
			int i(30);
			k += 10;
			j *= 2;
			if (k > 0){
				int i(5);
				int k(10);
				j = k;
			} 
		}
	}
	//cout << i << endl;
}
