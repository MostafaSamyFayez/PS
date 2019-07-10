#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<string,int> &a, const pair<string,int> &b)
{
    return (a.second < b.second);
}

int main()
{/*
  // $$$$$$$$$$$$$$$$$$$$ vector of pairs $$$$$$$$$$$$$$$$$$$
  vector< pair <string, int> > age;
  age.push_back( make_pair("mostafa",23) );
  age.push_back( make_pair("sara",19) );
  age.push_back( make_pair("ahmed",28) );
  age.push_back( make_pair("sami",62) );
  age.push_back( make_pair("maysa",55) );

sort(age.begin(), age.end(),sortbysec);
for(int i=0 ; i<5; i++)
{
  cout<<age[i].first<<" :"<<age[i].second<<endl;
}*/

/*
//$$$$$$$$$$$$$$$$$$$$$$$$$ pair of pairs $$$$$$$$$$$$$$$$$$$$$$$$
pair< pair<string,int>,pair<string,int>> customer;
customer.first.first="ahmed";
customer.first.second=29;
customer.second.first="engineer";
customer.second.second=1000;

cout<<customer.first.first<<endl;
cout<<customer.first.second<<endl;
cout<<customer.second.first<<endl;
cout<<customer.second.second<<endl;
*/

//$$$$$$$$$$$$$$$$$$$$$$ vector $$$$$$$$$$$$$$$$$$$$$$$$$
/*
vector<int>v;
int x;
while(x!=0)
{
  cin>>x;
  v.push_back(x);
}
//v.insert(v.begin(),9);
v.erase(v.begin()+2);

//sort(v.begin(),v.end());
cout<<endl;
for (int i=0; i<v.size();i++)
{
  cout <<v[i]<<endl;
}
cout<<endl<<endl<<v.size();
*/
stack<int> t;
int x=1,size;
while(x!=0)
{
  cin>>x;
  t.push(x);
}
cout<<endl<<endl;
size=t.size();
cout<<size<<endl<<endl;
while(size!=0)
{
cout<<(t.top());
t.pop();
size--;
}
}






















//g++ hello.cpp -o test
//./test
