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
		case 5:		// ��� �м���ȸ�� �� �߿��� Ű���尡 ���Ե� �����
			RetrievePaperByName();
			break;
		case 6:		// �ش��ϴ� �м���ȸ ã�� ���� �߰�
			RunSession();
			break;
			break;
		case 7:		// �м���ȸ ���ڸ� ȭ�鿡 ����ϰ�, Ư�� �м���ȸ ��ȣ�� �Է�. �Էµ� �м���ȸ�� ��� ���� ���
			GetConferenceInfo();
			break;
		case 8:		// ��� �м���ȸ�� ����(���� ����)�� ȭ�� ���.
			DisplayAllConferences();
			break;
		case 9:		// ���Ͽ��� ����Ʈ ������ �о����
			ReadDataFromFile();
			break;
		case 10:		// ����Ʈ ������ ���Ͽ� �����ϱ�
			WriteDataToFile();
			break;
		case 0:     // ���α׷� ����
			exit(0);
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// ���α׷� ����̹�
void Application::RunSession()
{
	ConferenceType dummy;
	cout << "\tSession�� �߰��� �м���ȸ���� ��Ȯ�� �Է����ּ���\n";
	dummy.SetNameFromKB();

	ConferenceType* item = m_List.Get2(dummy);				// �߰��� �м���ȸ�� ����. (item���� ����Ű�� ��)
	if (item == NULL) {
		return;
	}

	while (1)
	{
		m_Commands = GetCommandSession();

		switch (m_Commands)
		{
		case 1:		// ���ڵ带 ����Ʈ�� �߰�
			AddSession(item);
			break;
		case 2:		// ����Ʈ���� �ش� ���ڵ� ����
			DeleteSession(item);
			break;
		case 3:		// ����Ʈ���� �ش� ������ ����
			ReplaceSession(item);
			break;
		case 4:		// �м���ȸ�� ���� �̸����� �˻��Ͽ� ȭ�� ���
			RetrieveBySessionName(item);
			break;
		case 5:		// ��� �м���ȸ�� �� �߿��� Ű���尡 ���Ե� �����
			RunPaper(item);
			break;
		case 0:     // ���α׷� ����
			Run();
			break;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// ���α׷� ����̹�
void Application::RunPaper(ConferenceType* item)
{
	cout << "\tPaper�� �߰��� Session �̸��� ��Ȯ�� �Է����ּ���\n";
	sessionType dummys;
	dummys.SetSessionNameFromKB();
	sessionType* items = item->GetsessionList()->Get2(dummys);
	if (items == NULL) {
		return;
	}

	while (1)
	{
		m_Commandp = GetCommandPaper();

		switch (m_Commandp)
		{
		case 1:		// ���ڵ带 ����Ʈ�� �߰�
					AddPaper(items);
			break;
		case 2:		// ����Ʈ���� �ش� ���ڵ� ����
					DeletePaper(items);
			break;
		case 3:		// ����Ʈ���� �ش� ������ ����
					ReplacePaper(items);
			break;
		case 4:		// �м���ȸ�� ���� �̸����� �˻��Ͽ� ȭ�� ���
					RetrieveByPaperName(items);
			break;
		case 0:     // ���α׷� ����
			Run();
			break;
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
	cout << "\t   5 : Search Paper by Name" << endl;
	cout << "\t   6 : Manage Session" << endl;
	cout << "\t   7 : Get Conference Info" << endl;
	cout << "\t   8 : Display Conference summary" << endl;
	cout << "\t   9 : Get from file" << endl; 
	cout << "\t   10 : Put to file " << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// ȭ�鿡 Ŀ�ǵ� ���� Ű����� �Է¹���
int Application::GetCommandSession()
{
	
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add session" << endl;
	cout << "\t   2 : Delete session" << endl;
	cout << "\t   3 : Replace session" << endl;
	cout << "\t   4 : Search by name" << endl;
	cout << "\t   5 : Manage paper" << endl;
	cout << "\t   0 : Go Back to Conference Manage" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// ȭ�鿡 Ŀ�ǵ� ���� Ű����� �Է¹���
int Application::GetCommandPaper()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add paper" << endl;
	cout << "\t   2 : Delete paper" << endl;
	cout << "\t   3 : Replace paper" << endl;
	cout << "\t   4 : Search by name" << endl;
	cout << "\t   0 : Go Back to Conference Manage" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// ���ο� ���ڵ带 ����Ʈ�� �߰�
int Application::AddConference()
{ 

	ConferenceType item;

	item.SetRecordFromKB();
	m_List.Add(item);
	// ���� list ���

	cout << endl << "\t<<���� ����Ʈ ��Ȳ>>" << endl;
	DisplayAllConferences();

	return 1;
}

// ���ο� ���ڵ带 ����Ʈ�� �߰�
int Application::AddSession(ConferenceType* item)
{

	sessionType sess;				
	sess.SetSessionNameFromKB();
	ArrayList<sessionType> *session = item->GetsessionList();
	session->Add(sess); // �ش� �м���ȸ�� �� session add
	
	cout << endl << "\t<<"<<item->GetName()<<"�� ���� ��Ȳ>>" << endl;
	DisplayAllSessions(item);

	return 1;
}

int Application::AddPaper(sessionType* items)
{
	paperType pp;
	pp.SetPaperFromKB();
	ArrayList<paperType> *paper = items->GetpaperList();
	paper->Add(pp);

	cout << endl << "\t<<����" << items->GetsessionName() << "�� �� ��Ȳ>>" << endl;
	DisplayAllPapers(items);
	return 1;
}

// �ش� �м���ȸ�� ���� ����Ʈ ��� ���
void Application::DisplayAllConferences()
{
	ConferenceType data;

	cout << "\n\tCurrent list" << endl;

	m_List.ResetList();	// ����Ʈ �ʱ�ȭ
						// list�� ��� �����͸� ȭ�鿡 ���
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
		cout << "\n\t\t|\n\n";
	}
}

// �ش� �м���ȸ�� ��� ���ǵ� ȭ�� ���
void Application::DisplayAllSessions(ConferenceType* targetconf)
{
	sessionType data;
	targetconf->GetsessionList()->ResetList();	// ����Ʈ �ʱ�ȭ
	// list�� ��� �����͸� ȭ�鿡 ���
	//cout << targetconf.GetsessionList()->GetLength();
	for (int i = 0; i < targetconf->GetsessionList()->GetLength(); i++)
	{
		targetconf->GetsessionList()->GetNextItem(data);
		data.DisplaySessionNameOnScreen();
		cout << "\n\t\t|\n\n";
	}
}

// �ش� ������ ��� ���� ȭ�� ���
void Application::DisplayAllPapers(sessionType* targetsess)
{
	paperType data;
	targetsess->GetpaperList()->ResetList();	// ����Ʈ �ʱ�ȭ
												// list�� ��� �����͸� ȭ�鿡 ���
												//cout << targetconf.GetsessionList()->GetLength();
	for (int i = 0; i < targetsess->GetpaperList()->GetLength(); i++)
	{
		targetsess->GetpaperList()->GetNextItem(data);
		data.DisplayPaperRecordOnScreen();
		cout << "\n\t\t|\n\n";
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
	if (!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ���̸� ���Ϲ޾� ����
	int length = m_List.GetLength();

	// iteration�� �̿��Ͽ� ��� item ���
	for (int i = 0; i<length; i++)
	{
		m_List.GetNextItem(data);
		data.WriteDataToFile(m_OutFile);
		if (i != length - 1)
			m_OutFile << endl;
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

//������ ����Ʈ���� ����
int Application::DeleteSession(ConferenceType* item) {

	sessionType sess;	// ������ ������ �̸��� ���� object
	cout << "\t   �����ϰ� ���� �̸��� �Է��ϼ���" << endl;
	sess.SetSessionNameFromKB();
	ArrayList<sessionType> *session = item->GetsessionList();
	session->Delete(sess);

	cout << endl << "\t<<" << item->GetName() << "�� ���� ��Ȳ>>" << endl;
	DisplayAllSessions(item);

	return 1;
}

//���� ����Ʈ���� ����
int Application::DeletePaper(sessionType* items) {

	paperType pp;	// ������ ���� �̸��� ���� object
	cout << "\t   �����ϰ� ���� �̸��� �Է��ϼ���" << endl;
	pp.SetpaperTitleFromKB();
	ArrayList<paperType> *paper = items->GetpaperList();
	paper->Delete(pp);

	cout << endl << "\t<<" << items->GetsessionName() << "�� �� ��Ȳ>>" << endl;
	DisplayAllPapers(items);

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
	item.SetPlaceFromKB();
	item.SetOpenDateFromKB();
	item.SetISBNFromKB();
	m_List.Replace(item);
	
	cout << endl << "\t<<���� ����Ʈ ��Ȳ>>" << endl;
	DisplayAllConferences();

	return 1;
}

//session�� ����Ʈ���� ����
int Application::ReplaceSession(ConferenceType* item) {

	sessionType items;
	cout << "\t�����ϰ� ���� session �̸��� �Է��ϼ���" << endl;
	items.SetSessionNameFromKB(); // ��� �ٲ� ���ΰ�
	sessionType* wheretoReplace = item->GetsessionList()->Get2(items); // �ٲٴ� ���� ��ġ����Ű��
	cout << "\t������ session �̸��� �Է��ϼ���" << endl;
	sessionType whattoReplace;   // �������� �ٲ� ���ΰ�
	whattoReplace.SetSessionNameFromKB();
	
	wheretoReplace->SetsessionName(whattoReplace.GetsessionName());

	//item->GetsessionList()->Replace(items); 

	cout << endl << "\t<<" << item->GetName() << "�� ���� ��Ȳ>>" << endl;
	DisplayAllSessions(item);

	return 1;
}

//session�� ����Ʈ���� ����
int Application::ReplacePaper(sessionType* item) {

	paperType itemp;
	cout << "\t�����ϰ� ���� �� �̸��� �Է��ϼ���" << endl;
	itemp.SetpaperTitleFromKB(); // ��� �ٲ� ���ΰ�
	itemp.SetauthorFromKB();     // ������ ���� ����
	itemp.SetpageNumFromKB();
	
	item->GetpaperList()->Replace(itemp);			//�����ϱ�
	
	cout << endl << "\t<<" << item->GetsessionName() << "�� �� ��Ȳ>>" << endl;
	DisplayAllPapers(item);

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
	
	m_List.GetByPrimaryKey(item);
	
	return 1;
}

//�м���ȸ�� �м���ȸ �̸����� �˻��Ͽ� ȭ�� ���
int Application::RetrieveBySessionName(ConferenceType* item) {


	sessionType sess;
	cout << "\t�˻��ϰ� ���� Session Name�� �Է��ϼ���" << endl;
	sess.SetSessionNameFromKB();
	item->GetsessionList()->GetByPrimaryKey(sess);

	return 1;
}

//�м���ȸ�� �м���ȸ �̸����� �˻��Ͽ� ȭ�� ���
int Application::RetrieveByPaperName(sessionType* item) {


	paperType pp;
	cout << "\t�˻��ϰ� ���� �� �̸��� �Է��ϼ���" << endl;
	pp.SetpaperTitleFromKB();
	item->GetpaperList()->GetByPrimaryKey(pp);

	return 1;
}

/*
// ���ο� ���ڵ带 ����Ʈ�� �߰�
int Application::AddSession(ConferenceType* item)
{

	sessionType sess;
	sess.SetSessionNameFromKB();
	ArrayList<sessionType> *session = item->GetsessionList();
	session->Add(sess); // �ش� �м���ȸ�� �� session add

	cout << endl << "\t<<" << item->GetName() << "�� ���� ��Ȳ>>" << endl;
	DisplayAllSessions(item);

	return 1;
}
*/
//�м���ȸ ������ ���� �� Ű���尡 ���Ե� �� ���
int Application::RetrievePaperByName() {
	if (m_List.IsEmpty()) {
		cout << "\t   List is Empty" << endl;
		return 0;
	}

	paperType item;	
	cout << "\t�˻��ϰ� ���� �� �̸��� �Է��ϼ���" << endl;
	item.SetpaperTitleFromKB();
	ConferenceType dummy;
	m_List.ResetList();
	sessionType dummys;

	for (int i = 0; i < m_List.GetLength(); i++) {
		if(i==0)  m_List.GetNextItem(dummy);
		dummy.GetsessionList()->ResetList();
		for (int j = 0; j < dummy.GetsessionList()->GetLength(); j++)
		{
			if (j == 0) dummy.GetsessionList()->GetNextItem(dummys); 
			dummy.GetsessionList()->Get2(dummys)->GetpaperList()->GetByPrimaryKey(item);
			if ((j != dummy.GetsessionList()->GetLength() - 1) && j!=0) dummy.GetsessionList()->GetNextItem(dummys);
		}
		if ((i != m_List.GetLength() - 1)&&i!=0) { m_List.GetNextItem(dummy); }
	}
	//paperList.GetByPrimaryKeyS(item);

	return 1;
}

// �м���ȸ ��������� ȭ�鿡 ����ϰ�, Ư�� �м���ȸ ��ȣ�� �Է� �޾� �ڼ��� ���� ���
void Application::GetConferenceInfo() {
	ConferenceType data;

	cout << "\n\tCurrent list" << endl;

	// �м���ȸ ������� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		cout << i + 1 << " : ";
		data.DisplayAbbrevationOnScreen();
	}

	int num;
	cout << "\t�˻��� index �Է� : ";
	cin >> num;
	m_List.ResetList();
	ConferenceType display;
	for (int i = 0; i < num; i++) {
		m_List.GetNextItem(display);
	}
	cout << "\n\t<<�˻����>>\n";
	cout <<num<<" : "<< display.GetAbrv() << " : " << display.GetName() << endl;
}