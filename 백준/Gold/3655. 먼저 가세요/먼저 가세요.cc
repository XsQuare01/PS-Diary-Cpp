#define MAX 200
#define MOD 1000000007
#define INF 128

#include<bits/stdc++.h>

using namespace std;

int T, N;
string S;
vector<int> vec[INF];
int arr[INF];
int prefix = 0;

void init(){
    for(int i = 0; i < INF; i++){
        vec[i] = vector<int>();
        arr[i] = 0;
    }
    prefix = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        init();
        cin >> N >> S;
        for(int j = 0; j < N; j++){
            int t = S[j];
            vec[t].push_back(j);
            arr[t] = j;
        }

        for(int j = 0; j < INF; j++){
            if(vec[j].empty() || vec[j].size() == 1){
                continue;
            }

            int len = vec[j].size();
            for(int k = 0; k < len; k++){
                prefix += arr[j] - vec[j][k] - (len - k - 1);
            }
        }

        cout << prefix * 5 << "\n";
    }

    return 0;
}