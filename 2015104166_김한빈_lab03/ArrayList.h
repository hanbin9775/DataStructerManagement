#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;


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
	NodeType<T>* m_pList;					///< Linked List�� ����Ű�� ���� ������
	int m_nLength;				///< ����Ʈ�� �ִ� ���� ����
	NodeType<T>* m_pCurPointer;			///< ���� ��ġ ����Ű�� ������
};

//������
template <typename T>
ArrayList<T>::ArrayList()
{
	m_nLength = 0;
	m_pList = NULL;
	//m_pList->next = NULL;
	m_pCurPointer = NULL;
}

//�Ҹ���
template <typename T>
ArrayList<T>::~ArrayList()
{
//	MakeEmpty();
}
/*
//��������� (deep copy)
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
	ResetList(); // ����Ʈ �ʱ�ȭ 

	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
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

			if (m_pCurPointer->data > node->data)
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

template <typename T>
T* ArrayList<T>::Get2(T item) {
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
			return &(location->data);
			//item = location->data;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}
	if (found == false) {
		cout << "�ش� ������ ã�� ���Ͽ����ϴ�" << endl;
		return NULL;
	}
	//if (found)
	//	return 1;
	//else
	//	return 0;	//ã���� 1, �׷��� ���ϸ� 0�� �����Ѵ�.

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