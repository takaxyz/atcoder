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
  int a,b;
  ll c;
  cin >> a >> b >> c;

  int d=0;
  REP(i,60){
    if((c >> i)&1)d++;
  }

  if((d % 2) != abs(a-b) % 2){
    cout << -1 << endl;
    return 0;
  }

  if((a + b + d) % 2 != 0 || a + b + d > 120 || a > b + d || b > d + a || d > a + b){
        cout << "-1" << endl;
        return 0;
  }
  //cout << d << endl;

  int a1,b1;
  if(a>b){
    a1 = (d - (a-b))/2 + (a-b);
    b1 = (d - (a-b))/2;
  }else{
    a1 = (d - (b-a))/2;
    b1 = (d - (b-a))/2 + (b-a);;
  }

  int x1 = a - a1;
  if(x1<0){
    cout << -1 << endl;
    return 0;
  }

  //cout << a1 << " " << b1 << " " << x1 << endl;
  //return 0;

  ll x=0,y=0;
  REP(i,60){
    if((c>>i)&1){
      if(a1>0){
        x += (1LL<<i);
        a1--;
      }else if(b1>0){
        y += (1LL<<i);
        b1--;
      }
    }else{
      if(x1>0){
        x += (1LL<<i);
        y += (1LL<<i);
        x1--;
      }
    }

  }
  cout << x << " " << y << endl;
}

