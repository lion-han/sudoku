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
string question[9][9];
void fun();
int main()
{
	fun();
	slove(question);

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

void fun() {
	string filepath = "zhongju.txt";
	int i = 0,j=0,jj=0;
	int degree = 40;
	int x_0[60], y_0[60];
	string line;
	string all[9][9];
	
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

void slove(string* que){
	int a = 1;
		for (a = 1; a <= 9; a++) {

	}
}