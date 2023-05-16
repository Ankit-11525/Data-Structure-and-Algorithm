
class DSU{
  public:
    int N;
    vector<int> par,size,edg;
    DSU(int n)
    {
        N=n;
        par.assign(N,0);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        size.assign(N,1);
        edg.assign(N,0);
        
    }
    int findpar(int n)
    {
        if(par[n]==n) return n;
        return par[n]=findpar(par[n]);
    }
    void _union(int u,int v)
    {
        int x=findpar(u);
        int y=findpar(v);
        if(x==y)
        {
            edg[x]++;
            return ;
        }
        if(size[x]<size[y])
        {
            par[x]=y;
            size[y]+=size[x];
            edg[y]+=edg[x]+1;
        }
        else{
            par[y]=x;
            size[x]+=size[y];
            edg[x]+=edg[y]+1;
        }
    }
};
