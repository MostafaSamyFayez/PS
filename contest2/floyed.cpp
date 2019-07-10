#include<bits/stdc++.h>
using namespace std;
const int N=35,M=1000, OO=0x3f3f3f3f;

int n;
char u, v;

int dis[N][N];
void floyd(){
    for(int k = 0 ; k < n ; ++k)
        for(int u = 0 ; u < n ; ++u)
            for(int v = 0 ; v < n ; ++v)
                dis[u][v] = min(dis[u][v], dis[u][k]+dis[k][v]);
}

int main()
{
  int m,ttl,ii=1;
  char st;
  set <char> s;
  while(1){
    //scanf("%d",&m);
    cin>>m;
    if(m==0)break;
    s.clear();
    memset(dis, OO, sizeof dis);
    while (m--){
      //scanf("%d %d",&u,&v);
      cin>>u>>v;
      dis[u][v] = 1;
      dis[v][u] = 1;
      s.insert(u);s.insert(v);
    }
      n=s.size();
      while(1){
        //scanf("%d %d",&st,&ttl );
        cin>>st>>ttl;
        if(!(st||ttl)) break;
        int sol=0;
        floyd();
        for (auto itr = s.begin(); itr != s.end(); ++itr)
        {
          if((dis[st][(*itr)]>ttl)&&(dis[st][(*itr)]!=OO)&&((*itr)!=st)) ++sol;
        }
        cout<<"Case "<<ii<<": "<<sol<<" nodes not reachable from node "<<st<<" with TTL = "<<ttl<<".";
        cout<<endl;
        ++ii;
      }
  }
  return 0;
}
