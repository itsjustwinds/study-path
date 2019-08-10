/*
 * linuxF.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: huy
 */
#include"linuxF.h"

void linuxF::gotoXY(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}

void linuxF::clrscr(){
	system("clear");
}

int linuxF::inputkey(){
	while((key=getch())==-1){
		refresh();
		gotoXY(0,0);
	}
	return key;
}
