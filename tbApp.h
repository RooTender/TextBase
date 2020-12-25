#pragma once
#include "wx/wx.h"
#include "tbMain.h"

class tbApp : public wxApp
{
public:
	tbApp();
	~tbApp();

	virtual bool OnInit();

private:
	tbMain* mainFrame = nullptr;

};

