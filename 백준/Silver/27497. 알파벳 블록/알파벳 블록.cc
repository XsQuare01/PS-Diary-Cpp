#define MAX 200
#define MOD 1000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
stack<int> latest;
deque<char> dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        int index;
        cin >> index;
        switch(index){
            char c;
            case 1:
                cin >> c;
                dq.push_back(c);
                latest.push(1);
                break;
            case 2:
                cin >> c;
                dq.push_front(c);
                latest.push(2);
                break;
            case 3:
                if(latest.empty()){
                    break;
                }
                int lat = latest.top();
                latest.pop();
                if(lat == 1){
                    dq.pop_back();
                }
                else if(lat == 2){
                    dq.pop_front();
                }
                break;
        }
    }

    if(dq.empty()){
        cout << 0;
        return 0;
    }

    for(auto a: dq){
        cout << a;
    }

    return 0;
}