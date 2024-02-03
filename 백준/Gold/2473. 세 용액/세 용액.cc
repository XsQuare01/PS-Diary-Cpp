#define MAX 5000
#define INF 6000000000

#include<bits/stdc++.h>

using namespace std;

int n;
long long arr[MAX] = {0, };
long long res[3] = {0, };
long long r_sum = INF;

void PrintResult(){
    sort(res, res + 3);
    for(auto i: res){
        cout << i << " ";
    }
}

bool BinarySearch(int st, int ed, long long v, int i, int j){
    int mid;
    while(st <= ed){
        mid = (st + ed) / 2;
        if(st == i || st == j){
            st++;
            continue;
        }

        if(ed == i || ed == j){
            ed--;
            continue;
        }
        
        
        long long ts = v + arr[mid];
        if(ts < 0){
            st = mid + 1;
        }
        if(ts > 0){
            ed = mid - 1;
        }
        if(ts == 0 && mid != i && mid != j){
            res[0] = arr[i];
            res[1] = arr[j];
            res[2] = arr[mid];
            return true;
        }
        if(ts == 0){
            int la = arr[mid] - arr[mid-1];
            int ra = arr[mid+1] - arr[mid];
            if(la >= ra){
                mid++;
            }
            if(la < ra){
                mid--;
            }
            ts = v + arr[mid];
            r_sum = abs(ts);
            res[0] = arr[i];
            res[1] = arr[j];
            res[2] = arr[mid];
            return ts == 0;

        }
        
        if(abs(ts) < r_sum && mid != i && mid != j){
            r_sum = abs(ts);
            res[0] = arr[i];
            res[1] = arr[j];
            res[2] = arr[mid];
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    res[0] = arr[0];
    res[1] = arr[1];
    res[2] = arr[2];
    r_sum = abs(arr[0] + arr[1] + arr[2]);

    if(r_sum == 0){
        PrintResult();
        return 0;
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            long long t_sum = arr[i] + arr[j];

            if(BinarySearch(0, n-1, t_sum, i, j)){
                PrintResult();
                return 0;
            }
        }
    }

    PrintResult();
    return 0;
}