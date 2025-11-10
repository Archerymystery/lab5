#include <iostream>
#include <cmath>
using namespace std;

void checkValidInput()
{
    if (cin.fail())
    {
        throw "Incorect data";
    }
}

void checkValidParams(int n)
{
    if (n < 1)
    {
        throw "n must be greater then 1";
    }
}
double calculate(int n, double x)
{
    double y;
    if (x > 0)
    {
        y = 1;

        for (double i = 1; i <= n; i++)
        {
            y = y * ((1 / x) - (1 / i));
        }
    }
    else
    {
        y = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((x - i + x * j) == 0)
                {

                    return INFINITY;
                }
                y += 1 / (x - i + x * j);
            }
        }
    }
    return y;
}

#ifndef UNIT_TEST
int main()
{

    try

    {

        double x, y;

        int n;

        cout << "n=";

        cin >> n;

        checkValidInput();

        checkValidParams(n);

        cout << "x=";

        cin >> x;

        checkValidInput();

        cout << "x: " << x << " y: " << calculate(n, x) << endl;
    }

    catch (const char *ex)

    {

        cout << ex << endl;

        return -1;
    }

    catch (...)

    {

        cout << "Unknown error\n";

        return -2;
    }
}

#endif