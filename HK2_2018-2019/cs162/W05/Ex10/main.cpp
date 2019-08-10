/*
 * main.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: huy
 */

#include"book_store.h"

int main(){
	book_store store;
	store.init();
	while(1){
		/*cout<<"input:\n";
		cout<<"1 to init\n";
		cout<<"2 to input a book\n";
		cout<<"3 to sell a book\n";
		cout<<"4 to find a book\n";
		cout<<"5 to remove all book have stock less than K\n";
		cout<<"0 to exit\n";*/
		int ques;
		cin>>ques;
		if(ques==1){
			store.init();
		}
		if(ques==2){
			book *New=new book;
			//cout<<"input title: ";
			cin>>New->title;
			//cout<<"input ISBN: ";
			cin>>New->ISBN;
			//cout<<"input author: ";
			cin>>New->author;
			//cout<<"input language: ";
			cin>>New->language;
			//cout<<"input year published: ";
			cin>>New->year_published;
			//cout<<"input price: ";
			cin>>New->price;
			//cout<<"input stock level: ";
			cin>>New->stock_level;
			New->Next=nullptr;
			cout<<New->title<<" "<<New->ISBN<<"\n";
			if(store.input(New)==0) delete New;
		}
		if(ques==3){
			book *New=new book;
			//cout<<"input title: ";
			cin>>New->title;
			//cout<<"input ISBN: ";
			cin>>New->ISBN;
			//cout<<"input author: ";
			cin>>New->author;
			//cout<<"input language: ";
			cin>>New->language;
			//cout<<"input year published: ";
			cin>>New->year_published;
			//cout<<"input price: ";
			cin>>New->price;
			//cout<<"input stock level: ";
			cin>>New->stock_level;
			New->Next=nullptr;
			delete New;
		}
		if (ques==4){
			char s[200];
			//cout<<"intput title: ";
			cin>>s;
			store.find(s);
		}
		if (ques==5){
			int k;
			cout<<"input K: ";
			cin>>k;
			store.remove_less_than_k(k);
		}
		if (ques==0) break;
	}
	return 0;
}

