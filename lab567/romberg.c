#include <stdio.h>
#include <math.h>
#define MAX_ITERATIONS 10
double f(double x)
{
    return x * x;
}
double romberg(double a, double b, int n)
{
    double h = (b - a);
    double R[MAX_ITERATIONS][MAX_ITERATIONS];

    R[0][0] = 0.5 * h * (f(a) + f(b));

    for (int i = 1; i <= n; i++)
    {
        double sum = 0.0;
        for (int k = 1; k <= pow(2, i - 1); k++)
        {
            sum += f(a + (k - 0.5) * h);
        }
        R[i][0] = 0.5 * (R[i - 1][0] + h * sum);

        for (int j = 1; j <= i; j++)
        {
            R[i][j] = R[i][j - 1] + (R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
        }

        h /= 2;
    }

    return R[n][n];
}
int main()
{
    double a = 0.0;
    double b = 1.0;
    printf("Integral of x^2 from %.1f to %.1f using Romberg method:\n", a, b);
    for (int i = 1; i <= 5; i++)
    {
        printf("n = %d: %.8f\n", (int)pow(2, i - 1), romberg(a, b, i));
    }
    return 0;
}
