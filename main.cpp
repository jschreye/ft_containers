#include "vector.hpp"
//#include "stack.hpp"
//#include "map.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> x(2);
    ft::vector<int> y(2);

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
   /* x.insert(x.begin(), 3, 4);
    y.insert(y.begin(), 3, 4);
    for (size_t i = 0; i < x.size(); i++)
        std::cout << "x :" << x[i] << " y :" << y[i] << std::endl;*/
    //x.insert(x.begin() + 5, 4, 9);
    //y.insert(y.begin() + 5, 9);
    for (size_t i = 0; i < x.size(); i++)
        std::cout << "x :" << x[i] << std::endl;
    for (size_t i = 0; i < y.size(); i++)
        std::cout << " y :" << y[i] << std::endl;

    return (0);
}


/*
truc tanguy pour insert
            {
                pointer new_vector = this->_vector;
                size_type pos = position - this->begin();
                size_type first = 0;
                size_type end = _size;
                size_type i;
                std::cout << "pos = "<< pos << "size = " << _size << "first  = " << first << "end = " << end << std::endl;
                if (this->_size == this->_capacity || _size == 0)
                {
                    new_vector = _space.allocate(this->_size + 1);
                    for (i = 0; i < pos; i++)
                        _space.construct(new_vector + i, this->_vector[i]);
                    this->_capacity++;
                }  
                if (pos <= this->_size)
                {
                    std::cout << "1" << std::endl;
                    _space.construct(new_vector + pos, val);
                    for (i = end; i > pos; i--)
                    {
                         //std::cout << i << std::endl;
                        _space.construct(new_vector + i + 1, this->_vector[i]);
                    }
                }
                //_space.deallocate(this->_vector, this->_capacity);
                this->_vector = new_vector;
                this->_size++;
                return this->_vector + pos; 
            }
*/