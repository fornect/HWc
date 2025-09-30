#include <stdio.h>
#include <string.h>
int main()
{
    char str1[10]="2145663221";
    char str2[2]="21";
    int k;
    //fgets(str1, sizeof(str1) ,stdin);
    //fgets(str2, sizeof(str2) ,stdin);
    printf("%d\n", strlen(str1)-1);
    for (int i=0; strlen(str1)-1; i++)
    {
        for (int j=0; strlen(str1)-1; j++)
        {
            if (str2[j] != str1[i+j])
            {
                break;
            }
            else if (strlen(str2)-1 == i+1)
            {
                k++;
                break;
            }
        }
        printf("%d\n", k);
    }
    printf("%d", k);
    return 0;
}