"""Алгоритм Штрассена"""


def add_matrices(a, b):
    """Складывает две матрицы A и B."""
    return [[a[i][j] + b[i][j] for j in range(len(a[0]))] for i in range(len(a))]


def subtract_matrices(a, b):
    """Вычитает матрицы B из A."""
    return [[a[i][j] - b[i][j] for j in range(len(a[0]))] for i in range(len(a))]


def pad_matrix(matrix, size):
    """Дополняет матрицу нулями до размера size x size."""
    padded = []
    for i in range(size):
        if i < len(matrix):
            padded.append(matrix[i] + [0] * (size - len(matrix[i])))
        else:
            padded.append([0] * size)
    return padded

def split_matrix(matrix):
    """Делит матрицу на 4 подматрицы."""
    n = len(matrix)
    mid = n // 2
    return (
        [row[:mid] for row in matrix[:mid]],  # a11
        [row[mid:] for row in matrix[:mid]],  # a12
        [row[:mid] for row in matrix[mid:]],  # a21
        [row[mid:] for row in matrix[mid:]]   # a22
    )

def strassen_recursive(a, b):
    """Рекурсивная функция для умножения матриц с использованием алгоритма Штрассена."""
    if len(a) == 1:  # базовый случай
        return [[a[0][0] * b[0][0]]]
    # Получаем подматрицы a и b в виде списков
    a_s = split_matrix(a)
    b_s = split_matrix(b)
    # Вызовы для вычисления m1, m2, m3, m4, m5 и m6
    m1 = strassen_recursive(add_matrices(a_s[0], a_s[3]),add_matrices(b_s[0], b_s[3]))  # m1
    m2 = strassen_recursive(add_matrices(a_s[2], a_s[3]),b_s[0])  # m2
    m3 = strassen_recursive(a_s[0],subtract_matrices(b_s[1], b_s[3]))  # m3
    m4 = strassen_recursive(a_s[3],subtract_matrices(b_s[2], b_s[0]))  # m4
    m5 = strassen_recursive(add_matrices(a_s[0], a_s[1]),b_s[3])  # m5
    m6 = strassen_recursive(subtract_matrices(a_s[2], a_s[0]),add_matrices(b_s[0], b_s[1]))  # m6
    m7 = strassen_recursive(subtract_matrices(a_s[1], a_s[3]),add_matrices(b_s[2], b_s[3]))  # m7

    # Собираем итоговую матрицу из результатов
    c11 = add_matrices(subtract_matrices(add_matrices(m1, m4), m5), m7)
    c22 = add_matrices(subtract_matrices(add_matrices(m1, m3), m2), m6)

    # Объединяем подматрицы в итоговую матрицу
    top = [c11_row + c12_row for c11_row, c12_row in zip(c11, add_matrices(m3, m5))]
    bottom = [c21_row + c22_row for c21_row, c22_row in zip(add_matrices(m2, m4), c22)]
    return top + bottom

def assemble_result(c11, c12, c21, c22):
    """Собирает итоговую матрицу из четырех подматриц."""
    top_half = [c11[i] + c12[i] for i in range(len(c11))]
    bottom_half = [c21[i] + c22[i] for i in range(len(c21))]
    return top_half + bottom_half

def strassen(a, b):
    """Основная функция для умножения матриц с использованием алгоритма Штрассена."""
    return strassen_recursive(a, b)

def multiply_matrices(a, b):
    """Умножает две матрицы A и B, дополняя их до квадратного размера при необходимости."""
    a_rows, a_cols = len(a), len(a[0])
    b_rows, b_cols = len(b), len(b[0])     # Определяем новый размер для квадратных матриц
    new_size = 1
    while new_size < max(a_rows, a_cols, b_rows, b_cols):
        new_size *= 2

    # Дополняем матрицы нулями
    padded_a = pad_matrix(a, new_size)
    padded_b = pad_matrix(b, new_size)

    # Умножаем дополненные матрицы
    padded_c = strassen(padded_a, padded_b)

    # Обрезаем результат до оригинального размера
    return [row[:b_cols] for row in padded_c[:a_rows]]

def read_matrix(rows, cols):
    """Считывает матрицу заданного размера с клавиатуры."""
    matrix = []
    for i in range(rows):
        row_m = list(map(int, input(f"Введите элементы {i + 1}-й строки: ").split()))
        while len(row_m) != cols:
            print(f"Ошибка: ожидалось {cols} элементов, а введено {len(row_m)}. Попробуйте снова.")
            row_m = list(map(int, input(f"Введите элементы {i + 1}-й строки: ").split()))
        matrix.append(row_m)
    return matrix

# Использование
rows_a = int(input("Введите количество строк для матрицы A: "))
cols_a = int(input("Введите количество столбцов для матрицы A: "))
A = read_matrix(rows_a, cols_a)

rows_b = int(input("Введите количество строк для матрицы B: "))
cols_b = int(input("Введите количество столбцов для матрицы B: "))
B = read_matrix(rows_b, cols_b)

# Проверяем, соответствует ли количество столбцов матрицы A количеству строк матрицы B
if cols_a != rows_b:
    print("Ошибка: количество столбцов в матрице A должно быть равно количеству строк в матрице B.")
else:
    result = multiply_matrices(A, B)
    print("Результат умножения:")
    for row in result:
        print(row) # lab_1 (\r\n)
