#include <iostream>
#include <cmath>
#include "functions.h"
using namespace std;

int main()
{
    setlocale(0, "Russian");
    cout << "Задание 3.2. Нахождение производных таблично-заданной функции по формулам численного дифференцирования." << endl;
    cout << "Вариант 3." << endl << "Дана функция f(x)=exp(6*x)" << endl;

    size_t m;
    double a, step;
    /*Ввод данных с клавиатуры*/
    cout << "Введите число значений в таблице: ";
    cin >> m;
    while (m > 1000)
    {
        cout << "Введите число m < 1000" << endl;
        cin >> m;
    }
    m--;
    cout << "Введите значение a(нижнюю границу): ";
    cin >> a;
    cout << endl << "Введите значение h(шаг): ";
    cin >> step;

    /*Создание таблицы*/
    double x_table[1000], y_table[1000];
    cout << "Исходная таблица значений функций:" << endl;
    for (size_t i = 0; i < m; i++)
    {
        x_table[i] = a + i*step;
        y_table[i] = func(x_table[i]);
        cout << "x = " << x_table[i] << "; y = " << y_table[i] << endl;
    }

    cout << "Введите:" << endl << "1 - вывод таблицы с центральной разностной производной;" << endl
                               << "2 - вывод таблицы, если точка в начале таблицы;" << endl
                               << "3 - вывод таблицы, если точка в конце таблицы;" << endl
                               << "4 - конец работы" << endl;

    size_t num;
    cin >> num;
    while (num != 1 && num != 2 && num != 3 && num != 4)
    {
        cout << "Введено неверное значение! Повторите попытку.";
        cin >> num;
    }
    while (num != 4){
        switch (num){
        case 1:
            for (size_t i = 1; i < m-1; i++)
                cout << "x = " << x_table[i] << "; y = " << y_table[i] << "; f'(x)_чд = " << centralDifferenceDerivative(y_table, i, step)
                << "; |f'(x)-f'(x)_чд| = " << fabs(getDerivativeValue(x_table[i])-centralDifferenceDerivative(y_table, i, step))
                << "; f''(x)_чд = " << secondDerivativeValue(y_table, i, step) << "; |f''(x)-f''(x)_чд| = "
                << fabs(getDerivativeValue(x_table[i])-secondDerivativeValue(y_table, i, step)) << endl;
            cout << "----------------------------------------------------" << endl;
            cin >> num;
            break;
        case 2:
            for (size_t i = 1; i < m-1; i++)
                cout << "x = " << x_table[i] << "; y = " << y_table[i] << "; f'(x)_чд = " << pointAtTheBeginning(y_table, i, step)
                << "; |f'(x)-f'(x)_чд| = " << fabs(getDerivativeValue(x_table[i])-pointAtTheBeginning(y_table, i, step))
                << "; f''(x)_чд = " << secondDerivativeValue(y_table, i, step) << "; |f''(x)-f''(x)_чд| = "
                << fabs(getDerivativeValue(x_table[i])-secondDerivativeValue(y_table, i, step)) << endl;
            cout << "----------------------------------------------------" << endl;
            cin >> num;
            break;
        case 3:
            for (size_t i = 1; i < m-1; i++)
                cout << "x = " << x_table[i] << "; y = " << y_table[i] << "; f'(x)_чд = " << pointAtTheEnd(y_table, i, step)
                << "; |f'(x)-f'(x)_чд| = " << fabs(getDerivativeValue(x_table[i])-pointAtTheEnd(y_table, i, step))
                << "; f''(x)_чд = " << secondDerivativeValue(y_table, i, step) << "; |f''(x)-f''(x)_чд| = "
                << fabs(getDerivativeValue(x_table[i])-secondDerivativeValue(y_table, i, step)) << endl;
            cout << "----------------------------------------------------" << endl;
            cin >> num;
            break;
        case 4:
            return 0;
        }
    }
}
