/*
 * book_store.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: huy
 */

#include"book_store.h"


void book_store::delete_all(book *&item){
	if (item==nullptr) return;
	delete_all(item->Next);
	delete item;
}

void book_store::init(){
	item=nullptr;
}

bool book_store::input(book *New){
	book *cur=item;
	if(cur==nullptr) {
		cur=New;
		return 1;
	}
	while(cur!=nullptr){
		if (compare(cur,New)){
			cur->stock_level++;
			return 0;
		}
		if (cur->Next==nullptr){
			cur->Next=New;
			return 1;
		}
	}
	return 1;
}

bool book_store::sell(book *New){
	book *cur=item;
	while(cur!=nullptr){
		if (compare(cur,New)){
			cur->stock_level++;
			return 0;
		}
	}
	cout<<"OUT OF STOCK\n";
	return 1;
}

void book_store::find(char s[]){
	book *cur=item;
	while(cur!=nullptr){
		if (right(s,cur->title)){
			cout<<"BOOK: "<<cur->title<<"\n";
			cout<<cur->ISBN<<"\n";
		}
	}
}

void book_store::remove_less_than_k(int k){
	while(item->stock_level<k){
		book *tmp=item;
		delete item;
		item=tmp;
	}
	book *cur=item;
	while(cur->Next!=nullptr){
		if (cur->Next->stock_level>=k){
			cur=cur->Next;
			continue;
		}
		book *tmp=cur->Next->Next;
		delete cur->Next;
		cur->Next=tmp;
	}
}