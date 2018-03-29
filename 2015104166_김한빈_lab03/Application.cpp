#include "Application.h"


// ���α׷� ����̹�
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// ���ڵ带 ����Ʈ�� �߰�
			AddConference();
			break;
		case 2:		// ����Ʈ���� �ش� ���ڵ� ����
			DeleteConference();
			break;
		case 3:		// ����Ʈ���� �ش� ������ ����
			ReplaceConference();
			break;
		case 4:		// �м���ȸ�� �м���ȸ �̸����� �˻��Ͽ� ȭ�� ���
			RetrieveByName();
			break;
		case 5:		// �м���ȸ ��������� ȭ�鿡 ����ϰ�, Ư�� �м���ȸ ��ȣ�� �Է¹޾� ������ ���� ���
			GetConferenceInfo();
			break;
		case 6:		// ��� �м���ȸ�� ���� ������ ȭ�� ���
			DisplayAllConferences();
			break;
		case 7:		// ���Ͽ��� ����Ʈ ������ �о����
			ReadDataFromFile();
			break;
		case 8:		// ����Ʈ ������ ���Ͽ� �����ϱ�
			WriteDataToFile();
			break;
		case 0:     // ���α׷� ����
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// ȭ�鿡 Ŀ�ǵ� ���� Ű����� �Է¹���
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Search by name" << endl;
	cout << "\t   5 : Get Conference Info" << endl;
	cout << "\t   6 : Display Conference summary" << endl;
	cout << "\t   7 : Get from file" << endl; 
	cout << "\t   8 : Put to file " << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// ���ο� ���ڵ带 ����Ʈ�� �߰�
int Application::AddConference()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if(m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ConferenceType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	// ���� list ���

	cout << endl << "\t<<���� ����Ʈ ��Ȳ>>" << endl;
	DisplayAllConferences();

	return 1;
}


// ��� �м���ȸ�� ��൷ ������ ȭ�� ���
void Application::DisplayAllConferences()
{
	ConferenceType data;

	cout << "\n\tCurrent list" << endl << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.DisplayNameOnScreen();
		data.DisplayNumOnScreen();
		data.DisplayDateOnScreen();
		data.DisplayOrganizationOnScreen();
		cout << endl;
		curIndex = m_List.GetNextItem(data);
	}
}


// ���� ��ũ���͸� ���� �Է����Ϸ� ���� ����
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// �Է��� ���� ���� ����
	
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_InFile)	return 0;
	else	return 1;
}


// ��� �������� ���� descriptor ����
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// ����� ���� ���� ����.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// �б� ���� ���� ����, ���Ͽ��ִ� ��� ������ �о����.
int Application::ReadDataFromFile()
{
	int index = 0;
	ConferenceType data;	// �б�� �ӽ� ����
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while(!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	DisplayAllConferences();

	return 1;
}


// ���� ���� ���Ͽ���, ���Ͽ� ��� ������ ����
int Application::WriteDataToFile()
{
	ConferenceType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

//�м���ȸ�� ����Ʈ���� ����
int Application::DeleteConference() {
	if (m_List.IsEmpty()) {
		cout << "\t   List is Empty" << endl;
		return 0;
	}

	ConferenceType item;

	cout << "\t   �����ϰ� ���� �̸��� �Է��ϼ���" << endl;
	item.SetNameFromKB();
	m_List.Delete(item);

	cout << endl << "\t<<���� ����Ʈ ��Ȳ>>" << endl;
	DisplayAllConferences();

	return 1;
}

//�м���ȸ�� ����Ʈ���� ����
int Application::ReplaceConference() {
	if (m_List.IsEmpty()) {
		cout << "\t   List is Empty" << endl;
		return 0;
	}

	ConferenceType item;
	cout << "\t�����ϰ� ���� �̸��� �Է��ϼ���" << endl;
	item.SetNameFromKB();
	cout << "\t������ ��¥,���� Ƚ��,���� ����� �Է��ϼ���" << endl;
	item.SetDateFromKB();
	item.SetNumFromKB();
	item.SetOrganizationFromKB();
	m_List.Replace(item);
	
	cout << endl << "\t<<���� ����Ʈ ��Ȳ>>" << endl;
	DisplayAllConferences();

	return 1;
}

//�м���ȸ�� �м���ȸ �̸����� �˻��Ͽ� ȭ�� ���
int Application::RetrieveByName() {
	if (m_List.IsEmpty()) {
		cout << "\t   List is Empty" << endl;
		return 0;
	}

	ConferenceType item;
	cout << "\t�˻��ϰ� ���� Name�� �Է��ϼ���" << endl;
	item.SetNameFromKB();
	
	m_List.GetByName(item);
	
	return 1;
	/*}
	else
		return 0;*/
}

// �м���ȸ ��������� ȭ�鿡 ����ϰ�, Ư�� �м���ȸ ��ȣ�� �Է� �޾� �ڼ��� ���� ���
void Application::GetConferenceInfo() {
	ConferenceType data;

	cout << "\n\tCurrent list" << endl;

	// �м���ȸ ������� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		cout << curIndex+1 << ": ";
		data.DisplayAbbrevationOnScreen();
		cout << endl;
		curIndex = m_List.GetNextItem(data);
	}
	int num;
	cout << "\t�˻��� index �Է� : ";
	cin >> num;
	ConferenceType display = m_List.GetItem(num-1);
	cout << "\n\t<<�˻����>>\n";
	cout <<num<<" : "<< display.GetAbrv() << " : " << display.GetName() << endl;
}