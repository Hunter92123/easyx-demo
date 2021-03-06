// 该程序示范了常见的鼠标操作，程序执行后会在鼠标的移动轨迹上画红点，按左键画小方块，按 Ctrl + 左键画大方块，按右键退出程序。
#include <graphics.h>
#include <conio.h>

int main()
{
	// 初始化图形窗口
	initgraph(640, 480);

	MOUSEMSG m; // 定义鼠标消息
	while (true)
	{
		m = GetMouseMsg();

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			// 鼠标移动的时候画红色的小点点
			putpixel(m.x, m.y, RED);
			break;
		case WM_LBUTTONDOWN:
			// 同时按下Ctrl键
			if (m.mkCtrl)
			{
				// 画一个大矩形
				rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
			}
			else {
				// 画一个小矩形
				rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
			}
			break;
		case WM_RBUTTONUP:
			// 鼠标右键弹起推出程序
			return 0;
			break;
		default:
			break;
		}
	}
	// 关闭图形窗口
	closegraph();
}