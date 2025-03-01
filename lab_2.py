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

def strassen(a, b):
    """Умножает матрицы A и B с использованием алгоритма Штрассена."""
    n = len(a)
    if n == 1:  # базовый случай
        return [[a[0][0] * b[0][0]]]
    mid = n // 2   # Разделяем A и B на 4 подматрицы
    a11 = [row[:mid] for row in a[:mid]]
    a12 = [row[mid:] for row in a[:mid]]
    a21 = [row[:mid] for row in a[mid:]]
    a22 = [row[mid:] for row in a[mid:]]  # Разделяем A и B на 4 подматрицы
    b11 = [row[:mid] for row in b[:mid]]
    b12 = [row[mid:] for row in b[:mid]]
    b21 = [row[:mid] for row in b[mid:]]
    b22 = [row[mid:] for row in b[mid:]]

    # Вычисляем промежуточные матрицы
    m1 = strassen(add_matrices(a11, a22), add_matrices(b11, b22))
    m2 = strassen(add_matrices(a21, a22), b11)
    m3 = strassen(a11, subtract_matrices(b12, b22))
    m4 = strassen(a22, subtract_matrices(b21, b11))
    m5 = strassen(add_matrices(a11, a12), b22)
    m6 = strassen(subtract_matrices(a21, a11), add_matrices(b11, b12))
    m7 = strassen(subtract_matrices(a12, a22), add_matrices(b21, b22))

    # Собираем результаты в итоговую матрицу
    c11 = add_matrices(subtract_matrices(add_matrices(m1, m4), m5), m7)
    c12 = add_matrices(m3, m5)
    c21 = add_matrices(m2, m4)
    c22 = add_matrices(subtract_matrices(add_matrices(m1, m3), m2), m6)

    # Собираем матрицу C
    new_size = len(c11)
    c = []
    for i in range(new_size):
        c.append(c11[i] + c12[i])
    for i in range(new_size):
        c.append(c21[i] + c22[i])

    return c

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
