/*
#include "ArrayList.h"
#include <string>

//������
template <typename T>
ArrayList<T>::ArrayList()
{
	m_Array = new T[MAXSIZE];
	m_Length = 0;
	ResetList();
}

//�Ҹ���
template <typename T>
ArrayList<T>::~ArrayList()
{
	delete[] m_Array;
}

// ����Ʈ ����
template <typename T>
void ArrayList<T>::MakeEmpty()
{
	m_Length = 0;
}


// ���� ����Ʈ�� �ִ� ���ڵ� ���� ��������
template <typename T>
int ArrayList<T>::GetLength()
{
	return m_Length;
}


// ����Ʈ �� á���� Ȯ��
template <typename T>
bool ArrayList<T>::IsFull()
{
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// ����Ʈ ������ִ��� Ȯ��
template <typename T>
bool ArrayList<T>::IsEmpty()
{
	if (m_Length == 0)
		return true;
	else
		return false;
}

// ���������� ���� ����Ʈ�� ���ο� ������ �߰�
template <typename T>
int ArrayList<T>::Add(T inData)
{
	if(!IsFull())
	{
		for(int i = 0; i<m_Length;i++){
			if (m_Array[i].CompareByName(inData) == EQUAL) {
				cout << "primary key�� �ߺ��� �� �����ϴ�";
				return 0;
			}
			if (m_Array[i].CompareByName(inData) == GREATER) {			// indata�� ���� ������ �� �տ� ���� ��
				for (int j = i; j < m_Length; j++) {
					m_Array[m_Length-j+i] = m_Array[m_Length-j+i-1];	// ���� �����͵��� ��ĭ�� �ڷ� �̷��
				}
				m_Array[i] = inData;
				m_Length++;
				return 1;
			}
		}
		m_Array[m_Length] = inData;		// indata�� ���� ������ ���� ����Ʈ���� ���� �� �϶�
		m_Length++;
		return 1;
	}
	else
	{ 
		cout << "\n\t	����Ʈ �� ��!" << endl;
		return 0;

	}
}


// ����Ʈ iterartor �ʱ�ȭ
template <typename T>
void ArrayList<T>::ResetList()
{
	m_CurPointer = -1;
}


// ����Ʈ iterator�� ���� ���������� �ű�� �� �������� �����´�
template <typename T>
int ArrayList<T>::GetNextItem(T& data)
{
	m_CurPointer++;	// list pointer ����
	if(m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

// �Ű������� data�� primary key ������ ����Ʈ�� �ִ� ���ڵ��� �� �� ��ġ�Ѵٸ� �� ���ڵ� data�� ����.
template <typename T>
int ArrayList<T>::Get(T& data) {
	if (m_Length == 0) { // ����Ʈ ������� -1 ����
		cout << "list �������" << endl; 
		return 0;
	}
	
	for (int i = 0; i < m_Length; i++) {
		if (m_Array[i].CompareByName(data)==EQUAL){
			data = m_Array[i]; // data�� �ش� ���ڵ� ����
			return 1; // ����
		}
	}
	cout << "�ش� ���ڵ� ����" << endl; // ���� ���� ������ 0 ��ȯ
	return 0;
}

// �Ű������� data�� primary key ������ ����Ʈ�� �ִ� ���ڵ��� �� �� ��ġ�Ѵٸ� �� ���ڵ� ����
template <typename T>
int ArrayList<T>::Delete(T data) {
	for (int i = 0; i < m_Length; i++) {
			if (m_Array[i].CompareByName(data)==EQUAL){

				// ������ ���� ���ڵ� �̵� �����ϴ� �ݺ���
				for (int j = i; j < m_Length; j++) {
					m_Array[j] = m_Array[j + 1];
				}
				m_Length--;
				
				return 1;
		}
	}
	cout << "�ش��ϴ� ���ڵ� ����" << endl;
	return 0;
}

// �Ű������� data�� primary key ������ ����Ʈ�� �ִ� ���ڵ��� �� �� ��ġ�Ѵٸ� �� ���ڵ� ���� data�� ������ ����
template <typename T>
int ArrayList<T>::Replace(T data) {
	for (int i = 0; i < MAXSIZE; i++) {
		if (m_Array[i].CompareByName(data)){
			m_Array[i] = data;
			return 1;
		}
	}
	cout << "�ش��ϴ� ���ڵ� ����" << endl;
	return 0;
}

// primary key(�̸�)�� �������� �����͸� �̺й����� �˻��ϰ� �ش� �����͸� ������
template <typename T>
int ArrayList<T>::GetByBinarySearch(T& data) {
	int first = 0;
	int last = m_Length-1;
	int mid = (first + last) / 2;
	while (m_Array[mid].CompareByName(data) != EQUAL) {					// ã�� ������ ����	
		
		if ((first == last) && (m_Array[mid].CompareByName(data) != EQUAL)) {	// �ش� ������ ����Ʈ�� ���� ��
			cout << "\t�ش� �̸� ����\n";
			return 0;
		}

		if (m_Array[mid].CompareByName(data) == LESS) {					// ���� ������ �ش� �����Ͱ� �ڿ� �ִٸ�
			first = mid+1;
			mid = (first + last) / 2;
		}
		else if (m_Array[mid].CompareByName(data) == GREATER) {			// ���� ������ �ش� �����Ͱ� �տ� �ִٸ�
			last = mid;
			mid = (first + last) / 2;
		}
		
	}
	data = m_Array[mid];
	return 1;
}

// primary key(�̸�)�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������. primary key�� ���Ե� �м���ȸ ������ ��� ������
template <typename T>
int ArrayList<T>::GetByName(T& data) {
	if (m_Length == 0) { // ����Ʈ ������� 0 ����
		cout << "list �������" << endl;
		return 0;
	}
	
	
	for (int i = 0; i < m_Length+1; i++) {
		string str(m_Array[i].GetName());
		if (string::npos!=str.find(data.GetName())){ // ���ڵ���� �̸��� primary key�� �ش��ϴ��� Ȯ��
			data = m_Array[i]; // data�� �ش� ���ڵ� ����
			data.DisplayRecordOnScreen(); // �ش� ���ڵ� ���
		}
		
	}
	return 1;
}

// �ش��ϴ� ����Ʈ index�� ������ ��ȯ
template <typename T>
T ArrayList<T>::GetItem(int num) {
	return m_Array[num];
}
*/