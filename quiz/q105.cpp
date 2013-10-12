#include <iostream>
using namespace std;

int main() {
	int a(23);
	int b(2);
	a = b;
	b *= a;
	cout << a << ", " << b << endl;
}
