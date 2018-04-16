#include "ConferenceType.h"


// 키보드로 학술대회 명 설정
void ConferenceType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}


// 키보드로 시작년월일 설정
void ConferenceType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> m_sDate;
}


// 키보드로 개최 횟수 설정
void ConferenceType::SetNumFromKB()
{
	cout << "\tNumber of times : ";
	cin >> m_Num;
}


// 키보드로 개최 기관 설정
void ConferenceType::SetOrganizationFromKB()
{
	cout << "\tOrganization : ";
	cin >> m_sOrg;
}

// 키보드로 학술대회명 약자 설정
void ConferenceType::SetAbbrevationFromKB()
{
	cout << "\tAbbrevation : ";
	cin >> m_sAbrv;
}

// 키보드로 개최 장소 설정
void ConferenceType::SetPlaceFromKB()
{
	cout << "\tPlace : ";
	cin >> m_sPlace;
}

// 키보드로 학술대회 개최 일시 설정
void ConferenceType::SetOpenDateFromKB()
{
	cout << "\tOpen date : ";
	cin >> m_OpenDate;
}

// 키보드로 ISBN 설정
void ConferenceType::SetISBNFromKB()
{
	cout << "\tISBN : ";
	cin >> m_sISBN;
}

// 키보드로 학술대회 기록 설정
void ConferenceType::SetRecordFromKB()
{
	SetNameFromKB();
	SetDateFromKB();
	SetNumFromKB();
	SetOrganizationFromKB();
	SetAbbrevationFromKB();
	SetPlaceFromKB();
	SetOpenDateFromKB();
	SetISBNFromKB();
}


// 파일에서 기록 읽어오기
int ConferenceType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_sName;
	fin >> m_sDate;
	fin >> m_Num;
	fin >> m_sOrg;
	fin >> m_sAbrv;
	fin >> m_sPlace;
	fin >> m_OpenDate;
	fin >> m_sISBN;
	return 1;
};


// 파일에 기록
int ConferenceType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_sName << " ";
	fout << m_sDate << " ";
	fout << m_Num << " ";
	fout << m_sOrg << " ";
	fout << m_sAbrv;
	fout << m_sPlace;
	fout << m_OpenDate;
	fout << m_sISBN;
	return 1;
}


// 두 아이템 타입 비교
RelationType ConferenceType::CompareByName(const ConferenceType &data)
{
	if(this->m_sName.compare(data.m_sName)==1)
		return GREATER;
	else if(this->m_sName.compare(data.m_sName)==-1)
		return LESS;
	else
		return EQUAL;
}

/**
*	@brief	'<'를 재정의한다.
*	@pre	기존 '<'으로 정의 되어있다.
*	@post	'<' 재정의 된 것으로 사용할 수 있다.
*	@return	해당 케이스면 TRUE, 그렇지 않으면 FALSE.
*/
bool ConferenceType::operator < (ConferenceType &item)
{
	if (this->GetName() < item.m_sName)
		return true;
	else
		return false;
}


// Compare two item types by item id.
bool ConferenceType::operator > (ConferenceType &data)
{
	if (this->GetName() > data.m_sName)
		return true;
	else
		return false;
}

	// Compare two item types by item id.
bool ConferenceType::operator==(ConferenceType &item)
{

	if (this->GetName() == item.m_sName || this->GetName() == item.m_sName)
	{
		return true;
	}
	else
		return false;
}	//return 1 if this.id == data.id, 0 if not.

string ConferenceType::operator+() 
{
	return this->GetName();
}

void ConferenceType::operator-() 
{
	this->DisplayRecordOnScreen();
	return;
}