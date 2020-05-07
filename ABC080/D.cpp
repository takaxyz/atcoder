#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);



int main(){
  int N,C;
  cin >> N >> C;

  vector<vector<pair<int, int>>> st(C+1);

  REP(i,N){
    int s,t,c;
    cin >> s >> t>> c;
    st[c].push_back(make_pair(s,t));
  }

  vector<int> sum(200001,0);

  FOR(i,1,C+1){
    sort(ALL(st[i]));
    REP(j,st[i].size()){
      if(j>0 && st[i][j-1].second == st[i][j].first){
        sum[st[i][j].first*2+1] += 1;
        sum[st[i][j].second*2+1] -= 1;        
      }else{
        sum[st[i][j].first*2-1] += 1;
        sum[st[i][j].second*2+1] -= 1;        
      }
    }

  }

  FOR(i,1,sum.size()){
    sum[i] += sum[i-1];
  }

  int ans=0;
  FOR(i,1,sum.size()){
    ans = max(ans,sum[i]);
  }
  cout << ans << endl;
}

