#pragma once
#include "wx/wx.h"

class tbDialogNew : public wxDialog
{
public:
	tbDialogNew(wxFrame* parent, int itemid, const wxString& title, wxSize dimensions = wxDefaultSize);
	~tbDialogNew();

private:
};

