#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>
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
            typedef std::reverse_iterator<iterator>             reverse_iterator;
            typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;

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
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
            : _space(alloc)
            {
                assign(first, last);
            }
            
            vector (const vector& x)
            : _space(x._space), _vector(NULL), _size(0), _capacity(0)
            {
                *this = x;
            }

            //destructor
            ~vector() 
            {
                clear();
                _space.deallocate(_vector, this->_capacity);
            }

            //operator assignement
            vector& operator=(const vector& rhs)
            {
                if(this != &rhs)
                {
                    this->_capacity = rhs._capacity;
                    this->_size = rhs._size;
                    this->_space = rhs._space;
                    this->_vector = rhs._vector;
                }
                return (*this);
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
                if (n >= this->_size)
                    throw std::out_of_range("Index used is out of range");
                return (this->_vector[n]);
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
            void assign (InputIterator first, InputIterator last)
            {
                clear();
                size_type new_size = last - first;
                reserve(new_size);
                for (size_t i = 0; i < new_size; i++)
                {
                    _space.construct(_vector + i, first);
                    first++;
                }
                _size = new_size;
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
                pointer new_vector = NULL;
                size_type pos = position - this->begin();
                size_type end = this->end() - this->begin();
                size_type i;
                if (pos <= this->_size)
                {
                    new_vector = _space.allocate(this->_size + 1);
                    for (i = 0; i < pos; i++)
                        _space.construct(new_vector + i, this->_vector[i]);
                    _space.construct(new_vector + i, val);
                    for (; i < end; i++)
                        _space.construct(new_vector + i + 1, this->_vector[i]);
                    _space.deallocate(this->_vector, this->_capacity);
                    this->_vector = new_vector;
                    this->_size++;
                    this->_capacity++;
                }
                else if (pos > this->_size)
                {
                    new_vector = _space.allocate(pos + 1); 
                    for (i = 0; i < pos; i++)
                        _space.construct(new_vector + i, _vector[i]);
                    _space.construct(new_vector + i, val);
                    for (; i < end; i++)
                        _space.construct(new_vector + i + 1, _vector[i]);
                    _space.deallocate(this->_vector, this->_capacity);
                    this->_vector = new_vector;
                    this->_size = pos + 1;
                    this->_capacity = pos + 1;
                }
                return this->_vector + pos; 
            }
            void insert (iterator position, size_type n, const value_type& val) //A FAIRE
            {
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
                        {
                            std::cout << pos << " i = " << i << std::endl;
                            _space.construct(new_vector + i, _vector[i - n]);
                        }
                    else if (i <= pos)
                        for (i = 0; i < pos; i++)
                        {
                            std::cout << pos << " i2 = " << i << std::endl;
                            _space.construct(new_vector + i, _vector[i]);
                        }
                    if (i >= pos)
                    {
                        for (; i - pos < n; i++)
                        {
                            std::cout << "a" << std::endl;
                            _space.construct(new_vector + i, val);
                        }
                    }
                    else if (i < pos)
                        for (; pos - i < n; i++)
                        {
                            std::cout << "b" << std::endl;
                            _space.construct(new_vector + i, val);
                        }
                    for (; i < end; i++)
                        _space.construct(new_vector + i + 1, _vector[i - n]);
                    _space.deallocate(this->_vector, this->_capacity);
                    this->_vector = new_vector;
                    this->_size = pos + n;
                    this->_capacity = pos + n;
                }  
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);//A FAIRE
            
            iterator erase (iterator position)
            {
                size_t i = 0;
                size_type pos = position - begin();
                _space.destroy(_vector + pos);
                for (i = pos; i <= _size - 1; i++)
                    *(_vector + i) = *(_vector + i + 1);
                this->_size--;
                return (begin() + pos);
            }

            iterator erase (iterator first, iterator last)
            {
                size_type size_delete = 0;
                for (iterator it = first; it != last; it++) {
                    _space.destroy(&(*it));
                    size_delete++;
                }
                for (iterator it = first; last != this->end(); last++) {
                    *it = *last;
                    it++;
                }
                this->_size -= size_delete;
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
        if (lhs == rhs)
            return true;
        else
            return false;
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs != rhs)
            return true;
        else
            return false;
    }

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs < rhs)
            return true;
        else
            return false;
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs <= rhs)
            return true;
        else
            return false;
    }

    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs > rhs)
            return true;
        else
            return false;
    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs >= rhs)
            return true;
        else
            return false;
    }

}
#endif