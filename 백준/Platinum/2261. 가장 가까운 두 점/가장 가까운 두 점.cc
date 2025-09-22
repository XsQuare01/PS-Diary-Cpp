#define MIN 1
#define MAX 100000
#define LEN 5000000
#define INF LONG_LONG_MAX

#include<bits/stdc++.h>

using namespace std;

int N;
pair<long long, long long> arr[MAX];

inline long long getDistance(int idx1, int idx2){
    return 1LL * (arr[idx1].first - arr[idx2].first) * (arr[idx1].first - arr[idx2].first) + (arr[idx1].second - arr[idx2].second) * (arr[idx1].second - arr[idx2].second);
}

bool sortY(pair<long long, long long> p1, pair<long long, long long> p2){
    if(p1.second < p2.second){
        return true;
    }
    else{
        return false;
    }
}

// 1. O(N log^2 N)
long long divideAndConquer(int st, int ed){
    // 0. Base
    if(ed - st == 2){
        return min(getDistance(st, ed), min(getDistance(st, st+1), getDistance(st+1, ed)));
    }
    else if(ed - st == 1){
        return getDistance(st, ed);
    }

    // 1. Recursion
    int mid = (st + ed) / 2;
    long long d = INF;
    long long le = divideAndConquer(st, mid);
    long long ri = divideAndConquer(mid, ed);
    d = min(le, ri);

    // 2. mid를 기준으로 좌우 d만큼을 정렬
    int le_idx = mid-1;
    int ri_idx = mid+1;
    while((arr[mid].first - arr[le_idx].first) * (arr[mid].first - arr[le_idx].first) <= d && le_idx >= st){
        le_idx--;
    }
    le_idx++;
    while((arr[ri_idx].first - arr[mid].first) * (arr[ri_idx].first - arr[mid].first) <= d && ri_idx <= ed){
        ri_idx++;
    }
    ri_idx--;
    sort(arr + le_idx, arr + ri_idx+1, sortY);
    // 3. Combine
    for(int i = le_idx; i <= ri_idx; i++){
        for(int j = 1; j <= 5; j++){
            if(i + j > ri_idx){
                break;
            }

            long long td = getDistance(i, i+j);
            d = min(d, td);
        }
    }

    // 4. sort
    sort(arr + st, arr + ed + 1);
    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        long long x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    sort(arr, arr + N);     // X축 정렬
    long long res = divideAndConquer(0, N-1);
    cout << res;

	return 0;
}