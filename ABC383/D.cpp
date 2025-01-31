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

using mint = modint1000000007;
// using mint = modint998244353;

struct Eratosthenes {
    // テーブル
    vector<bool> isprime;
    
    // 整数 i を割り切る最小の素数
    vector<int> minfactor;

    // コンストラクタで篩を回す
    Eratosthenes(int N) : isprime(N+1, true),
                          minfactor(N+1, -1) {
        // 1 は予めふるい落としておく
        isprime[1] = false;
        minfactor[1] = 1;

        // 篩
        for (int p = 2; p <= N; ++p) {
            // すでに合成数であるものはスキップする
            if (!isprime[p]) continue;

            // p についての情報更新
            minfactor[p] = p;
            
            // p 以外の p の倍数から素数ラベルを剥奪
            for (int q = p * 2; q <= N; q += p) {
                // q は合成数なのでふるい落とす
                isprime[q] = false;
                
                // q は p で割り切れる旨を更新
                if (minfactor[q] == -1) minfactor[q] = p;
            }
        }
    }

    // 高速素因数分解
    // pair (素因子, 指数) の vector を返す
    vector<pair<int,int>> factorize(int n) {
        vector<pair<int,int>> res;
        while (n > 1) {
            int p = minfactor[n];
            int exp = 0;

            // n で割り切れる限り割る
            while (minfactor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }  
};

int main(){
  ll n;
  cin >> n;

  Eratosthenes era(2*1000000);

  int ans=0;
  for(ll i = 1; i*i <= n; i++){
    auto vs = era.factorize(i);
    if(vs.size()==2 && vs[0].second ==1 && vs[1].second == 1){
      ans++;
    }
    if(vs.size()==1 && vs[0].second ==4){
      ans++;
    }
  }
  cout << ans << endl;

}

