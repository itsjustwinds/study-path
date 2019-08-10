#include"function.h"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char **seat;
	int *price;
	int total=0;
	init(seat);
	enter_price(price);
	show_sheet(seat);
	while (1) {
		cout << "sell more ? 1 is YES, 0 is NO\n";
		int ok,n,row,col;
		cin >> ok;
		if (ok == 0) break;
		cout << "please enter number of seats you want: ";
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cout << "enter row and columm: ";
			cin >> row >> col;
			if (!check(row, col,seat)) {
				--i;
				cout << "seat not real\n";
				continue;
			}
			sold(seat, total, price, row, col);
		}
		clrscr();
		show_sheet(seat);
		show_sales(total);
	}
	show_seat_left(seat);
	system("pause");
}