
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
int slove_all(char *filepath);//�Ż��ļ���д
int slove_all_1(char *filepath);
int isvalue(int x, int y, int value);
int slove(char que[][9], int x, int y);
int linenum(char *filepath);


//��������12+��������34+����������45+����������35+����������12+34+����������12+45+����������12+35+67
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

//ofstreamд�뷽ʽ
//int generate_final(int sum, char *filepath) {
//
//	char one[] = "612345789";//��ʼ��
//	char oneone[19];
//	char all[9][9];
//	int i = 0, j = 0, n = 1, k = 0, s = 0;
//	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };	//�ɵ�һ���ƶ�λ��
//
//	memset(oneone, 0, sizeof(oneone));
//	memset(final, 0, sizeof(final));
//
//	ofstream ofile;
//	ofile.open(filepath);
//
//	//��������
//	while (n <= sum) {
//		k = 0;		
//		next_permutation(one+1 , one+9);//ȫ����
//
//		strcpy(oneone, one);
//		strcat(oneone, one);
//
//		//�ƶ�
//		for (i = 0; i < 9; i++) {
//			for (j = 0; j < 9; j++) {
//				all[i][j] = oneone[j + sequence[i]];
//			}
//		}
//		//д��		
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
//					//printf("������%d���վ����ļ�%s.\n", sum, filepath);
//					return 1;
//				}
//				n++;
//		}
//		ofile << final;			
//	}
//	return 1;
//}
//ֱ��д��
//int generate_final(int sum, char *filepath) {
//
//	string one = { "612345789" };//��ʼ��
//	string oneone;
//	string all[10];
//	//"zhongju.txt"
//
//	int i = 0, j = 0, n = 1;
//	//�ɵ�һ���ƶ�λ��
//	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };
//
//
//	ofstream ofile;
//	ofile.open(filepath);
//
//	//��������
//	while (n <= sum) {
//		next_permutation(one.begin() + 1, one.end());//ȫ����
//		oneone = one + one;
//		//�ƶ�
//		for (i = 0; i < 9; i++) {
//			all[i] = oneone.substr(sequence[i], 9);
//		}
//		//д��
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
//	//printf("������%d���վ����ļ�%s.\n", sum, filepath);
//	return 1;
//}
//60��ofstreamд��

int mainfun(int argc, char* argv[]) {
	char finalpath[50] = { FINALPATH };
	char questionpath[50] = { QUESTIONPATH };
	if (argc !=3) {
		printf("Please enter the correct command format. \nFor example:---------\n");
		printf("sudoku.exe -c Num:      final Sudoku number\n");
		printf("sudoku.exe -s filePath: solve Sudoku, filePath: file path of the question\n");
		printf("-----------------------------------------------------");
		/*printf("��������ȷ�����ʽ.\n-----------���磺------------------\n");
		printf("sudoku.exe -c Num:����Num�������վ�.\n");
		printf("sudoku.exe -s filePath:������,fileΪ�ļ�·��.\n");
		printf("-----------------------------------------------------");*/
		return 1;
	}
	//��������
	if (strcmp(argv[1], "-c") == 0) {
		int len = strlen(argv[2]);
		if (len > 7) {
			printf("The final Sudoku number must be an integer. Scope:0~1e6\n");
			//printf("���������վ��� ����Ϊ����.��Χ��0~1e6\n");
			return 2;
		}
		for (int i = 0; i < len; i++) {
			if (argv[2][i] > '9' || argv[2][i] < '0') {
				printf("The final Sudoku number must be an integer. Scope:0~1e6\n");
				//printf("���������վ��� ����Ϊ����.��Χ��0~1e6\n");
				return 2;
			}
		}
		int num = atoi(argv[2]);
		if (num > 1000000) {
			printf("The final Sudoku number   Maximum:1e6\n");
			//printf("���������վ��� ���Ϊ 1e6\n");
			return 2;
		}
		DWORD startTime = GetTickCount64();//��ʱ��ʼ
		generate_final(num, finalpath);
		DWORD endTime = GetTickCount64();//��ʱ����
		cout << "The run time is:" << endTime - startTime << "ms" << endl;
		return 0;
	}
	//������
	if (strcmp(argv[1], "-s") == 0) {
		int len = strlen(argv[2]);
		char solutionpath[150];
		strcpy_s(solutionpath, argv[1]);

		if (len >= 150) {
			printf("File name exceeds limited length, please enter the correct file name.\n");
			//printf("�ļ��������޶����ȣ���������ȷ�ļ���.\n");
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
				//printf("����������Ŀ ����Ϊ����.��Χ��0~1e6\n");
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

	char one[] = "612345789";//��ʼ�� 6Ϊ(3+2)%9+1 
	char oneone[19];
	char all[9][9];//�洢ÿ������
	int i = 0, j = 0, n = 1, k = 0, s = 0, sign = 0;
	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };	//�������ɵ�һ���ƶ�λ��

	memset(oneone, 0, sizeof(oneone));
	memset(final, 0, sizeof(final));

	ofstream ofile;
	ofile.open(filepath);
	//���ļ��ж�
	if (!ofile) {
		printf("Open final file error.\n");
		return 1;
	}
	//��������
	while (n <= sum) {

		sign++;
		next_permutation(one + 1, one + 9);//ȫ����

		strcpy(oneone, one);
		strcat(oneone, one);

		//�ƶ�
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				all[i][j] = oneone[j + sequence[i]];
			}
		}
		//д��		
		for (s = 0; s < 30; s++) {//30�в�ͬ�н���һ��
			for (i = 0; i < 9; i++) {
				for (j = 0; j < 8; j++) {
					final[k] = all[swap_line[s][i]][j];
					k++;
					final[k] = ' ';
					k++;
				}
				final[k] = all[swap_line[s][i]][8];//ʵ�ֽ�����
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
				//printf("������%d���վ����ļ�%s.\n", sum, filepath);
				return 0;
			}
			n++;
		}
		if (sign == 2) { //2*30��д���ļ�
			ofile << final;
			sign = 0;
			k = 0;
		}
	}
	return 0;
}

//fputsд�뷽ʽ60
int generate_final_1(int sum, char *filepath) {

	char one[] = "612345789";//��ʼ��
	char oneone[19];
	char all[9][9];
	int i = 0, j = 0, n = 1, k = 0, s = 0, sign = 0;
	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };	//�ɵ�һ���ƶ�λ��

	memset(oneone, 0, sizeof(oneone));

	FILE *pfile;
	if ((pfile = fopen(filepath, "w")) == NULL) {
		printf("open final file path error.\n");
		return 0;
	}
	/*ofstream ofile;
	ofile.open(filepath);*/

	//��������
	while (n <= sum) {
		sign++;
		next_permutation(one + 1, one + 9);//ȫ����

		strcpy(oneone, one);
		strcat(oneone, one);

		//�ƶ�
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				all[i][j] = oneone[j + sequence[i]];
			}
		}
		//д��		
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
				//printf("������%d���վ����ļ�%s.\n", sum, filepath);
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
//	string one = { "612345789" };//��ʼ��
//	string oneone;
//	//char final[2000010];
//
//	DWORD startTime = GetTickCount();//��ʱ��ʼ
//	memset(final, 0, sizeof(final));
//	DWORD endTime = GetTickCount();//��ʱ����
//	cout << "The memset time is:" << endTime - startTime << "ms" << endl;
//
//	string all[10];
//	int i = 0, j = 0, n = 1, k = 0, s = 0;
//	//�ɵ�һ���ƶ�λ��
//	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };
//	char temp;
//	ofstream ofile;
//	ofile.open(filepath);
//
//	//��������
//	while (n <= sum) {
//		//k = 0;
//
//		next_permutation(one.begin() + 1, one.end());//ȫ����
//		oneone = one + one;
//		//�ƶ�
//		for (i = 0; i < 9; i++) {
//			all[i] = oneone.substr(sequence[i], 9);
//		}
//		//swap_string(all[4], all[5]);
//		//д��
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
//				//printf("������%d���վ����ļ�%s.\n", sum, filepath);
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
//	//printf("������%d���վ����ļ�%s.\n", sum, filepath);
//	return 1;
//}

 //fwrite
//int generate_final(int sum, char *filepath) {
//
//	/*char *finall = NULL;
//	finall = new char[200000005];*/
//
//	string one = { "612345789" };//��ʼ��
//	string oneone;
//	//char final[2000010];
//
//	DWORD startTime = GetTickCount();//��ʱ��ʼ
//	memset(final, 0, sizeof(final));
//	DWORD endTime = GetTickCount();//��ʱ����
//	cout << "The memset time is:" << endTime - startTime << "ms" << endl;
//	//generate_que(5);
//	//memset(final, 0, sizeof(final));
//	string all[10];
//	int i = 0, j = 0, n = 1, k = 0, s = 0;
//	//�ɵ�һ���ƶ�λ��
//	int sequence[9] = { 0,3, 6, 2, 8, 5, 1, 7, 4 };
//
//	FILE *pFile;
//	if ((pFile = fopen(filepath, "w")) == NULL){
//		printf("open final file path error.\n");
//		return 0;
//	}
//	int count = sum * 162 + sum - 1;
//	//��������
//	while (n <= sum) {
//		//k = 0;
//		next_permutation(one.begin() + 1, one.end());//ȫ����
//		oneone = one + one;
//		//�ƶ�
//		for (i = 0; i < 9; i++) {
//			all[i] = oneone.substr(sequence[i], 9);
//		}
//		//д��
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
//				//printf("������%d���վ����ļ�%s.\n", sum, filepath);
//				return 1;
//			}
//			//fwrite(final, sizeof(char), 6050, pFile);
//			n++;
//		}
//
//	}
//	
//	printf("%d final sudokus generated. filepath: %s\n", sum, filepath);
//	//printf("������%d���վ����ļ�%s.\n", sum, filepath);
//	return 1;
//}

int generate_que(int num_solution) {
	char finalpath[] = FINALPATH;
	int i = 0, j = 0, jj = 0, k;
	int degree = 5;//�Ѷȼ��𣬼���0.degree�Ŀ�
	string line;
	char all[9][9];

	ifstream ifile;
	ofstream ofile;
	ifile.open(FINALPATH);//���վ� FINALPATH �в�����Ŀ

	if (!ifile) {
			printf("Open final file error.\n");
			return 1;
		}
	ifile.close();
	//�ж����ɵ���Ŀ�Ƿ�����վֵ���Ŀ
	int sumline=linenum(finalpath);
	if (sumline < num_solution) {
		printf("ERROR:num_solution is greater than final sudoku number.\n");
		return 2;
	}

	ifile.open(FINALPATH);//���վ� FINALPATH �в�����Ŀ
	ofile.open(QUESTIONPATH);//����������� QUESTIONPATH

	for (k = 0; k < num_solution; k++) {
		//���վ��ļ�
		srand((unsigned int)time(NULL));
		for (i = 0; i < 9; i++) {
			getline(ifile, line);
			for (j = 0, jj = 0; j < 8; j++) {

				if (rand() % 10 >= degree) { //50%�ĸ���Ϊ��
					all[i][j] = '0';
					ofile << all[i][j] << ' ';
				}
				else {
					all[i][j] = line[jj];
					ofile << all[i][j] << ' ';//д��
				}
				jj = jj + 2;
			}

			all[i][j] = line[jj];//���һ����
			//���һ���޿���
			ofile << all[i][j];
			if (i < 8) {
				ofile << endl;
			}
		}
		if (k != num_solution - 1) {
			ofile << endl << endl;//������
		}
		getline(ifile, line);
	}
	ofile.close();
	ifile.close();
	printf("Having  generated %d sodoku questions.\n", num_solution);
	return 0;
	////�����cout
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

	/* //�����ض������Ŀ�
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
	int degree = 5;//�Ѷȼ��𣬼���0.degree�Ŀ�
	string line;
	char all[9][9];

	ifstream ifile;
	ofstream ofile;
	ifile.open(FINALPATH);//���վ� FINALPATH �в�����Ŀ
	ofile.open(QUESTIONPATH);//����������� QUESTIONPATH
	
	if (!ifile) {
		printf("Open final file error.\n");
		return 1;
	}
	ifile.get();
	if (ifile.eof()) {
		printf("error: file is empty.\n");
		return 2;
	}
	ifile.seekg(0, ios::beg);//���ļ�ָ�붨λ����ͷ

	while(++count) {
		//���վ��ļ�
		srand((unsigned int)time(NULL));
		for (i = 0; i < 9; i++) {
			getline(ifile, line);
			for (j = 0, jj = 0; j < 8; j++) {

				if (rand() % 10 >= degree) { //50%�ĸ���Ϊ��
					all[i][j] = '0';
					ofile << all[i][j] << ' ';
				}
				else {
					all[i][j] = line[jj];
					ofile << all[i][j] << ' ';//д��
				}
				jj = jj + 2;
			}

			all[i][j] = line[jj];//���һ����
			//���һ���޿���
			ofile << all[i][j];
			if (i < 8) {
				ofile << endl;
			}
		}
		getline(ifile, line);
		if (!ifile.eof()) {
			ofile << endl << endl;//������
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
	int end = 0;//0Ϊ����ĩβ
	ifstream ifile;
	ofstream ofile;
	ifile.open(filepath);//��filepath �еõ���Ŀ
	ofile.open(SOLUTIONPATH);//���������solutionpath

	if (!ifile) {
		printf("Open question file error.\n");
		return 2;
	}
	//�ж��Ƿ�Ϊ��
	ifile.get();
	if (ifile.eof()) {
		printf("error: file is empty.\n");
		return 0;
	}
	ifile.seekg(0, ios::beg);//���ļ�ָ�붨λ����ͷ
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
			//printf("��%d������ �����.\n", count);
			for (i = 0; i < 9; i++) {
				for (j = 0; j < 8; j++) {
					ofile << question[i][j] << ' ';
				}
				ofile << question[i][j] << endl;
			}
		}
		else {
			printf("%dnd sudoku solution is not exist.\n", count);
			//printf("��%d������ �޽�.\n", count);
		}
		if (end == 1) {
			break;
		}
		else {
			ofile << endl;
		}
	}
	printf("solving sudoku is over. sum is %d\n", count);
	//printf("���������,��%d��.\n", count);
	return 1;
}

//�Ż��ļ���д
int slove_all(char *filepath) {
	string line;
	//char question[9][9];
	int count = 0, i, j, jj, k = 0;
	int end = 0;//0Ϊ����ĩβ
	char solution[200];
	ifstream ifile;
	ofstream ofile;
	ifile.open(filepath);//��filepath �еõ���Ŀ
	ofile.open(SOLUTIONPATH);//���������SOLUTIONPATH

	if (!ifile) {
		printf("Open question file error.\n");
		return 1;
	}
	//�ж��Ƿ�Ϊ��
	ifile.get();
	if (ifile.eof()) {
		printf("error: File is empty.\n");
		return 2;
	}
	ifile.seekg(0, ios::beg);//���ļ�ָ�붨λ����ͷ
	while (++count) {
		//��ȡһ������
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
		//������
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
		else { //�޽�
			printf("%dnd sudoku solution is not exist.\n", count);
			//printf("��%d������ �޽�.\n", count);
		}
		//ĩβ����
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
	//printf("���������,��%d��.\n", count);
	return 0;
}

int slove(char que[][9], int x, int y) {

	int value;
	int next_x, next_y;

	next_x = x;
	next_y = y;
	//��һ��λ��
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
	//�߽��ж�
	if (que[x][y] != '0') {
		if (x == 8 && y == 8) {
			return 1;
		}
		if (slove(que, next_x, next_y) == 1) {
			return 1;
		}
		else return 0;
	}
	//�ݹ�����
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
	//��
	for (i = 0; i < 9; i++) {
		if (question[x][i] == (value + '0')) {
			return 0;
		}
	}
	//��
	for (i = 0; i < 9; i++) {
		if (question[i][y] == (value + '0')) {
			return 0;
		}
	}

	//����
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
	ifile.seekg(0, ios::beg);//���ļ�ָ�붨λ����ͷ
	while (++sum) {
		getline(ifile, line);
		if (ifile.eof()) {
			ifile.close();
			return sum;
		}
	}
}

// pch.cpp: ��Ԥ�����ͷ��Ӧ��Դ�ļ�������ɹ��������

//#include "pch.h"

// һ������£����Դ��ļ����������ʹ�õ���Ԥ�����ͷ���뱣������