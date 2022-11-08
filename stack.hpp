#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "vector.hpp"
#include <cstddef>

namespace ft
{

// TODO: tests

    template<class T, class Container = ft::vector<T> >
    class stack
    {
        private:

            Container	_c;

        public:
            stack()
            {

            }

            stack(const stack &)
            {

            }
            stack &operator=(const stack &)
            {

            }

            ~stack()
            {

            }

            bool empty() const
            {
                return _c.empty();
            }

            size_t size() const
            {
                return _c.size();
            }

            T &top()
            {
                return _c.back();
            }

            const T &top() const
            {
                return _c.back();
            }

            void push (const T & val)
            {
                _c.push_back(val);
            }

            void pop()
            {
                _c.pop_back();
            }

            friend bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
            friend bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
            friend bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
            friend bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
            friend bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
            friend bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
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

} // NAMEPACE ft

#endif