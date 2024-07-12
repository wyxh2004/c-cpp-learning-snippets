#include <stdio.h>
#include <GLFW/glfw3.h>
#include <OpenGL/glut.h>

/**
 * 通用绘图接口
 * @param self: pointer to the painter object 指向绘图实例的指针
 * @param pos: point to draw 绘制的点的位置指针
 * @param color: color to draw 绘制的点的颜色指针
 */
typedef int (*painter_draw_point_fn_t)(void *self, struct point pos, int color);

struct painter_i
{
    painter_draw_point_fn_t draw_point;
};

struct point
{
    unsigned int x;
    unsigned int y;
};

void draw_point(void *self, struct point pos, int color)
{
    // 假设 self 是一个指向绘图实例的指针
    // pos 是表示要绘制的点的位置的结构体实例
    // color 是表示绘制的颜色的整数

    // 获取当前绘图上下文
    if (glfwGetCurrentContext() == NULL)
    {
        printf("No valid context\n");
        return;
    }

    // 设置颜色
    glColor3ub(color, color, color);

    // 绘制点
    glBegin(GL_POINTS);
    glVertex2f(pos.x, pos.y);
    glEnd();

    // 交换缓冲区
    glfwSwapBuffers();
    glfwPollEvents();
}
int draw_rect(struct painter_i **painter, struct point p1, struct point p2, int color)
{
    struct point c;

    // 计算矩形的中心点
    c.x = (p1.x + p2.x) / 2;
    c.y = (p1.y + p2.y) / 2;

    // 获取到下一个矩形边的点到 c 里面
    while (/* 条件为真 */)
    {
        // 假设 draw_point 函数已经实现了绘制点的功能
        (*painter)->draw_point(painter, c, color);

        // 更新 c 的值，使其更接近矩形的对角线上的点
        c.x += (p2.x - p1.x) / 2;
        c.y += (p2.y - p1.y) / 2;
    }

    // ...

    return 0;
}