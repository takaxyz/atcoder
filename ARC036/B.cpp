#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define p(a)       cout << (a) << endl
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);
//const int INF=(1<<29);

int main(){
  int N;
  cin >> N;
  VI h(N);
  REP(i,N)cin >> h[i];

  int ans = 0;
  REP(i,N){
    if((i==0 || h[i-1]<=h[i]) && (i==N-1 || h[i]>=h[i+1])){
      int l = i;
      while(l > 0 && h[l-1]<=h[l])l--;
      int r = i;
      while(r < N-1 && h[r]>=h[r+1])r++;
      //cout << i << " " << l << " " << r << endl;
      chmax(ans, r-l+1);
    }
  }
  p(ans);

}

