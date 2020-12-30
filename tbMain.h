#pragma once
#include "wx/wx.h"
#include "wx/listctrl.h"

class tbMain : public wxFrame
{
public:
	tbMain(const wxString title, const wxSize size);
	~tbMain();

private:
	const int margin = 10;

	// menubar
	wxMenuBar* menuBar = nullptr;

	wxMenu* fileMenu = nullptr;
		wxMenu* sNewMenu = nullptr;
	wxMenu* editMenu = nullptr;
	wxMenu* viewMenu = nullptr;
	wxMenu* toolsMenu = nullptr;
	wxMenu* helpMenu = nullptr;

	// app content
	wxButton* addButton = nullptr;
	wxButton* editButton = nullptr;
	wxButton* delButton = nullptr;

	wxStaticText* searchBarLabel = nullptr;
	wxTextCtrl* searchBar = nullptr;
	wxComboBox* searchCatBox = nullptr;

	wxListView* listView = nullptr;

	void initMenuBar();
	void setSizers(wxPanel* leftPanel, wxPanel* mainPanel, wxListView* listViewToAttach);
};

