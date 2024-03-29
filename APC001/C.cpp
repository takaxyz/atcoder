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
  int l = 0, r =n;

  auto output = [&](int x) -> int{
    cout << x << endl;
    string y;
    cin >> y;
    if(y=="Vacant"){
      return -1;
    }else if(y=="Male")return 0;
    else return 1;
  };

  int last = output(0);
  if(last==-1)return 0;
  while(1){
    int mid = (l+r)/2;

    int now = output(mid);
    if(now==-1)return 0;
    if(abs(mid - l) % 2){
      if(now == last)r = mid;
      else {l = mid; last = now;}
    }else{
      if(now == last){l = mid; last=now;}
      else r = mid;
    }
  }
}
