#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include "vector.hpp"

namespace ft
{
    template <class T, class Container = vector<T> >
    class stack
    {
        private:

        public:

            //constructor
            explicit stack (const container_type& ctnr = container_type());

            //function membre
            bool empty() const;
            size_type size() const;
            value_type& top();
            const value_type& top() const;
            void push (const value_type& val);

            template <class... Args>
            void emplace (Args&&... args);
            
            void pop();
            void swap (stack& x) noexcept(/*see below*/);
    };
};

template <class T, class Container>
void swap (stack<T,Container>& x, stack<T,Container>& y) noexcept(noexcept(x.swap(y)));

template <class T, class Container>
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	
template <class T, class Container>
bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	
template <class T, class Container>
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	
template <class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

#endif