#include "vector.hpp"
//#include "stack.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <memory>
#include "tree.hpp"

int main()
{
    /*std::vector<int> x;
    ft::vector<int> y;
    y.push_back(0);
    y.push_back(1);
    y.push_back(2);
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    
    std::cout << "The first character is x '" << x.front() << "'.\n";
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
    y.swap(y);
    std::cout << "The first character is x '" << x.front() << "'.\n";
    std::cout << "The first character is x '" << x.back() << "'.\n";
    std::cout << "The first character is y '" << y.front() << "'.\n";
    std::cout << "The first character is y '" << y.back() << "'.\n";
    x.swap(x);
    std::cout << "The first character is x '" << x.front() << "'.\n";
    std::cout << "The first character is x '" << x.back() << "'.\n";
    std::cout << "The first character is y '" << y.front() << "'.\n";
    std::cout << "The first character is y '" << y.back() << "'.\n";
    x.assign(2, 1111);
    const std::string extra(9, 'z');
    y.assign(extra.begin(), extra.end());
    for (size_t i = 0; i < y.size(); i++)
        std::cout << y[i] << " il y a ca " << std::endl;
    for (size_t i = 0; i < x.size(); i++)
        std::cout << x[i] << " il y a ca dans x " << std::endl;
    x.insert(x.begin() +3 , 5, 9);
    y.insert(y.begin()+3, 5, 9);
    
    for (size_t i = 0; i < x.size(); i++)
        std::cout << "x :" << x[i] << std::endl;
    for (size_t i = 0; i < y.size(); i++)
        std::cout << " y :" << y[i] << std::endl;*/
  //On cree un nouvel arbre, qui contiendra des entiers 
    ft::Cl_Arbre <char> arbre; 
  
  //On le remplit de valeurs 
    arbre.Creer('C'); 
    arbre.Creer('A'); 
    arbre.Creer('X'); 
    arbre.Creer('Z'); 
    arbre.Creer('T'); 
    arbre.Creer('I'); 
    arbre.Creer('H'); 
    arbre.Creer('M');
  
  //En affichant, on se rend compte que l arbre est trié 
  //Magique ! 
    arbre.Affichage(); 
    std::cout << "\nFIN PROGRAM 1" << std::endl;
    arbre.Supprimer('Z'); 
    arbre.Affichage(); 
    std::cout << "\nFIN PROGRAM 2" << std::endl;
    arbre.NbrNoeuds();

    return (0);
}












                /* mon ancien insert
                pointer new_vector = NULL;
                size_type pos = position - this->begin();
                size_type end = this->end() - this->begin();
                size_type i = 0;

                if (pos <= this->_size)
                {
                    new_vector = _space.allocate(this->_size + n);
                    for (i = 0; i < pos; i++)
                        _space.construct(new_vector + i, this->_vector[i]);
                    for (; i - pos < n; i++)
                        _space.construct(new_vector + i, val);
                    for (; i < end + n; i++)
                        _space.construct(new_vector + i, this->_vector[i - n]);
                    _space.deallocate(this->_vector, this->_capacity);
                    this->_vector = new_vector;
                    this->_capacity = _capacity + n;
                    this->_size = _size + n;
                }
                else if (pos > this->_size)
                {
                    new_vector = _space.allocate(pos + n);
                    if (i > pos)
                        for (i = 0; i < pos; i++)
                            _space.construct(new_vector + i, _vector[i - n]);
                    else if (i <= pos)
                        for (i = 0; i < pos; i++)
                            _space.construct(new_vector + i, _vector[i]);
                    else if (i >= pos)
                        for (; i - pos < n; i++)
                            _space.construct(new_vector + i, val);
                    else if (i < pos)
                        for (; pos - i < n; i++)
                            _space.construct(new_vector + i, val);
                    for (; i < end; i++)
                        _space.construct(new_vector + i + 1, _vector[i - n]);
                    _space.deallocate(this->_vector, this->_capacity);
                    this->_vector = new_vector;
                    this->_size = pos + n;
                    this->_capacity = pos + n;
                }
                */ 