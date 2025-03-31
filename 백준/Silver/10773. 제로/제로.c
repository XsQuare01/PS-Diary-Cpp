#define _CRT_SECURE_NO_WARNINGS
#define MAX 100000
#define INF 300000

#include<stdio.h>

int k, idx;
int num[MAX];
long ans = 0;

int main() {

    scanf("%d",&k);
    for (int i=0;i<k;i++)
        {
            scanf("%d",&num[i]);
            if(num[i]==0)
            {
                i -=2;
                k -=2;
            }
        }
    for (int j=0;j<k;j++)
        {
            ans += num[j];
        }
    printf("%ld",ans);
    return 0;
}