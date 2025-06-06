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

struct Trie {
  vvi to;
  vi is_x,is_y;

  Trie(): to(1,vi(26,-1)), is_x(500001), is_y(500001) {}
  int ans=0;

  int addx(string s){
    int v = 0;
    REP(i,s.size()){
      int cn = s[i] - 'a';
      if(to[v][cn] == -1){
        to[v][cn] = to.size();
        to.emplace_back(vi(26,-1));
      }
      v = to[v][cn];
    }

    is_x[v] = 1;

    if(is_y[v]){
      ans -= is_y[v];
      is_y[v]=0;
    }
    REP(i,26)if(to[v][i]!=-1)addx2(to[v][i]);    
    to[v] = vi(26,-1);
    return ans;
  }

  void addx2(int v){
    if(is_y[v])ans-=is_y[v];
    REP(i,26){    
      if(to[v][i]==-1)continue;
      addx2(to[v][i]);
    }
  }

  int addy(string s){
    int v = 0;
    REP(i,s.size()){
      int cn = s[i] - 'a';
      if(to[v][cn] == -1){
        to[v][cn] = to.size();
        to.emplace_back(vi(26,-1));
      }
      v = to[v][cn];

      if(is_x[v]){
        return ans;
      }
    }
    is_y[v]++;
    ans++;
    return ans;
  }

};

Trie trie;

int main(){
  int q;
  cin >> q;
  REP(_, q){
    int t;
    string s;
    cin >> t >> s;
    if(t == 1){
      cout << trie.addx(s) << endl;
    }else{
      cout << trie.addy(s) << endl;
    }
  }
}

