#define MAX 100
#define LMAX 10
#define INF 987654321

//https://www.acmicpc.net/submit/2607

#include<bits/stdc++.h>

using namespace std;

int n;
int arr[MAX][26];
int larr[MAX];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        int len = s.length();
        larr[i] = len;
        for(int j = 0; j < len; j++){
            int idx = s[j] - 'A';
            arr[i][idx]++;
        }
    }

    int res = 0;
    for(int i = 1; i < n; i++){
        if(larr[0] > larr[i] + 1 || larr[0] < larr[i] - 1){
            continue;
        }
        int ucnt = 0;
        int dcnt = 0;
        for(int j = 0; j < 26; j++){
            int iv = arr[0][j];
            int jv = arr[i][j];

            if(iv - jv >= 0){
                ucnt += iv - jv;
            }
            if(iv - jv < 0){
                dcnt += iv - jv;
            }
        }

        if(ucnt > 1 || dcnt < -1){
            continue;
        }
        res++;
    }

    cout << res;
    
    return 0;
}