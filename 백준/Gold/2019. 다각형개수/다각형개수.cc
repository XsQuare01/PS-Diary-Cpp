#define MAX 100
#define INF 2100000000

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int y;
	int x;

	Node() {};
	Node(int _y, int _x) : y(_y), x(_x) {};

	bool is_equal(int _y, int _x) {
		return y == _y && x == _x;
	}
};

int N, cnt = 1, res = 0;
Node arr[MAX + 2];
vector<int> edge[MAX + 2];
int parent[MAX + 2];
bool flag[MAX + 2] = { false, };
set<int> cycle_set;
bool cycle = false;

bool isLine(int idx1, int idx2, int idx3){
    int x1 = arr[idx1].x;
    int y1 = arr[idx1].y;
    int x2 = arr[idx2].x;
    int y2 = arr[idx2].y;
    int x3 = arr[idx3].x;
    int y3 = arr[idx3].y;

    return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) == 0;
}

bool checkPolygon(){
    vector<int> cycle_vec;
    for(auto a: cycle_set){
        cycle_vec.push_back(a);
    }

    int len = cycle_vec.size();
    for(int i = 0; i < len - 2; i++){
        int idx1 = cycle_vec[i];
        int idx2 = cycle_vec[i+1];
        int idx3 = cycle_vec[i+2];

        if(isLine(idx1, idx2, idx3)){
            return false;
        }
    }

    return true;
}

int DFS(int idx) {
	int tres = 1;
    int prev = -1;
	flag[idx] = true;

	if (edge[idx].size() <= 1) {
		tres = -1;
	}
	for (auto a : edge[idx]) {
		if (parent[idx] == a) {
			continue;
		}

        if(prev == a){
            tres = -1;
            continue;
        }
        prev = a;

        if(a == idx){
            tres = -1;
            continue;
        }

		// 싸이클?
		if (flag[a]) {
			// 첫 싸이클
			if (!cycle) {
				cycle = true;
				cycle_set.insert(idx);
				while (idx != a) {
					cycle_set.insert(parent[idx]);
					idx = parent[idx];
				}
			}
			// 다른 싸이클!
			else if (cycle_set.find(a) == cycle_set.end()) {
				tres = -1;
			}
			continue;
		}

		parent[a] = idx;
		if (DFS(a) == -1) {
			tres = -1;
		}
	}

	return tres;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int idx1 = 0;
		int idx2 = 0;
		for (int j = 1; j < cnt; j++) {

			// 이미 존재
			if (arr[j].is_equal(y1, x1)) {
				idx1 = j;
				break;
			}
		}
		if (!idx1) {
			idx1 = cnt++;
			arr[idx1] = Node(y1, x1);
		}

		for (int j = 1; j < cnt; j++) {

			// 이미 존재
			if (arr[j].is_equal(y2, x2)) {
				idx2 = j;
				break;
			}
		}
		if (!idx2) {
			idx2 = cnt++;
			arr[idx2] = Node(y2, x2);
		}

		// if (idx1 == idx2) {
		// 	continue;
		// }

		// bool f = true;
		// // 그래프 연결
		// for (auto a : edge[idx1]) {
		// 	if (a == idx2) {
		// 		f = false;
		// 	}
		// }
		// if (!f) {
		// 	continue;
		// }
		edge[idx1].push_back(idx2);
		edge[idx2].push_back(idx1);
	}

    for(int i = 0; i < cnt; i++){
        sort(edge[i].begin(), edge[i].end());
    }

	
	for (int i = 1; i <= N; i++) {
		// 이미 탐색 완료
		if (flag[i]) {
			continue;
		}

		cycle_set.clear();
		cycle = false;
		if (DFS(i) != -1) {
            res++;
			
		}
	}

	cout << res;

	return 0;
}