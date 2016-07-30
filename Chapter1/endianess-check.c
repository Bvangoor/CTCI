#include <stdio.h>

int main() {
        unsigned short word = 0x1234;
        unsigned char *p = (unsigned char *) &word;

        if (p[0] == 0x34)
                printf("Machine is Little endian\n");
        else
                printf("Machine is Big endian\n");

return 0;
}
