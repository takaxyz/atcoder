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
const int MOD = 1e9 + 7;

int main(){
  ll l;
  int n1,n2;
  cin >> l >> n1 >> n2;
  vi v1(n1), v2(n2);
  vector<ll> l1(n1), l2(n2);

  REP(i,n1)cin >> v1[i] >> l1[i];
  REP(i,n2)cin >> v2[i] >> l2[i];
  REP(i,n1-1)l1[i+1] += l1[i];
  REP(i,n2-1)l2[i+1] += l2[i];

  ll p = 0;
  vector<tuple<int, int, ll>> v;
  int i1=0;
  int i2=0;
  while(true){
    v.emplace_back(v1[i1], v2[i2], p);
    if(l1[i1] > l2[i2]){
      p = l2[i2];
      i2++;
    }else if(l1[i1] == l2[i2]){
      p = l2[i2];
      i1++;i2++;
    }else{
      p = l1[i1];
      i1++;
    }
    if(p==l)break;
  }
  v.emplace_back(0,1,l);

  ll ans=0;
  REP(i, v.size()-1){
    auto [a1,b1,p1] = v[i];
    auto [a2,b2,p2] = v[i+1];
    if(a1==b1){
      ans += p2-p1;
    }
  }
  cout << ans << endl;
}

