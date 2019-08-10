/*
 * main.cpp
 *
 *  Created on: Mar 22, 2019
 *      Author: huy
 */

#include"function.h"

int main(){
	char tmp[100];
	cin>>tmp;
	char *s=new char[strlen(tmp)];
	int len=strlen(tmp);
	for (int i=0;i<len;++i)
		s[i]=tmp[i];
	cout<<isPalindrome(0,len-1,s);
	delete[] s;
}

