#include "tbMain.h"

tbMain::tbMain(const wxString title, const wxSize size) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size)
{
	const int lPanelWidth = size.GetWidth() / 5;
	const int mainPanelWidth = size.GetWidth() - lPanelWidth;
	
	const int margin = 10;
	const int componentWidth = lPanelWidth - 2 * margin;

	initMenuBar();

	wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(lPanelWidth, size.GetHeight()));
	leftPanel->SetBackgroundColour(wxColor(100, 100, 200));

	addButton = new wxButton(leftPanel, wxID_ANY, "Add", wxPoint(margin, 10), wxSize(componentWidth, 50));
	editButton = new wxButton(leftPanel, wxID_ANY, "Edit", wxPoint(margin, 70), wxSize(componentWidth, 50));
	delButton = new wxButton(leftPanel, wxID_ANY, "Remove", wxPoint(margin, 130), wxSize(componentWidth, 50));

	searchBarLabel = new wxStaticText(leftPanel, wxID_ANY, "Search for:", wxPoint(margin, 200));
	searchBar = new wxTextCtrl(leftPanel, wxID_ANY, wxEmptyString, wxPoint(margin, 220), wxSize(componentWidth, 24));
	searchCatBox = new wxComboBox(leftPanel, wxID_ANY, "\"any\"", wxPoint(margin, 254), wxSize(componentWidth, 24));


	wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(mainPanelWidth, size.GetHeight()));
	mainPanel->SetBackgroundColour(wxColor(100, 200, 100));

	listView = new wxListView(mainPanel, wxID_ANY, wxPoint(margin, 10), wxSize(mainPanelWidth - 2 * margin, size.GetHeight() - 2 * margin));


	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* sizerHorizontal = new wxBoxSizer(wxHORIZONTAL);
	sizerHorizontal->Add(leftPanel, 0, wxEXPAND);
	sizerHorizontal->Add(mainPanel, 1, wxEXPAND);

	sizer->Add(sizerHorizontal, 1, wxEXPAND);

	this->SetSizerAndFit(sizer);
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
