#include "sessionType.h"

bool sessionType::operator>(sessionType item) {
	return (this->GetsessionName()>item.GetsessionName());
}

bool sessionType::operator==(sessionType item) {
	return (this->GetsessionName() == item.GetsessionName());
}