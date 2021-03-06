////////////////////////////////////////////
// 程序名称：打字母游戏
// 编译环境：Visual C++ 6.0 / 2010，EasyX_20200806
// 程序编写：yangw80 <yw80@qq.com>
// 发布日期：2010-8-26
//
#include "pch.h"
#include <graphics.h>
#include <conio.h>
#include <time.h>

// 欢迎界面
void welcome()
{
	// 输出屏幕提示
	cleardevice();
	settextcolor(YELLOW);
	settextstyle(64, 0, _T("黑体"));
	outtextxy(160, 50, _T("打字母游戏"));
	settextcolor(WHITE);
	settextstyle(16, 0, _T("宋体"));
	outtextxy(100, 200, _T("就是很传统的那个掉字母然后按相应键就消失的游戏"));
	outtextxy(100, 240, _T("只是做了一个简单的实现"));
	outtextxy(100, 280, _T("功能并不很完善，比如生命数、分数等都没有写"));
	outtextxy(100, 320, _T("感兴趣的自己加进去吧"));

	// 实现闪烁的“按任意键继续”
	int c = 255;
	while (!_kbhit())
	{
		settextcolor(RGB(c, 0, 0));
		outtextxy(280, 400, _T("按任意键继续"));
		c -= 8;
		if (c < 50) c = 255;
		Sleep(30);
	}
	_getch();
	cleardevice();
}

// 退出界面
void goodbye()
{
	cleardevice();
	settextcolor(YELLOW);
	settextstyle(48, 0, _T("黑体"));
	outtextxy(104, 180, _T("多写程序  不老青春"));
	_getch();
}

// 主函数
int main()
{
	initgraph(640, 480);				// 初始化屏幕为 640x480

	welcome();							// 显示欢迎界面

	srand((unsigned)time(NULL));		// 设置随机种子
	settextstyle(20, 0, _T("Arial"));	// 设置字母的字体和大小
	setfillcolor(BLACK);				// 设置清除字母的填充区域颜色

	char target;						// 目标字母
	char key;							// 用户的按键
	int x, y;							// 字母的位置

	// 主循环
	while (true)
	{
		target = 65 + rand() % 26;		// 产生任意大写字母
		x = rand() % 620;				// 产生任意下落位置
		for (y = 0; y < 460; y++)
		{
			settextcolor(WHITE);		// 设置字母的颜色
			outtextxy(x, y, target);	// 显示字母

			if (_kbhit())
			{
				key = _getch();			// 获取用户按键

				if ((key == target) || (key == target + 32))
				{
					// 按键正确，“击落”字母（画黑色方块擦除）
					solidrectangle(x, y, x + 20, y + 20);
					break;				// 跳出循环，进行下一个字母
				}
				else if (key == 27)
				{
					goto EXIT;			// 如果按 ESC，退出游戏主循环
				}
			}

			// 延时，并清除字母
			Sleep(10);
			solidrectangle(x, y, x + 20, y + 20);
		}
	}

EXIT:
	// 退出部分
	goodbye();

	// 关闭图形界面
	closegraph();
	return 0;
}