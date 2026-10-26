#ifndef STRINGS_H_INCLUDED
#define STRINGS_H_INCLUDED

/*
 * Выделение подстроки из src в готовый буфер dest.
 * n - начальный индекс (если < 0, отсчет с конца строки).
 * m - длина подстроки (если < 0, то m задает конечный индекс, а не длину).
 * Возвращает указатель на dest.
 */
char *substr(const char *src, char *dest, long long n, long long m);

#endif /* STRINGS_H_INCLUDED */