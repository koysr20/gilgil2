#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t readFile(const char* filename) {
    FILE* file = fopen(filename, "rb");

    uint32_t value;
    if (fread(&value, sizeof(value), 1, file) != 1) {
        perror("Error reading from file");
        return -1;
    }

    fclose(file);

    return ntohl(value);
}

int main(int argc, char* argv[]) {
    uint32_t value1 = readFile(argv[1]);
    uint32_t value2 = readFile(argv[2]);
    uint32_t sum = value1 + value2;

    printf("%u(0x%08x) + %u(0x%08x) = %u(0x%08x)\n", value1, value1, value2, value2, sum, sum);

    return 0;
}

