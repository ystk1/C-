#pragma once
#include <afxcmn.h>

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

class CTest : public CListCtrl {

	private:
	int iCurRow = 0;  // ｶﾚﾝﾄ行
	int iCurCol = 0;  // ｶﾚﾝﾄ列

	int iTotalColNum = 0;  // 全列数
	int iTotalRowNum = 0;  // 全行数

	TE_LTTYPE enCurLtType =EN_LTTYPE_MAIN_TBL;	// 自身のListControlﾀｲﾌﾟ

public:
	void Init_GridTable_ListCtrl();	 // ListCtrl初期化
	
};
