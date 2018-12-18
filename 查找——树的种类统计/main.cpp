#include<bits/stdc++.h>
using namespace std;

struct node
{
    char name[2001];
    int dp;
    struct node *lchild, *rchild;
}*head;


struct node *BTree(struct node *head, char w[])
{
    if(!head)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head-> lchild = NULL;
        head-> rchild = NULL;
        strcpy(head-> name, w);
        head-> dp = 1;
    }

    else
    {
        if(strcmp(head-> name, w) > 0)
        {
            head-> lchild = BTree(head-> lchild, w);
        }

        else if(strcmp(head-> name, w) < 0)
        {
            head-> rchild = BTree(head-> rchild, w);
        }

        else
        {
            head-> dp++;
        }
    }
    return head;
}

void inorder(struct node *head, int n)
{
    if(head)
    {
        inorder(head-> lchild, n);
        printf("%s %.2lf%%\n", head-> name, 100 *(double)head-> dp / n);
        inorder(head-> rchild, n);
    }
}

int main(void)
{
    char w[2001];
    int n, i, j;
    int l;
    scanf("%d", &n);

    getchar();
    head = NULL;
    for(j = 0; j < n; j++)
    {
        gets(w);
        l = strlen(w);
        for(i = 0; i < l; i++)
        {
            if(w[i] >= 'A' && w[i] <= 'Z')
            {
                w[i] += 32;
            }
        }

        head = BTree(head, w);
    }

    inorder(head, n);


    return 0;
}
