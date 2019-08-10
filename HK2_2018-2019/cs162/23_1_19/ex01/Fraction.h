/*
 * Fraction.h
 *
 *  Created on: Jan 23, 2019
 *      Author: huy
 */

#pragma once
#ifndef Fraction_H
#define Fraction_H
#include <iostream>
#include<algorithm>
#include <fstream>

using namespace std;
struct Fraction{
int nu, de;
};
bool loadArray(const char *path, Fraction a[], int &n);
bool compare(Fraction p1, Fraction p2);
Fraction max(Fraction a[], int n);
bool saveAFraction(const char *path, Fraction p);

#endif