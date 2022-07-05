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
  ll x,a,d,n;
  cin >> x >> a >> d >> n;


  if(d==0){
    cout << abs(x-a) << endl;
    return 0;
  }

  if(d > 0){
    ll r = a + d * (n-1);

    if(r < x){
      cout << x - r << endl;
    }else if(x < a){
     cout << a - x << endl;
    }else{
      ll y = (x - a) / d * d + a;
      cout << min(x-y, y + d - x) << endl;
    }
  }else{
    ll r = a + d * (n-1);

    if(r > x){
      cout << r - x << endl;
    }else if(x > a){
     cout << x - a << endl;
    }else{
      ll y = (x - a) / d * d + a;
      cout << min(y - x, x - y - d) << endl;
    }
  }
}

