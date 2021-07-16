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
void mio(int i, int j, int xy[30][30][3], int xx, int yy);
bool trump(int x, int y, int namosi[30][30][3]);
bool tek(int n, int m, int y[30][30][3]);
bool nakona(int i, int j, int mio[30][30][3], int xx, int yy);
bool mishimago(int i, int j, int xx, int yy);
void ssort(int arrr[], int size);
void swap(int&, int&);
bool mirio();
int main() {
	bool jk = true;
	while (jk) {
		int xx, yy;
		cin >> xx >> yy;
		play(xx, yy);
		jk = mirio();
	}

}
bool nakona(int i, int j, int mio[30][30][3], int xx, int yy) {
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
bool tek(int n, int m, int y[30][30][3]) {
	if (y[n][m][1] != 0) {
		return true;
	}
	return false;
}

void mio(int i, int j, int xy[30][30][3], int xx, int yy) {
	if (xy[i][j][0] == 0 && !tek(i, j, xy) && !mishimago(i, j, xx, yy) && !trump(i, j, xy)) {
		xy[i][j][1] = 1;
		if (xy[i - 1][j][0] != 0 && !mishimago(i - 1, j, xx, yy) && !trump(i - 1, j, xy)) {
			xy[i - 1][j][1] = 1;
		}
		if (xy[i - 1][j + 1][0] != 0 && !mishimago(i - 1, j + 1, xx, yy) && !trump(i - 1, j + 1, xy)) {
			xy[i - 1][j + 1][1] = 1;
		}
		if (xy[i + 1][j + 1][0] != 0 && !mishimago(i + 1, j + 1, xx, yy) && !trump(i + 1, j + 1, xy)) {
			xy[i + 1][j + 1][1] = 1;
		}
		if (xy[i + 1][j - 1][0] != 0 && !mishimago(i + 1, j - 1, xx, yy) && !trump(i + 1, j - 1, xy)) {
			xy[i + 1][j - 1][1] = 1;
		}
		if (xy[i][j - 1][0] != 0 && !mishimago(i, j - 1, xx, yy) && !trump(i, j - 1, xy)) {
			xy[i][j - 1][1] = 1;
		}
		if (xy[i][j + 1][0] != 0 && !mishimago(i, j + 1, xx, yy) && !trump(i, j + 1, xy)) {
			xy[i][j + 1][1] = 1;
		}

		if (xy[i - 1][j - 1][0] != 0 && !mishimago(i - 1, j - 1, xx, yy) && !trump(i - 1, j - 1, xy)) {
			xy[i - 1][j - 1][1] = 1;

		}
		if (xy[i + 1][j][0] != 0 && !mishimago(i + 1, j, xx, yy) && !trump(i + 1, j, xy)) {
			xy[i + 1][j][1] = 1;

		}

		mio(i - 1, j, xy, xx, yy);
		mio(i - 1, j + 1, xy, xx, yy);
		mio(i + 1, j, xy, xx, yy);
		mio(i, j + 1, xy, xx, yy);
		mio(i, j - 1, xy, xx, yy);
		mio(i + 1, j - 1, xy, xx, yy);
		mio(i + 1, j + 1, xy, xx, yy);
		mio(i - 1, j - 1, xy, xx, yy);

	}

}

bool mishimago(int i, int j, int xx, int yy) {
	if ((i > xx - 1) || (j > yy - 1) || (j < 0) || (i < 0)) {
		return true;
	}
	return false;
}
bool trump(int x, int y, int namosi[30][30][3]) {
	if (namosi[x][y][2] == 4) {
		return true;
	}
	else
		return false;

}
void  play(int xx, int yy) {

	{
		bool pari = true;
		int m, n, a, F, x, y;
		int avakanka = 0;
		int emwar[30][30][3];
		int win = 0;
		int Cocakola = 0;
		int o = 0;
		int q = 3;
		int duration;
		int cocakola = 0;

		
		system("Color 4");
		cout << "EMWAR MINESWEEPER";
		Sleep(2000);
		for (int mo = 1; mo < 6; mo++) {
			system("cls");
			Beep(523 * mo / 2, 300); // 523 hertz (C5) for 500 milliseconds
			Beep(587 * mo / 2, 300);
			Beep(659 * mo / 2, 300);
			Beep(698 * mo / 2, 300);
			Beep(784 * mo / 2, 300);
		}

		int scorearr[100];
		for (int i = 0; i < 100; i++)
			scorearr[i] = 0;
		for (int i = 0; i < 5; i++) {


			system("color 6");
			cout << "                        *                                                                * " << endl;
			cout << "                   *         *            MATONA!                      / *          *       *        *                 EMWAR                               *    " << endl;
			cout << "                *               *                      *___\ _______ *        *         *           *              *    *  " << endl;
			cout << "              *                   *                    *    *      /                 *               *                                *" << endl;
			cout << "             *       0    0        *          * *             \    *     *       *    MEG AMRICA     *  *           * " << endl;
			cout << "            *                      *                        * * __ *___/    *                   *       *  *          * " << endl;
			cout << "            *           ^          *                     * / \  /            *                         *                        *           *        *  *   *              *                * " << endl;
			cout << "             *                    *                *       *  *     *                        *                        *       *        * " << endl;
			cout << "              *       ====       *                     OFTAMDIM RAFT :(                         *     BUDIES!        *     **" << endl;
			cout << "                *              *                                                                      *       *     * " << endl;
			cout << "                   *       *                                                                      DANESHGAH KHAR AST     " << endl;
			cout << "                       *                                " << endl;
			cout << "                       *                                " << endl;
			cout << "                                                                    HEEEY!                                                                              *     *    * " << endl;
			Sleep(1200);
			system("cls");
			cout << "                        *                                                         HATONA        * " << endl;
			cout << "                   *         *                             / *          *       *        *                                        MATANA        *    " << endl;
			cout << "                *               *                      *___\ _______ *        *         *           *       EMWAR       *      *  " << endl;
			cout << "              *                   *                    *    *      /                 *               *                                *" << endl;
			cout << "             *       0    0        *          * *             \    *     *       *         *  *           * " << endl;
			cout << "            *                      *                        * * __ *___/    *                   *       *  *          * " << endl;
			cout << "            *           ^          *                     * / \  /            *           HAMZE LOVES POURIA!              *                        *           *        *  *   *              *                * " << endl;
			cout << "             *                    *                *       *  *     *                        *                        *       *    GORBE NARE    * " << endl;
			cout << "              *       ====       *              !!!!  PO  !!!                       *             *     **" << endl;
			cout << "                *              *                                                                      *       *     * " << endl;
			cout << "                   *       *                                   " << endl;
			cout << "                       *                                " << endl;
			cout << "                       *                                " << endl;
			cout << "                                                                     welcome budy be crafull                                                                                *     *    * " << endl;
			Sleep(1000);
			system("cls");
			cout << "                        *                                                                * " << endl;
			cout << "                   *         *                             / *          *        *        *                                                *    " << endl;
			cout << "                *               *                       *___\ _______ *          *              *            *              *    *  " << endl;
			cout << "              *                   *                    *    *      /                 *               *                                *" << endl;
			cout << "             *       0    0        *          *  *             \    *     *          *         *  *           * " << endl;
			cout << "            *                      *                          * __ *___/    *                   *          HAMZE LOVES POURIA!   *  *          * " << endl;
			cout << "            *            ^         *                        /            *                         *                        *           *        *  *   *              *                * " << endl;
			cout << "             *                    *             !!!  PORI !!! *     *       *  *   *                        *                        *       *        * " << endl;
			cout << "              *       =^^=       *                                    *             *     **" << endl;
			cout << "                *              *                                                                    *       *     * " << endl;
			cout << "                   *       *                 " << endl;
			cout << "                       *                    " << endl;
			cout << "                       *                 " << endl;
			cout << "                                                                        WannnAaaaa Play ?                                                  *" << endl;
			Sleep(1000);
			system("cls");
			cout << "                        *                                                                * " << endl;
			cout << "                   *         *                             / *          *       *        *                                                *    " << endl;
			cout << "                *               *                       *___\ _______ *          *             *           *              *    *  " << endl;
			cout << "              *                   *                    *    *      /                 *   HAMZE EATS PIZZA        *           *                                   *   *" << endl;
			cout << "             *       0    0        *          *  *             \    *     *          *         *  *           * " << endl;
			cout << "            *                      *                         * __ *___/    *                   *       *  *          * " << endl;
			cout << "            *          ^          *                    *    /            *                         *                        *  MEHRDAD LOVES MOHSEN         *        *  *   *              *                * " << endl;
			cout << "             *                    *            EMWAR IS GETTING WILD!        *       *  *   *                        *                        *        *        * " << endl;
			cout << "              *       =~~=       *                                     *             *     **" << endl;
			cout << "                   *       *                  " << endl;
			cout << "                *              *                                                          HAMZE?PPRIA       *       *     * " << endl;
			cout << "                       *                            " << endl;
			cout << "                       *                    !!!!!!A!!!!!!                                           *         *       " << endl;
			cout << "                                                                      Ready??????????                          " << endl;
			Sleep(1000);
			system("cls");
		}
		for (int i = 0; i < 3; i++) {
			cout << "                                                                                  " << (i + 1) << endl;
			Sleep(1000);
		}
		system("cls");
		cout << "                                                                                " << ">play" << endl << "                                                                                " << ">bye" << endl << "(0 / 1)" << endl;
		int i;
		cin >> i;
		system("cls");
		cout << "CHIGHADE MIKHAY NOMRE BEDI ?" << endl;
		cin >> i;
		if (i < 5) {
			cout << " RO MOKHE PARI NARO!";
			while (i < 5) {
				cin >> i;

				cout << " RO MOKHE PARI NARO!";
			}
		}
		system("cls");
		cout << "                                                                                               " << " goood booooi!"; system("cls");
		cout << "lets start";
		Sleep(1500);
		system("cls");
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
		cout << "how many bombs" << endl;
		cin >> n;

		srand(time(NULL));
		for (int i = 0; i < n;) {
			m = rand() % xx;
			q = rand() % yy;
			if (nakona(m, q, emwar, xx, yy))
				i++;
		}


		while (avakanka != 1) {

			Cocakola = 0;
			cout << "ENETER x and y" << endl;
			cin >> x >> y;
			cout << "GOOdboy!" << endl;
			cout << "flag or touch ?(flag=1/touch=0)" << endl;
			system("color 6");
			Sleep(700);
			system("color 4");
			cin >> a;
			if (a == 0) {
				if (emwar[x][y][1] == 2) {
					cout << "are u sure (0/1)?" << endl;
					cin >> a;
					system("color 6");
					Sleep(700);
					system("color 4");
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
				cout << "flag or diflag(flag=1,deflag=0)" << endl;
				system("color 6");
				Sleep(700);
				system("color 4");
				cin >> a;
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
			system("cls");
			cout << "                                                *****    " << endl;
			cout << "                                               * @ @ *   " << endl;
			cout << "                                                * _ *    " << endl;
			cout << "                                                  *      " << endl;
			win = 0;
			for (int i = 0; i < xx; i++) {
				for (int j = 0; j < yy; j++) {

					if (emwar[i][j][1] == 1) {
						if (emwar[i][j][2] == 4) {
							cout << "#" << " |";
							avakanka = 1;
						}

						else {
							cout << emwar[i][j][0] << " |";
							scorearr[o] += 7 * emwar[i][j][0] + 5;
							win++;
						}
					}

					if (emwar[i][j][1] == 0) {
						cout << "*" << " |";
					}
					if (emwar[i][j][1] == 2) {
						cout << "F" << " |";
						win++;
					}



				}
				cout << endl;
			}

			if (win == (xx * yy - n)) {
				system("cls");
				system("color 4");
				cout << "                                                        win                                                        " << endl;
				cout << "                                                   ^_^ -   - ^_^                                " << endl;
				cout << "                                              ^_^ -              - ^_^                                " << endl;
				cout << "                                              ^_^                 ^_^                                " << endl;
				cout << "                                                 ^_^ __________ ^_^                                " << endl;
				Beep(587 / 2, 300);
				Sleep(10000);
				system("color 6");
				Sleep(10000);
				return;
			}

		}

		if (avakanka == 1) {
			system("cls");
			for (int i = 0; i < xx; i++) {
				for (int j = 0; j < yy; j++) {
					if (emwar[i][j][2] == 4) {
						cout << "#" << " | ";
					}
					else {
						cout << emwar[i][j][0] << " | ";
					}
				}
				cout << endl;
			}
			system("Color F5");
			cout << endl << "YOU LOSE" << endl;
			duration = (std::clock()) / (double)CLOCKS_PER_SEC;
			Sleep(1000);

			std::cout << endl << duration << " second" << '\n';
			Beep(423, 1500);
			ssort(scorearr, o + 1);

			for (int i = 0; i <= o; i++) {
				cout << i + 1 << "- your score : " << scorearr[i] << endl;
				Sleep(3000);
			}

			o++;
		}
	}
}
bool mirio() {
	system("cls");
	cout << "wana restart?if you do press 1" << endl;
	int a;
	cin >> a;
	if (a == 1) {

		system("cls");

		return true;
	}
	else {
		return false;
	}
}
void ssort(int arrr[], int size) {
	for (int y = 0; y < size; ++y) {
		for (int j = y; j < size; j++) {
			if (arrr[j] > arrr[y]) {
				swap(arrr[j], arrr[y]);
			}
		}
	}
}
void swap(int& x, int& y) {
	int hold = x;
	x = y;
	y = hold;
}