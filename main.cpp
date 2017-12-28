/*
 * main.cpp
 *
 * 작성자: Jungdy
 * 작성일자: 2017. 12. 28
 * 주제명: 직원 명부 프로그램
 */

#include <iostream>
#include "Company.h"

using namespace std;


int main(){

	Company<Emp> company;
	company.run();

	return 0;
}
