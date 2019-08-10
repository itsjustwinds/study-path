#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
void clrscr();
void init(char **&seat);
int check(int row, int col,char **seat);
void show_sheet(char **&seat);
void enter_price(int *&price);
void sold(char **&seat, int &total, int *price,int row,int col);
void show_sales(int total);
void show_seat_left(char **&seat);

#endif