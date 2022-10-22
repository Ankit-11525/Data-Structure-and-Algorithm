Alice and Bob have an undirected graph of n nodes and three types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can be traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

 

Example 1:



Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
Example 2:



Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
Example 3:



Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 

 

Constraints:
1 <= n <= 105
1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
edges[i].length == 3
1 <= typei <= 3
1 <= ui < vi <= n
All tuples (typei, ui, vi) are distinct









CODE:
///


    
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
