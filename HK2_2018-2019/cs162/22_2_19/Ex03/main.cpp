/*
 * main.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: huy
 */

#include"function.h"
int main(){
	int n;
	int *a;
	input(n,a);
	cout<<greatest_frequency(n,a);
	delete[] a;
}
