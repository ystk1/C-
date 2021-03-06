#include "pch.h"
#include "CListCtrlWrapper.h"

CListCtrlWrapper::CListCtrlWrapper()
	 : iCurRow(0),
	 iCurCol(0),
	 iTotalRowNum(0),
	 iTotalColNum(0)
{
	enCurLtType = TE_LTTYPE::EN_LTTYPE_MAIN_TBL;
}

CListCtrlWrapper::~CListCtrlWrapper() {
}

// グリッドTableの行を全て選択
void CListCtrlWrapper::AllSelect_GridTable() {
	int iTotalNumBuf;

	switch (enCurLtType) {
	case TE_LTTYPE::EN_LTTYPE_MAIN_TBL:
		iTotalNumBuf = (int)TE_COL_LIST::EN_COL_NUM;
		break;
	case TE_LTTYPE::EN_LTTYPE_SUB_TBK:
		break;
	default:
		iTotalNumBuf = 0;
		break;
	}

	for (int Item = 0; Item < iTotalNumBuf; Item++) {
		// フォーカス＆選択状態にしたいアイテムのインデックス
		this->SetItemState(Item, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	}
}

// ListCtrl初期化
//void CListCtrlWrapper::Init_GridTable_ListCtrl()
void CListCtrlWrapper::Init_GridTable_ListCtrl(TE_LTTYPE en)
{
	switch (en) {
	case TE_LTTYPE::EN_LTTYPE_MAIN_TBL:
		//! ListContrl 初期化
		this->InsertColumn((int)TE_COL_LIST::EN_COL_AD, _T("ｱﾄﾞﾚｽ"), LVCFMT_LEFT, 50);
		this->InsertColumn((int)TE_COL_LIST::EN_COL_ST_AD, _T("開始ｱﾄﾞﾚｽ"), LVCFMT_CENTER, 80);
		this->InsertColumn((int)TE_COL_LIST::EN_COL_DECI, _T("10進数"), LVCFMT_RIGHT, 50);
		this->InsertColumn((int)TE_COL_LIST::EN_COL_HEX, _T("HEX"), LVCFMT_RIGHT, 50);
		this->InsertColumn((int)TE_COL_LIST::EN_COL_VARNAME, _T("変数名"), LVCFMT_RIGHT, 100);
		this->InsertColumn((int)TE_COL_LIST::EN_COL_REMARK, _T("備考"), LVCFMT_RIGHT, 100);

		for (int Item = 0; Item < (int)TE_COL_LIST::EN_COL_NUM; Item++) {
			this->InsertItem(Item, _T("0"));
			this->SetItemText(Item, 1, _T("1"));
			this->SetItemText(Item, 2, _T("2"));
			this->SetItemText(Item, 3, _T("3"));
			this->SetItemText(Item, 5, _T("3"));
		}

		break;
	case TE_LTTYPE::EN_LTTYPE_SUB_TBK:
		break;
	}

	// 拡張スタイル設定
	unsigned long ulStyle = this->GetExtendedStyle();
	// 1行選択
	ulStyle |= LVS_EX_FULLROWSELECT;
	// グリッド線表示
	ulStyle |= LVS_EX_GRIDLINES;

	ulStyle |= LVS_EX_HEADERDRAGDROP;
	ulStyle |= LVS_EX_INFOTIP;

	this->SetExtendedStyle(ulStyle);
}

// ｶﾚﾝﾄ行を設定
void CListCtrlWrapper::SetRow(int iNewVal) {
	iCurRow = iNewVal;
}
// ｶﾚﾝﾄ列を設定
void CListCtrlWrapper::SetCol(int iNewVal) {
	iCurCol = iNewVal;
}

// 列の幅
void CListCtrlWrapper::SetColWidth(int iIdx, int iNewVal) {
}

// ｶﾚﾝﾄ行列番地に文字列ｾｯﾄ
void CListCtrlWrapper::SetText(char* cdat) {
}

// 縦のｾﾙ数を設定
void CListCtrlWrapper::SetRows(int iNewVal) {
}

// 横のｾﾙ数を設定
void CListCtrlWrapper::SetCols(int iNewVal) {
}
// 行番号を取得
void CListCtrlWrapper::GetRow() {
}

// 列番号取得
void CListCtrlWrapper::GetCol() {}

//
void CListCtrlWrapper::SetFixedRows(int iNewVal) {
}

// 指定行列番地に文字列を追加
void CListCtrlWrapper::SetTextMatrix(int iRow, int iCol, char* cdat) {
}