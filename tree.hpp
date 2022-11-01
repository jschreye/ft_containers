
#include <iostream>

namespace ft
{
    template <class T> class Tree;
    template <class T> 
    class Node
    { 
        private:
        static int nbNode;

        public: 
            Node *left; 
            Node *right; 
            T value; 
            inline T & val()const   {return value;}
            Node(){nbNode++;}
            ~Node(){delete left;delete right;}
            friend class Tree <T>;
  };

    template<class T> 
    int Node<T>::nbNode = 0;
    template<class T> 
    class Tree
    { 
        private: 
            Node <T> *root; 
            void insert (Node <T> *); 
            void scanning(Node <T> *);
            Node <T> *getRoot()const{return root;}
            Node <T> *search (const T)const; 

        public: 
            Tree (){root = NULL;} //constructeur
            ~Tree (){delete root;} //constructeur
            void create (const T); 
            void deleteNode(const T); 
            void display(void); 
            void nbNode(void){std::cout << Node<T>::nbNode;}; 
    };

    template <class T> 
    void Tree<T>::display()
    { 
        if(root!=NULL) 
            scanning(root);
        else
            std::cout << "Arbre vide!" << std::endl;
    }

    template <class T> 
    void Tree<T>::scanning(Node<T> *ptrNode)
    { 

        if (ptrNode->left) 
            scanning(ptrNode->left); 
        if (ptrNode)
            std::cout << ptrNode->value << "\n"; 
        if (ptrNode->right)
            scanning(ptrNode->right); 
    }

    template <class T> 
    void Tree <T>::create(const T val)
    { 
        Node <T> * ptrNodeTmp = new Node <T>; 
        ptrNodeTmp->left = NULL; 
        ptrNodeTmp->right = NULL; 
        ptrNodeTmp->value = val;  
        insert (ptrNodeTmp); 
    }

    template <class T> 
    void Tree<T>::insert(Node <T> *ptrNode)
    { 
        if (!ptrNode)
            return; 
        if (root == NULL)
        { 
            root = ptrNode; 
            return; 
        } 
        Node<T> * current = root; 
        Node<T> * previous = NULL; 
        while (current)
        { 
            previous = current; 
            if (ptrNode->value < current->value) 
                current = current->left; 
            else 
                current = current->right; 
        }
        if (ptrNode->value < previous->value) 
            previous->left = ptrNode; 
        else 
            previous->right = ptrNode; 
    }

    template<class T> 
    void Tree<T>::deleteNode(const T val)
    { 
        Node<T> *ptrNode = search(val);
        if (!ptrNode)
        {
            std::cout << "Unsuccessful search! Cannot find this value." << std::endl;
            return; 
        }
        Node<T> *right = ptrNode->right; 
        Node<T> *left = ptrNode->left; 
        Node<T> *current = root; 
        if (ptrNode == root)
        { 
            root = right; 
            if (left)
                insert(left); 
            delete ptrNode;
            return; 
        }
        while (current)
        {
            if (current->right == ptrNode || current->left == ptrNode)
                break;
            if (ptrNode->value >= current->value) 
                current = current->right; 
            else 
                current = current->left; 
        }

        if (current->right == ptrNode) 
            current->right = right; 
        else 
            current->left = right; 
        if (left)
            insert(left); 
        delete ptrNode; 
        std::cout << "Deleted node!" << std::endl;
    }
    
    template <class T> 
    Node<T> *Tree<T>::search(const T val)const
    { 
        Node<T> *current = root; 
        while(current)
        { 
            if (current->value == val) 
                return current; 
            if (val < current->value) 
                current = current->left; 
            else 
                current = current->right; 
        } 
        return NULL; 
    }
}