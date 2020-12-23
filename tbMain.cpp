#include "tbMain.h"

tbMain::tbMain(const wxString title, const wxSize size) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size)
{
	initMenuBar();
}

tbMain::~tbMain()
{
}

void tbMain::initMenuBar()
{
	menuBar = new wxMenuBar();

	fileMenu = new wxMenu();
	fileMenu->Append(wxID_OPEN, _T("Open"));
	menuBar->Append(fileMenu, _T("File"));

	editMenu = new wxMenu();
	menuBar->Append(editMenu, _T("Edit"));

	viewMenu = new wxMenu();
	menuBar->Append(viewMenu, _T("View"));

	toolsMenu = new wxMenu();
	menuBar->Append(toolsMenu, _T("Tools"));

	helpMenu = new wxMenu();
	menuBar->Append(helpMenu, _T("Help"));

	SetMenuBar(menuBar);
}
