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
//const int INF=(1<<29);

int main(){
  int n,r;
  cin >> n >> r;
  string s;
  cin >> s;

  int t=-1;
  REP(i,s.size())if(s[i]=='.')t=i;

  if(t==-1){
    cout << 0 << endl;
    return 0;
  }

  int i = 0;
  int cnt = 0;
  while(i < n){
    if(s[i]=='.'){
      i += r;
      cnt += 1;
    }else i++;
  }

  cout << cnt + max(0, t-r+1) << endl;

}

