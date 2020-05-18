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
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  REP(i,n){
    cin >> a[i];
    a[i]--;
  }

  int pos=0;
  int cnt=1;
  vector<int> ans;
  map<int,int> mp;
  ans.emplace_back(0);
  mp[0] = cnt;
  while(mp[a[pos]] == 0){
    mp[a[pos]] = ++cnt;
    ans.emplace_back(a[pos]);
    pos=a[pos];
  }

  // REP(i,ans.size()){
  //   cout << ans[i] << "   " << mp[ans[i]] << endl;
  // }

  int l = mp[a[ans.back()]]-1;
  int r = ans.size() - l;

  if(k < l){
    cout << ans[k] + 1 << endl;
  }else{
    k -= l;
    k %= r;
    cout << ans[k+l] + 1 << endl;
  }





}

