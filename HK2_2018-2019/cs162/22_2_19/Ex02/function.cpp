/*
 * function.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: huy
 */

#include"function.h"
int dosomething(int *a,int *b){
	int temp=*a;
	*a=*b *10;
	*b=temp*10;
	return *a + *b;
}


