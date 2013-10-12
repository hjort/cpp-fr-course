#include <iostream>
using namespace std;

int main() {
	int i(53);
	int j;
	int k;
	k = i;
	i = i + 1;
	j = i;
	i = i + 1;
	cout << i << ", " << j << ", " << k << endl;
}
