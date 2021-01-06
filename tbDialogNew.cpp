#include "tbDialogNew.h"

tbDialogNew::tbDialogNew(wxFrame* parent, int itemid, const wxString& title, wxSize dimensions) : wxDialog(parent, wxID_ANY, title, wxDefaultPosition, dimensions)
{
	const wxPoint initItemPosition = this->GetPosition();

	switch (itemid) {
	case 51:

		break;
	default:
		wxStaticText* label = new wxStaticText(this, wxID_ANY, _T("Error: Given ID is undefined! ID given: " + std::to_string(itemid)), initItemPosition);

		break;
	}
}

tbDialogNew::~tbDialogNew()
{
}
