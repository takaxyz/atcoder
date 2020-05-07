#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);

struct edge{
  int to;
  int dist;
};

bool dfs(int n,vector<vector<edge>> &edges, vector<bool> &visited, vector<ll> &d){
  if(visited[n])return true;

  visited[n]=true;
  queue<pair<int,ll>> q;
  q.push(make_pair(n,0));
  d[n]=0;

  while(!q.empty()){
    pair<int, ll> v = q.top(); q.pop();
    if(visited[v]){
      if(d[v] != d[edge)
    }
    
  }

}

int main(){
  int N,M;
  cin >> N >> M;

  vector<vector<edge>> edges(N+1);

  REP(i,M){
    int l,r,d;
    edges[l].push_back({r,d});
    edges[r].push_back({l,-d});
  }

  vector<bool> vesited(N+1,false);
  vector<ll> d(N+1,INF);


}

