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

ll mpow(ll x, ll n){
  if(n==0)return 1;

  ll y = mpow(x, n/2);
  y *= y;

  if(n%2==1) y *=x;
  return y;
}

int main(){
  ll n;
  cin >> n;


  FOR(i,1,20){
    ll x = mpow(26,i);
    if(n <= x){
      string ans = "";
      n--;
      REP(j,i){
        ans += 'a' + (n%26);
        n /= 26;
      }
      reverse(ALL(ans));
      PRINT(ans);
      break;
    }else{
      n -= x;
    }
  }
}

