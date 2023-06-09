//
// MFCStarterKitDlg.cpp�: fichier d'impl�mentation
//

#include "stdafx.h"
#include "MFCStarterKit.h"
#include "MFCStarterKitDlg.h"
#include "afxdialogex.h"
#include "pmXTrace.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// bo�te de dialogue CAboutDlg utilis�e pour la bo�te de dialogue '� propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Donn�es de bo�te de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Impl�mentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	TRACE0("About DialogBox Open");
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// bo�te de dialogue de CMFCStarterKitDlg

CMFCStarterKitDlg::CMFCStarterKitDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSTARTERKIT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCStarterKitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCStarterKitDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCStarterKitDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCStarterKitDlg::OnBnClickedButton2)
	ON_WM_CLOSE()
	ON_BN_CLICKED( IDOK, &CMFCStarterKitDlg::OnBnClickedOk )
END_MESSAGE_MAP()


// gestionnaires de messages de CMFCStarterKitDlg

BOOL CMFCStarterKitDlg::OnInitDialog()
{
	// To be displayed TRACE must be initialized
	TRACE_INIT(GetModuleHandle(0));
	TRACE0("OnInitDialog:TRACE_INIT");

	CDialogEx::OnInitDialog();

	// Ajouter l'�l�ment de menu "� propos de..." au menu Syst�me.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes syst�me.
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

	// D�finir l'ic�ne de cette bo�te de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne


	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
}

void CMFCStarterKitDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si vous ajoutez un bouton R�duire � votre bo�te de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'ic�ne.  Pour les applications MFC utilisant le mod�le Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CMFCStarterKitDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de p�riph�rique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'ic�ne dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'ic�ne
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le syst�me appelle cette fonction pour obtenir le curseur � afficher lorsque l'utilisateur fait glisser
//  la fen�tre r�duite.
HCURSOR CMFCStarterKitDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCStarterKitDlg::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

void CMFCStarterKitDlg::OnBnClickedButton1()
{
//	TRACE_INIT(GetModuleHandle(0));

	BYTE theBuffer[121];

	PM_TRACE0(T("This is a Trace Test"));
	TRACE0("This is a Trace Test");
	PM_TRACE0(TL( "This is a test."));

	PM_TRACE0(TL( "%#2hx.", 4));
	PM_TRACE0(TL( "[\\n\\r\\t] = [\n\r\t]"));
	PM_TRACE0(TL( "Specials: [??]"));

	theBuffer[0] = 0xE9;
	theBuffer[1] = 0xE8;
	PM_TRACE0(T( "Specials in a buffer:"));
	PM_TRACE0(B(theBuffer, 2));

	{
		int i;

		for (i = 0; i < sizeof(theBuffer) - 1; i++)
			theBuffer[i] = i;
		theBuffer[sizeof(theBuffer) - 1] = 0;
		PM_TRACE0(TL( "Buffer in ASCII: %s", theBuffer + 1));
		PM_TRACE0(T("Buffer in HEXA"));
		PM_TRACE0(B(theBuffer, sizeof(theBuffer)));
	}

//	TRACE_CLOSE();
}

void CMFCStarterKitDlg::OnBnClickedButton2()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contr�le
	TRACE0("You clicked on button 2");
}


void CMFCStarterKitDlg::OnClose()
{
	// TODO: ajoutez ici le code de votre gestionnaire de messages et/ou les param�tres par d�faut des appels

	TRACE0("You closed the Application.");
	TRACE0("OnClose:TRACE_CLOSE");
	TRACE_CLOSE();

	CDialogEx::OnClose();
}


void CMFCStarterKitDlg::OnBnClickedOk()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contr�le
	
	// While it's a Dialogbox click on Ok may closed de DialogBox
	TRACE0("OnBnClickedOk:TRACE_CLOSE");
	TRACE_CLOSE();
	CDialogEx::OnOK();
}
