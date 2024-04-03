// #include <stdio.h>
// #include <conio.h>
// #include <math.h>
// long int factorial(int n);

// int main()
// {
//     int x, i;
//     float s, r;
//     char c;

//     printf("You have this series:-1+x/1! + x^2/2! + x^3/3! + x^4/4!..x^x/x!");
//     printf("To which term you want its sum of ?  ");
//     scanf("%d", &x);
//     s = 0;
//     for (i = 1; i <= x; i++)
//     {
//         s = s + ((float)pow(x, i) / (float)factorial(i));
//     }
//     printf("The sum of %d terms is %f", x, 1 + s);

//     fflush(stdin);
//     getch();
// }

// long int factorial(int n)
// {
//     if (n <= 1)
//         return (1);
//     else
//         n = n * factorial(n - 1);
//     return (n);
// }

#include <stdio.h>

// Function to calculate the derivative dy/dt = -y
double derivative(double y)
{
    return -y;
}

// Taylor series method for solving ODE
double taylor_series(double y, double h)
{
    return y + h * derivative(y);
}

int main()
{
    double y0 = 1.0; // Initial value
    double tf = 1.0; // Final time
    double h = 0.1;  // Step size

    double y = y0;
    double t = 0.0;

    printf("t\t\t y(t)\n");
    printf("%.2f\t\t%.4f\n", t, y);

    while (t < tf)
    {
        y = taylor_series(y, h);
        t += h;
        printf("%.2f\t\t%.4f\n", t, y);
    }

    return 0;
}
