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

  map<int,int> me,mo;
  REP(i,n){
    int m;
    cin >> m;
    if(i%2==0){
      me[m]++;
    }else{
      mo[m]++;
    }
  }

  vector<P> ev, od;
  for(auto v: me){
    ev.emplace_back(make_pair(v.second, v.first));
  }
  for(auto v: mo){
    od.emplace_back(make_pair(v.second, v.first));
  }
  sort(ev.rbegin(), ev.rend());
  sort(od.rbegin(), od.rend());

  int e1,e2,o1,o2;
  e1 = ev[0].second;
  e2 = (ev.size() > 1 ? ev[1].second : -1);
  o1 = od[0].second;
  o2 = (od.size() > 1 ? od[1].second : -1);

  if(e1!=o1){
    cout << n - me[e1] - mo[o1] << endl;
  }else{
    cout << min(n - me[e1] - mo[o2], n - me[e2] - mo[o1]) << endl;
  }

}

