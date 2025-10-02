#include <stdio.h>
#include <string.h>
int main()
{
    char str1[]="21456663221";
    char str2[]="66";
    int k;
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    //fgets(str1, sizeof(str1) ,stdin);
    //fgets(str2, sizeof(str2) ,stdin);
    for (int i=0; i<l1; i++)
    {
        for (int j=0; (i<l1) & (j<l2+1); j++)
        {
            if (str2[j] != str1[i+j])
            {
                break;
            }
            else if (strlen(str2)-1 == j)
            {
                k++;
                break;
            }
        }
    }
    printf("%d", k);
    return 0;
}