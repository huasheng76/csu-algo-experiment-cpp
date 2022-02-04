#include<bits/stdc++.h>

using namespace std;

int n;
int cw;
int bestw;
int r;
int c1;
int c2;
int x[100];
int bestx[100];
int w[100];

void BackTrack(int i){
    if(i>n){
        if(cw>bestw){
            for(i=1;i<=n;++i){
                bestx[i]=x[i];
            } 
            bestw=cw;
        }
        return;
    }
    r-=w[i];
    if(cw+w[i]<=c1){
        cw+=w[i];
        x[i]=1;
        BackTrack(i+1);
        x[i]=0;
        cw-=w[i];
    }
    if(cw+r>bestw){
        x[i]=0;
        BackTrack(i+1);
    }
    r+=w[i];
}

void input(){
    cin >> n;
    cin >> c1 >> c2;
    for(int i=1;i<=n;i++){
        cin >> w[i];
    }
}

void intlialize(){
    bestw=0;
    r=0;
    cw=0;
    for(int i=1;i<=n;i++){
        r+=w[i];
    }
}

void output(){
    int rw=0;
    int weight;
    for(int i=1;i<=n;i++){
        if(bestx[i]==0){
            rw+=w[i];
        }
    }
    if(rw>c2) cout << "不能装入" << endl;
    else{
        cout << "船1装入货物为：";
        for(int i=1;i<=n;i++){
            if(bestx[i]==1) {
                weight+=w[i];
                cout << i << " ";}
        }
        cout << "船2装入货物为：";
        for(int i=1;i<=n;i++){
            if(bestx[i]!=1) {
                weight+=w[i];
                cout << i << " ";
                }
        }
        cout << endl;
         cout << weight;
    }
}

int main(){
    input();
    intlialize();
    BackTrack(1);
    output();
    system("pause");
    return 0;
}