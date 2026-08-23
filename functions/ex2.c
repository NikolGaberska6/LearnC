#include <stdio.h>
#include <math.h>
#define PI M_PI

int areaOfSquare(int a) {
    int area = (a * a);
    return area;
}
int areaOfRectangle(int a, int b) {
    int area = a * b;
    return area;
}
double areaOfRightTriangle(int b, int c) {
    double area = (b * c) / 2.0;
    return area;
}
double areaOfCircle(int r) {
    double area = M_PI * r * r;
    return area;
}

int main() {
    int figureCode;
    printf("Enter figure code (1-Square, 2-Rectangle, 3-Right triangle, 4-Circle): ");
    scanf("%d", &figureCode);

    switch (figureCode) {
        case 1: {
            printf("Square\n");
            int a;
            printf("Enter side length: ");
            scanf("%d", &a);

            printf("Area of square is: %d\n", areaOfSquare(a));
            break;
        }
        case 2: {
            printf("Rectangle\n");
            int a, b;
            printf("Enter sides: ");
            scanf("%d %d", &a, &b);
            printf("Area of rectangle is: %d\n", areaOfRectangle(a, b));
            break;
        }
        case 3: {
            printf("Right triangle\n");
            int b, c;
            printf("Enter legs: ");
            scanf("%d %d", &b, &c);
            printf("Area of triangle is: %.2f\n", areaOfRightTriangle(b, c));
            break;
        }
        case 4: {
            printf("Circle\n");
            int r;
            printf("Enter radius: ");
            scanf("%d", &r);
            printf("Area of circle is: %.2f\n", areaOfCircle(r));
            break;
        }
        default: {
            printf("Invalid figure code!\n");
        }
    }
    return 0;
}
