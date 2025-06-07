#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void input_array(double arr[], int size, char name) 
{
    for (int i = 0; i < size; i += 1) 
    {
        printf("%c[%d] = ", name, i);
        scanf("%lf", &arr[i]);
    }
}

void calculate_sum_and_product(double arr[], int size, double* sum, double* product) 
{
    *sum = 0;
    *product = 1;

    for (int i = 0; i < size; i += 1) 
    {
        *sum += arr[i];
        *product *= arr[i];
    }
}

int main() 
{
    system("chcp 65001");

    int n, m;
    double x[100], y[100]; 

    printf("Введіть кількість елементів у масиві x: ");
    scanf("%d", &n);
    input_array(x, n, 'x');

    printf("Введіть кількість елементів у масиві y: ");
    scanf("%d", &m);
    input_array(y, m, 'y');

    double sum_x, prod_x;
    calculate_sum_and_product(x, n, &sum_x, &prod_x);

    double A = 0, B = 0, C = 0;

    for (int i = 0; i < n; i += 1) 
    {
        A += x[i] * sin(x[i]);
        B += x[i] * cos(x[i]);
        C += x[i] * tan(x[i]);
    }

    A *= sum_x;
    B *= prod_x;
    C *= (sum_x + prod_x);

    double sum_y, prod_y;
    calculate_sum_and_product(y, m, &sum_y, &prod_y);

    double D = 0, E = 0, F = 0;

    for (int i = 0; i < m; i += 1) 
    {
        D += y[i] * tan(y[i]);
        E += y[i] * exp(y[i]);
        F += y[i] * cos(y[i]);
    }

    D *= sum_y;
    E *= prod_y;
    F *= (sum_y + prod_y);

    double numerator = A + B * cos(C);
    double denominator = D + E * sin(F);

    if (denominator == 0) 
    {
        printf("Помилка: знаменник дорівнює нулю.\n");
    } 
    
    else 
    {
        double gamma = numerator / denominator;
        printf("Результат γ = %.6lf\n", gamma);
    }

    return 0;
}