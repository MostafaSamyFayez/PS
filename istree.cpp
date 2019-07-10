#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5, M=1e6+6, OO = 0x3f3f3f3f;

int ne, nxt[M], to[M], head[N];
int n, m, u, v;
int vis[N];

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

int DFS(int u)
{
  if(vis[u]) return 0;
  int ret =1;
  vis[u]=1;
  for(int k= head[u]; ~k; k=nxt[k])
  {
    int v= to[k];
    ret+=DFS(v);
  }
  return ret;
}

int main()
{
  scanf("%d %d", &n, &m);
  if((m!=n-1)) return puts("NO"), 0;
  init();
  while(m--){
  scanf("%d %d", &u, &v);
  --u, --v;
  addBiEdge(u, v);
}
  if(DFS(0) == n) puts("YES");
  else puts("NO");
return 0;
}
