#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>

void calculate_md5(const unsigned char* data, size_t length, unsigned char* md5_hash) {
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, data, length);
    MD5_Final(md5_hash, &ctx);
}

void print_md5(const unsigned char* md5_hash) {
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", md5_hash[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {

    if (argc < 2)
        {
            printf("Usage: %s str\n", argv[0]);
            return 1;
        }


    size_t length = sizeof(argv[1]) - 1; // 减去字符串末尾的空字符
    unsigned char md5_hash[MD5_DIGEST_LENGTH];

    calculate_md5(argv[1], length, md5_hash);
    print_md5(md5_hash);

    return 0;
}
