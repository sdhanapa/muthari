#include <stdio.h>

void getInt(void *data) {
    int *info = (int*)data; // typecasting the void pointer to specific data type
    printf("Integer data: %d",*info);
}

void getOperation(void *data, void (*fp)(void*)) {
    fp(data); // call the function pointed by the pointer
}

int main() {
    int idata = 56;
    getOperation(&idata, getInt);
    
    return 0;
}