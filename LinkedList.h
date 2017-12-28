/*
 * LinkedList.h
 *
 * 작성자: Jungdy
 * 작성일자: 2017. 12. 28
 * 주제명: 직원 명부 프로그램
 *
 */

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
class LinkedList{

private:
	Node<T>* first;
	Node<T>* current;
public:
	LinkedList();
	~LinkedList();

	void push_back(T data);
	T pop();
	Node<T>* peak() const;
	Node<T>* atFirst() const;
	bool isEmpty() const;
};

template <typename T>
LinkedList<T>::LinkedList(){
	this->first = NULL;
	this->current = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList(){

	while (current != NULL)
	{
		pop();
	} // end of while

}

template <typename T>
void LinkedList<T>::push_back(T data){

	Node<Emp>* createNode = new Node<Emp>();
	createNode->setPrev(NULL);
	createNode->setData(data);
	createNode->setNext(NULL);

	if ( current == NULL ){
		current = createNode;
		first = createNode;
	}
	else
	{
		createNode->setPrev(current);
		current->setNext( createNode );
		current = current->getNext();
	} // end of if

}

template <typename T>
T LinkedList<T>::pop(){

	if ( current != NULL ){

		Node<T>* pNode = current;
		T data = current->getData();

		if ( current->getPrev() == NULL ){
			current = NULL;
			first = NULL;
		}
		else{
			current = current->getPrev();
			current->setNext(NULL);
		}

		delete[] pNode;

		return data;
	}

}

template <typename T>
Node<T>* LinkedList<T>::peak() const{
	return current;
}

template <typename T>
Node<T>* LinkedList<T>::atFirst() const{
	return first;
}

template <typename T>
bool LinkedList<T>::isEmpty() const{

	if ( first != NULL ){
		return false;
	}

	return true;
}


#endif
