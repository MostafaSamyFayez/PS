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
  int tc,r,c;
  while (tc--) {
    memset(dis, OO, sizeof dis);
    cin>>row>>col;
    for(int i=0; i<row; ++i)
    {
      for(int j=0; j<col;++j)
      {
        cin>>u;
        s.insert(u);
        dis[i][j]=u;
      }
    }
    floyd();
    cout<<dis[]
  }
  return 0;
}
