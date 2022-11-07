#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "iterator_traits.hpp"
#include "enable_if.hpp"
#include "iterator.hpp"
#include "equal.hpp"
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
            typedef ft::reverse_iterator<iterator>             reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>       const_reverse_iterator;

        private: // "variable"

            allocator_type  _space; //l'allocation memoir
            pointer         _vector; //pointeur sur tableau
            size_type       _capacity; //taille max de la memoir allouee
            size_type       _size; //taille en cour
        
        private: //pour les fonctions



        public:

            //constructor
            explicit vector (const allocator_type& alloc = allocator_type())
            : _space(alloc), _vector(NULL), _capacity(0), _size(0) {}

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            : _space(alloc), _vector(NULL), _capacity(n), _size(n) 
            {
                this->_vector = this->_space.allocate(n);
                for (size_type i = 0; i < _size; i++)
                    this->_space.construct((this->_vector + i), val);
            }
            
            template <class InputIterator>
            vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
                        InputIterator last, const allocator_type &alloc = allocator_type() ) : _space(alloc)
            {
                size_type diff = ft::distance(first, last);
                _vector = _space.allocate(diff);
                _size = diff;
                _capacity = diff;

                for (size_t i = 0; i < diff; i++)
                {
                    _space.construct((_vector + i), *first++);
                }
            }
            
            vector (const vector& x)
            : _space(x._space), _vector(NULL), _capacity(0), _size(0)
            {
                *this = x;
            }

            //destructor
            ~vector() 
            {
                clear();
                if (this->capacity() != 0)
                    _space.deallocate(_vector, _capacity);
            }

            //operator assignement
            vector& operator=(const vector& rhs)
            {
                if(this != &rhs)
                    this->assign(rhs.begin(), rhs.end());
                return *this;
            }

            //iterator
            iterator begin()                        {return iterator(this->_vector);}
            const_iterator begin() const            {return const_iterator(this->_vector);}
            iterator end()                          {return iterator(this->_vector + this->_size);}
            const_iterator end() const              {return const_iterator(this->_vector + this->_size);}
            reverse_iterator rbegin()               {return reverse_iterator(iterator(this->end()));}
            const_reverse_iterator rbegin() const   {return const_reverse_iterator(iterator(this->end));}
            reverse_iterator rend()                 {return reverse_iterator(iterator(this->begin()));}
            const_reverse_iterator rend() const     {return const_reverse_iterator(iterator(this->begin()));}

            //capacity
            size_type size() const                  {return this->_size;}
            size_type max_size() const              {return _space.max_size();}

            void resize (size_type n, value_type val = value_type())
            {
                if (n < _size)
                {
                    for (; _size != n; _size--)
                        _space.destroy(_vector + _size);
                }
                else if (n > _size)
                {
                    if (n > _capacity)
                    {
                        pointer tmp = _space.allocate(n);
                        for (size_t i = 0; i != _size; i++)
                            this->_space.construct(tmp + i, this->_vector[i]);  
                        _space.deallocate(this->_vector, this->_capacity);
                        _capacity = n;
                        this->_vector = tmp;
                    }
                    for(size_t i = _size; i != n; i++)
                        this->_space.construct(_vector + i, val);
                }
                _size = n;
            }

            size_type capacity() const                                  {return this->_capacity;}
            bool empty() const                                          {return this->_size == 0;}
            void reserve (size_type n)
            {
                if (n > this->max_size())
                    throw::std::length_error("The requested size is too high");
                if (this->_capacity <= n)
                {
                    pointer tmp = _space.allocate(n);
                    for (size_type i = 0; i < this->_size; i++) {
                        _space.construct(tmp + i, *(this->_vector + i));
                    }

                    for (size_type i = 0; i < this->_capacity; i++) {
                        _space.destroy(_vector + i);
                    }
                    _space.deallocate(this->_vector, this->_capacity);
                    this->_vector = tmp;
                    this->_capacity = n;
                }
            }

            //element access
            reference operator[] (size_type n)              {return this->_vector[n];}
            const_reference operator[] (size_type n) const  {return this->_vector[n];}

            reference at (size_type n)
            {
                if (n >= _size || n < 0)
                    throw std::out_of_range("vector");
                return this->_vector[n];
            }

            const_reference at (size_type n) const
            {
                if (n >= this->_size)
                    throw std::out_of_range("Index used is out of range");
                return (this->_vector[n]);
            }

            reference front()               {return this->_vector[0];}
            const_reference front() const   {return this->_vector[0];}
            reference back()                {return this->_vector[this->_size - 1];}
            const_reference back() const    {return this->_vector[this->_size - 1];}
            value_type* data()              {return this->_vector;}
            const value_type* data() const  {return this->_vector;}

            //modifiers
            template <class InputIterator>
            void assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
                         InputIterator last)
            {
                size_type diff = ft::distance(first, last);
                this->clear();
                if (diff > this->_capacity)
                {
                    _space.deallocate(_vector, _capacity);
                    _vector = _space.allocate(diff);
                    this->_capacity = diff;
                }
                for (size_type i = 0; i < diff; i++) {
                    _space.construct((_vector + i), *first++);
                }
                this->_size = diff;
            }

            void assign (size_type n, const value_type& val)
            {
                clear();
                if (n <= _size)
                {
                    for(size_t i = 0; i != n; i++)
                        _space.construct(_vector + i, val);
                }
                else if (n > _size)
                {
                    resize(n, val);
                }
                _size = n;
            }

            void push_back (const value_type& val)                                      
            {
                if (this->_size == 0)
                    this->reserve(1);
                else if (this->_size + 1 > this->capacity())
                    this->reserve(this->capacity() * 2);
                _space.construct((this->_vector + this->size()), val);
                this->_size++;
            }

            void pop_back()
            {
                if (!(this->empty()))
                {  
                    this->_space.destroy(&this->back());
                    this->_size--;
                }
            }

            iterator insert (iterator position, const value_type& val)//A FAIRE
            {
                insert(position, 1, val);
                return position;
            }

            void insert (iterator position, size_type n, const value_type& val) //A FAIRE
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
            void insert (iterator position,
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
            InputIterator last)
            {
                size_type n = ft::distance(first, last);
                size_type distance = ft::distance(begin(), position);
                if (_size + n > _capacity)
                {
                    if (this->size() == 0)
                    {
                        this->_vector = _space.allocate(n);
                        for (size_type i = 0; i < n; i++) {
                            try {_space.construct(this->_vector + i, *first++);}
                            catch(...)
                            {
                                _size = i;
                                _capacity = n;
                                this->clear();
                                _space.deallocate(_vector, n);
                                _capacity = 0;
                                throw std::exception();
                            }
                        }
                        this->_size = n;
                        this->_capacity = n;
                    }
                    else {
                        size_type old_cap = this->capacity();
                        if (this->size() + n > this->capacity() * 2)
                            this->_capacity = n + this->size();
                        else
                            this->_capacity *= 2;
                        pointer tmp = _space.allocate(this->capacity());
                        for (size_type i = 0; i < distance; i++)
                            _space.construct(tmp + i, *(_vector + i));
                        for (size_type i = 0; i < n; i++)
                            _space.construct(tmp + i + distance, *first++);
                        for (size_type i = 0; i + distance < this->size(); i++)
                            _space.construct(tmp + distance + n + i, *(_vector + distance + i));
                        for (size_type j = 0; j < this->size(); j++)
                            _space.destroy(_vector + j);
                        _size = this->size() + n;
                        _space.deallocate(_vector, old_cap);
                        _vector = tmp;
                    }
                }
                else if (n != 0)
                {
                    size_type new_end = _size + n;
                    for (iterator end_scope = this->end(); end_scope != position; end_scope--)
                    {
                        _space.construct(_vector + new_end--, *end_scope);
                    }
                    _space.construct(_vector + new_end, *position);
                    for (size_type i = 0;i < n; i++)
                    {
                        *(position + i) = *first++;
                    }
                    _size += n;
                }
            }

            iterator erase (iterator position)
            {
                return (erase(position, position + 1));
            }

            iterator erase (iterator first, iterator last)
            {
                size_type size_delete = ft::distance(first, last);
                pointer tmp = this->_vector + (size() - size_delete);
                ft::copy(last, end(), first);
                while(tmp != end())
                {
                    this->_space.destroy(tmp);
                    tmp++;
                }
                this->_size -= ft::distance(first, last);
                return (first);                
            }

            void swap (vector<T,Alloc>& x)
            {
                allocator_type  _space_tmp = x._space;
                pointer         _vector_tmp = x._vector;
                size_type       _capacity_tmp = x._capacity;
                size_type       _size_tmp = x._size;

                x._space = this->_space;
                x._vector = this->_vector;
                x._capacity = this->_capacity;
                x._size = this->_size;

                this->_space = _space_tmp;
                this->_vector = _vector_tmp;
                this->_capacity = _capacity_tmp;
                this->_size = _size_tmp;
            }

            void clear()
            {
                for (; _size != 0; _size--)
                    _space.destroy(_vector + _size);
            }
            //allocator
            allocator_type get_allocator() const    {return this->_space;}

    };

    //function non membre
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }

    //operator non membre	
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        return std::equal(lhs.begin(), lhs.end(), rhs.begin());
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
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(rhs > lhs);
    }

}
#endif