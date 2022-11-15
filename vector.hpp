#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "enable_if.hpp"
#include "equal.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "lexico.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:

            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::difference_type    difference_type;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef pointer                                     iterator;
            typedef const_pointer                               const_iterator;
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

        private:

            allocator_type  _alloc; //l'allocation memoir
            pointer         _begin; //pointeur sur tableau
            pointer         _end; //pointeur sur fin de tableau
            size_type       _capacity; //taille max de la memoir allouée

        public:

            //constructor
            explicit vector (const allocator_type& alloc = allocator_type())
            : _alloc(alloc), _begin(), _end(), _capacity() {}

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            : _alloc(alloc), _begin(), _end(), _capacity(n)
            {
                this->_begin = this->_alloc.allocate(n);
                this->_end = this->_begin;
                assign(n, val);
            }
            
            template <class InputIterator>
            vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type() )
            : _alloc(alloc), _begin(), _end(), _capacity()
            {
                size_type n = ft::distance(first, last);

                this->_begin = _alloc.allocate(n);
                this->_end = this->_begin;
                assign(first, last);
            }
            
            vector (const vector& x)
            : _alloc(x._alloc), _begin(), _end(), _capacity(x._capacity)
            {
                this->_begin = _alloc.allocate(this->_capacity);
                this->_end = this->_begin;
                this->assign(x.begin(), x.end());
            }

            //destructor
            ~vector() 
            {
                clear();
                this->_alloc.deallocate(this->_begin, this->_capacity);
            }

            //operator assignement
            vector& operator=(const vector& rhs)
            {
                if(this != &rhs)
                    this->assign(rhs.begin(), rhs.end());
                return *this;
            }

            //iterator
            iterator begin()                        {return iterator(this->_begin);}
            const_iterator begin() const            {return const_iterator(this->_begin);}
            iterator end()                          {return iterator(this->_end);}
            const_iterator end() const              {return const_iterator(this->_end);}
            reverse_iterator rbegin()               {return reverse_iterator(this->_end);}
            const_reverse_iterator rbegin() const   {return const_reverse_iterator(this->_end);}
            reverse_iterator rend()                 {return reverse_iterator(this->_begin);}
            const_reverse_iterator rend() const     {return const_reverse_iterator(this->_begin);}

            //capacity
            size_type size() const                  {return this->_end - this->_begin;}
            size_type max_size() const              {return _alloc.max_size();}

            void resize (size_type n, value_type val = value_type())
            {
                if (n > max_size())
                    throw std::length_error("Length error: vector::reserve");
                if (n < size())
                {
                    pointer	tmp = this->_begin + n;
                    while (tmp != this->_end)
                    {
                        this->_alloc.destroy(tmp);
                        tmp++;
                    }
                    this->_end = this->_begin + n;
                }
                else if (n > size())
                {
                    if (n > this->_capacity)
                    {
                        if (n <= this->_capacity * 2)
                            reserve(this->_capacity * 2);
                        else
                            reserve(n);
                    }
                    for (size_t i = size(); i < n; i++)
                    {
                        this->_alloc.construct(this->_end, val);
                        this->_end++;
                    }
                }
            }

            size_type capacity() const  {return this->_capacity;}
            bool empty() const          {return this->_begin == this->_end;}
            void reserve (size_type n)
            {
                if (n > max_size())
                    throw std::length_error("Length error: vector::reserve");
                if (n > capacity())
                {
                    pointer tmp = this->_alloc.allocate(n);
                    int i = 0;
                    while (this->_begin + i != this->_end)
                    {
                        this->_alloc.construct(&tmp[i], *(this->_begin + i));
                        i++;
                    }
                    clear();
                    this->_alloc.deallocate(this->_begin, this->_capacity);
                    this->_begin = tmp;
                    this->_end = this->_begin + i;
                    this->_capacity = n;
                }
            }

            //element access
            reference operator[] (size_type n)              {return this->_begin[n];}
            const_reference operator[] (size_type n) const  {return this->_begin[n];}

            reference at (size_type n)
            {
                if (n >= this->size() || n < 0)
                    throw std::out_of_range("Index used is out of range");
                return (this->_begin[n]);
            }

            const_reference at (size_type n) const
            {
                if (n >= this->size()|| n < 0)
                    throw std::out_of_range("Index used is out of range");
                return (this->_begin[n]);
            }

            reference front()               {return *this->_begin;}
            const_reference front() const   {return *this->_begin;}
            reference back()                {return *(this->_end - 1);}
            const_reference back() const    {return *(this->_end - 1);}
            value_type* data()              {return this->_begin;}
            const value_type* data() const  {return this->_begin;}

            //modifiers
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last)
            {
                this->clear();
                this->insert(this->begin(), first, last);
            }

            void assign (size_type n, const value_type& val)
            {
                this->clear();
                this->insert(this->begin(), n, val);
            }

            void push_back (const value_type& val)                                      
            {
                if (this->size() == 0)
                    this->reserve(1);
                else if (this->size() + 1 > this->capacity())
                    this->reserve(this->capacity() * 2);
                this->_alloc.construct(this->_end, val);
                this->_end++;
            }

            void pop_back()
            {
                if (!(this->empty()))
                {  
                    this->_alloc.destroy(this->_end - 1);
                    this->_end--;
                }
            }

            iterator insert (iterator position, const value_type& val)
            {
                insert(position, 1, val);
                return position;
            }

            void insert (iterator position, size_type n, const value_type& val)
            {
                if (n > max_size() || n + size() > max_size())
                    throw std::length_error("Length error: vector::insert");
                size_type start = ft::distance(begin(), position);
                size_type end = size();
                resize(size() + n);
                ft::copy_backward(begin() + start, begin() + end, begin() + start + n);
                ft::fill(begin() + start, begin() + start + n, val);
            }
            
            template <class InputIterator>
            void insert (iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
            {
                size_type n = ft::distance(first, last);
                if (n > max_size() || n + size() > max_size())
                    throw std::length_error("Length error: vector::insert");
                size_type start = distance(begin(), position);
                size_type end = size();
                resize(size() + n);
                ft::copy_backward(begin() + start, begin() + end, begin() + start + n);
                for (size_t i = 0; i < n; i++)
                {
                    *(this->_begin + start + i) = *first;
                    first++;
                }
            }
            
            iterator erase (iterator position)
            {
                return erase(position, position + 1);
            }

            iterator erase (iterator first, iterator last)
            {
                size_type n = ft::distance(first, last);
                pointer  tmp = this->_begin + (size() - n);
                ft::copy(last, end(), first);
                while (tmp != this->_end)
                {
                    this->_alloc.destroy(tmp);
                    tmp++;
                }
                this->_end -= ft::distance(first, last);
                return first;
            }

            void swap (vector<T,Alloc>& x)
            {
                ft::swap(_end, x._end);
                ft::swap(_begin, x._begin);
                ft::swap(_capacity, x._capacity);
            }

            void clear()
            {
                pointer	tmp = this->_begin;	
                while (tmp != this->_end)
                {
                    this->_alloc.destroy(tmp);
                    tmp++;
                }
                this->_end = this->_begin;
            }
            //allocator
            allocator_type get_allocator() const    {return this->_alloc;}

    };

    //function non membre
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        	vector<T, Alloc> temp = x;
	        x = y;
	        y = temp;
    }

    //operator non membre	
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return rhs < lhs;
    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(rhs > lhs);
    }
}
#endif