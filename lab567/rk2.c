// #include <stdio.h>
// #include <conio.h>
// #include <math.h>
// float f(float x, float y)
// {
//     float a;
//     a = x * y;
//     return a;
// }

// void main()
// {
//     int n, i;
//     float x, xf, y, h, s, s1, s2;
//     printf("Enter the First value :- ");
//     scanf("%d", &x);
//     printf("Enter the Second value :- ");
//     scanf("%d", &xf);
//     printf("Enter the Lenth y :- ");
//     scanf("%d", &y);
//     printf("Enter the Width h :- ");
//     scanf("%d", &h);
//     while (x < xf)
//     {
//         s1 = f(x, y);
//         s2 = f(x + h, y + h * s1);
//         s = (s1 + s2) / 2;
//         y = y + (h * s);
//         x = x + h;
//     }
//     printf("Output = %f", y);

//     getch();
// }

#include <stdio.h>

// Function to calculate the derivative dy/dt = -y
double derivative(double t, double y)
{
    return -y;
}

// Second-order Runge-Kutta method (RK2) for solving ODE
double rk2(double t, double y, double h)
{
    double k1, k2;

    k1 = h * derivative(t, y);
    k2 = h * derivative(t + h, y + k1);

    return y + 0.5 * (k1 + k2);
}

int main()
{
    double t0 = 0.0; // Initial time
    double y0 = 1.0; // Initial value
    double tf = 1.0; // Final time
    double h = 0.1;  // Step size

    double t = t0;
    double y = y0;

    printf("t\t\t y(t)\n");
    printf("%.2f\t\t%.4f\n", t, y);

    while (t < tf)
    {
        y = rk2(t, y, h);
        t += h;
        printf("%.2f\t\t%.4f\n", t, y);
    }

    return 0;
}
