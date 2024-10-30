#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
using namespace std;

void func(char str[], int &sum0, int &count0, int &j0) {
    int sum = 0, count = 0, num = 0;
    int i = 0, start = -1;

    while (str[i] != '\n') {
        if (isdigit(str[i])) {
            if (start == -1) start = i;
            num = num * 10 + (str[i] - '0');
        }
        else {
            if (start != -1) {
                sum += num;
                count++;
                num = 0;
                start = -1;
            }
        }
        i++;
    }
    if (start != -1) { 
        sum += num;
        count++;
    }

    int j = i;
    str[j++] = '&';
    sum0 = sum;
    count0 = count;
    j0 = j;
}

void task1() {
    int sum, count;
    int j;
    setlocale(LC_ALL, "RUS");
    char str[100];
    cout << "Введите строку: ";
    fgets(str, sizeof(str), stdin);
    cout << "Результат: ";
    func(str, sum, count, j);
    for (int h = 0; h < j; h++) {
        cout << str[h];
    }
    cout << sum << "&" << count;
}

void task2() {
    int sum, count;
    int j;
    setlocale(LC_ALL, "RUS");
    char str[100];
    cout << "Введите строку: ";
    fgets(str, sizeof(str), stdin);
    cout << "Результат: ";
    func(str, sum, count, j);
    for (int h = 0; h < j; h++) {
        cout << str[h];
    }
    cout << sum << "&" << count;
}

void task3() {
    int sum, count;
    int j;
    FILE* ugar = fopen("ugar.txt", "r");
    char str[100];
    fgets(str, sizeof(str), ugar);
    fclose(ugar);
    cout << "Результат: ";
    func(str, sum, count, j);
    FILE* ugar2 = fopen("ugar2.txt", "w");
    fprintf(ugar2, "%.*s&%d&%d", j, str, sum, count);
    fclose(ugar2);
}

int main(){
    task3();
}
