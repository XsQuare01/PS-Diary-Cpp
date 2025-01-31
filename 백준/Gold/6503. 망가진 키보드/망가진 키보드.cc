#define _CRT_SECURE_NO_WARNINGS
#define MAX 128

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

string S;
int M;
int arr[MAX];

void init() {
    for (int i = 0; i < MAX; i++) {
        arr[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    
    while (true) {
        string MS;
        getline(cin, MS);
        M = stoi(MS);
        if (!M) {
            break;
        }
        init();
        getline(cin, S);

        int st = 0, ed = 0;
        int cnt = 0;
        int len = 0;
        int res = -1;
        while (ed < S.length()) {
            int idx = (int)S[ed];
            if ((!arr[idx] && cnt < M) || arr[idx]) {
                if (!arr[idx]) {
                    cnt++;
                }
                arr[idx]++;
                len++;
                ed++;
            }
            else if (cnt == M) {
                int sidx = (int)S[st++];
                arr[sidx]--;
                if (!arr[sidx]) {
                    cnt--;
                }
                len--;
            }
            res = max(res, len);
        }

        cout << res << "\n";
    }

    return 0;
}