    #include <bits/stdc++.h>
    using namespace std;
    long long int bit[101005],m,bit1[101005],n;
    const int maxn=1e5+100;
     vector< pair<long long int,long long int> >v2[maxn+4],v[maxn+4];
    const long long int mod=1e9+7;
    void update(long long int idx,long long int val)
    {
        //cout<<m<<endl;
        while(idx<=maxn)
        {
            bit[idx]=(bit[idx]+val);
            idx+=idx&(-idx);
        }
    }
    void update1(long long int idx,long long int val)
    {
        //cout<<n<<endl;
        while(idx<=maxn)
        {
            bit1[idx]=(bit1[idx]+val);
        //    if(bit1[idx]>=mod)
          //      bit1[idx]=bit1[idx]%mod;
            idx+=idx&(-idx);
        }
    }
    long long query1(long long int idx)
    {
        long long s=0;
        while(idx>0)
        {
            s=(s+bit1[idx]);
            if(s>=mod)
                s=s%mod;
            idx-=idx&(-idx);
        }
        return s;
    }
    long long query(long long int idx)
    {
        long long s=0;
        while(idx>0)
        {
            s=(s+bit[idx]);
            if(s>=mod)
                s=s%mod;
            idx-=idx&(-idx);
        }
        return s;
    }
    int main()
    {
        int counterr=0;
        for(int i=0;i<1000;i++)
            counterr++;
        int t;
        scanf("%d",&t);
        while(t--)
        {
            long long int i,j,g,h,k;
             scanf("%lld%lld",&n,&m);
            map<long long int,long long int>map1,map2;

            long long int b[maxn+8];
            for(i=0;i<=maxn;i++){
                bit[i]=0;
                bit1[i]=0;
                v2[i].clear();
                v[i].clear();
                b[i]=0;
            }
            for(i=1;i<=m;i++)
            {
                cin>>g>>h>>k;
                if(g==1)
                {
                    v[i].push_back(make_pair(h,k));
                    map2[i]=1;
                   b[i]++;
                   b[i+1]--;
                }
                else
                {
                    v2[i].push_back(make_pair(h,k));
                    map1[i]=1;
                    b[h]++;
                    b[k+1]--;
                }
            }
            long long o=0;
            for(i=1;i<=m;i++)
            {
                o=(o+b[i]);
                b[i]=o;
            }
            for(i=m;i>=1;i--)
            {
                if(map1[i]==1)
                {
                    b[i]=query(i)+b[i];
                    update(v2[i][0].first,b[i]);
                    update(v2[i][0].second+1,-b[i]);
                    v2[i].clear();
                }
            }
            for(i=1;i<=m;i++)
            {
                if(map2[i]==1)
                {
                    long long int left1=v[i][0].first;
                    long long int left2=v[i][0].second;
                    long long int val=(query(i)%mod+b[i]%mod)%mod;
                    v[i].clear();
                    update1(left1,val);
                    update1(left2+1,-val);
                }
            }
            o=0;
            long long int p;
            for(i=1;i<=n;i++)
            {
                p=query1(i);
                p=p%mod;
               printf("%lld ",p);
            }
            printf("\n");
              map1.clear();
            map2.clear();
        }
    }
