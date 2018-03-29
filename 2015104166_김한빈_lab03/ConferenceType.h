
#ifndef _CONFERENCETYPE_H
#define _CONFERENCETYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
*	�� ������ �� ����
*/
enum RelationType {LESS, GREATER, EQUAL};


/**
*	�м���ȸ ��, ���� �����, ���� Ƚ��, ���� ����� ������ ������ �ִ� ������ ���� Ŭ����
*	@author ���Ѻ�
*	@date   2018-03-29
*/
class ConferenceType
{
public:
	/**
	*	�⺻ ������
	*/
	ConferenceType()
	{
		m_sName = "";
		m_sDate = "";
		m_Num = -1;
		m_sOrg = "";
	}

	/**
	*	�Ҹ���
	*/
	~ConferenceType()	{}

	/**
	*	@brief	�м���ȸ �� ��������
	*	@pre	�м���ȸ �̸��� ���� �����Ǿ��־����.
	*	@post	����
	*	@return	�м���ȸ �̸�
	*/
	string GetName()
	{
		return m_sName;
	}

	/**
	*	@brief	���۳���� ��������
	*	@pre	���۳���� ���� �����Ǿ��־����
	*	@post	����
	*	@return	���۳����
	*/
	string GetDate()
	{
		return m_sDate;
	}

	/**
	*	@brief	���� Ƚ�� ��������
	*	@pre	���� Ƚ�� ���� �����Ǿ��־����.
	*	@post	none.
	*	@return	���� Ƚ��.
	*/
	int GetNum()
	{
		return m_Num;
	}

	/**
	*	@brief	���� ��� ��������
	*	@pre	���� ��� ���� �����Ǿ��־����
	*	@post	none.
	*	@return	���� ���.
	*/
	string GetOrg()
	{
		return m_sOrg;
	}
	
	/**
	*	@brief	�м���ȸ �� ���� ��������
	*	@pre	�м���ȸ �� ���� �����Ǿ��־����
	*	@post	none.
	*	@return	�м���ȸ �� ����
	*/
	string GetAbrv() 
	{
		return m_sAbrv;
	}

	/**
	*	@brief	�м���ȸ �̸� �� �����ϱ�
	*	@pre	none.
	*	@post	�м���ȸ �̸��� ���� �����
	*	@param	inName	������ �м���ȸ �̸�.
	*/
	void SetName(string inName)
	{
		m_sName = inName;
	}

	/**
	*	@brief	���۳���� ����
	*	@pre	����.
	*	@post	���۳���Ͽ� ���� �����.
	*	@param	indate	������ ���۳����
	*/
	void SetDate(string indate)
	{
		m_sDate = indate;
	}

	/**
	*	@brief	���� Ƚ�� ����
	*	@pre	����.
	*	@post	���� Ƚ���� ���� �����.
	*	@param	indate	������ ����Ƚ��
	*/
	void SetNum(int innum)
	{
		m_Num = innum;
	}


	/**
	*	@brief	���� ��� �� �����ϱ�.
	*	@pre	none.
	*	@post	���� ��� ���� �����
	*	@param	inOrg	������ ���� ��� 
	*/
	void SetOrganization(string inOrg)
	{
		m_sOrg = inOrg;
	}
	
	/**
	*	@brief	�м� ���ڵ� ����
	*	@pre	����
	*	@post	�м� ���ڵ� ������
	*	@param	inName	�м���ȸ �� 
	*	@param	inDate	���۳����
	*	@param	inNum	���� Ƚ��
	*	@param	inOrg	���� ���
	*/
	void SetRecord(string inname, string indate,int innum ,string inorg)
	{
		SetName(inname);
		SetDate(indate);
		SetNum(innum);
		SetOrganization(inorg);
	}

	/**
	*	@brief	�м���ȸ �� ȭ�鿡 ���
	*	@pre	�м���ȸ �̸� ���� �����Ǿ��־����
	*	@post	�м���ȸ �̸��� ȭ�鿡 ���
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_sName << endl;
	};

	/**
	*	@brief  ���� ����� ȭ�鿡 ���
	*	@pre	���� ������� �����Ǿ��־����.
	*	@post	���� ������� ȭ�鿡 ���
	*/
	void DisplayDateOnScreen() 
	{
		cout << "\tDate : " << m_sDate << endl; 
	};

	/**
	*	@brief	�м���ȸ ���� Ƚ�� ��ũ���� ���
	*	@pre	���� Ƚ���� ���� ����Ǿ��־����.
	*	@post	���� Ƚ�� ���� ȭ�鿡 ���
	*/
	void DisplayNumOnScreen()
	{
		cout << "\tNumber of time  : " << m_Num << endl;
	};

	/**
	*	@brief	���� ��� ȭ�鿡 ���
	*	@pre	���� ��� ���� �����Ǿ��־����
	*	@post	���� ����� ȭ�鿡 ���
	*/
	void DisplayOrganizationOnScreen() 
	{
		cout << "\tOrganization : " << m_sOrg << endl; 
	};

	/**
	*	@brief	�м���ȸ �� ���� ȭ�鿡 ���
	*	@pre	�м���ȸ �� ���� ���� �����Ǿ��־����
	*	@post	�м���ȸ �� ������ ȭ�鿡 ���
	*/
	void DisplayAbbrevationOnScreen()
	{
		cout << "\tAbbrevation : " << m_sAbrv << endl;
	};

	/**
	*	@brief	ȭ�鿡 �м���ȸ ���ڵ� ����ϱ�
	*	@pre	�м���ȸ ���ڵ尡 �����Ǿ��־����.
	*	@post	�м���ȸ ���ڵ尡 ȭ�鿡 ���
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayDateOnScreen();
		DisplayNumOnScreen();
		DisplayOrganizationOnScreen();
		DisplayAbbrevationOnScreen();
	};

	/**
	*	@brief	�м���ȸ�� Ű����� �Է��ؼ� �� ����
	*	@pre	none.
	*	@post	�м���ȸ���� ���� ������.
	*/
	void SetNameFromKB();

	/**
	*	@brief	���۳���� Ű����� �Է��ؼ� �� ����
	*	@pre	none.
	*	@post	���۳������ ������
	*/
	void SetDateFromKB();

	/**
	*	@brief	���� Ƚ�� Ű����� �Է��ؼ� �� ����
	*	@pre	none.
	*	@post	���� Ƚ�� ������
	*/
	void SetNumFromKB();

	/**
	*	@brief	���� ��� Ű����� �Է��ؼ� �� ����
	*	@pre	none.
	*	@post	���� ��� ������
	*/
	void SetOrganizationFromKB();

	/**
	*	@brief	�м� ��ȸ �� ���� Ű����� �Է��ؼ� �� ����
	*	@pre	none.
	*	@post	�м� ��ȸ �� ���� ������.
	*/
	void SetAbbrevationFromKB();

	/**
	*	@brief	�м���ȸ ���ڵ� Ű����� �Է��ؼ� �� ����
	*	@pre	none.
	*	@post	�м���ȸ ���ڵ尡 ������
	*/
	void SetRecordFromKB();

	/**
	*	@brief	���Ϸκ��� ���ڵ� �о����.
	*	@pre	��ǥ ������ ����
	*	@post	�м���ȸ ���ڵ尡 ������
	*	@param	fin	 ���� ��ũ����
	*	@return	�� �Լ��� �� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	���Ͽ� ���ڵ� ����
	*	@pre	�ش� ������ ����. ����Ʈ�� �ʱ�ȭ�Ǿ����.
	*	@post	�ش� ������ ���ο� �м���ȸ ���ڵ忡 ���Ե�
	*	@param	fout	���� ��ũ����
	*	@return	�Լ��� �� �۵��ϸ� 1 �ƴ� 0 ��ȯ
 	*/
	int WriteDataToFile(ofstream& fout);
	
	/**
	*	@brief	�� ������ Ÿ���� name ��
	*	@pre	�� ������ Ÿ���� �����Ǿ��־����
	*	@post	����
	*	@param	data	�񱳸� ���� ������
	*	@return	this->m_sName�� data.m_sName���� ���������� �ռ��� GREATER �ڿ������� LESS ������ EQUAL			
	*/
	RelationType CompareByName(const ConferenceType &data);

protected:
	string m_sName;		///< �м���ȸ ��
	int m_Num;			///< ���� Ƚ��
	string m_sDate;		///< ���� ����� ex)2018.03.19
	string m_sOrg;		///< ���� ���
	string m_sAbrv;		///< ��ȸ�� �̴ϼ�
};

#endif	// _ConferenceType_H
