/*
 * main.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: huy
 */

#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream fout;
	fout.open("data.bin",ios::binary);
	while(1){
		int x;
		cin>>x;
		fout.write((char*)&x,32);
		if (x==0) break;
	}
	fout.close();

	ifstream fin;
	fin.open("data.bin",ios::binary);
	int dem=0;
	while(1){
		int x;
		fin.read((char*)&x,32);
		if (x==0) break;
		cout<<x<<" ";
		++dem;
	}
	cout<<"\n";
	printf("There are %d number in the array",dem);
	fin.close();
}


