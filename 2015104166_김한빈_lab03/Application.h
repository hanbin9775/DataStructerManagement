#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"
#include "ConferenceType.h"

#define FILENAMESIZE 1024


/**
*	������ ������ �������ϱ� ���� ���ø����̼� Ŭ����
*	@author ���Ѻ�
*	@date   2018-03-29
*/
class Application
{
public:
	/**
	*	�⺻ ������
	*/
	Application()
	{
		m_Command = 0;
	}
	
	/**
	*	�Ҹ���
	*/
	~Application()	{}

	/**
	*	@brief	���α׷� ����̹�
	*	@pre	���α׷��� ���۵ȴ�
	*	@post	���α׷��� ����ȴ�
	*/
	void Run();

	/**
	*	@brief	Ŀ�ǵ� ȭ�鿡 ���� Ű����� �Է¹޴´�
	*	@pre	����
	*	@post	����
	*	@return	������� Ŀ�ǵ�
	*/
	int GetCommand();

	/**
	*	@brief	����Ʈ�� ���ڵ� �߰�
	*	@pre	����Ʈ�� �����Ǿ��־����.
	*	@post	����Ʈ�� ���ο� ���ڵ尡 �߰���
	*	@return	�� �۵��� 1, �ƴϸ� 0  ��ȯ
	*/
	int AddConference();

	/**
	*	@brief	��� �м���ȸ�� ���� ���� ȭ�� ���
	*	@pre	����
	*	@post	����
	*/
	void DisplayAllConferences();
	
	/**
	*	@brief	ȭ�鿡 ����Ʈ�� �ִ� ��� ���ڵ� ��� ���� ��� �� Ư�� �м���ȸ ��ȣ �Է¹޾� �ڼ��� ���� ���
	*	@pre	����
	*	@post	����
	*/
	void GetConferenceInfo();

	/**
	*	@brief	���� ��ũ���͸� ���� �Է� ���Ϸ� ���� ����
	*	@pre	�б� ������ ������ �����Ѵ�
	*	@post	�б⸦ ���� ������ ����
	*	@param	fileName	�б⸦ ���� �� ���� �̸�
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	���� ��ũ���͸� �̿��� ��� ���Ϸ� ���� ����
	*	@pre	����Ʈ�� �����Ǿ��־����
	*	@post	���⸦ ���� ���� ����
	*	@param	fileName	���⸦ ���� �� ���� �̸� 
	*	@return	�� �۵��ϸ� 1, �ƴϸ� 0 ��ȯ
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	�б� ���� ���� ���� ���Ͽ� �ִ� ��� ������ �а� �����ͷ� ����Ʈ ����
	*	@pre	������ ���µǾ����� ����.
	*	@post	���Ͽ� �ִ� ��� ���ڵ带 ����Ʈ�� ������ �ִ´�
	*	@return	�� �۵��ϸ� 1, �ƴϸ� 0 ��ȯ
	*/
	int ReadDataFromFile();

	/**
	*	@brief	��� ���� ���� ���� ���� ��� ������ ���Ͽ� ����
	*	@pre	������ ���µǾ����� ����
	*	@post	��� ���Ͽ� ����Ʈ�� ������
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int WriteDataToFile();
	
	/**
	*	@brief	�ش� ������ ����Ʈ���� �����ϱ�
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�ش� ���ڵ尡 ������ �� ��� ���ڵ� ȭ�鿡 ���
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/	
	int DeleteConference();

	/**
	*	@brief	�ش� ������ �����ϱ�
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�ش� ���ڵ尡 ���ŵ� �� ��� ����ũ ȭ�鿡 ���
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int ReplaceConference();
	

	/**
	*	@brief	�м���ȸ�� �̸����� �˻��Ͽ� ȭ�� ���
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�ش��̸��� �м���ȸ ���� ��� ���
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int RetrieveByName();

	/**
	*	@brief	��� �м���ȸ�� �� �߿��� Ű���尡 ���Ե� �� ���
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�� ����, ����, ������ �� ��� 
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	//int RetrievePaperByName();

private:
	ifstream m_InFile;		///< �Է� ���� ��ũ����
	ofstream m_OutFile;		///< ��� ���� ��ũ����
	ArrayList<ConferenceType> m_List;	///< ArrayList �� m_list
	int m_Command;			///< ���� Ŀ�ǵ� ����
};

#endif	// _APPLICATION_H