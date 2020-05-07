#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  string s;
  cin >> s;

  reverse(ALL(s));

  int n = 1;
  vector<int> moda;
  REP(i,s.size()){
    int m = s[i] - '0';
    moda.emplace_back((n * m) % 2019);
    
    n = (n * 10) % 2019;
  }

  map<int, int> mp;
  mp[0]=1;
  int t = 0;
  REP(i,moda.size()){
    t = (t + moda[i]) % 2019;
    mp[t]++;
  }
  
  // REP(i,moda.size()){
  //   cout << moda[i] << endl;
  // }

  ll ans=0;
  for(auto &v: mp){
    ans += (v.second * (v.second - 1))/2;
  }

  cout << ans << endl;

}

