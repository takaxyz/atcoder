#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int N,M,X;
  cin >> N >> M >> X;

  vector<int> a(M);

  REP(i,M)cin >> a[i];
  int t = lower_bound(ALL(a),X) - a.begin();
  cout << min(t, M-t) << endl;
}

