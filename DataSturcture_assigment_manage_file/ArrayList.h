#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;


template<typename T>
class DoublyIterator;


/**
*	Linked Sorted List를 위한 Node Structure
*/
template <typename T>
struct DoublyNodeType
{
	T data;				/// 노드에 들어가있는 데이터
	DoublyNodeType* prev;
	DoublyNodeType* next;		/// 다음 노드를 가리키는 포인터 변수
};


/**
*	배열 기반 간단한 sorted 리스트
*	@author 김한빈
*	@date   2018-03-29
*/
template <typename T>
class ArrayList
{
	friend class DoublyIterator<T>; //< DoublyIterator와 친구 클래스.
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
	*	복사생성자 (deep copy)
	*/
	//ArrayList(const ArrayList<T>& copy);

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
	int GetLength() const;


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
	*	@param	item	새로운 데이터
	*	@return	잘 작동하면 1, 아니면 0 반환 
	*/
	int Add(T item);

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
	*	@param	item	현재 iterator의 아이템을 가져옴. 초기화 될 필요는 없음.
	*	@return	리스트의 끝이 아니라면 iterator의 아이템의 현재 위치 반환
	*/
	void GetNextItem(T& item);

	/**
	*	@brief	primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	*	@pre	없음 
	*	@post	없음
	*	@param	item	primary key에 해당하는 아이템 가져옴    
	*	@return	해당하는 아이템을 반환하면 1 아니면 0 반환 
	*/
	int Get(T& item);

	/**
	*	@brief	primary key를 기준으로 데이터를 검색하고 해당 데이터의 주소값 반환 (참조용)
	*	@pre	없음
	*	@post	없음
	*	@param	item	primary key에 해당하는 아이템 가져옴
	*	@return	해당하는 클래스 타입형의 data 주소값 반환
	*/
	T* Get2(T item);

	/**
	*	@brief	기존 레코드 삭제
	*	@pre	none
	*	@post	none
	*	@param	item	삭제될 ItemType
	*	@return	성공하면 1 반환 실패 시 0 반환
	*/
	int Delete(T item);
	
	/**
	*	@brief	기존 레코드 갱신
	*	@pre	none
	*	@post	none
	*	@param	item	갱신될 ItemType
	*	@return 성공하면 1 반환 실패 시 0 반환 
	*/
	int Replace(T item);

	/**
	*	@brief	primary key(이름)를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	*	@pre	없음
	*	@post	없음
	*	@param	data	primary key에 해당하는 아이템 가져옴
	*	@return 성공하면 1 아니면 0 반환
	*/
	int GetByPrimaryKey(T item);

	/**
	*	@brief	primary key(이름)를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	*	@pre	없음
	*	@post	없음
	*	@param	data	primary key에 해당하는 아이템 가져옴
	*	@return 성공하면 1 아니면 0 반환
	*/

private:
	DoublyNodeType<T>* m_pFirst;					///< Linked List를 가리키기 위한 포인터
	int m_nLength;				///< 리스트에 있는 원소 개수
	DoublyNodeType<T>* m_pLast;			///< 현재 위치 가리키는 포인터
};

//생성자
template <typename T> 
ArrayList<T>::ArrayList()
{
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->data = min; // 최솟값.
	m_pFirst->next = m_pLast; // 끝과 처음이 서로를 가리키게 초기화.
	m_pFirst->prev = NULL; // 처음.

	m_pLast->data = max; //  최댓값.
	m_pLast->next = NULL; // 끝.
	m_pLast->prev = m_pFirst; // 끝과 처음이 서로를 가리키게 초기화.

	m_nLength = 0; // 길이는 0.
}

//소멸자
template <typename T>
ArrayList<T>::~ArrayList()
{
	delete m_pFirst;
	delete m_pLast;
}
/*
//복사생성자 (deep copy)
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copy) {
	DoublyNodeType<T>* ptr1;
	DoublyNodeType<T>* ptr2;
	if (copy.m_pCurPointer == NULL)
		m_pCurPointer = NULL;
	else {
		ptr2 = new DoublyNodeType<T>;
		m_pCurPointer = ptr2;
		ptr2->data = copy.m_pCurPointer->data;
		ptr1 = copy.m_pCurPointer->next;
		while (ptr1 != NULL) {
			ptr2->next = new DoublyNodeType<T>;
			ptr2 = ptr2->next;
			ptr2->data = ptr1->data;
			ptr1 = ptr1->next;
		}
		ptr2->next = NULL;
	}
}
*/
// 리스트 비우기
template <typename T>
void ArrayList<T>::MakeEmpty()
{
	DoublyNodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}
	
	m_nLength = 0;
}


// 현재 리스트에 있는 레코드 개수 가져오기
template <typename T>
int ArrayList<T>::GetLength() const
{
	return m_nLength;
}


// 리스트 비워져있는지 확인
template <typename T>
bool ArrayList<T>::IsEmpty()
{
	if (m_nLength == 0)
		return true;
	else
		return false;
}

// 사전순으로 정렬 리스트에 새로운 데이터 추가
template <typename T>
int ArrayList<T>::Add(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // 다음으로 이동.

	if (IsEmpty()) // 처음 삽입할 때
	{
		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // 처음과 끝 사이에 삽입.
		m_nLength++;
		return 1;
	}
	else // 처음이 아닐 때
	{
		while (1)
		{
			if (item < itor.m_pCurPointer->data) // 맞는 자리를 찾는다.
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = itor.m_pCurPointer->prev;
				pItem->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem; // 아이템을 삽입.
				m_nLength++;
				return 1;
			}
			else if (item == itor.m_pCurPointer->data) // 같은 정보의 아이템이 있으면
				return 0; // 0을 반환.
			else
				itor.Next(); // 다음으로 이동.
		}
	}
}

// 리스트 iterartor 초기화
template <typename T>
void ArrayList<T>::ResetList()
{
	// current pointer 초기화
	m_pCurPointer = NULL;
}


// 리스트 iterator를 다음 아이템으로 옮기고 그 아이템을 가져온다
template <typename T>
void ArrayList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
}

// 매개변수인 item의 primary key 정보로 리스트에 있는 레코드들과 비교 후 일치한다면 그 레코드 item에 저장.
template <typename T>
int ArrayList<T>::Get(T& item) {
	DoublyIterator<T> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			item = itor.m_pCurPointer->data;
			return 1; // 일치하면 1을 반환.
		}
		else
			itor.Next(); // 다음으로 이동.
	}

	return 0; // 일치하지 않으면 0을 반환.
}

template <typename T>
T* ArrayList<T>::Get2(T item) {
DoublyIterator<T> itor(*this);
	itor.Next();

	while(itor.m_pCurPointer != m_pLast)
	{
		if(itor.m_pCurPointer->data == item)
		{
			return itor.m_pCurPointer->data;
		}
		else
			itor.Next(); // 다음으로 이동.
	}

	return NULL; // 일치하지 않으면 0을 반환.

}

// 매개변수인 item의 primary key 정보로 리스트에 있는 레코드들과 비교 후 일치한다면 그 레코드 삭제
template <typename T>
int ArrayList<T>::Delete(T item) {
	DoublyIterator<T> itor(*this);
	itor.Next(); // 다음으로 이동.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item) // 일치하는 데이터를 찾는다.
		{
			DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
			pItem = itor.m_pCurPointer;
			itor.Next();
			pItem->prev->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev = pItem->prev; // 삭제하는 노드의 앞과 뒤를 서로 이어준다.
			delete pItem; // 삭제.
			return;
		}
		else
			itor.Next();
	}
	m_nLength--; // 길이 감소.
	return;
}

// 매개변수인 item의 primary key 정보로 리스트에 있는 레코드들과 비교 후 일치한다면 그 레코드 값들 item의 값으로 갱신
template <typename T>
int ArrayList<T>::Replace(T item) {
	DoublyIterator<T> itor(*this);
	itor.Next(); // 다음으로 이동.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			itor.m_pCurPointer->data = item; // 정보를 교체.
			return;
		}
		else
			itor.Next();
	}

	return;

}


// primary key(이름)를 기준으로 데이터를 검색하고 해당 데이터를 가져옴. primary key가 포함된 학술대회 정보들 모두 가져옴
template <typename T>
int ArrayList<T>::GetByPrimaryKey(T item) {
	if (m_nLength == 0) { // 리스트 비어있음 0 리턴
		cout << "list 비어있음" << endl;
		return 0;
	}

	string str;
	T tmp;
	T dummy;
	tmp = item;
	ResetList();
	m_pCurPointer = m_pList;
	
	//cout <<(m_pCurPointer->data).operator+();
	for (int i = 0; i < m_nLength;i++) {
		str = (m_pCurPointer->data).operator+();	//operator+ == item.GetName()
		if (-1 != str.find(tmp.operator+())) {
			item = m_pCurPointer->data;
			item.operator-();						//operator- == item.DisplayRecordOnScreen
		}
		if(i!=m_nLength-1) GetNextItem(dummy);
	}
	
	/*
	while (m_pCurPointer != NULL) {
		str = (m_pCurPointer->data).operator+();	//operator+ == item.GetName()
		if (-1 != str.find(tmp.operator+())){ 
			item = m_pCurPointer->data; 
			item.operator-();						//operator- == item.DisplayRecordOnScreen
		}
		GetNextItem(dummy); // 이렇게하면 안됨! 
	}*/
}


#endif