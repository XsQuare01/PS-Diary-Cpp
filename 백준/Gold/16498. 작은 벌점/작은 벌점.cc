#define MAX 1000
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int A, B, C;
int aarr[MAX+2] = {0, };
int barr[MAX+2] = {0, };
int carr[MAX+2] = {0, };

long long res = INF;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> C;
    for(int i = 1; i <= A; i++){
        cin >> aarr[i];
    }
    sort(aarr+1, aarr + A + 1);   
    for(int i = 1; i <= B; i++){
        cin >> barr[i];
    }
    sort(barr+1, barr + B + 1); barr[0] = -INF; barr[B+1] = INF;
    for(int i = 1; i <= C; i++){
        cin >> carr[i];
    }
    sort(carr+1, carr + C + 1); carr[0] = -INF; carr[C+1] = INF;

    for(int i = 1; i <= A; i++){
        int a = aarr[i];

        int b_upper_index = upper_bound(barr, barr + B, a) - barr;
        int b_upper = barr[b_upper_index];

        int b_lower_index = b_upper_index - 1;
        int b_lower = barr[b_lower_index];
        if(b_lower == -INF){
            b_lower = b_upper;
        }

        int c_upper_index = upper_bound(carr, carr + C, a) - carr;
        int c_upper = carr[c_upper_index];

        int c_lower_index = c_upper_index - 1;
        int c_lower = carr[c_lower_index];
        if(c_lower == -INF){
            c_lower = c_upper;
        }

        //Debug
        // cout << a << " " << b_upper << " " << b_lower << " " << c_upper << " " << c_lower << "\n";

        long long res1 = INF;
        if(a <= b_upper && b_upper <= c_upper){
            res1 = c_upper - a;
            res = min(res, res1);
            // cout << "res1: " << res1 << " ";
        }
        long long res2 = INF;
        if(a <= c_upper && c_upper <= b_upper){
            res2 = b_upper - a;
            res = min(res, res2);
            // cout << "res2: " << res2 << " ";
        }
        long long res3 = INF;
        if(b_lower <= a && a <= c_upper){
            res3 = c_upper - b_lower;
            res = min(res, res3);
            // cout << "res3: " << res3 << " ";
        }
        long long res4 = INF;
        if(b_lower <= c_lower && c_lower <= a){
            res4 = a - b_lower;
            res = min(res, res4);
            // cout << "res4: " << res4 << " ";
        }
        long long res5 = INF;
        if(c_lower <= a && a <= b_upper){
            res5 = b_upper - c_lower;
            res = min(res, res5);
            // cout << "res5: " << res5 << " ";
        }
        long long res6 = INF;
        if(c_lower <= b_lower && b_lower <= a){
            res6 = a - c_lower;
            res = min(res, res6);
            // cout << "res6: " << res6 << " ";
        }
        // cout << "\n";

    }
    cout << res;
    return 0;
}   