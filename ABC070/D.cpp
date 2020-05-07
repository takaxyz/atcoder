#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);

int N;
vector<pair<int, int>> edge[100001];
ll cost[100001];

void dfs(int n, int p, ll d){
  cost[n] = d;
  REP(i,edge[n].size()){
    if (edge[n][i].first == p)continue;
    dfs(edge[n][i].first, n, d + edge[n][i].second);
  }
}

int main(){
  cin >> N;

  REP(i,N-1){
    int a,b,c;
    cin >> a >> b >> c;
    edge[a].push_back(make_pair(b,c));
    edge[b].push_back(make_pair(a,c));
  }

  REP(i,N+1)cost[i]=-1;

  int Q,K;
  cin >> Q >> K;


  dfs(K,-1,0);

  REP(i,Q){
    int x,y;
    cin >> x >> y;
    cout << cost[x] + cost[y] << endl;
  }


}

