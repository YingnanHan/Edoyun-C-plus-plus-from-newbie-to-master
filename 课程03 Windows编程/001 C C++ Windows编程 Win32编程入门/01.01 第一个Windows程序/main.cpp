// dos main
//
// 目的：窗口程序
// 1. 掌握C++面向对象思想
// 2. 理解消息机制
// 3. 多态性
#include<windows.h>
#include<stdio.h>

LPCSTR clsName = "My";
LPCSTR msgName = "Welcome";

// a 设计一个窗口类 b 注册窗口类 c 创建窗口 d 显示以及更新窗口 e 消息循环

LRESULT CALLBACK MyWinProc(
	HWND hwnd,        // handle to window
	UINT uMsg,        // message identifier
	WPARAM wParam,    // first message parameter word
	LPARAM lParam);    // second message parameter long

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd
) 
{
// 	UINT        style;
// 	WNDPROC     lpfnWndProc;
// 	int         cbClsExtra;
// 	int         cbWndExtra;
// 	HINSTANCE   hInstance;
// 	HICON       hIcon;
// 	HCURSOR     hCursor;
// 	HBRUSH      hbrBackground;
// 	LPCWSTR     lpszMenuName;
// 	LPCWSTR     lpszClassName;
 
// a.设计一个窗口类
	//1.定义和配置窗口对象
	WNDCLASS wndclass;
	wndclass.cbClsExtra = NULL;
	wndclass.cbWndExtra = NULL;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 设置背景色
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance = hInstance;
	//2.定义交互响应
	wndclass.lpfnWndProc = MyWinProc; // 回调函数
	//3.定义窗口代号
	wndclass.lpszClassName = clsName;
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
// b.注册窗口类
	RegisterClass(&wndclass);
// c.创建窗口
	HWND hwnd;
	hwnd = CreateWindow(clsName, msgName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
// d.显示和刷新窗口
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
// e.消息循环 GetMessage只有在接收到WM_QUIT才会返回0
//            TranslateMessage 翻译消息 将消息合并送到消息队列之中 
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg); // 产生消息并将消息放到消息队列中
		DispatchMessage(&msg); // 分派消息
	}
	return msg.wParam;
} // VA

LRESULT CALLBACK MyWinProc(
	HWND hwnd,        // handle to window
	UINT uMsg,        // message identifier
	WPARAM wParam,    // first message parameter word
	LPARAM lParam)
{
	//uMsg 消息类型 -> 
	int ret;
	HDC hdc;
	switch (uMsg)
	{
	case WM_CHAR: // 字符消息
		char szChar[20];
		sprintf_s(szChar, "您刚才按下了: %c", wParam);
		MessageBox(hwnd, szChar, "char", NULL);
		break;
	case WM_LBUTTONDOWN: // 左键按下
		MessageBox(hwnd, "监测到鼠标左键按下", "msg", NULL);
		break;
	case WM_PAINT: // 重绘消息
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 0, 0, "www.google.com", strlen("www.google.com"));
		EndPaint(hwnd, &ps);
		MessageBox(hwnd, "重绘", "msg", NULL);
		break;
	case WM_CLOSE: // 关闭消息
		ret = MessageBox(hwnd, "是否真的结束?","msg" , MB_YESNO);
		if (ret == IDYES)
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY: //毁灭消息
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam); // 返回默认Windows消息
	};
	return 0; // 这个值是为了测试而随便返回的
}