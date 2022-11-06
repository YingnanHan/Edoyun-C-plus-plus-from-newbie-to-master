﻿#pragma warning(disable:4996)

// ClipBoardDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "ClipBoard.h"
#include "ClipBoardDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClipBoardDlg 对话框



CClipBoardDlg::CClipBoardDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLIPBOARD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClipBoardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CClipBoardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_RECV_BTN2, &CClipBoardDlg::OnBnClickedRecvBtn2)
	ON_BN_CLICKED(IDC_SEND_BTN, &CClipBoardDlg::OnBnClickedSendBtn)
	ON_BN_CLICKED(IDC_RECV_BTN, &CClipBoardDlg::OnBnClickedRecvBtn)
END_MESSAGE_MAP()


// CClipBoardDlg 消息处理程序

BOOL CClipBoardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CClipBoardDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CClipBoardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CClipBoardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CClipBoardDlg::OnBnClickedSendBtn()
{
	#pragma warning(disable:4996)
	// 1.如果成功打开剪切板返回True
	if (OpenClipboard())
	{
		// 2. 成功打开剪切板后，清空剪切板
		EmptyClipboard();
		char* szSendBuf;
		// 3. 获取编辑框的内容
		CStringA strSend;
		GetDlgItemTextA(IDC_EDIT_SEND, strSend);
		// 4. 分配一个内存对象,内存对象的句柄就是hclip
		HANDLE hClip = GlobalAlloc(GMEM_MOVEABLE, strSend.GetLength() + 1);

		// 5. 将剪切板加锁
		szSendBuf = (char*)GlobalLock(hClip);// 为公共内存加锁 锁加在句柄上
		strcpy(szSendBuf, strSend);
		GlobalUnlock(hClip); // 解锁句柄

		// 6. 将数据放入剪切板
		SetClipboardData(CF_TEXT, hClip);

		// 7. 关闭剪切板
		CloseClipboard();
	}
}


void CClipBoardDlg::OnBnClickedRecvBtn()
{
	// 1.如果成功打开剪切板返回True
	if (OpenClipboard())
	{
		// 2. 判断剪切板是否可用
		if (IsClipboardFormatAvailable(CF_TEXT))
		{
			char* szRecvBuf;
			// 3. 向剪切板要数据
			HANDLE hClip = GetClipboardData(CF_TEXT);
			szRecvBuf = (char*)GlobalLock(hClip);
			SetDlgItemTextA(IDC_EDIT_RECV, szRecvBuf);
			GlobalUnlock(hClip); // 关闭句柄
		}
		// 4. 关闭剪切板
		CloseClipboard();
	}
}


// 这个项目可以将发送端与接收端互相分离实现一个单工通信的小程序组合