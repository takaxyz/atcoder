#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

vector<ll> p;
vector<vector<int> > edge;


ll dfs(int parent, int n, int k){

  fprintf(stderr,"%d %d %d\n",parent,n,k);
  if(edge[n].size()==1)return 1;

  ll ret=p[edge[n].size()-1];
//  fprintf(stderr, "%lld\n",k-2-(ll)edge[n].size()+2);
//  fprintf(stderr,"%lld\n",ret);

  REP(i,edge[n].size()){
    if(edge[n][i] == parent)continue;
    ret = (ret * dfs(n,edge[n][i],k))%MOD;
  }


  fprintf(stderr,"%lld\n",ret);

  return ret;
}


int main(){
  int N,K;
  cin >> N >> K;

  edge = vector<vector<int> > (N+1);
  p = vector<ll>(K);

  p[1] = (K-2)%MOD;
  for(int i = 2; i < K-1; i++){
    p[i] = p[i-1] * (K-1-i) % MOD;
  }

  REP(i,p.size()){
    cout << i << " " << p[i] << endl;
  }
  cout << endl;

  REP(i,K){
    int a,b;

    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  ll ans=(K*(K-1)*p[1])%MOD;

  REP(i,edge[1].size()){
    ans = (ans * dfs(1,edge[1][i],K))%MOD;
  }
  cout << ans << endl;
}

