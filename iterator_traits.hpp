#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include "reverse_iterator.hpp"

//SOURCE https://www.ibm.com/docs/en/zos/2.2.0?topic=classes-iterator-traits
namespace ft
{
	struct input_iterator_tag
	{

	};

	struct output_iterator_tag
	{

	};

	struct forward_iterator_tag : public input_iterator_tag
	{

	};

	struct bidirectional_iterator_tag : public forward_iterator_tag
	{

	};

	struct random_access_iterator_tag : public bidirectional_iterator_tag
	{
	
	};

	template<class Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ft::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef size_t								difference_type;
		typedef T*									pointer;
		typedef T&									reference;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ft::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef size_t								difference_type;
		typedef const T*							pointer;
		typedef const T&							reference;
	};
}

#endif
