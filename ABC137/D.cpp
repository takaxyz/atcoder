#include<iostream>
#include<vector>
#include <queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int, int> > ab;
  REP(i,n){
    int a,b;
    cin >> a >> b;
    ab.push_back(make_pair(a,b));
  }

  sort(ab.begin(), ab.end());
  priority_queue<int>  q;

  int j=0;
  ll ans=0;
  for(int i = 1; i <= m; i++){
    while(true){
      if(j < ab.size() && ab[j].first <= i){
        q.push(ab[j].second);
        j++;
      }else{
        break;
      }
    }
    if(!q.empty()){
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
}
