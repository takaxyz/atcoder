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

void solve(ll a, ll s){
  int d=0;
  while(a > 0 || s > 0){
    //cout << (a&1) << " " << (s&1) << " " << d << endl;;
    if(d==0){
      if(a%2 == 1){
        if(s%2 == 1){
          cout << "No" << endl;
          return;
        }else{
          d=1;
        }
      }else{

      }
    }else{
      if(a%2 == 1){
        if(s%2 == 1){

        }else{
          cout << "No" << endl;
          return;
        }
      }else{
        if(s%2 == 1){
          // 0, 0
          d = 0;
        }else{
          // 0, 1
        }
      }
    }
    a/=2; s/=2;
  }
  if(d==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}

int main(){
  int t;
  cin >> t;
  REP(i,t){
    ll a, s;
    cin >> a >> s;
    solve(a,s);
  }

}

