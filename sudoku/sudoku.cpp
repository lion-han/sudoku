#include "head.h"

int main(int argc, char* argv[])
{
	
	char finalpath[50] = { FINALPATH };
	char questionpath[50] = { QUESTIONPATH };

	//DWORD startTime = GetTickCount();//计时开始
	//generate_final(1000, finalpath);
	//DWORD endTime = GetTickCount();//计时结束
	//cout << "The run time is:" << endTime - startTime << "ms" << endl;

	/*if (value_file(40, finalpath)) {
		cout << "valuable\n";
	}*/
	//generate_queall();
	//generate_final(0, finalpath);
	//generate_que(5);
	//slove_all(questionpath);

	//return 0;
	if (argc >= 4) {
		printf("Please enter the correct command format. \nFor example:---------\n");
		printf("sudoku.exe -c Num:      final Sudoku number\n");
		printf("sudoku.exe -s filePath: solve Sudoku, filePath: file path of the question\n");
		printf("-----------------------------------------------------");
		/*printf("请输入正确命令格式.\n-----------例如：------------------\n");
		printf("sudoku.exe -c Num:生成Num个数独终局.\n");
		printf("sudoku.exe -s filePath:解数独,file为文件路径.\n");
		printf("-----------------------------------------------------");*/
		return 0;
	}
	//数独生成
	if (strcmp(argv[1], "-c") == 0) {
		//printf("lalalal.\n");
		int len = strlen(argv[2]);
		if (len > 7) {
			printf("The final Sudoku number must be an integer. Scope:0~1e6\n");
			//printf("生成数独终局数 必须为整数.范围：0~1e6\n");
			return 0;
		}
		for (int i = 0; i < len; i++) {
			if (argv[2][i] > '9' || argv[2][i] < '0') {
				printf("The final Sudoku number must be an integer. Scope:0~1e6\n");
				//printf("生成数独终局数 必须为整数.范围：0~1e6\n");
				return 0;
			}
		}
		int num = atoi(argv[2]);
		if (num > 1000000) {
			printf("The final Sudoku number   Maximum:1e6\n");
			//printf("生成数独终局数 最大为 1e6\n");
			return 0;
		}
		DWORD startTime = GetTickCount64();//计时开始
		generate_final(num, finalpath);
		DWORD endTime = GetTickCount64();//计时结束
		cout << "The run time is:" << endTime - startTime << "ms" << endl;
	}
	//解数独
	if (strcmp(argv[1], "-s") == 0) {
		int len = strlen(argv[2]);
		char solutionpath[150];
		strcpy_s(solutionpath, argv[1]);

		if (len >= 150) {
			printf("File name exceeds limited length, please enter the correct file name.\n");
			//printf("文件名超过限定长度，请输入正确文件名.\n");
			return 0;
		}
		slove_all(argv[2]);
	}

	if (strcmp(argv[1], "-q") == 0) {
		if (strcmp(argv[2], "all") == 0){
			generate_queall();
			}
		int num = atoi(argv[2]);
		if (num > 1000000) {
			printf("Please input a litter number.\n");
			return 0;
		}
		generate_que(num);
		printf("Generated %d question of sudoku.\n",num);
		return 1;
	}

	/*generate();
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
	}*/
	return 0;
}





