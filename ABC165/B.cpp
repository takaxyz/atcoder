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
  ll x;
  cin >> x;
 
  ll n = 100;
  int cnt = 0;
  while(n < x){
    n = (ll)n * 1.01;
    cnt++;
  }
  cout << cnt << endl;
}