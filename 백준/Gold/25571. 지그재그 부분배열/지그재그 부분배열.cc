#define MAX 200000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int T, N;
long long res;
vector<int> arr;

pair<int, long long> Zig(int st){
    int init = st;
    int ed = st + 1;
    if(arr[st] == arr[ed]){
        return {ed, 0};
    }
    bool up = arr[st] < arr[ed] ? true : false;
    while(true){
        st++;
        ed++;
        if(ed == N){
            break;
        }
        if(up && arr[st] < arr[ed]){
            break;
        }
        else if(!up && arr[st] > arr[ed]){
            break;
        }
        else if(arr[st] == arr[ed]){
            break;
        }
        up = !up;
    }

    return {st, 1LL * (ed - init - 1) * (ed - init) / 2};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        // Init
        arr = vector<int>();
        res = 0;

        cin >> N;
        for(int j = 0; j < N; j++){
            int t;
            cin >> t;
            arr.push_back(t);
        }

        for(int j = 0; j < N-1;){
            auto a = Zig(j);
            j = a.first;
            res += a.second;
        }

        cout << res << "\n";
    }

    return 0;
}