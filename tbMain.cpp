#include "tbMain.h"

tbMain::tbMain(const wxString title, const wxSize size) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size)
{
	initMenuBar();
	addButton = new wxButton(this, wxID_ANY, "Add", wxPoint(10, 10), wxSize(150, 50));
	editButton = new wxButton(this, wxID_ANY, "Edit", wxPoint(10, 70), wxSize(150, 50));
	delButton = new wxButton(this, wxID_ANY, "Remove", wxPoint(10, 130), wxSize(150, 50));

	searchBarLabel = new wxStaticText(this, wxID_ANY, "Search for:", wxPoint(10, 200));
	searchBar = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(10, 220), wxSize(150, 24));
	searchCatBox = new wxComboBox(this, wxID_ANY, "\"any\"", wxPoint(10, 254), wxSize(150, 24));

	const int xOffset = 180;
	listView = new wxListView(this, wxID_ANY, wxPoint(xOffset, 10), wxSize(size.x - xOffset - 30, size.y - 80));
}

tbMain::~tbMain()
{
}

void tbMain::initMenuBar()
{
	menuBar = new wxMenuBar();

	fileMenu = new wxMenu();

	sNewMenu = new wxMenu();
	sNewMenu->Append(wxID_ANY, _T("Database"));
	sNewMenu->Append(wxID_ANY, _T("Table"));
	sNewMenu->Append(wxID_ANY, _T("Record"));

	fileMenu->AppendSubMenu(sNewMenu, _T("New..."));
	fileMenu->Append(wxID_ANY, _T("Open database"));
	fileMenu->Append(wxID_EXIT, _T("Exit"));
	menuBar->Append(fileMenu, _T("File"));

	editMenu = new wxMenu();
	editMenu->Append(wxID_ANY, _T("Edit checked records"));
	editMenu->Append(wxID_ANY, _T("Change database name"));
	menuBar->Append(editMenu, _T("Edit"));

	viewMenu = new wxMenu();
	menuBar->Append(viewMenu, _T("View"));

	toolsMenu = new wxMenu();
	toolsMenu->Append(wxID_ANY, _T("Preferences"));
	menuBar->Append(toolsMenu, _T("Tools"));

	helpMenu = new wxMenu();
	helpMenu->Append(wxID_HELP, _T("Show docs"));
	helpMenu->Append(wxID_ANY, _T("About"));
	menuBar->Append(helpMenu, _T("Help"));

	SetMenuBar(menuBar);
}
