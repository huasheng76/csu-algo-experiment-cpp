#include<bits/stdc++.h>

using namespace std;

char maze[21][21];
int visted[21][21][5][4];
int dire[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int sx,sy,sc,sd,dx,dy,dc;

typedef struct Node{
    int x,y;
    int color;
    int dire;
    int time;
    Node(int x1,int y1,int color1,int dire1,int time1){
        x=x1;y=y1;color=color1;dire=dire1;time=time1;
    }
}node;

Node toStraight(Node s){
    node v=s;
    v.x+=dire[s.dire][0];
    v.y+=dire[s.dire][1];
    v.color=(s.color+1)%5;
    v.time++;
    return v;
}

Node toLeft(Node s){
    node v=s;
    v.dire=(s.dire+3)%4;
    v.time++;
    return v;
}

Node toRight(Node s){
    node v=s;
    v.dire=(s.dire+1)%4;
    v.time++;
    return v;
}


int bfs(){
    queue<node> q;
    node s=Node(sx,sy,sc,sd,0);
    q.push(s);
    while(!q.empty()){
        s=q.front();
        q.pop();
        node v=toStraight(s);
        if(v.x==dx && v.y==dy && v.color==dc){
            return v.time;
        }
        if(v.x<=20 && v.x>=1 && v.y<=20 && v.y>=1 && maze[v.x][v.y]=='.' && !visted[v.x][v.y][v.color][v.dire]){
            visted[v.x][v.y][v.color][v.dire]=1;
            q.push(v);
        }

        v=toLeft(s);
        if(!visted[v.x][v.y][v.color][v.dire]){
            visted[v.x][v.y][v.color][v.dire]=1;
            q.push(v);
        }
        v=toRight(s);
        if(!visted[v.x][v.y][v.color][v.dire]){
            visted[v.x][v.y][v.color][v.dire]=1;
            q.push(v);
        }
    }
    return -1;
}


int main(){
    cin >> sx >> sy >> sc >> sd >> dx >> dy >> dc;
    for(int i=1;i<=20;i++){
        for(int j=1;j<=20;j++){
            cin >> maze[i][j];
        }
    }
    cout << bfs();
    system("pause");
}
