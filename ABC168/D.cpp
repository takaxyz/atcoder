#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  int n, m;
  cin >> n >> m;

  vector<vector<int>> edge(n+1, vector<int>());

  REP(i,m){
    int a,b;
    cin >> a >> b;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  vector<bool> visited(n+1, false);
  vector<int> ans(n+1,-1);

  queue<int> q;
  q.push(1);
  visited[1]=true;

  while(!q.empty()){
    int v = q.front();
    q.pop();

    for(int nv: edge[v]){
      if(visited[nv])continue;
      ans[nv] = v;
      visited[nv] = true;
      q.push(nv);
    }
  }

  cout << "Yes" << endl;
  FOR(i,2,n+1){
    cout << ans[i] << endl;
  }

}

