#include <bits/stdc++.h>
#define MAX 1000
#define INF 2100000000
#define MOD 1000000007

using namespace std;

int T;
string S;
string arr[10] = {
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE"
};
int carr[26] = {0, };
vector<int> res;

void init(int cnt){
    for(int i = 0; i < 26; i++){
        carr[i] = 0;
    }
    res = vector<int>();
    cout << "Case #" << cnt << ": ";
}

void deleteChar(int idx){
    res.push_back(idx);
    int len = arr[idx].length();
    for(int i = 0; i < len; i++){
        int num = (arr[idx][i] - 'A');
        carr[num]--;
    }
}
void deleteString(char c, int idx){
    int cnt = carr[c - 'A'];
    for(int i = 0; i < cnt; i++){
        deleteChar(idx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        init(i+1);
        cin >> S;
        int len = S.length();
        for(int j = 0; j < len; j++){
            int idx = S[j] - 'A';
            carr[idx]++;
        }

        deleteString('Z', 0);
        deleteString('W', 2);
        deleteString('U', 4);
        deleteString('X', 6);
        deleteString('G', 8);
        deleteString('O', 1);
        deleteString('H', 3);
        deleteString('F', 5);
        deleteString('S', 7);
        deleteString('I', 9);
        
        sort(res.begin(), res.end());
        for(auto a: res){
            cout << a;
        }
        cout << "\n";
    }


    return 0;
}
