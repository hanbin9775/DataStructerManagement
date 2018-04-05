#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ConferenceType.h"
#include "Application.h"

#define MAXSIZE 5

/**
*	Linked Sorted List�� ���� Node Structure
*/
template <typename T>
struct NodeType
{
	T data;				/// ��忡 ���ִ� ������
	NodeType* next;		/// ���� ��带 ����Ű�� ������ ����
};


/**
*	�迭 ��� ������ sorted ����Ʈ
*	@author ���Ѻ�
*	@date   2018-03-29
*/
template <typename T>
class ArrayList
{
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
	*	@brief	����Ʈ �� á���� Ȯ��
	*	@pre	none.
	*	@post	none.
	*	@return	�� á���� true �ƴϸ� false
	*/
	bool IsFull();

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
	*	@brief	primary key(�̸�)�� �������� �����͸� �̺й����� �˻��ϰ� �ش� �����͸� ������
	*	@pre	����
	*	@post	����
	*	@param	item	primary key�� �ش��ϴ� ������ ������
	*	@return �����ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int GetByBinarySearch(T& item);
	
	/**
	*	@brief	primary key(�̸�)�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	*	@pre	����
	*	@post	����
	*	@param	item	primary key�� �ش��ϴ� ������ ������
	*	@return �����ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int GetByName(T item);
	
	/**
	*	@brief	�ش��ϴ� ����Ʈ index�� ������ ��ȯ
	*	@pre	none
	*	@post	none
	*	@param	num		��ȯ�� �������� index
	*	@return �ش� index�� ������
	*/
	T GetItem(int num);

private:
	NodeType<T>* m_pList;					///< Linked List�� ����Ű�� ���� ������
	int m_Length;				///< ����Ʈ�� �ִ� ���� ����
	NodeType<T>* m_CurPointer;			///< ���� ��ġ ����Ű�� ������
};

//������
template <typename T>
ArrayList<T>::ArrayList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL:
}

//�Ҹ���
template <typename T>
ArrayList<T>::~ArrayList()
{
	MakeEmpty();
}

// ����Ʈ ����
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


// ���� ����Ʈ�� �ִ� ���ڵ� ���� ��������
template <typename T>
int ArrayList<T>::GetLength() const
{
	return m_Length;
}


// ����Ʈ �� á���� Ȯ��
template <typename T>
bool ArrayList<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// ����Ʈ ������ִ��� Ȯ��
template <typename T>
bool ArrayList<T>::IsEmpty()
{
	if (m_Length == 0)
		return true;
	else
		return false;
}

// ���������� ���� ����Ʈ�� ���ο� ������ �߰�
template <typename T>
int ArrayList<T>::Add(T item)
{
	ResetList(); // ����Ʈ �ʱ�ȭ 

	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = data;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (m_pCurPointer->item>node->data)
			{
				if (pre == NULL)
				{
					node->next = m_pCurPointer;
					m_pList = node;
					break;
				}	//���� �ڸ� �� ���Ұ� �������� ���� �� ù��° ���ҷ� ����.
				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}	//���� ����Ű�� ������ item���� node�� item������ Ŭ ��� pre ���ڸ��� ����.

				// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
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
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;	//ã���� 1, �׷��� ���ϸ� 0�� �����Ѵ�.

}

// �Ű������� item�� primary key ������ ����Ʈ�� �ִ� ���ڵ��� �� �� ��ġ�Ѵٸ� �� ���ڵ� ����
template <typename T>
int ArrayList<T>::Delete(T item) {
	bool moreToSearch, found;
	NodeType<T>* pre = NULL;	//���� ����

	m_pCurPointer = m_pList;
	found = false;
	moreToSearch = (m_pCurPointer != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == m_pCurPointer->data)	//���� ����Ű�� ������ ���� item�� ���� ��ġ�� ��
		{
			found = true;	//ã�����Ƿ� found �� ����
			if (pre == NULL)
				m_pList = m_pCurPointer->next;	//�׸� ������ �ٸ� ���Ұ� ���� �� �׸��� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.
			else
			{
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}	//������ ������ ���� ���Ҹ� '����Ű�� �׸��� ���� ����'�� �ٲ۴�.
			m_nLength--;	//����Ʈ�� ���̸� 1 �ٿ��ش�.
		}
		else
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);
		}	//��ġ���� ���� �� ���� ���Ҹ� ����Ų��. ��, pre�� ������ ���Ҹ� ����Ų��.
	}

	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �ƴϸ� 0�� �����Ѵ�.
}

// �Ű������� item�� primary key ������ ����Ʈ�� �ִ� ���ڵ��� �� �� ��ġ�Ѵٸ� �� ���ڵ� ���� item�� ������ ����
template <typename T>
int ArrayList<T>::Replace(T item) {
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �׷��� ���ϸ� 0�� �����Ѵ�.

}

// primary key(�̸�)�� �������� �����͸� �̺й����� �˻��ϰ� �ش� �����͸� ������
template <typename T>
int ArrayList<T>::GetByBinarySearch(T& item) {
	int first = 0;
	int last = m_Length - 1;
	int mid = (first + last) / 2;
	while (m_Array[mid].CompareByName(item) != EQUAL) {					// ã�� ������ ����	

		if ((first == last) && (m_Array[mid].CompareByName(item) != EQUAL)) {	// �ش� ������ ����Ʈ�� ���� ��
			cout << "\t�ش� �̸� ����\n";
			return 0;
		}

		if (m_Array[mid].CompareByName(item) == LESS) {					// ���� ������ �ش� �����Ͱ� �ڿ� �ִٸ�
			first = mid + 1;
			mid = (first + last) / 2;
		}
		else if (m_Array[mid].CompareByName(item) == GREATER) {			// ���� ������ �ش� �����Ͱ� �տ� �ִٸ�
			last = mid;
			mid = (first + last) / 2;
		}

	}
	item = m_Array[mid];
	return 1;
}

// primary key(�̸�)�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������. primary key�� ���Ե� �м���ȸ ������ ��� ������
template <typename T>
int ArrayList<T>::GetByName(T item) {
	if (m_Length == 0) { // ����Ʈ ������� 0 ����
		cout << "list �������" << endl;
		return 0;
	}

	string str;
	T tmp;
	tmp = item;


	for (int i = 0; i < m_Length + 1; i++) {	
		str = m_Array[i].GetName();
		if (-1 != str.find(tmp.GetName())) { // ���ڵ���� �̸��� primary key�� �ش��ϴ��� Ȯ��
			item = m_Array[i]; // item�� �ش� ���ڵ� ����
			item.DisplayRecordOnScreen(); // �ش� ���ڵ� ���
		}

	}
	return 1;
}

// �ش��ϴ� ����Ʈ index�� ������ ��ȯ
template <typename T>
T ArrayList<T>::GetItem(int num) {
	return m_Array[num];
}



#endif	// _UNSORTEDLIST_H