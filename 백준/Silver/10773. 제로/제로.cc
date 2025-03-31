#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#define INF 300000

#include<bits/stdc++.h>

using namespace std;

int K;
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K;
	for(int i = 0; i < K; i++){
		int t;
		cin >> t;
		if(!t){
			st.pop();
		}
		else{
			st.push(t);
		}
	}

	int sum = 0;
	while(!st.empty()){
		int t = st.top();
		st.pop();

		sum += t;
	}
	cout << sum;
	return 0;
}