// sudoku.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。


#include "pch.h"
#include <iostream>
#include<string> 
#include<cstring>
#include<vector>
#include<algorithm>
#include<fstream>
#include<stdlib.h>
#include<ctime>
using namespace std;
#define size 9;
#define me 6
//(3+2)%9+1=6
char question[9][9];
void generate();
int isvalue(int x, int y, int value);
int slove(char que[][9], int x, int y);
int main()
{
	generate();
	cout << "题目：" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << question[i][j];
		}
		cout << endl;
	}
	if (slove(question, 0, 0)) {
		cout << "解为：" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << question[i][j];
			}
			cout << endl;
		}
	}
	else {
		cout << "无解" << endl;
	}
	
	return 0;


	string one = { "612345789" };
	string oneone;
	int sum;
	int i = 0, j = 0;
	int sequence[9] = {0,3, 6, 2, 8, 5, 1, 7, 4};

	int n = 0;
	string all[10];

	scanf_s("%d", &sum);
	
	ofstream ofile;
	ofile.open("zhongju.txt"); 


	
	while (n<sum) {
		next_permutation(one.begin()+1, one.end());
		oneone = one + one;

		for ( i = 0; i < 9; i++) {
			all[i]= oneone.substr(sequence[i], 9);
		}

		for ( i = 0; i < 9; i++) {
			for ( j = 0; j < 8; j++) {
				ofile << all[i][j];
				ofile << ' ';
			}
			ofile << all[i][8]<<endl;
			//ofile << endl;
		}
		
		/*for (int i = 0; i < 9; i++) {
			ofile << all[i + 1] << endl;
		}*/
		ofile << endl;
		n++;		
	}
	cout << "over";
	ofile.close();
}

void generate() {
	string filepath = "zhongju.txt";
	int i = 0,j=0,jj=0;
	int degree = 65;
	int x_0[80], y_0[80];
	string line;
	char all[9][9];
	
	ifstream ifile;
	ifile.open("zhongju.txt");

	//freopen("zhongju.txt", "r", stdin);
	for (i = 0; i < 9; i++) {
		getline(ifile, line); 
		for (j = 0,jj=0; j < 9; j++) {	
			all[i][j] = line[jj];
			jj = jj + 2;		
		}
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {			
			cout << all[i][j];
		}			
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			question[i][j] = all[i][j];
		}
	}
	
	srand((unsigned int)time(NULL));
	for (i = 0; i < degree; i++) {
		x_0[i] = rand() % 9;
		y_0[i] = rand() % 9;
	}
	
	for (i = 0; i < degree; i++) {

		question[x_0[i]][y_0[i]] = '0';
	}

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cout << question[i][j];
		}
		cout << endl;
	}
}

int slove(char que[][9],int x,int y){

	int value;
	int next_x, next_y;

	next_x = x;
	next_y = y;
	//下一个位置
	if (y != 8) {
		next_y++;
	}
	else if (y = 8) {
		if (x == 8)
			;
		else {
			next_y = 0;
			next_x++;
		}
	}

	if (que[x][y] != '0') {
		if (x == 8 && y == 8) {
			return 1;
		}
		if (slove(que, next_x, next_y) == 1) {
			return 1;
		}
		else return 0;
	}
		
	for (value = 1; value <= 9; value++) {
		if (isvalue(x, y, value)) {
			que[x][y] = value + '0';
			
			if (x == 8 && y == 8) {
				return 1;
			}
			if (slove(que, next_x, next_y) == 1) {
				return 1;
			}	
			que[x][y] = '0';
		}
	}
	return 0;
}

int isvalue(int x, int y,int value) {
	int a, b;
	int i = 0,j = 0;
	//行
	for (i = 0; i < 9; i++) {
		if (question[x][i] == (value + '0')) {
			return 0;
		}
	}
	//列
	for (i = 0; i < 9; i++) {
		if (question[i][y] == (value + '0')) {
			return 0;
		}
	}
	
	//方格
	a = x / 3;
	b = y / 3;
	for (i = a * 3; i < (a + 1) * 3; i++) {
		for (j = b * 3; j < (b + 1) * 3; j++) {
			if (question[i][j] == (value + '0')) {
				return 0;
			}
		}
	}
	return 1;

	
}

