#ifndef _SESSIONTYPE_H
#define _SESSIONTYPE_H

#include <string>
#include "ArrayList.h"
#include "paperType.h"
using namespace std;

/**
*	���� �̸�, �� ����Ʈ�� �⺭ ������ ������ �ִ� Ŭ����Ÿ��
*	@author ���Ѻ�
*	@date   2018-04-06
*/
class sessionType {
private:
	string sessionName;
	ArrayList<paperType> paperList;
};

#endif 


