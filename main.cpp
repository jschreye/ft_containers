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
    x.push_back(4);
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    y.push_back(4);
    y.push_back(5);
    std::cout << y.size() << std::endl;
    std::cout << "The first character is x '" << x.front() << "'.\n";
    std::cout << "The first character is x '" << x.back() << "'.\n";
    std::cout << "The first character is y '" << y.front() << "'.\n";
    std::cout << "The first character is y '" << y.back() << "'.\n";/*
    x.pop_back();
    y.pop_back();
    //std::cout << "The first character is x'" << x.front() << "'.\n";
    //std::cout << "The first character is x'" << x.back() << "'.\n";
    std::cout << "The first character is y'" << y.front() << "'.\n";
    std::cout << "The first character is y'" << y.back() << "'.\n";
    y.push_back('c');
    std::cout << "The first character is y'" << y.back() << "'.\n";*/
    return (0);
}