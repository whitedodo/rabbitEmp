/*
 * Emp.cpp
 *
 * 작성자: Jungdy
 * 작성일자: 2017. 12. 28
 * 주제명: 직원 명부 프로그램
 *
 */

#include <iostream>
#include "Emp.h"

using namespace std;

void Emp::setId(int id){
	this->id = id;
}

const int Emp::getId(){
	return this->id;
}

const char* Emp::getName() const{
	return this->name;
}

void Emp::setName(char* name){
	this->name = name;
}

const int Emp::getGrade(){
	return this->grade;
}

void Emp::setGrade(int grade){
	this->grade = grade;
}

const int Emp::getPay(){
	return pay;
}

void Emp::setPay(int pay){
	this->pay = pay;
}
