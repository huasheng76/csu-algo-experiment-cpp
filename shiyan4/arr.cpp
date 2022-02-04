#include<bits/stdc++.h>

using namespace std;

int tmp=1;

struct Num
{
    int a[100];
    int sum;
}num,dp[100][100];


bool cmp(int a,int b){
    return a>b;
}

Num solution(int arr[],int n){
    sort(arr,arr+n-1,cmp);
    for(int i=0;i<n;i++){
        dp[i][0].sum=0;
        dp[i][0].a[100]={};
    }
    for(int i=0;i<=n;i++){
        if(arr[i]%3==0){    
            dp[0][i].sum=arr[0];
            dp[0][i].a[0]=arr[0];
        }
        else{
            dp[0][i].sum=0;
        }
        
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            if((dp[i-1][j-1].sum+arr[i])%3==0){
                dp[i][j].sum+=arr[i];
                dp[i][j].a[tmp++]=arr[i];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n-1][n];
}

int main(){
    int n,arr[100];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    Num solve;
    solve=solution(arr,n);
    for(int i=1;i<tmp;i++){
        cout << solve.a[i];
    }
    system("pause");
}