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
  int N;
  cin >> N;

  vector<vector<char>> a(N,vector<char>(N));

  REP(i,N)REP(j,N){
    char c;
    cin >> a[i][j];
  }

  string ans;
  REP(i,N/2){
    bool ok=false;
    REP(j,N)REP(k,N){
      if(a[i][j] == a[N-1-i][k]){
        ok=true;
        ans += a[i][j];
        break;
      }
    }
    if(!ok){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans;

  if(N%2==1){
    cout << a[N/2][0];
  }

  reverse(ALL(ans));
  cout << ans << endl;
}

