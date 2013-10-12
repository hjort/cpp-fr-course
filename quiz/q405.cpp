#include <iostream>
using namespace std;

bool f(int a, int&b)
{
    a += 3;
    b *= 2;

    return ((a + b) >= 10);
}

int main() {

	int x(2);
    int y(4);

    if ( /* condition manquante */ f(x , y) ){
        cout << x + y << " " << x << " " << y << endl;
    }
    else {
        cout << x * y << " " << y << " " << x << endl;
    }
    return 0;

}
