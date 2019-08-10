/*
 * 18125130_ex05.cpp
 *
 *  Created on: Jan 24, 2019
 *      Author: huy
 */

#include"Date.h"
using namespace std;
int main(){
	date a[100];
	int n;
	int responding=load_data("/home/huy/Documents/HK2 2018-2019/cs162/23_1_19/ex05/input.txt",a,n);
	if (responding==0){
		cout<<"Oops, can not load file";
		return 0;
	}
	sort(a,n);
	int ans=save_data("/home/huy/Documents/HK2 2018-2019/cs162/23_1_19/ex05/res.txt",a,n);
	if (ans)
		cout<<"find answer and save successully\n";
	return 0;
}


