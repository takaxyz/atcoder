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

ll b8tolong(string s){
  ll ret = 0;
  for(auto c: s){
    ret *= 8;
    ret += (int)(c - '0');
  }
  return ret;
}

string longtob9(ll x){
  string ret="";

  while(x > 0){
    ret = char('0' + x % 9) + ret;
    x /= 9;
  }

  return (ret == "" ? "0" : ret);

}

int main(){
  string n;
  int k;
  cin >> n >> k;
  REP(_,k){
    n = longtob9(b8tolong(n));
    REP(i,n.size()){
      if(n[i]=='8')n[i]='5';
    }
  }
  cout << n << endl;
}

