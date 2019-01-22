int t, k, num[10];
char chars[10];

void perm(int k, int pos)
{
    if(k!=pos)
    {
        for(int i=0; i<k; i++)
        {
            if(num[i]==0)
            {
                // num[i] = 1,0 in comments = > permutations with repetitions
                chars[pos]=(char)(i+'a');
                num[i]=1;
                perm(k, pos+1);
                num[i]=0;
            }
        }
    }
    else
    {
        for(int i=0; i<k; i++)
            printf("%c", chars[i]);
        printf("\n");
        return;
    }
}
int main()
{
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        scanf("%d", &k);
        perm(k, 0);
    }
    return 0;
}
