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
  int N,K;
  cin >> N >> K;

  vector<int> x(N),y(N);
  vector<char> c(N);

  REP(i,N)cin >> x[i] >> y[i] >> c[i];
  REP(i,N)x[i] %= 2*K;
  REP(i,N)y[i] %= 2*K;

}

