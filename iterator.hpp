#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
    template <class T>
    class iterator {

        public:
            typedef T               value_type;
            typedef std::ptrdiff_t  difference_type;
            typedef T&              reference;
            typedef T*              pointer;

        protected:
            pointer _ptr;

        public:
            iterator(): _ptr(NULL) {}
            iterator(pointer ptr): _ptr(ptr) {}
            iterator(const iterator& rhs): _ptr(rhs._ptr) {}
            template <class iter>
            iterator(const iterator<iter> & it): _ptr(it.base()){}
            virtual ~iterator() {}
            iterator& operator=(const iterator& rhs)
            {
                if (this == &rhs)
                    return *this;
                this->_ptr = rhs._ptr;
                return *this;
            }

            iterator& operator++()
            {
                _ptr++;
                return *this;
            }

            iterator& operator++(int)
            {
                iterator old = *this;
                operator++();
                return old;
            }

            pointer base() const
            {
                return this->_ptr;
            }
    };

    template <class T>
    class input_iterator : public virtual iterator<T> {

        public:
            typedef iterator<T>                     base;
            typedef typename base::value_type       value_type;
            typedef typename base::difference_type  difference_type;
            typedef typename base::pointer          pointer;
            typedef typename base::reference        reference;

        public:
            input_iterator() {}
            input_iterator(pointer p): iterator<T>(p) {}

            const reference operator*() const {return *(this->_ptr);}
            const pointer operator->() const {return &(this->operator*());}
            friend bool operator==(const input_iterator& lhs, const input_iterator& rhs);
            friend bool operator!=(const input_iterator& lhs, const input_iterator& rhs);
    };
    template<class T>
    bool operator==(const input_iterator<T>& lhs, const input_iterator<T>& rhs)
    {
        return lhs.base() == rhs.base();
    }
    template<class T>
    bool operator!=(const input_iterator<T>& lhs, const input_iterator<T>& rhs)
    {
        return lhs.base() != rhs.base();
    }

    template <class T>
    class output_iterator : public virtual iterator<T> {

        public:
            typedef iterator<T>                     base;
            typedef typename base::value_type       value_type;
            typedef typename base::difference_type  difference_type;
            typedef typename base::pointer          pointer;
            typedef typename base::reference        reference;

        public:
            output_iterator() {}
            output_iterator(pointer p): iterator<T>(p) {} 

            reference operator*() {return *(this->_ptr);}
            pointer operator->() {return &(this->operator*());}
            friend bool operator==(const output_iterator& lhs, const output_iterator& rhs);
            friend bool operator!=(const output_iterator& lhs, const output_iterator& rhs);

    };
    template<class T>
    bool operator==(const output_iterator<T>& lhs, const output_iterator<T>& rhs)
    {
        return lhs.base() == rhs.base();
    }
    template<class T>
    bool operator!=(const output_iterator<T>& lhs, const output_iterator<T>& rhs)
    {
        return lhs.base() != rhs.base();
    }

    template <class T>
    class forward_iterator : public virtual input_iterator<T>, public virtual output_iterator<T>
    {
        public:
            typedef iterator<T>                     base;
            typedef typename base::value_type       value_type;
            typedef typename base::difference_type  difference_type;
            typedef typename base::pointer          pointer;
            typedef typename base::reference        reference;
        
        public:
            forward_iterator() {}
            forward_iterator(pointer p): input_iterator<T>(p), output_iterator<T>(p) {}
    };

    template <class T>
    class bidirectional_iterator : public virtual forward_iterator<T> {

        public:
            typedef iterator<T>                     base;
            typedef typename base::value_type       value_type;
            typedef typename base::difference_type  difference_type;
            typedef typename base::pointer          pointer;
            typedef typename base::reference        reference;

        public:
            bidirectional_iterator() {}
            bidirectional_iterator(pointer p): forward_iterator<T>(p) {}

            bidirectional_iterator<T>& operator--()
            {
                (this->_ptr)--;
                return (*this);
            }

            bidirectional_iterator<T> operator--(int)
            {
                bidirectional_iterator tmp = *this;
                operator--();
                return (tmp);
            }
    };

    template <class T>
    class random_access_iterator : public virtual bidirectional_iterator<T>
    {
        public:
            typedef iterator<T>                     base;
            typedef typename base::value_type       value_type;
            typedef typename base::difference_type  difference_type;
            typedef typename base::pointer          pointer;
            typedef typename base::reference        reference;

            random_access_iterator() {}
            template <class iter>
            random_access_iterator(const random_access_iterator<iter> & it): iterator<T>(it) {}
            random_access_iterator(pointer p): bidirectional_iterator<T>(p) {}

            random_access_iterator operator+(int n)
            {
                random_access_iterator ret = random_access_iterator(*this);
                ret._ptr += n;
                return ret;
            }

            random_access_iterator operator-(int n)
            {
                random_access_iterator ret = random_access_iterator(*this);
                ret._ptr -= n;
                return ret;
            }

            friend random_access_iterator operator+(int n, const random_access_iterator & rhs);
            friend random_access_iterator operator-(int n, const random_access_iterator & rhs);

            difference_type operator-(const random_access_iterator & rhs) {return this->_ptr - rhs._ptr;}
            bool operator<(const random_access_iterator &rhs) const { return this->_ptr < rhs._ptr;}
            bool operator>(const random_access_iterator &rhs) const { return rhs._ptr < this->_ptr;}
            bool operator<=(const random_access_iterator &rhs) const { return !operator>(rhs);}
            bool operator>=(const random_access_iterator &rhs) const { return !operator<(rhs);}

            random_access_iterator &operator+=(int n)
            {
                this->_ptr += n;
                return this;
            }

            random_access_iterator &operator-=(int n)
            {
                this->_ptr -= n;
                return *this;
            }

            reference operator[](difference_type n)
            {
                return *(this->_ptr + n);
            }
    };
    template<class T>
    random_access_iterator<T> operator+(int n, const random_access_iterator<T> &rhs)
    {
        random_access_iterator<T> ret = random_access_iterator<T>(rhs);
        ret._ptr += n;
        return ret;
    }

    template<class T>
    random_access_iterator<T> operator-(int n, const random_access_iterator<T> &rhs)
    {
        random_access_iterator<T> ret = random_access_iterator<T>(rhs);
        ret._ptr -= n;
        return ret;
    }

}

#endif