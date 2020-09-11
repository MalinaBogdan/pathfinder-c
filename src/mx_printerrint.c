#include "pathfinder.h"
#include "libmx.h"

void mx_printerrint(int n) {
    if (n == 0) {
        write(2, "0", 1);
        return;
    }
    int ultralow = 0;
    int minus = 0;
    if (n < 0) {
        minus = 1;
        if (n != -2147483648)
            n *= -1;
        else {
            n += 1;
            n *= -1;
            ultralow = 1;
        }
    }
    int buf[25];
    int counter = 0;
    while (n != 0) {
        buf[counter] = n % 10;
        n /= 10;
        counter++;
    }
    if (ultralow == 1)
        buf[0] = 8;
    if (minus == 1)
        write(2, "-", 1);
    char bufout;
    for (int i = counter - 1; i >= 0; i--) {
        bufout=buf[i]+'0';
        write(2, &bufout, 1);
    }
}
