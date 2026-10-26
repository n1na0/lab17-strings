#include "strings.h"

char *substr(const char *src, char *dest, long long n, long long m) {
    /* 1. Длина строки */
    long long len = 0;
    while (src[len] != '\0') len++;

    /* Если m = 0, это всегда "до конца строки" */
    if (m == 0) {
        if (n >= 0 && n < len) {
            long long j = 0;
            for (long long i = n; i < len; i++) dest[j++] = src[i];
            dest[j] = '\0';
            return dest;
        } else if (n < 0) {
            long long start = len + n;
            if (start < 0) start = 0;
            long long j = 0;
            for (long long i = start; i < len; i++) dest[j++] = src[i];
            dest[j] = '\0';
            return dest;
        } else {
            dest[0] = '\0';
            return dest;
        }
    }

    long long start;
    /* 2. Вычисляем базовый start */
    if (n >= 0) {
        start = n;
    } else {
        start = len + n;
    }

    /* 3. Обрабатываем границы для n */
    if (start < 0) {
        if (m > 0) {
            m = m + start; /* съедаем длину */
            if (m <= 0) { dest[0] = '\0'; return dest; }
            start = 0;
        } else {
            /* Если n до строки и m < 0, мы не можем взять символы */
            dest[0] = '\0';
            return dest;
        }
    } else if (start >= len) {
        if (m < 0) {
            long long overshoot = start - len;
            m = m + overshoot;
            start = len;
            if (m >= 0) { dest[0] = '\0'; return dest; }
        } else {
            dest[0] = '\0';
            return dest;
        }
    }

    /* 4. Определяем end и корректируем start для отрицательного m */
    long long end;
    if (m > 0) {
        end = start + m;
    } else {
        /* m < 0 */
        long long length = -m;
        end = start + 1;
        start = start - length + 1;
        
        if (start < 0) {
            /* Если start ушел влево, мы просто берем с 0 до исходного start + 1 */
            start = 0;
        }
    }

    /* 5. Финальная корректировка границ */
    if (end > len) end = len;
    if (end < start) end = start;

    /* 6. Копирование */
    long long i, j = 0;
    for (i = start; i < end; i++) {
        dest[j++] = src[i];
    }
    dest[j] = '\0';

    return dest;
}