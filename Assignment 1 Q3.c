#include <stdio.h>
#include <stdlib.h>

int main() {
    int b;
    float a, y = 1;

    printf("Enter a: ");
    scanf("%f", &a);
    printf("\nEnter b : ");
    scanf("%d", &b);
    while (b != 0) {
        y *= a;
        b--;
    }

    printf ("result= %f",y);

    return 0;
}
