#include <stdlib.h>
#include <string.h>
#include "memory_pool.h"

// 创建内存池
MemoryPool *create_memory_pool(size_t blockSize)
{
    MemoryPool *pool = (MemoryPool *)malloc(sizeof(MemoryPool));
    if (!pool) // 内存分配失败
        return NULL;
    pool->memory = malloc(blockSize);
    if (!pool->memory)
    {
        free(pool);
        return NULL;
    }
    pool->size = blockSize;
    pool->used = 0;
    return pool;
}

// 从内存池分配内存
void *pool_alloc(MemoryPool *pool, size_t size)
{
    if (pool->used + size > pool->size) // 超出内存池大小
        return NULL;
    void *ptr = (char *)pool->memory + pool->used; // 将指针指向内存池中未使用的空间
    pool->used += size;
    return ptr;
}

// 释放内存池
void destroy_memory_pool(MemoryPool *pool)
{
    if (pool)
    {
        if (pool->memory)
        {
            free(pool->memory);
            free(pool);
        }
    }
}