/*
 * login.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: huy
 */

#include"login.h"

int login::main_move(int &curX,int &curY){
	linuxF LinuxF;
	LinuxF.gotoXY(0,0);
	LinuxF.key=LinuxF.inputkey();
	if (LinuxF.key=='w'){
		if (curY!=15) --curY;
	}
	if (LinuxF.key=='s'){
		if (curY!=18) ++curY;
	}
	if (LinuxF.key==13){
		if (curY==17) {}
		if (curY==18) return 0;

	}

	return 1;
}

int login::login_main(){
	linuxF LinuxF;
	int curX=12,curY=15;
	while(1){
		LinuxF.gotoXY(15,15);
		printf("User: ");
		LinuxF.gotoXY(15,16);
		printf("Password: ");
		LinuxF.gotoXY(15,17);
		printf("login");
		LinuxF.gotoXY(15,18);
		printf("return");
		if (main_move(curX,curY)==0) return 1;
	}
	return 0;
}

int login::screen_move(int &curX,int &curY){
	linuxF LinuxF;
	LinuxF.gotoXY(0,0);
	LinuxF.key=LinuxF.inputkey();
	if (LinuxF.key=='w'){
		if (curY!=15) --curY;
	}
	if (LinuxF.key=='s'){
		if (curY!=16) ++curY;
	}
	if (LinuxF.key==13){
		return login_main();
	}

	return 1;
}

int login::screen(){
	linuxF LinuxF;
	int curX=16;
	int curY=15;
	while(1){
		LinuxF.gotoXY(15,7);
		printf("STUDENT MANAGER SYSTEM\n");
		LinuxF.gotoXY(20,15);
		printf("Login");
		LinuxF.gotoXY(20,16);
		printf("exit");
		LinuxF.gotoXY(curX,curY);
		printf(">");
		if(screen_move(curX,curY)==0) break;
		LinuxF.clrscr();
	}
	return 1;
}
