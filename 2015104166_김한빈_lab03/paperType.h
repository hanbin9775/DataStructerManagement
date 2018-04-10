#ifndef _PAPERTYPE_H
#define _PAPERTYPE_H

#include "ArrayList.h"
/**
*	�� ����, ����, ������ ���� ��� ������ ���� Ŭ����
*	@author ���Ѻ�
*	@date   2018-04-06
*/
class paperType {
public:
	
	/**
	*	�⺻ ������
	*/
	paperType() {
		string paperTitle = "";
		string author = "";
		int pageNum = -1;
	}
	
	/**
	*	�Ҹ���
	*/
	~paperType() {};

	/**
	*	@brief	�� �̸� Ű����� �Է��ؼ� �� ����
	*	@pre	none.
	*	@post	�� �̸��� ���� ������.
	*/
	void SetpaperTitleFromKB() {
		cout << "\tPaper Title : ";
		cin >> paperTitle;
	}

	/**
	*	@brief	�۰� �̸� Ű����� �Է��ؼ� �� ����
	*	@pre	none.
	*	@post   �۰� �̸��� ���� ������.
	*/
	void SetauthorFromKB() {
		cout << "\tAuthor : ";
		cin >> author;
	}

	/**
	*	@brief	�� ������ �� Ű����� �Է��ؼ� �� ����
	*	@pre	none.
	*	@post   �� ������ �� ���� ������.
	*/
	void SetpageNumFromKB() {
		cout << "\tPage number : ";
		cin >> pageNum;
	}

	/**
	*	@brief	�� ������ �� Ű����� �Է��ؼ� �� ����
	*	@pre	none.
	*	@post   �� ������ �� ���� ������.
	*/
	void SetPaperFromKB() {
		SetpaperTitleFromKB();
		SetauthorFromKB();
		SetpageNumFromKB();
	}

	/**
	*	@brief	�� ���� ��������
	*	@pre	�� ���� ���� �����Ǿ��־����.
	*	@post	����
	*	@return	�� ���� 
	*/
	string GetpaperTitle()
	{
		return paperTitle;
	}

	/**
	*	@brief	���� ��������
	*	@pre	�� ���� ���� �����Ǿ��־����.
	*	@post	����
	*	@return	�� ����
	*/
	string Getauthor()
	{
		return author;
	}

	/**
	*	@brief	�� ������ �� ��������
	*	@pre	��  ������ �� ���� �����Ǿ��־����.
	*	@post	����
	*	@return	�� ������ ��
	*/
	int GetpageNum()
	{
		return pageNum;
	}

	/**
	*	@brief  �� ���� ȭ�鿡 ���
	*	@pre	�� ���� ���� �����Ǿ��־����
	*	@post	�� ������ ȭ�鿡 ���
	*/
	void DisplayPaperTitleOnScreen()
	{
		cout << "\tPaper Title : " << paperTitle << endl;
	};

	/**
	*	@brief	�� ���� ȭ�鿡 ���
	*	@pre	�� ���� ���� �����Ǿ��־����
	*	@post	�� ���� ȭ�鿡 ���
	*/
	void DisplayAuthorOnScreen()
	{
		cout << "\tAuthor : " << author << endl;
	};

	/**
	*	@brief	�� �ʼ� ȭ�鿡 ���
	*	@pre	�� �ʼ� ���� �����Ǿ��־����
	*	@post	�� �ʼ� ȭ�鿡 ���
	*/
	void DisplayPageNumOnScreen()
	{
		cout << "\tpageNum : " << pageNum << endl;
	};

	/**
	*	@brief	�� ���ڵ� ȭ�鿡 ���
	*	@pre	�� ���ڵ� ���� �����Ǿ��־����
	*	@post	�� ���ڵ� ȭ�鿡 ���
	*/
	void DisplayPaperRecordOnScreen()
	{
		DisplayPaperTitleOnScreen();
		DisplayAuthorOnScreen();
		DisplayPageNumOnScreen();
	};


	/**
	*	@brief	2���� item id �� ��
	*	@pre	2���� item���� ���� ���� �Ǿ��־����.
	*	@param	item	���� ������
	*	@return	return 1 ���� this.id > data.id, �ƴ϶�� 0
	*/
	bool operator>(paperType item) {
		return (this->GetpaperTitle() > item.GetpaperTitle());
	}

	/**
	*	@brief	2���� item id �� ��
	*	@pre	2���� item���� ���� ���� �Ǿ��־����.
	*	@param	item	���� ������
	*	@return	return 1 ���� this.id == data.id, �ƴ϶�� 0
	*/
	bool operator==(paperType item) {
		return (this->GetpaperTitle() == item.GetpaperTitle());
	}

	/**
	*	@brief	�ش� item�� id ��ȯ
	*	@pre	�ش� item�� id�� ���� ���� �Ǿ��־����
	*	@return	�ش� item�� id ��ȯ
	*/
	string operator+() {
		return this->GetpaperTitle();
	}

	/**
	*	@brief	�ش� item�� ���ڵ� ���
	*	@pre	�ش� item�� ���ڵ�� ���� �����Ǿ��־����
	*	@return	�ش� �������� ���ڵ� ���
	*/
	void operator-() {
		return this->DisplayPaperRecordOnScreen();
	}

private:
	string paperTitle;		// �� ����
	string author;			// ����
	int pageNum;			// ������ ��
};

#endif 
