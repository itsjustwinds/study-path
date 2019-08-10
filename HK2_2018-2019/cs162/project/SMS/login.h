/*
 * login.h
 *
 *  Created on: Feb 25, 2019
 *      Author: huy
 */
#pragma once
#ifndef LOGIN_H_
#define LOGIN_H_
#include<iostream>
#include<stdio.h>
#include"linuxF.h"
using namespace std;
struct login{
	int screen();
	int screen_move(int &curX,int &curY);
	int login_main();
	int main_move(int &curX,int &curY);
};



#endif /* LOGIN_H_ */
