#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; ++i) a[i] = b[i] = N;

    ll black = ll(N - 2) * (N - 2);

    int H = N, W = N;

    while (Q--) {
        int t, x;
        cin >> t >> x;
        printf("q : %d %d\n", t, x);

        if (t == 1) {
            if (x < W) {
                for (int i = x; i < W; ++i) {
                    b[i] = H;
                    printf("b[%d] -> %d\n",i,H);
                }
                W = x;
            }
            black -= b[x] - 2;

        } else {
            if (x < H) {
                for (int i = x; i < H; ++i) {
                    a[i] = W;
                    printf("a[%d] -> %d\n",i,W);
                }
                H = x;
            }
            black -= a[x] - 2;
        }

        for(int i = 2; i < N; i++){         
          printf("a[%d] = %d\n", i, a[i]);
        }
        for(int i = 2; i < N; i++){
          printf("b[%d] = %d\n", i, b[i]);
        }
        printf("W = %d H = %d\n", W, H);
        printf("black: %d\n", black);
    }
    cout << black << endl;

    return 0;
}
