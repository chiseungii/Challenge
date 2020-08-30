#include <iostream>
#include <vector>
using namespace std;

// char boards[30][30];
char check[30][30];		// 없어지는 블록 체크

void organize(int m, int n, vector<string> &board) {
	// 맨 왼쪽부터 채우기
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			if (board[j][i] == ' ') {
				int index = j - 1;
				for (; index >= 0 && board[index][i] == ' '; index--);
				if (index == -1) break;
				board[j][i] = board[index][i];
				board[index][i] = ' ';
			}
		}
	}
}

int solution(int m, int n, vector<string> board) {
	/*
	// 판에 채워넣기
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			boards[i][j] = board[i][j];
	*/

	// 반복문
	int del_cnt = 0;
	while (1) {
		/*
		// init
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				check[i][j] = 0;
		*/

		// 없어지는 블록 없으면 종료
		bool no_bump = true;
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (board[i][j] == ' ') continue;
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j]
					&& board[i][j] == board[i + 1][j + 1]) {
					check[i][j] = check[i][j + 1] = 1;
					check[i + 1][j] = check[i + 1][j + 1] = 1;
					no_bump = false;
				}
			}
		}
		if (no_bump) break;

		// 체크된 블록 지우기
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j]) {
					board[i][j] = ' ';
					del_cnt++;
					check[i][j] = 0;
				}
			}
		}

		// 정리
		organize(m, n, board);
	}

	return del_cnt;
}
