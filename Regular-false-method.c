#include <stdio.h>
#include <string.h>

/* Function definition */
double f(double x) {
    return (x*x*x + 2*x - 1);
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
    double a, b, x, fx;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    printf("\nSelect option:\n");
    printf("1. Smallest positive solution (automatic interval)\n");
    printf("2. Set interval manually\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    /* -------- OPTION 1 -------- */
    if (choice == 1) {
        a = 0;
        b = 1;

        while (f(a) * f(b) >= 0) {
            a = b;
            b = b + 1;
        }
    }

    /* -------- OPTION 2 -------- */
    else if (choice == 2) {
        printf("\nEnter interval a and b: ");
        scanf("%lf %lf", &a, &b);

        if (f(a) * f(b) >= 0) {
            printf("Invalid interval! f(a) × f(b) must be < 0\n");
            return 0;
        }
    } else {
        printf("Invalid choice!\n");
        return 0;
    }

    /* Initial interval display */
    printf("\nRoot lies between (");
    print_double_clean(a);
    printf(" , ");
    print_double_clean(b);
    printf(")\n");

    /* Initial midpoint check (same as before) */
    x = (a + b) / 2.0;
    printf("\nInitial Midpoint value x = ");
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

    /* -------- REGULAR FALSE METHOD -------- */
    printf("\nBy Regular False Method\n");
    printf("Formula used:\n");
    printf("x = (a×f(b) - b×f(a)) / (f(b) - f(a))\n\n");

    for (i = 1; i <= n; i++) {
        x = (a * f(b) - b * f(a)) / (f(b) - f(a));
        fx = f(x);

        printf("X%d = ", i);
        print_double_clean(x);
        printf("\n");

        printf("f(X%d) = ", i);
        print_double_clean(fx);
        printf("\n");

        if (f(a) * fx < 0)
            b = x;
        else
            a = x;

        printf("Root lies between (");
        print_double_clean(a);
        printf(" , ");
        print_double_clean(b);
        printf(")\n\n");
    }

    return 0;
}
