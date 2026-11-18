#include "InputUtils.h"

int inputInt(string message)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value)
        {
            cin.ignore(10000, '\n');
            return value;
        }

        cout << "Du lieu khong hop le! Vui long nhap so nguyen.\n";

        cin.clear();
        cin.ignore(10000, '\n');
    }
}

double inputDouble(string message)
{
    double value;

    while (true)
    {
        cout << message;

        if (cin >> value && value >= 0)
        {
            cin.ignore(10000, '\n');
            return value;
        }

        cout << "Du lieu khong hop le! Vui long nhap so thuc >= 0.\n";

        cin.clear();
        cin.ignore(10000, '\n');
    }
}

string inputString(string message)
{
    string value;

    while (true)
    {
        cout << message;
        getline(cin, value);

        if (!value.empty())
        {
            return value;
        }

        cout << "Khong duoc de trong! Vui long nhap lai.\n";
    }
}
