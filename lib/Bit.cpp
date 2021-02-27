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

// 1-indexed
template <typename T>
struct BIT{
private:
  int n;
  vector<T> d;

public:
  BIT(int _n=0){
    n = _n;
    d = vector<T>(n+1);
  }

  void add(int i, T x){
    for(i++; i <= n; i+=i&-i)d[i]+=x;
  }
  // [1,i] 
  T sum(int i){
    T x = 0;
    for(i++; i > 0; i-=i&-i)x+=d[i];
    return x;
  }
  // [i,j] 
  T sum(int i, int j){
    return sum(j) - sum(i-1);
  }
};


int main(){
  BIT<int> bit(10);
  bit.add(1,1);
  bit.add(3,1);

  REP(i,11){
    cout << i  << " " << bit.sum(i) << endl;
  }
}

