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
  cin >> n;
  string str;
  cin >> str;

  int p = 0, r = 0, s = 0;

  for(auto c : str){
    int old_p = 0, old_r = 0, old_s = 0;
    swap(old_p, p); swap(old_r, r); swap(old_s, s);

    if(c == 'R'){
      chmax(p, old_r + 1);
      chmax(p, old_s + 1);
      chmax(r, old_s);
      chmax(r, old_p);
    }else if(c == 'S'){
      chmax(s, old_r);
      chmax(s, old_p);
      chmax(r, old_s + 1);
      chmax(r, old_p + 1);
    }else{
      chmax(s, old_p + 1);
      chmax(s, old_r + 1);
      chmax(p, old_s);
      chmax(p, old_r);
    }
  }

  cout << max({p,s,r}) << endl;

}


