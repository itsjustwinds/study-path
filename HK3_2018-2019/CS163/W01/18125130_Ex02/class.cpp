#include "class.h"

ChainHashing::ChainHashing (const vector <int> &c) {
	sz = c.size();
	a.assign(sz, vector <int> ());
	for (auto it : c) add(it);
}
void ChainHashing::add(int x) {
	a[x % sz].push_back(x);
}

bool ChainHashing::exist(int x) {
	for (auto it : a[x % sz]) if (it == x) {
		return true;
	}
	return false;
}

void ChainHashing::display() {
	cout << "Chain Hasing\n";
	int i = 0;
	for (auto it : a) {
		cout << i++ << " ";
		for (auto jt : it) cout << jt << " ";
		cout << "\n";
	}
}
