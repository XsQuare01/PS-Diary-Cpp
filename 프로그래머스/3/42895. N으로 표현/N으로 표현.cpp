#define MAX 10
#define NMAX 1000000000
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> varr[MAX];

void FOperation(int x, int y){
    for(auto a: varr[x]){
        for(auto b: varr[y]){
            varr[x+y].push_back(a + b);
            varr[x+y].push_back(a - b);
            varr[x+y].push_back(b - a);
            varr[x+y].push_back(a * b);
            if(b){
                if(a / b){
                    varr[x+y].push_back((int)(a / b));
                }
                
            }
            if(a){
                if(b / a){
                    varr[x+y].push_back((int)(b / a));
                }
            }   
        }
    }
}

int solution(int N, int number) {
    int answer = 0;
    int tten = N;
    varr[1].push_back(N);
    for(int i = 2; i < 9; i++){
        tten = tten * 10 + N;
        varr[i].push_back(tten);
        for(int j = i - 1; j >= 1; j--){
            FOperation(j, i - j);
        }
    }
    
    for(int i = 1; i < 9; i++){
        for(auto a: varr[i]){
            if(a == number){
                return i;
            }
        }
    }
    
    return -1;
}