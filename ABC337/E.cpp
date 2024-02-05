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
  cin >> n;

  int m = 0;
  int nn=n-1;
  while(nn){
    m++;
    nn/=2;
  }

  vi f(m);

  int n2=1;
  REP(_,m)n2*=2;

  vector<bitset<128>> bs(m);

  REP(i,m){
    int c=0;
    REP(j,1<<i){
      REP(k, n2>>(i+1)){
        bs[i].set(c);
        c++;
      }
      REP(k, n2>>(i+1))c++;
    }
  }

  cout << m << endl;
  REP(i,m){
    vi x;
    REP(j,n){
      if(bs[i][j])x.pb(j+1);
    }
    cout << x.size() << " ";
    REP(j,x.size()){
      cout << x[j] << (j < x.size() - 1 ? " " : "");
    }
    cout << endl;
  }

  string s;
  cin >> s;
  bitset<128> one;
  REP(i,128)one.set(i);

  //REP(i,m)cout << bs[i] << endl;

  REP(i,m){
    if(s[i]=='0')bs[i] ^= one;
  }

//  REP(i,m)cout << bs[i] << endl;

  REP(i,m){
    one &= bs[i];
  }

//  cout << one << endl;
  REP(i,n2){
    if(one[i])cout << i + 1 << endl;
  }
}

