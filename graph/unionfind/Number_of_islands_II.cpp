Description
Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally,
the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that
you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.
You need to return an array of size K.
                                                       Example
  
Example 1:
Input: n = 4, m = 5, A = [[1,1],[0,1],[3,3],[3,4]]
Output: [1,1,2,2]
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011

  
Example 2:
Input: n = 3, m = 3, A = [[0,0],[0,1],[2,2],[2,1]]
Output: [1,1,2,2]



class DSU {
public:
    int N;
    vector<int> par , rank;
    DSU(int n) {
        par.assign(n, 0);
        rank.assign(n, 0);
        N = n;
        for(int i=0;i<N;i++) par[i]=i;
    }

    int findParent(int node) {
        if (par[node] == node) return node;
        return par[node] = findParent(par[node]);
    }

  void _union(int p, int q) {
            int i = findParent(p), j = findParent(q);
            if (i == j) return;
            if (rank[i] < rank[j]) {
                par[i] = j;  
            } else {
                par[j] = i;
                if (rank[i] == rank[j]) rank[i]++;
            }
          
        }

};
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{
    vector<vector<int>> v(n,vector<int>(m,0));
    vector<int> sol;
    int N=(n+1)*(m+1);
    DSU dsu(N);
    int ans=0;
    for(auto e:q)
    {
        int x=e[0];
        int y=e[1];
        if( v[x][y]) 
        {
            sol.push_back(ans);
            continue;
        }
        ans++;
        v[x][y]=1;
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        for(auto f:dir)
        {
            int nx=x+f[0];
            int ny=y+f[1];
            if(nx<0 || ny <0 || nx>=n || ny>=m) continue;
            if(v[nx][ny])
            {
                if(dsu.findParent(x*m+y)!=dsu.findParent(nx*m+ny))
                {
                    dsu._union(x*m+y,nx*m+ny);
                    ans--;
                }
              
            }
        }
        sol.push_back(ans);
    }
    return sol;
}
