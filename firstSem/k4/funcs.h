#include <stdio.h>
#include <math.h>
 
const double eps = 0.0000001;
 
 
double f1(double x) {
    return 2 * x * sin(x) - cos(x);
}
 
double F1(double x) {
    return (1 / tan(x)) / 2;
}
 
double Fp1(double x) {
    return 3 * sin(x) + 2 * x * cos(x);
}
 
double f2(double x) {
    return 0.5+atan(sqrt(x))-x;
}
 
double F2(double x) {
    return 0.5+atan(sqrt(x));
}
 
double Fp2(double x) {
    return 1/(1+x)-1;
}
 
double f3(double x) {
    return 4 * cos(x * sin(x)) + exp(x) + 5 * x;
}
 
double F3(double x) {
    return (-exp(x) - 4 * cos(x * sin(x))) / 5;
}
 
double Fp3(double x) {
    return -4 * sin(x * sin(x)) * (sin(x) + x * cos(x)) + exp(x) + 5;
}
 
double dichotomy(double f(double), double a, double b) {
    double prevX = b, x = (a + b) / 2.;
    while (fabs(prevX - x) > eps) {
        if (f(x) * f(a) > 0)
            a = x;
        else
            b = x;
        prevX = x;
        x = (a + b) / 2.;
    }
    return x;
}
 
double iteration(double f(double), double a, double b) {
    double prevX = (a + b) / 2., x = f(prevX);
    while (fabs(x - prevX) > eps) {
        prevX = x;
        x = f(x);
    }
    return x;
}
 
double tangent(double f(double), double F(double), double a, double b) {
    double prevX = (a + b / 2.), x = prevX - f(prevX) / F(prevX);
    while (fabs(prevX - x) > eps) {
        prevX = x;
        x = prevX - f(prevX) / F(prevX);
    }
    return x;
}
 
double chord(double f(double), double a, double b) {
    double prevX = b, ya = f(a), yb = f(b);
    double x = (ya * b - yb * a) / (ya - yb);
    while (fabs(prevX - x) > eps) {
        if (ya * f(x) > 0)
            a = x;
        else
            b = x;
        ya = f(a), yb = f(b);
        prevX = x;
        x = (ya * b - yb * a) / (ya - yb);
    }
    return x;
}
