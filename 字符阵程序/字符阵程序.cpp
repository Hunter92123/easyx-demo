// 程序名称：字符阵
// 编译环境：Visual C++ 6.0 / 2010，EasyX_20200806
// 发布日期：2009-2-22
//
#include "pch.h"
#include <graphics.h>
#include <time.h>
#include <conio.h>

int main()
{
	// 设置随机函数种子
	srand((unsigned)time(NULL));

	// 初始化图形模式
	initgraph(640, 480);

	int x, y;
	TCHAR c;

	settextstyle(16, 8, _T("Courier"));	// 设置文字样式
	settextcolor(GREEN);				// 设置文字颜色
	setlinecolor(BLACK);				// 设置画线颜色

	while (!_kbhit())
	{
		for (int i = 0; i < 479; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				x = (rand() % 80) * 8;
				y = (rand() % 20) * 24;
				c = (rand() % 26) + 65;
				outtextxy(x, y, c);
			}

			line(0, i, 639, i);

			Sleep(10);
			if (_kbhit()) break;
		}
	}

	// 关闭图形模式
	closegraph();
	return 0;
}