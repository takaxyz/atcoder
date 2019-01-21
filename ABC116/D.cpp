#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
#include<iomanip>
#include <queue>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
#define MAXS(x,y) (x = max(x,y))
#define MINS(x,y) (x = min(x,y))

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

ll f[100001];
int N, K;

int main(){
  cin >> N >> K;

  priority_queue<int, vector<int>, greater<int> > pq;

  vector<pair<int, int> > td;
  set<int> s;

  REP(i,N){
    ll t,d;
    cin >> t >> d;
    td.push_back(make_pair(d,t));
  }
  sort(td.begin(), td.end(), greater<pair<int, int> >());

  ll ans = 0;
  REP(i,K){
    ans += td[i].first;
    if(s.find(td[i].second) == s.end()){
      s.insert(td[i].second);
    }else{
      pq.push(td[i].first);
    }
  }

  ll f = ans;
  ans = ans + s.size() * s.size();

  FOR(i,K,N){
    if(pq.empty())break;
    if(s.count(td[i].second))continue;
    s.insert(td[i].second);
    f -= pq.top(); pq.pop();
    f += td[i].first;
    ans = max(ans, (ll)(f + s.size() * s.size()));
  }
  cout << ans << endl;


}