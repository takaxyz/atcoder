#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  int n;
  cin >> n;

  VI p(n),q(n);
  REP(i,n)cin >> p[i];
  REP(i,n)cin >> q[i];

  VI a(n);
  REP(i,n)a[i]=i+1;

  int cnt=1;
  int ai,bi;
  do{
    bool ok=true;
    REP(i,n){
      if(a[i]!=p[i])ok=false;
    }
    if(ok)ai=cnt;

    ok = true;
    REP(i,n){
      if(a[i]!=q[i])ok=false;
    }
    if(ok)bi=cnt;
    cnt++;
  }while(next_permutation(ALL(a)));
  cout << abs(ai-bi) << endl;
}

