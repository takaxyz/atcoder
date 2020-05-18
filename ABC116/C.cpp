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
  cin >> n;
  VI h(n);
  REP(i,n)cin >> h[i];

  bool flag=true;
  int ans=0;
  while(flag){
    REP(i,n){
      if(i>0){
        if(h[i]>0 && h[i-1]==0)ans++;
      }else{
        if(h[i]>0)ans++;
      }
    }
    flag=false;
    REP(i,n){
      if(h[i]>0)h[i]--;
      if(h[i]>0)flag=true;
    }
  }
  cout << ans << endl;
}

