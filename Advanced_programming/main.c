#include <stdio.h>
#include "memory_pool.h"

int main()
{
    // 创建一个大小为1024字节的内存池
    MemoryPool *pool = create_memory_pool(1024);
    if (!pool)
    {
        printf("Failed to create memory pool\n");
        return 1;
    }

    // 从内存池分配256字节的内存
    void *block1 = pool_alloc(pool, 256);
    if (!block1)
    {
        printf("Failed to allocate memory from pool\n");
        destroy_memory_pool(pool);
        return 1;
    }

    // 从内存池再分配512字节的内存
    void *block2 = pool_alloc(pool, 512);
    if (!block2)
    {
        printf("Failed to allocate memory from pool\n");
        destroy_memory_pool(pool);
        return 1;
    }

    // 打印内存池的使用情况
    printf("Memory pool created with size: %zu bytes\n", pool->size);
    printf("Memory pool used: %zu bytes\n", pool->used);

    // 销毁内存池
    destroy_memory_pool(pool);
    return 0;
}
