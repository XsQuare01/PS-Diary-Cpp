#define MAX 1000000

#include<bits/stdc++.h>

using namespace std;

int T;
char C;
int arr[MAX + 1];
int carr[MAX + 1];
int harr[MAX + 1];

int FindUnion(int t){
    if(arr[t] == t){
        return t;
    }
    return FindUnion(arr[t]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    for(int i = 1; i <= MAX; i++){
        arr[i] = i;
        carr[i] = 1;
        harr[i] = 1;
    }

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> C;
        if(C == 'I'){
            int A, B;
            cin >> A >> B;
            int pa = FindUnion(A);
            int pb = FindUnion(B);

            if(pa == pb){
                continue;
            }

            if(harr[pa] >= harr[pb]){
                arr[pb] = pa;
                carr[pa] += carr[pb];
                harr[pa] = max(harr[pa], harr[pb] + 1);
            }
            else if(harr[pa] < harr[pb]){
                arr[pa] = pb;
                carr[pb] += carr[pa];
                harr[pb] = max(harr[pb], harr[pa] + 1);
            }
        }
        if(C == 'Q'){
            int D;
            cin >> D;

            int pd = FindUnion(D);
            cout << carr[pd] << "\n";
        }
    }

    return 0;
}