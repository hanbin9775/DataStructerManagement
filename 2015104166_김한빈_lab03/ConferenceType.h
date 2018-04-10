#ifndef _CONFERENCETYPE_H
#define _CONFERENCETYPE_H

#include "sessionType.h"


/**
*	�� ������ �� ����
*/
enum RelationType {LESS, GREATER, EQUAL};


/**
*	�м���ȸ ��, ���� �����, ���� Ƚ��, ���� ����� ������ ������ �ִ� ������ ���� Ŭ����
*	@author ���Ѻ�
*	@date   2018-04-10
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
		m_sAbrv = "";
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
	*	@brief	���� ��� �� ���� ��������
	*	@pre	���� ��� ���� �����Ǿ��־����
	*	@post	none.
	*	@return	���� ��� 
	*/
	string GetPlace()
	{
		return m_sPlace;
	}

	/**
	*	@brief	���� �Ͻ� �� ��������
	*	@pre	���� �Ͻ� ���� �����Ǿ��־����.
	*	@post	none.
	*	@return	���� �Ͻ�
	*/
	string GetOpenDate()
	{
		return m_OpenDate;
	}

	/**
	*	@brief	ISBN ��������
	*	@pre	ISBN ���� �����Ǿ��־����
	*	@post	none.
	*	@return	ISBN ��
	*/
	string GetISBN()
	{
		return m_sISBN;
	}

	/**
	*	@brief	SessionList ��������
	*	@pre	SessionList ���� �����Ǿ��־����
	*	@post	none.
	*	@return	SessionList ��
	*/
	ArrayList<sessionType>* GetsessionList()
	{
		ArrayList<sessionType> *sess = new ArrayList<sessionType>();
		sess = &(this->sessionList);
		return sess;
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
	*	@brief	�м���ȸ �� ���� �����ϱ�.
	*	@pre	none.
	*	@post	�м���ȸ �� ���� ���� �����
	*	@param	inAbrv	������ �м� ��ȸ�� ����
	*/
	void SetAbbrevation(string inAbrv)
	{
		m_sAbrv = inAbrv;
	}

	/**
	*	@brief	�м���ȸ ���� ��� �����ϱ�.
	*	@pre	none.
	*	@post	�м���ȸ ���� ��� ���� �����
	*	@param	inPlace	������ ��� ��ȸ�� ����
	*/
	void SetPlace(string inPlace)
	{
		m_sPlace = inPlace;
	}
	
	/**
	*	@brief	�м���ȸ ���� �Ͻ� �����ϱ�.
	*	@pre	none.
	*	@post	�м���ȸ ���� �Ͻ� ���� �����
	*	@param	inOpenDate	������ ���� ��� 
	*/
	void SetOpenDate(string inOpenDate)
	{
		m_OpenDate = inOpenDate;
	}

	/**
	*	@brief	ISBN �� �����ϱ�
	*	@pre	none.
	*	@post	ISBN ���� �����
	*	@param	inISBN	������ ISBN
	*/
	void SetISBN(string inISBN)
	{
		m_sISBN = inISBN;
	}

	/**
	*	@brief	�м� ���ڵ� ����
	*	@pre	����
	*	@post	�м� ���ڵ� ������
	*	@param	inName	�м���ȸ �� 
	*	@param	inDate	���۳����
	*	@param	inNum	���� Ƚ��
	*	@param	inOrg	���� ���
	*	@param	inAbrv	�м���ȸ�����
	*	@param	inPlace �м���ȸ ���� ���
	*	@param	inOpenDate	���� �Ͻ�
	*	@param	inISBN	ISBN
	*/
	void SetRecord(string inname, string indate,int innum ,string inorg,string inabrv, string inplace, string inopendate, string inisbn)
	{
		SetName(inname);
		SetDate(indate);
		SetNum(innum);
		SetOrganization(inorg);
		SetAbbrevation(inabrv);
		SetPlace(inplace);
		SetOpenDate(inopendate);
		SetISBN(inisbn);
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

	/**
	*	@brief	2���� item id �� ��
	*	@pre	2���� item���� ���� ���� �Ǿ��־����.
	*	@param	item	���� ������
	*	@return	return 1 ���� this.id > data.id, �ƴ϶�� 0
	*/
	bool operator>(ConferenceType item);

	/**
	*	@brief	2���� item id �� ��
	*	@pre	2���� item���� ���� ���� �Ǿ��־����.
	*	@param	item	���� ������
	*	@return	return 1 ���� this.id == data.id, �ƴ϶�� 0
	*/
	bool operator==(ConferenceType item);

	/**
	*	@brief	�ش� item�� id ��ȯ
	*	@pre	�ش� item�� id�� ���� ���� �Ǿ��־����
	*	@return	�ش� item�� id ��ȯ
	*/
	string operator+();

	/**
	*	@brief	�ش� item�� ���ڵ� ���
	*	@pre	�ش� item�� ���ڵ�� ���� �����Ǿ��־����
	*	@return	�ش� �������� ���ڵ� ���
	*/
	void operator-();

protected:
	string m_sName;		///< �м���ȸ ��
	int m_Num;			///< ���� Ƚ��
	string m_sDate;		///< ���� ����� ex)2018.03.19
	string m_sOrg;		///< ���� ���
	string m_sAbrv;		///< ��ȸ�� �̴ϼ�
	string m_sPlace;	///< ���� ���
	string m_OpenDate;  ///< ���� �Ͻ�
	string m_sISBN;		///< isbn
	ArrayList<sessionType> sessionList; /// 
};

#endif	// _CONFERENCETYPE_H
