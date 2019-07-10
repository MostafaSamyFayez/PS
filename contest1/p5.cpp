#include<bits/stdc++.h>
using namespace std;

const int N=1e4+4, M=1e44;
int ne, head[N], nxt[M], to[M];
int n,m,u,v;

void init()
{
  memset(head, -1, n*sizeof head[0]);
  ne=0;
}

void addEdge(int f, int t)
{
  nxt[ne]=head[f];
  to[ne]=t;
  head[f]=ne++;
}

void addBiEdge(int f, int t)
{
  addEdge(f,t);
  addEdge(t,f);
}

int vis[N];
int DFS(int u)
{
  if(vis[u]==1) return;
  int ret=0
  vis[u]=1;

  for(int k=head[u]; ~k; k=nxt[k])
  {
    int v = to[k];
    DFS(v);
  }
}














int main(){

}
