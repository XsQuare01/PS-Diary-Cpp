#define MAX 1000

#include<bits/stdc++.h>

using namespace std;

int N, L, R = 0;
string arr[MAX];
int narr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    L = arr[0].length();
    for(int i = L-1; i >= 0; i--){
        R++;
        bool flag = true;
        set<string> st;
        for(int j = 0; j < N; j++){
            string str = arr[j].substr(i, L);
            if(st.find(str) != st.end()){
                flag = false;
                break;
            }
            st.insert(str);
        }
        if(flag){
            break;
        }
    }
    cout << R;
    return 0;
}