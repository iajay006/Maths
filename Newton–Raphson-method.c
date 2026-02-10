#include <stdio.h>
#include <string.h>
#include <math.h>

/* Function f(x) */
double f(double x) {
    return (x*x*x + 2*x*x + 10*x - 20);
}

/* Derivative f'(x) */
double df(double x) {
    return (3*x*x + 4*x + 10);
}

/* Print double without trailing zeros */
void print_double_clean(double value) {
    char str[50];
    int i;

    sprintf(str, "%.15f", value);

    for (i = strlen(str) - 1; i > 0; i--) {
        if (str[i] == '0')
            str[i] = '\0';
        else
            break;
    }

    if (str[strlen(str) - 1] == '.')
        str[strlen(str) - 1] = '\0';

    printf("%s", str);
}

int main() {
    int n, choice, i;
    double a, b, x, x0;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    printf("\nSelect option:\n");
    printf("1. Smallest positive solution (automatic interval)\n");
    printf("2. Set interval manually\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    /* Interval Selection */
    if (choice == 1) {
        a = 0;
        b = 1;
        while (f(a) * f(b) >= 0) {
            a = b;
            b = b + 1;
        }
    }
    else if (choice == 2) {
        printf("\nEnter interval a and b: ");
        scanf("%lf %lf", &a, &b);

        if (f(a) * f(b) >= 0) {
            printf("Invalid interval! f(a) × f(b) must be < 0\n");
            return 0;
        }
    }
    else {
        printf("Invalid choice!\n");
        return 0;
    }

    /* Display function info */
    printf("\nf(x) = x^3 + 2x^2 + 10x - 20\n");
    printf("f'(x) = 3x^2 + 4x + 10\n");

    printf("\nBy Newton Raphson Method\n");
    printf("Formula used:\n");
    printf("X(n+1) = (xn - f(xn)) / f'(xn)\n");

    /* Initial interval */
    printf("\nRoot lies between (");
    print_double_clean(a);
    printf(" , ");
    print_double_clean(b);
    printf(")\n");

    /* Midpoint */
    x = (a + b) / 2.0;
    printf("\nx = ");
    print_double_clean(x);
    printf("\n");

    if (f(a) * f(x) < 0)
        b = x;
    else
        a = x;

    printf("Root lies between (");
    print_double_clean(a);
    printf(" , ");
    print_double_clean(b);
    printf(")\n");

    /* Choose x0 */
    if (fabs(f(a)) < fabs(f(b)))
        x0 = a;
    else
        x0 = b;

    printf("\nx0 = ");
    print_double_clean(x0);
    printf("\n");

    printf("\nUsing Newton Raphson Method\n\n");

    /* Newton–Raphson Iterations */
    for (i = 1; i <= n; i++) {
        printf("Iteration %d\n", i);

        printf("x%d = ", i - 1);
        print_double_clean(x0);
        printf("\n");

        printf("f(x%d) = ", i - 1);
        print_double_clean(f(x0));
        printf("\n");

        printf("f'(x%d) = ", i - 1);
        print_double_clean(df(x0));
        printf("\n");

        x = x0 - f(x0) / df(x0);

        printf("x%d = ", i);
        print_double_clean(x);
        printf("\n\n");

        x0 = x;
    }

    return 0;
}
