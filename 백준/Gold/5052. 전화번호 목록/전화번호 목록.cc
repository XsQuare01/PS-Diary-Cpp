#include <bits/stdc++.h>
#define SMAX 10000
#define MAX 10
#define INF 10
#define MOD 987654321

using namespace std;

int T, N;
string arr[SMAX];
bool flag = false;
struct Node{
    Node* edge[MAX];
    bool is_end = false;

    Node* next(int idx){
        if(edge[idx] == NULL){
            edge[idx] = new Node();
        }

        return edge[idx];
    }
};

Node* head;

void init(){
    delete head;
    head = new Node();
    flag = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for(int i = 0; i < T; i++){
        init();
        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> arr[j];
        }
        sort(arr, arr + N);

        for(int j = 0; j < N; j++){

            int len = arr[j].length();
            Node* trie = head;
            for(int k = 0; k < len; k++){
                int idx = arr[j][k] - '0';
                trie = trie->next(idx);
                if(trie->is_end){
                    flag = true;
                }
            }
            trie->is_end = true;
        }

        if(flag){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
        }
    }
    return 0;
}
