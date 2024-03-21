#define MAX 50
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, M, R;
vector<int> parr;
vector<int> marr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        if(t > 0){
            parr.push_back(t);
        }
        if(t < 0){
            marr.push_back(-t);
        }
    }

    int p_size = parr.size();
    int m_size = marr.size();

    for(int i = p_size % M; i < M; i++, p_size++){
        parr.push_back(0);
    }
    for(int i = m_size % M; i < M; i++, m_size++){
        marr.push_back(0);
        
    }

    sort(parr.begin(), parr.end());
    sort(marr.begin(), marr.end());

    for(int i = M-1; i < p_size; i += M){
        R += (2 * parr[i]);
    }
    for(int i = M-1; i < m_size; i += M){
        R += (2 * marr[i]);
    }

    int t = max(parr[p_size-1], marr[m_size-1]);
    R -= t;
    cout << R;
    return 0;
}
