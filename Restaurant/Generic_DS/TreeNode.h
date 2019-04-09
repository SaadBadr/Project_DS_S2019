
#ifndef __TNODE_H_
#define __TNODE_H_

template < typename T>
struct TreeNode
{
private :
	T item; // A data item
//	double priority ; 
	TreeNode<T>* right; // Pointer to next node
	TreeNode<T>* left;  // Pointer to next node

public :
	TreeNode();
	TreeNode( const T & r_Item);	//passing by const ref.

	void setItem ( const T r_Item);
	void setRight(TreeNode<T>* r);
	void setLeft (TreeNode<T>* l);

	T getItem() const ;
	TreeNode<T>* getRight() const ;
	TreeNode<T>* getLeft () const ;

	~ TreeNode () ;
};

template < typename T>
TreeNode<T>::TreeNode() 
{
	left  = NULL ;
	right = NULL ;
} 

template < typename T>
TreeNode<T>::TreeNode( const T& r_Item)
{
	item = r_Item;
	left = NULL;
	right = NULL;
} 

template <class T>
void TreeNode<T> :: setItem ( const T r_Item)
{
	item = r_Item ;
}


template < typename T>
void TreeNode<T>::setRight(TreeNode<T>* r)
{
	right = r ;
} 
template < typename T>
void TreeNode<T>::setLeft(TreeNode<T>* l)
{
	left = l ;
} 

template < typename T>
T TreeNode<T>::getItem() const
{
	return item;
} 

template < typename T>
TreeNode<T>* TreeNode<T>::getLeft() const
{
	return left;
} 
template < typename T>
TreeNode<T>* TreeNode<T>::getRight() const
{
	return right;
} 

template<class T>
TreeNode<T> :: ~ TreeNode ()
{}

#endif