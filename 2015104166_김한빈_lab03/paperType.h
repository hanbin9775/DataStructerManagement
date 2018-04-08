#ifndef _PAPERTYPE_H
#define _PAPERTYPE_H

#include <string>
#include "ArrayList.h"
#include "sessionType.h"
using namespace std;

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

private:
	string paperTitle;		// �� ����
	string author;			// ����
	int pageNum;			// ������ ��
};

#endif 
