#include <iostream>
using namespace std;

int main() {

	int m(0);
	int p(3);
	bool test1(true);
	bool test2(!test1);

	while(m <= p) {
		if (test1 || test2) {
			cout << test1 << " " << m << " ";
			test1 = !test1;
		}
		else {
			cout << test2 << " " << p << " ";

			/* code manquant */
			//test2 = test1;				 
			//test1 = !test2;
			test2 = !test1;
			//test1 = !test1;
			
		}
		++m;
	}

	if (test1 || (test2 && !test1)) {
		cout << test1 << " ";
	}

}
