
// CtrlList_Test.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CCtrlListTestApp:
// このクラスの実装については、CtrlList_Test.cpp を参照してください
//

class CCtrlListTestApp : public CWinApp
{
public:
	CCtrlListTestApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CCtrlListTestApp theApp;
