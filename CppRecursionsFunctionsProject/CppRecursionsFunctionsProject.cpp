#include <iostream>

double Power(double x, int n);
double PowerRec(double x, int n);
double PowerBinRec(double x, int n);

unsigned long long Hanoy(int disk);

double CircleArea(double radius);

unsigned long long FactRec(int n);
unsigned long long FactLoop(int n);

void BinNumber(int number);

unsigned long long FibRec(int n);


int main()
{
    //std::cout << Hanoy(64) / 3600 / 24 / 365 << "\n";
    //BinNumber(37);
    //std::cout << "\n";
    std::cout << FibRec(100) << "\n";
}

double CircleArea(double radius)
{
    return 3.14 * Power(radius, 2);
}

double Power(double x, int n)
{
    double result(1);

    while (n)
    {
        if (n & 1)
            result *= x;
        x *= x;
        n /= 2;
    }

    return result;
}

double PowerBinRec(double x, int n)
{
    if (n == 0) return 1;
    if (n & 1)
        return PowerBinRec(x, n - 1) * x;
    else
    {
        double temp{ PowerBinRec(x, n / 2) };
        return temp * temp;
    }
        

}

unsigned long long Hanoy(int disk)
{
    if (disk == 1) return 1;
    return Hanoy(disk - 1) * 2 + 1;
}

unsigned long long FactRec(int n)
{
    if (n == 0) 
        return 1;
    return FactRec(n - 1) * n;
}

unsigned long long FactLoop(int n)
{
    unsigned long long result{ 1 };
    for (int i{}; i < n; i++)
        result *= i;
    return result;
}

void BinNumber(int number)
{
    if (number >= 2)
        BinNumber(number / 2);
    std::cout << number % 2;
}

unsigned long long FibRec(int n)
{
    static unsigned long long fibArr[1000]{};
    
    if (n == 0 || n == 1) return n;
    
    if(!fibArr[n])
        fibArr[n] = FibRec(n - 1) + FibRec(n - 2);

    return fibArr[n];
}

double PowerRec(double x, int n)
{
    if (n == 0)
        return 1;
    return PowerRec(x, n - 1) * x;
}