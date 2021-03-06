
// CtrlList_TestDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "CtrlList_Test.h"
#include "CtrlList_TestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
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


// CCtrlListTestDlg ダイアログ



CCtrlListTestDlg::CCtrlListTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CTRLLIST_TEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCtrlListTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LT_1, m_ltTest);
}

BEGIN_MESSAGE_MAP(CCtrlListTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_RCLICK, IDC_LT_1, &CCtrlListTestDlg::OnNMRClickLt1)
	ON_COMMAND(ID_32773, &CCtrlListTestDlg::On32773)
END_MESSAGE_MAP()


// CCtrlListTestDlg メッセージ ハンドラー

BOOL CCtrlListTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
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

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	//Init_ListCtrl();	// ﾘｽﾄｺﾝﾄﾛｰﾙの初期化

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}
//
//void CCtrlListTestDlg::Init_ListCtrl(CListCtrl* plstCtrl)
//{
//	//! ListContrl 初期化
//	m_ltTest.InsertColumn(EN_COL_AD, _T("ｱﾄﾞﾚｽ"), LVCFMT_LEFT, 50);
//	m_ltTest.InsertColumn(EN_COL_ST_AD, _T("開始ｱﾄﾞﾚｽ"), LVCFMT_CENTER, 80);
//	m_ltTest.InsertColumn(EN_COL_DECI, _T("10進数"), LVCFMT_RIGHT, 50);
//	m_ltTest.InsertColumn(EN_COL_HEX, _T("HEX"), LVCFMT_RIGHT, 50);
//	m_ltTest.InsertColumn(EN_COL_VARNAME, _T("変数名"), LVCFMT_RIGHT, 100);
//	m_ltTest.InsertColumn(EN_COL_REMARK, _T("備考"), LVCFMT_RIGHT, 100);
//
//	for (int Item = 0; Item < EN_COL_NUM; Item++) {
//		m_ltTest.InsertItem(Item, _T("0"));
//		m_ltTest.SetItemText(Item, 1, _T("1"));
//		m_ltTest.SetItemText(Item, 2, _T("2"));
//		m_ltTest.SetItemText(Item, 3, _T("3"));
//		m_ltTest.SetItemText(Item, 5, _T("3"));
//	}
//
//	// 拡張スタイル設定
//	unsigned long ulStyle = m_ltTest.GetExtendedStyle();
//	// 1行選択
//	ulStyle |= LVS_EX_FULLROWSELECT;
//	// グリッド線表示
//	ulStyle |= LVS_EX_GRIDLINES;
//
//	ulStyle |= LVS_EX_HEADERDRAGDROP;
//	ulStyle |= LVS_EX_INFOTIP;
//
//	m_ltTest.SetExtendedStyle(ulStyle);
//}

/**
* 選択されたﾘｽﾄｺﾝﾄﾛｰﾙの行番号を返答
*
* @param[in] 
* @param[out] 
* @return -1 : 該当なし  0以上　選択している行番号
*/
int CCtrlListTestDlg::GetSelectedRowNo()
{
	// 選択された項目を最初から全て検索します。
	int nSelected = -1;
	do {
		nSelected = m_ltTest.GetNextItem(nSelected, LVNI_SELECTED);
	} while (nSelected != -1);

	return nSelected;
}

void CCtrlListTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CCtrlListTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CCtrlListTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCtrlListTestDlg::OnNMRClickLt1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	*pResult = 0;

	// 通知をLPNMITEMACTIVATE型にキャストする
	LPNMITEMACTIVATE pItem = (LPNMITEMACTIVATE)pNMHDR;

	// アイテム上以外での右クリック
	if (pItem->iItem == -1) {
		*pResult = 0;
		return;
	}

	// アイテム上で右クリックした場合は、メニューを表示する
	CMenu* popupMenuP = NULL;
	CMenu cMenu;
	CPoint posMouse;
	int err = 0;

	// メニューをロード
	if (!err)
		if (!cMenu.LoadMenu(IDR_MENU1))
			err = 1;
	// サブメニューを取得
	if (!err)
		if ((popupMenuP = cMenu.GetSubMenu(0)) == NULL)
			err = 1;
	// メニューをポップアップ
	if (!err) {
		GetCursorPos(&posMouse);
		if (popupMenuP->TrackPopupMenu(TPM_LEFTBUTTON, posMouse.x, posMouse.y, this))
			err = 1;
	}
	// メニューを削除
	cMenu.DestroyMenu();

	*pResult = 0;
}

/**
* 右クリック 全選択
*
* @param[in] 
* @param[out] 
* @return 
*/
void CCtrlListTestDlg::On32773()
{
	//// TODO: ここにコマンド ハンドラー コードを追加します。

	//for (int Item = 0; Item < EN_COL_NUM; Item++) {
	//	// フォーカス＆選択状態にしたいアイテムのインデックス
	//	m_ltTest.SetItemState(Item,	LVIS_FOCUSED | LVIS_SELECTED,LVIS_FOCUSED | LVIS_SELECTED);	
	//}
}
