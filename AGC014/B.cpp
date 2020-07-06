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
//const int INF=(1<<29);

int main(){
  int n,m;
  cin >> n >> m;
  map<int,int> mp;
  REP(i,m){
    int a,b;
    cin >> a >> b;
    mp[a]++; mp[b]++;
  }

  bool ok=true;
  for(auto v: mp){
    if(v.second%2!=0)ok=false;
  }
  cout << (ok ? "YES" : "NO") << endl;
}

