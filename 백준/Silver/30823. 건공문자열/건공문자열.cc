#define MAX 500000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, K;
string S;
stack<char> st;
queue<char> qu;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> S;
    int t;

    if((N+K)%2 == 0){
        for(int i = 0; i < K-1; i++){
            st.push(S[i]);
        }
    }
    else{
        for(int i = 0; i < K-1; i++){
            qu.push(S[i]);
        }
    }
    
    for(int i = K-1; i < N; i++){
        cout << S[i];
    }
    while(!st.empty()){
        char c = st.top();
        st.pop();
        cout << c;
    }
    while(!qu.empty()){
        char c = qu.front();
        qu.pop();
        cout << c;
    }
    

    return 0;
}