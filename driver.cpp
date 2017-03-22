#include "stack/Stack.h"
#include "stdio.h"

int main() {
    Stack<int> s(1);
    s.push(1);

    char *str = s.toString(',');
    printf("%s", str);
    return 0;
}