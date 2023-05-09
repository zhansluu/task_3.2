#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <cmath>

double func (double x)
{
    return exp(6*x);
}

double getDerivativeValue (double x)
{
    return 6*exp(6*x);
}

double getSecondDerivativeValue (double x)
{
    return 36*exp(6*x);
}

double centralDifferenceDerivative (double y_table[], size_t i, double step)
{
    return (y_table[i+1] - y_table[i-1])/(2*step);
}

double pointAtTheBeginning (double y_table[], size_t i, double step)
{
    return (-3*y_table[i]+4*y_table[i+1]-y_table[i+2])/(2*step);
}

double pointAtTheEnd (double y_table[], size_t i, double step)
{
    return (3*y_table[i]-4*y_table[i-1]+y_table[i-2])/(2*step);
}

double secondDerivativeValue (double y_table[], size_t i, double step)
{
    return (y_table[i+1]-2*y_table[i]+y_table[i-1])/(step*step);
}

#endif // FUNCTIONS_H_INCLUDED
