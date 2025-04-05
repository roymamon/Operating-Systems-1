#include <stdio.h>
#include <signal.h>

int main() {
    raise(SIGFPE);
    return 0;
}
