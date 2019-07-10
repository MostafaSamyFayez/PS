/*
TASK: comehome
LANG: C++14
 */
/*
#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+5, M = 2e4, OO = 0x3f3f3f3f;

int n, m, c;
char u, v;

//int adj[N][N];

int dist[N], nVis[N];
void dijkstra(int src){
    // Assign arrayes and variablers that we will use and itialize it's values
    memset(dist, OO, sizeof dist);
    dist[src] = 0;
    iota(nVis, nVis+n, 0);
    int nxt = src, s = n;
    //start Dijkstra loop
    while(nxt != -1){
        //update the root variable which we will loop on it's chilred and clear the previous one
        int u = nVis[nxt];      //Minimum Node
        nVis[nxt] = nVis[--s];
        nxt = -1;
        int mn = OO;
        //
        for(int k = 0 ; k < s ; ++k){
            int v = nVis[k];
            int d = dist[u] + adj[u][v];
            if(dist[v] > d)         //Relax
                dist[v] = d;
            if(mn > dist[v]){
                mn = dist[v];
                nxt = k;
            }
        }
    }
}

int ne, head[N], nxt[M], to[M], cost[M];

void init(){
    memset(head, -1, n*sizeof(head[0]));
    ne = 0;
}

void addEdge(int f, int t, int c){
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int a, int b, int c){
    addEdge(a, b, c);
    addEdge(b, a, c);
}

void dijkstraSparse(int src){
    memset(dist, OO, sizeof dist);
    dist[src] = 0;
    priority_queue<pair<int, int>> q; // to put distances in at to easy pick min dis
    q.push({0, src});
    while(q.size()){
        int d = -q.top().first;
        int u = q.top().second;
        q.pop();
        if(d != dist[u])    continue;
        for(int e = head[u] ; ~e ; e = nxt[e]){
            int v = to[e];
            int dd = d + cost[e];
            if(dist[v] > dd){
                dist[v] = dd;
                q.push({-dd, v});
            }
        }
    }
}

int main(){
    freopen("comehome.in", "rt", stdin);
    freopen("comehome.out", "wt", stdout);
    n = 128;
    scanf("%d", &m);
    memset(adj, OO, sizeof adj);
    init();
    while(m--){
        scanf(" %c %c %d", &u, &v, &c);
        // adj[u][v] = min(adj[u][v], c);
        // adj[v][u] = min(adj[v][u], c);
        addBiEdge(u, v, c);
    }
    dijkstraSparse('Z');
    char c = min_element(dist+'A', dist+'Z')-dist;
    printf("%c %d\n", c, dist[c]);
    return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5, M = 2e6, OO = 0x3f3f3f3f;

int n, m, c,t,st,en;
int u, v;



int dist[M], nVis[M];
int ne, head[M], nxt[M], to[M], cost[M];

void init()
{
  memset(head, -1, sizeof head);
  ne=0;
}

  void addEdge(int f, int t, int c){
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
  }

void addBiEdge(int a, int b, int c){
    addEdge(a, b, c);
    addEdge(b, a, c);
}

void dijkstraSparse(int src){
    memset(dist, OO, sizeof dist);
    dist[src] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, src});
    while(q.size()){
        int d = -q.top().first;
        int u = q.top().second;
        q.pop();
        //if(d != dist[u])    continue;
        for(int e = head[u] ; ~e ; e = nxt[e]){
            int v = to[e];
            int dd = d + cost[e];
            if(dist[v] > dd){
                dist[v] = dd;
                q.push({-dd, v});
            }
        }
    }
}
int main(){
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &n, &m, &st, &en);
        init();
        en--;
        st--;
        while(m--){
            scanf("%d %d %d", &u, &v, &c);
            --u;
            --v;
            addBiEdge(u, v, c);
        }
        /*for(int i=0;i<n;++i)
        {
        for(int e = head[i] ; ~e ; e = nxt[e]){
            int v = to[e];
            cout << (i+1) <<" "<<(v+1)<<" cost is: " <<cost[e]<<endl;
          }
        }*/

        dijkstraSparse(st);
        if(dist[en] == OO) puts("NONE");
        else printf("%d\n", dist[en]);
    }
    return 0;
}
