#include "pch.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <Windows.h>
#include <cstdlib>
#include<cmath>
#include <iostream>
#include <chrono>
#include<iomanip>
using namespace std;
void play(int, int);
void mio(int i, int j, int xy[30][30][3],int xx,int yy);
bool trump(int x, int y, int namosi[30][30][3]);
bool tek(int n, int m, int y[30][30][3]);
bool nakona(int i, int j, int mio[30][30][3], int xx, int yy);
bool mishimago(int i, int j, int xx, int yy);
void ssort(int arrr[], int size);
void swap(int &, int &);
bool mirio();
int main() {
	bool jk = true;
	while (jk) {
		int xx, yy;
		int aria;
		aria = 0;
		while (aria == 0) {
			
			Console.WriteLine("less than 30");
			xx = Convert.ToInt32(Console.Read.line());
			yy= Convert.ToInt32(Console.Read.line());
			if (xx <= 30 && yy <= 30)
				aria = 1;
			
		}
		play(xx, yy);
		jk = mirio();
	}

}
bool nakona(int i, int j, int[][][]mio,int xx,int yy) {
	if (mio[i][j][2] != 4) {
		mio[i][j][2] = 4;
		if (!mishimago(i - 1, j, xx, yy))
			mio[i - 1][j][0]++;
		if (!mishimago(i - 1, j + 1, xx, yy))
			mio[i - 1][j + 1][0]++;
		if (!mishimago(i + 1, j, xx, yy))
			mio[i + 1][j][0]++;
		if (!mishimago(i, j + 1, xx, yy))
			mio[i][j + 1][0]++;
		if (!mishimago(i, j - 1, xx, yy))
			mio[i][j - 1][0]++;
		if (!mishimago(i + 1, j - 1, xx, yy))
			mio[i + 1][j - 1][0]++;
		if (!mishimago(i + 1, j + 1, xx, yy))
			mio[i + 1][j + 1][0]++;
		if (!mishimago(i - 1, j - 1, xx, yy))
			mio[i - 1][j - 1][0]++;
		return true;
	}
	return false;
}
bool tek(int n, int m, int[][][]y) {
	if (y[n][m][1] != 0) {
		return true;
	}
	return false;
}
void mio(int i, int j, int[][][] xy,int xx, int yy) {
	if (xy[i][j][0] == 0 && !tek(i, j, xy) && !mishimago(i, j,xx,yy) && !trump(i, j, xy)) {
		xy[i][j][1] = 1;
		if (xy[i - 1][j][0] != 0 && !mishimago(i - 1, j, xx, yy) && !trump(i - 1, j, xy)) {
			xy[i - 1][j][1] = 1;
		}
		if (xy[i - 1][j + 1][0] != 0 && !mishimago(i - 1, j + 1, xx, yy) && !trump(i - 1, j + 1, xy)) {
			xy[i - 1][j + 1][1] = 1;
		}
		if (xy[i + 1][j + 1][0] != 0 && !mishimago(i + 1, j + 1,xx,yy) && !trump(i + 1, j + 1, xy)) {
			xy[i + 1][j + 1][1] = 1;
		}
		if (xy[i + 1][j - 1][0] != 0 && !mishimago(i + 1, j - 1, xx, yy) && !trump(i + 1, j - 1, xy)) {
			xy[i + 1][j - 1][1] = 1;
		}
		if (xy[i][j - 1][0] != 0 && !mishimago(i, j - 1,xx, yy) && !trump(i, j - 1, xy)) {
			xy[i][j - 1][1] = 1;
		}
		if (xy[i][j + 1][0] != 0 && !mishimago(i, j + 1,xx, yy) && !trump(i, j + 1, xy)) {
			xy[i][j + 1][1] = 1;
		}

		if (xy[i - 1][j - 1][0] != 0 && !mishimago(i - 1, j - 1, xx, yy) && !trump(i - 1, j - 1, xy)) {
			xy[i - 1][j - 1][1] = 1;

		}
		if (xy[i + 1][j][0] != 0 && !mishimago(i + 1, j, xx, yy) && !trump(i + 1, j, xy)) {
			xy[i + 1][j][1] = 1;

		}

		mio(i - 1, j, xy,xx,yy);
		mio(i - 1, j + 1, xy,xx,yy);
		mio(i + 1, j, xy,xx,yy);
		mio(i, j + 1, xy,xx,yy);
		mio(i, j - 1, xy,xx,yy);
		mio(i + 1, j - 1, xy,xx,yy);
		mio(i + 1, j + 1, xy,xx,yy);
		mio(i - 1, j - 1, xy,xx,yy);

	}

}
bool mishimago(int i, int j ,int xx , int yy) {
	if ((i > xx-1) || (j > yy-1) || (j < 0) || (i < 0)) {
		return true;
	}
	return false;
}
bool trump(int x, int y, int[][][] namosi) {
	if (namosi[x][y][2] == 4) {
		return true;
	}
	else
		return false;

}
void  play(int xx, int yy) {

		bool pari = true;
		int m, n, a, F, x, y;
		int avakanka = 0;
		int[][][]emwar= new int[30][30][3];
		int win = 0;
		int Cocakola = 0;
		int o = 0;
		int q = 3;
		int duration;
		int cocakola = 0;
		
		srand(time(0));
		for (int i = 0; i < xx; i++) {
			for (int j = 0; j < yy; j++) {
				emwar[i][j][0] = 0;
			}
		}
		int counter, hold, holder;
		for (int i = 0; i < xx; i++) {
			for (int j = 0; j < yy; j++) {
				emwar[i][j][1] = 0;
			}
		}
		for (int i = 0; i < xx; i++) {
			for (int j = 0; j < yy; j++) {
				emwar[i][j][2] = 0;
			}
		}

		if (pari) {
			cout << "                                                      *****    " << endl;
			cout << "                                                     * @ @ *   " << endl;
			cout << "                                                      * _ *    " << endl;
			cout << "                                                        *      " << endl;
			for (int i = 0; i < 4 * xx; i++)
				cout << char(95);
			cout << endl;
			for (int i = 0; i < xx; i++) {
				for (int j = 0; j < yy; j++) {
					cout << "*" << " | ";
				}

				cout << endl;
			}
			pari = false;
		}
		n = 30;

		srand(time(NULL));
		for (int i = 0; i < n;) {
			m = rand() % xx;
			q = rand() % yy;
			if (nakona(m, q, emwar , xx, yy))
				i++;
		}


		while (avakanka != 1) {
			Y:
			Cocakola = 0;
			cout << "ENETER x and y" << endl;
			x=Convert.ToInt32(Console.Read.line());
			y= Convert.ToInt32(Console.Read.line());
			if (x > xx || y > yy) {
				cout << " BIGGER THAN THE SIZE !!!WT..";
				goto Y;
			}
			cout << "GOOdboy!" << endl;
			cout << ">flag or touch ?" << endl;
			cout << "(flag=1/touch=0)" << endl;
			a = Convert.ToInt32(Console.Read.line());;
			if (a == 0) {
				if (emwar[x][y][1] == 2) {
					cout << "are u sure (0/1)?" << endl;
					a = Convert.ToInt32(Console.Read.line());;
				
					Sleep(700);
					
					if (a == 1)
					{
						if (emwar[x][y][2] == 4)
						{
							avakanka = 1;
						}
						Cocakola = 1;
					}
				}
				else {
					if (emwar[x][y][2] == 4)
					{
						avakanka = 1;
					}
					Cocakola = 1;
				}
			}
			else {
				cout << "flag or deflag?" << endl;
				cout<<"(flag = 1, deflag = 0)" << endl;
			
				a = Convert.ToInt32(Console.Read.line());
				if (a == 0) {
					emwar[x][y][1] = 0;
				}
				else {
					emwar[x][y][1] = 2;
				}
			}
			if (Cocakola == 1) {
				if (emwar[x][y][0] == 0) {
					mio(x, y, emwar, xx, yy);
				}
				else {
					emwar[x][y][1] = 1;
				}
			}
		
			win = 0;
			for (int i = 0; i < xx; i++) {
				for (int j = 0; j < yy; j++) {

					if (emwar[i][j][1] == 1) {
						if (emwar[i][j][2] == 4) {
							Console.WriteLine("#" + " |");
							avakanka = 1;
						}

						else {
							Console.WriteLine(emwar[i][j][0] + " |");
							scorearr[o] += 7 * emwar[i][j][0] + 5;
							win++;
						}
					}

					if (emwar[i][j][1] == 0) {
						Console.WriteLine("*" + " |");
		
					}
					if (emwar[i][j][1] == 2) {
					
						Console.WriteLine("F" + " |");
						win++;
					}



				}
				Console.WriteLine("\n\r");
			}

			if (win == (xx*yy- n)) {
				
				Console.WriteLine("win");
			
				return;
			}

		}

		if (avakanka == 1) {
			for (int i = 0; i < xx; i++) {
				for (int j = 0; j < yy; j++) {
					if (emwar[i][j][2] == 4) {
						Console.WriteLine("#" + " |");
					}
					else {
						Console.WriteLine(emwar[i][j][0] + " |");
					}
				}
				Console.WriteLine("\n\r");
			}
			
			
		}
}
bool mirio() {
	system("cls");
	
	int a;
	a = Convert.ToInt32(Console.Read.line());
	if (a == 1) {

		system("cls");

		return true;
	}
	else {
		return false;
	}
}
void ssort(int[] arrr, int size) {
	for (int y = 0; y < size; ++y) {
		for (int j = y; j < size; j++) {
			if (arrr[j] > arrr[y]) {
				swap(arrr[j], arrr[y]);
			}
		}
	}
}
void swap(int &x, int &y) {
	int hold = x;
	x = y;
	y = hold;
}