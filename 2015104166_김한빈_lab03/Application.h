#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"
#include "ConferenceType.h"

#define FILENAMESIZE 1024


/**
*	아이템 관리를 간단히하기 위한 어플리케이션 클래스
*	@author 김한빈
*	@date   2018-03-29
*/
class Application
{
public:
	/**
	*	기본 생성자
	*/
	Application()
	{
		m_Command = 0;
	}
	
	/**
	*	소멸자
	*/
	~Application()	{}

	/**
	*	@brief	프로그램 드라이버
	*	@pre	프로그램이 시작된다
	*	@post	프로그램이 종료된다
	*/
	void Run();

	/**
	*	@brief	커맨드 화면에 띄우고 키보드로 입력받는다
	*	@pre	없음
	*	@post	없음
	*	@return	사용자의 커맨드
	*/
	int GetCommand();

	/**
	*	@brief	리스트에 레코드 추가
	*	@pre	리스트가 설정되어있어야함.
	*	@post	리스트에 새로운 레코드가 추가됨
	*	@return	잘 작동시 1, 아니면 0  반환
	*/
	int AddConference();

	/**
	*	@brief	모든 학술대회의 요약된 정보 화면 출력
	*	@pre	없음
	*	@post	없음
	*/
	void DisplayAllConferences();
	
	/**
	*	@brief	화면에 리스트에 있는 모든 레코드 요약 정보 출력 후 특정 학술대회 번호 입력받아 자세한 정보 출력
	*	@pre	없음
	*	@post	없음
	*/
	void GetConferenceInfo();

	/**
	*	@brief	파일 디스크립터를 통해 입력 파일로 파일 오픈
	*	@pre	읽기 가능한 파일이 존재한다
	*	@post	읽기를 위한 파일을 오픈
	*	@param	fileName	읽기를 위해 열 파일 이름
	*	@return	잘 작동하면 1 아니면 0 반환
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	파일 디스크립터를 이용해 출력 파일로 파일 오픈
	*	@pre	리스트가 설정되어있어야함
	*	@post	쓰기를 위한 파일 오픈
	*	@param	fileName	쓰기를 위해 열 파일 이름 
	*	@return	잘 작동하면 1, 아니면 0 반환
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	읽기 모드로 파일 열기 파일에 있는 모든 데이터 읽고 데이터로 리스트 설정
	*	@pre	파일은 오픈되어있지 않음.
	*	@post	파일에 있는 모든 레코드를 리스트에 가지고 있는다
	*	@return	잘 작동하면 1, 아니면 0 반환
	*/
	int ReadDataFromFile();

	/**
	*	@brief	모든 파일 쓰기 모드로 열고 모든 데이터 파일에 쓰기
	*	@pre	파일은 오픈되어있지 않음
	*	@post	출력 파일에 리스트가 적힌다
	*	@return	잘 작동하면 1 아니면 0 반환
	*/
	int WriteDataToFile();
	
	/**
	*	@brief	해당 데이터 리스트에서 삭제하기
	*	@pre	리스트가 비어있으면 안됨
	*	@post	해당 레코드가 삭제된 후 모든 레코드 화면에 출력
	*	@return	잘 작동하면 1 아니면 0 반환
	*/	
	int DeleteConference();

	/**
	*	@brief	해당 데이터 갱신하기
	*	@pre	리스트가 비어있으면 안됨
	*	@post	해당 레코드가 갱신된 후 모든 레고크 화면에 출력
	*	@return	잘 작동하면 1 아니면 0 반환
	*/
	int ReplaceConference();
	

	/**
	*	@brief	학술대회를 이름으로 검색하여 화면 출력
	*	@pre	리스트가 비어있으면 안됨
	*	@post	해당이름의 학술대회 정보 모두 출력
	*	@return	잘 작동하면 1 아니면 0 반환
	*/
	int RetrieveByName();

	/**
	*	@brief	모든 학술대회의 논문 중에서 키워드가 포함된 논문 출력
	*	@pre	리스트가 비어있으면 안됨
	*	@post	논문 제목, 제자, 페이지 수 출력 
	*	@return	잘 작동하면 1 아니면 0 반환
	*/
	//int RetrievePaperByName();

private:
	ifstream m_InFile;		///< 입력 파일 디스크립터
	ofstream m_OutFile;		///< 출력 파일 디스크립터
	ArrayList<ConferenceType> m_List;	///< ArrayList 형 m_list
	int m_Command;			///< 현재 커맨드 숫자
};

#endif	// _APPLICATION_H