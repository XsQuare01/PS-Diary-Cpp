#include<string>
#include <iostream>
#include<stack>

using namespace std;

stack<int> st;

bool solution(string s)
{
    bool answer = true;

    int len = s.length();
    for(int i = 0; i < len; i++){
        int v;
        if(s[i] == '('){
            v = 1;
        }
        if(s[i] == ')'){
            v = 0;
        }
        
        if(st.empty()){
            st.push(v);
            continue;
        }
        int u = st.top();
        
        if(u == 1 && v == 0){
            st.pop();
            continue;
        }
        st.push(v);
    }
    
    if(!st.empty()){
        answer = false;
    }

    return answer;
}