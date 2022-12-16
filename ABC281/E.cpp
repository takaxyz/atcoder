#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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
  int n,m,k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  REP(i,n)cin >> a[i];

  ll sum=0;
  multiset<ll> ls, rs;
  vector<ll> b(m);
  REP(i,m)b[i]=a[i];
  sort(ALL(b));

  REP(i,m){
    if(i<k){
      sum += b[i];
      ls.insert(b[i]);
    }else{
      rs.insert(b[i]);
    }
  }

  cout << sum << endl;

  REP(i,n-m){
    auto mx = ls.rbegin();

    if(*mx <= a[i+m]){
      rs.insert(a[i+m]);
    }else{
      ls.insert(a[i+m]);
      sum += a[i+m];
    }

    if(*mx >= a[i]){
      ls.erase(ls.find(a[i]));
      sum -= a[i];
    }else{
      rs.erase(rs.find(a[i]));
    }

    if(ls.size()==k){
    }else if(ls.size()<k){
      auto it = rs.begin();
      ls.insert(*it);
      sum += *it;
      rs.erase(it);
    }else{
      auto it = ls.rbegin();
      sum -= *it;
      rs.insert(*it);
      ls.erase(ls.find(*it));
    }
      cout << sum << endl;

  }
}

