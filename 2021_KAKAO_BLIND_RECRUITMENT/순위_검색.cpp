/*
처음엔 하나씩 다 비교해서 정확도만 통과하고 효율성은 하나도 통과 못 함.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> scores[108];            // 그룹화할 벡터
    int base[4] = { 27, 9, 3, 1 };

	// 그룹에 맞게 분류
    for(int i=0; i<info.size(); i++) {
        string tmp = info[i];

    	// 각 항목 분류
        istringstream ss(tmp);
        string buf;
    	
        int index = 0;
        string infos[5];    // 항목 저장할 배열
    	
        while (getline(ss, buf, ' '))
            infos[index++] = buf;

    	// 항목을 숫자로 바꿔서 다시 저장
        int infos_num[4];

    	// 개발언어
        if (infos[0] == "cpp") infos_num[0] = 1;
        else if (infos[0] == "java") infos_num[0] = 2;
        else infos_num[0] = 3;

    	// 직군
        if (infos[1] == "backend") infos_num[1] = 1;
        else infos_num[1] = 2;

    	// 경력
        if (infos[2] == "junior") infos_num[2] = 1;
        else infos_num[2] = 2;

    	// 소울푸드
        if (infos[3] == "chicken") infos_num[3] = 1;
        else infos_num[3] = 2;

    	// 점수
        int score = stoi(infos[4]);

    	// 0번째는 무조건 속함
        scores[0].push_back(score);

    	// base와 계산
        for (int i = 0; i < 4; i++) infos_num[i] *= base[i];

    	// 1개 포함된 그룹
        scores[infos_num[0]].push_back(score);    // 개발언어
        scores[infos_num[1]].push_back(score);    // 직군
        scores[infos_num[2]].push_back(score);    // 경력
        scores[infos_num[3]].push_back(score);    // 소울푸드

    	// 2개 포함된 그룹
        scores[infos_num[0] + infos_num[1]].push_back(score);   // 개발언어 + 직군
        scores[infos_num[0] + infos_num[2]].push_back(score);   // 개발언어 + 경력
        scores[infos_num[0] + infos_num[3]].push_back(score);   // 개발언어 + 소울푸드
        scores[infos_num[1] + infos_num[2]].push_back(score);   // 직군 + 경력
        scores[infos_num[1] + infos_num[3]].push_back(score);   // 직군 + 소울푸드
        scores[infos_num[2] + infos_num[3]].push_back(score);   // 경력 + 소울푸드

    	// 3개 포함된 그룹
        scores[infos_num[0] + infos_num[1] + infos_num[2]].push_back(score);    // 개발언어 + 직군 + 경력
        scores[infos_num[0] + infos_num[1] + infos_num[3]].push_back(score);    // 개발언어 + 직군 + 소울푸드
        scores[infos_num[0] + infos_num[2] + infos_num[3]].push_back(score);    // 개발언어 + 경력 + 소울푸드
        scores[infos_num[1] + infos_num[2] + infos_num[3]].push_back(score);    // 직군 + 경력 + 소울푸드

    	// 모두 포함된 그룹
        scores[infos_num[0] + infos_num[1] + infos_num[2] + infos_num[3]].push_back(score);
    }

    vector<int> result;     // 결과 저장할 벡터

	// 쿼리 실행
    for(int i=0; i<query.size(); i++) {
        string tmp = query[i];

        // 각 항목 분류
        istringstream ss(tmp);
        string buf;

        int index = 0;
        string q[8];    // 항목 저장할 배열

        while (getline(ss, buf, ' '))
            q[index++] = buf;
    	
    	// 항목을 숫자로 변환
        int q_nums[4];

        if (q[0] == "cpp") q_nums[0] = 1;
        else if (q[0] == "java") q_nums[0] = 2;
        else if (q[0] == "python") q_nums[0] = 3;
        else q_nums[0] = 0;

        if (q[2] == "backend") q_nums[1] = 1;
        else if (q[2] == "frontend") q_nums[1] = 2;
        else q_nums[1] = 0;

        if (q[4] == "junior") q_nums[2] = 1;
        else if (q[4] == "senior") q_nums[2] = 2;
        else q_nums[2] = 0;

        if (q[6] == "chicken") q_nums[3] = 1;
        else if (q[6] == "pizza") q_nums[3] = 2;
        else q_nums[3] = 0;

        int score = stoi(q[7]);

    	// 그룹 번호 구하기
        int group_num = 0;
        for (int j = 0; j < 4; j++)
            group_num += (q_nums[j] * base[j]);

    	// 카운팅
        int cnt = 0;

        for (int j = 0; j < scores[group_num].size(); j++)
            if (scores[group_num][j] >= score) cnt++;

        result.push_back(cnt);
    }

    return result;
}
