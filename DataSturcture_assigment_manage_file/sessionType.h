#ifndef _SESSIONTYPE_H
#define _SESSIONTYPE_H

#include "paperType.h"


/**
*	���� �̸�, �� ����Ʈ�� �⺭ ������ ������ �ִ� Ŭ����Ÿ��
*	@author ���Ѻ�
*	@date   2018-04-06
*/
class sessionType 
{
public:
	
	/**
	*	�⺻ ������
	*/
	sessionType() {
		string sessionName = "";
	}

	/**
	*	�Ҹ���
	*/
	~sessionType() {};

	/**
	*	@brief	���� �̸� �����ϱ�
	*	@pre	����
	*	@post	�����̸��� �Ű������� ������ �����ȴ�
	*   @param   sN     sessionName�� ������ string ��
	*/
	void SetsessionName(string sN)
	{
		sessionName = sN;
	}

	/**
	*	@brief	���� ��������
	*	@pre	���� ���� �����Ǿ��־����.
	*	@post	����
	*	@return	����
	*/
	string GetsessionName()
	{
		return sessionName;
	}

	/**
	*	@brief	���� �̸� Ű����� �Է��ؼ� �� ����
	*	@pre	none.
	*	@post	���� �̸��� ���� ������.
	*/
	void SetSessionNameFromKB() {
		cout << "\tSession Name : ";
		cin >> sessionName;
	}

	/**
	*	@brief	���� �̸� ȭ�鿡 ���
	*	@pre	���� �̸� ���� �����Ǿ��־����
	*	@post	���� �̸��� ȭ�鿡 ���
	*/
	void DisplaySessionNameOnScreen()
	{
		cout << "\tName : " << sessionName << endl;
	};


	/**
	*	@brief	SessionList ��������
	*	@pre	SessionList ���� �����Ǿ��־����
	*	@post	none.
	*	@return	SessionList ��
	*/
	ArrayList<paperType>* GetpaperList()
	{
		ArrayList<paperType> *paper = new ArrayList<paperType>();
		paper = &(this->paperList);
		return paper;
	}

	/**
	*	@brief	2���� item id �� ��
	*	@pre	2���� item���� ���� ���� �Ǿ��־����.
	*	@param	item	���� ������
	*	@return	return 1 ���� this.id > data.id, �ƴ϶�� 0
	*/
	bool operator>(sessionType item);

	/**
	*	@brief	2���� item id �� ��
	*	@pre	2���� item���� ���� ���� �Ǿ��־����.
	*	@param	item	���� ������
	*	@return	return 1 ���� this.id == data.id, �ƴ϶�� 0
	*/
	bool operator==(sessionType item);

	/**
	*	@brief	�ش� item�� id ��ȯ
	*	@pre	�ش� item�� id�� ���� ���� �Ǿ��־����
	*	@return	�ش� item�� id ��ȯ
	*/
	string operator+() {
		return this->GetsessionName();
	}

	/**
	*	@brief	�ش� item�� ���ڵ� ���
	*	@pre	�ش� item�� ���ڵ�� ���� �����Ǿ��־����
	*	@return	�ش� �������� ���ڵ� ���
	*/
	void operator-() {
		DisplaySessionNameOnScreen();
	}

private:
	string sessionName;
	ArrayList<paperType> paperList;
};

#endif 


