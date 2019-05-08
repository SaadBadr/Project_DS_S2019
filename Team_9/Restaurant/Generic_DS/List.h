#pragma once
#include<iostream>
#include"Node.h"
using namespace std;

template<class T>
class List {
private:
	Node<T>* Head;
	int count;
public:
	List();
	~List();
	void clear();
	bool Insert(T data, int pos);
	bool remove(int pos);
	int getLength()const;
	bool replace(const T newData, int pos);
	bool GetItmeAt(int pos, T& putin) const;
};

template<class T>
List<T>::List(){
	Head = nullptr;
	count = 0;
}

template<class T>
List<T>::~List(){
	clear();
}

template<class T>
int List<T>::getLength() const{
	return count;
}

template<class T>
void List<T>::clear(){
	Node<T> *P = Head;
	while (Head != NULL)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
	count = 0;
}

template<class T>
bool List<T>::Insert(T data, int pos){
	if (!Head || pos == 1)	{
		Head = new Node<T>(data);
		count++;
		return 1;
	}
	Node<T>* p = Head;
	Node<T>*temp = new Node<T>(data);
	if (!temp || pos < 1) return 0;
	if (pos == count + 1) {
		while (p->getNext()) {
			p = p->getNext();
		}
		p->setNext(temp);
		temp->setNext(NULL);
	}
	else {
		while (pos > 2) {
			pos--;
			p = p->getNext();
		}
		temp->setNext(p->getNext());
		p->setNext(temp);
	}
	count++;
	return 1;
}

template<class T>
bool List<T>::remove(int pos){
	if (pos < 1 || pos > count || !Head) return 0;
	Node<T>* p = Head;
	Node<T>*temp = nullptr;
	if (pos == 1) {
		Head = Head->getNext();
		delete p;
		p = nullptr;
	}
	else if(pos < count) {
		temp = p->getNext();
		while (pos > 2) {
			pos--;
			p = p->getNext();
			temp = temp->getNext();
		}
		p->setNext(temp->getNext());
		delete temp;
		temp = nullptr;
	}
	else {
		while (p->getNext()->getNext())	{
			p = p->getNext();
		}
		temp = p->getNext();
		p->setNext(p->getNext()->getNext());
		delete temp;
		temp = nullptr;
	}
	count--;
	return 1;
}

template<class T>
bool List<T>::replace(const T newData, int pos){
	if (pos<1 || pos > count || !Head) return 1;
	Node<T>* p = Head;
	while (pos > 1)	{
		pos--;
		p = p->getNext();
	}
	p->setItem(newData);
	return 1;
}

template<class T>
bool List<T>::GetItmeAt(int pos,T& putin) const{
	if (pos<1 || pos > count || !Head) return false;
	Node<T>* p = Head;
	while (pos > 1) {
		pos--;
		p = p->getNext();
	}
	putin =  (p->getItem());
	return true;
}