#include <stdio.h>
#include <stdlib.h>

// 定义一个通用的数据容器结构体
typedef struct GenericContainer
{
    void *data; // 使用void*指针来存储任何类型的数据
    // 可以添加其他字段，例如数据的大小、类型信息等
} GenericContainer;

// 创建一个新的数据容器实例
GenericContainer *createContainer(void *data)
{
    GenericContainer *container = (GenericContainer *)malloc(sizeof(GenericContainer));
    if (container == NULL)
    {
        // 内存分配失败
        return NULL;
    }
    container->data = data;
    return container;
}

// 销毁数据容器实例
void destroyContainer(GenericContainer *container)
{
    if (container != NULL)
    {
        free(container->data); // 假设data指向的内存是通过malloc分配的
        free(container);
    }
}

// 获取容器中的数据
void *getData(GenericContainer *container)
{
    if (container != NULL)
    {
        return container->data;
    }
    return NULL;
}

// 设置容器中的数据
void setData(GenericContainer *container, void *data)
{
    if (container != NULL)
    {
        container->data = data;
    }
}

int main()
{
    // 创建一个整型数据
    int *number = (int *)malloc(sizeof(int));
    *number = 42;

    // 创建一个通用的数据容器，并将整型数据存储进去
    GenericContainer *container = createContainer(number);

    // 获取并打印容器中的数据
    int *result = (int *)getData(container);
    printf("The number is: %d\n", *result);

    // 销毁数据容器
    destroyContainer(container);

    return 0;
}