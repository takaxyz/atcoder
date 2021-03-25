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

int calc(vi &v, int x){
  vi cnt(11);
  REP(i,4)cnt[v[i]]++;
  cnt[x]++;

  int ret=0;
  FOR(i,1,10){
    int tmp=i;
    REP(j,cnt[i])tmp*=10;
    ret += tmp;
  }
  return ret;
}

int main(){
  int k;
  cin >> k;
  vi s(4),t(4);
  vi om(11);
  string ss,tt;
  cin >> ss >> tt;
  REP(i,4){
    s[i] = ss[i]-'0';
    om[s[i]]++;
  }
  REP(i,4){
    t[i] = tt[i]-'0';
    om[t[i]]++;
  }

  double ans=0;
  FOR(i,1,10){
    double tmp = 0;
    if(k - om[i]==0)continue;
    tmp = ((double)(k - om[i])) /  (9 * k - 8);
    om[i]++;
    FOR(j,1,10){
      if(k - om[j]==0)continue;
      double tmp2 = tmp * ((double)(k - om[j])) /  (9 * k - 9);
      if(calc(s,i) > calc(t,j)){
        ans += tmp2;
      }
    }
    om[i]--;
  }
  printf("%0.7f\n",ans);

}

