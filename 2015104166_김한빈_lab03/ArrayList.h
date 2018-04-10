#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;


/**
*	Linked Sorted List를 위한 Node Structure
*/
template <typename T>
struct NodeType
{
	T data;				/// 노드에 들어가있는 데이터
	NodeType* next;		/// 다음 노드를 가리키는 포인터 변수
};


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
	NodeType<T>* m_pList;					///< Linked List를 가리키기 위한 포인터
	int m_nLength;				///< 리스트에 있는 원소 개수
	NodeType<T>* m_pCurPointer;			///< 현재 위치 가리키는 포인터
};

//생성자
template <typename T>
ArrayList<T>::ArrayList()
{
	m_nLength = 0;
	m_pList = NULL;
	//m_pList->next = NULL;
	m_pCurPointer = NULL;
}

//소멸자
template <typename T>
ArrayList<T>::~ArrayList()
{
//	MakeEmpty();
}
/*
//복사생성자 (deep copy)
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copy) {
	NodeType<T>* ptr1;
	NodeType<T>* ptr2;
	if (copy.m_pCurPointer == NULL)
		m_pCurPointer = NULL;
	else {
		ptr2 = new NodeType<T>;
		m_pCurPointer = ptr2;
		ptr2->data = copy.m_pCurPointer->data;
		ptr1 = copy.m_pCurPointer->next;
		while (ptr1 != NULL) {
			ptr2->next = new NodeType<T>;
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
	NodeType<T>* tempPtr;

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
	ResetList(); // 리스트 초기화 

	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			if (m_pCurPointer->data > node->data)
			{
				if (pre == NULL)
				{
					node->next = m_pCurPointer;
					m_pList = node;
					break;
				}	//넣을 자리 앞 원소가 존재하지 않을 때 첫번째 원소로 삽입.
				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}	//지금 가리키는 원소의 item값이 node의 item값보다 클 경우 pre 뒷자리에 삽입.

				// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
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
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;	//찾으면 1, 그렇지 못하면 0을 리턴한다.

}

template <typename T>
T* ArrayList<T>::Get2(T item) {
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			return &(location->data);
			//item = location->data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}
	if (found == false) {
		cout << "해당 데이터 찾지 못하였습니다" << endl;
		return NULL;
	}
	//if (found)
	//	return 1;
	//else
	//	return 0;	//찾으면 1, 그렇지 못하면 0을 리턴한다.

}

// 매개변수인 item의 primary key 정보로 리스트에 있는 레코드들과 비교 후 일치한다면 그 레코드 삭제
template <typename T>
int ArrayList<T>::Delete(T item) {
	bool moreToSearch, found;
	NodeType<T>* pre = NULL;	//변수 선언

	m_pCurPointer = m_pList;
	found = false;
	moreToSearch = (m_pCurPointer != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == m_pCurPointer->data)	//현재 가리키는 원소의 값과 item의 값이 일치할 때
		{
			found = true;	//찾았으므로 found 값 변경
			if (pre == NULL)
				m_pList = m_pCurPointer->next;	//항목 이전에 다른 원소가 없을 때 항목의 다음 원소를 첫번째 원소로 한다.
			else
			{
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}	//이전의 원소의 다음 원소를 '가리키는 항목의 다음 원소'로 바꾼다.
			m_nLength--;	//리스트의 길이를 1 줄여준다.
		}
		else
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);
		}	//일치하지 않을 때 다음 원소를 가리킨다. 단, pre는 지금의 원소를 가리킨다.
	}

	if (found)
		return 1;
	else
		return 0;	//삭제가 성공하면 1, 아니면 0을 리턴한다.
}

// 매개변수인 item의 primary key 정보로 리스트에 있는 레코드들과 비교 후 일치한다면 그 레코드 값들 item의 값으로 갱신
template <typename T>
int ArrayList<T>::Replace(T item) {
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 리스트의 항목에 item을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;	//수정에 성공하면 1, 그렇지 못하면 0을 리턴한다.

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