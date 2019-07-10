#include<bits/stdc++.h>
using namespace std;
const int N=10000,M=1000, OO=0x3f3f3f3f;

int ne, nxt[M], to[M], head[N],vis[N];
int u,v;
void init()
{
  memset(head, -1, sizeof head);
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
int dist[N][N];
void dijkstraSparse(int src){
    dist[src][src] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, src});
    while(q.size()){
        int d = -q.top().first;
        int u = q.top().second;
        q.pop();
        if(d != dist[src][u])    continue;
        for(int e = head[u] ; ~e ; e = nxt[e]){
            int v = to[e];
            int dd = d + 1;
            if(dist[src][v] > dd){
                dist[src][v] = dd;
                q.push({-dd, v});
            }
        }
    }
}
int main()
{
  int m,st,ttl,ii=1;
  set <int> s;
  while(1)
  {
    scanf("%d",&m);
    if(m==0)
    {
      break;
    }
    init();
    s.clear();
    while (m--)
    {
      scanf("%d %d",&u,&v );
      --u;--v;
      s.insert(u);
      s.insert(v);
      addBiEdge(u,v);
    }
    memset(dist, OO, sizeof dist);
    /*for (auto itr = s.begin(); itr != s.end(); ++itr)
    {
      dijkstraSparse(*itr);
    }*/

      while(1)
      {
        scanf("%d %d",&st,&ttl );
        //cin>>st>>ttl;
        if(!(st||ttl))
        {
          break;
        }
        int sol=0;
        if(vis[(st-1)]==0)
        {
          dijkstraSparse((st-1));
        }
        vis[(st-1)]=1;
        {
          if(dist[st-1][*itr]>ttl) ++sol;
        }
        cout<<"Case "<<ii<<": "<<sol<<" nodes not reachable from node "<<st<<" with TTL = "<<ttl<<".";
        cout<<endl;
        /*for(int i=0; i<s.size(); ++i)
        cout<<"dist ("<<st<<" , "<<(i+1)<<") is:"<<dist[st-1][i]<<endl;*/
        ++ii;
      }
  }
  return 0;
}
