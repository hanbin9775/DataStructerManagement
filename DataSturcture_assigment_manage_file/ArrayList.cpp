/*
#include "ArrayList.h"
#include <string>

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
	if(m_Length > MAXSIZE - 1)
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
	if(!IsFull())
	{
		for(int i = 0; i<m_Length;i++){
			if (m_Array[i].CompareByName(inData) == EQUAL) {
				cout << "primary key는 중복될 수 없습니다";
				return 0;
			}
			if (m_Array[i].CompareByName(inData) == GREATER) {			// indata가 사전 순으로 더 앞에 있을 때
				for (int j = i; j < m_Length; j++) {
					m_Array[m_Length-j+i] = m_Array[m_Length-j+i-1];	// 기존 데이터들을 한칸씩 뒤로 미룬다
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
	if(m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
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
		if (m_Array[i].CompareByName(data)==EQUAL){
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
			if (m_Array[i].CompareByName(data)==EQUAL){

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
		if (m_Array[i].CompareByName(data)){
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
	int last = m_Length-1;
	int mid = (first + last) / 2;
	while (m_Array[mid].CompareByName(data) != EQUAL) {					// 찾을 때까지 진행	
		
		if ((first == last) && (m_Array[mid].CompareByName(data) != EQUAL)) {	// 해당 데이터 리스트에 없을 시
			cout << "\t해당 이름 없음\n";
			return 0;
		}

		if (m_Array[mid].CompareByName(data) == LESS) {					// 사전 순으로 해당 데이터가 뒤에 있다면
			first = mid+1;
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
int ArrayList<T>::GetByName(T& data) {
	if (m_Length == 0) { // 리스트 비어있음 0 리턴
		cout << "list 비어있음" << endl;
		return 0;
	}
	
	
	for (int i = 0; i < m_Length+1; i++) {
		string str(m_Array[i].GetName());
		if (string::npos!=str.find(data.GetName())){ // 레코드들의 이름에 primary key가 해당하는지 확인
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
*/