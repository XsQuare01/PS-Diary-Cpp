#define MAX 400
#define INF 1000000

#include<bits/stdc++.h>

using namespace std;

long long S, T;
queue<pair<long long, string>> q;
string res1, res2;

long long Times(long long s){
    return s * s;
}

long long Plus(long long s){
    return s + s;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S >> T;
    if(S == T){
        cout << 0;
        return 0;
    }
    if(T == 1){
        cout << '/';
        return 0;
    }

    q.push({S, ""});
    while(!q.empty()){
        long long ts  = q.front().first;
        string res = q.front().second;
        q.pop();

        long long tss;
        if(ts != 1){
            tss = Times(ts);
            if(tss == T){
                res1 =  res + '*';
                break;
            }
            if(tss < T){
                q.push({tss, res + '*'});
            }
        }
        

        tss = Plus(ts);
        if(tss == T){
            res1 =  res + '+';
            break;
        }
        if(tss < T){
            q.push({tss, res + '+'});
        }
    }
    if(T == 2){
        res2 = "/+";
    }
    if(T != 2){
        q.push({2, "/+"});
        while(!q.empty()){
            long long ts  = q.front().first;
            string res = q.front().second;
            q.pop();

            long long tss = Times(ts);
            if(tss == T){
                res2 = res + '*';
                break;
            }
            if(tss < T){
                q.push({tss, res + '*'});
            }

            tss = Plus(ts);
            if(tss == T){
                res2 =  res + '+';
                break;
            }
            if(tss < T){
                q.push({tss, res + '+'});
            }
        }
    }

    

    int len1 = res1.length();
    int len2 = res2.length();

    if(!len1 && !len2){
        cout << -1;
        return 0;
    }
    if(!len1){
        cout << res2;
        return 0;
    }
    if(!len2){
        cout << res1;
        return 0;
    }
    if(len1 > len2){
        cout << res2;
    }
    if(len1 <= len2){
        cout << res1;
    }
    
    return 0;   
}
