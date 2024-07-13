/**
 * 分块的基本思想是，通过对原数据的适当划分，并在划分后的每一个块上预处理部分信息，从而较一般的暴力算法取得更优的时间复杂度。

分块的时间复杂度主要取决于分块的块长，一般可以通过均值不等式求出某个问题下的最优块长，以及相应的时间复杂度。

分块是一种很灵活的思想，相较于树状数组和线段树，分块的优点是通用性更好，可以维护很多树状数组和线段树无法维护的信息。

当然，分块的缺点是渐进意义的复杂度，相较于线段树和树状数组不够好。

不过在大多数问题上，分块仍然是解决这些问题的一个不错选择。

下面是几个例子。
 - 区间和
 - 块内最大值
 - 块内最小值
 - 对询问分块
 */

/**
 * 先求出块的大小(block)
 * 求出块数(num)
 * 求出块的左右端点(l[],r[])
 * 求一下每个节点属于哪个块(belong[])
 *
    int n, m, num, block;
    int l[nmax], r[nmax], belong[nmax]; // 块的左右端点, 每个节点属于哪个块
    void build()
    {
        block = sqrt(n);
        num = n / block + (n % block); // 计算块数
        for (int i = 1; i <= num; i++)
        {
            l[i] = (i - 1) * block + 1;
            r[i] = i * block;
        }
        r[num] = n;
        for (int i = 1; i <= n; i++)
            belong[i] = (i - 1) / block + 1;
    }
 * /


/**
 * 示例程序
 * @author tongyilingma
 */
#include <stdio.h>
#include <stdlib.h>

// 数据类型定义，这里假设数据类型为整型
typedef int DataType;

// 定义块的结构体
typedef struct
{
    int start;
    int end;
} Block;

// 分块函数
void split_data(int data[], int num_elements, int num_blocks, Block blocks[])
{
    int elements_per_block = num_elements / num_blocks;
    int remainder = num_elements % num_blocks;

    int current_index = 0;
    for (int i = 0; i < num_blocks; i++)
    {
        blocks[i].start = current_index;
        blocks[i].end = current_index + elements_per_block - 1;

        // 如果还有剩余元素，将其分配给当前块
        if (remainder > 0)
        {
            blocks[i].end++;
            remainder--;
        }

        // 更新当前索引
        current_index = blocks[i].end + 1;
    }
}

// 检查分块结果的辅助函数
void check_blocks(int data[], int num_elements, Block blocks[], int num_blocks)
{
    for (int i = 0; i < num_blocks; i++)
    {
        printf("Block %d: Start=%d, End=%d\n", i, blocks[i].start, blocks[i].end);
    }
}

int main()
{
    // 创建数据集
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num_elements = sizeof(data) / sizeof(data[0]);

    // 指定要分成的块数
    int num_blocks = 3;

    // 创建块数组
    Block blocks[num_blocks];

    // 调用分块函数
    split_data(data, num_elements, num_blocks, blocks);

    // 检查分块结果
    check_blocks(data, num_elements, blocks, num_blocks);

    return 0;
} /**
  *  数组划分：将数组划分为若干块，每块的大小为N
     预处理：计算每个块的初始和，并初始化懒惰数组以处理延迟更新。
     范围更新：分块更新，每次更新时只更新涉及到的块。
     范围查询：分块查询，每次查询时只查询涉及到的块。
  */