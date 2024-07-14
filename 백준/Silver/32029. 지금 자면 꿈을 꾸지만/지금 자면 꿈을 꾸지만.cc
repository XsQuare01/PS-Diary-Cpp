#define MAX 100
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

long long N, A, B;
long long arr[MAX];
// int prefix[MAX];

long long times = 0;
long long res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> A >> B;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    for(int k = 0; k < N; k++){
        long long t_res = 0;
        long long t_times = 0;
        long long prefix = 0;
        for(int i = 0; i < k; i++){
            if(t_times + A <= arr[i]){
                t_times += A;
                prefix++;
            }
        }

        
        for(int i = 0; i < A; i++){
            long long t_a = A-i;
            long long tt_times = t_times + B*i;

            long long tt_res = prefix;
            for(int j = k; j < N; j++){
                if(tt_times + t_a <= arr[j]){
                    tt_res++;
                    tt_times += t_a;
                }
            }
            t_res = max(t_res, tt_res);
            
        }
        res = max(res, t_res);
    }

    cout << res;
    return 0;
}   