#include "vector.hpp"
//#include "stack.hpp"
//#include "map.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> x;
    ft::vector<int> y;

    for (int i = 0; i < 3; i++)
    {
        x[i] = i;
        y[i] = i;
    }

    std::cout << "The first character is '" << x.front() << "'.\n";
    std::cout << "The first character is '" << y.front() << "'.\n";
    
    return (0);
}