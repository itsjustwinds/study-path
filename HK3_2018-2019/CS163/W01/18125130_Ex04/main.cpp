#include "class.h"

int main() {
	vector <int> a({1, 2, 3, 5});
	QuadraticHashing lh(a);
	lh.display();
	cout << lh.exist(3) << " " << lh.exist(4) << "\n";
	return 0;
}
