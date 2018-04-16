#include "ConferenceType.h"


// Ű����� �м���ȸ �� ����
void ConferenceType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}


// Ű����� ���۳���� ����
void ConferenceType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> m_sDate;
}


// Ű����� ���� Ƚ�� ����
void ConferenceType::SetNumFromKB()
{
	cout << "\tNumber of times : ";
	cin >> m_Num;
}


// Ű����� ���� ��� ����
void ConferenceType::SetOrganizationFromKB()
{
	cout << "\tOrganization : ";
	cin >> m_sOrg;
}

// Ű����� �м���ȸ�� ���� ����
void ConferenceType::SetAbbrevationFromKB()
{
	cout << "\tAbbrevation : ";
	cin >> m_sAbrv;
}

// Ű����� ���� ��� ����
void ConferenceType::SetPlaceFromKB()
{
	cout << "\tPlace : ";
	cin >> m_sPlace;
}

// Ű����� �м���ȸ ���� �Ͻ� ����
void ConferenceType::SetOpenDateFromKB()
{
	cout << "\tOpen date : ";
	cin >> m_OpenDate;
}

// Ű����� ISBN ����
void ConferenceType::SetISBNFromKB()
{
	cout << "\tISBN : ";
	cin >> m_sISBN;
}

// Ű����� �м���ȸ ��� ����
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


// ���Ͽ��� ��� �о����
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


// ���Ͽ� ���
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


// �� ������ Ÿ�� ��
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
*	@brief	'<'�� �������Ѵ�.
*	@pre	���� '<'���� ���� �Ǿ��ִ�.
*	@post	'<' ������ �� ������ ����� �� �ִ�.
*	@return	�ش� ���̽��� TRUE, �׷��� ������ FALSE.
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