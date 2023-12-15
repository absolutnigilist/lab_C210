#pragma once
#include <iostream>
struct StringComparator {
	bool operator()(const char* a, const char* b) {
	
	return std::strcmp(a,b)>0;
	}
};