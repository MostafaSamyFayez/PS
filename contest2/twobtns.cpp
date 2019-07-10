#include <queue>
#include <unordered_map>
using namespace std;

unordered_map <int, int> dis;
// f->0   No problem
// f->1    node is greater than target there is no need for multiplication any more
// f->2   node is less than zero there is no need for subtraction or multiplication any more

int clk(int u, bool i)
{
  if(i==0)
  {
    return (u-1);
  }
    return (u*2);
}
int BFS(int n, int m)
{
  if(n>m) return n-m;
  if(n==m) return 0;
  queue<int> q;
  dis[n]=0;
  q.push(n);
  while(!q.empty())
  {
    int u = q.front();
    if(u==m)
    {
      break;
    }
    q.pop();
    if (u>m)
    {
      int du=dis[u];
      int k=clk(u,0);
      if(!dis.count(k))
      {
        q.push(k);
        dis[k]=du+1;
      }
      continue;
    }
    for(int i=0; i<2; ++i)
    {

      int du=dis[u];
      int k=clk(u,i);
      if (k<0) break;
      if(!dis.count(k))
      {
        q.push(k);
        dis[k]=du+1;
      }
    }
  }
  return 0;
}
int main(){
  int n , m, sol;
  scanf("%d %d", &n, &m);
  if(n==m)
  {
    sol=0;
    printf("%d\n", sol);
    return 0;
  }
  int ret=BFS(n,m);
  sol=dis[m];
  if(!(m>n)) sol=ret;
  printf("%d\n", sol);
  return 0;
}
