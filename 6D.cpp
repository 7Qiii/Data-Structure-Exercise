#include <iostream>
#include <vector>
#include <queue>
#define maxn 100
using namespace std;

vector<int> G[maxn];
int in[maxn];

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        queue<int> in0;
        vector<int> L;
        int node, edge;
        cin >> node >> edge;
        for (int i = 0; i < edge; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            G[v1].push_back(v2);
            in[v2]++;
        }
        for (int i = 1; i <= node; i++)
        {
            if (in[i] == 0)
                in0.push(i);
        }
        while (!in0.empty())
        {
            int u = in0.front();
            in0.pop();
            L.push_back(u);
            for (auto y : G[u])
            {
                if (--in[y] == 0)
                {
                    in0.push(y);
                }
            }
        }
        if (L.size() == node)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}