#include "class.h"
QuadraticHashing::QuadraticHashing (const vector <int> &c) {
	sz = c.size() + 1;
	a.assign(sz, 0);
	for (auto it : c) add(it);
}
void QuadraticHashing::add(int x) {
	int k = x % sz;
	for (int i = 0; i < sz; ++i) {
		k = (k + i * i) % sz;
		if (!a[k]) break;
	}
	if (!a[k]) a[k] = x;
}

bool QuadraticHashing::exist(int x) {
	int k = x % sz;
	for (int i = 0; i < sz; ++i) {
		k = (k + i * i) % sz;
		if (a[k] == x) return true;
	}
	return false;
}

void QuadraticHashing::display() {
	puts("Quaratic Hasing");
	for (auto it : a) cout << it << " ";
	puts("");
}
