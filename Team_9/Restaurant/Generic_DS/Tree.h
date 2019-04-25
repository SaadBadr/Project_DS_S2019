#ifndef _TREE_
#define _TREE_
#include "TreeNode.h"
#include <iostream>

using namespace std ;



template <class T>
class Tree
{
	TreeNode<T> * root ;
	int size ;
//	int height ;
	TreeNode<T> * get_smallest (TreeNode<T> * now) ;

public : 
	Tree () ;
	bool insert (T n) ;
	bool remove    (T itm) ;
	bool pop_largest(T & frontentry);										// i made it to handle my need
	bool get_largest(T & frontentry);										// i made it to handle my need

	TreeNode<T> * getRoot () ;
	bool isEmpty () ;
	int getSize () ;
	int getHeight () ;
	void clear (TreeNode<T> * from) ;						// using a member as a default requires static member
	T getEntry () ;
	
	~ Tree () ;


};

template<class T>
Tree<T> :: Tree () 
{
	size = 0 ;
	root = NULL ;
}

template<class T>
int Tree<T> ::   getSize () {return size ;}

template<class T>
bool Tree<T> ::  isEmpty() {return (size==0) ;}

template<class T>
bool Tree<T> :: insert (T n) 
{
	TreeNode<T> * elem = new TreeNode<T> (n) ; if (!elem) return 0 ;
	TreeNode<T> * curr = root ,* parent ;

	if (isEmpty()) {root = elem ;size++ ;return 1 ;} 
	else 
	{
		while (curr)
		{
			parent = curr ;
			if (curr->getItem() < n) curr = curr->getRight() ;
			else					 curr = curr->getLeft();
		}
	}
	if (parent->getItem() < n) parent->setRight(elem) ;
	else					   parent->setLeft (elem);

	size++;

	return 1 ;
}

template<class T>
bool Tree<T> :: pop_largest(T & frontentry)
{
	TreeNode<T> * curr = root;
	T elem ;
	if (isEmpty())return 0 ;
	if(!curr) return NULL ;							// no elements !! what to do ?

	while (curr->getRight())
		curr=curr->getRight();

	frontentry = curr->getItem() ;
	remove(frontentry) ;
	return 1 ;
}

template<class T>
bool Tree<T> :: remove (T itm)							// to remove one for that elem even if it repeated... isn't it true ?
{
	TreeNode<T> * curr = root ,  *parent  = root;	
	bool found = 0 ;

	while (curr)
	{
		if (curr->getItem() == itm){found = 1 ;break;}
		parent = curr ;
		if (itm > curr->getItem())curr = curr ->getRight() ;
		else curr=curr->getLeft() ;
	}

	if (curr == root)
		root = root->getLeft();

	if (!found) return 0 ;

	if((curr->getLeft() == NULL && curr->getRight() != NULL)|| (curr->getLeft() != NULL && curr->getRight() == NULL))	//have one child
	{
		if ((curr->getLeft() == NULL && curr->getRight() != NULL))
			{if (curr == parent->getLeft())       parent->setLeft(curr->getRight())  ;
			else if (curr == parent->getRight())  parent->setRight(curr->getRight());}
		
		else if (curr->getLeft() != NULL && curr->getRight() == NULL)
		{if (curr == parent->getLeft())       parent->setLeft(curr->getLeft())  ;
			else if (curr == parent->getRight())  parent->setRight(curr->getLeft());}
		
		TreeNode<T> * temp = curr ;
		curr = NULL ;
		delete temp ;
	}

	else if (curr->getLeft() == NULL && curr->getRight() == NULL)	//have no children
	{if(parent->getRight() == curr)parent->setRight(NULL) ;
	 else if (parent->getLeft() == curr)parent->setLeft(NULL);
	 delete curr ;} 
	
	else											// have 2 children
	{
		TreeNode<T> * mini = get_smallest(curr) ;
		TreeNode<T> my_new_node ;

		curr->setItem(mini->getItem());				// new item in the node we want to remove

		remove(mini->getItem());
	}
	
	size -- ;
	return 1 ;
}

template<class T>
void Tree<T> :: clear (TreeNode<T> * from )
{
	if (!from) return ;
    clear(from ->getLeft()) ;
    clear(from -> getRight()) ;
	TreeNode <T> * temp ; temp = from ;
	from = NULL ;
	delete temp ;
	root = NULL ;
}

template<class T>
bool Tree <T> :: get_largest(T & frontentry)
{
	if (isEmpty())return 0 ;
	TreeNode<T> * curr = root;
	T elem ;
	while (curr->getRight())curr=curr->getRight();
	frontentry = curr->getItem() ;
	return 1 ;
}

template <class T>
TreeNode<T> * Tree<T> :: get_smallest (TreeNode<T> * now) // how to clear sub queue "have a problem with '*&'  "
{
	TreeNode<T> * mini = now ;

	while (mini->getLeft())
	{ mini = mini-> getLeft() ;}

	return mini ;
}

template <class T>
Tree<T> :: ~ Tree () 
{clear(root) ;}


#endif