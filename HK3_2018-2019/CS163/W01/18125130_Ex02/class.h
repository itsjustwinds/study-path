#ifndef FUNCTION_H_DEFINED
#define FUNCTION_H_DEFINED

#include <iostream>
#include <string.h>
#include <vector>
#include <utility>

using namespace std;

class ChainHashing {
public:
	ChainHashing (const vector <int> &c);

    void add(int x);

    bool exist(int x);

    void display();

private:
    int sz;
	vector < vector <int> > a;
};
#endif
