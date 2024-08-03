#define MAX 676
#define LEN 80
#define INF 1000000000
#define PI 3.141592653589793

#include <bits/stdc++.h>

using namespace std;

string S;
int len;
int hashing[MAX+1][LEN+1] = {0, };

void init(){
    for(int i = 0; i <= MAX; i++){
        for(int j = 0; j <= LEN; j++){
            hashing[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        cin >> S;
        if(S == "*"){
            break;
        }

        init();
        cout << S << " ";
        len = S.length();

        bool f = false;
        for(int i = 1; i < len; i++){

            for(int j = 0; j < len - i; j++){
                int c1 = S[j] - 'A';
                int c2 = S[j + i] - 'A';
                
                int t_hash = c1 * 26 + c2;

                if(hashing[t_hash][i]){
                    f = true;
                    break;
                }
                hashing[t_hash][i] = 1;
            }

            if(f){
                break;
            }
        }

        if(f){
            cout << "is NOT surprising.\n";
        }
        else{
            cout << "is surprising.\n";
        }
    }


    return 0;
}