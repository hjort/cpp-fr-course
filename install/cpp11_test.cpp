#include <iostream>
#include <vector>

int main()
{
     std::vector<std::vector<double>> matrice { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

     std::cout << "Bonjour, voici une matrice:" << std::endl;
     for (auto element : matrice) {
	  for (auto val : element) {
	       std::cout << val << " ";
	  }
	  std::cout << std::endl;
     }
     std::cout << std::endl;

     return 0;
}
