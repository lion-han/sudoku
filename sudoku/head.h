
//#include "pch.h"
#include<iostream>
#include<string> 
#include<cstring>
#include<algorithm>
#include<fstream>
#include<stdlib.h> 
#include<stdio.h>
#include<ctime>
#include <windows.h>
using namespace std;
#define me 6
#define FINALPATH "final_sudoku.txt"
#define QUESTIONPATH "question.txt"
#define	SOLUTIONPATH "solution.txt"
//(3+2)%9+1=6
char question[9][9];
char final[12000];

int mainfun(int argc, char* argv[]);
int generate_final(int sum, char *filepath);
int generate_que(int num_solution);
int generate_queall();
int slove_all(char *filepath);//优化文件读写
int slove_all_1(char *filepath);
int isvalue(int x, int y, int value);
int slove(char que[][9], int x, int y);
int linenum(char *filepath);


//两个换，12+两个换，34+后三个换，45+后三个换，35+后三个换，12+34+后三个换，12+45+后三个换，12+35+67
int swap_line[30][9] = { {0,1,2,3,4,5,6,7,8},{0,2,1,3,4,5,6,7,8} ,\
{0,1,2,3,5,4,6,7,8},{0,1,2,4,3,5,6,7,8},{0,1,2,5,4,3,6,7,8},\
{0,1,2,3,4,5,7,6,8},{0,1,2,3,4,5,6,8,7},{0,1,2,3,4,5,8,7,6},\

{0,2,1,3,5,4,6,7,8},{0,2,1,4,3,5,6,7,8},{0,2,1,5,4,3,6,7,8},\
{0,2,1,3,4,5,7,6,8},{0,2,1,3,4,5,6,8,7},{0,2,1,3,4,5,8,7,6},\

{0,1,2,4,3,5,7,6,8},{0,1,2,4,3,5,6,8,7},{0,1,2,4,3,5,8,7,6},\
{0,1,2,3,5,4,7,6,8},{0,1,2,3,5,4,6,8,7},{0,1,2,3,5,4,8,7,6},\
{0,1,2,5,4,3,7,6,8},{0,1,2,5,4,3,6,8,7},{0,1,2,5,4,3,8,7,6},\

{0,2,1,4,3,5,7,6,8},{0,2,1,4,3,5,6,8,7},{0,2,1,4,3,5,8,7,6},\
{0,2,1,3,5,4,7,6,8},{0,2,1,3,5,4,6,8,7},{0,2,1,3,5,4,8,7,6},\
{0,2,1,5,4,3,7,6,8}
};

//ofstream写入方式
//int generate_final(int sum, char *filepath) {
//
//	char one[] = "612345789";//初始行
//	char oneone[19];
//	char all[9][9];
//	int i = 0, j = 0, n = 1, k = 0, s = 0;
//	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };	//由第一行移动位数
//
//	memset(oneone, 0, sizeof(oneone));
//	memset(final, 0, sizeof(final));
//
//	ofstream ofile;
//	ofile.open(filepath);
//
//	//生成数独
//	while (n <= sum) {
//		k = 0;		
//		next_permutation(one+1 , one+9);//全排列
//
//		strcpy(oneone, one);
//		strcat(oneone, one);
//
//		//移动
//		for (i = 0; i < 9; i++) {
//			for (j = 0; j < 9; j++) {
//				all[i][j] = oneone[j + sequence[i]];
//			}
//		}
//		//写入		
//		for ( s = 0; s < 30; s++) {
//			
//			for (i = 0; i < 9; i++) {
//				for (j = 0; j < 8; j++) {
//					
//					final[k] = all[swap_line[s][i]][j];
//					k++;	
//					final[k] = ' ';
//					k++;
//				}
//				final[k] = all[i][8]; 
//				k++;
//				final[k] = '\n';
//				k++;
//				}
//				
//				//ofile << final;
//				if (n != sum) {
//					//ofile << endl;
//					final[k] = '\n';
//					k++;
//				}
//				else {
//					final[k] = '\0';
//					ofile << final;
//					ofile.close();
//					printf("%d final sudokus generated. filepath: %s\n", sum, filepath);
//					//printf("已生成%d个终局至文件%s.\n", sum, filepath);
//					return 1;
//				}
//				n++;
//		}
//		ofile << final;			
//	}
//	return 1;
//}
//直接写入
//int generate_final(int sum, char *filepath) {
//
//	string one = { "612345789" };//初始行
//	string oneone;
//	string all[10];
//	//"zhongju.txt"
//
//	int i = 0, j = 0, n = 1;
//	//由第一行移动位数
//	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };
//
//
//	ofstream ofile;
//	ofile.open(filepath);
//
//	//生成数独
//	while (n <= sum) {
//		next_permutation(one.begin() + 1, one.end());//全排列
//		oneone = one + one;
//		//移动
//		for (i = 0; i < 9; i++) {
//			all[i] = oneone.substr(sequence[i], 9);
//		}
//		//写入
//		for (i = 0; i < 9; i++) {
//			for (j = 0; j < 8; j++) {
//				ofile << all[i][j];
//				ofile << ' ';
//			}
//			ofile << all[i][8] << endl;
//		}
//		if (n != sum) {
//			ofile << endl;
//		}
//		n++;
//	}
//	ofile.close();
//	printf("%d final Sudokus generated. filepath: %s\n", sum, filepath);
//	//printf("已生成%d个终局至文件%s.\n", sum, filepath);
//	return 1;
//}
//60次ofstream写入

int mainfun(int argc, char* argv[]) {
	char finalpath[50] = { FINALPATH };
	char questionpath[50] = { QUESTIONPATH };
	if (argc !=3) {
		printf("Please enter the correct command format. \nFor example:---------\n");
		printf("sudoku.exe -c Num:      final Sudoku number\n");
		printf("sudoku.exe -s filePath: solve Sudoku, filePath: file path of the question\n");
		printf("-----------------------------------------------------");
		/*printf("请输入正确命令格式.\n-----------例如：------------------\n");
		printf("sudoku.exe -c Num:生成Num个数独终局.\n");
		printf("sudoku.exe -s filePath:解数独,file为文件路径.\n");
		printf("-----------------------------------------------------");*/
		return 1;
	}
	//数独生成
	if (strcmp(argv[1], "-c") == 0) {
		int len = strlen(argv[2]);
		if (len > 7) {
			printf("The final Sudoku number must be an integer. Scope:0~1e6\n");
			//printf("生成数独终局数 必须为整数.范围：0~1e6\n");
			return 2;
		}
		for (int i = 0; i < len; i++) {
			if (argv[2][i] > '9' || argv[2][i] < '0') {
				printf("The final Sudoku number must be an integer. Scope:0~1e6\n");
				//printf("生成数独终局数 必须为整数.范围：0~1e6\n");
				return 2;
			}
		}
		int num = atoi(argv[2]);
		if (num > 1000000) {
			printf("The final Sudoku number   Maximum:1e6\n");
			//printf("生成数独终局数 最大为 1e6\n");
			return 2;
		}
		DWORD startTime = GetTickCount64();//计时开始
		generate_final(num, finalpath);
		DWORD endTime = GetTickCount64();//计时结束
		cout << "The run time is:" << endTime - startTime << "ms" << endl;
		return 0;
	}
	//解数独
	if (strcmp(argv[1], "-s") == 0) {
		int len = strlen(argv[2]);
		char solutionpath[150];
		strcpy_s(solutionpath, argv[1]);

		if (len >= 150) {
			printf("File name exceeds limited length, please enter the correct file name.\n");
			//printf("文件名超过限定长度，请输入正确文件名.\n");
			return 2;
		}
		slove_all(argv[2]);
		return 0;
	}

	if (strcmp(argv[1], "-q") == 0) {
		if (strcmp(argv[2], "all") == 0) {
			generate_queall();
			return 0;
		}
		int len = strlen(argv[2]);

		for (int i = 0; i < len; i++) {
			if (argv[2][i] > '9' || argv[2][i] < '0') {
				printf("The generate Sudoku number must be an integer. Scope:0~1e6\n");
				//printf("生成数独题目 必须为整数.范围：0~1e6\n");
				return 2;
			}
		}
		int num = atoi(argv[2]);
		if (num > 1000000) {
			printf("Please input a litter number.\n");
			return 2;
		}
		generate_que(num);
		printf("Generated %d question of sudoku.\n", num);
		return 0;
	}
	return 2;
}

int generate_final(int sum, char *filepath) {

	char one[] = "612345789";//初始行 6为(3+2)%9+1 
	char oneone[19];
	char all[9][9];//存储每个数独
	int i = 0, j = 0, n = 1, k = 0, s = 0, sign = 0;
	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };	//其他行由第一行移动位数

	memset(oneone, 0, sizeof(oneone));
	memset(final, 0, sizeof(final));

	ofstream ofile;
	ofile.open(filepath);
	//打开文件判断
	if (!ofile) {
		printf("Open final file error.\n");
		return 1;
	}
	//生成数独
	while (n <= sum) {

		sign++;
		next_permutation(one + 1, one + 9);//全排列

		strcpy(oneone, one);
		strcat(oneone, one);

		//移动
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				all[i][j] = oneone[j + sequence[i]];
			}
		}
		//写入		
		for (s = 0; s < 30; s++) {//30中不同行交换一组
			for (i = 0; i < 9; i++) {
				for (j = 0; j < 8; j++) {
					final[k] = all[swap_line[s][i]][j];
					k++;
					final[k] = ' ';
					k++;
				}
				final[k] = all[swap_line[s][i]][8];//实现交换行
				k++;
				final[k] = '\n';
				k++;
			}
			if (n != sum) {
				final[k] = '\n';
				k++;
			}
			else {
				final[k] = '\0';
				ofile << final;
				ofile.close();
				printf("%d final sudokus generated. filepath: %s\n", sum, filepath);
				//printf("已生成%d个终局至文件%s.\n", sum, filepath);
				return 0;
			}
			n++;
		}
		if (sign == 2) { //2*30次写入文件
			ofile << final;
			sign = 0;
			k = 0;
		}
	}
	return 0;
}

//fputs写入方式60
int generate_final_1(int sum, char *filepath) {

	char one[] = "612345789";//初始行
	char oneone[19];
	char all[9][9];
	int i = 0, j = 0, n = 1, k = 0, s = 0, sign = 0;
	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };	//由第一行移动位数

	memset(oneone, 0, sizeof(oneone));

	FILE *pfile;
	if ((pfile = fopen(filepath, "w")) == NULL) {
		printf("open final file path error.\n");
		return 0;
	}
	/*ofstream ofile;
	ofile.open(filepath);*/

	//生成数独
	while (n <= sum) {
		sign++;
		next_permutation(one + 1, one + 9);//全排列

		strcpy(oneone, one);
		strcat(oneone, one);

		//移动
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				all[i][j] = oneone[j + sequence[i]];
			}
		}
		//写入		
		for (s = 0; s < 30; s++) {

			for (i = 0; i < 9; i++) {
				for (j = 0; j < 8; j++) {

					final[k] = all[swap_line[s][i]][j];
					k++;
					final[k] = ' ';
					k++;
				}
				final[k] = all[swap_line[s][i]][8];
				k++;
				final[k] = '\n';
				k++;
			}

			//ofile << final;
			if (n != sum) {
				//ofile << endl;
				final[k] = '\n';
				k++;
			}
			else {
				final[k] = '\0';
				fputs(final, pfile);
				fclose(pfile);
				printf("%d final sudokus generated. filepath: %s\n", sum, filepath);
				//printf("已生成%d个终局至文件%s.\n", sum, filepath);
				return 1;
			}
			n++;
		}
		if (sign == 2) {
			fputs(final, pfile);
			sign = 0;
			k = 0;
		}

	}
	return 1;
}

////string
//int generate_final(int sum, char *filepath) {
//
//	/*char *finall = NULL;
//	finall = new char[200000005];*/
//
//	string one = { "612345789" };//初始行
//	string oneone;
//	//char final[2000010];
//
//	DWORD startTime = GetTickCount();//计时开始
//	memset(final, 0, sizeof(final));
//	DWORD endTime = GetTickCount();//计时结束
//	cout << "The memset time is:" << endTime - startTime << "ms" << endl;
//
//	string all[10];
//	int i = 0, j = 0, n = 1, k = 0, s = 0;
//	//由第一行移动位数
//	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };
//	char temp;
//	ofstream ofile;
//	ofile.open(filepath);
//
//	//生成数独
//	while (n <= sum) {
//		//k = 0;
//
//		next_permutation(one.begin() + 1, one.end());//全排列
//		oneone = one + one;
//		//移动
//		for (i = 0; i < 9; i++) {
//			all[i] = oneone.substr(sequence[i], 9);
//		}
//		//swap_string(all[4], all[5]);
//		//写入
//
//		for (s = 0; s < 30; s++) {
//			k = 0;
//			for (i = 0; i < 9; i++) {
//				for (j = 0; j < 8; j++) {
//					temp = swap_line[s][i];
//					final[k] = all[temp][j];
//					k++;
//					final[k] = ' ';
//					k++;
//				}
//				final[k] = all[i][8];
//				k++;
//				final[k] = '\n';
//				k++;
//			}
//			//ofile << final;
//			if (n != sum) {
//				//ofile << endl;
//				final[k] = '\n';
//				k++;
//			}
//			else {
//				ofile << final;
//				ofile.close();
//				printf("%d final sudokus generated. filepath: %s\n", sum, filepath);
//				//printf("已生成%d个终局至文件%s.\n", sum, filepath);
//				return 1;
//			}
//			n++;
//		}
//		ofile << final;
//
//
//	}
//	ofile.close();
//	printf("%d final sudokus generated. filepath: %s\n", sum, filepath);
//	//printf("已生成%d个终局至文件%s.\n", sum, filepath);
//	return 1;
//}

 //fwrite
//int generate_final(int sum, char *filepath) {
//
//	/*char *finall = NULL;
//	finall = new char[200000005];*/
//
//	string one = { "612345789" };//初始行
//	string oneone;
//	//char final[2000010];
//
//	DWORD startTime = GetTickCount();//计时开始
//	memset(final, 0, sizeof(final));
//	DWORD endTime = GetTickCount();//计时结束
//	cout << "The memset time is:" << endTime - startTime << "ms" << endl;
//	//generate_que(5);
//	//memset(final, 0, sizeof(final));
//	string all[10];
//	int i = 0, j = 0, n = 1, k = 0, s = 0;
//	//由第一行移动位数
//	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };
//
//	FILE *pFile;
//	if ((pFile = fopen(filepath, "w")) == NULL){
//		printf("open final file path error.\n");
//		return 0;
//	}
//	int count = sum * 162 + sum - 1;
//	//生成数独
//	while (n <= sum) {
//		//k = 0;
//		next_permutation(one.begin() + 1, one.end());//全排列
//		oneone = one + one;
//		//移动
//		for (i = 0; i < 9; i++) {
//			all[i] = oneone.substr(sequence[i], 9);
//		}
//		//写入
//
//		for (s = 0; s < 30; s++) {
//			for (i = 0; i < 9; i++) {
//				for (j = 0; j < 8; j++) {
//					final[k] = all[swap_line[s][i]][j];
//					k++;
//					final[k] = ' ';
//					k++;
//				}
//				final[k] = all[i][8];
//				k++;
//				final[k] = '\n';
//				k++;
//			}
//			
//			if (n != sum) {
//			
//				final[k] = '\n';
//				k++;
//			}
//			else {
//				fwrite(final, sizeof(char), count, pFile);
//				fclose(pFile);				
//				printf("%d final sudokus generated. filepath: %s\n", sum, filepath);
//				//printf("已生成%d个终局至文件%s.\n", sum, filepath);
//				return 1;
//			}
//			//fwrite(final, sizeof(char), 6050, pFile);
//			n++;
//		}
//
//	}
//	
//	printf("%d final sudokus generated. filepath: %s\n", sum, filepath);
//	//printf("已生成%d个终局至文件%s.\n", sum, filepath);
//	return 1;
//}

int generate_que(int num_solution) {
	char finalpath[] = FINALPATH;
	int i = 0, j = 0, jj = 0, k;
	int degree = 5;//难度级别，即有0.degree的空
	string line;
	char all[9][9];

	ifstream ifile;
	ofstream ofile;
	ifile.open(FINALPATH);//从终局 FINALPATH 中产生题目

	if (!ifile) {
			printf("Open final file error.\n");
			return 1;
		}
	ifile.close();
	//判断生成的数目是否大于终局的数目
	int sumline=linenum(finalpath);
	if (sumline < num_solution) {
		printf("ERROR:num_solution is greater than final sudoku number.\n");
		return 2;
	}

	ifile.open(FINALPATH);//从终局 FINALPATH 中产生题目
	ofile.open(QUESTIONPATH);//将问题输出到 QUESTIONPATH

	for (k = 0; k < num_solution; k++) {
		//读终局文件
		srand((unsigned int)time(NULL));
		for (i = 0; i < 9; i++) {
			getline(ifile, line);
			for (j = 0, jj = 0; j < 8; j++) {

				if (rand() % 10 >= degree) { //50%的概率为空
					all[i][j] = '0';
					ofile << all[i][j] << ' ';
				}
				else {
					all[i][j] = line[jj];
					ofile << all[i][j] << ' ';//写入
				}
				jj = jj + 2;
			}

			all[i][j] = line[jj];//最后一个数
			//最后一行无空行
			ofile << all[i][j];
			if (i < 8) {
				ofile << endl;
			}
		}
		if (k != num_solution - 1) {
			ofile << endl << endl;//最后空行
		}
		getline(ifile, line);
	}
	ofile.close();
	ifile.close();
	printf("Having  generated %d sodoku questions.\n", num_solution);
	return 0;
	////输出到cout
	//for (i = 0; i < 9; i++) {
	//	for (j = 0; j < 9; j++) {			
	//		cout << all[i][j];
	//	}			
	//	cout << endl;
	//}
	//cout << endl;

	/*for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			question[i][j] = all[i][j];
		}
	}*/

	/* //给定特定数量的空
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
	}*/
}

int generate_queall() {
	//string filepath = FINALPATH;
	int i = 0, j = 0, jj = 0;
	int count = 0;
	int degree = 5;//难度级别，即有0.degree的空
	string line;
	char all[9][9];

	ifstream ifile;
	ofstream ofile;
	ifile.open(FINALPATH);//从终局 FINALPATH 中产生题目
	ofile.open(QUESTIONPATH);//将问题输出到 QUESTIONPATH
	
	if (!ifile) {
		printf("Open final file error.\n");
		return 1;
	}
	ifile.get();
	if (ifile.eof()) {
		printf("error: file is empty.\n");
		return 2;
	}
	ifile.seekg(0, ios::beg);//将文件指针定位到开头

	while(++count) {
		//读终局文件
		srand((unsigned int)time(NULL));
		for (i = 0; i < 9; i++) {
			getline(ifile, line);
			for (j = 0, jj = 0; j < 8; j++) {

				if (rand() % 10 >= degree) { //50%的概率为空
					all[i][j] = '0';
					ofile << all[i][j] << ' ';
				}
				else {
					all[i][j] = line[jj];
					ofile << all[i][j] << ' ';//写入
				}
				jj = jj + 2;
			}

			all[i][j] = line[jj];//最后一个数
			//最后一行无空行
			ofile << all[i][j];
			if (i < 8) {
				ofile << endl;
			}
		}
		getline(ifile, line);
		if (!ifile.eof()) {
			ofile << endl << endl;//最后空行
		}
		else {
			ofile.close();
			ifile.close();
			printf("Having  generated %d sodoku questions.\n", count);
			return 0;
		}
	}
	return 0;
}

int slove_all_1(char *filepath) {
	string line;
	//char question[9][9];
	int count = 0, i, j, jj;
	int end = 0;//0为不是末尾
	ifstream ifile;
	ofstream ofile;
	ifile.open(filepath);//从filepath 中得到题目
	ofile.open(SOLUTIONPATH);//将解输出到solutionpath

	if (!ifile) {
		printf("Open question file error.\n");
		return 2;
	}
	//判断是否为空
	ifile.get();
	if (ifile.eof()) {
		printf("error: file is empty.\n");
		return 0;
	}
	ifile.seekg(0, ios::beg);//将文件指针定位到开头
	while (++count) {

		for (i = 0; i < 9; i++) {
			getline(ifile, line);
			for (j = 0, jj = 0; j < 9; j++) {
				question[i][j] = line[jj];
				jj = jj + 2;
			}
		}
		if (ifile.eof()) {
			end = 1;

		}
		else {
			getline(ifile, line);
		}

		if (slove(question, 0, 0)) {
			printf("%dnd sudoku solution completed.\n", count);
			//printf("第%d个数独 解完成.\n", count);
			for (i = 0; i < 9; i++) {
				for (j = 0; j < 8; j++) {
					ofile << question[i][j] << ' ';
				}
				ofile << question[i][j] << endl;
			}
		}
		else {
			printf("%dnd sudoku solution is not exist.\n", count);
			//printf("第%d个数独 无解.\n", count);
		}
		if (end == 1) {
			break;
		}
		else {
			ofile << endl;
		}
	}
	printf("solving sudoku is over. sum is %d\n", count);
	//printf("数独解完成,共%d个.\n", count);
	return 1;
}

//优化文件读写
int slove_all(char *filepath) {
	string line;
	//char question[9][9];
	int count = 0, i, j, jj, k = 0;
	int end = 0;//0为不是末尾
	char solution[200];
	ifstream ifile;
	ofstream ofile;
	ifile.open(filepath);//从filepath 中得到题目
	ofile.open(SOLUTIONPATH);//将解输出到SOLUTIONPATH

	if (!ifile) {
		printf("Open question file error.\n");
		return 1;
	}
	//判断是否为空
	ifile.get();
	if (ifile.eof()) {
		printf("error: File is empty.\n");
		return 2;
	}
	ifile.seekg(0, ios::beg);//将文件指针定位到开头
	while (++count) {
		//读取一个数独
		for (i = 0; i < 9; i++) {
			getline(ifile, line);
			for (j = 0, jj = 0; j < 9; j++) {
				question[i][j] = line[jj];
				jj = jj + 2;
			}
		}
		if (ifile.eof()) {
			end = 1;
		}
		else {
			getline(ifile, line);
		}
		//解数独
		if (slove(question, 0, 0)) {
			k = 0;
			//printf("%dnd sudoku solution completed.\n", count);
			for (i = 0; i < 9; i++) {
				for (j = 0; j < 8; j++) {

					solution[k] = question[i][j];
					k++;
					solution[k] = ' ';
					k++;
				}
				solution[k] = question[i][8];
				k++;
				solution[k] = '\n';
				k++;
			}
		}
		else { //无解
			printf("%dnd sudoku solution is not exist.\n", count);
			//printf("第%d个数独 无解.\n", count);
		}
		//末尾处理
		if (end == 1) {
			solution[k] = '\0';
			ofile << solution;
			break;
		}
		else {
			solution[k] = '\n';
			k++;
			solution[k] = '\0';
			ofile << solution;
		}
	}
	printf("Solving sudoku is over. sum is %d\n", count);
	//printf("数独解完成,共%d个.\n", count);
	return 0;
}

int slove(char que[][9], int x, int y) {

	int value;
	int next_x, next_y;

	next_x = x;
	next_y = y;
	//下一个位置
	if (y != 8) {
		next_y++;
	}
	else if (y == 8) {
		if (x == 8)
			;
		else {
			next_y = 0;
			next_x++;
		}
	}
	//边界判断
	if (que[x][y] != '0') {
		if (x == 8 && y == 8) {
			return 1;
		}
		if (slove(que, next_x, next_y) == 1) {
			return 1;
		}
		else return 0;
	}
	//递归深搜
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

int isvalue(int x, int y, int value) {
	int a, b;
	int i = 0, j = 0;
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

int linenum(char *filepath) {
	ifstream ifile;
	ifile.open(filepath);
	string line;
	int sum = 0;
	ifile.get();
	if (ifile.eof()) {
		return 0;
	}
	ifile.seekg(0, ios::beg);//将文件指针定位到开头
	while (++sum) {
		getline(ifile, line);
		if (ifile.eof()) {
			ifile.close();
			return sum;
		}
	}
}

// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

//#include "pch.h"

// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。