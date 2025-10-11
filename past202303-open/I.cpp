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
  int n;
  string x;
  cin >> n >> x;
  vector<string> s(n);
  REP(i,n)cin >> s[i];

  vector<tuple<int, int, int>> score(n);
  REP(i,n){
    vector<P> vs;
    REP(j,(1<<4)){
      if(__builtin_popcount(j) != 2)continue;
      vector<int> cnt(26);
      REP(jj,4){
        if((j >> jj) & 1)cnt[s[i][jj] - 'A']++;
      }
      REP(k,(1<<5)){
        if(__builtin_popcount(k) != 3)continue;
        vector<int> cnt2 = cnt;
        REP(kk,5){
          if((k>>kk)&1){
            cnt2[x[kk]- 'A']++;
          }
        }

        int nn = -1;
        int cc = -1;
        REP(l, 26){
          if(nn < cnt2[l]){
            nn = cnt2[l];
            cc = l;
          }
        }
        vs.pb({-nn,cc});
      }      
    }
    sort(ALL(vs));
    score[i] = {vs[0].first,vs[0].second,i+1};
  }
  sort(ALL(score));

  cout << get<2>(score[0]) << endl;
}

