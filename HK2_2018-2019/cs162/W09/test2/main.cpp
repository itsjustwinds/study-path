/*
 * main.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: huy
 */

#include<iostream>
#include<fstream>
#include<cstring>
#include<stdio.h>
using namespace std;
class book{
private:
	int ID;
	char* title;
	char* authors;
	float price;
	int stock;
public:
	void update_ID(int new_ID){ID=new_ID;}
	void update_title(char* new_s){title=new_s;}
	void update_authors(char* new_s){authors=new_s;}
	void update_price(float new_price){price=new_price;}
	void update_stock(int new_stock){stock=new_stock;}
	int get_ID(){return ID;}
	char* get_title(){return title;}
	char* get_authors(){return authors;}
	float get_price(){return price;}
	int get_stock(){return stock;}
};

void read_from_console(int &n,book* &a){
	cin>>n;
	a=new book[n];
	for (int i=0;i<n;++i){
		int x;
		char s[255];
		float z;
		cin>>x;
		a[i].update_ID(x);
		cin.get(s,255,'\n');
		a[i].update_title((char*)s);
		cin.get(s,255,'\n');
		a[i].update_authors((char*)s);
		cin>>z;
		a[i].update_price(z);
		cin>>x;
		a[i].update_stock(x);
	}
}

void write_to_file(int &n,book* a){
	ofstream fout;
	fout.open("data.bin",ios::binary);
	fout.write((char*)&n,sizeof(int));
	for (int i=0;i<n;++i){
		int x=a[i].get_ID();
		float tmp=a[i].get_price();
		fout.write((char*)&x,sizeof(int));
		fout.write((char*)a[i].get_title(),strlen(a[i].get_title()));
		fout.write((char*)a[i].get_authors(),strlen(a[i].get_authors()));
		fout.write((char*)&tmp,sizeof(float));
		x=a[i].get_stock();
		fout.write((char*)&x,sizeof(int));
	}
	fout.close();
}
int main(){
	int n;
	book *a;
	read_from_console(n,a);
	for (int i=0;i<n;++i){
		cout<<a[i].get_ID()<<"\n";
		cout<<a[i].get_title()<<"\n";
		cout<<a[i].get_authors()<<"\n";
		cout<<a[i].get_price()<<"\n";
		cout<<a[i].get_stock()<<"\n";
		cout<<"\n";
	}
	delete[] a;
}


