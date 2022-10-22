class Solution
{
public:
    class DSU
    {
    public:
        int N;
        vector<int> par, rank;
        DSU(int n)
        {
            par.assign(n + 1, 0);
            rank.assign(n + 1, 0);
            N = n + 1;
            iota(par.begin(), par.end(), 0);
        }

        int findParent(int node)
        {
            if (par[node] == node)
                return node;
            return par[node] = findParent(par[node]);
        }

        bool _union(int p, int q)
        {
            int i = findParent(p), j = findParent(q);
            if (i == j)
                return false;
            if (rank[i] < rank[j])
            {
                par[i] = j;
            }
            else
            {
                par[j] = i;
                if (rank[i] == rank[j])
                    rank[i]++;
            }
            return true;
        }
    };
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] > b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DSU a(n);
        DSU b(n);
        int counta = 1, countb = 1;
        int remove = 0;
        sort(edges.begin(), edges.end(), cmp);
        for (auto e : edges)
        {
            // cout<<e[0]<<" "<<e[1]<<" "<<e[2]<<endl;
            if (e[0] == 3)
            {
                bool tempa = a._union(e[1], e[2]);
                bool tempb = b._union(e[1], e[2]);
                if (tempa == 0 && tempb == 0)
                    remove++;
                else
                {
                    counta++, countb++;
                }
            }
            else if (e[0] == 2)
            {
                bool tempb = b._union(e[1], e[2]);
                if (tempb)
                    countb++;
                else
                    remove++;
            }
            else
            {
                bool tempa = a._union(e[1], e[2]);
                if (tempa)
                    counta++;
                else
                    remove++;
            }
        }
        if (counta == n && countb == n)
        {
            return remove;
        }
        return -1;
    }
};
