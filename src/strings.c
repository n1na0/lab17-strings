#include "strings.h"

char *substr(const char *src, char *dest, long long n, long long m) {
    /* 1. Длина строки */
    long long len = 0;
    while (src[len] != '\0') len++;

    /* 2. Начальная позиция */
    long long start = (n >= 0) ? n : len + n;
    long long end;

    /* 3. Конечная позиция */
    if (m == 0) {
        end = len;                 // Если длина 0, берем до конца
    } else if (m > 0) {
        end = start + m;           // Обычная длина
    } else {
        long long length = -m;     // m < 0: это длина, взятая НАЗАД
        end = start + 1;
        start = start - length + 1;
    }

    /* 4. Защита от выхода за границы */
    if (start < 0) {
        if (m > 0) {
            m = m + start;    
            if (m <= 0) { dest[0] = '\0'; return dest; }
            start = 0;
            end = start + m;
        } else {
            start = 0;             // Если ушли влево, начинаем с 0
        }
    }

    if (start > len) start = len;
    if (end > len) end = len;
    if (end < start) end = start;

    /* 5. Копирование через указатели */
    const char *p = src + start;
    char *q = dest;
    while (p < src + end) {
        *q = *p;
        q++;
        p++;
    }
    *q = '\0';

    return dest;
}