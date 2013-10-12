#include <iostream>
using namespace std;

int main() {
	int a(11);
	int b(a + 4);
	int c(a + b);
	a += b - 5;
	cout << a << ", " << 2*b << ", " << c << endl;
}
