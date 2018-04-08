#ifndef _PAPERTYPE_H
#define _PAPERTYPE_H

#include <string>
#include "ArrayList.h"
#include "sessionType.h"
using namespace std;

/**
*	논문 제목, 저자, 페이지 수를 멤버 변수로 가진 클래스
*	@author 김한빈
*	@date   2018-04-06
*/
class paperType {
public:
	
	/**
	*	기본 생성자
	*/
	paperType() {
		string paperTitle = "";
		string author = "";
		int pageNum = -1;
	}
	
	/**
	*	소멸자
	*/
	~paperType() {};

	/**
	*	@brief	논문 제목 가져오기
	*	@pre	논문 제목 값이 설정되어있어야함.
	*	@post	없음
	*	@return	논문 제목 
	*/
	string GetpaperTitle()
	{
		return paperTitle;
	}

	/**
	*	@brief	저자 가져오기
	*	@pre	논문 제목 값이 설정되어있어야함.
	*	@post	없음
	*	@return	논문 제목
	*/
	string Getauthor()
	{
		return author;
	}

	/**
	*	@brief	논문 페이지 수 가져오기
	*	@pre	논문  페이지 수 값이 설정되어있어야함.
	*	@post	없음
	*	@return	논문 페이지 수
	*/
	int GetpageNum()
	{
		return pageNum;
	}

private:
	string paperTitle;		// 논문 제목
	string author;			// 저자
	int pageNum;			// 페이지 수
};

#endif 
