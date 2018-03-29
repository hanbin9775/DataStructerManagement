#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ConferenceType.h"

#define MAXSIZE 5

/**
*	배열 기반 간단한 sorted 리스트
*	@author 김한빈
*	@date   2018-03-29
*/
template <typename T>
class ArrayList
{
public:
	/**
	*	클래스 생성시 Maxsize 길이 만큼의 itemtype 형 배열 동적할당
	*/
	ArrayList();

	/**
	*	소멸자
	*/
	~ArrayList();

	/**
	*	@brief	리스트 비우기
	*	@pre	none.
	*	@post	리스트가 비워짐
	*/
	void MakeEmpty();

	/**
	*	@brief  현재 리스트의 길이 가져오기
	*	@pre	none.
	*	@post	none.
	*	@return	현재 리스트의 길이 반환
	*/
	int GetLength();

	/**
	*	@brief	리스트 꽉 찼는지 확인
	*	@pre	none.
	*	@post	none.
	*	@return	꽉 찼으면 true 아니면 false
	*/
	bool IsFull();

	/**
	*	@brief	리스트가 비워져 있는지 확인
	*	@pre	없음
	*	@post	없음
	*	@return	리스트가 비워져 있으면 true 아니면 false
	*/
	bool IsEmpty();
	
	
	/**
	*	@brief	리스트에 새로운 데이터 추가
	*	@pre	리스트가 설정되어있어야함 
	*	@post	리스트에 새로운 레코드 추가
	*	@param	data	새로운 데이터
	*	@return	잘 작동하면 1, 아니면 0 반환 
	*/
	int Add(T data);

	/**
	*	@brief	리스트 iterator를 초기화
	*	@pre	리스트가 설정되어있어야함
	*	@post	iterator가 리셋됨
	*/
	void ResetList();

	/**
	*	@brief	리스트 iterator를 다음 아이템으로 옮기고 그 아이템을 가져온다
	*	@pre	리스트와 리스트 iterator는 초기화되지 않아야 한다.
	*	@post	iterator가 다음 아이템으로 옮겨감.
	*	@param	data	현재 iterator의 아이템을 가져옴. 초기화 될 필요는 없음.
	*	@return	리스트의 끝이 아니라면 iterator의 아이템의 현재 위치 반환
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	*	@pre	없음 
	*	@post	없음
	*	@param	data	primary key에 해당하는 아이템 가져옴    
	*	@return	해당하는 아이템을 반환하면 1 아니면 0 반환 
	*/
	int Get(T& data);

	/**
	*	@brief	기존 레코드 삭제
	*	@pre	none
	*	@post	none
	*	@param	data	삭제될 ItemType
	*	@return	성공하면 1 반환 실패 시 0 반환
	*/
	int Delete(T data);
	
	/**
	*	@brief	기존 레코드 갱신
	*	@pre	none
	*	@post	none
	*	@param	data	갱신될 ItemType
	*	@return 성공하면 1 반환 실패 시 0 반환 
	*/
	int Replace(T data);

	/**
	*	@brief	primary key(이름)를 기준으로 데이터를 이분법으로 검색하고 해당 데이터를 가져옴
	*	@pre	없음
	*	@post	없음
	*	@param	data	primary key에 해당하는 아이템 가져옴
	*	@return 성공하면 1 아니면 0 반환
	*/
	int GetByBinarySearch(T& data);
	
	/**
	*	@brief	primary key(이름)를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	*	@pre	없음
	*	@post	없음
	*	@param	data	primary key에 해당하는 아이템 가져옴
	*	@return 성공하면 1 아니면 0 반환
	*/
	int GetByName(T data);
	
	/**
	*	@brief	해당하는 리스트 index의 아이템 반환
	*	@pre	none
	*	@post	none
	*	@param	num		반환할 아이템의 index
	*	@return 해당 index의 아이템
	*/
	T GetItem(int num);

private:
	T *m_Array;  ///< 리스트 배열
	int m_Length;				///< 리스트에 있는 원소 개수
	int m_CurPointer;			///< iterator 포인터
};

//생성자
template <typename T>
ArrayList<T>::ArrayList()
{
	m_Array = new T[MAXSIZE];
	m_Length = 0;
	ResetList();
}

//소멸자
template <typename T>
ArrayList<T>::~ArrayList()
{
	delete[] m_Array;
}

// 리스트 비우기
template <typename T>
void ArrayList<T>::MakeEmpty()
{
	m_Length = 0;
}


// 현재 리스트에 있는 레코드 개수 가져오기
template <typename T>
int ArrayList<T>::GetLength()
{
	return m_Length;
}


// 리스트 꽉 찼는지 확인
template <typename T>
bool ArrayList<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// 리스트 비워져있는지 확인
template <typename T>
bool ArrayList<T>::IsEmpty()
{
	if (m_Length == 0)
		return true;
	else
		return false;
}

// 사전순으로 정렬 리스트에 새로운 데이터 추가
template <typename T>
int ArrayList<T>::Add(T inData)
{
	if (!IsFull())
	{
		for (int i = 0; i<m_Length; i++) {
			if (m_Array[i].CompareByName(inData) == EQUAL) {
				cout << "primary key는 중복될 수 없습니다";
				return 0;
			}
			if (m_Array[i].CompareByName(inData) == GREATER) {			// indata가 사전 순으로 더 앞에 있을 때
				for (int j = i; j < m_Length; j++) {
					m_Array[m_Length - j + i] = m_Array[m_Length - j + i - 1];	// 기존 데이터들을 한칸씩 뒤로 미룬다
				}
				m_Array[i] = inData;
				m_Length++;
				return 1;
			}
		}
		m_Array[m_Length] = inData;		// indata가 사전 순으로 기존 리스트에서 제일 뒤 일때
		m_Length++;
		return 1;
	}
	else
	{
		cout << "\n\t	리스트 꽉 참!" << endl;
		return 0;

	}
}

// 리스트 iterartor 초기화
template <typename T>
void ArrayList<T>::ResetList()
{
	m_CurPointer = -1;
}


// 리스트 iterator를 다음 아이템으로 옮기고 그 아이템을 가져온다
template <typename T>
int ArrayList<T>::GetNextItem(T& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

// 매개변수인 data의 primary key 정보로 리스트에 있는 레코드들과 비교 후 일치한다면 그 레코드 data에 저장.
template <typename T>
int ArrayList<T>::Get(T& data) {
	if (m_Length == 0) { // 리스트 비어있음 -1 리턴
		cout << "list 비어있음" << endl;
		return 0;
	}

	for (int i = 0; i < m_Length; i++) {
		if (m_Array[i].CompareByName(data) == EQUAL) {
			data = m_Array[i]; // data에 해당 레코드 복사
			return 1; // 성공
		}
	}
	cout << "해당 레코드 없음" << endl; // 존재 하지 않으면 0 반환
	return 0;
}

// 매개변수인 data의 primary key 정보로 리스트에 있는 레코드들과 비교 후 일치한다면 그 레코드 삭제
template <typename T>
int ArrayList<T>::Delete(T data) {
	for (int i = 0; i < m_Length; i++) {
		if (m_Array[i].CompareByName(data) == EQUAL) {

			// 삭제를 위한 레코드 이동 진행하는 반복문
			for (int j = i; j < m_Length; j++) {
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;

			return 1;
		}
	}
	cout << "해당하는 레코드 없음" << endl;
	return 0;
}

// 매개변수인 data의 primary key 정보로 리스트에 있는 레코드들과 비교 후 일치한다면 그 레코드 값들 data의 값으로 갱신
template <typename T>
int ArrayList<T>::Replace(T data) {
	for (int i = 0; i < MAXSIZE; i++) {
		if (m_Array[i].CompareByName(data)) {
			m_Array[i] = data;
			return 1;
		}
	}
	cout << "해당하는 레코드 없음" << endl;
	return 0;
}

// primary key(이름)를 기준으로 데이터를 이분법으로 검색하고 해당 데이터를 가져옴
template <typename T>
int ArrayList<T>::GetByBinarySearch(T& data) {
	int first = 0;
	int last = m_Length - 1;
	int mid = (first + last) / 2;
	while (m_Array[mid].CompareByName(data) != EQUAL) {					// 찾을 때까지 진행	

		if ((first == last) && (m_Array[mid].CompareByName(data) != EQUAL)) {	// 해당 데이터 리스트에 없을 시
			cout << "\t해당 이름 없음\n";
			return 0;
		}

		if (m_Array[mid].CompareByName(data) == LESS) {					// 사전 순으로 해당 데이터가 뒤에 있다면
			first = mid + 1;
			mid = (first + last) / 2;
		}
		else if (m_Array[mid].CompareByName(data) == GREATER) {			// 사전 순으로 해당 데이터가 앞에 있다면
			last = mid;
			mid = (first + last) / 2;
		}

	}
	data = m_Array[mid];
	return 1;
}

// primary key(이름)를 기준으로 데이터를 검색하고 해당 데이터를 가져옴. primary key가 포함된 학술대회 정보들 모두 가져옴
template <typename T>
int ArrayList<T>::GetByName(T data) {
	if (m_Length == 0) { // 리스트 비어있음 0 리턴
		cout << "list 비어있음" << endl;
		return 0;
	}

	string str;
	T tmp;
	tmp = data;


	for (int i = 0; i < m_Length + 1; i++) {	
		str = m_Array[i].GetName();
		if (-1 != str.find(tmp.GetName())) { // 레코드들의 이름에 primary key가 해당하는지 확인
			data = m_Array[i]; // data에 해당 레코드 복사
			data.DisplayRecordOnScreen(); // 해당 레코드 출력
		}

	}
	return 1;
}

// 해당하는 리스트 index의 아이템 반환
template <typename T>
T ArrayList<T>::GetItem(int num) {
	return m_Array[num];
}



#endif	// _UNSORTEDLIST_H