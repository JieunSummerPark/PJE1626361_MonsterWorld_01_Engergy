
// PJE1626361_MonsterWorld_01_EngergyDlg.h: 헤더 파일
//

#pragma once

#ifdef UNICODE
#pragma comment(linker, "/ENTRY:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/ENTRY:WinMainCRTStartup /subsystem:console")
#endif


// CPJE1626361MonsterWorld01EngergyDlg 대화 상자
class CPJE1626361MonsterWorld01EngergyDlg : public CDialogEx
{
// 생성입니다.
public:
	CPJE1626361MonsterWorld01EngergyDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PJE1626361_MONSTERWORLD_01_ENGERGY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
