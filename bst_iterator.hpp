#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

template<typename T, typename container, typename value> class	bst_iterator
{
	public:
		typedef			T						node;
		typedef			value					value_type;
		typedef			value_type&				reference;
		typedef			value_type*				pointer;
		typedef			value_type				iterator_category;
		typedef			ptrdiff_t				difference_type;

	private:
		node	_current;

	public:
		bst_iterator() : _current()
		{

		}

		bst_iterator(const bst_iterator<typename container::node *, container, typename container::value_type> & in) : _current(in.base())
		{
		}
		bst_iterator(node const &in) : _current(in)
		{
		}
		virtual ~bst_iterator()
		{
		}
	
		node		&base()
		{
			return _current;
		}
		const node	&base() const
		{
			return _current;
		}
	
		bst_iterator &operator++()
		{
			if (_current->right != nullptr){
				_current = _current->right;
				while (_current->left) {
					_current = _current->left;
				}
			}
			else {
				node	c = _current;
				_current = _current->parent;
				while (_current->right == c)
				{
					c = _current;
					_current = _current->parent;
				}
		}
		return *this;
	}

	bst_iterator operator++(int)
	{
		bst_iterator tmp = *this;
		++(*this);
		return tmp;
	}

	bst_iterator &operator--()
	{
		if (_current->left != nullptr) {
			_current = _current->left;
			while (_current->right) {
				_current = _current->right;
			}
			
		}
		else {
			node	c = _current;
			_current = _current->parent;
			while (_current->left == c) {
				c = _current;
				_current = _current->parent;
			}
		}
		return *this;
	}

	bst_iterator operator--(int)
	{
		bst_iterator tmp = *this;
		--(*this);
		return tmp;
	}

	bst_iterator	operator-(int const &i) const
	{
		bst_iterator ret = *this;
		for (int j = 0; j < i; j++) {
			ret--;
		}
		return ret;
	}

	bst_iterator	operator+(int const &i) const {
		bst_iterator ret = *this;
		for (int j = 0; j < i; j++) {
			ret++;
		}
		return ret;
	}

	pointer	operator->()
	{
		return &(this->operator*());
	}
	pointer	operator->() const
	{
		return &(this->operator*());
	}
	
	bool operator==(bst_iterator const &x) const
	{
		return _current == x._current;
	}
	bool operator!=(bst_iterator const &x) const
	{
		return !(*this == x);
	}

	value_type	&operator*()
	{
		return _current->value;
	}
	value_type	&operator*() const
	{
		return _current->value;
	}
};

#endif