#include <stdio.h>
#include <string.h>
int main()
{
    int k = 0;
    char strq[] = "hellowwwww(())";
    for(int i=0; i<strlen(strq); i++)
    {
        if (strq[i] == ')')
        {
            k--;
        }
        else if (strq[i] == '(')
        {
            k++;
        }
        if (k < 0)
        {
            printf("%s", "баланс не соблюден");
            return 0;
        }
    }
    if (k == 0)
    {
        printf("%s", "баланс соблюден");
        return 0;
    }
    printf("%s", "баланс не соблюден");
    return 0;
}