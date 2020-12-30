#include "tbMain.h"

tbMain::tbMain(const wxString title, const wxSize size) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size)
{
	const int lPanelWidth = size.GetWidth() / 5;
	const int mainPanelWidth = size.GetWidth() - lPanelWidth;

	initMenuBar();

	wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(lPanelWidth, size.GetHeight()));
	leftPanel->SetBackgroundColour(wxColor(100, 100, 200));

	wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(mainPanelWidth, size.GetHeight()));
	mainPanel->SetBackgroundColour(wxColor(100, 200, 100));
	
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* sizerHorizontal = new wxBoxSizer(wxHORIZONTAL);
	sizerHorizontal->Add(leftPanel, 0, wxEXPAND);
	sizerHorizontal->Add(mainPanel, 1, wxEXPAND);

	sizer->Add(sizerHorizontal, 1, wxEXPAND);

	this->SetSizerAndFit(sizer);

	/*addButton = new wxButton(this, wxID_ANY, "Add", wxPoint(10, 10), wxSize(lPanelWidth, 50));
	editButton = new wxButton(this, wxID_ANY, "Edit", wxPoint(10, 70), wxSize(150, 50));
	delButton = new wxButton(this, wxID_ANY, "Remove", wxPoint(10, 130), wxSize(150, 50));

	searchBarLabel = new wxStaticText(this, wxID_ANY, "Search for:", wxPoint(10, 200));
	searchBar = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(10, 220), wxSize(150, 24));
	searchCatBox = new wxComboBox(this, wxID_ANY, "\"any\"", wxPoint(10, 254), wxSize(150, 24));

	const int xOffset = 180;

	listView = new wxListView(this, wxID_ANY, wxPoint(xOffset, 10), wxSize(size.x - xOffset - 30, size.y - 80));*/
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
