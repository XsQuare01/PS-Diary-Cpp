#define MAX 100
#define TMAX 300000
#define INF 2100000000

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[2*MAX];
stack<int> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cout << "Case #" << i << ": ";
		cin >> N;
		
		for(int j = 0; j < 2 * N; j++){
			cin >> arr[j];
		}

		for(int j = 0; j < 2 * N; j++){
			if(!arr[j]){
				continue;
			}
			cout << arr[j] << " ";
			for(int k = j + 1; k < 2 * N; k++){
				if(arr[j] / 3 * 4 == arr[k]){
					arr[k] = 0;
					break;
				}
			}
		}


		cout << "\n";
	}
	return 0;
}