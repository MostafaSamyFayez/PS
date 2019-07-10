#include <bits/stdc++.h>
using namespace std;

const int N=1e2+6, M=1e6+6;
int ne, nxt[M],to[M],head[N];
int n,m,u,v;
int vis[N],vid;
char* sep;

void init()
{
  memset(head, -1, n*sizeof head[0]);
  ne=0;
}

void addEdge(int f,int t)
{
nxt[ne]=head[f];
to[ne]=t;
head[f]=ne++;
}
 void DFS(int u)
 {
   if(vis[u]==vid) return;
   vis[u]=vid;
   for(int k=head[u]; ~k; k=nxt[k]){
     int v=to[k];
     DFS(v);
   }
   printf("%s%d", sep, u+1);
  sep = " ";
 }


int main()
{
  while(scanf("%d %d", &n, &m), n||m)
  {
    init();
    while(m--)
    {
      scanf("%d %d",&u, &v);
      --u;--v;
      addEdge(v,u);
    }
    sep = "";
    ++vid;
    for(int i=0; i<n; ++i)
    {
      DFS(i);
    }
      puts("");
  }
  return 0;
}
