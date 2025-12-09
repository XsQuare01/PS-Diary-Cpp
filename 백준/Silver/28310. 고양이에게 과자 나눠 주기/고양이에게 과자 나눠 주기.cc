#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#define INF 300000

#include<bits/stdc++.h>

using namespace std;

int T, N, M;
int sum[MAX];
int arr[MAX][MAX];

long long numerator_arr[MAX];
long long denominator_arr[MAX];


void init(){
    for(int i = 0; i < MAX; i++){
        numerator_arr[i] = 0;
        denominator_arr[i] = 1;
    }
}

long long gcd(long long a, long long b){
    if(a < b){
        swap(a, b);
    }

    if(b == 0){
        return 1;
    }

    while(a % b){
        a %= b;

        if(a < b){
            swap(a, b);
        }
    }

    return b;
}

long long lcm(long long a, long long b){
    long long g = gcd(a, b);
    return a * b / g;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> T;

    for(int i = 0; i < T; i++){
        init();

        cin >> N >> M;
        for(int j = 0; j < M; j++){
            cin >> sum[j];

            for(int k = 0; k < N; k++){
                cin >> arr[j][k];
            }            
        }

        for(int j = 0; j < N; j++){
            numerator_arr[j] = 0;    // 분자
            denominator_arr[j] = 1;
            for(int k = 0; k < M; k++){

                long long n_denominator = lcm(denominator_arr[j], sum[k]);
                long long le = n_denominator / denominator_arr[j];
                long long ri = n_denominator / sum[k];

                long long n_numerator = numerator_arr[j] * le + arr[k][j] * ri;

                numerator_arr[j] = n_numerator;
                denominator_arr[j] = n_denominator;
            }
        }

        long long maximum = -1;
        long long minimum = LLONG_MAX;
        for(int j = 0; j < N; j++){
            maximum = max(maximum, numerator_arr[j]);
            minimum = min(minimum, numerator_arr[j]);
        }

        long long numerator = maximum - minimum;
        long long denominator = denominator_arr[0];

        if(numerator == 0){
            cout << 0 << "\n";
            continue;
        }

        long long g = gcd(numerator, denominator);

        numerator /= g;
        denominator /= g;

        if(denominator == 1){
            cout << numerator << "\n";
        }
        else{
            cout << numerator << "/" << denominator << "\n";
        }
    }
    
    return 0;
}