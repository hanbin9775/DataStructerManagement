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
		case 5:		// 학술대회 요약정보를 화면에 출력하고, 특정 학술대회 번호를 입력받아 제사한 정보 출력
			GetConferenceInfo();
			break;
		case 6:		// 모든 학술대회의 요약된 정보를 화면 출력
			DisplayAllConferences();
			break;
		case 7:		// 파일에서 리스트 데이터 읽어오기
			ReadDataFromFile();
			break;
		case 8:		// 리스트 데이터 파일에 저장하기
			WriteDataToFile();
			break;
		case 0:     // 프로그램 종료
			return;
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


// 새로운 레코드를 리스트에 추가
int Application::AddConference()
{
	// 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if(m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ConferenceType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	// 현재 list 출력

	cout << endl << "\t<<현재 리스트 현황>>" << endl;
	DisplayAllConferences();

	return 1;
}


// 모든 학술대회의 요약돈 정보를 화면 출력
void Application::DisplayAllConferences()
{
	ConferenceType data;

	cout << "\n\tCurrent list" << endl << endl;

	// list의 모든 데이터를 화면에 출력
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
	if(!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
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
	m_List.Replace(item);
	
	cout << endl << "\t<<현재 리스트 현황>>" << endl;
	DisplayAllConferences();

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
	
	m_List.GetByName(item);
	
	return 1;
	/*}
	else
		return 0;*/
}

// 학술대회 요약정보를 화면에 출력하고, 특정 학술대회 번호를 입력 받아 자세한 정보 출력
void Application::GetConferenceInfo() {
	ConferenceType data;

	cout << "\n\tCurrent list" << endl;

	// 학술대회 요약정보 화면에 출력
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
	cout << "\t검색할 index 입력 : ";
	cin >> num;
	ConferenceType display = m_List.GetItem(num-1);
	cout << "\n\t<<검색결과>>\n";
	cout <<num<<" : "<< display.GetAbrv() << " : " << display.GetName() << endl;
}