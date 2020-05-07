#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int N, P;
  cin >> N >> P;

  string s;
  cin >> s;
  reverse(ALL(s));

  map<int, int> mp;
  mp[0]=1;

  ll ans = 0;
  if(P==2 || P ==5){
    REP(i,s.size()){
      int n = s[i] - '0';
      if(n%P==0)ans += N-i;
    }
  }else{

    int t=0;
    int base = 1;
    REP(i,s.size()){
      int n = s[i] - '0';

      t = (n * base + t) % P;
      base = (base * 10) % P;
      ans += mp[t%P];
      mp[t]++;
    }

  }


  cout << ans << endl;
}