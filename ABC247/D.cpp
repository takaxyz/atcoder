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
  int Q;
  cin >> Q;
  deque<pair<ll, ll>> q;

  REP(_, Q){
    int t;
    ll x, c;
    cin >> t;

    if(t == 1){
      cin >> x >> c;
      q.push_back({x,c});
    }else{
      cin >> c;
      ll sum=0;
      while(c){
        ll cx = q.front().first;
        ll cc = q.front().second;
        q.pop_front();

        if(cc > c){
          sum += c * cx;
          q.push_front({cx, cc - c});
          break;
        }else{
          c -= cc;
          sum += cc * cx;
        }
      }
      cout << sum << endl;
    }
  }
}

