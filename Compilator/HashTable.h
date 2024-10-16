#pragma once
//#include "includes.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Token.h"
#include <string>

using namespace std;

const int ConstSize = 9;

class HashTable {
private:
    Token* table;
    int size;
    int elementCount;

    void rehash()
    {
        // Увеличиваем размер в два раза и находим следующий простое число
        int newSize = size * 2;
        while (!isPrime(newSize)) {
            newSize++;
        }

        Token* newTable = new Token[newSize];
        int oldSize = size;

        // Инициализируем новую таблицу
        for (int i = 0; i < newSize; ++i) {
            newTable[i] = Token(); // Инициализация пустых токенов
        }

        // Пересчитываем элементы из старой таблицы
        for (int i = 0; i < oldSize; ++i)
        {
            if (table[i].getLexem() != "")
            {
                int newHash = hashFunc(table[i].getLexem(), newSize);

                // Пробируем для нахождения пустой ячейки
                while (newTable[newHash].getLexem() != "")
                {
                    newHash = (newHash + 1) % newSize;
                }
                newTable[newHash] = table[i]; // Перемещаем токен
            }
        }

        delete[] table; // Удаляем старую таблицу
        table = newTable; // Устанавливаем новую таблицу
        size = newSize; // Обновляем размер
    }

    // Проверка числа на простоту
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    HashTable()
    {
        size = ConstSize;
        elementCount = 0;
        table = new Token[ConstSize];
    }
    int hashFunc(const string& str, int size) const
    {
        unsigned long hash = 5381;
        int c;
        const char* s = str.c_str();

        while ((c = *s++))
        {
            hash = ((hash << 5) + hash) + c; 
        }

        return (hash) % size; // Возвращаем значение в пределах размера таблицы
    }
    void add(Token& token)
    {
        if (elementCount >= size * 0.75)
        {
            rehash();
        }
        int hash = hashFunc(token.getLexem(), size);
        if (elementCount < size)
        {
            Token tokenByIndex = table[hash];
            if (tokenByIndex.getLexem() == token.getLexem())
            {
                return;
            }
            else
            {
                while (tokenByIndex.getLexem() != "")
                {
                    if (tokenByIndex.getLexem() == token.getLexem())
                    {
                        return;
                    }
                    hash = (hash + 1) % size;
                    tokenByIndex = table[hash];
                }
                table[hash].setLexemName(token.getLexem());
                table[hash].setLexemType(token.getLexemType());
                elementCount++;
            }
        }
    }
    string get(const string& key)
    {
        int hash = hashFunc(key, size);
        int startIndex = hash;
        while (table[hash].getLexem() != "")
        {
            if (table[hash].getLexem() == key)
            {
                return table[hash].getLexemType();
            }
            hash = (hash + 1) % size;
            if (hash == startIndex)
            {
                break;
            }
        }
        return "";
    }

    void printHashTable() const
    {
        std::ofstream out("output.txt");
        for (int i = 0; i < size; i++)
        {
            if (!table[i].getLexem().empty())
            {
                out << setw(10) << i << " |" << setw(10) << table[i].getLexem() << " |      " << table[i].getLexemType() << '\n';
            }
        }
        out.close(); // Закрываем файл после записи
    }

    ~HashTable()
    {
        delete[] table; // Освобождаем память при уничтожении
    }
};