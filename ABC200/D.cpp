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
  int n;
  cin >> n;
  vi a(n);
  REP(i,n)cin >> a[i];

  vvi cnt(200);

  int m = min(8,n);
  FOR(i, 1, 1<<m){
    int mod=0;
    REP(j,m){
      if(i & (1<<j)){
        mod += a[j];
        mod %= 200;
      }
    }
    cnt[mod].push_back(i);
  }

  bool ok = false;
  REP(i,200){
    if(cnt[i].size()>1){
      cout << "Yes" << endl;
      REP(j,2){
        int mask = cnt[i][j];
        vi arr;

        REP(k, m)if(mask & (1<<k))arr.push_back(k+1);

        cout << arr.size() << " ";
        REP(k, arr.size()){
          cout << arr[k] << (k == arr.size()-1 ? "\n" : " ");
        }
      }
      return 0;
    }
  }

  cout << "No" << endl;
}

