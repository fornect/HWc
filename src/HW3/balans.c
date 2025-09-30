#include <stdio.h>
#include <string.h>
int main()
{
    int k;
    char strq[1000] = "hellowwwww";
    int len = strlen(strq);
    len = len - 1;
    printf("%d", len);
    printf("%d", k);
    for(int i=0; len; ++i)
    {
        
        if (strq[i] == ')')
        {
            printf("%s", "баланс не соблюден!");
            return 0;
        }
        else if (strq[i] == '(')
        {
            for(int j=i; len; j++)
            {
                if (strq[j] == ')')
                {
                    strq[j] = 'e';
                    break;
                }
                else if (j == len-1)
                {
                    printf("%s", "баланс не соблюден");
                    return 0;
                }
            }
            while ((getchar()) != '\n');
        }
    }
    printf("%s", "баланс соблюден");
    return 0;
}