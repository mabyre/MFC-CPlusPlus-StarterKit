
// MFCStarterKit.h�: fichier d'en-t�te principal de l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CMFCStarterKitApp�:
// Consultez MFCStarterKit.cpp pour l'impl�mentation de cette classe
//

class CMFCStarterKitApp : public CWinApp
{
public:
	CMFCStarterKitApp();

// Substitutions
public:
	virtual BOOL InitInstance();

// Impl�mentation
	
	DECLARE_MESSAGE_MAP()
};

extern CMFCStarterKitApp theApp;
