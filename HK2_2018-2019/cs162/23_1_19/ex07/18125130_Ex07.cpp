/*
 * 18125130_Ex07.cpp
 *
 *  Created on: Jan 24, 2019
 *      Author: huy
 */

#include"Student.h"

int main(){
	student a[100];
	int n;
	int responding=load_data("/home/huy/Documents/HK2 2018-2019/cs162/23_1_19/ex07/input.txt",a,n);
	if (!responding){
		cout<<"can not load file\n";
		return 0;
	}
	student res=best_of_list(a,n);
	int ans=save_data("/home/huy/Documents/HK2 2018-2019/cs162/23_1_19/ex07/res.txt",res);
	if (ans) cout<<"find res and save successully\n";
	delete_pointer(a,n);
	return 0;
}


