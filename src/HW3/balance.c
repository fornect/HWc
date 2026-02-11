#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool balancec(char* s)
{
    int lens = strlen(s);
    int k = 0;
    for (int i = 0; i < lens; i++) {
        if (s[i] == ')') {
            k--;
        } else if (s[i] == '(') {
            k++;
        }
        if (k < 0) {
            return false;
        }
    }
    if (k == 0) {
        return true;
    }
    return false;
}

int main()
{
    char strq[1000] = "";
    scanf("%s", &strq);
    if (balancec(strq)) {
        printf("%s", "баланс соблюден");
        return 0;
    }
    printf("%s", "баланс не соблюден");
    return 0;
}