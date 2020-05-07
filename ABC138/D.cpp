#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int N,Q;
vector<vector<int>> edge;
vector<bool> visited;

int main(){
  cin >> N >> Q;

  edge.resize(N+1);
  visited.resize(N+1,false);

  REP(i,N-1){
    int a,b;
    cin >> a >> b;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }
  vector<int> x(N+1,0);
  vector<int> c(N+1,0);

  REP(i,Q){
    int pp,xx;
    cin >> pp >> xx;
    x[pp] += xx;
  }

  stack<int> st;

  st.push(1);
  c[1] = x[1];
  visited[1] = true;

  while(!st.empty()){
    int v = st.top(); st.pop();
    REP(i,edge[v].size()){
      if(visited[edge[v][i]])continue;

      c[edge[v][i]] = c[v] + x[edge[v][i]];

      st.push(edge[v][i]);
      visited[edge[v][i]]=true;
    }
  }

  FOR(i,1,N+1){
    cout << c[i] << (i == N ? "\n" : " ");
  }
}

