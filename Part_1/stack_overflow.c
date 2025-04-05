#include <stdio.h>

void crash() {
    crash();  
}

int main() {
    crash();
    return 0;
}
