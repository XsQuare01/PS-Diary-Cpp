#define MAX 1000000000

#include<bits/stdc++.h>

using namespace std;

int N;
int t, t1;
bool f, f1;
set<int> res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        res = set<int>();
        f = false;
        f1 = false;

        cin >> t;
        t1 = t + 1;

        int sq = ceil(sqrt(t1));
        for(int i = 2; i <= sq; i++){
            
            while(t%i == 0){
                t /= i;
                f = true;
                res.insert(i);
            }

            while(t1%i ==0){
                t1 /= i;
                f1 = true;
                res.insert(i);
            }
        }

        if(t!= 1){
            res.insert(t);
        }
        if(t1 != 1){
            res.insert(t1);
        }

        cout << res.size() << "\n";
    }


    return 0;
}