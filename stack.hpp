#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#include <cstddef>

namespace ft
{
    template<class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef Container   container_type;
            typedef T           value_type;
            typedef size_t      size_type;

        protected:
            container_type	_c;

        public:
            explicit stack(const Container & c = Container()): _c(c) {}

            stack(const stack & rhs)
            {
                *this = rhs;
            }

            stack &operator=(const stack & rhs)
            {
                if (this != &rhs)
                    this->_c = rhs._c;
                return (*this);
            }

            ~stack()
            {

            }

            bool empty() const
            {
                return _c.empty();
            }

            size_type size() const
            {
                return _c.size();
            }

            value_type &top()
            {
                return _c.back();
            }

            const value_type &top() const
            {
                return _c.back();
            }

            void push (const value_type & val)
            {
                _c.push_back(val);
            }

            void pop()
            {
                _c.pop_back();
            }
            template<class Type, class Cont>
            friend bool operator==(const stack<Type, Cont>& lhs, const stack<Type, Cont>& rhs);
            template<class Type, class Cont>
            friend bool operator!=(const stack<Type, Cont>& lhs, const stack<Type, Cont>& rhs);
            template<class Type, class Cont>
            friend bool operator<(const stack<Type, Cont>& lhs, const stack<Type, Cont>& rhs);
            template<class Type, class Cont>
            friend bool operator<=(const stack<Type, Cont>& lhs, const stack<Type, Cont>& rhs);
            template<class Type, class Cont>
            friend bool operator>(const stack<Type, Cont>& lhs, const stack<Type, Cont>& rhs);
            template<class Type, class Cont>
            friend bool operator>=(const stack<Type, Cont>& lhs, const stack<Type, Cont>& rhs);
    };

    template<class T, class Container>
    bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    {
        return (lhs._c == rhs._c);
    }

    template<class T, class Container>
    bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    {
        return !(lhs == rhs);
    }

    template<class T, class Container>
    bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    {
        return lhs._c < rhs._c;
    }

    template<class T, class Container>
    bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    {
        return lhs._c <= rhs._c;
    }

    template<class T, class Container>
    bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    {
        return lhs._c > rhs._c;
    }

    template<class T, class Container>
    bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    {
        return lhs._c >= rhs._c;
    }

}

#endif