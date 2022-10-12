#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

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

            size_type       _capacity;
            pointer         _finish;
            pointer         _start;
            pointer         _end;
            allocator_type  _space;
        
        private:
            void erase_at_end(pointer end)                                              {
                                                                                            _space.deallocate(this->_end - end);
                                                                                            this->_end = end;
                                                                                        }
            void destruct(pointer start, size_type capacity)                            {
                                                                                            for (size_t i = 0; i < capacity; i++)
                                                                                                this->_start.destroy(start[i]);
                                                                                        }

        public:

            //constructor
            explicit vector (const allocator_type& alloc = allocator_type())
            : _space(alloc), _finish(0), _start(0), _end(0), _capacity(0){}

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            : _capacity(n), value_type(val), _space(alloc), _finish(0), _start(0), _end(0) {}
            
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());	
            
            vector (const vector& x)                                                    {*this = x;}//PAS FINI

            //destructor
            ~vector()                                                                   {}//PAS FINI

            //operator assignement
            vector& operator=(const vector& rhs)                                        {
                                                                                            if(this == &rhs)
                                                                                                return *this;
                                                                                        }//PAS FINI

            //iterator
            iterator begin()                                                            {return iterator(this->_start);}
            const_iterator begin() const                                                {return const_iterator(this->_start);}
            iterator end()                                                              {return iterator(this->_end);}
            const_iterator end() const                                                  {return const_iterator(this->_end);}
            reverse_iterator rbegin()                                                   {return reverse_iterator(this->_end);}
            const_reverse_iterator rbegin() const                                       {return const_reverse_iterator(this->_end);}
            reverse_iterator rend()                                                     {return reverse_iterator(this->_start);}
            const_reverse_iterator rend() const                                         {return const_reverse_iterator(this->_start);}

            //capacity
            size_type size() const                                                      {return this->_end - this->_start;}
            size_type max_size() const                                                  {return this->_space.max_size();}
            void resize (size_type n, value_type val = value_type())                    {
                                                                                            if (n > size())
                                                                                                fill_insert(this->_start, n - size(), val);
                                                                                            else if (n < size())
                                                                                                erase_at_end(this->_start + n);
                                                                                        }//PAS FINI
            size_type capacity() const                                                  {return this->_capacity;}
            bool empty() const                                                          {return begin() == end();}
            void reserve (size_type n);

            //element access
            reference operator[] (size_type n)                                          {return this->_start[n];}
            const_reference operator[] (size_type n) const                              {return this->_start[n];}
            reference at (size_type n)                                                  {
                                                                                            if (n >= size() || n < 0)
                                                                                                throw std::out_of_range("vector");
                                                                                            return this->_start[n];
                                                                                        }
            const_reference at (size_type n) const                                      {
                                                                                            if (n >= size() || n < 0)
                                                                                                throw std::out_of_range("vector");
                                                                                            return this->_start[n];
                                                                                        }
            reference front()                                                           {return *this->_start;}
            const_reference front() const                                               {return *this->_start;}
            reference back()                                                            {return *(this->_end - 1);}
            const_reference back() const                                                {return *(this->_end - 1);}
            value_type* data() noexcept;
            const value_type* data() const noexcept;

            //modifiers
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last);//ATTENTION INCREMENTER _FINISH = _START
            
            void assign (size_type n, const value_type& val);//ATTENTION INCREMENTER _FINISH = _START
            void push_back (const value_type& val);//ATTENTION INCREMENTER _FINISH
            void pop_back();//ATTENTION INCREMENTER _FINISH
            iterator insert (iterator position, const value_type& val);//ATTENTION INCREMENTER _FINISH
            void insert (iterator position, size_type n, const value_type& val);//ATTENTION INCREMENTER _FINISH
           
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);   //ATTENTION INCREMENTER _FINISH
            
            iterator erase (iterator position);
            iterator erase (iterator first, iterator last);
            void swap (vector<T,Alloc>& x)                                              {
                                                                                            pointer tmp;

                                                                                            tmp = this->_start;
                                                                                            this->_start = x._start;
                                                                                            x._start = tmp;
                                                                                            
                                                                                            tmp = this->_finish;
                                                                                            this->_finish = x._finish;
                                                                                            x._finish = tmp;

                                                                                            tmp = this->_end;
                                                                                            this->_end = x._end;
                                                                                            x._end = tmp;
                                                                                        }
            void clear()                                                                {
                                                                                            destruct(this->_start, this->_capacity);
                                                                                            this->_capacity = this->_start;
                                                                                        }

            //allocator
            allocator_type get_allocator() const                                        {return this->_space;}

    };

    //function non membre
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        vector<T,Alloc>& tmp = x;
        x = y;
        y = tmp;
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