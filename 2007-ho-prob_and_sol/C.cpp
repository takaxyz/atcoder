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
  int n;
  cin >> n;

  VI x(n), y(n);

  set<pair<int,int>> st;

  REP(i,n){
    cin >> x[i] >> y[i];
    st.insert(make_pair(x[i],y[i]));
  }
  int ans=0;
  REP(i,n)FOR(j,i+1,n){
    int dx = x[j] - x[i];
    int dy = y[j] - y[i];

    if(st.count(make_pair(x[j]+dy, y[j]-dx)) && st.count(make_pair(x[i]+dy, y[i]-dx))){  
      ans = max(ans, dx*dx + dy*dy);
    }else if(st.count(make_pair(x[j]-dy, y[j]+dx)) && st.count(make_pair(x[i]-dy, y[i]+dx))){
      ans = max(ans, dx*dx + dy*dy);
    }
  }
  cout << ans << endl;
}

