#define MAX 500000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
string PS, CS;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        cin >> PS;
        if(PS == "#"){
            break;
        }

        int len = PS.length();
        bool flag = true;

        while(true){
            cin >> CS;
            if(CS == "#"){
                break;
            }

            if(len != CS.length()){
                flag = false;
            }
            
            int cnt = 0;
            for(int i = 0; i < len; i++){
                char pc = PS[i];
                char cc = CS[i];

                if(pc != cc){
                    cnt++;
                }
            }

            if(cnt != 1){
                flag = false;
            }

            PS = CS;
        }

        if(flag){
            cout << "Correct\n";
        }
        else{
            cout << "Incorrect\n";
        }
    }

    return 0;
}