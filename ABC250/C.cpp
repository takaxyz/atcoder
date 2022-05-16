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

int main(){
  int n,q;
  cin >> n >> q;
  vi a(n+1), p(n+1);
  REP(i,n+1){
    a[i]=i;
    p[i]=i;
  }

  REP(i,q){
    int x;
    cin >> x;
    if(p[x]==n){
      swap(a[n-1],a[n]);
      p[a[n]]=n;
      p[a[n-1]]=n-1;
    }else{
      int pos = p[x];
      swap(a[pos],a[pos+1]);
      p[a[pos]] = pos;
      p[a[pos+1]] = pos+1;
    }
  }
  REP(i,n){
    cout << a[i+1] << endl;
  }
}

