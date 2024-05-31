#include <stdio.h>

int main() {
    int i, j, a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    for (i = 1; i <= a; i++) {
        for (j = 1; j <= a - i; j++) {
            printf(" ");
        }

        for (j = 1; j <= b; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
