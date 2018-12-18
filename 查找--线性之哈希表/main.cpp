#include<bits/stdc++.h>
using namespace std;

int hashx[1501];
int a[1501], top;

void rehashx(int x, int p)
{
    int t;
    t = x % p;
    int j = 0;
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
    int n, p, i, x;

    while(~scanf("%d %d", &n, &p))
    {
        memset(hashx, -1, sizeof(hashx));
        top = 0;
        memset(a, 0, sizeof(a));
        for(i = 0; i < n; i++)
        {
            scanf("%d", &x);
            rehashx(x, p);
        }

        for(i = 0; i < n; i++)
        {
            printf("%d%c", a[i], i == n - 1 ? '\n' :' ');
        }
    }

    return 0;
}
