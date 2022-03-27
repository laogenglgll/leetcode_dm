//vsc 找不到库。。。


#include <easyx.h> //图形库
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

//界面宽高
#define windowWidth  640
#define windowHeight  480

//数组
char game[11];


// 函数声明

void createWindows(int high, int width);
void createOptions(int high, int width);
void createText(int left, int top,int right,int bottom,char text[]);
void startEvent();
void gameWindow(); //游戏界面
int gameButtonEvent(); //鼠标点击九个框中的一个
void pawnDraw(int x,int one); //画棋子
int diplomaticVictorySpeedFactor(); //判断胜利
void Victory(int victoryPeople);
int computerPlayer();
void computerPawnDraw(int x);
void createOPtions_over(int high, int width); // 一局结束后选项界面
int buttonEvent(); //重现开始和退出
void gameTime(); // 游戏过程中，来回调用函数的调用过程



int main() {
	createWindows(640, 480);
	return 0;
}


//创建选项窗口

void createWindows(int high,int width) {
	initgraph(high, width, EW_SHOWCONSOLE); //创建窗口
	setbkcolor(WHITE);
	cleardevice(); //覆盖颜色
	createOptions(high, width);
	startEvent();
	closegraph();
	return;
}


//创建框
void createOptions(int high, int width) {
	BeginBatchDraw();

	//图片
	IMAGE img;
	loadimage(NULL, _T("D:\\cxy\\vs\\githubYouXI\\sy\\bk.jpg"), 640, 480);

	//创建开始选项框
	setfillcolor(RGB(180,238,180));
	fillrectangle(150, 40, 240, 90);
	fillrectangle(390, 40, 480, 90);



	//文字
	char text_1[] = "开始";
	char text_2[] = "退出";
	createText(150, 40, 240, 90,text_1);
	createText(390, 40, 480, 90, text_2);

	EndBatchDraw();
}

//框内写文字
void createText(int left, int top, int right, int bottom, char text[]) {
	settextstyle(40, 0, "楷体");
	setbkmode(TRANSPARENT);
	settextcolor(RED);

	int textWidth = (right - left) / 2 - textwidth(text) / 2;
	int textHeight = (bottom - top) / 2 - textheight(text) / 2;

	outtextxy(left + textWidth, top + textHeight, text);

}

//开始按钮鼠标右键点击事件 

void startEvent() {
	while (1) {
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				if (msg.x >= 150 && msg.x <= 240 && msg.y >= 40 && msg.y <= 90) {
					gameWindow();
					gameTime();
				}
				else if (msg.x >= 390 && msg.x <= 480 && msg.y >= 40 && msg.y <= 90) {
					return;
				}
			}
		}
	}
}

//绘制游戏界面

void gameWindow() {
	cleardevice();
	BeginBatchDraw();
	setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
	setlinecolor(RED);
	//横线
	line(0, 160, 640, 160);
	line(0, 320, 640, 320);
	//竖线
	line(213, 0, 213, 480);
	line(426, 0, 426, 480);
	EndBatchDraw();
	return;
}

//游戏界面下棋位置的点击
int gameButtonEvent() {
	while (1) {
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				if(msg.x >= 0 && msg.x < 213) {
					if (msg.y >= 0 && msg.y < 160) {
						if (game[1] != 'o') {
							pawnDraw(1, 1);
							game[1] = 'x';
							if (diplomaticVictorySpeedFactor() == 1) {
								return 1;
							}
						}
						else continue;
					}
					else if (msg.y >= 160 && msg.y < 320) {
						if (game[4] != 'o') {
							pawnDraw(4, 1);
							game[4] = 'x';
							if (diplomaticVictorySpeedFactor() == 1) {
								return 1;
							}
						}
						else continue;
					}
					else {
						if (game[7] != 'o') {
							pawnDraw(7, 1);
							game[7] = 'x';
							if (diplomaticVictorySpeedFactor() == 1) {
								return 1;
							}
						}
						else continue;
					}
				}
				else if (msg.x >= 213 && msg.x < 416) {
					if (msg.y >= 0 && msg.y < 160) {
						if (game[2] != 'o') {
							pawnDraw(2, 1);
							game[2] = 'x';
							if (diplomaticVictorySpeedFactor() == 1) {
								return 1;
							}
						}
						else continue;
					}
					else if (msg.y >= 160 && msg.y < 320) {
						if (game[5] != 'o') {
							pawnDraw(5, 1);
							game[5] = 'x';
							if (diplomaticVictorySpeedFactor() == 1) {
								return 1;
							}
						}
						else continue;
					}
					else {
						if (game[8] != 'o') {
							pawnDraw(8, 1);
							game[8] = 'x';
							if (diplomaticVictorySpeedFactor() == 1) {
								return 1;
							}
						}
						else continue;
					}
				}
				else {
					if (msg.y >= 0 && msg.y < 160) {
						if (game[3] != '0') {
							pawnDraw(3, 1);
							game[3] = 'x';
							if (diplomaticVictorySpeedFactor() == 1) {
								return 1;
							}
						}
						else continue;
					}
					else if (msg.y >= 160 && msg.y < 320) {
						if (game[6] != 'o') {
							pawnDraw(6, 1);
							game[6] = 'x';
							if (diplomaticVictorySpeedFactor() == 1) {
								return 1;
							}
						}
						else continue;
					}
					else {
						if (game[9] != '0') {
							pawnDraw(9, 1);
							game[9] = 'x';
							if (diplomaticVictorySpeedFactor() == 1) {
								return 1;
							}

						}
						else continue;
					}
				}
				int i = 0;
				// 防止满了之后进出computerPalyer()函数;
				for (i = 1; i < 10; i++) {
					if (game[i] != 'x' && game[i] != 'o') {
						break;
					}
				}
				if (i == 10) return 3;

				computerPawnDraw(computerPlayer());
				if (diplomaticVictorySpeedFactor() == 2) return 2;
			}
			
		}
	}
	return -1;
}

//棋子绘制

void pawnDraw(int x,int one) {
	BeginBatchDraw();
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID || PS_ENDCAP_SQUARE,5);

	int  left_1, right_1, top_1, bottom_1;
	int  left, right, top, bottom;
	left_1 = right_1 = top_1 = bottom_1 = left =  right = top  = bottom = 0;
	if (x == 1 || x == 4 || x == 7) {
		left_1 = left = 0 + 20;
		right = right_1 = windowWidth / 3 - 20;
		if (x == 1) {
			top = bottom_1 = 0 + 20;
			top_1 = bottom = windowHeight / 3 -20;
		}
		else if (x == 4) {
			top = bottom_1 = windowHeight / 3 + 20;
			top_1 = bottom = (windowHeight / 3) * 2 - 20;
		}
		else {
			top = bottom_1 = (windowHeight / 3) * 2 + 20;
			top_1 = bottom = windowHeight - 20;
		}
	}
	if (x == 2 || x == 5 || x == 8) {
		left_1 = left = windowWidth / 3 + 20;
		right = right_1 = windowWidth / 3 * 2 - 20;
		if (x == 2) {
			top = bottom_1 = 0 + 20;
			top_1 = bottom = windowHeight / 3 - 20;
		}
		else if (x == 5) {
			top = bottom_1 = windowHeight / 3 + 20;
			top_1 = bottom = (windowHeight / 3) * 2 - 20;
		}
		else {
			top = bottom_1 = (windowHeight / 3) * 2 + 20;
			top_1 = bottom = windowHeight - 20;
		}
	}
	if (x == 3 || x == 6 || x == 9) {
		left_1 = left = windowWidth / 3 * 2 + 20;
		right = right_1 = windowWidth - 20;
		if (x == 3) {
			top = bottom_1 = 0 + 20;
			top_1 = bottom = windowHeight / 3 - 20;
		}
		else if (x == 6) {
			top = bottom_1 = windowHeight / 3 + 20;
			top_1 = bottom = (windowHeight / 3) * 2 - 20;
		}
		else {
			top = bottom_1 = (windowHeight / 3) * 2 + 20;
			top_1 = bottom = windowHeight - 20;
		}
	}
	line(left, top, right, bottom);
	line(left_1,top_1,right_1 ,bottom_1);

	EndBatchDraw();
}

//胜利判断
int diplomaticVictorySpeedFactor() {
	if (game[1] == 'x' && game[2] == 'x' && game[3] == 'x') {
		return 1;
	}
	else if (game[1] == 'x' && game[5] == 'x' && game[9] == 'x') {
		return 1;
	}
	else if (game[1] == 'x' && game[4] == 'x' &&game[7] == 'x') {
		return 1;
	}
	else if (game[2] == 'x' && game[5] == 'x' && game[8] == 'x') {
		return 1;
	}
	else if (game[4] == 'x' && game[5] == 'x' && game[6] == 'x') {
		return 1;
	}
	else if (game[7] == 'x' && game[8] == 'x' && game[9] == 'x') {
		return 1;
	}
	else if (game[3] == 'x' && game[5] == 'x' && game[7] == 'x') {
		return 1;
	}
	else if (game[3] == 'x' && game[6] == 'x' && game[9] == 'x') {
		return 1;
	} 
	//2号玩家胜利
	if (game[1] == 'o' && game[2] == 'o' && game[3] == 'o') {
		return 2;
	}
	else if (game[1] == 'o' && game[5] == 'o' && game[9] == 'o') {
		return 2;
	}
	else if (game[1] == 'o' && game[4] == 'o' && game[7] == 'o') {
		return 2;
	}
	else if (game[2] == 'o' && game[4] == 'o' && game[8] == 'o') {
		return 2;
	}
	else if (game[4] == 'o' && game[5] == 'o' && game[6] == 'o') {
		return 2;
	}
	else if (game[7] == 'o' && game[8] == 'o' && game[9] == 'o') {
		return 2;
	}
	else if (game[3] == 'o' && game[5] == 'o' && game[7] == 'o') {
		return 2;
	}
	else if (game[3] == 'o' && game[6] == 'o' && game[9] == 'o') {
		return 2;
	}
	else return 0;
}


//绘制胜利界面
void Victory(int victoryPeople) {
	BeginBatchDraw();
	setbkcolor(WHITE);
	settextcolor(RED);
	settextstyle(100, 0, "楷体");

	cleardevice();

	//图片
	IMAGE img;
	loadimage(NULL, _T("D:\\cxy\\vs\\githubYouXI\\sy\\bk2.png"), 640, 480);

	char str[] = "恭喜1号玩家！";
	if (victoryPeople == 1) {
		str[4] = '1';
	}
	else {
		str[4] = '2';
	}
	char str_[] = "你胜利了。";

	int width1 = windowWidth / 2 - textwidth(str) / 2;
	int width2 = windowWidth / 2 - textwidth(str_) / 2;
	int height1 = windowHeight / 2 - textheight(str) / 2 - 50;
	int height2 =  windowHeight / 2 - textheight(str_) / 2 + 50;

	outtextxy(width1, height1, str);
	outtextxy(width2, height2, str_);
	
	EndBatchDraw();
}

//电脑下棋

int computerPlayer() {
	int x = 0;
	int i = 0;
	for (int i = 1; i < 10; i++) {
		if (game[i] != 'x' && game[i] != 'o') {
			break;
		} 
	}
	if (i == 10)
	{
		return -1;
	}

	while (1) {
		x = rand() % 10;
		if (x == 0) {
			continue;
		}
		if (game[x] != 'x' && game[x] != 'o') {
			game[x] = 'o';
			break;
		}
	}
	return x;
}


//电脑棋子绘制
void computerPawnDraw(int x) {
	if (x == -1) return ;

	BeginBatchDraw();

	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 5);
	
	int widht = 0;
	int height = 0;
	if (x == 1 || x == 2 || x == 3) {
		height = windowHeight / 3 / 2;
	}
	else if (x == 4 || x == 5 || x == 6) {
		height = windowHeight / 3 * 2 - windowHeight / 3 / 2;
	}
	else {
		height = windowHeight / 3 * 3 - windowHeight / 3 / 2;
	}
	x = x % 3;
	if (x == 1) {
		widht = windowWidth / 3 / 2;
	}
	else if (x == 2) {
		widht = windowWidth / 3 + windowWidth / 3 / 2;
	}
	else {
		widht = windowWidth / 3 * 2 + windowWidth / 3 / 2;
	}

	circle(widht, height, 20);
	EndBatchDraw();
}

//
void createOPtions_over(int high, int width) {
	BeginBatchDraw();
	//创建开始选项框
	cleardevice();


	//图片
	IMAGE img;
	loadimage(NULL, _T("D:\\cxy\\vs\\githubYouXI\\sy\\bk3.png"), 640, 480);


	setfillcolor(RGB(180, 238, 180));
	fillrectangle(100, 40, 300, 90);
	fillrectangle(390, 40, 480, 90);
	//文字
	char text_1[] = "重现开始";
	char text_2[] = "退出";
	createText(100, 40, 300, 90, text_1);
	createText(390, 40, 480, 90, text_2);

	EndBatchDraw();
}


//
int buttonEvent() {
	while (1) {
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				if (msg.x >= 100 && msg.x <= 300 && msg.y >= 40 && msg.y <= 90) {
					return 1;
				}
				else if (msg.x >= 390 && msg.x <= 480 && msg.y >= 30 && msg.y <= 90) {
					return 2;
				}
			}
		}
	}
	return -1;
}

//
int n = 0;
void gameTime() {
	n = gameButtonEvent();
	Sleep(1000);
	if (n == 1) {
		Victory(1);
		Sleep(1000);
		printf("yes");
	}
	else if (n == 2) {
		Victory(2);
		Sleep(1000);
	}
	if (n == -1) printf("nimeide");
	if (n == 3) {
		cleardevice();
		outtextxy(250, 280, "平局");
		Sleep(1000);
	}


	createOPtions_over(windowWidth, windowHeight);
	if (buttonEvent() == 1) {
		cleardevice();
		strcpy_s(game, "asdfghjkl");
		gameWindow();
		gameTime();
	}
	else {
		return;
	}
}


