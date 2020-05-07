#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);

set<int> edge[51];
int N,M;

bool dfs(int n){
  vector<bool> visited(N+1,false);

  visited[n] = true;
  stack<int> st;
  st.push(n);
  while(!st.empty()){
    int m = st.top(); st.pop();
    for(const auto& v : edge[m]){
      if(visited[v])continue;
      visited[v] = true;
      st.push(v);
    }
  }

  bool flag = true;
  FOR(i,1,N+1){
    if(!visited[i])flag=false;
  }
  return flag;
}

int main(){
  cin >> N >> M;

  vector<int> a(M), b(M);

  REP(i,M){
    cin >> a[i] >> b[i];
    edge[a[i]].insert(b[i]);
    edge[b[i]].insert(a[i]);
  }

  int ans=0;

  REP(i,M){
    edge[a[i]].erase(b[i]);
    edge[b[i]].erase(a[i]);

    if(!dfs(1)){
      ans++;
    }
    edge[a[i]].insert(b[i]);
    edge[b[i]].insert(a[i]);
  }

  cout << ans << endl;
}

