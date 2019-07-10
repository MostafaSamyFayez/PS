#include<bits/stdc++.h>
using  namespace std;
const int N=1e4+4;
pair<int,int> move(pair<int,int>p, int d)
{
  pair<int,int> ret;
  switch (d) {
    case 0:ret.first=p.first;ret.second=p.second+1;
    break;
    case 1:ret.first=p.first;ret.second=p.second-1;
    break;
    case 2:ret.first=p.first+1;ret.second=p.second;
    break;
    case 3:ret.first=p.first-1;ret.second=p.second;
    break;
  }
  return ret;
}

string ptos(pair<int,int>p)
{
  return (to_string(p.first)+to_string(p.second));
}

unordered_map <string,int> disR,disc1,disc2;
unordered_map <string,int> BFS(pair<int,int> src,int row, int col, bool is)
{
  unordered_map <string,int> dis;
  queue<pair<int,int>> q;
  q.push(src);
  dis[ptos(src)]=0;

  while(!q.empty())
  {
    pair<int,int> u=q.front();
    q.pop();
    int du = dis[ptos(u)];
    for(int k=0;k<4;++k)
    {
      pair<int,int> v=move(u,k);
      if((v.first>row)||(v.second>col)||(v.first<1)||(v.second<1))
      {
        continue;
      }

      if(!dis.count(ptos(v))){
        dis[ptos(v)] = du + 1;
        q.push(v);
        //cout<<ptos(v)<<" "<<dis[ptos(v)]<<endl;
      }
    }
    if(dis.size()==(row*col)) break; // if all cells in the grid visited;
  }
  //dis[ptos(src)]=300;
  if(is==1) dis[ptos(src)]=300;
  return dis;
}
int main()
{
  int row ,col,tc;
  int x_r, y_r ,  x_c1,y_c1, x_c2,y_c2;
  pair<int,int>p;
  cin>>row>>col;
  cin>>tc;
  if(tc==0)
  {
    return 0;
  }
  for(int i=0; i<tc; ++i)
  {
    cin>>x_r>>y_r>>x_c1>>y_c1>>x_c2>>y_c2;
    p.first=x_r+1;
    p.second=y_r+1;

    disR=BFS(p,row+2,col+2,1);

    p.first=x_c1+1;
    p.second=y_c1+1;
    disc1=BFS(p,row+2,col+2,0);

    p.first=x_c2+1;
    p.second=y_c2+1;
    disc2=BFS(p,row+2,col+2,0);
    for (auto const& x : disR)
    {
      if((x.second<disc1[x.first])&&(x.second<disc2[x.first]))
      {
        cout<<"YES"<<endl;
        goto l;
      }
      //cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<"NO"<<endl;
    l:;
  }
  return 0;
}
