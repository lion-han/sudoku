// sudoku.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。


#include "pch.h"
#include <iostream>
#include<string> 
#include<cstring>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
#define size 9;

int main()
{
	//{'1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '2', '3', '4', '5', '6', '7'};
	//123456789
	//string a = { "1234" };
	//getchar();
	string one = { "123456789" };
	string oneone;
	int sum;
	int sequence[9] = {0,3, 6, 2, 8, 5, 1, 7, 4};
	//int sequence[8] = { 1,2,3,4,5,6,7,8 };
	int n = 0;
	string all[10];

	scanf_s("%d", &sum);
	
	ofstream ofile;
	ofile.open("zhongju.txt"); 


	
	while (n<sum) {
		next_permutation(one.begin()+1, one.end());
		oneone = one + one;

		for (int i = 0; i < 9; i++) {
			all[i]= oneone.substr(sequence[i], 9);
		}

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				ofile << all[i][j];
				ofile << ' ';
			}
			ofile << endl;
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

