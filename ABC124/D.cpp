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
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  VI c0, c1;
  int cnt=1;
  if(s[0]=='0')c1.emplace_back(0);

  FOR(i,1,(int)s.size()){
    if(s[i]==s[i-1]){
      cnt++;
    }else if(s[i-1]=='0'){
      c0.emplace_back(cnt);
      cnt=1;
    }else{
      c1.emplace_back(cnt);
      cnt=1;
    }
  }
  if(s.back() == '0'){
    c0.emplace_back(cnt);
  }else{
    c1.emplace_back(cnt);
  }

  if(c0.size() <= k){
    cout << s.size() << endl;
    return 0;
  }

  int t=0;
  REP(i,k)t+=c0[i];
  REP(i,k+1)t+=c1[i];

  int ans=t;
  FOR(i,k,(int)c0.size()){
    t += c0[i];
    if(i+1 < c1.size())t += c1[i+1];
    t -= c0[i-k];
    t -= c1[i-k];
    chmax(ans,t);
  }
  cout << ans << endl;

}

