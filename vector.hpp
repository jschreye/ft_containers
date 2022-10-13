#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>

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

        private:

            allocator_type  _space;
            pointer         _vector;
            size_type       _capacity;
            size_type       _size;
        
        private:



        public:

            //constructor
            explicit vector (const allocator_type& alloc = allocator_type())
            : _space(alloc), _vector(NULL), _capacity(0), _size(0) {}

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            : _space(alloc), _vector(NULL), _size(n), _capacity(n) 
            {
                this->_vector = this->_space.allocate(n);
                for (size_type i = 0; i < _size; i++)
                    this->_space.construct((this->_vector + i), val);
            }
            
            /*template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
            : _space(alloc)
            {

            }*/
            
            vector (const vector& x)
            : _space(x._space), _vector(NULL), _size(0), _capacity(0)
            {
                *this = x;
            }

            //destructor
            ~vector()                                                                   {}//PAS FINI

            //operator assignement
            vector& operator=(const vector& rhs)                                        {
                                                                                            if(this == &rhs)
                                                                                                return *this;
                                                                                        }//PAS FINI

            //iterator
            iterator begin()                                                            {return iterator(this->_vector);}
            const_iterator begin() const                                                {return const_iterator(this->_vector);}
            iterator end()                                                              {return iterator(this->_vector + this->_size);}
            const_iterator end() const                                                  {return const_iterator(this->_vector + this->_size);}
            reverse_iterator rbegin()                                                   {return reverse_iterator(iterator(this->end()));}
            const_reverse_iterator rbegin() const                                       {return const_reverse_iterator(iterator(this->end));}
            reverse_iterator rend()                                                     {return reverse_iterator(iterator(this->begin()));}
            const_reverse_iterator rend() const                                         {return const_reverse_iterator(iterator(this->begin()));}

            //capacity
            size_type size() const                                                      {return this->_size;}
            size_type max_size() const                                                  {return _space.max_size();}
            void resize (size_type n, value_type val = value_type());
            size_type capacity() const                                                  {return this->_capacity;}
            bool empty() const                                                          {return this->_size == 0;}
            void reserve (size_type n);

            //element access
            reference operator[] (size_type n)                                          {return this->_vector[n];}
            const_reference operator[] (size_type n) const                              {return this->_vector[n];}
            reference at (size_type n);
            const_reference at (size_type n) const;
            reference front()                                                           {return this->_vector[0];}
            const_reference front() const                                               {return this->_vector[0];}
            reference back()                                                            {return this->_vector[this->_size - 1];}
            const_reference back() const                                                {return this->_vector[this->_size - 1];}
            value_type* data()                                                          {return this->_vector;}
            const value_type* data() const                                              {return this->_vector;}

            //modifiers
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last);
            
            void assign (size_type n, const value_type& val);
            void push_back (const value_type& val)                                      {
                                                                                            //if (this->_vector[this->_size - 1] == this->_capacity)
                                                                                                //grow(capacity() + 1);
                                                                                            this->_vector[this->size()] = val;
                                                                                            this->_size++;
                                                                                        }
            void pop_back()                                                             {
                                                                                            if (!(this->empty()))
                                                                                            {
                                                                                                this->_space.destroy(&this->back());
                                                                                                this->_size--;
                                                                                            }
                                                                                        }
            iterator insert (iterator position, const value_type& val);
            void insert (iterator position, size_type n, const value_type& val);
           
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);
            
            iterator erase (iterator position);
            iterator erase (iterator first, iterator last);
            void swap (vector<T,Alloc>& x);
            void clear();

            //allocator
            allocator_type get_allocator() const                                        {return this->_space;}

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