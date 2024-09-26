#define MAX 300
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, G;
vector<int> arr;
set<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        arr = vector<int>();
        s = set<int>();

        cin >> G;
        for(int j = 0; j < G; j++){
            int t;
            cin >> t;
            arr.push_back(t);
        }

        int modular = G;
        while(true){
            s = set<int>();
            bool f = true;

            for(int j = 0; j < G; j++){
                int t = arr[j] % modular;

                if(s.find(t) != s.end()){
                    f = false;
                    break;
                }
                s.insert(t);
            }

            if(f){
                cout << modular << "\n";
                break;
            }
            modular++;
        }
    }

    return 0;
}