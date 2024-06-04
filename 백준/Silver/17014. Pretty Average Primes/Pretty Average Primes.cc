#define MOD 1000000007
#define MAX 2000000

#include<bits/stdc++.h>

using namespace std;

vector<int> prime_vector;
int parr[MAX + 1] = {false, };
int T, N;

void FindPrimes(){
    for(int i = 2; i<= MAX; i++){
        if(parr[i]){
            continue;
        }
        prime_vector.push_back(i);
        for(int j = i+i; j <= MAX; j += i){
            parr[j] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    FindPrimes();

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        N *= 2;

        for(auto a: prime_vector){
            int b = N - a;
            if(!parr[b]){
                cout << a << " " << b;
                break;
            }
        }
        cout << "\n";
    }

    return 0;
}