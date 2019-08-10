/*
 * function.cpp
 *
 *  Created on: Mar 22, 2019
 *      Author: huy
 */

#include"function.h"
bool isPalindrome(int l, int r, char* s){
	if (l>=r) return 1;
	return (s[l]==s[r]&&isPalindrome(l+1,r-1,s));
}
