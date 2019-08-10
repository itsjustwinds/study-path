#include "class.h"

int main() {
	vector <int> a({1, 2, 3, 5});
	ChainHashing ch(a);
	cout << ch.exist(3) << " " << ch.exist(4) << "\n";
	return 0;;
}
