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
  cin >> n >> m;
  int a,b;
  vector<pair<int,int>> ba;

  REP(i,m){
    cin >> a >> b;
    ba.push_back(make_pair(b,a));
  }

  sort(ALL(ba));

  int prev_b = 0;
  int ans=0;
  for(auto &v: ba){
    int bb = v.first;
    int aa = v.second;

    if(aa >= prev_b){
      ans++;
      prev_b = bb;
    }
  }
  cout << ans << endl;
}

