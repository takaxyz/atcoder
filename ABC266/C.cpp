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

int check(P a, P b, P c){
  P ba = {a.first - b.first, a.second - b.second};
  P bc = {c.first - b.first, c.second - b.second};

  return ba.first * bc.second - ba.second * bc.first;
}


int main(){
  vector<P> p(4);

  REP(i,4)cin >> p[i].first >> p[i].second;

  // a : 0, b: 1 c: 2, d:3
  REP(i,4){
    if(check(p[(i+2)%4], p[(i+1)%4], p[i]) <= 0){
      cout << "No"  << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}

