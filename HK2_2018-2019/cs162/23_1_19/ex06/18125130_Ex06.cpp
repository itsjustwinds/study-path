/*
 * 18125130_Ex06.cpp
 *
 *  Created on: Jan 24, 2019
 *      Author: huy
 */

#include"Book.h"

int main(){
	book a[100];
	int n;
	int responding=load_data("/home/huy/Documents/HK2 2018-2019/cs162/23_1_19/ex06/input.txt",a,n);
	if (!responding){
		cout<<"can not read file\n";
		return 0;
	}
	ll res=get_res(a,n);
	int ans=save_data("/home/huy/Documents/HK2 2018-2019/cs162/23_1_19/ex06/res.txt",res);
	if (ans) cout<<"get res and save successully\n";
	delete_pointer(a,n);
	return 0;
}


