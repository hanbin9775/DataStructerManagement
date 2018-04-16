#include "Application.h"


// 프로그램 드라이버
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// 레코드를 리스트에 추가
			AddConference();
			break;
		case 2:		// 리스트에서 해당 레코드 삭제
			DeleteConference();
			break;
		case 3:		// 리스트에서 해당 아이템 갱신
			ReplaceConference();
			break;
		case 4:		// 학술대회를 학술대회 이름으로 검색하여 화면 출력
			RetrieveByName();
			break;
		case 5:		// 모든 학술대회의 논문 중에서 키워드가 포함된 논문출력
			RetrievePaperByName();
			break;
		case 6:		// 해당하는 학술대회 찾아 세션 추가
			RunSession();
			break;
			break;
		case 7:		// 학술대회 약자를 화면에 출력하고, 특정 학술대회 번호를 입력. 입력된 학술대회의 모든 정보 출력
			GetConferenceInfo();
			break;
		case 8:		// 모든 학술대회의 정보(약자 제외)를 화면 출력.
			DisplayAllConferences();
			break;
		case 9:		// 파일에서 리스트 데이터 읽어오기
			ReadDataFromFile();
			break;
		case 10:		// 리스트 데이터 파일에 저장하기
			WriteDataToFile();
			break;
		case 0:     // 프로그램 종료
			exit(0);
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// 프로그램 드라이버
void Application::RunSession()
{
	ConferenceType dummy;
	cout << "\tSession을 추가할 학술대회명을 정확히 입력해주세요\n";
	dummy.SetNameFromKB();

	ConferenceType* item = m_List.Get2(dummy);				// 추가할 학술대회로 접근. (item으로 가리키게 함)
	if (item == NULL) {
		return;
	}

	while (1)
	{
		m_Commands = GetCommandSession();

		switch (m_Commands)
		{
		case 1:		// 레코드를 리스트에 추가
			AddSession(item);
			break;
		case 2:		// 리스트에서 해당 레코드 삭제
			DeleteSession(item);
			break;
		case 3:		// 리스트에서 해당 아이템 갱신
			ReplaceSession(item);
			break;
		case 4:		// 학술대회의 세션 이름으로 검색하여 화면 출력
			RetrieveBySessionName(item);
			break;
		case 5:		// 모든 학술대회의 논문 중에서 키워드가 포함된 논문출력
			RunPaper(item);
			break;
		case 0:     // 프로그램 종료
			Run();
			break;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// 프로그램 드라이버
void Application::RunPaper(ConferenceType* item)
{
	cout << "\tPaper를 추가할 Session 이름을 정확히 입력해주세요\n";
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
		case 1:		// 레코드를 리스트에 추가
					AddPaper(items);
			break;
		case 2:		// 리스트에서 해당 레코드 삭제
					DeletePaper(items);
			break;
		case 3:		// 리스트에서 해당 아이템 갱신
					ReplacePaper(items);
			break;
		case 4:		// 학술대회의 세션 이름으로 검색하여 화면 출력
					RetrieveByPaperName(items);
			break;
		case 0:     // 프로그램 종료
			Run();
			break;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// 화면에 커맨드 띄우고 키보드로 입력받음
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

// 화면에 커맨드 띄우고 키보드로 입력받음
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

// 화면에 커맨드 띄우고 키보드로 입력받음
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


// 새로운 레코드를 리스트에 추가
int Application::AddConference()
{ 

	ConferenceType item;

	item.SetRecordFromKB();
	m_List.Add(item);
	// 현재 list 출력

	cout << endl << "\t<<현재 리스트 현황>>" << endl;
	DisplayAllConferences();

	return 1;
}

// 새로운 레코드를 리스트에 추가
int Application::AddSession(ConferenceType* item)
{

	sessionType sess;				
	sess.SetSessionNameFromKB();
	ArrayList<sessionType> *session = item->GetsessionList();
	session->Add(sess); // 해당 학술대회에 들어가 session add
	
	cout << endl << "\t<<"<<item->GetName()<<"의 세션 현황>>" << endl;
	DisplayAllSessions(item);

	return 1;
}

int Application::AddPaper(sessionType* items)
{
	paperType pp;
	pp.SetPaperFromKB();
	ArrayList<paperType> *paper = items->GetpaperList();
	paper->Add(pp);

	cout << endl << "\t<<세션" << items->GetsessionName() << "의 논문 현황>>" << endl;
	DisplayAllPapers(items);
	return 1;
}

// 해당 학술대회의 세션 리스트 모두 출력
void Application::DisplayAllConferences()
{
	ConferenceType data;

	cout << "\n\tCurrent list" << endl;

	m_List.ResetList();	// 리스트 초기화
						// list의 모든 데이터를 화면에 출력
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
		cout << "\n\t\t|\n\n";
	}
}

// 해당 학술대회의 모든 세션들 화면 출력
void Application::DisplayAllSessions(ConferenceType* targetconf)
{
	sessionType data;
	targetconf->GetsessionList()->ResetList();	// 리스트 초기화
	// list의 모든 데이터를 화면에 출력
	//cout << targetconf.GetsessionList()->GetLength();
	for (int i = 0; i < targetconf->GetsessionList()->GetLength(); i++)
	{
		targetconf->GetsessionList()->GetNextItem(data);
		data.DisplaySessionNameOnScreen();
		cout << "\n\t\t|\n\n";
	}
}

// 해당 세션의 모든 논문들 화면 출력
void Application::DisplayAllPapers(sessionType* targetsess)
{
	paperType data;
	targetsess->GetpaperList()->ResetList();	// 리스트 초기화
												// list의 모든 데이터를 화면에 출력
												//cout << targetconf.GetsessionList()->GetLength();
	for (int i = 0; i < targetsess->GetpaperList()->GetLength(); i++)
	{
		targetsess->GetpaperList()->GetNextItem(data);
		data.DisplayPaperRecordOnScreen();
		cout << "\n\t\t|\n\n";
	}
}

// 파일 디스크립터를 통해 입력파일로 파일 열기
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// 입력을 위한 파일 오픈
	
	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_InFile)	return 0;
	else	return 1;
}


// 출력 파일으로 파일 descriptor 열기
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// 출력을 위한 파일 오픈.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// 읽기 모드로 파일 열고, 파일에있는 모든 데이터 읽어들임.
int Application::ReadDataFromFile()
{
	int index = 0;
	ConferenceType data;	// 읽기용 임시 변수
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if(!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while(!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAllConferences();

	return 1;
}


// 쓰기 모드로 파일열고, 파일에 모든 데이터 쓰기
int Application::WriteDataToFile()
{
	ConferenceType data;	// 쓰기용 임시 변수
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 길이를 리턴받아 저장
	int length = m_List.GetLength();

	// iteration을 이용하여 모든 item 출력
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

//학술대회를 리스트에서 삭제
int Application::DeleteConference() {
	if (m_List.IsEmpty()) {
		cout << "\t   List is Empty" << endl;
		return 0;
	}

	ConferenceType item;

	cout << "\t   삭제하고 싶은 이름을 입력하세요" << endl;
	item.SetNameFromKB();
	m_List.Delete(item);

	cout << endl << "\t<<현재 리스트 현황>>" << endl;
	DisplayAllConferences();

	return 1;
}

//세션을 리스트에서 삭제
int Application::DeleteSession(ConferenceType* item) {

	sessionType sess;	// 삭제할 세션의 이름을 담을 object
	cout << "\t   삭제하고 싶은 이름을 입력하세요" << endl;
	sess.SetSessionNameFromKB();
	ArrayList<sessionType> *session = item->GetsessionList();
	session->Delete(sess);

	cout << endl << "\t<<" << item->GetName() << "의 세션 현황>>" << endl;
	DisplayAllSessions(item);

	return 1;
}

//논문을 리스트에서 삭제
int Application::DeletePaper(sessionType* items) {

	paperType pp;	// 삭제할 논문의 이름을 담을 object
	cout << "\t   삭제하고 싶은 이름을 입력하세요" << endl;
	pp.SetpaperTitleFromKB();
	ArrayList<paperType> *paper = items->GetpaperList();
	paper->Delete(pp);

	cout << endl << "\t<<" << items->GetsessionName() << "의 논문 현황>>" << endl;
	DisplayAllPapers(items);

	return 1;
}

//학술대회를 리스트에서 갱신
int Application::ReplaceConference() {
	if (m_List.IsEmpty()) {
		cout << "\t   List is Empty" << endl;
		return 0;
	}

	ConferenceType item;
	cout << "\t갱신하고 싶은 이름을 입력하세요" << endl;
	item.SetNameFromKB();
	cout << "\t갱신할 날짜,개최 횟수,개최 기관을 입력하세요" << endl;
	item.SetDateFromKB();
	item.SetNumFromKB();
	item.SetOrganizationFromKB();
	item.SetPlaceFromKB();
	item.SetOpenDateFromKB();
	item.SetISBNFromKB();
	m_List.Replace(item);
	
	cout << endl << "\t<<현재 리스트 현황>>" << endl;
	DisplayAllConferences();

	return 1;
}

//session을 리스트에서 갱신
int Application::ReplaceSession(ConferenceType* item) {

	sessionType items;
	cout << "\t갱신하고 싶은 session 이름을 입력하세요" << endl;
	items.SetSessionNameFromKB(); // 어딜 바꿀 것인가
	sessionType* wheretoReplace = item->GetsessionList()->Get2(items); // 바꾸는 곳의 위치가리키기
	cout << "\t갱신할 session 이름을 입력하세요" << endl;
	sessionType whattoReplace;   // 무엇으로 바꿀 것인가
	whattoReplace.SetSessionNameFromKB();
	
	wheretoReplace->SetsessionName(whattoReplace.GetsessionName());

	//item->GetsessionList()->Replace(items); 

	cout << endl << "\t<<" << item->GetName() << "의 세션 현황>>" << endl;
	DisplayAllSessions(item);

	return 1;
}

//session을 리스트에서 갱신
int Application::ReplacePaper(sessionType* item) {

	paperType itemp;
	cout << "\t갱신하고 싶은 논문 이름을 입력하세요" << endl;
	itemp.SetpaperTitleFromKB(); // 어딜 바꿀 것인가
	itemp.SetauthorFromKB();     // 갱신할 하위 값들
	itemp.SetpageNumFromKB();
	
	item->GetpaperList()->Replace(itemp);			//갱신하기
	
	cout << endl << "\t<<" << item->GetsessionName() << "의 논문 현황>>" << endl;
	DisplayAllPapers(item);

	return 1;
}

//학술대회를 학술대회 이름으로 검색하여 화면 출력
int Application::RetrieveByName() {
	if (m_List.IsEmpty()) {
		cout << "\t   List is Empty" << endl;
		return 0;
	}

	ConferenceType item;
	cout << "\t검색하고 싶은 Name을 입력하세요" << endl;
	item.SetNameFromKB();
	
	m_List.GetByPrimaryKey(item);
	
	return 1;
}

//학술대회를 학술대회 이름으로 검색하여 화면 출력
int Application::RetrieveBySessionName(ConferenceType* item) {


	sessionType sess;
	cout << "\t검색하고 싶은 Session Name을 입력하세요" << endl;
	sess.SetSessionNameFromKB();
	item->GetsessionList()->GetByPrimaryKey(sess);

	return 1;
}

//학술대회를 학술대회 이름으로 검색하여 화면 출력
int Application::RetrieveByPaperName(sessionType* item) {


	paperType pp;
	cout << "\t검색하고 싶은 논문 이름을 입력하세요" << endl;
	pp.SetpaperTitleFromKB();
	item->GetpaperList()->GetByPrimaryKey(pp);

	return 1;
}

/*
// 새로운 레코드를 리스트에 추가
int Application::AddSession(ConferenceType* item)
{

	sessionType sess;
	sess.SetSessionNameFromKB();
	ArrayList<sessionType> *session = item->GetsessionList();
	session->Add(sess); // 해당 학술대회에 들어가 session add

	cout << endl << "\t<<" << item->GetName() << "의 세션 현황>>" << endl;
	DisplayAllSessions(item);

	return 1;
}
*/
//학술대회 세션의 눈문 중 키워드가 포함된 논문 출력
int Application::RetrievePaperByName() {
	if (m_List.IsEmpty()) {
		cout << "\t   List is Empty" << endl;
		return 0;
	}

	paperType item;	
	cout << "\t검색하고 싶은 논문 이름을 입력하세요" << endl;
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

// 학술대회 요약정보를 화면에 출력하고, 특정 학술대회 번호를 입력 받아 자세한 정보 출력
void Application::GetConferenceInfo() {
	ConferenceType data;

	cout << "\n\tCurrent list" << endl;

	// 학술대회 요약정보 화면에 출력
	m_List.ResetList();
	int length = m_List.GetLength();

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		cout << i + 1 << " : ";
		data.DisplayAbbrevationOnScreen();
	}

	int num;
	cout << "\t검색할 index 입력 : ";
	cin >> num;
	m_List.ResetList();
	ConferenceType display;
	for (int i = 0; i < num; i++) {
		m_List.GetNextItem(display);
	}
	cout << "\n\t<<검색결과>>\n";
	cout <<num<<" : "<< display.GetAbrv() << " : " << display.GetName() << endl;
}