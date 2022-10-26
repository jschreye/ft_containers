#include <stdio.h>
#include <iostream>

namespace ft
{
    template <class T> class Cl_Arbre;
    template <class T> 
    class Cl_Noeud
    { 
        private:
        static int NbrNoeuds;

        public: 
            Cl_Noeud *gauche; 
            Cl_Noeud *droite; 
            T valeur; 
            inline T & val()const   {return valeur;}
            Cl_Noeud(){NbrNoeuds++;};
            ~Cl_Noeud(){delete gauche;delete droite;}
            friend class Cl_Arbre <T>;
  };

    template<class T> 
    int Cl_Noeud<T>::NbrNoeuds = 0;
    template<class T> 
    class Cl_Arbre
    { 
        private: 
            Cl_Noeud <T> *racine; 
            void Inserer (Cl_Noeud <T> *); 
            void Balayage(Cl_Noeud <T> *);
            Cl_Noeud <T> *DonnepRacine()const{return racine;}
            Cl_Noeud <T> *Rechercher (const T)const; 

        public: 
            Cl_Arbre (){racine = NULL;} //constructeur
            ~Cl_Arbre (){delete racine;} //constructeur
            void Creer (const T); 
            void Supprimer(const T); 
            void Affichage(void); 
            void NbrNoeuds(void){std::cout << Cl_Noeud<T>::NbrNoeuds;}; 
    };

    template <class T> 
    void Cl_Arbre<T>::Affichage()
    { 
        if(racine!=NULL) 
            Balayage(racine);
        else
            std::cout << "Arbre vide!" << std::endl;
    }

    template <class T> 
    void Cl_Arbre<T>::Balayage(Cl_Noeud<T> *pNoeud)
    { 

        if (pNoeud->gauche) 
            Balayage(pNoeud->gauche); 
        if (pNoeud)
            std::cout << pNoeud->valeur << "\n"; 
        if (pNoeud->droite)
            Balayage(pNoeud->droite); 
    }

    template <class T> 
    void Cl_Arbre <T>::Creer(const T val)
    { 
        Cl_Noeud <T> * pNoeudTmp = new Cl_Noeud <T>; 
        pNoeudTmp->gauche = NULL; 
        pNoeudTmp->droite = NULL; 
        pNoeudTmp->valeur = val;  
        Inserer (pNoeudTmp); 
    }

    template <class T> 
    void Cl_Arbre<T>::Inserer(Cl_Noeud <T> *pNoeud)
    { 
        if (!pNoeud)
            return; 
        if (racine == NULL)
        { 
            racine = pNoeud; 
            return; 
        } 
        Cl_Noeud<T> * courant = racine; 
        Cl_Noeud<T> * precedent = NULL; 
        while (courant)
        { 
            precedent = courant; 
            if (pNoeud->valeur < courant->valeur) 
            courant = courant->gauche; 
            else 
                courant = courant->droite; 
        }
        if(pNoeud->valeur < precedent->valeur) 
            precedent->gauche = pNoeud; 
        else 
            precedent->droite = pNoeud; 
    }

    template<class T> 
    void Cl_Arbre<T>::Supprimer(const T val)
    { 
        Cl_Noeud<T> *pNoeud = Rechercher(val);
        if (!pNoeud)
        {
            std::cout << "Recherche infructueuse! impossible de trouver cette valeur." << std::endl;
            return; 
        }
        Cl_Noeud<T> *droite = pNoeud->droite; 
        Cl_Noeud<T> *gauche = pNoeud->gauche; 
        Cl_Noeud<T> *courant = racine; 
        if(pNoeud == racine)
        { 
            racine = droite; 
            if(gauche)
                Inserer(gauche); 
            delete pNoeud;
            return; 
        }
        while(courant)
        {
            if(courant->droite == pNoeud || courant->gauche == pNoeud)
                break;
            if(pNoeud->valeur >= courant->valeur) 
                courant = courant->droite; 
            else 
                courant = courant->gauche; 
        }

        if(courant->droite == pNoeud) 
            courant->droite = droite; 
        else 
            courant->gauche = droite; 
        if(gauche)
            Inserer(gauche); 
        delete pNoeud; 
        std::cout << "Noeud effacé!" << std::endl;
    }
    
    template <class T> 
    Cl_Noeud<T> *Cl_Arbre<T>::Rechercher(const T val)const
    { 
        Cl_Noeud<T> *courant = racine; 
        while(courant)
        { 
            if(courant->valeur == val) 
                return courant; 
            if (val < courant->valeur) 
                courant = courant->gauche; 
            else 
                courant = courant->droite; 
        } 
        return NULL; 
    }
}