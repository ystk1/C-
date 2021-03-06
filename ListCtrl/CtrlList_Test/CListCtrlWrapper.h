#pragma once
#include <afxcmn.h>

// ListCtrl 列構成
enum TE_COL_LIST : int {
	EN_COL_AD = 0,	 // ｱﾄﾞﾚｽ
	EN_COL_ST_AD,	 // 開始ｱﾄﾞﾚｽ
	EN_COL_DECI,	 // 10進数
	EN_COL_HEX,		 // 16進数
	EN_COL_VARNAME,	 // 変数名
	EN_COL_REMARK,	 // 備考
	EN_COL_NUM
};

// ListCtrl初期化 No
enum TE_LTTYPE : int {
	EN_LTTYPE_MAIN_TBL = 0,
	EN_LTTYPE_SUB_TBK,
	EN_LTTYPE_NUM
};

//class CListCtrlWrapper {
class CListCtrlWrapper : public CListCtrl {

public:
	CListCtrlWrapper();
	~CListCtrlWrapper();

private:
	const CListCtrlWrapper& operator=(const CListCtrlWrapper& obj);
	CListCtrlWrapper(const CListCtrlWrapper& obj);

private:
	int iCurRow = 0;  // ｶﾚﾝﾄ行
	int iCurCol = 0;  // ｶﾚﾝﾄ列

	int iTotalColNum = 0;  // 全列数
	int iTotalRowNum = 0;  // 全行数

	TE_LTTYPE enCurLtType = EN_LTTYPE_MAIN_TBL;	 // 自身のListControlﾀｲﾌﾟ

public:
	//void Init_GridTable_ListCtrl();	 // ListCtrl初期化
	void Init_GridTable_ListCtrl(TE_LTTYPE en);			 // ListCtrl初期化
	void AllSelect_GridTable();							 // グリッドTableの
	void SetColWidth(int iIdx, int iNewVal);			 // 列
	void SetText(char* cdat);							 // ｶﾚﾝﾄ行列番地に
	void SetRows(int iNewVal);							 // 縦のｾﾙ数を設定
	void SetCols(int iNewVal);							 // 横のｾﾙ数を設定
	void SetRow(int iNewVal);							 // ｶﾚﾝﾄ行を設定
	void SetCol(int iNewVal);							 // ｶﾚ
	void GetRow();										 // 行番号を取得
	void GetCol();										 // 列番号取得
	void SetFixedRows(int iNewVal);						 //
	void SetTextMatrix(int iRow, int iCol, char* cdat);	 // 指定行列番地に文字列を追加
};