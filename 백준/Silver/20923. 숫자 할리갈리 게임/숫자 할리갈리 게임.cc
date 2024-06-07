#define WIN 5
#define MAX 30000

#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr1[MAX];
int arr2[MAX];
int t1 = 0; int t2 = 0;
queue<int> q1, q2, r1, r2;

void WinPlayer1(){
    if(t1 == WIN || t2 == WIN){
        t1 = 0; t2 = 0;
        while(!r2.empty()){
            int t = r2.front();
            r2.pop();
            q1.push(t);
        }
        while(!r1.empty()){
            int t = r1.front();
            r1.pop();
            q1.push(t);
        }
    }
}

void WinPlayer2(){
    if(t1 + t2 == WIN){
        t1 = 0; t2 = 0;
        while(!r1.empty()){
            int t = r1.front();
           r1.pop();
            q2.push(t);
        }
        while(!r2.empty()){
            int t = r2.front();
            r2.pop();
            q2.push(t);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr1[i] >> arr2[i];
    }
    for(int i = N-1; i >= 0; i--){
        q1.push(arr1[i]);
        q2.push(arr2[i]);
    }
    for(int i = 0; i < M; i++){
        if(i % 2 == 0){
            t1 = q1.front();
            q1.pop();
            r1.push(t1);

            if(q1.empty()){
                cout << "su";
                return 0;
            }

            WinPlayer1();
            WinPlayer2();
        }
        else{
            t2 = q2.front();
            q2.pop();
            r2.push(t2);

            if(q2.empty()){
                cout << "do";
                return 0;
            }
            WinPlayer1();
            WinPlayer2();
        }
    }

    if(q1.size() > q2.size()){
        cout << "do";
        return 0;
    }
    if(q1.size() < q2.size()){
        cout << "su";
        return 0;
    }
    if(q1.size() == q2.size()){
        cout << "dosu";
        return 0;
    }

    return 0;
}