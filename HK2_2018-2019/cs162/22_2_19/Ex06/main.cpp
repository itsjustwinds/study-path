/*
 * main.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: huy
 */
#include"function.h"

int main(){
	char s1[50] = "neveroddoreven";
	char s2[50] = "not a palindrome";
	cout << isPalindrome(s1) << endl; // true
	cout << isPalindrome(s2) << endl; // false
	return 0;
}


