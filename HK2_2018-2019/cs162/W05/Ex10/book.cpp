/*
 * book.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: huy
 */

#include"book.h"

bool compare(book *&a,book *&b){
	int ok=a->title==b->title;
	ok=ok&(a->ISBN==b->ISBN);
	ok=ok&(a->author==b->author);
	ok=ok&(a->language==b->language);
	ok=ok&(a->year_published==b->year_published);
	ok=ok&(a->price==b->price);
	return ok;
}

bool right(char a[],char b[]){
	int lenb=strlen(b);
	int lena=strlen(a);
	for (int i=0;i<lenb-lena+1;++i){
		int ok=1;
		for (int j=0;j<lena;++j)
			if (a[j]!=b[i+j]) ok=0;
		if (ok) return 1;
	}
	return 0;
}
