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
  string s;
  ll k;

  cin >> s;
  cin >> k;

  for(ll i=0; i < min(k, (ll)s.size()); i++){
    if(s[i]!='1'){
      cout << s[i] << endl;
      exit(0);
    }
  }
  cout << 1 << endl;
}

