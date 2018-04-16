#ifndef _SESSIONTYPE_H
#define _SESSIONTYPE_H

#include "paperType.h"


/**
*	세션 이름, 논문 리스트를 멤벼 변수로 가지고 있는 클래스타입
*	@author 김한빈
*	@date   2018-04-06
*/
class sessionType 
{
public:
	
	/**
	*	기본 생성자
	*/
	sessionType() {
		string sessionName = "";
	}

	/**
	*	소멸자
	*/
	~sessionType() {};

	/**
	*	@brief	세션 이름 설정하기
	*	@pre	없음
	*	@post	세션이름이 매개변수의 값으로 설정된다
	*   @param   sN     sessionName에 저장할 string 값
	*/
	void SetsessionName(string sN)
	{
		sessionName = sN;
	}

	/**
	*	@brief	세션 가져오기
	*	@pre	세션 값이 설정되어있어야함.
	*	@post	없음
	*	@return	세션
	*/
	string GetsessionName()
	{
		return sessionName;
	}

	/**
	*	@brief	세션 이름 키보드로 입력해서 값 설정
	*	@pre	none.
	*	@post	세션 이름의 값이 설정됨.
	*/
	void SetSessionNameFromKB() {
		cout << "\tSession Name : ";
		cin >> sessionName;
	}

	/**
	*	@brief	세션 이름 화면에 출력
	*	@pre	세션 이름 값이 설정되어있어야함
	*	@post	세션 이름이 화면에 출력
	*/
	void DisplaySessionNameOnScreen()
	{
		cout << "\tName : " << sessionName << endl;
	};


	/**
	*	@brief	SessionList 가져오기
	*	@pre	SessionList 값이 설정되어있어야함
	*	@post	none.
	*	@return	SessionList 값
	*/
	ArrayList<paperType>* GetpaperList()
	{
		ArrayList<paperType> *paper = new ArrayList<paperType>();
		paper = &(this->paperList);
		return paper;
	}

	/**
	*	@brief	2개의 item id 로 비교
	*	@pre	2개의 item들은 값이 설정 되어있어야함.
	*	@param	item	비교할 아이템
	*	@return	return 1 만약 this.id > data.id, 아니라면 0
	*/
	bool operator>(sessionType item);

	/**
	*	@brief	2개의 item id 로 비교
	*	@pre	2개의 item들은 값이 설정 되어있어야함.
	*	@param	item	비교할 아이템
	*	@return	return 1 만약 this.id == data.id, 아니라면 0
	*/
	bool operator==(sessionType item);

	/**
	*	@brief	해당 item의 id 반환
	*	@pre	해당 item의 id는 값이 설정 되어있어야함
	*	@return	해당 item의 id 반환
	*/
	string operator+() {
		return this->GetsessionName();
	}

	/**
	*	@brief	해당 item의 레코드 출력
	*	@pre	해당 item의 레코드는 값이 설정되어있어야함
	*	@return	해당 아이템의 레코드 출력
	*/
	void operator-() {
		DisplaySessionNameOnScreen();
	}

private:
	string sessionName;
	ArrayList<paperType> paperList;
};

#endif 


