#include <bits/stdc++.h>
using namespace std;
int main()
{
  int k,n;
  int aa[50200]={},bb[50200]={},cc[50200]={},result[3];
  for(int a=0;a<224;a++)
  {
    for(int b=0;b<224;b++)
    {
      for(int c=0;c<224;c++)
      {
        if ((a*a)+(b*b)+(c*c)>50000)
        {
          break;
        }
        k=(a*a)+(b*b)+(c*c);
        if ((cc[k]!=0)||(bb[k]!=0)||(aa[k]!=0))
        {
          continue;
        }
        aa[k]=a;
        bb[k]=b;
        cc[k]=c;
      }

    }
  }
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>k;
    if ((cc[k]==0)&&(bb[k]==0)&&(aa[k]==0)&&(k!=0)) {
      printf("%d\n",-1);
      continue;
    }
    result[0]=aa[k];
    result[1]=bb[k];
    result[2]=cc[k];
    sort(result,result+3);
    printf("%d %d %d\n", result[0], result[1],result[2]);
  }
  return 0;
}
