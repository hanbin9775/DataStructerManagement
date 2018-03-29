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

// 키보드로 학술대회 기록 설정
void ConferenceType::SetRecordFromKB()
{
	SetNameFromKB();
	SetDateFromKB();
	SetNumFromKB();
	SetOrganizationFromKB();
	SetAbbrevationFromKB();
}


// 파일에서 기록 읽어오기
int ConferenceType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_sName;
	fin >> m_sDate;
	fin >> m_Num;
	fin >> m_sOrg;
	fin >> m_sAbrv;

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