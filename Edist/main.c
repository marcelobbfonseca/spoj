#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[3000],t[3000];
        scanf("%s",s);
        scanf("%s",t);
        int sizes = strlen(s),sizet = strlen(t);
        vector<int> v1(sizet+9),v2(sizet+9);
        for(int i=0;i<=sizet;i++)
            v1[i] = i;
        for(int i=0;i<sizes;i++)
        {
            v2[0] = i+1;
            for(int j=0;j<sizet;j++)
            {
                int add;
                if(s[i] == t[j])
                    add = 0;
                else 
                    add = 1;
                v2[j+1] = min(v2[j]+1,min(v1[j+1]+1,v1[j]+add));
            }
            for(int i=0;i<sizet;i++)
                v1[i] = v2[i];
        }
        printf("%d\n",v2[sizet]);
    }
    return 0;
}
