#include "class.h"

LinearHashing::LinearHashing (const vector <int> &c) {
	sz = c.size();
	a.assign(sz, 0);
	for (auto it : c) add(it);
}

void LinearHashing::add(int x) {
	int k = x % sz;
	while (a[k]) k = (k + 1) % sz;
	a[k] = x;
}

bool LinearHashing::exist(int x) {
	int k = x % sz;
	for (int i = 0; i < sz; ++i) if (a[(k + i) % sz] == x) {
		return true;
	}
	return false;
}

void LinearHashing::display() {
	cout << "Linear Hasing\n";
	for (auto it : a) cout << it << " ";
	puts("");
}
