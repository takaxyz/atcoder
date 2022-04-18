#include <bits/stdc++.h>
using namespace std;

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
  int n, x, y;
  cin >> n >> x >> y;
  vi a(n);
  REP(i,n)cin >> a[i];

  if(x==y){
    int prev=-1;
    ll c=0;
    ll ans = 0;
    REP(i,n){
      if(a[i]==x)c++;
      else{
        if(c>0){
          ans += c * (c+1) / 2;
        }
        c = 0;
      }
    }
    if(c>0)ans += c*(c+1)/2;
    cout << ans << endl;
    return 0;

  }

  vi mi, mx, mo;
  REP(i,n){
    if(a[i] == y)mi.push_back(i);
    else if(a[i] == x)mx.push_back(i);
    else if(a[i] > x || y > a[i])mo.push_back(i);
  }

  ll ans=0;
  REP(i,n){
    if(a[i] > x || y > a[i])continue;
    auto it1 = lower_bound(ALL(mi), i);
    auto it2 = lower_bound(ALL(mx), i);
    auto it3 = lower_bound(ALL(mo), i);

    if(it1 == mi.end() || it2 == mx.end())break;
    int r = max(*it1, *it2);
    int rr;
    if(it3 == mo.end())rr=n;
    else rr=*it3;

    if(r > rr)continue;
    ans += rr - r;
  }
  cout << ans << endl;
}

