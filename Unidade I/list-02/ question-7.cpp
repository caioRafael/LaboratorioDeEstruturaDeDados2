#include <iostream>
float raiz(float x, float x0, float e);
int main()
{
    float x, x0, e;
    x = 13;
    x0 = 3.5;
    e = 0.001;
    //scanf("%f %f %f", &x, &x0, &e);
    float xx = raiz(x, x0, e);
    printf("%f\n", xx);
    return 0;
}

float raiz(float x, float x0, float e)
{
    float condi1;
    if ((x0 * x0) > x)
    {
        condi1 = (x0 * x0) - x;
    }
    else
    {
        condi1 = x - (x0 * x0);
    }
    if (condi1 <= e)
    {
        return x0;
    }
    else
    {
        x0 = ((x0 * x0) + x) / (2 * x0);
        return raiz(x, x0, e);
    }
}