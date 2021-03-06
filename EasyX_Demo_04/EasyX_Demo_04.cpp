#include <graphics.h>
#include <conio.h>

int main()
{
	initgraph(640, 480);

	float H = 190; // 色相
	float S = 1;  // 饱和度
	float L = 0.7f; // 亮度
	for (int y = 0; y < 480; y++)
	{
		L += 0.0005f;
		setlinecolor(HSLtoRGB(H, S, L));
		line(0, y, 639, y);
	}
	// 画彩虹(通过色相逐渐增加)
	H = 0;
	S = 1;
	L = 0.5f;
	setlinestyle(PS_SOLID, 2);		// 设置线宽为 2
	for (int r = 400; r > 344; r--)
	{
		H += 5;
		setlinecolor(HSLtoRGB(H, S, L));
		circle(500, 480, r);
	}

	// 按任意键退出
	_getch();
	closegraph();
}