#include <bits/stdc++.h>
using namespace std;

bool cycle_detection(const vector<vector<int>> &g)
{
    int n = g.size();
    vector<bool> visited(n, false), finished(n, false);
    auto dfs = [&](auto self, int x) -> bool
    {
        if (visited[x]) return false;
        visited[x] = true;
        for (auto y : g[x])
        {
            if (finished[y]) continue;
            if (visited[y] || self(self, y)) return true;
        }
        finished[x] = true;
        return false;
    };
    for (int i = 0; i < n; i++)
        if (dfs(dfs, i)) return true;
    return false;
}

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges;
    for (int i = 0; i < M; i++)
    {
        int U, V;
        cin >> U >> V;
        U--, V--;
        edges.push_back(make_pair(U, V));
        edges.push_back(make_pair(V, U));
    }
    int W;
    cin >> W;
    vector<string> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];

    for (int i = 0; i < N; i++)
        edges.push_back(make_pair(i, i));

    vector<vector<int>> g(N * W);
    for (auto [x, y] : edges)
        for (int i = 0; i < W; i++)
        {
            int j = (i + 1) % W;
            if (S[x][i] == 'o' && S[y][j] == 'o')
                g[N * i + x].push_back(N * j + y);
        }

    bool ans = cycle_detection(g);
    cout << (ans ? "Yes" : "No") << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--)
        solve();
}
