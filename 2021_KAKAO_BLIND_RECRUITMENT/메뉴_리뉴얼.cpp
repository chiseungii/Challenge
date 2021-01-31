#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    // 주문된 메뉴를 알파벳 정렬해서 다시 벡터로 만듦
    vector<vector<char>> sorted_orders;

    for (int i = 0; i < orders.size(); i++) {
        string tmp = orders[i];

        vector<char> order;
        for (int j = 0; j < tmp.length(); j++)
            order.push_back(tmp[j]);
        sort(order.begin(), order.end());

        sorted_orders.push_back(order);
    }

    vector<string> result;  // 최종 메뉴 저장될 벡터
    int max_orders;         // 제일 많이 주문한 수

    // course 수만큼 반복
    for (int i = 0; i < course.size(); i++) {
        int num_course = course[i]; // 메뉴 수
        vector<string> courses[20]; // 메뉴 조합 저장할 벡터

        // 조합 저장
        for (int j = 0; j < sorted_orders.size(); j++) {
            if (sorted_orders[j].size() >= num_course) {
                vector<char> combination;   // 조합 만들 벡터

                for (int k = 0; k < num_course; k++)
                    combination.push_back(1);
                for (int k = 0; k < sorted_orders[j].size() - num_course; k++)
                    combination.push_back(0);

                vector<char> before = combination;  // 종료 조건 저장

                while (1) {
                    string cmb = "";    // 조합 문자열

                    for (int k = 0; k < combination.size(); k++) {
                        if (combination[k]) cmb += sorted_orders[j][k];
                    }

                    // 조합 저장
                    courses[j].push_back(cmb);

                    // 다음 조합
                    prev_permutation(combination.begin(), combination.end());

                    // 종료 조건
                    if (combination == before) break;
                }
            }
        }

        // 주문 수 초기화
        max_orders = 2;
        vector<string> tmp_result;  // 중간 결과

        for (int j = 0; j < orders.size() - 1; j++) {
            for (int k = 0; k < courses[j].size(); k++) {
                int cnt = 1;
                for (int m = j + 1; m < orders.size(); m++) {
                    for (int n = 0; n < courses[m].size(); n++) {
                        if (courses[m][n] == courses[j][k]){
                            cnt++;
                            courses[m].erase(courses[m].begin() + n);
                            break;
                        }
                    }
                }

                if (cnt == max_orders) tmp_result.push_back(courses[j][k]);
                else if (cnt > max_orders) {
                    max_orders = cnt;
                    tmp_result.clear();
                    tmp_result.push_back(courses[j][k]);
                }
            }
        }

        // 최종 저장
        for (int j = 0; j < tmp_result.size(); j++)
            result.push_back(tmp_result[j]);
    }

    // 정렬
    sort(result.begin(), result.end());

    return result;
}
