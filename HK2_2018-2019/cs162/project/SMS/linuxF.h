/*
 * linuxF.h
 *
 *  Created on: Feb 25, 2019
 *      Author: huy
 */
#pragma once
#ifndef LINUXF_H_
#define LINUXF_H_
#include <iostream>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

using namespace std;
struct linuxF{
	int key;
	void gotoXY(int x,int y);
	int inputkey();
	void clrscr();
};


#endif /* LINUXF_H_ */
