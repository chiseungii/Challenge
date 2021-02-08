#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// const int MAX_COST = 1e8;

int di[4] = { 1, 0, -1, 0 };		// 하, 우, 상, 좌
int dj[4] = { 0, 1, 0, -1 };

int change_dir[3] = { 0, 1, -1 };	// 직진, 좌회전, 우회전

char check[25][25][4];				// 중복 체크용

class Block {
public:
	int i, j;
	int dir;
	int cost;

	Block(int i, int j, int dir, int cost) {
		this->i = i;
		this->j = j;
		this->dir = dir;
		this->cost = cost;
	}
};

int solution(vector<vector<int>> board) {
	int N = board.size();		// N x N
	vector<vector<int>> costs;	// BFS 돌릴 벡터

	// costs 벡터 초기화
	for(int i=0; i<N; i++) {
		vector<int> cost;
		for (int j = 0; j < N; j++)
			cost.push_back(0);
		costs.push_back(cost);
	}
	
	// (0, 0) 초기화
	// costs[0][0] = 0;
	// (0, 1), (1, 0) 초기화
	costs[0][1] = costs[1][0] = 100;

	queue<Block> blocks;	// 큐 생성

	// 초기 원소 삽입
	blocks.push(Block(0, 1, 1, 0));
	blocks.push(Block(1, 0, 0, 0));

	// check 초기화
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 25; j++)
			for (int k = 0; k < 4; k++)
				check[i][j][k] = 0;

	// BFS
	while(blocks.size()) {
		Block block = blocks.front();
		blocks.pop();

		// 마지막 지점이면 건너뛰기
		if (block.i == N - 1 && block.j == N - 1)
			continue;

		for(int i=0; i<3; i++) {
			int dir = change_dir[i];	// 직진 or 좌회전 or 우회전
			int move_dir = block.dir + dir;	// 상, 하, 좌, 우

			if (move_dir < 0) move_dir += 4;
			if (move_dir > 3) move_dir -= 4;

			int move_i = block.i + di[move_dir];
			int move_j = block.j + dj[move_dir];

			// 범위를 벗어난 경우
			if (move_i < 0 || move_i >= N) continue;
			else if (move_j < 0 || move_j >= N) continue;
			// 아니면 체크
			else if(!board[move_i][move_j]) {
				int change_cost = costs[block.i][block.j];
				
				// 직진이면 +100
				if (dir == 0) change_cost += 100;
				// 아니면 +600
				else change_cost += 600;

				// 처음 가거나 가격이 작아지거나 같으면 등록
				if (costs[move_i][move_j] == 0 || costs[move_i][move_j] > change_cost) {
					costs[move_i][move_j] = change_cost;

					if (!check[move_i][move_j][move_dir]) {
						blocks.push(Block(move_i, move_j, move_dir, change_cost));
						check[move_i][move_j][move_dir] = 1;
					}
				}
			}
		}
	}

	return costs[N - 1][N - 1];
}
