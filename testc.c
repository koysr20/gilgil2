#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

uint32_t readHexValue(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    uint32_t value;
    if (fread(&value, sizeof(value), 1, file) != 1) {
        perror("Error reading from file");
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return ntohl(value);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    uint32_t value1 = readHexValue(argv[1]);
    uint32_t value2 = readHexValue(argv[2]);
    uint32_t sum = value1 + value2;

    printf("%u(0x%08x) + %u(0x%08x) = %u(0x%08x)\n", value1, value1, value2, value2, sum, sum);

    return EXIT_SUCCESS;
}

