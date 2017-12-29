/*
 * Company.h
 *
 * �ۼ���: Jungdy
 * �ۼ�����: 2017. 12. 28
 * ������: ���� ��� ���α׷�
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

	cout << "�̸��� �Է��ϼ���" << endl;
	cin.clear();
    cin.ignore();
    cin.getline(name, sizeof(name));

	cout << "������ �Է��ϼ���(���ڸ�)" << endl;
	cin >> grade;
	cout << "�޿��� �Է��ϼ���(���ڸ�)" << endl;
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
		cout << "| ����                              |" << endl;
		cout << "---------------------------" << endl;
		cout << "����ID:" << emp.getId() << endl;
		cout << "������:" << emp.getName() << endl;
		cout << "����:" << emp.getGrade() << endl;
		cout << "�޿�:" << emp.getPay() << endl;
	}
	else
	{
		cout << "�ڷᰡ ����ֽ��ϴ�." << endl;
	}

}

template <typename T>
void Company<T>::view(LinkedList<T>& linkedlist){

	Emp emp;

	if ( !linkedlist.isEmpty() ){

		cout << "---------------------------" << endl;
		cout << "| ��ȸ                              |" << endl;
		cout << "---------------------------" << endl;

		Node<Emp>* pNode = NULL;
		pNode = linkedlist.atFirst();

		while ( pNode != NULL ){

			emp = pNode->getData();

			cout << "����ID:" << emp.getId() << endl;
			cout << "������:" << emp.getName() << endl;
			cout << "����:" << emp.getGrade() << endl;
			cout << "�޿�:" << emp.getPay() << endl;

			pNode = pNode->getNext();

		} // end of while


	}
	else
	{
		cout << "�ڷᰡ ����ֽ��ϴ�." << endl;
	}
}


template <typename T>
void Company<T>::run(){

	LinkedList<Emp> linkedlist;

	int choose = -1;

	while ( choose ){

		cout << "------------------------------" << endl;
		cout << "| Rabbit-white = ���� ��� ����   |" << endl;
		cout << "------------------------------" << endl;

		cout << "1. �߰�" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��ȸ" << endl;
		cout << "0. ����" << endl;

		cin >> choose;

		switch ( choose ){

			// �߰�
			case INSERT:
				insert(linkedlist);
				break;

			// ����
			case REMOVE:
				remove(linkedlist);
				break;

			case VIEW:
				view(linkedlist);
				break;

		} // end of switch

		// ����:Ż��
		if ( choose == EXIT )
			break;

	} // end of while

}



#endif
