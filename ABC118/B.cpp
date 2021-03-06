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
  int n,m;
  cin >> n >> m;
  VI s(m,0);

  REP(i,n){
    int k;
    cin >> k;
    REP(j,k){
      int a;
      cin >> a;
      s[--a]++;
    }
  }
  int ans=0;
  REP(i,m){
    if(s[i]==n)ans++;
  }
  cout << ans << endl;
}

