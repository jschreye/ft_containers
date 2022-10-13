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

            }*/                                         //A FAIRE
            
            vector (const vector& x)
            : _space(x._space), _vector(NULL), _size(0), _capacity(0)
            {
                *this = x;
            }

            //destructor
            ~vector() {}//PAS FINI

            //operator assignement
            vector& operator=(const vector& rhs)
            {
                if(this == &rhs)
                    return *this;
            }//PAS FINI

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
            size_type size() const                                      {return this->_size;}
            size_type max_size() const                                  {return _space.max_size();}
            /*void resize (size_type n, value_type val = value_type()); 
            {
                Redimensionne le conteneur afin qu'il contienne n éléments.

                Si n est plus petit que la taille actuelle du conteneur ,
                le contenu est réduit à ses n premiers éléments, supprimant ceux au-delà (et les détruisant).

                Si n est supérieur à la taille actuelle du conteneur ,
                le contenu est développé en insérant à la fin autant d'éléments que nécessaire pour atteindre une taille de n .
                Si val est spécifié, les nouveaux éléments sont initialisés en tant que copies de val , sinon, ils sont initialisés en valeur.

                Si n est également supérieur à la capacité actuelle du conteneur, une réallocation automatique de l'espace de stockage alloué a lieu.

                Notez que cette fonction modifie le contenu réel du conteneur en y insérant ou en supprimant des éléments.            
            }                                                                                                               //A FAIRE*/
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
            void assign (InputIterator first, InputIterator last);/* //A FAIRE/
            {
                Attribue un nouveau contenu au vecteur , en remplaçant son contenu actuel et en modifiant sa taille en conséquence.
                Tous les éléments contenus dans le conteneur avant l'appel sont détruits et remplacés par des éléments nouvellement construits (aucune affectation d'éléments n'a lieu).
                Cela provoque une réallocation automatique de l'espace de stockage alloué si -et seulement si- la nouvelle taille du vecteur dépasse la capacité actuelle du vecteur 
            }*/
            void assign (size_type n, const value_type& val); //A FAIRE

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

            iterator insert (iterator position, const value_type& val);/* //A FAIRE
            {
                Le vecteur est étendu en insérant de nouveaux éléments avant l'élément à la position spécifiée ,
                augmentant ainsi la taille du conteneur du nombre d'éléments insérés.

                Cela provoque une réallocation automatique de l'espace de stockage alloué si -et seulement si-
                la nouvelle taille du vecteur dépasse la capacité actuelle du vecteur .

                Étant donné que les vecteurs utilisent un tableau comme stockage sous-jacent,
                l'insertion d'éléments dans des positions autres que la fin du vecteur oblige le conteneur à déplacer
                tous les éléments qui se trouvaient après la positionà leurs nouveaux postes. Il s'agit généralement d'une opération inefficace
                par rapport à celle effectuée pour la même opération par d'autres types de conteneurs de séquence (tels que list ou forward_list ).

                Les paramètres déterminent combien d'éléments sont insérés et à quelles valeurs ils sont initialisés :
            }*/
            void insert (iterator position, size_type n, const value_type& val); //A FAIRE
           
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last); //A FAIRE
            
            iterator erase (iterator position); //A FAIRE
            iterator erase (iterator first, iterator last); //A FAIRE
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
                for (size_type i = 0; i != this->size(); i++)
                    _space.destroy(_vector + i);
                this->_size = 0;
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