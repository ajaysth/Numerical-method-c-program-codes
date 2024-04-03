
#include <stdio.h>
#include <math.h>
float f1(float x)
{
    return (1 + (x) + pow(x, 2) / 2);
}
float f2(float x)
{
    return (1 + (x) + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 8);
}

float f3(float x)
{
    return (1 + (x) + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 8 + pow(x, 5) / 15 + pow(x, 6) / 48);
}

int main()
{
    float x0, xn, err, tmp, y1[30], y2[30], y3[30];
    int c;
    printf("\nEnter the initial value: ");
    scanf("%f", &x0);
    printf("\nEnter the final Value: ");
    scanf("%f", &xn);
    printf("\nEnter the allowed error: ");
    scanf("%f", &err);
    for (tmp = x0, c = 0; tmp <= xn; tmp = tmp + err, c++)
    {
        y1[c] = f1(tmp);
        y2[c] = f2(tmp);
        y3[c] = f3(tmp);
    }
    printf("\nx--");
    for (tmp = x0; tmp <= xn; tmp = tmp + err)
        printf("%.4f", tmp);
    printf("\n\nY(1)--");
    for (tmp = x0, c = 0; tmp <= xn; tmp = tmp + err, c++)
        printf("%.4f", y1[c]);
    printf("\n\nY(2)--");
    for (tmp = x0, c = 0; tmp <= xn; tmp = tmp + err, c++)
        printf("%.4f", y2[c]);
    printf("\n\nY(3) --");
    for (tmp = x0, c = 0; tmp <= xn; tmp = tmp + err, c++)
        printf("%.4f", y3[c]);
    return 0;
}