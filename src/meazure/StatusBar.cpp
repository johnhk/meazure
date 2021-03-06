/*
 * Copyright 2001, 2004, 2011 C Thing Software
 *
 * This file is part of Meazure.
 * 
 * Meazure is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Meazure is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with Meazure.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "stdafx.h"
#include "StatusBar.h"


BEGIN_MESSAGE_MAP(MeaStatusBar, CStatusBar)
    ON_MESSAGE(WM_SETTEXT, OnSetText)
END_MESSAGE_MAP()


 MeaStatusBar::MeaStatusBar() : CStatusBar()
{
}


MeaStatusBar::~MeaStatusBar()
{
}


void MeaStatusBar::SetIdleMessage(LPCTSTR msg)
{
    m_idleMsg = msg;
    SetPaneText(0, static_cast<LPCTSTR>(msg), TRUE);
}


LRESULT MeaStatusBar::OnSetText(WPARAM wParam, LPARAM lParam)
{
    CString idleMessage = MAKEINTRESOURCE(AFX_IDS_IDLEMESSAGE);

    if ((lParam != 0) && (idleMessage == reinterpret_cast<LPTSTR>(lParam))) {
        lParam = reinterpret_cast<LPARAM>(m_idleMsg.GetBuffer(256));
    }

    return CStatusBar::OnSetText(wParam, lParam);
}


int MeaStatusBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
    if (CStatusBar::OnCreate(lpCreateStruct) == -1) {
        return -1;
    }
    
    m_idleMsg = MAKEINTRESOURCE(AFX_IDS_IDLEMESSAGE);
    return 0;
}
