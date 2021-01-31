#include <iostream>
#include <string>
using namespace std;

string delete_dont(string id){
    string result = "";
    
    for(int i=0; i<id.length(); i++){
        bool check = isalpha(id[i]) || isdigit(id[i]) || id[i] == '-' || id[i] == '_' || id[i] == '.';
        if(check) result += id[i];
    }
    
    return result;
}

string dot(string id){
    bool flag = false;
    string result = "";
    
    for(int i=0; i<id.length(); i++){
        if(id[i] == '.'){
            if(flag) continue;
            else{
                flag = true;
                result += '.';
            }
        }
        else{
            flag = false;
            result += id[i];
        }
    }
    
    return result;
}

string solution(string new_id){
    // 1. 모든 대문자를 소문자로 치환
    for(int i=0; i<new_id.length(); i++){
        if(isalpha(new_id[i]) && isupper(new_id[i]))
            new_id[i] = tolower(new_id[i]);
    }
    
    // 2. 불가능한 문자 모두 제거
    new_id = delete_dont(new_id);
    
    // 3. 마침표(.)가 2번 이상인 부분을 하나로 치환
    new_id = dot(new_id);
    
    // 4. 마침표(.)가 처음이나 끝에 위치하면 제거
    if(new_id.length() && new_id[0] == '.') new_id = new_id.substr(1);
    if(new_id.length() && new_id[new_id.length() - 1] == '.')
        new_id = new_id.substr(0, new_id.length() - 1);
    
    // 5. 빈 문자열이면 a 대입
    if(new_id.length() == 0) new_id = "a";
    
    // 6. 16자 이상이면 15자 제외하고 모두 삭제
    if(new_id.length() >= 16) new_id = new_id.substr(0, 15);
    
    // 삭제 후 마침표(.)가 끝에 있으면 제거
    if(new_id[new_id.length() - 1] == '.')
        new_id = new_id.substr(0, new_id.length() - 1);
    
    // 7. 2자 이하면 마지막 문자를 길이가 3이 될 때까지 반복해서 붙임
    while(new_id.length() <= 2) new_id += new_id[new_id.length() - 1];
    
    return new_id;
}
