#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<iomanip>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

vector<vector<pair<int,ll> > > d(100001);

int color[100001];
bool visited[100001];

void dfs(int n, int col){
//  printf("%d %d\n",n,col);
  if(visited[n])return;
  visited[n] = true;
  color[n]=col;
  int col2 = col == 0 ? 1 : 0;

  REP(i,d[n].size()){
    if(d[n][i].second % 2 == 0){
      dfs(d[n][i].first, col);
    }else{
      dfs(d[n][i].first, col2);
    }
  }
}

int main(){

  int N;
  cin >> N;


  REP(i,N-1){
    int u,v;
    ll w;
    cin >> u >> v >> w;
    d[u].push_back(make_pair(v,w));
    d[v].push_back(make_pair(u,w));
  }

  // FOR(i,1,N+1){
  //   cout << i << endl;
  //   REP(j,d[i].size()){
  //     printf("%d %lld\n", d[i][j].first,d[i][j].second);
  //   }
  // }

  FOR(i,1,N+1)visited[i]=false;

  dfs(1,0);

  FOR(i,1,N+1){
    cout << color[i] << endl;
  }

}
