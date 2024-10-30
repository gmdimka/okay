#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
using namespace std;

void func(char str[], int& sum0, int& count0, int& j0) {
    int sum = 0, count = 0, num = 0;
    int i = 0, start = -1;

    while (str[i] != '\0') {
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
    sum0 = sum;
    count0 = count;
    j0 = j;
}

void task1() {
    int sum, count;
    int j;
    char* str = (char*)malloc(sizeof(char));
    if (str == NULL) {
        cout << "Memory was not allocated" << endl;
        exit(1);
    }

    cout << "Введите строку: ";
    char symbol;
    int length = 0;
    while ((symbol = getchar()) != '\n') {
        str[length++] = symbol;

        char* tmp = (char*)malloc((length + 2) * sizeof(char));
        if (tmp == NULL) {
            cout << "Memory was not allocated for tmp" << endl;
            free(str);
            exit(1);
        }

        for (int i = 0; i < length; i++) {
            tmp[i] = str[i];
        }

        free(str);
        str = tmp;
    }
    str[length] = '\0';
    func(str, sum, count, j);
    for (int h = 0; h < j; h++) {
        cout << str[h];
    }
    free(str);
    cout << "&" << sum << "&" << count;
}

void task2() {
    int sum, count;
    int j;
    setlocale(LC_ALL, "RUS");
    int length = 0, allocated = 4;
    char symbol;
    char* str = (char*)calloc(allocated, sizeof(char));

    if (str == NULL) {
        cout << "Memory was not allocated" << endl;
        exit(1);
    }

    cout << "Введите строку: ";


    while ((symbol = getchar()) != '\n') {
        if ((length + 1) >= allocated) {
            allocated += 4;
            char* tmp = (char*)realloc(str, allocated * sizeof(char));

            if (tmp != NULL) {
                str = tmp;
            }
            else {
                free(str);
                cout << "Memory was not allocated for tmp" << endl;
                exit(1);
            }
        }

        str[length++] = symbol;
    }
    str[length] = '\0';
    cout << "Результат: ";
    func(str, sum, count, j);
    for (int h = 0; h < j; h++) {
        cout << str[h];
    }
    free(str);
    cout << "&" << sum << "&" << count;
}

void task3() {
    int sum, count;
    int j;
    int length = 0, allocated = 4;
    char symbol;
    char* str = (char*)calloc(allocated, sizeof(char));

    if (str == NULL) {
        cout << "Memory was not allocated" << endl;
        exit(1);
    }

    cout << "Enter message: ";

    while ((symbol = getchar()) != '\n') {
        if (length >= allocated) {
            allocated += 4;
            char* tmp = (char*)realloc(str, allocated * sizeof(char));

            if (tmp != NULL) {
                str = tmp;
            }
            else {
                free(str);
                cout << "Memory was not allocated for tmp" << endl;
                exit(1);
            }
        }

        str[length++] = symbol;
    }

    FILE* ugar = fopen("ugar.txt", "w");
    for (int i = 0; i < length; i++)
    {
        fputc(str[i], ugar);
    }

    free(str);
    fclose(ugar);

    length = 0, allocated = 4;

    FILE* ugar2 = fopen("ugar.txt", "r");
    char* new_str = (char*)calloc(allocated, sizeof(char));
    int new_sym;
    if (new_str == NULL) {
        cout << "Memory was not allocated" << endl;
        exit(1);
    }
    
    while ((new_sym = fgetc(ugar2)) != EOF) {
        if ((length + 1) >= allocated) {
            allocated += 4;
            char* tmp = (char*)realloc(new_str, allocated * sizeof(char));
            if (tmp != NULL) {
                new_str = tmp;
            }
            else {
                free(new_str);
                cout << "Memory was not allocated fot tmp" << endl;
                exit(1);
            }
        }

        new_str[length++] = new_sym;
    }
    new_str[length] = '\0';

    fclose(ugar2);
    func(new_str, sum, count, j);
    FILE* res = fopen("res.txt", "w");
    fprintf(res, "%s&%d&%d", new_str, sum, count);
    fclose(res);
    free(new_str);
}

int main() {
    setlocale(LC_ALL, "RUS");
    task3();
}
