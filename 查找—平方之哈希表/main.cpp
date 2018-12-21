#include<bits/stdc++.h>
using namespace std;

int hashx[1501];
int a[1501];
int top;

void searhashx(int a[], int x, int p)
{
    int t, j;
    t = x % p;
    j = 1;
    if(hashx[t] == -1)
    {
        a[top++] = t;
        hashx[t] = x;
    }

    else
    {
        while(hashx[(t + j * j) % p] != -1 && hashx[(t - j * j) % p] != -1)
        {
            j++;
        }

        if(hashx[(t + j * j) % p] == -1)
        {
            a[top++] = (t + j * j) % p;
            hashx[(t + j * j) % p] = x;
        }

        else if(hashx[(t - j * j) % p] == -1)
        {
            a[top++] = (t - j * j) % p;
            hashx[(t - j * j) % p] = x;
        }
    }
}

int main(void)
{
    int n, i, p, x;

    while(~scanf("%d %d", &n, &p))
    {
        top = 0;
        memset(hashx, -1, sizeof(hashx));
        memset(a, 0, sizeof(a));
        for(i = 0; i < n; i++)
        {
            scanf("%d", &x);
            searhashx(a, x, p);
        }

        for(i = 0; i < n; i++)
        {
            printf("%d%c", a[i], i == n - 1?'\n':' ');
        }
    }

    return 0;
}
