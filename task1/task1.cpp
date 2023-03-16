// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
using namespace std;
int** createArray(int rows, int cols);
template <class T>
void printArray(T** array, int rows, int cols);
int** delCols(int** array, int rows, int* cols);
int** inputCols(int** array, int rows, int* size);
int** spinLeft(int** arr, int rows, int cols);
int** spinRight(int** arr, int rows, int cols);
int** spinUp(int** arr, int rows, int cols);
int** spinDown(int** arr, int rows, int cols);
int main()
{
    srand(time(NULL));
    cout << "1 - Create Array" << endl;
    int rows, cols;
    cout << "Input rows: ";
    cin >> rows;
    cout << "Input cols: ";
    cin >> cols;
    int** arr = createArray(rows, cols);
    cout << endl;
    while (true) {
        printArray(arr, rows, cols);
        cout << "1 - Add Col" << endl;
        cout << "2 - Del Col" << endl;
        cout << "3 - Change" << endl;
        int check;
        cin >> check;
        if (check == 1) {       
            arr = inputCols(arr, rows, &cols);
            cout << endl;
            system("cls");
            continue;
        }
        else if (check == 2) {           
            arr = delCols(arr, rows, &cols);
            cout << endl;
            system("cls");
            continue;
        }
        else if (check == 3) {
            cout << "1 - left" << endl;
            cout << "2 - right" << endl;
            cout << "3 - up" << endl;
            cout << "4 - down" << endl;
            cin >> check;
            cout << "How many spins? ";
            int spins;
            cin >> spins;
            if (check == 1) {
                for (int i = 0; i < spins; i++) {
                    system("cls");
                    arr = spinLeft(arr, rows, cols);
                    printArray(arr, rows, cols);
                    cout << "----------------" << endl;
                    Sleep(500);
                    system("cls");
                }
                continue;
            }
            else if (check == 2) {
                for (int i = 0; i < spins; i++) {
                    system("cls");
                    arr = spinRight(arr, rows, cols);
                    printArray(arr, rows, cols);
                    cout << "----------------" << endl;
                    Sleep(500);
                    system("cls");
                }
                continue;
            }
            else if (check == 3) {
                for (int i = 0; i < spins; i++) {
                    system("cls");
                    arr = spinUp(arr, rows, cols);
                    printArray(arr, rows, cols);
                    cout << "----------------" << endl;
                    Sleep(500);
                    system("cls");
                }
                continue;
            }
            else if (check == 4) {
                for (int i = 0; i < spins; i++) {
                    system("cls");
                    arr = spinDown(arr, rows, cols);
                    printArray(arr, rows, cols);
                    cout << "----------------" << endl;
                    Sleep(500);
                    system("cls");
                }
                continue;
            }
        }
    }
}
int** spinDown(int** arr, int rows, int cols) {
    int** arrNew = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arrNew[i] = new int[cols];
    }
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            arrNew[i + 1][j] = arr[i][j];
        }
    }
    for (int j = 0; j < cols; j++) {
        arrNew[0][j] = arr[rows - 1][j];
    }
    for (int i = 0; i < rows; i++) {
        delete[]arr[i];
    }
    delete[]arr;
    return arrNew;
}
int** spinUp(int** arr, int rows, int cols) {
    int** arrNew = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arrNew[i] = new int[cols];
    }
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arrNew[i - 1][j] = arr[i][j];
        }
    }
    for (int j = 0; j < cols; j++) {
        arrNew[rows - 1][j] = arr[0][j];
    }
    for (int i = 0; i < rows; i++) {
        delete[]arr[i];
    }
    delete[]arr;
    return arrNew;
}
int** spinRight(int** arr, int rows, int cols) {
    int** arrNew = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arrNew[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            arrNew[i][j] = arr[i][j - 1];
        }
    }
    for (int i = 0; i < rows; i++) {
        arrNew[i][0] = arr[i][cols - 1];
    }
    for (int i = 0; i < rows; i++) {
        delete[]arr[i];
    }
    delete[]arr;
    return arrNew;
}
int** spinLeft(int** arr, int rows, int cols) {
    int** arrNew = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arrNew[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            arrNew[i][j] = arr[i][j + 1];
        }
    }
    for (int i = 0; i < rows; i++) {
        arrNew[i][cols - 1] = arr[i][0];
    }
    for (int i = 0; i < rows; i++) {
        delete[]arr[i];
    }
    delete[]arr;
    return arrNew;
}
int** createArray(int rows, int cols) {
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 10;
        }
    }
    return array;
}
template <class T>
void printArray(T** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
int** delCols(int** array, int rows, int* cols) {
    int position;
    cout << "Delete col!" << endl;
    cout << "Input col:";
    cin >> position;
    int** arr2 = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr2[i] = new int[*cols - 1];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < position - 1; j++) {
            arr2[i][j] = array[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = position; j < *cols; j++) {
            arr2[i][j - 1] = array[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        delete[]array[i];
    }
    delete[]array;
    (*cols)--;
    return arr2;
}
int** inputCols(int** array, int rows, int* cols) {
    int position, number;
    cout << "Add cols!" << endl;
    cout << "Input number: ";
    cin >> number;
    cout << "Input position: ";
    cin >> position;
    int** array2 = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array2[i] = new int[*cols + 1];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < position - 1; j++) {
            array2[i][j] = array[i][j];
        }
        array2[i][position - 1] = number;
        for (int j = position - 1; j < *cols; j++) {
            array2[i][j + 1] = array[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        delete[]array[i];
    }
    delete[]array;
    (*cols)++;
    return array2;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
