#include<bits/stdc++.h>

using namespace std;

char maze[13][13];
int visited[13][13];
int sx,sy,dx,dy;
int dire[4][2]={{0,1},{-1,0},{0,-1},{1,0}};

typedef struct Node
{
    int x,y;
    Node(int x1,int y1){x=x1;y=y1;};
}node;

int bfs(){
    queue<node> q;
    node s=Node(sx,sy);
    q.push(s);
    visited[sx][sy]=0;
    while(!q.empty()){
        s=q.front();
        q.pop();
        int temp=visited[s.x][s.y]+1;                
        if(s.x==dx && s.y==dy){
                    return visited[dx][dy];
                }
        for(int i=0;i<4;i++){
            int cx=s.x+dire[i][0];
            int cy=s.y+dire[i][1];
            if(!visited[cx][cy] && maze[cx][cy]=='.' && cx<=12 && cx>=1 && cy<=12 && cy>=1 ){
                q.push(Node(cx,cy));
                visited[cx][cy]=temp;
            }
        }
    }
    return -1;
}

int main(){
    cin >> sx >> sy >> dx >> dy;
    for(int i=1;i<=12;i++){
        for(int j=1;j<=12;j++){
            cin >> maze[i][j];
        }
    }
    cout << bfs();
    system("pause");
}



