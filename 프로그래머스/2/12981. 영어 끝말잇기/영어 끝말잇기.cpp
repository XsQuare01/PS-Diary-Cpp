#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
vector<string> arr[26];

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int len = words.size();
    char last = words[0][0];
    int cnt = 1;
    for(int i = 0, idx = 1; i < len; i++, idx++){
        if(idx > n){
            idx = 1;
            cnt++;
        }
        
        if(last != words[i][0]){
            answer.push_back(idx);
            answer.push_back(cnt);
            return answer;
        }
        int tail = words[i].length() - 1;
        last = words[i][tail];
        
        int init = words[i][0] - 'a';
        for(auto a : arr[init]){
            if(a != words[i]){
                continue;
            }
            if(a == words[i]){
                answer.push_back(idx);
                answer.push_back(cnt);
                return answer;
            }
        }
        arr[init].push_back(words[i]);
    }
    
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}