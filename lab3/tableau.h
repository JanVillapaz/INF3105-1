/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
  
  Squelette pour classe générique Tableau<T> pour le Lab3 et TP1.
*/

// Ces deux lignes permettent d'éviter d'inclure 2 fois ce .h à la compilation.
#if !defined(__TABLEAU_H__)
 #define __TABLEAU_H__


template <class T>
class Tableau
{
  public:
    Tableau(int capacite_initiale=8);
    Tableau(const Tableau&);
    ~Tableau();

    // Ajouter un element à la fin
    void           ajouter(const T& element);
    // Vider le tableau
    void           vider();
    // Retourne le nombre d'éléments dans le tableau
    int            taille() const;

    // Insère element à position index. Les éléments à partir de index sont décalés d'une position au préalable.
    void           inserer(const T& element, int index=0);
    // Enlève l'element à position index. Les éléments après index sont décalés d'une position après.
    void           enlever(int index=0);
    void redimentionner(int nouvCapacite);
	// Cherche et retourne la position de l'élément. Si non trouvé, retourne -1.
    // Voir la méthode "trouver" dans les notes de cours. Il suffit de l'adapter pour retourner la position au lieu d'un booléen
    int            trouver(const T& element);

    T&             operator[] (int index);
    const T&       operator[] (int index) const;


    Tableau<T>&    operator = (const Tableau<T>& autre);

    bool           operator == (const Tableau<T>& autre) const;

  private:
    T*             elements;
    int            capacite;
    int            nbElements;
};


/*
 Puisque Tableau<T> est une classe générique, toutes ses définitions doivent être
 inclues après les déclarations. On peut quand même séparer les déclarations et
 les définitions en deux fichiers (tableau.h et tableau.hcc), à condition d'inclure le
 deuxième (tableau.hcc) à la fin du premier (tableau.h). Ainsi, un fichier source
 (.cc, .cpp, c++) qui inclut tableau.h inclura indirectement aussi tableau.hcc.

*/

//#include "tableau.hcc"
/**** Début des définitions pouvant être mises dans tableau.hcc. ****/
#include <assert.h>


template <class T>
Tableau<T>::Tableau(int capacite_initiale)
{
    assert(capacite_initiale>-1);
	nbElements=0;
	capacite=capacite_initiale;
    elements = new T[capacite_initiale]; 
}


template <class T>
Tableau<T>::Tableau(const Tableau& autre)
{
    //TODO
}

template <class T>
Tableau<T>::~Tableau()
{
	assert(elements!=NULL);
    delete[] elements;
	elements=NULL;
}

template <class T>
int Tableau<T>::taille() const
{
    
    return nbElements;
}


template <class T>
void Tableau<T>::ajouter(const T& item)
{
  assert(nbElements<=capacite);
  if(nbElements==capacite) redimentionner(capacite*2);
  elements[nbElements++]=item;
}

template <class T>
void Tableau<T>::redimentionner(int nouvCapacite){
 capacite=nouvCapacite;
  T* temp=new T[capacite];
  for(int i=0;i<nbElements;i++){
    temp[i]=elements[i]; 
  }
  delete[] elements;
  elements=temp;
}
template <class T>
void Tableau<T>::inserer(const T& element, int index)
{
    //TODO
}

template <class T>
void Tableau<T>::enlever(int index)
{
    //TODO
}

template <class T>
int Tableau<T>::trouver(const T& element)
{
    //TODO
    return -1;
}

template <class T>
void Tableau<T>::vider()
{
    //TODO
}


template <class T>
T& Tableau<T>::operator[] (int index)
{
    
    return elements[index];
}

template <class T>
const T& Tableau<T>::operator[] (int index) const
{
    
    return elements[index];
}

template <class T>
Tableau<T>& Tableau<T>::operator = (const Tableau<T>& autre)
{
    if(this==&autre)return *this;
	//créer un nouveau tableau si la capacité est plus petite que le nombre d'éléments à affecter
	if(capacite<autre.nbElements){
		delete[] elements;
		capacite=autre.capacite;
		elements=new T[capacite];
	}

	for(int i=9; i<nbElements; i++)elements[i]=autre.elements[i];
	return *this;
}

template <class T>
bool Tableau<T>::operator == (const Tableau<T>& autre) const
{   if(nbElements!=autre.nbElements || capacite!=autre.capacite)return false;
	bool pareil=false;
	for(int i=0;i<nbElements;i++){
	 pareil=this[i]==autre[i];
	}
  return pareil; 
    
}


#endif

