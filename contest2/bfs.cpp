#include<bits/stdc++.h>
using namespace std;

int d[]={0,1,2,3};
string rotateClk(string s, int c)
{

}
string rotateAClk(string s, int c)
{

}
int du = dis[u];
/*steps of BFS:
1- push source node in the queue
2- compute the 8 childs of the source
3- if child not visited yet(didn't have preivious value in the map )
    then push it to the queue and asign distance value to it's map.
4- relope on the while loop and pick the front of the queue removeing it and
    calculate it's 8 childs and repeate the step 3.
Note: if a node can be accessed from one or more nodes from another branch
the Bfs will reach this node from the shortest path first so there is no need to
revisit a visited to to store it's distance.
*/

unordered_map<int, int> dis; // to store distance form the source to each node
int BFS (int src)
{
  queue<int> q;
  dis[src]=0;
  q.push(src);

  while(!q.empty())
  u=q.front();
  q.pop();
  int du = dis[u];
  for(int k=0;k<4;++k)
  {
    int v=rotateClk(tostring(u),d[k]);
    int vv=stoi(v,nullprt);
    if(!dis.count(vv)){          // if the node not visited yet
             dis[vv] = du + 1;
             q.push(vv);
         }

    q.push(vv);
    dis[vv]= du;
    q.push(vv);


    v=rotateClk(tostring(u),d[k]);
    vv=stoi(v,);
    q.push(vv);
    dis[vv]= du;
    q.push(vv);


    }
}
