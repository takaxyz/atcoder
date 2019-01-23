#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<iomanip>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
#define MAXS(x,y) (x = max(x,y))
#define MINS(x,y) (x = min(x,y))

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int N,M;
vector<vector<pair<int, int> > > e;
vector<bool> visited;
vector<ll> pos;

void dp(int n, int p){
//  cout << n << " " << p << endl;
  if(visited[n]){
    if(pos[n] != p){
      cout << "No" << endl;
      exit(0);
    }else{
      return;
    }
  }

  pos[n] = p;
  visited[n] = true;
  REP(i,e[n].size()){
    dp(e[n][i].first, p + e[n][i].second);
  }

}

int main(){
  cin >> N >> M;

  e.resize(N+1);
  visited.resize(N+1);
  pos.resize(N+1);

  REP(i,M){
    int l,r,d;

    cin >> l >> r >> d;
    e[l].push_back(make_pair(r,d));
    e[r].push_back(make_pair(l,-d));
  }
  
  FOR(i,1,N+1){
    if(visited[i])continue;
    dp(i,0);
  }

  cout << "Yes" << endl;

}