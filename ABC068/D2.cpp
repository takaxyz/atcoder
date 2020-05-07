#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);

int main(){
    int K;
    cin >> K;
    const int N = 50;
    int base = K / N;
    int simulation = K % N;
    vector<int> ans(N, N - 1 + base);
    while (simulation != 0) {
        --simulation;
        ans[simulation] += N;
        for (int i = 0; i < N; i++) {
            if (i == simulation) continue;
            ans[i]--;
        }
    }
    cout << N << endl;
    for (int i = 0; i < N; i++) cout << ans[i] << (i == N - 1 ? '\n' : ' ');
    
}

