#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    double a, b, h, y;
    bool f;
    int n;
    ofstream fout("result.txt");

    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "h=";
    cin >> h;
    cout << "n=";
    cin >> n;
    cout << "whether to write to a file (1 yes, 0 no): ";
    cin >> f;
    if (a >= b)
    {
        cout << "a must be less then b";
        return 0;
    }
    if (b - a <= h)
    {
        cout << "step must be less then interval";
        return 0;
    }
    if (n < 1)
    {
        cout << "n must be greater then 1";
        return 0;
    }
    if (f)
    {
        fout << "interval: (" << a << ";" << b << ") step: " << h << " n:" << n << endl;
    }
    double x = a;
    while (x <= b)
    {

        if (x > 0)
        {
            y = 1;

            for (double i = 1; i <= n; i++)
            {
                y = y * ((1 / x) - (1 / i));
            }
            if (f)
            {
                fout << "x: " << x << "\ny: " << y << "\n\n";
            }
            cout << "x: " << x << "\ny: " << y << "\n\n";
        }
        else
        {
            y = 0;
            bool error = false;
            for (int i = 0; i < n && !error; i++)
            {
                for (int j = 0; j < n && !error; j++)
                {
                    if ((x - i + x * j) == 0)
                    {
                        if (f)
                        {
                            fout << "x: " << x << "\ny: undefind \n\n";
                        }
                        cout << "x: " << x << "\ny: undefind \n\n";
                        error = true;
                    }
                    y += 1 / (x - i + x * j);
                }
            }
            if (!error)
            {
                if (f)
                {
                    fout << "x: " << x << "\ny: " << y << "\n\n";
                }
                cout << "x: " << x << "\ny: " << y << "\n\n";
            }
        }
        x += h;
    }
    fout.close();
}