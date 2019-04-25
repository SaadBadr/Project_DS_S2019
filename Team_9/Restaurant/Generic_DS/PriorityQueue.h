#ifndef _PQ_
#define _PQ_

#include "Tree.h"

template < class T >
struct PriorityQueue 
{
private :
													
	Tree <T> myTree ;	

public :

	PriorityQueue () ;

	bool enqueue(T) ;							
	bool dequeue(T & frontentry) ;											
	bool frontpeek(T & frontentry) ;
	bool  isEmpty() ;

};


template <class T>
PriorityQueue <T> :: PriorityQueue () 
{}

template <class T>
bool PriorityQueue <T> ::  enqueue(T  ord) 
{
	return myTree.insert(ord)  ;
}

template <class T>
bool PriorityQueue <T> :: frontpeek (T & frontentry)
{
	return myTree.get_largest(frontentry) ;
}

template<class T>
bool PriorityQueue <T> :: dequeue(T & frontentry)			// what can i do if there is no items ?
{

	return myTree.pop_largest(frontentry);
}

template<class T>
bool PriorityQueue<T> ::  isEmpty()   
{
	return (myTree.getSize() == 0) ;
}


#endif