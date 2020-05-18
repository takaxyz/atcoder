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
  int N,T;
  cin >> N >> T;

  int ans = (1<<30);
  REP(i,N){
    int c,t;
    cin >> c >> t;
    if(t > T)continue;
    chmin(ans,c);
  }
  if(ans == (1<<30)){
    cout << "TLE" << endl;
  }else{
    cout << ans << endl;
  }
}

