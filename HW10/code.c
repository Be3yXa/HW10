#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

float area_triangle(float a, float b);
void draw_triangle(int rows, char sym);
void print_definition();
int get_sides_param(int rows);
int compare_triangles(float area1, float area2);
int main() {
    setlocale(LC_CTYPE, "RUS");
    int choice;
    int size = 5;
    char symbol = '*';
    printf("--- Программа для работы с геометрической фигурой ---\n");
    printf("Текущая фигура: Прямоугольный равнобедренный треугольник\n");
    printf("Размер катета (число строк) по умолчанию: %d\n\n", size);
    do {
        printf("Выберите операцию из меню:\n");
        printf("1) Рассчитать площадь фигуры\n");
        printf("2) Вывести определение фигуры\n");
        printf("3) Нарисовать фигуру\n");
        printf("4) Сравнить площадь текущей фигуры с другой\n");
        printf("0) Выход из программы\n");
        printf("Ваш выбор: ");
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода!\n");
            break;
        }
        switch (choice) {
        case 1: {
            float area = area_triangle((float)size, (float)size);
            printf("\nПлощадь треугольника с катетами %d и %d равна: %.2f\n\n", size, size, area);
            break;
        }
        case 2:
            print_definition();
            break;
        case 3:
            printf("\nВведите символ для отрисовки фигуры (например, * или 5): ");
            scanf(" %c", &symbol);
            printf("Введите размер катета (количество строк): ");
            scanf("%d", &size);
            printf("\nРезультат отрисовки:\n");
            draw_triangle(size, symbol);
            break;
        case 4: {
            int other_size;
            printf("\nВведите размер катета второго треугольника для сравнения: ");
            scanf("%d", &other_size);

            float area1 = area_triangle((float)size, (float)size);
            float area2 = area_triangle((float)other_size, (float)other_size);

            int diff = compare_triangles(area1, area2);
            if (diff > 0) {
                printf("Первый треугольник больше второго по площади.\n\n");
            }
            else if (diff < 0) {
                printf("Первый треугольник меньше второго по площади.\n\n");
            }
            else {
                printf("Треугольники равны по площади.\n\n");
            }
            break;
        }
        case 0:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный пункт меню! Попробуйте снова.\n\n");
        }
    } while (choice != 0);
    return 0;
}
// 1) Функция вычисления площади треугольника
float area_triangle(float a, float b) {
    return 0.5f * a * b;
}
// 2) Функция вывода определения фигуры
void print_definition() {
    setlocale(LC_CTYPE, "RUS");
    printf("\nОпределение:\n");
    printf("На изображении представлен прямоугольный равнобедренный треугольник.\n");
    printf("Это треугольник, у которого один угол прямой (90 градусов), ");
    printf("а два катета равны между собой.\n\n");
}
// 3) Функция рисования фигуры заданным символом
void draw_triangle(int rows, char sym) {
    setlocale(LC_CTYPE, "RUS");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c ", sym);
        }
        printf("\n");
    }
    printf("\n");
}
// Функция вывода текущего параметра стороны
int get_sides_param(int rows) {
    return rows;
}
// 4) Функция сравнения двух фигур по площади (возвращает разницу знаков)
int compare_triangles(float area1, float area2) {
    if (area1 > area2) return 1;
    if (area1 < area2) return -1;
    return 0;
}