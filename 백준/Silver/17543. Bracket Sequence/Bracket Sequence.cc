#define MAX 300000
#define MOD 1000000007

#include<bits/stdc++.h>

using namespace std;

int N;
string input;
stack<long long> st;
int cnt = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        if(input == "("){
            st.push(-1);
            cnt++;
        }
        else if(input == ")"){
            long long tres = st.top();
            st.pop();

            if(tres == -1){
                continue;
                cnt--;
            }

            while(st.top() != -1){
                long long st_top = st.top();
                st.pop();

                if(cnt%2 == 0){ // plus
                    tres += st_top;
                    tres %= MOD;
                }
                if(cnt%2 == 1){ //time
                    tres *= st_top;
                    tres %= MOD;
                }
            }
            st.pop();   // '(' pop
            st.push(tres);
            cnt--;
        }
        else{
            long long num = stoll(input);
            st.push(num);
        }
    }

    long long res = st.top();
    st.pop();
    while(!st.empty()){
        long long s_top = st.top();
        st.pop();
        res += s_top;
    }

    cout << res % MOD;
    return 0;
}