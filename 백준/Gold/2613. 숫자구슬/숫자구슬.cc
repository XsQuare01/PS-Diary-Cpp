#define MIN 1
#define MAX 300
#define LEN 5000000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr[MAX+1];
int le, ri, res;
vector<int> vec;

bool binarySearch(int mid){
    int cnt = 1;
    int tsum = 0;
    for(int i = 1; i <= N; i++){
        if(tsum + arr[i] > mid){
            cnt++;
            tsum = arr[i];

            if(cnt > M){
                return false;
            }
        }
        else{
            tsum += arr[i];
        }
    }
    

    return true;
}

void findGroup(){
    int tsum = 0;
    int cnt = 0;

    for(int i = 1; i <= N; i++){
        if(tsum + arr[i] > res){
            vec.push_back(cnt);
            tsum = arr[i];
            cnt = 1;
            M -= 1;
        }
        else{
            tsum += arr[i];
            cnt++;
        }

        if(N - i + 1 == M){
            vec.push_back(cnt);
            for(int j = i + 1; j <= N; j++){
                vec.push_back(1);
            }
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		le = max(le, arr[i]);
        ri += arr[i];
	}

    while(le <= ri){
        int mid = (le + ri) / 2;
        if(binarySearch(mid)){
            res = mid;
            ri = mid - 1;
        }
        else{
            le = mid + 1;
        }
    }
    findGroup();

    cout << res << "\n";
    for(auto a: vec){
        cout << a << " ";
    }

	return 0;
}