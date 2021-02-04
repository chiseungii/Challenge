#include <iostream>
#include <vector>
#include <string>
using namespace std;

int distances[12][12];

void init_dist() {
	distances[1][2] = distances[3][2] = 1;
	distances[1][5] = distances[3][5] = 2;
	distances[1][8] = distances[3][8] = 3;
	distances[1][0] = distances[3][0] = 4;

	distances[4][2] = distances[6][2] = 2;
	distances[4][5] = distances[6][5] = 1;
	distances[4][0] = distances[6][0] = 3;
	distances[4][8] = distances[6][8] = 2;

	distances[7][2] = distances[9][2] = 3;
	distances[7][5] = distances[9][5] = 2;
	distances[7][8] = distances[9][8] = 1;
	distances[7][0] = distances[9][0] = 2;

	distances[10][2] = distances[11][2] = 4;
	distances[10][5] = distances[11][5] = 3;
	distances[10][8] = distances[11][8] = 2;
	distances[10][0] = distances[11][0] = 1;

	distances[2][5] = 1;
	distances[2][8] = 2;
	distances[2][0] = 3;

	distances[5][2] = distances[5][8] = 1;
	distances[5][0] = 2;

	distances[8][2] = 2;
	distances[8][5] = distances[8][0] = 1;

	distances[0][2] = 3;
	distances[0][5] = 2;
	distances[0][8] = 1;
}

string solution(vector<int> numbers, string hand) {
	bool left = hand == "left" ? true : false;	// 왼손잡이인지?

	int left_hand = 10;		// 처음 왼손 엄지손가락 (* = 10)
	int right_hand = 11;	// 처음 오른손 엄지손가락 (# = 11)

	string result = "";		// 결과 저장

	init_dist();

	for(int i=0; i<numbers.size(); i++) {
		int number = numbers[i];

		if (number == 1 || number == 4 || number == 7) {
			result += 'L';
			left_hand = number;
		}
		else if(number==3 || number==6 || number==9) {
			result += 'R';
			right_hand = number;
		}
		else {
			// 움직이는 거리가 같으면
			if(distances[left_hand][number] == distances[right_hand][number]) {
				if(left) {
					result += 'L';
					left_hand = number;
				}
				else {
					result += 'R';
					right_hand = number;
				}
			}
			else if(distances[left_hand][number] < distances[right_hand][number]) {
				result += 'L';
				left_hand = number;
			}
			else {
				result += 'R';
				right_hand = number;
			}
		}
	}

	return result;
}
