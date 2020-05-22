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

ll f(ll n){
  switch (n%4)
  {
  case 0:
    return n;
    break;
  case 1:
    return 1;
    break;
  case 2:
    return n^1;
    break;
  case 3:
    return 0;
    break;
  }
  return 0;
}

int main(){
  ll a, b;
  cin >> a >> b;

  cout << (f(b) ^ f(a-1)) << endl;
}
