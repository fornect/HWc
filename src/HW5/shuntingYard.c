#include "stack.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    char queue[100];
    int n = 0;
    char e;
    charStack *head = NULL;
    scanf("%s", a);
    int lena = strlen(a);
    for (int i = 0; i < lena; i++){
        e = peek(head);
        
        if ((a[i] == '-' || a[i] == '+' || a[i] == '*' || a[i] == '/') && e == 'N'){
            push(&head, a[i]);
        }
        else if ((a[i] == '-' || a[i] == '+')){
            e = pop(&head);
            queue[n] = e;
            n++;
            push(&head, a[i]);
            
        }
        else if ((a[i] == '*' || a[i] == '/')){
            if (e == '*' || e == '/'){
                e = pop(&head);
                queue[n] = e;
                n++;
            }
            push(&head, a[i]);
        }
        else if (a[i] != ' '){
            queue[n] = a[i];
            n++;
        }
    }
    while (peek(head) != 'N'){
        e = pop(&head);
        queue[n] = e;
        n++;
    }

    for (int i = 0; i <= n; i++){
        printf("%c ", queue[i]);
    }
    return 0;
    
}