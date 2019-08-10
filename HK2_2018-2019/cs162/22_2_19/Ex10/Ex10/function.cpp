#include"function.h"

void init(char **&seat) {
	seat = new char *[15];
	for (int i = 0; i < 15; ++i)
		seat[i] = new char[30];
	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 30; ++j)
			seat[i][j] = '#';
}

int check(int row, int col,char **seat) {
	return (row >= 1 && row <= 15) && (col >= 1 && col <= 30)&&seat[row-1][col-1]=='#';
}

void clrscr() {
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void show_sheet(char **&seat) {
	cout << "\n";
	for (int i = 1; i <= 10; ++i)
		cout << " ";
	for (int i = 1; i <= 30; ++i)
		cout << i % 10;
	cout << "\n";
	for (int i = 1; i <= 15; ++i) {
		cout << "Row " << i;
		for (int j = 1; j <= 5 - (i >= 10); ++j)
			cout << " ";
		for (int j = 1; j <= 30; ++j)
			cout << seat[i - 1][j - 1];
		cout << "\n";
	}
}

void enter_price(int *&price) {
	cout << "please enter price for each row\n";
	price = new int[15];
	for (int i = 0; i < 15; ++i) {
		cout << "enter price of row " << i+1 << " :";
		cin >> price[i];
	}
}

void sold(char **&seat, int &total, int *price,int row,int col) {
	total += price[row-1];
	seat[row-1][col-1] = '*';
}

void show_sales(int total) {
	cout <<"Sales: "<< total<<"\n";
}

void show_seat_left(char **&seat) {
	int total = 0;
	for (int i = 1; i <= 15; ++i) {
		int num = 0;
		for (int j = 1; j <= 30; ++j)
			if (seat[i - 1][j - 1] == '#') num++;
		cout << "number of seats haven't sold in "<<i<<" is: " << num<<"\n";
		total += num;
	}
	cout << "entire :" << total<<"\n";
}