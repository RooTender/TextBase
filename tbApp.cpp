#include "tbApp.h"

wxIMPLEMENT_APP(tbApp);

tbApp::tbApp()
{
}

tbApp::~tbApp()
{
}

bool tbApp::OnInit()
{	
	mainFrame = new tbMain("TextBase - Simple Database Editor", wxSize(800, 480));
	mainFrame->Show();

	return true;
}
