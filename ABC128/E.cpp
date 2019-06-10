#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<tuple>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int N,Q;

int main(){
  cin >> N >> Q;
  set<int> ss;
  vector<pair<ll, ll> > event;
  REP(i,N){
    ll s,t,x;
    cin >> s >> t >> x;
    event.push_back(make_pair(s-x, x));
    event.push_back(make_pair(t-x, -x));
  }

  sort(event.begin(),event.end());

  int i = 0;
  REP(j,Q){
    ll d;
    cin >> d;

    while(i < 2*N && event[i].first <= d){
      if(event[i].second > 0){
        ss.insert(event[i].second);
      }else{
        ss.erase(-event[i].second);
      }
      i++;
    }
    if(ss.empty()){
      cout << -1 << endl;
    }else{
      cout << *ss.begin() << endl;
    }
  }
}

