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
  int n,k;
  ll m,r;
  cin >> n >> k >> m >> r;
  ll sum=0;
  vector<ll> s(n-1);
  REP(i,n-1){
    cin >> s[i];
  }
  sort(RALL(s));
  REP(i,min(k,n-1))sum+=s[i];

  if(sum >= k*r){
    cout << 0 << endl;
  }else{
    if(k==n){
      ll ans = k*r - sum;
      cout << (ans <= m ? ans : -1) << endl;
    }else{
      ll ans = k*r - (sum - s[k-1]);
      cout << (ans <= m ? ans : -1) << endl;
    }
  }
}

