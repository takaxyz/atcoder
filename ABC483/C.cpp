#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;

using mint = modint1000000007;
// using mint = modint998244353;

bool cmp(const P &a, const P &b){
    return a.first != b.first
        ? a.first > b.first
        : a.second < b.second;
}

int main(){
  int n,m;
  cin >> n >> m;
  vi cnt(n);
  vvi second(n,vi());
  REP(_,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    cnt[a]++;
    second[a].pb(b);
  }
  vector<P> vs(n);
  REP(i,n)vs[i] = {cnt[i],i};
  sort(ALL(vs),cmp);


  REP(i,n){
    map<int,int> mp;
    REP(j,2)mp[vs[j].second] = vs[j].first;
    mp[i]=0;
    for(auto x: second[i]){
      if(mp.count(x)==0){
        mp[x] = cnt[x] + 1;
      }else{
        mp[x]++;
      }
    }
    vector<P> vs2;
    for(auto [k,v]: mp)vs2.pb({v,k});
    sort(ALL(vs2), cmp);
    cout << vs2[0].second + 1 << endl;
  }
}

