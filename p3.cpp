#include <bits/stdc++.h>
using namespace std;
int main()
{
  int l,dist=0,start=0,end=0,min_dist=0,flagr=0,flagd=0,flagx=0;
  string a;
  for(int i=0;i<2000000;i++)
  {
  dist=0;start=0;end=0;min_dist=0;flagr=0;flagd=0;flagx=0;
  cin>>l;
  if(l==0)
  {
    return 0;
  }
  cin>>a;
  for(int i=0;i<l;i++)
  {
    if(a[i]=='Z')
    {
      min_dist=0;
      break;
    }
    if(a[i]=='R')
    {
      flagr=1;
      start=i;
      if(flagd==1)
      {
      dist=abs(start-end);
      if(flagx==0)
      {
        min_dist=dist;
        flagx=1;
      }
      min_dist=min(dist,min_dist);
      }
    }
    if(a[i]=='D')
    {
      flagd=1;
      end=i;
      if(flagr==1)
      {
        dist=abs(start-end);
        if(flagx==0)
        {
          min_dist=dist;
          flagx=1;
        }
        min_dist=min(dist,min_dist);
      }
    }
  }
  cout<<min_dist<<endl;
}
}
