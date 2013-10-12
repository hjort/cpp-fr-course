#include <iostream>
using namespace std;

int main() {
	int a(3);
	int b(6);
	bool test1(b%a==1);
	bool test2(false);
	bool test(not (test2 and test1));
	cout << test << endl;
}
