#include <stdio.h>

float areaOfCircle(float radius) {
    float area;
    area = (radius * 3.1415926 * radius);
    return area;
}

int main() {
    float radius1;
    float radius2;
    float area1;
    float area2;
    printf("Enter the first radius: ");
    scanf("%f", &radius1);

    printf("Enter the second radius: ");
    scanf("%f", &radius2);

    area1 = areaOfCircle(radius1);
    area2 = areaOfCircle(radius2);

    printf("The first area with radius %.2lf is: %.2lf\n",radius1, area1);
    printf("The second are with radius %.2lf is: %.2lf", radius2, area2);
}