#include "pch.h"
#include "../sudoku/head.h"
#define FINALPATH "final_sudoku.txt"
#define QUESTIONPATH "question.txt"
#define	SOLUTIONPATH "solution.txt"

bool value_file(int all, char *filepath);
bool isvalue_sudoku(char *filepath);


//TEST(GenerateTest, size0) {
//	generate_final(0, FINALPATH);
//	int sign = value_file(0, FINALPATH);
//	EXPECT_TRUE(sign);
//}
//TEST(GenerateTest, size1) {
//	generate_final(1, FINALPATH);
//	int sign = value_file(1, FINALPATH);
//	EXPECT_TRUE(sign);
//}
//TEST(GenerateTest, size50) {
//	generate_final(50, FINALPATH);
//	int sign = value_file(50, FINALPATH);
//	EXPECT_TRUE(sign);
//}
//TEST(GenerateTest, size1e6) {
//	generate_final(1000000, FINALPATH);
//	int sign = value_file(1000000, FINALPATH);
//	EXPECT_TRUE(sign);
//}
//
////���Խ������������ȷ�ԣ���֤������Ŀ�ļ�������Ŀ������������������Ŀ
//TEST(SolutionTest, answersright) {
//	ifstream ifile;
//	ifile.open(QUESTIONPATH);
//	if (!ifile) {
//		generate_que(10);
//	}
//	ifile.close();
//	slove_all(QUESTIONPATH);
//	int sign=isvalue_sudoku(SOLUTIONPATH);
//	EXPECT_TRUE(sign);
//}
////���Խ��������������ļ�������ʱ
//TEST(SolutionTest, nofile) {
//	char filename[] = "jjjj.txt";
//	int sign=slove_all(filename);
//	EXPECT_EQ(sign, 2);
//}
////���Խ��������������ļ�Ϊ��ʱ
//TEST(SolutionTest, emptyfile) {
//	char filename[] = "text_empty.txt";
//	ofstream ofile;
//	ofile.open(filename);
//	ofile.close();
//	int sign = slove_all(filename);
//	EXPECT_EQ(sign,3 );
//}


TEST(LineNum, size0) {
	char filename[] = "text_line.txt";
	ofstream ofile;
	ofile.open(filename);
	ofile.close();
	int sign = linenum(filename);
	EXPECT_EQ(sign, 0);
}
TEST(LineNum, size1) {
	char filename[] = "text_line.txt";
	ofstream ofile;
	ofile.open(filename);
	ofile << '1';
	ofile.close();
	int sign = linenum(filename);
	EXPECT_EQ(sign, 1);
}
TEST(LineNum, size1000) {
	char filename[] = "text_line.txt";
	ofstream ofile;
	ofile.open(filename);
	int temp = 999;
	ofile << '1';
	while (temp--) {
		ofile << '\n';
	}
	ofile.close();
	int sign = linenum(filename);
	EXPECT_EQ(sign, 1000);
}

int _tmain(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
//�ж���������all�Ƿ����
bool value_file(int all, char *filepath) {
	ifstream ifile;
	ifile.open(filepath);
	string line;
	int sum = 0, i = 1;
	while (i) {
		getline(ifile, line);
		if (ifile.eof()) {
			//cout << "File line is" << i << endl;
			ifile.close();
			if (i == all*10) {
				return 1;
			}
			else {
				return 0;
			}
		}
		i++;
	}
}
//�ж������Ƿ���ȷ,���һ���пո�
bool isvalue_sudoku(char *filepath) {
	string line;
	char solution[9][9];
	int count = 0, i, j, jj, k = 0;
	int end = 0;//0Ϊ����ĩβ
	int wrong = 0;
	ifstream ifile;	
	ifile.open(SOLUTIONPATH);//���������SOLUTIONPATH

	////�ж��Ƿ�Ϊ��
	//ifile.get();
	//if (ifile.eof()) {
	//	printf("error: File is empty.\n");
	//	return 0;
	//}
	ifile.seekg(0, ios::beg);//���ļ�ָ�붨λ����ͷ
	while (++count) {

		for (i = 0; i < 9; i++) {
			getline(ifile, line);
			for (j = 0, jj = 0; j < 9; j++) {
				question[i][j] = line[jj];
				jj = jj + 2;
			}
		}

		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++) {
				if (!isvalue(i, j, question[i][j])) {
					printf("%dth solution of sudoku is wrong.\n", count);
					wrong++;
					break;
				}
			}

		getline(ifile, line);
		if (ifile.eof()) {
			printf("Solutions number is %d\n", count);
			printf("Wrong solution number is %d\n", wrong);
			if (wrong == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
}
