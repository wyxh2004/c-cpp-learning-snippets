#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int block_size, num_block; // 块的大小, 块的数量
vector<string> block;

void initialize(const string s)
{
    int size = s.size();
    block_size = sqrt(size);
    num_block = size / block_size + size % block_size;
    for (int i = 0; i < size; i++)
        block[i / block_size].push_back(s[i]);
}

void insert(char ch, int index)
{
    int block_index = index / block_size;
    int positoin = index % block_size;
    if (index >= block.size())
    {
        if (block.empty())
            block.push_back(string(1, ch));
        block.back().push_back(ch);
    }
    else
    {
        block[block_index].insert(block[block_index].begin() + positoin, ch);
        // 在一个块中插入字符后，可能会导致该块的大小超过预设的 BLOCK_SIZE。为了保持每个块的大小在合理范围内，需要将多余的字符移动到相邻的块中。
        for (int i = block_index; i < block.size(); i++)
        {
            if (block[i].size() > block_size) // 块的大小超过预设的 BLOCK_SIZE
            {
                if (i == block.size() - 1) // 最后一个块
                {
                    block.push_back(string(1, block[i].back()));
                }
                else
                {
                    block[i + 1].push_back(block[i].back());
                    block[i].resize(block_size);
                }
            }
        }
    }
}

char query(int index)
{
    int block_index = index / block_size;
    int position = index % block_size;
    return block[block_index][position];
}

int main()
{
    string str; // 初始字符串
    cin >> str;
    int n;
    cin >> n; // 操作的数量
    initialize(str);
    vector<char> answers;

    while (n--)
    {
        char opt;    // Query or Insert
        char letter; // 插入的字符
        int query_num, insert_num;
        cin >> opt;

        if (opt == 'Q') // Query
        {
            cin >> query_num;
            query(query_num);
        }
        else if (opt == 'I')
        {
            cin >> letter >> insert_num;
            insert(letter, insert_num);
        }
    }

    for (vector<char>::iterator it = answers.begin(); it != answers.end(); it++)
        answers.push_back(*it);
    for (int i = 0; i < answers.size(); i++)
        cout << answers[i] << endl;

    return 0;
}
