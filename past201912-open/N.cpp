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
//const int INF=(1<<29);

int main(){
  int n, w, c;
  cin >> n >> w >> c;
  vector<pair<int,int>> st, ed;

  REP(i,n){
    int l,r;
    int p;
    cin >> l >> r >> p;
    st.emplace_back(make_pair(l,p));
    ed.emplace_back(make_pair(r,p));
  }
  sort(ALL(st));
  sort(ALL(ed));

  int l=0;
  int r=0;

  ll now=0;
  int si=0;
  int ei=0;
  ll ans = INF;
  while(r<=c){
    while(si < st.size() && st[si].first < r){
      now += st[si].second;
      si++;
    }
    r++;
  }
  r--;
  chmin(ans, now);
//  cout <<l << " " << r << " " <<  now << endl;

  while(r<w){
    r++;
    while(si < st.size() && st[si].first < r){
      now += st[si].second;
      si++;
    }
    l++;
    while(ei < ed.size() && ed[ei].first == l){
      now -= ed[ei].second;
      ei++;
    }
    //cout <<l << " " << r << " " <<  now << endl;
    chmin(ans,now);
  }
  cout << ans << endl;  
}

