#include "vector.hpp"
//#include "stack.hpp"
//#include "map.hpp"
#include <vector>
#include <iostream>

int main()
{
    ft::vector<int> x;
    ft::vector<int> y;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    y.push_back('a');
    y.push_back('b');
    y.push_back('z');
    /*
    std::cout << "The first character is x '" << x.front() << "'.\n";
    std::cout << "The first character is x '" << x.back() << "'.\n";
    std::cout << "The first character is y '" << y.front() << "'.\n";
    std::cout << "The first character is y '" << y.back() << "'.\n";
    x.pop_back();
    y.pop_back();
    std::cout << "The first character is x '" << x.front() << "'.\n";
    std::cout << "The first character is x '" << x.back() << "'.\n";
    std::cout << "The first character is y '" << y.front() << "'.\n";
    std::cout << "The first character is y '" << y.back() << "'.\n";
    y.push_back('c');
    std::cout << "The first character is y '" << y.back() << "'.\n";
    */
    swap(x, y);
    std::cout << "The first character is x '" << x.front() << "'.\n";
    std::cout << "The first character is x '" << x.back() << "'.\n";
    std::cout << "The first character is y '" << y.front() << "'.\n";
    std::cout << "The first character is y '" << y.back() << "'.\n";
    y.swap(x);
    std::cout << "The first character is x '" << x.front() << "'.\n";
    std::cout << "The first character is x '" << x.back() << "'.\n";
    std::cout << "The first character is y '" << y.front() << "'.\n";
    std::cout << "The first character is y '" << y.back() << "'.\n";
    return (0);
}