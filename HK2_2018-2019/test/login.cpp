/*
 * login.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: huy
 */

#include"login.h"
int login::screen(){
	linuxF LinuxF;
	int curX=16,curY=15;
	while(1){
		LinuxF.gotoXY(15,7);
		printf("STUDENT MANAGER SYSTEM\n");
		LinuxF.gotoXY(20,15);
		printf("Login");
		LinuxF.gotoXY(20,16);
		printf("exit");
		for (int i=15;i<=16;++i){
			LinuxF.gotoXY(16,i);
			printf(" ");
		}
		LinuxF.gotoXY(curX,curY);
		printf(">");
		LinuxF.gotoXY(0,0);
		while((LinuxF.key=LinuxF.inputkey())==-1){
			refresh();
			LinuxF.gotoXY(0,0);
		}
		if (LinuxF.key=='w'){
			if (curY!=15) --curY;
		}
		if (LinuxF.key=='s'){
			if (curY!=16) ++curY;
		}
	}
	return 1;
}

