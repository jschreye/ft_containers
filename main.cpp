#include "vector.hpp"
//#include "stack.hpp"
//#include "map.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> x;
    ft::vector<int> y;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    /*std::cout << "The first character is x '" << x.front() << "'.\n";
    std::cout << "The first character is x '" << x.back() << "'.\n";
    std::cout << "The first character is y '" << y.back() << "'.\n";
    std::cout << "The first character is y '" << y.front() << "'.\n";
    x.pop_back();
    y.pop_back();
    std::cout << "The first character is x '" << x.front() << "'.\n";
    std::cout << "The first character is x '" << x.back() << "'.\n";
    std::cout << "The first character is y '" << y.front() << "'.\n";
    std::cout << "The first character is y '" << y.back() << "'.\n";
    y.push_back('c');
    std::cout << "The first character is y '" << y.back() << "'.\n";
    swap(x, y);
    std::cout << "The first character is x '" << x.front() << "'.\n";
    std::cout << "The first character is x '" << x.back() << "'.\n";
    std::cout << "The first character is y '" << y.front() << "'.\n";
    std::cout << "The first character is y '" << y.back() << "'.\n";
    y.swap(x);
    std::cout << "The first character is x '" << x.front() << "'.\n";
    std::cout << "The first character is x '" << x.back() << "'.\n";
    std::cout << "The first character is y '" << y.front() << "'.\n";
    std::cout << "The first character is y '" << y.back() << "'.\n";*/
    /*x.assign(2, 1111);
    const std::string extra(9, 'z');
    y.assign(extra.begin(), extra.end());
    for (size_t i = 0; i < y.size(); i++)
        std::cout << y[i] << " il y a ca " << std::endl;
    for (size_t i = 0; i < x.size(); i++)
        std::cout << x[i] << " il y a ca dans x " << std::endl;*/

    std::cout << *(x.erase(x.begin() + 2)) << std::endl;
    std::cout << *(y.erase(y.begin() + 2)) << std::endl;

    for (size_t i = 0; i < y.size(); i++)
        std::cout << y[i] << " il y a ca dans y " << std::endl;
    for (size_t i = 0; i < x.size(); i++)
        std::cout << x[i] << " il y a ca dans x " << std::endl;

    return (0);
}