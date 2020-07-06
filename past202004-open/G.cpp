#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define RALL(v) rbegin(v), rend(v)

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
  int Q;
  cin >> Q;
  queue<pair<char,ll>> q;

  REP(i,Q){
    int t;
    cin >> t;
    if(t==1){
      char c;
      ll x;
      cin >> c >> x;
      q.push(P{c,x});
    }else{
      int d;
      cin >> d;
      map<char,ll> mp;
      while(d>0 && !q.empty()){
        auto &p = q.front();
        if(d >= p.second){
          d -= p.second;
          q.pop();
          mp[p.first] += p.second;
        }else{
          p.second -= d;
          mp[p.first] += d;
          d = 0;
        }
      }
      ll ans=0;
      for(auto v: mp){
        ans += v.second * v.second;
      }
      PRINT(ans);
    }
  }


}

