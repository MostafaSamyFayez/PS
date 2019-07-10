#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int x)
{
  // Find floating point value of
  // square root of x.
  long double sr = sqrt(x);

  // If square root is an integer
  return ((sr - floor(sr)) == 0);
}
int main()
{
  int a , b,sum=0;
  for(int i=0;i<201;i++)
  {
    cin>>a>>b;
    if((a==0)&&(b==0))
    {
      return 0;
    }
    for(int i=a ;i<=b;i++)
    {
      if(isPerfectSquare(i))
      {
        sum++;
      }
    }
    cout << sum << endl;
    sum=0;
  }
}
//g++ hello.cpp -o test
//./test
