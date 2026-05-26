#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_M = 50;
const int MAX_N = 50;

// Прототипи функцій
void task1();
void task2();
void get_matr(int in_matr[MAX_M][MAX_N], int & in_m, int & in_n);
void show_matr(const int out_matr[MAX_M][MAX_N], const int m, const int n);
void process_matrix_19(const int matr[MAX_M][MAX_N], const int m, const int n);
void swap_quadrants_58(int matr[MAX_M][MAX_N], const int m, const int n);

// Головна функція
int main() {
    int num;
    do {
        cout << "---" << endl;
        cout << "Task num (1 - Matrix19, 2 - Matrix58, 0 - Exit) -> ";
        cin >> num;
        switch(num){
            case 0:
                cout << "Exit..." << endl;
                break;
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            default:
                cout << "Wrong task num!" << endl;
        }
    } while(num != 0);
    return 0;
}

// Функція введення матриці
void get_matr(int in_matr[MAX_M][MAX_N], int & in_m, int & in_n) {
    do {
        cout << "Enter rows count M (2-50): ";
        cin >> in_m;
        cout << "Enter columns count N (2-50): ";
        cin >> in_n;
    } while (in_n < 2 || in_n > MAX_N || in_m < 2 || in_m > MAX_M);
    
    cout << "Enter elements: " << endl;
    for (int i = 0; i < in_m; i++) {
        for (int j = 0; j < in_n; j++) {
            cin >> in_matr[i][j];
        }
    }
}

// Функція виведення масиву
void show_matr(const int out_matr[MAX_M][MAX_N], const int m, const int n) {
    cout << endl << "Matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << out_matr[i][j];
        }
        cout << endl;
    }
}

// Завдання 1 (Matrix19)
void task1() {
    int matr1[MAX_M][MAX_N];
    int row, col;
    cout << "\n--- Завдання 1 (Matrix19) ---" << endl;
    get_matr(matr1, row, col);
    cout << "Вихідна матриця:";
    show_matr(matr1, row, col);
    process_matrix_19(matr1, row, col);
}

// Функція обробки для Завдання 1 (Сума рядків)
void process_matrix_19(const int matr[MAX_M][MAX_N], const int m, const int n) {
    cout << "\nСуми елементів рядків:" << endl;
    for (int i = 0; i < m; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += matr[i][j];
        }
        cout << "Рядок " << i + 1 << ": " << row_sum << endl;
    }
}

// Завдання 2 (Matrix58)
void task2() {
    int matr1[MAX_M][MAX_N];
    int row, col;
    cout << "\n--- Завдання 2 (Matrix58) ---" << endl;
    get_matr(matr1, row, col);
    
    // Перевірка на парність
    if (row % 2 != 0 || col % 2 != 0) {
        cout << "Помилка! Для Завдання 58 M і N повинні бути парними числами." << endl;
        return;
    }
    
    cout << "Матриця до змін:";
    show_matr(matr1, row, col);
    
    swap_quadrants_58(matr1, row, col);
    
    cout << "Матриця після перестановки чвертей:";
    show_matr(matr1, row, col);
}

// Функція обробки для Завдання 2 (Перестановка чвертей)
void swap_quadrants_58(int matr[MAX_M][MAX_N], const int m, const int n) {
    int half_m = m / 2;
    int half_n = n / 2;
    
    for (int i = 0; i < half_m; i++) {
        for (int j = 0; j < half_n; j++) {
            // Міняємо місцями праву верхню (i, j + half_n) і ліву нижню (i + half_m, j)
            int temp = matr[i][j + half_n];
            matr[i][j + half_n] = matr[i + half_m][j];
            matr[i + half_m][j] = temp;
        }
    }
}
