/*
 * main.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: huy
 */

#include"addOne.h"
int main(){
	int *a;
	a=new int;
	*a=100;
	cout<<*a<<" ";
	addOne(a);
	cout<<*a;
	delete a;
	return 0;
}

