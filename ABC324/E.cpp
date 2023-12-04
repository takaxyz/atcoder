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
  int n;
  string t;
  cin >> n >> t;
  vector<string> s(n);
  REP(i,n)cin >> s[i];

  vi pre(n), suf(n);
  REP(i,n){
    int j = 0;
    for(auto c: s[i]){
      if(c == t[j])j++;
      if(j==(int)t.size())break;
    }
    pre[i]=j;
  }
  REP(i,n){
    int j = t.size()-1;
    for(int k = s[i].size()-1; k >=0; k--){
      if(s[i][k] == t[j])j--;
      if(j<0)break;
    }
    suf[i]=t.size()-1-j;
  }

  // REP(i,n)cout << pre[i] << endl;
  // REP(i,n)cout << suf[i] << endl;

  vector<ll> scnt(t.size()+1);
  vector<ll> scnt2(t.size()+1);
  REP(i,n)scnt[suf[i]]++;

  for(int i = t.size(); i >=0; i--){
    if(i==t.size())scnt2[i]=scnt[i];
    else scnt2[i] = scnt[i]+scnt2[i+1]; 
  }

  // REP(i,n+1)cout << scnt2[i] << endl;

  ll ans=0;
  REP(i,n){
    ans += scnt2[t.size()-pre[i]];
  }
  cout << ans << endl;




}

