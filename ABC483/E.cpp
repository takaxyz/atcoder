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

int main(){
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  REP(i,n)cin >> s[i];

  ll d0=0, d1=0, d2=0;
  unordered_map<string, ll> mp;
  REP(i,n)mp[s[i]]++;
  for(auto [k,v]: mp)d0 += v * (v-1) /2;
  mp.clear();
  //cout << d0 << endl;

  REP(i,m){
    REP(j,n){
      string t = s[j];
      t.erase(t.begin()+i);
      mp[t]++;
    }
    for(auto [k,v]: mp)d1 += v * (v-1) /2;
    mp.clear();
  }
  
  //cout << d1 << endl;

  REP(i,m)FOR(j,i+1,m){
    REP(k,n){
      string t = s[k];
      t.erase(t.begin()+j);
      t.erase(t.begin()+i);
      //cout << t << endl;
      mp[t]++;
    }
    for(auto [k,v]: mp)d2 += v * (v-1) /2;
    mp.clear();
  }

  //cout << d2 << endl;

  ll c0 = d0;
  ll c1 = d1 - c0 * m;
  ll c2 = d2 - c1*(m-1) - c0 * m * (m-1)/2;
  
  cout << c0 + c1 + c2 << endl;


}

