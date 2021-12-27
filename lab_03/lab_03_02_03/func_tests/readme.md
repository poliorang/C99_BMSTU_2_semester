# тесты для лабораторной работы №2

## Входные данные 
Размер матрицы (целые числа): r, c;
Заданная цифра (целое число): num;
Элементы матрицы (целые числа).

## Выходные данные
Матрица, из которой удалены все столбцы, хотя бы в одном числе 
которых встречается заданная цифра.

## Позитивные тесты:
 - 01 - матрица малого размера;
 - 02 - матрица большого размера;
 - 03 - количество столбцов равно 1;
 - 04 - заданное число - нуль;
 - 05 - количество строк равно 1.

## Негативные тесты:
 - 01 - число столбцов равно 0;
 - 02 - число строк больше 10;
 - 03 - некорректный символ при вводе элементов матрицы(буква);
 - 04 - некорректный символ при задании параметров матрицы (буква);
 - 05 - некорректный символ при вводе элементов матрицы(буква);
 - 06 - некорректный символ при вводе элементов матрицы(число, а не цифра);
 - 07 - некорректный символ при вводе элементов матрицы(буква);
 - 08 - все столбцы удалены.