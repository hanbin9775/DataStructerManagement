#ifndef _CONFERENCETYPE_H
#define _CONFERENCETYPE_H

#include "sessionType.h"


/**
*	두 아이템 간 관계
*/
enum RelationType {LESS, GREATER, EQUAL};


/**
*	학술대회 명, 시작 년월일, 개최 횟수, 개최 기관의 정보를 가지고 있는 아이템 정보 클래스
*	@author 김한빈
*	@date   2018-04-10
*/
class ConferenceType
{
public:
	/**
	*	기본 생성자
	*/
	ConferenceType()
	{
		m_sName = "";
		m_sDate = "";
		m_Num = -1;
		m_sOrg = "";
		m_sAbrv = "";
	}

	/**
	*	소멸자
	*/
	~ConferenceType()	{}


	/**
	*	@brief	학술대회 명 가져오기
	*	@pre	학술대회 이름의 값이 설정되어있어야함.
	*	@post	없음
	*	@return	학술대회 이름
	*/
	string GetName()
	{
		return m_sName;
	}

	/**
	*	@brief	시작년월일 가져오기
	*	@pre	시작년월일 값이 설정되어있어야함
	*	@post	없음
	*	@return	시작년월일
	*/
	string GetDate()
	{
		return m_sDate;
	}

	/**
	*	@brief	개최 횟수 가져오기
	*	@pre	개최 횟수 값이 설정되어있어야함.
	*	@post	none.
	*	@return	개최 횟수.
	*/
	int GetNum()
	{
		return m_Num;
	}

	/**
	*	@brief	개최 기관 가져오기
	*	@pre	개최 기관 값이 설정되어있어야함
	*	@post	none.
	*	@return	개최 기관.
	*/
	string GetOrg()
	{
		return m_sOrg;
	}
	
	/**
	*	@brief	학술대회 명 약자 가져오기
	*	@pre	학술대회 명 값이 설정되어있어야함
	*	@post	none.
	*	@return	학술대회 명 약자
	*/
	string GetAbrv() 
	{
		return m_sAbrv;
	}

	/**
	*	@brief	개최 장소 명 약자 가져오기
	*	@pre	개최 장소 값이 설정되어있어야함
	*	@post	none.
	*	@return	개최 장소 
	*/
	string GetPlace()
	{
		return m_sPlace;
	}

	/**
	*	@brief	개최 일시 값 가져오기
	*	@pre	개최 일시 값이 설정되어있어야함.
	*	@post	none.
	*	@return	개최 일시
	*/
	string GetOpenDate()
	{
		return m_OpenDate;
	}

	/**
	*	@brief	ISBN 가져오기
	*	@pre	ISBN 값이 설정되어있어야함
	*	@post	none.
	*	@return	ISBN 값
	*/
	string GetISBN()
	{
		return m_sISBN;
	}

	/**
	*	@brief	SessionList 가져오기
	*	@pre	SessionList 값이 설정되어있어야함
	*	@post	none.
	*	@return	SessionList 값
	*/
	ArrayList<sessionType>* GetsessionList()
	{
		ArrayList<sessionType> *sess = new ArrayList<sessionType>();
		sess = &(this->sessionList);
		return sess;
	}

	/**
	*	@brief	학술대회 이름 값 저장하기
	*	@pre	none.
	*	@post	학술대회 이름에 값이 저장됨
	*	@param	inName	설정할 학술대회 이름.
	*/
	void SetName(string inName)
	{
		m_sName = inName;
	}

	/**
	*	@brief	시작년월일 설정
	*	@pre	없음.
	*	@post	시작년월일에 값이 저장됨.
	*	@param	indate	설정할 시작년월일
	*/
	void SetDate(string indate)
	{
		m_sDate = indate;
	}

	/**
	*	@brief	개최 횟수 설정
	*	@pre	없음.
	*	@post	개최 횟수에 값이 저장됨.
	*	@param	indate	설정할 개최횟수
	*/
	void SetNum(int innum)
	{
		m_Num = innum;
	}


	/**
	*	@brief	개최 기관 값 설정하기.
	*	@pre	none.
	*	@post	개최 기관 값이 저장됨
	*	@param	inOrg	설정할 개최 기관 
	*/
	void SetOrganization(string inOrg)
	{
		m_sOrg = inOrg;
	}

	/**
	*	@brief	학술대회 명 약자 설정하기.
	*	@pre	none.
	*	@post	학술대회 명 약자 값이 저장됨
	*	@param	inAbrv	설정할 학술 대회명 약자
	*/
	void SetAbbrevation(string inAbrv)
	{
		m_sAbrv = inAbrv;
	}

	/**
	*	@brief	학술대회 개최 장소 설정하기.
	*	@pre	none.
	*	@post	학술대회 개최 장소 값이 저장됨
	*	@param	inPlace	설정할 장소 대회명 약자
	*/
	void SetPlace(string inPlace)
	{
		m_sPlace = inPlace;
	}
	
	/**
	*	@brief	학술대회 개최 일시 설정하기.
	*	@pre	none.
	*	@post	학술대회 개최 일시 값이 저장됨
	*	@param	inOpenDate	설정할 개최 장소 
	*/
	void SetOpenDate(string inOpenDate)
	{
		m_OpenDate = inOpenDate;
	}

	/**
	*	@brief	ISBN 값 설정하기
	*	@pre	none.
	*	@post	ISBN 값이 저장됨
	*	@param	inISBN	설정할 ISBN
	*/
	void SetISBN(string inISBN)
	{
		m_sISBN = inISBN;
	}

	/**
	*	@brief	학술 레코드 설정
	*	@pre	없음
	*	@post	학술 레코드 설정됨
	*	@param	inName	학술대회 명 
	*	@param	inDate	시작년월일
	*	@param	inNum	개최 횟수
	*	@param	inOrg	개최 기관
	*	@param	inAbrv	학술대회명약자
	*	@param	inPlace 학술대회 개최 장소
	*	@param	inOpenDate	개최 일시
	*	@param	inISBN	ISBN
	*/
	void SetRecord(string inname, string indate,int innum ,string inorg,string inabrv, string inplace, string inopendate, string inisbn)
	{
		SetName(inname);
		SetDate(indate);
		SetNum(innum);
		SetOrganization(inorg);
		SetAbbrevation(inabrv);
		SetPlace(inplace);
		SetOpenDate(inopendate);
		SetISBN(inisbn);
	}

	/**
	*	@brief	학술대회 명 화면에 출력
	*	@pre	학술대회 이름 값이 설정되어있어야함
	*	@post	학술대회 이름이 화면에 출력
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_sName << endl;
	};

	/**
	*	@brief  시작 년월일 화면에 출력
	*	@pre	시작 년월일이 설정되어있어야함.
	*	@post	시작 년월일이 화면에 출력
	*/
	void DisplayDateOnScreen() 
	{
		cout << "\tDate : " << m_sDate << endl; 
	};

	/**
	*	@brief	학술대회 개최 횟수 스크린에 출력
	*	@pre	개최 횟수의 값이 저장되어있어야함.
	*	@post	개최 횟수 값이 화면에 출력
	*/
	void DisplayNumOnScreen()
	{
		cout << "\tNumber of time  : " << m_Num << endl;
	};

	/**
	*	@brief	개최 기관 화면에 출력
	*	@pre	개최 기관 값이 설정되어있어야함
	*	@post	개최 기관이 화면에 출력
	*/
	void DisplayOrganizationOnScreen() 
	{
		cout << "\tOrganization : " << m_sOrg << endl; 
	};

	/**
	*	@brief	학술대회 명 약자 화면에 출력
	*	@pre	학술대회 명 약자 값이 설정되어있어야함
	*	@post	학술대회 명 약자이 화면에 출력
	*/
	void DisplayAbbrevationOnScreen()
	{
		cout << "\tAbbrevation : " << m_sAbrv << endl;
	};

	/**
	*	@brief	화면에 학술대회 레코드 출력하기
	*	@pre	학술대회 레코드가 설정되어있어야함.
	*	@post	학술대회 레코드가 화면에 출력
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayDateOnScreen();
		DisplayNumOnScreen();
		DisplayOrganizationOnScreen();
		DisplayAbbrevationOnScreen();
	};

	/**
	*	@brief	학술대회명 키보드로 입력해서 값 설정
	*	@pre	none.
	*	@post	학술대회명의 값이 설정됨.
	*/
	void SetNameFromKB();

	/**
	*	@brief	시작년월일 키보드로 입력해서 값 설정
	*	@pre	none.
	*	@post	시작년월일이 설정됨
	*/
	void SetDateFromKB();

	/**
	*	@brief	개최 횟수 키보드로 입력해서 값 설정
	*	@pre	none.
	*	@post	개최 횟수 설정됨
	*/
	void SetNumFromKB();

	/**
	*	@brief	개최 기관 키보드로 입력해서 값 설정
	*	@pre	none.
	*	@post	개최 기관 설정됨
	*/
	void SetOrganizationFromKB();

	/**
	*	@brief	학술 대회 명 약자 키보드로 입력해서 값 설정
	*	@pre	none.
	*	@post	학술 대회 명 약자 설정됨.
	*/
	void SetAbbrevationFromKB();

	/**
	*	@brief	학술대회 레코드 키보드로 입력해서 값 설정
	*	@pre	none.
	*	@post	학술대회 레코드가 설정됨
	*/
	void SetRecordFromKB();

	/**
	*	@brief	파일로부터 레코드 읽어들임.
	*	@pre	목표 파일이 열림
	*	@post	학술대회 레코드가 설정됨
	*	@param	fin	 파일 디스크립터
	*	@return	이 함수가 잘 작동하면 1 아니면 0 반환
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	파일에 레코드 쓰기
	*	@pre	해당 파일이 열림. 리스트는 초기화되어야함.
	*	@post	해당 파일이 새로운 학술대회 레코드에 포함됨
	*	@param	fout	파일 디스크립터
	*	@return	함수가 잘 작동하면 1 아님 0 반환
 	*/
	int WriteDataToFile(ofstream& fout);
	
	/**
	*	@brief	두 아이템 타입의 name 비교
	*	@pre	두 아이템 타입이 설정되어있어야함
	*	@post	없음
	*	@param	data	비교를 위한 아이템
	*	@return	this->m_sName이 data.m_sName보다 사전순으로 앞서면 GREATER 뒤에있으면 LESS 같으면 EQUAL			
	*/
	RelationType CompareByName(const ConferenceType &data);

	/**
	*	@brief	2개의 item id 로 비교
	*	@pre	2개의 item들은 값이 설정 되어있어야함.
	*	@param	item	비교할 아이템
	*	@return	return 1 만약 this.id > data.id, 아니라면 0
	*/
	bool operator>(ConferenceType item);

	/**
	*	@brief	2개의 item id 로 비교
	*	@pre	2개의 item들은 값이 설정 되어있어야함.
	*	@param	item	비교할 아이템
	*	@return	return 1 만약 this.id == data.id, 아니라면 0
	*/
	bool operator==(ConferenceType item);

	/**
	*	@brief	해당 item의 id 반환
	*	@pre	해당 item의 id는 값이 설정 되어있어야함
	*	@return	해당 item의 id 반환
	*/
	string operator+();

	/**
	*	@brief	해당 item의 레코드 출력
	*	@pre	해당 item의 레코드는 값이 설정되어있어야함
	*	@return	해당 아이템의 레코드 출력
	*/
	void operator-();

protected:
	string m_sName;		///< 학술대회 명
	int m_Num;			///< 개최 횟수
	string m_sDate;		///< 시작 년월일 ex)2018.03.19
	string m_sOrg;		///< 개최 기관
	string m_sAbrv;		///< 대회명 이니셜
	string m_sPlace;	///< 개최 장소
	string m_OpenDate;  ///< 개최 일시
	string m_sISBN;		///< isbn
	ArrayList<sessionType> sessionList; /// 
};

#endif	// _CONFERENCETYPE_H
