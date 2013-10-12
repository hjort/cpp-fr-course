#include <iostream>
using namespace std;

void f1(int i, int j)
{
  int copie(i);
  i=j;
  j=copie;
}

int f2(int j)
{
  j=1;
  return j-1;
}

int f3(int& i)
{
  i=0;
  return i+1;
}

int f4(int& j)
{
  j=1;
  return j;
}

int main()
{
  int i(1);
  int j(0);

 /* code manquant */ 
 i = f2(j); 

  cout << "i = "   << i
       << "; j = " << j << endl;
  return 0;
}
