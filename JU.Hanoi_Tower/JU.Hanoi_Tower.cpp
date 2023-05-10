#include <iostream>

using namespace std;

// Функция проверки вводимого значения
int foolcheck(int lb, int hb);
// Показ положения дисков
void show(int* arr1, int* arr2, int* arr3, int size);
// Функция перемещения дисков
void mySwap(int a, int b, int* arr1, int* arr2, int* arr3, int size);
// Функция автоматической перестановки
void autoGame(int* arr1, int* arr2, int* arr3, int size, int& count, int n, int f, int k);

int main()
{
    setlocale(LC_ALL, "Rus");
    int disks = 0, f = 1, k = 3, n, count = 0;
    cout << "ХАНОЙСКАЯ БАШНЯ\n\n";
    while (!disks)
    {
        cout << "Введите количество дисков от 3 до 10: ";
        disks = foolcheck(3, 10);
    }
    // Объявление и инициализация массивов условными значениями радиусов дисков
    int* arrDisks1 = new int[disks];
    int* arrDisks2 = new int[disks];
    int* arrDisks3 = new int[disks];
    for (int i = 0; i < disks; i++)
    {
        arrDisks1[i] = i + 1;
        arrDisks2[i] = 0;
        arrDisks3[i] = 0;
        cout << "\t" << arrDisks1[i] << "\t" << arrDisks2[i] << "\t" << arrDisks3[i] << endl;
    }
    cout << endl;
    n = disks;
    autoGame(arrDisks1, arrDisks2, arrDisks3, disks, count, n, f, k);
    cout << "Сделано перестановок: " << count << endl;
}

//-----------------------------------------------------------------------------------

int foolcheck(int lb, int hb)
{
    int num;
    cin >> num;
    if (num >= lb && num <= hb)
    {
        return num;
    }
    else
    {
        cout << "\nНекорректный ввод.\n\n";
        cin.clear();
        while (cin.get() != '\n')   // Очистка буфера
        {
            continue;
        }
        return 0;
    }
    while (cin.get() != '\n')       // Очистка буфера в случае ввода числа с плавающей точкой
    {
        continue;
    }
}

//-----------------------------------------------------------------------------------

void show(int* arr1, int* arr2, int* arr3, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr1[i] << "\t" << arr2[i] << "\t" << arr3[i] << endl;
    }
    cout << endl;
}

//-----------------------------------------------------------------------------------

void mySwap(int a, int b, int* arr1, int* arr2, int* arr3, int size)
{
    if (a == 1 && b == 2)           // Перестановка с 1 стержня на 2
    {
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr1[j] != 0 && arr2[i] == 0)
                {
                    swap(arr1[j], arr2[i]);
                    goto exit;
                }
            }
        }
    }
    else if (a == 1 && b == 3)      // Перестановка с 1 стержня на 3
    {
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr1[j] != 0 && arr3[i] == 0)
                {
                    swap(arr1[j], arr3[i]);
                    goto exit;
                }
            }
        }
    }
    else if (a == 3 && b == 2)      // Перестановка с 3 стержня на 2
    {
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr3[j] != 0 && arr2[i] == 0)
                {
                    swap(arr3[j], arr2[i]);
                    goto exit;
                }
            }
        }
    }
    else if (a == 3 && b == 1)      // Перестановка с 3 стержня на 1
    {
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr3[j] != 0 && arr1[i] == 0)
                {
                    swap(arr3[j], arr1[i]);
                    goto exit;
                }
            }
        }
    }
    else if (a == 2 && b == 1)      // Перестановка с 2 стержня на 1
    {
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr2[j] != 0 && arr1[i] == 0)
                {
                    swap(arr2[j], arr1[i]);
                    goto exit;
                }
            }
        }
    }
    else if (a == 2 && b == 3)      // Перестановка с 2 стержня на 3
    {
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr2[j] != 0 && arr3[i] == 0)
                {
                    swap(arr2[j], arr3[i]);
                    goto exit;
                }
            }
        }
    }
exit: show(arr1, arr2, arr3, size);
}

//-----------------------------------------------------------------------------------

void autoGame(int* arr1, int* arr2, int* arr3, int size, int& count, int n, int f, int k)
{
    if (n == 1)
    {
        mySwap(f, k, arr1, arr2, arr3, size);
        count++;
    }
    else
    {
        int tmp = 6 - f - k;    // Нахождение свободного стержня
        count++;
        autoGame(arr1, arr2, arr3, size, count, n - 1, f, tmp);
        mySwap(f, k, arr1, arr2, arr3, size);
        autoGame(arr1, arr2, arr3, size, count, n - 1, tmp, k);
    }
}