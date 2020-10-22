#include <stdio.h>
#include <math.h>

int main() {
    int x1 , y1 , z1;
    int x2 , y2 , z2;
    int x3 , y3 , z3;
    double x , y , z;
    scanf("%d%d%d", &x1, &y1, &z1);
    scanf("%d%d%d", &x2, &y2, &z2);
    x3 = y1 * z2 - y2 * z1;
    y3 = z1 * x2 - z2 * x1;
    z3 = x1 * y2 - x2 * y1;
    x = x3 / sqrt(x3 * x3 + y3 * y3 + z3 * z3);
    y = y3 / sqrt(x3 * x3 + y3 * y3 + z3 * z3);
    z = z3 / sqrt(x3 * x3 + y3 * y3 + z3 * z3);
    printf("%2.4f %.4f %.4f \n",x,y,z);
    printf("%.4f %.4f %.4f \n",-x,-y,-z);
    return 0;
}
