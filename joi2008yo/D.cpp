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
  int n,m;
  cin >> m;
  VI x1(m),y1(m);

  REP(i,m){
    cin >> x1[i] >> y1[i];
  }

  cin >> n;
  VI x2(n),y2(n);
  set<pair<int,int>> st;

  REP(i,n){
    cin >> x2[i] >> y2[i];
    st.insert({x2[i],y2[i]});
  }

  REP(i,n){
    int dx = x2[i] - x1[0];
    int dy = y2[i] - y1[0];
    bool ok=true;
    FOR(j,1,m){
      if(st.count({x1[j]+dx, y1[j]+dy}) == 0){
        ok=false;
        break;
      }
    }

    if(ok){
      cout << dx << " " << dy << endl;
      return(0);
    }
  }


}

