#ifndef EQUAL_HPP
#define EQUAL_HPP

#include "reverse_iterator.hpp"

//SOURCE cplusplus.com
namespace ft
{

    template <class ForwardIterator, class T>
    void fill(ForwardIterator first, ForwardIterator last, const T& val)
    {
        while (first != last)
        {
            *first = val;
            ++first;
        }
    }
    
    template<typename iterator, typename InputIterator>
    iterator copy_backward(InputIterator first, InputIterator last, iterator position)
    {
        first--;
        last--;
        size_t n = ft::distance(first, last);
        position = position + n - 1;
        while (last != first)
        {
            *position = *last;
            last--;
            position--;
        }
        return position + n;
    }

    template<class InputIterator, class OutputIterator> OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result)
	{
		while (first != last)
		{
			*result = *first;
			++result;
			++first;
		}
		return result;
	}

	template <class InputIterator1, class InputIterator2>
    bool equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template<class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred )
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

    template <class T> 
    void swap ( T& a, T& b )
	{
		T c(a); 
        a=b; 
        b=c;
	}
}

#endif