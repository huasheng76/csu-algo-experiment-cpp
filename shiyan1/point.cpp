#include<bits/stdc++.h>

using namespace std;

#define INF 655432
#define N 10000

struct node{
    double x,y;
}point[10000];

int cmp(const void*a,const void*b){
    struct node ac=*(struct node*)a;
    struct node bd=*(struct node*)b;
    if(ac.x!=bd.x){
        return ac.x-bd.x;
    }
    else return ac.x-bd.y;
    
}

double mindistance(double l,double r){
    return l<r?l:r;
}

double distance(int l,int r){
    return sqrt((point[l].x-point[r].x)*(point[l].x-point[r].x)+(point[l].y-point[r].y)*(point[l].y-point[r].y));
}

double Clostpairs(int l,int r){
    double enddis=INF;
    int i=0,j=0,k=0;
    if(l==r) return enddis;
    if(r-l==1) return distance(l,r);
    int mid=(l+r)>>1;
    double distanceleft=Clostpairs(l,mid);
    double distanceright=Clostpairs(mid+1,r);
    enddis=mindistance(distanceleft,distanceright);
    int temp[N];
    for(i=l;i<r;i++){
        if(fabs(point[i].x-point[mid].x)<enddis) temp[k++]=i;
    }
    for(i=0;i<k;i++){
        for(j=i+1;j<k && j<i+7;j++){
            if(fabs(point[temp[j]].y-point[temp[i]].y)<enddis) enddis=mindistance(enddis,distance(temp[i],temp[j]));
        }
    }
    return enddis;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> point[i].x >> point[i].y;
    }
    qsort(point,n,sizeof(point[0]),cmp);
    cout << Clostpairs(0,n-1) << endl;
    system("pause");
    return 0;
}