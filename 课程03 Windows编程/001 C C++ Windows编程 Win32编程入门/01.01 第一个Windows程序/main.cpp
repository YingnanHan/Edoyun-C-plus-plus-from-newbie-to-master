// dos main
//
// Ŀ�ģ����ڳ���
// 1. ����C++�������˼��
// 2. �����Ϣ����
// 3. ��̬��
#include<windows.h>
#include<stdio.h>

LPCSTR clsName = "My";
LPCSTR msgName = "Welcome";

// a ���һ�������� b ע�ᴰ���� c �������� d ��ʾ�Լ����´��� e ��Ϣѭ��

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
 
// a.���һ��������
	//1.��������ô��ڶ���
	WNDCLASS wndclass;
	wndclass.cbClsExtra = NULL;
	wndclass.cbWndExtra = NULL;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ���ñ���ɫ
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance = hInstance;
	//2.���彻����Ӧ
	wndclass.lpfnWndProc = MyWinProc; // �ص�����
	//3.���崰�ڴ���
	wndclass.lpszClassName = clsName;
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
// b.ע�ᴰ����
	RegisterClass(&wndclass);
// c.��������
	HWND hwnd;
	hwnd = CreateWindow(clsName, msgName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
// d.��ʾ��ˢ�´���
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
// e.��Ϣѭ�� GetMessageֻ���ڽ��յ�WM_QUIT�Ż᷵��0
//            TranslateMessage ������Ϣ ����Ϣ�ϲ��͵���Ϣ����֮�� 
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg); // ������Ϣ������Ϣ�ŵ���Ϣ������
		DispatchMessage(&msg); // ������Ϣ
	}
	return msg.wParam;
} // VA

LRESULT CALLBACK MyWinProc(
	HWND hwnd,        // handle to window
	UINT uMsg,        // message identifier
	WPARAM wParam,    // first message parameter word
	LPARAM lParam)
{
	//uMsg ��Ϣ���� -> 
	int ret;
	HDC hdc;
	switch (uMsg)
	{
	case WM_CHAR: // �ַ���Ϣ
		char szChar[20];
		sprintf_s(szChar, "���ղŰ�����: %c", wParam);
		MessageBox(hwnd, szChar, "char", NULL);
		break;
	case WM_LBUTTONDOWN: // �������
		MessageBox(hwnd, "��⵽����������", "msg", NULL);
		break;
	case WM_PAINT: // �ػ���Ϣ
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 0, 0, "www.google.com", strlen("www.google.com"));
		EndPaint(hwnd, &ps);
		MessageBox(hwnd, "�ػ�", "msg", NULL);
		break;
	case WM_CLOSE: // �ر���Ϣ
		ret = MessageBox(hwnd, "�Ƿ���Ľ���?","msg" , MB_YESNO);
		if (ret == IDYES)
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY: //������Ϣ
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam); // ����Ĭ��Windows��Ϣ
	};
	return 0; // ���ֵ��Ϊ�˲��Զ���㷵�ص�
}