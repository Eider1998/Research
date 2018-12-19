#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *lchild, *rchild;
}*head, *head1;

struct node *CbTree(struct node *head, int x)
{
    if(!head)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head-> data = x;
        head-> lchild = head-> rchild = NULL;
    }

    else
    {
        if(x > head-> data)
        {
            head-> lchild = CbTree(head-> lchild, x);
        }

        else
        {
            head-> rchild = CbTree(head-> rchild, x);
        }
    }

    return head;
}

int Tougou(struct node *head, struct node *head1)
{
    if(!head && !head1)
    {
        return 1;
    }

    else if(head && head1)
    {
        if(head-> data != head1-> data)
        {
            return 0;
        }

        else
        {
            return Tougou(head-> lchild, head1-> lchild) && Tougou(head-> rchild, head1-> rchild);
        }
    }

    else
    {
        return 0;
    }
}

int main(void)
{
    int n, i, l, x;

    while(scanf("%d %d", &n, &l) && n != 0)
    {
        head = NULL;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &x);
            head = CbTree(head, x);
        }

        while(l--)
        {
            head1 = NULL;
            for(i = 0; i < n; i++)
            {
                scanf("%d", &x);
                head1 = CbTree(head1, x);
            }

            if(Tougou(head, head1))
            {
                printf("Yes\n");
            }

            else
            {
                printf("No\n");
            }
        }
    }

    return 0;
}
