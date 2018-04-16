#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;


template<typename T>
class DoublyIterator;


/**
*	Linked Sorted List�� ���� Node Structure
*/
template <typename T>
struct DoublyNodeType
{
	T data;				/// ��忡 ���ִ� ������
	DoublyNodeType* prev;
	DoublyNodeType* next;		/// ���� ��带 ����Ű�� ������ ����
};


/**
*	�迭 ��� ������ sorted ����Ʈ
*	@author ���Ѻ�
*	@date   2018-03-29
*/
template <typename T>
class ArrayList
{
	friend class DoublyIterator<T>; //< DoublyIterator�� ģ�� Ŭ����.
public:
	/**
	*	Ŭ���� ������ Maxsize ���� ��ŭ�� itemtype �� �迭 �����Ҵ�
	*/
	ArrayList();

	/**
	*	�Ҹ���
	*/
	~ArrayList();

	/**
	*	��������� (deep copy)
	*/
	//ArrayList(const ArrayList<T>& copy);

	/**
	*	@brief	����Ʈ ����
	*	@pre	none.
	*	@post	����Ʈ�� �����
	*/
	void MakeEmpty();

	/**
	*	@brief  ���� ����Ʈ�� ���� ��������
	*	@pre	none.
	*	@post	none.
	*	@return	���� ����Ʈ�� ���� ��ȯ
	*/
	int GetLength() const;


	/**
	*	@brief	����Ʈ�� ����� �ִ��� Ȯ��
	*	@pre	����
	*	@post	����
	*	@return	����Ʈ�� ����� ������ true �ƴϸ� false
	*/
	bool IsEmpty();
	
	
	/**
	*	@brief	����Ʈ�� ���ο� ������ �߰�
	*	@pre	����Ʈ�� �����Ǿ��־���� 
	*	@post	����Ʈ�� ���ο� ���ڵ� �߰�
	*	@param	item	���ο� ������
	*	@return	�� �۵��ϸ� 1, �ƴϸ� 0 ��ȯ 
	*/
	int Add(T item);

	/**
	*	@brief	����Ʈ iterator�� �ʱ�ȭ
	*	@pre	����Ʈ�� �����Ǿ��־����
	*	@post	iterator�� ���µ�
	*/
	void ResetList();

	/**
	*	@brief	����Ʈ iterator�� ���� ���������� �ű�� �� �������� �����´�
	*	@pre	����Ʈ�� ����Ʈ iterator�� �ʱ�ȭ���� �ʾƾ� �Ѵ�.
	*	@post	iterator�� ���� ���������� �Űܰ�.
	*	@param	item	���� iterator�� �������� ������. �ʱ�ȭ �� �ʿ�� ����.
	*	@return	����Ʈ�� ���� �ƴ϶�� iterator�� �������� ���� ��ġ ��ȯ
	*/
	void GetNextItem(T& item);

	/**
	*	@brief	primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	*	@pre	���� 
	*	@post	����
	*	@param	item	primary key�� �ش��ϴ� ������ ������    
	*	@return	�ش��ϴ� �������� ��ȯ�ϸ� 1 �ƴϸ� 0 ��ȯ 
	*/
	int Get(T& item);

	/**
	*	@brief	primary key�� �������� �����͸� �˻��ϰ� �ش� �������� �ּҰ� ��ȯ (������)
	*	@pre	����
	*	@post	����
	*	@param	item	primary key�� �ش��ϴ� ������ ������
	*	@return	�ش��ϴ� Ŭ���� Ÿ������ data �ּҰ� ��ȯ
	*/
	T* Get2(T item);

	/**
	*	@brief	���� ���ڵ� ����
	*	@pre	none
	*	@post	none
	*	@param	item	������ ItemType
	*	@return	�����ϸ� 1 ��ȯ ���� �� 0 ��ȯ
	*/
	int Delete(T item);
	
	/**
	*	@brief	���� ���ڵ� ����
	*	@pre	none
	*	@post	none
	*	@param	item	���ŵ� ItemType
	*	@return �����ϸ� 1 ��ȯ ���� �� 0 ��ȯ 
	*/
	int Replace(T item);

	/**
	*	@brief	primary key(�̸�)�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	*	@pre	����
	*	@post	����
	*	@param	data	primary key�� �ش��ϴ� ������ ������
	*	@return �����ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int GetByPrimaryKey(T item);

	/**
	*	@brief	primary key(�̸�)�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	*	@pre	����
	*	@post	����
	*	@param	data	primary key�� �ش��ϴ� ������ ������
	*	@return �����ϸ� 1 �ƴϸ� 0 ��ȯ
	*/

private:
	DoublyNodeType<T>* m_pFirst;					///< Linked List�� ����Ű�� ���� ������
	int m_nLength;				///< ����Ʈ�� �ִ� ���� ����
	DoublyNodeType<T>* m_pLast;			///< ���� ��ġ ����Ű�� ������
};

//������
template <typename T> 
ArrayList<T>::ArrayList()
{
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->data = min; // �ּڰ�.
	m_pFirst->next = m_pLast; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.
	m_pFirst->prev = NULL; // ó��.

	m_pLast->data = max; //  �ִ�.
	m_pLast->next = NULL; // ��.
	m_pLast->prev = m_pFirst; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.

	m_nLength = 0; // ���̴� 0.
}

//�Ҹ���
template <typename T>
ArrayList<T>::~ArrayList()
{
	delete m_pFirst;
	delete m_pLast;
}
/*
//��������� (deep copy)
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
// ����Ʈ ����
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


// ���� ����Ʈ�� �ִ� ���ڵ� ���� ��������
template <typename T>
int ArrayList<T>::GetLength() const
{
	return m_nLength;
}


// ����Ʈ ������ִ��� Ȯ��
template <typename T>
bool ArrayList<T>::IsEmpty()
{
	if (m_nLength == 0)
		return true;
	else
		return false;
}

// ���������� ���� ����Ʈ�� ���ο� ������ �߰�
template <typename T>
int ArrayList<T>::Add(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	if (IsEmpty()) // ó�� ������ ��
	{
		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}
	else // ó���� �ƴ� ��
	{
		while (1)
		{
			if (item < itor.m_pCurPointer->data) // �´� �ڸ��� ã�´�.
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = itor.m_pCurPointer->prev;
				pItem->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem; // �������� ����.
				m_nLength++;
				return 1;
			}
			else if (item == itor.m_pCurPointer->data) // ���� ������ �������� ������
				return 0; // 0�� ��ȯ.
			else
				itor.Next(); // �������� �̵�.
		}
	}
}

// ����Ʈ iterartor �ʱ�ȭ
template <typename T>
void ArrayList<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}


// ����Ʈ iterator�� ���� ���������� �ű�� �� �������� �����´�
template <typename T>
void ArrayList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}

// �Ű������� item�� primary key ������ ����Ʈ�� �ִ� ���ڵ��� �� �� ��ġ�Ѵٸ� �� ���ڵ� item�� ����.
template <typename T>
int ArrayList<T>::Get(T& item) {
	DoublyIterator<T> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			item = itor.m_pCurPointer->data;
			return 1; // ��ġ�ϸ� 1�� ��ȯ.
		}
		else
			itor.Next(); // �������� �̵�.
	}

	return 0; // ��ġ���� ������ 0�� ��ȯ.
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
			itor.Next(); // �������� �̵�.
	}

	return NULL; // ��ġ���� ������ 0�� ��ȯ.

}

// �Ű������� item�� primary key ������ ����Ʈ�� �ִ� ���ڵ��� �� �� ��ġ�Ѵٸ� �� ���ڵ� ����
template <typename T>
int ArrayList<T>::Delete(T item) {
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item) // ��ġ�ϴ� �����͸� ã�´�.
		{
			DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
			pItem = itor.m_pCurPointer;
			itor.Next();
			pItem->prev->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev = pItem->prev; // �����ϴ� ����� �հ� �ڸ� ���� �̾��ش�.
			delete pItem; // ����.
			return;
		}
		else
			itor.Next();
	}
	m_nLength--; // ���� ����.
	return;
}

// �Ű������� item�� primary key ������ ����Ʈ�� �ִ� ���ڵ��� �� �� ��ġ�Ѵٸ� �� ���ڵ� ���� item�� ������ ����
template <typename T>
int ArrayList<T>::Replace(T item) {
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			itor.m_pCurPointer->data = item; // ������ ��ü.
			return;
		}
		else
			itor.Next();
	}

	return;

}


// primary key(�̸�)�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������. primary key�� ���Ե� �м���ȸ ������ ��� ������
template <typename T>
int ArrayList<T>::GetByPrimaryKey(T item) {
	if (m_nLength == 0) { // ����Ʈ ������� 0 ����
		cout << "list �������" << endl;
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
		GetNextItem(dummy); // �̷����ϸ� �ȵ�! 
	}*/
}


#endif