#pragma once
#include "wx/wx.h"

class tbDialogNew : public wxDialog
{
public:
	tbDialogNew(wxFrame* parent, int itemid, const wxString& title, wxSize dimensions = wxDefaultSize);
	~tbDialogNew();

private:
	const int margin = 20;

	void newDatabase();
	void newTable();
	void newRecord();
};

