#ifndef _PAPERTYPE_H
#define _PAPERTYPE_H

#include "ArrayList.h"
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
	*	@brief	논문 이름 키보드로 입력해서 값 설정
	*	@pre	none.
	*	@post	논문 이름의 값이 설정됨.
	*/
	void SetpaperTitleFromKB() {
		cout << "\tPaper Title : ";
		cin >> paperTitle;
	}

	/**
	*	@brief	작가 이름 키보드로 입력해서 값 설정
	*	@pre	none.
	*	@post   작가 이름의 값이 설정됨.
	*/
	void SetauthorFromKB() {
		cout << "\tAuthor : ";
		cin >> author;
	}

	/**
	*	@brief	논문 페이지 수 키보드로 입력해서 값 설정
	*	@pre	none.
	*	@post   논문 페이지 수 값이 설정됨.
	*/
	void SetpageNumFromKB() {
		cout << "\tPage number : ";
		cin >> pageNum;
	}

	/**
	*	@brief	논문 페이지 수 키보드로 입력해서 값 설정
	*	@pre	none.
	*	@post   논문 페이지 수 값이 설정됨.
	*/
	void SetPaperFromKB() {
		SetpaperTitleFromKB();
		SetauthorFromKB();
		SetpageNumFromKB();
	}

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

	/**
	*	@brief  논문 제목 화면에 출력
	*	@pre	논문 제목 값이 설정되어있어야함
	*	@post	논문 제목이 화면에 출력
	*/
	void DisplayPaperTitleOnScreen()
	{
		cout << "\tPaper Title : " << paperTitle << endl;
	};

	/**
	*	@brief	논문 저자 화면에 출력
	*	@pre	논문 저자 값이 설정되어있어야함
	*	@post	논문 저자 화면에 출력
	*/
	void DisplayAuthorOnScreen()
	{
		cout << "\tAuthor : " << author << endl;
	};

	/**
	*	@brief	논문 쪽수 화면에 출력
	*	@pre	논문 쪽수 값이 설정되어있어야함
	*	@post	논문 쪽수 화면에 출력
	*/
	void DisplayPageNumOnScreen()
	{
		cout << "\tpageNum : " << pageNum << endl;
	};

	/**
	*	@brief	논문 레코드 화면에 출력
	*	@pre	논문 레코드 값이 설정되어있어야함
	*	@post	논문 레코드 화면에 출력
	*/
	void DisplayPaperRecordOnScreen()
	{
		DisplayPaperTitleOnScreen();
		DisplayAuthorOnScreen();
		DisplayPageNumOnScreen();
	};


	/**
	*	@brief	2개의 item id 로 비교
	*	@pre	2개의 item들은 값이 설정 되어있어야함.
	*	@param	item	비교할 아이템
	*	@return	return 1 만약 this.id > data.id, 아니라면 0
	*/
	bool operator>(paperType item) {
		return (this->GetpaperTitle() > item.GetpaperTitle());
	}

	/**
	*	@brief	2개의 item id 로 비교
	*	@pre	2개의 item들은 값이 설정 되어있어야함.
	*	@param	item	비교할 아이템
	*	@return	return 1 만약 this.id == data.id, 아니라면 0
	*/
	bool operator==(paperType item) {
		return (this->GetpaperTitle() == item.GetpaperTitle());
	}

	/**
	*	@brief	해당 item의 id 반환
	*	@pre	해당 item의 id는 값이 설정 되어있어야함
	*	@return	해당 item의 id 반환
	*/
	string operator+() {
		return this->GetpaperTitle();
	}

	/**
	*	@brief	해당 item의 레코드 출력
	*	@pre	해당 item의 레코드는 값이 설정되어있어야함
	*	@return	해당 아이템의 레코드 출력
	*/
	void operator-() {
		return this->DisplayPaperRecordOnScreen();
	}

private:
	string paperTitle;		// 논문 제목
	string author;			// 저자
	int pageNum;			// 페이지 수
};

#endif 
