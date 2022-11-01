#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <map>
#include <memory>
#include "enable_if.hpp"
#include "equal.hpp"
#include "pair.hpp"
#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "tree.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
    class map
    {
        public:

			class value_compare;
            typedef	Key											                key_type;
            typedef	T											        mapped_type;
            typedef	ft::pair<const key_type, mapped_type>               value_type;
            typedef	Compare											    key_compare;
            typedef	Allocator										    allocator_type;
            typedef	typename allocator_type::reference				    reference;
            typedef	typename allocator_type::const_referenc             const_reference;
            typedef	typename allocator_type::pointer				    pointer;
            typedef	typename allocator_type::const_pointer              const_pointer;
            typedef	typename allocator_type::size_type				    size_type;
            typedef	typename allocator_type::difference_typ             difference_type;
            typedef typename Tree<value_type>::iterator			        iterator;
            typedef typename Tree<value_type>::const_iterator		    const_iterator;
            typedef typename Tree<value_type>::reverse_iterator		    reverse_iterator;
            typedef typename Tree<value_type>::const_reverse_iterator   const_reverse_iterator;

        private:
			typedef	Tree<value_type>	_base;

			_base 		_tree;
			key_compare	_comp;

        public:

            //constructor
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
            
            map (const map& x);

            //destructor
            ~map();

            //operator =
            map& operator= (const map& rhs);

            //iterator
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;
            reverse_iterator rend();
            const_reverse_iterator rend() const;

            //capacity
            bool empty() const;
            size_type size() const;
            size_type max_size() const;

            //element access
            mapped_type& operator[] (const key_type& k);
            mapped_type& at (const key_type& k);
            const mapped_type& at (const key_type& k) const;

            //modifiers
            pair<iterator,bool> insert (const value_type& val);
            iterator insert (iterator position, const value_type& val);

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last);

            void erase (iterator position);
            size_type erase (const key_type& k);
            void erase (iterator first, iterator last);
            void swap (map& x);
            void clear();

            //observers
            key_compare key_comp() const;
            value_compare value_comp() const;

            //operations
            iterator find (const key_type& k);
            const_iterator find (const key_type& k) const;
            size_type count (const key_type& k) const;
            iterator lower_bound (const key_type& k);
            const_iterator lower_bound (const key_type& k) const;
            iterator upper_bound (const key_type& k);
            const_iterator upper_bound (const key_type& k) const;
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
            pair<iterator,iterator> equal_range (const key_type& k);

            //allocator
            allocator_type get_allocator() const;
    };

    template< class Key, class T, class Compare, class Alloc >
    bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );

    template< class Key, class T, class Compare, class Alloc >
    bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );

    template< class Key, class T, class Compare, class Alloc >
    bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );

    template< class Key, class T, class Compare, class Alloc >
    bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );

    template< class Key, class T, class Compare, class Alloc >
    bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );

    template< class Key, class T, class Compare, class Alloc >
    bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );
}

#endif