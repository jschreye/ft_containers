#include "vector.hpp"
//#include "stack.hpp"
#include "map.hpp"
#include <vector>
#include <iostream>
#include <memory>
#include <map>

int main()
{
    std::cout << "..................VECTOR......................" << std::endl << std::endl;
    std::cout << "................CONSTRUCTOR..................." << std::endl;
    std::vector<int> std_v1;
    std::vector<int> std_v2(2, 2);
    std::vector<int> std_v3(std_v2.begin(), std_v2.end());
    std::vector<int> std_v4(std_v3);
    ft::vector<int> ft_v1;
    ft::vector<int> ft_v2(2, 2);
    ft::vector<int> ft_v3(ft_v2.begin(), ft_v2.end());
    ft::vector<int> ft_v4(ft_v3);
    for(size_t i = 0; std_v4[i]; i++)
        std::cout << "std_v4 = " << std_v4[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v4[i]; i++)
        std::cout << "ft_v4 = " << ft_v4[i] << std::endl;
    std::cout << std::endl;

    std::cout << "................OPERATOR..................." << std::endl;
    std_v1 = std_v4;
    ft_v1 = ft_v4;
    for(size_t i = 0; std_v1[i]; i++)
        std::cout << "std_v1 = " << std_v1[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v1[i]; i++)
        std::cout << "ft_v1 = " << ft_v1[i] << std::endl;
    std::cout << std::endl;

    std::cout << "................ITERATOR...................." << std::endl;
    std::cout << std::endl;

    std::cout << "..................SIZE......................" << std::endl;
    std::cout << "std_v2 = " << std_v2.size() << std::endl;
    std::cout << "ft_v2 = " << ft_v2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "std_v2 = " << std_v2.max_size() << std::endl;
    std::cout << "ft_v2 = " << ft_v2.max_size() << std::endl;
    std::cout << std::endl;

    std::cout << "..................RESIZE......................" << std::endl;
    std_v2.clear();
    ft_v2.clear();
    for(size_t i = 1; i < 10; i++)
        std_v2.push_back(i);
    for(size_t i = 1; i < 10; i++)
        ft_v2.push_back(i);
    std::cout << std::endl;
    std_v2.resize(5);
    ft_v2.resize(5);
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;
    std_v2.resize(8, 100);
    ft_v2.resize(8, 100);
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;
    std_v2.resize(12);
    ft_v2.resize(12);
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;

    std::cout << ".................CAPACITY...................." << std::endl;
    std::cout << std_v2.capacity() << std::endl;
    std::cout << ft_v2.capacity() << std::endl; 
    std::cout << std::endl;

    std::cout << ".................EMPTY......................." << std::endl;
    std::cout << std_v2.empty() << std::endl;
    std::cout << ft_v2.empty() << std::endl;
    //std_v2.clear();
    //ft_v2.clear();
    std::cout << std_v2.empty() << std::endl;
    std::cout << ft_v2.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "................RESERVE......................" << std::endl;
    std::cout << std_v2.capacity() << std::endl;
    std::cout << ft_v2.capacity() << std::endl; 
    std::cout << std::endl;
    std_v2.reserve(20);
    ft_v2.reserve(20);
    std::cout << std_v2.capacity() << std::endl;
    std::cout << ft_v2.capacity() << std::endl; 
    std::cout << std::endl;

    std::cout << "...................AT........................" << std::endl;
    std::cout << std_v2.at(9) << std::endl;
    std::cout << ft_v2.at(9) << std::endl;
    std::cout << std::endl;

    std::cout << "................FRONT/BACK/DATA.............." << std::endl;
    std::cout << std_v2.front() << std::endl;
    std::cout << ft_v2.front() << std::endl;
    std::cout << std::endl;
    std::cout << std_v2.back() << std::endl;
    std::cout << ft_v2.back() << std::endl;
    std::cout << std::endl;
    std::cout << std_v2.data() << std::endl;
    std::cout << ft_v2.data() << std::endl;
    std::cout << std::endl;

    std::cout << ".................ASSIGNE....................." << std::endl;
    std_v2.assign(5, 99);
    ft_v2.assign(5, 99);   
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;
    std_v2.assign(std_v1.begin(), std_v1.end());
    ft_v2.assign(ft_v1.begin(), ft_v1.end());   
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;

    std::cout << "..................PUSH_BACK................" << std::endl;
    for(size_t i = 0; i < 10; i++)
        std_v2.push_back(3);
    for(size_t i = 0; i < 10; i++)
        ft_v2.push_back(3);
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "..................POP_BACK................" << std::endl;
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;
    std_v2.pop_back();
    ft_v2.pop_back();
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;

    std::cout << ".................INSERT......................" << std::endl;
    std_v2.insert(std_v2.begin() + 1, 10);
    ft_v2.insert(ft_v2.begin() + 1, 10);
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;
    std_v2.insert(std_v2.begin() + 1, 2, 8);
    ft_v2.insert(ft_v2.begin() + 1, 2, 8);
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;
    std_v2.insert(std_v2.begin(), std_v1.begin(), std_v1.end());
    ft_v2.insert(ft_v2.begin(), ft_v1.begin(), ft_v1.end());
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;

    std::cout << "...................ERASE...................." << std::endl;
    std_v2.erase(std_v2.begin() + 1);
    ft_v2.erase(ft_v2.begin() + 1);
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;

    std::cout << "...................MAP......................." << std::endl << std::endl;
    std::map <std::string, int> map1;
    ft::map <std::string, int> map2;
    map1["cat"] = 1;
    map1["chien"] = 2;
    map1.insert(std::make_pair("chat", 3));
    map2["cat"] = 1;
    map2["chien"] = 2;
    map2.insert(ft::make_pair("chat", 3));
    std::map<std::string, int>::iterator it;
    for(it = map1.begin(); it != map1.end(); it++)
        std::cout << it->first << " => " << it->second << std::endl;
    ft::map<std::string, int>::iterator it2;
    for(it2 = map2.begin(); it2 != map2.end(); it2++)
        std::cout << it2->first << " => " << it2->second << std::endl;


   
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