#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <vector>
#include <stack>
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
    if (std_v1 == std_v2)
        std::cout << "std = true" << std::endl;
    else 
        std::cout << "std = false" << std::endl;
    if (std_v1 != std_v2)
        std::cout << "std = true" << std::endl;
    else 
        std::cout << "std = false" << std::endl;
    if (std_v1 < std_v2)
        std::cout << "std = true" << std::endl;
    else 
        std::cout << "std = false" << std::endl;
    if (std_v1 > std_v2)
        std::cout << "std = true" << std::endl;
    else 
        std::cout << "std = false" << std::endl;
    if (std_v1 <= std_v2)
        std::cout << "std = true" << std::endl;
    else 
        std::cout << "std = false" << std::endl;
    if (std_v1 >= std_v2)
        std::cout << "std = true" << std::endl;
    else 
        std::cout << "std = false" << std::endl;
    std::cout << std::endl;
    if (ft_v1 == ft_v2)
        std::cout << "ft = true" << std::endl;
    else 
        std::cout << "ft = false" << std::endl;
    if (ft_v1 != ft_v2)
        std::cout << "ft = true" << std::endl;
    else 
        std::cout << "ft = false" << std::endl;
    if (ft_v1 < ft_v2)
        std::cout << "ft = true" << std::endl;
    else 
        std::cout << "ft = false" << std::endl;
    if (ft_v1 > ft_v2)
        std::cout << "ft = true" << std::endl;
    else 
        std::cout << "ft = false" << std::endl;
    if (ft_v1 <= ft_v2)
        std::cout << "ft = true" << std::endl;
    else 
        std::cout << "ft = false" << std::endl;
    if (ft_v1 >= ft_v2)
        std::cout << "ft = true" << std::endl;
    else 
        std::cout << "ft = false" << std::endl;
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
    std_v2.reserve(12);
    ft_v2.reserve(12);
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
    std_v1.push_back(999);
    ft_v1.push_back(999);
    for(size_t i = 0; std_v1[i]; i++)
        std::cout << "std_v1 = " << std_v1[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v1[i]; i++)
        std::cout << "ft_v1 = " << ft_v1[i] << std::endl;
    std::cout << std::endl;

    std::cout << "..................POP_BACK................" << std::endl;
    std::cout << "std_v1 = " << std_v1.size() << std::endl;
    std::cout << "ft_v1 = " << ft_v1.size() << std::endl;
    std::cout << std::endl;
    std_v1.pop_back();
    ft_v1.pop_back();
    for(size_t i = 0; std_v1[i]; i++)
        std::cout << "std_v1 = " << std_v1[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v1[i]; i++)
        std::cout << "ft_v1 = " << ft_v1[i] << std::endl;
    std::cout << std::endl;
    std::cout << "std_v1 = " << std_v1.size() << std::endl;
    std::cout << "ft_v1 = " << ft_v1.size() << std::endl;
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
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;
    std_v2.erase(std_v2.begin() + 1);
    ft_v2.erase(ft_v2.begin() + 1);
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;
    std_v2.erase(std_v2.begin(), std_v2.begin() + 3);
    ft_v2.erase(ft_v2.begin(), ft_v2.begin() + 3);
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;

    std::cout << "..................SWAP......................." << std::endl << std::endl;
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;
    std_v2.swap(std_v1);
    ft_v2.swap(ft_v1);
    for(size_t i = 0; std_v2[i]; i++)
        std::cout << "std_v2 = " << std_v2[i] << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; ft_v2[i]; i++)
        std::cout << "ft_v2 = " << ft_v2[i] << std::endl;
    std::cout << std::endl;
    std::swap(std_v1, std_v2);
    ft::swap(ft_v1, ft_v2);
    std::cout << std::endl;

    std::cout << "..............GET_ALLOCATOR.................." << std::endl << std::endl;
    int *std_p = std_v2.get_allocator().allocate(5);
    int *ft_p = ft_v2.get_allocator().allocate(5);
    std::cout << std_p << std::endl;
    std::cout << ft_p << std::endl;
    delete std_p;
    delete ft_p;
    std::cout << std::endl;

    std::cout << "...................MAP......................." << std::endl << std::endl;
    std::cout << "..........INSERT AND BEGIN AND END..........." << std::endl << std::endl;
    std::map <std::string, int> std_map1;
    ft::map <std::string, int> ft_map1;
    std_map1["cat"] = 1;
    std_map1["chien"] = 2;
    std_map1.insert(std::make_pair("chat", 3));
    ft_map1["cat"] = 1;
    ft_map1["chien"] = 2;
    ft_map1.insert(ft::make_pair("chat", 3));
    std::map<std::string, int>::iterator it;
    for(it = std_map1.begin(); it != std_map1.end(); it++)
        std::cout << it->first << " => " << it->second << std::endl;
    ft::map<std::string, int>::iterator it2;
    for(it2 = ft_map1.begin(); it2 != ft_map1.end(); it2++)
        std::cout << it2->first << " => " << it2->second << std::endl;
    std::cout << std::endl;

    std::cout << "..............SIZE AND MAXSIZE.............." << std::endl << std::endl;    
    std::cout << "std_map1 = " << std_map1.size() << std::endl;
    std::cout << "ft_map2 = " << ft_map1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "std_map1 = " << std_map1.max_size() << std::endl;
    std::cout << "ft_map1 = " << ft_map1.max_size() << std::endl;
    std::cout << std::endl;    

    std::cout << "....................SWAP...................." << std::endl << std::endl;
    std::map <std::string, int> std_map2;
    ft::map <std::string, int> ft_map2;
    std_map2["dog"] = 1;
    std_map2["oiseau"] = 2;
    std_map2.insert(std::make_pair("poulet", 3));
    ft_map2["dog"] = 1;
    ft_map2["oiseau"] = 2;
    ft_map2.insert(ft::make_pair("poulet", 3));
    for(it = std_map1.begin(); it != std_map1.end(); it++)
        std::cout << "std_map1 = " << it->first << " => " << it->second << std::endl;
    std_map1.swap(std_map2);
    for(it = std_map1.begin(); it != std_map1.end(); it++)
        std::cout << "std_map1 = " << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
    for(it2 = ft_map1.begin(); it2 != ft_map1.end(); it2++)
        std::cout << "ft_map1 = " << it2->first << " => " << it2->second << std::endl;
    ft_map1.swap(ft_map2);
    for(it2 = ft_map1.begin(); it2 != ft_map1.end(); it2++)
        std::cout << "ft_map1 = " << it2->first << " => " << it2->second << std::endl;
    std::cout << std::endl;

    std::cout << "..................ERASE....................." << std::endl << std::endl;
    std_map1.erase(std_map1.begin());
    for(it = std_map1.begin(); it != std_map1.end(); it++)
        std::cout << "std_map1 = " << it->first << " => " << it->second << std::endl;
    ft_map1.erase(ft_map1.begin());
    for(it2 = ft_map1.begin(); it2 != ft_map1.end(); it2++)
        std::cout << "ft_map1 = " << it2->first << " => " << it2->second << std::endl;
    std::cout << std::endl;
    std_map1.erase("poulet");
    for(it = std_map1.begin(); it != std_map1.end(); it++)
        std::cout << "std_map1 = " << it->first << " => " << it->second << std::endl;
    ft_map1.erase("poulet");
    for(it2 = ft_map1.begin(); it2 != ft_map1.end(); it2++)
        std::cout << "ft_map1 = " << it2->first << " => " << it2->second << std::endl;
    std_map1.erase(std_map1.begin(), std_map1.end());
    ft_map1.erase(ft_map1.begin(), ft_map1.end());
    std::cout << std::endl; 
    std::cout << "std_map1 = " << std_map1.empty() << std::endl;
    std::cout << "ft_map1 = " << ft_map1.empty() << std::endl;
    std::cout << std::endl;        

    std::cout << "..................STACK....................." << std::endl << std::endl;
    std::cout << "..................EMPTY....................." << std::endl << std::endl;
    std::stack<int> std_stack;
    ft::stack<int> ft_stack;
    std::cout << "std_stack = " << std_stack.empty() << std::endl;
    std::cout << "ft_stack = " << ft_stack.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "...........PUSH AND TOP AND POP............." << std::endl << std::endl;
    std_stack.push(1);
    std::cout <<  "std_stack = " << std_stack.top() << std::endl;
    std_stack.push(2);
    std::cout <<  "std_stack = " << std_stack.top() << std::endl;
    std_stack.push(3);
    //std_stack.pop();
    std::cout <<  "std_stack = " << std_stack.top() << std::endl;
    std::cout << std::endl;

    ft_stack.push(1);
    std::cout << "ft_stack = " << ft_stack.top() << std::endl;
    ft_stack.push(2);
    std::cout << "ft_stack = " << ft_stack.top() << std::endl;
    ft_stack.push(3);
    //ft_stack.pop();
    std::cout << "ft_stack = " << ft_stack.top() << std::endl;
    std::cout << std::endl;
    std::cout << "..................EMPTY....................." << std::endl << std::endl;
    std::cout << "std_stack = " << std_stack.empty() << std::endl;
    std::cout << "ft_stack = " << ft_stack.empty() << std::endl;
    std::cout << std::endl;
    std::cout << "...................SIZE....................." << std::endl << std::endl;
    std::cout << "std_stack = " << std_stack.size() << std::endl;
    std::cout << "ft_stack = " << ft_stack.size() << std::endl;
    return (0);
}
