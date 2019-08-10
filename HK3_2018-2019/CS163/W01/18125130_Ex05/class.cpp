#include "class.h"

DoubleHashing::DoubleHashing (vector <int> &c) {
	sz = c.size();
	a.assign(sz, 0);
	for (auto it : c) add(it);
}
void DoubleHashing::add(int x) {
	int i = x % sz, j = x % sz + 1, k = 0;
	while (a[(i + k * j) % sz]) k++;
	a[(i + k * j) % sz] = x;
}

bool DoubleHashing::exist(int x) {
	int i = x % sz, j = x % sz - 1;
	for (int k = 0; k <= sz; ++k) if (a[(i + k * j) % sz] == x) {
		return true;
	}
	return false;
}

void DoubleHashing::display() {
	puts("Double Hasing");
	for (auto it : a) cout << it << " ";
	puts("");
}
