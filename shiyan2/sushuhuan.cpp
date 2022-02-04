#include<bits/stdc++.h>

using namespace std;


bool isPrime(int x);
int arr[100];
void BackTrack(int cur);
bool check(int t);
bool used[100];

void BackTrack(int n,int cur){
    if(cur==n && isPrime(arr[0]+arr[n-1])){
        cout << "素数环为：";
        for(int i=0;i<n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    else{
        for(int i=2;i<=n;i++){
            if(isPrime(i+arr[cur-1]) && !used[i]){
                arr[cur]=i;
                used[i]=true;
                BackTrack(n,cur+1);
                used[i]=false;
            }
        }
    }
        
}


bool isPrime(int x){
    int k=(int)sqrt(x);
    for(int i=2;i<=k;i++){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    arr[0]=1;
    for(int i=1;i<=20;i++){
        used[i]=false;
    }
    BackTrack(n,1);
    system("pause");
}