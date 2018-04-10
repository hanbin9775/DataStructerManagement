#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "ConferenceType.h"

#define FILENAMESIZE 1024


/**
*	������ ������ �������ϱ� ���� ���ø����̼� Ŭ����
*	@author ���Ѻ�
*	@date   2018-04-10
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
	~Application(){}

	/**
	*	@brief	���α׷� ����̹�
	*	@pre	���α׷��� ���۵ȴ�
	*	@post	���α׷��� ����ȴ�
	*/
	void Run();

	/**
	*	@brief	���α׷� ����̹�
	*	@pre	���α׷��� ���۵ȴ�
	*	@post	���α׷��� ����ȴ�
	*/
	void RunSession();

	/**
	*	@brief	���α׷� ����̹�
	*	@pre	���α׷��� ���۵ȴ�
	*	@post	���α׷��� ����ȴ�
	*/
	void RunPaper(ConferenceType* item);

	/**
	*	@brief	Ŀ�ǵ� ȭ�鿡 ���� Ű����� �Է¹޴´�
	*	@pre	����
	*	@post	����
	*	@return	������� Ŀ�ǵ�
	*/
	int GetCommand();

	/**
	*	@brief	Ŀ�ǵ� ȭ�鿡 ���� Ű����� �Է¹޴´�
	*	@pre	����
	*	@post	����
	*	@return	������� Ŀ�ǵ�
	*/
	int GetCommandSession();

	/**
	*	@brief	Ŀ�ǵ� ȭ�鿡 ���� Ű����� �Է¹޴´�
	*	@pre	����
	*	@post	����
	*	@return	������� Ŀ�ǵ�
	*/
	int GetCommandPaper();

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
	*	@brief	�ش� �м���ȸ�� ���� ���
	*	@pre	����
	*	@post	����
	*	@param  targetconf	����ϰ���� ������ �м���ȸ
	*/
	void DisplayAllSessions(ConferenceType* targetconf);
	
	/**
	*	@brief	�ش� ������ �� ���
	*	@pre	����
	*	@post	����
	*	@param  targetsess	����ϰ���� ���� ����
	*/
	void DisplayAllPapers(sessionType* targetsess);

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
	*	@brief	�ش� ������ ����Ʈ���� �����ϱ�
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�ش� ���ڵ尡 ������ �� ��� ���ڵ� ȭ�鿡 ���
	*   @param  item ������ ������ �ִ� ���� ����Ű�� ConferenceType�� ������
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int DeleteSession(ConferenceType* item);

	/**
	*	@brief	�ش� ������ ����Ʈ���� �����ϱ�
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�ش� ���ڵ尡 ������ �� ��� ���ڵ� ȭ�鿡 ���
	*   @param  items ������ ���� �ִ� ���� ����Ű�� session�� ������
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int DeletePaper(sessionType* items);

	/**
	*	@brief	�ش� ������ �����ϱ�
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�ش� ���ڵ尡 ���ŵ� �� ��� ���ڵ� ȭ�鿡 ���
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int ReplaceConference();
	
	/**
	*	@brief	�ش� ������ �����ϱ�
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�ش� ���ڵ尡 ���ŵ� �� ��� ���ڵ� ȭ�鿡 ���
	*   @param  item ������ ������ �ִ� ���� ����Ű�� ConferenceType�� ������
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int ReplaceSession(ConferenceType* item);

	/**
	*	@brief	�ش� ������ �����ϱ�
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�ش� ���ڵ尡 ���ŵ� �� ��� ���ڵ� ȭ�鿡 ���
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int ReplacePaper(sessionType* item);

	/**
	*	@brief	�м���ȸ�� �̸����� �˻��Ͽ� ȭ�� ���
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�ش��̸��� �м���ȸ ���� ��� ���
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int RetrieveByName();

	/**
	*	@brief	������ �̸����� �˻��Ͽ� ȭ�� ���
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�ش��̸��� ���� ���� ��� ���
	*	@param  item	������ �̸��� �˻��� ConferenceType�� ������
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int RetrieveBySessionName(ConferenceType* item);

	/**
	*	@brief	���� �̸����� �˻��Ͽ� ȭ�� ���
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�ش��̸��� �� ���� ��� ���
	*	@param  item	�˻��� ���� �ִ� ���� ����Ű�� sessionType�� ������
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int RetrieveByPaperName(sessionType* item);

	/**
	*	@brief	��� �м���ȸ�� �� �߿��� Ű���尡 ���Ե� �� ���
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�� ����, ����, ������ �� ��� 
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int RetrievePaperByName();

	/**
	*	@brief	�ش��ϴ� �м���ȸ�� Session �߰�
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�м���ȸ�� session �߰���
	*   @param  item �߰��� ������ �ִ� ���� ����Ű�� ConferenceType�� ������
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int AddSession(ConferenceType* item);

	/**
	*	@brief	�ش��ϴ� �м���ȸ�� Session�� �� �߰�
	*	@pre	����Ʈ�� ��������� �ȵ�
	*	@post	�м���ȸ session�� �� �߰���
	*   @param  items �߰��� ���� �ִ� ���� ����Ű�� sessionType�� ������
	*	@return	�� �۵��ϸ� 1 �ƴϸ� 0 ��ȯ
	*/
	int AddPaper(sessionType* items);

public:
	ifstream m_InFile;		///< �Է� ���� ��ũ����
	ofstream m_OutFile;		///< ��� ���� ��ũ����
	ArrayList<ConferenceType> m_List;	///< ArrayList �� m_list
	int m_Command;			///< ���� Ŀ�ǵ� ����(conference)
	int m_Commands;			///< ���� Ŀ�ǵ� ����(session)
	int m_Commandp;			///< ���� Ŀ�ǵ� ����(paper)
};

#endif	// _APPLICATION_H