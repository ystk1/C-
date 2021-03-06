
// CtrlList_TestDlg.h : ヘッダー ファイル
//

#pragma once



// CCtrlListTestDlg ダイアログ
class CCtrlListTestDlg : public CDialogEx
{
// コンストラクション
public:
	CCtrlListTestDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CTRLLIST_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
private:
	void Init_ListCtrl();	// ﾘｽﾄｺﾝﾄﾛｰﾙの初期化
	int GetSelectedRowNo();		// ﾘｽﾄｺﾝﾄﾛｰﾙ選択された行番号を返す
	
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ltTest;
	afx_msg void OnNMRClickLt1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void On32773();
};
