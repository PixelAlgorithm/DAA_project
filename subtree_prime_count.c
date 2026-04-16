#include <stdio.h>
#include <stdbool.h>

#define MAX 100005

int head[MAX], to[2*MAX], next[2*MAX], edge=0;
int val[MAX], prime[MAX], ans[MAX];

void add(int u,int v){
    to[edge]=v;
    next[edge]=head[u];
    head[u]=edge++;

    to[edge]=u;
    next[edge]=head[v];
    head[v]=edge++;
}

void makePrime(int n){
    for(int i=0;i<=n;i++)
        prime[i]=1;

    prime[0]=prime[1]=0;

    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i)
                prime[j]=0;
        }
    }
}

int solve(int u,int parent){
    int cnt=0;

    if(prime[val[u]])
        cnt=1;

    for(int i=head[u];i!=-1;i=next[i]){
        int v=to[i];
        if(v!=parent)
            cnt+=solve(v,u);
    }

    ans[u]=cnt;
    return cnt;
}

int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        head[i]=-1;

    int maxv=0;

    for(int i=1;i<=n;i++){
        printf("Enter value of node %d: ",i);
        scanf("%d",&val[i]);
        if(val[i]>maxv)
            maxv=val[i];
    }

    for(int i=0;i<n-1;i++){
        int u,v;
        printf("Enter edge %d: ",i+1);
        scanf("%d %d",&u,&v);
        add(u,v);
    }

    makePrime(maxv);
    solve(1,-1);

    int q;
    printf("Enter number of queries: ");
    scanf("%d",&q);

    printf("\n=== Query Results ===\n");
    while(q--){
        int x;
        printf("Enter node: ");
        scanf("%d",&x);
        printf("Answer: %d\n",ans[x]);
    }

    return 0;
}