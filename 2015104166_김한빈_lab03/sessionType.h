#ifndef _SESSIONTYPE_H
#define _SESSIONTYPE_H

#include <string>
#include "ArrayList.h"
#include "paperType.h"
using namespace std;

/**
*	세션 이름, 논문 리스트를 멤벼 변수로 가지고 있는 클래스타입
*	@author 김한빈
*	@date   2018-04-06
*/
class sessionType {
private:
	string sessionName;
	ArrayList<paperType> paperList;
};

#endif 


