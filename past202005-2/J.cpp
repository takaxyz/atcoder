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
  int N,M;
  cin >> N >> M;
  VI d(N,0);

  REP(i,M){
    int a;
    cin >> a;
    a *= -1;

    auto iter = upper_bound(ALL(d), a);
    if(iter==d.end()){
      cout << -1 << endl;
    }else{
      *iter = a;
      cout << (iter - d.begin()) + 1 << endl;
    }
  }
}

