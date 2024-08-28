#define MAX 100000
#define MOD 1000000000
#define INF 2100000000

#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> mvec;
vector<int> pvec;

int m_len, p_len;
int res = INF;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        if(t < 0){
            mvec.push_back(t);
        }
        else if(t >= 0){
            pvec.push_back(t);
        }
    }
    sort(mvec.begin(), mvec.end(), greater<int>());

    m_len = mvec.size();
    p_len = pvec.size();

    if(p_len < 2){
        res = mvec[0] + mvec[1];
    }
    else if(m_len < 2){
        res =  pvec[0] + pvec[1];
    }

    int p_idx = 0;
    int m_idx = 0;

    while(p_idx < p_len && m_idx < m_len){
        int p = pvec[p_idx];
        int m = mvec[m_idx];

        if(abs(res) > abs(p + m)){
            res = p + m;
        }

        if(p + m < 0){
            p_idx++;
        }
        else if(p + m >= 0){
            m_idx++;
        }
    }
    cout << res;

    return 0;
}