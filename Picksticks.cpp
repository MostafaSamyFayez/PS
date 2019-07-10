#include <bits/stdc++.h>

using namespace std;
const int N = 1e6+5, M = 1e6+6, OO = 0x3f3f3f3f;

int n, ne, head[N], nxt[M], to[M];
int m, u, v;

void init(){
  memset(head, -1, n*sizeof head[0]);
  // memset(head, -1, sizeof head);
  ne = 0;
}

void addEdge(int f, int t){
  to[ne] = t;
  nxt[ne] = head[f];
  head[f] = ne++;
}

void addBiEdge(int a, int b){
  addEdge(a, b);
  addEdge(b, a);
}

int vis[N];
vector<int>sol;

int DFS(int u){
  if(vis[u]&&ret!=n)  puts("IMPOSSIBLE"), 0;
  int ret = 1;
  vis[u] = 1;
  for(int k = head[u] ; ~k ; k = nxt[k]){
    int v = to[k];
    ret += DFS(v);
  }
  return ret;
}

int main(){
  scanf("%d %d", &n, &m);
  if(n != m+1)  return puts("NO"), 0;
  init();
  while(m--){
    scanf("%d %d", &u, &v);
    --u, --v;
    addBiEdge(u, v);
  }
  if(DFS(0) == ) puts("YES");
  else puts("NO");
  return 0;
}
