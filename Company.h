/*
 * Company.h
 *
 * 작성자: Jungdy
 * 작성일자: 2017. 12. 28
 * 주제명: 직원 명부 프로그램
 *
 */

#ifndef _COMPANY_H_
#define _COMPANY_H_

#include "Emp.h"
#include "Node.h"
#include "LinkedList.h"

const int EXIT = 0;
const int INSERT = 1;
const int REMOVE = 2;
const int VIEW = 3;

template <typename T>
class Company{

private:
	void insert(LinkedList<T>& linkedlist);
	void remove(LinkedList<T>& linkedlist);
	void view(LinkedList<T>& linkedlist);

public:
	void run();

};

template <typename T>
void Company<T>::insert(LinkedList<T>& linkedlist){

	Emp emp;

	int id = 1;
	char name[128];
	int grade;
	int pay;

	cout << "이름을 입력하세요" << endl;
	cin.clear();
    cin.ignore();
    cin.getline(name, sizeof(name));

	cout << "직급을 입력하세요(숫자만)" << endl;
	cin >> grade;
	cout << "급여를 입력하세요(숫자만)" << endl;
	cin >> pay;

	emp.setId(id);
	emp.setName(name);
	emp.setGrade(grade);
	emp.setPay(pay);

	if ( !linkedlist.isEmpty() )
	{
		Node<Emp>* pNode = NULL;
		pNode = linkedlist.peak();
		Emp current = pNode->getData();
		id = current.getId();
		id++;
		emp.setId(id);
	}

	linkedlist.push_back(emp);

}

template <typename T>
void Company<T>::remove(LinkedList<T>& linkedlist){

	Emp emp;

	if ( !linkedlist.isEmpty() ){

		emp = linkedlist.pop();

		cout << "---------------------------" << endl;
		cout << "| 삭제                              |" << endl;
		cout << "---------------------------" << endl;
		cout << "직원ID:" << emp.getId() << endl;
		cout << "직원명:" << emp.getName() << endl;
		cout << "직급:" << emp.getGrade() << endl;
		cout << "급여:" << emp.getPay() << endl;
	}
	else
	{
		cout << "자료가 비어있습니다." << endl;
	}

}

template <typename T>
void Company<T>::view(LinkedList<T>& linkedlist){

	Emp emp;

	if ( !linkedlist.isEmpty() ){

		cout << "---------------------------" << endl;
		cout << "| 조회                              |" << endl;
		cout << "---------------------------" << endl;

		Node<Emp>* pNode = NULL;
		pNode = linkedlist.atFirst();

		while ( pNode != NULL ){

			emp = pNode->getData();

			cout << "직원ID:" << emp.getId() << endl;
			cout << "직원명:" << emp.getName() << endl;
			cout << "직급:" << emp.getGrade() << endl;
			cout << "급여:" << emp.getPay() << endl;

			pNode = pNode->getNext();

		} // end of while


	}
	else
	{
		cout << "자료가 비어있습니다." << endl;
	}
}


template <typename T>
void Company<T>::run(){

	LinkedList<Emp> linkedlist;

	int choose = -1;

	while ( choose ){

		cout << "------------------------------" << endl;
		cout << "| Rabbit-white = 직원 명부 관리   |" << endl;
		cout << "------------------------------" << endl;

		cout << "1. 추가" << endl;
		cout << "2. 삭제" << endl;
		cout << "3. 조회" << endl;
		cout << "0. 종료" << endl;

		cin >> choose;

		switch ( choose ){

			// 추가
			case INSERT:
				insert(linkedlist);
				break;

			// 삭제
			case REMOVE:
				remove(linkedlist);
				break;

			case VIEW:
				view(linkedlist);
				break;

		} // end of switch

		// 조건:탈출
		if ( choose == EXIT )
			break;

	} // end of while

}



#endif
