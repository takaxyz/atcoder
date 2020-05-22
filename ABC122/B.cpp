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
  string s;
  cin >> s;
  int ans=0;
  int cnt=0;
  REP(i,s.size()){
    if(s[i]=='A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C'){
      cnt++;
      chmax(ans, cnt);
    }else{
      cnt = 0;
    }
  }
  cout << ans << endl;
}

