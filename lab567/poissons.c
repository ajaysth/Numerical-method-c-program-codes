#include <stdio.h>
#include <math.h>

#define SIZE_X 5 // Size of the grid along the x-axis
#define SIZE_Y 5 // Size of the grid along the y-axis

#define TOLERANCE 1e-5      // Tolerance for convergence
#define MAX_ITERATIONS 1000 // Maximum number of iterations

// Function to print the grid values
void printGrid(double grid[][SIZE_Y])
{
    for (int i = 0; i < SIZE_X; i++)
    {
        for (int j = 0; j < SIZE_Y; j++)
        {
            printf("%.2f\t", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Jacobi iteration to solve Poisson's equation
void poissonJacobi(double grid[][SIZE_Y], double f[][SIZE_Y], double h)
{
    double tempGrid[SIZE_X][SIZE_Y]; // Temporary grid to store updated values
    double diff, maxDiff;

    do
    {
        maxDiff = 0.0;

        // Perform Jacobi iteration
        for (int i = 1; i < SIZE_X - 1; i++)
        {
            for (int j = 1; j < SIZE_Y - 1; j++)
            {
                tempGrid[i][j] = 0.25 * (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1] - h * h * f[i][j]);
                diff = fabs(tempGrid[i][j] - grid[i][j]);
                if (diff > maxDiff)
                {
                    maxDiff = diff;
                }
            }
        }

        // Update the original grid with the new values
        for (int i = 1; i < SIZE_X - 1; i++)
        {
            for (int j = 1; j < SIZE_Y - 1; j++)
            {
                grid[i][j] = tempGrid[i][j];
            }
        }
    } while (maxDiff > TOLERANCE);
}

int main()
{
    double grid[SIZE_X][SIZE_Y] = {{0}}; // Initialize grid with zeros
    double f[SIZE_X][SIZE_Y] = {{0}};    // Initialize source term with zeros

    // Set boundary conditions
    for (int i = 0; i < SIZE_X; i++)
    {
        grid[i][0] = 100.0;          // Bottom boundary
        grid[i][SIZE_Y - 1] = 100.0; // Top boundary
    }
    for (int j = 0; j < SIZE_Y; j++)
    {
        grid[0][j] = 100.0;          // Left boundary
        grid[SIZE_X - 1][j] = 100.0; // Right boundary
    }

    printf("Initial Grid:\n");
    printGrid(grid);

    // Perform Jacobi iterations to solve Poisson's equation
    poissonJacobi(grid, f, 1.0); // Assuming constant grid spacing (h = 1.0)

    printf("Solution Grid:\n");
    printGrid(grid);

    return 0;
}
