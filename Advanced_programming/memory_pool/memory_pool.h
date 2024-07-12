#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <stddef.h>

// 内存池结构体
/**
 * @param size 内存池的总大小
 * @param used 已使用的内存大小
 * @param memory 内存池的起始地址
 */
typedef struct MemoryPool
{
    size_t size;  // 内存池的总大小
    size_t used;  // 已使用的内存大小
    void *memory; // 内存池的起始地址
} MemoryPool;

// 初始化内存池
MemoryPool *create_memory_pool(size_t size);

// 从内存池分配内存
void *pool_alloc(MemoryPool *pool, size_t size);

// 释放内存池
void destroy_memory_pool(MemoryPool *pool);

#endif // MEMORY_POOL_H
