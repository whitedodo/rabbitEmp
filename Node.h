/*
 * Node.h
 *
 * 작성자: Jungdy
 * 작성일자: 2017. 12. 28
 * 주제명: 직원 명부 프로그램
 *
 */

#ifndef _NODE_H
#define _NODE_H

template <typename T>
class Node{
private:
	Node* prev;
	T data;
	Node* next;

public:
	T getData(){
		return data;
	}

	void setData(T data) {
		this->data = data;
	}

	Node* getPrev() const {
		return prev;
	}

	void setPrev(Node* prev) {
		this->prev = prev;
	}

	Node* getNext() const {
		return next;
	}

	void setNext(Node* next) {
		this->next = next;
	}

};

#endif
