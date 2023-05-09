#include <iostream>
#include <cmath>
#include "functions.h"
using namespace std;

int main()
{
    setlocale(0, "Russian");
    cout << "������� 3.2. ���������� ����������� ��������-�������� ������� �� �������� ���������� �����������������." << endl;
    cout << "������� 3." << endl << "���� ������� f(x)=exp(6*x)" << endl;

    size_t m;
    double a, step;
    /*���� ������ � ����������*/
    cout << "������� ����� �������� � �������: ";
    cin >> m;
    while (m > 1000)
    {
        cout << "������� ����� m < 1000" << endl;
        cin >> m;
    }
    m--;
    cout << "������� �������� a(������ �������): ";
    cin >> a;
    cout << endl << "������� �������� h(���): ";
    cin >> step;

    /*�������� �������*/
    double x_table[1000], y_table[1000];
    cout << "�������� ������� �������� �������:" << endl;
    for (size_t i = 0; i < m; i++)
    {
        x_table[i] = a + i*step;
        y_table[i] = func(x_table[i]);
        cout << "x = " << x_table[i] << "; y = " << y_table[i] << endl;
    }

    cout << "�������:" << endl << "1 - ����� ������� � ����������� ���������� �����������;" << endl
                               << "2 - ����� �������, ���� ����� � ������ �������;" << endl
                               << "3 - ����� �������, ���� ����� � ����� �������;" << endl
                               << "4 - ����� ������" << endl;

    size_t num;
    cin >> num;
    while (num != 1 && num != 2 && num != 3 && num != 4)
    {
        cout << "������� �������� ��������! ��������� �������.";
        cin >> num;
    }
    while (num != 4){
        switch (num){
        case 1:
            for (size_t i = 1; i < m-1; i++)
                cout << "x = " << x_table[i] << "; y = " << y_table[i] << "; f'(x)_�� = " << centralDifferenceDerivative(y_table, i, step)
                << "; |f'(x)-f'(x)_��| = " << fabs(getDerivativeValue(x_table[i])-centralDifferenceDerivative(y_table, i, step))
                << "; f''(x)_�� = " << secondDerivativeValue(y_table, i, step) << "; |f''(x)-f''(x)_��| = "
                << fabs(getDerivativeValue(x_table[i])-secondDerivativeValue(y_table, i, step)) << endl;
            cout << "----------------------------------------------------" << endl;
            cin >> num;
            break;
        case 2:
            for (size_t i = 1; i < m-1; i++)
                cout << "x = " << x_table[i] << "; y = " << y_table[i] << "; f'(x)_�� = " << pointAtTheBeginning(y_table, i, step)
                << "; |f'(x)-f'(x)_��| = " << fabs(getDerivativeValue(x_table[i])-pointAtTheBeginning(y_table, i, step))
                << "; f''(x)_�� = " << secondDerivativeValue(y_table, i, step) << "; |f''(x)-f''(x)_��| = "
                << fabs(getDerivativeValue(x_table[i])-secondDerivativeValue(y_table, i, step)) << endl;
            cout << "----------------------------------------------------" << endl;
            cin >> num;
            break;
        case 3:
            for (size_t i = 1; i < m-1; i++)
                cout << "x = " << x_table[i] << "; y = " << y_table[i] << "; f'(x)_�� = " << pointAtTheEnd(y_table, i, step)
                << "; |f'(x)-f'(x)_��| = " << fabs(getDerivativeValue(x_table[i])-pointAtTheEnd(y_table, i, step))
                << "; f''(x)_�� = " << secondDerivativeValue(y_table, i, step) << "; |f''(x)-f''(x)_��| = "
                << fabs(getDerivativeValue(x_table[i])-secondDerivativeValue(y_table, i, step)) << endl;
            cout << "----------------------------------------------------" << endl;
            cin >> num;
            break;
        case 4:
            return 0;
        }
    }
}
