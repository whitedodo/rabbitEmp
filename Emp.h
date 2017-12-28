/*
 * Emp.h
 *
 * 작성자: Jungdy
 * 작성일자: 2017. 12. 28
 * 주제명: 직원 명부 프로그램
 *
 */

#ifndef _EMP_H
#define _EMP_H

class Emp{

private:
	int id;
	char* name;
	int grade;
	int pay;

public:
	const int getId();
	void setId(int id);
	const char* getName() const;
	void setName(char* name);
	const int getGrade();
	void setGrade(int grade);
	const int getPay();
	void setPay(int pay);

};

#endif
