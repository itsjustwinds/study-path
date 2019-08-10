/*
 * Student.h
 *
 *  Created on: Jan 24, 2019
 *      Author: huy
 */
#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student{
	int ID;
	char *name;
	double GPA;
};
void delete_pointer(student a[],int &n);
void input(ifstream &fin, student &a);
bool load_data(const char *path,student a[],int &n);
bool save_data(const char *path, student &a);
student max(student &a, student &b);
student best_of_list(student a[],int &n);
#endif /* STUDENT_H_ */
