#include <stdio.h>
#include <string.h>
#include "strings.h"

/* Структура для одного теста */
typedef struct {
    long long n;
    long long m;
    const char *expected;
} TestCase;

int main(void) {
    const char *src = "0123456789";
    char dest[256]; /* Буфер с запасом */
    
    TestCase tests[] = {
        {3, 2, "34"},
        {4, 3, "456"},
        {4, 0, "456789"},
        {4, 100, "456789"},
        {10, 2, ""},
        {12, 3, ""},
        {6, -2, "56"},
        {4, -3, "234"},
        {0, -1, "0"},
        {3, 1, "3"},
        {3, -1, "3"},
        {4, -10, "01234"},
        {12, -5, "89"},
        {100, -3, ""},
        {-1, 1, "9"},
        {-3, 2, "78"},
        {-3, 0, "789"},
        {-4, 100, "6789"},
        {-12, 4, "01"},
        {-20, 3, ""},
        {-20, 0, "0123456789"},
        {-3, -2, "67"},
        {-6, -4, "1234"},
        {-6, -20, "01234"},
        {-20, -2, ""}
    };
    
    int total = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    printf("=== Автотесты для substr ===\n");
    
    for (int i = 0; i < total; i++) {
        /* Вызываем нашу функцию */
        substr(src, dest, tests[i].n, tests[i].m);
        
        /* Проверяем через strcmp */
        if (strcmp(dest, tests[i].expected) == 0) {
            passed++;
            printf("OK   (%3lld, %3lld) -> \"%s\"\n", 
                   tests[i].n, tests[i].m, dest);
        } else {
            printf("FAIL (%3lld, %3lld) -> получили \"%s\", ожидали \"%s\"\n", 
                   tests[i].n, tests[i].m, dest, tests[i].expected);
        }
    }
    
    printf("--------------------------------------\n");
    printf("Итого: %d/%d тестов пройдено\n", passed, total);
    
    return (passed == total) ? 0 : 1;
}