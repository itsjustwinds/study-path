/*
 * function.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: huy
 */

#include"function.h"

bool isPalindrome(char *cstr){
	char* front = cstr;
	char* back = cstr + strlen(cstr)-1;
	while(front<back){
		if (*front != *back) return false;
		front++;
		back--;
	}
	return true;
}

