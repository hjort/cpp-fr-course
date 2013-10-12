#include <iostream>
using namespace std;

const int  N(9);
const bool B(false);

void f(int p, int m , int n, bool b)
{
    for (int i(p); i >= 0; --i) { 
		  if ((i >= 2) and b) {
			  cout << /*  code manquant 1 */ i-2 << " ";   
			} else {
			  cout << /*  code manquant 2 */ i+2 << " "; 
			}
		  }
  int k(m);
  while (k <= n) {
    cout << k << " ";
    k *= 3;
  }
  cout << endl;
}

int main()
{
  f(N, N/2, N*2, true);
  return 0;
}
