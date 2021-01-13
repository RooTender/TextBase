#include "tbDialogNew.h"

tbDialogNew::tbDialogNew(wxFrame* parent, int itemid, const wxString& title, wxSize dimensions) : wxDialog(parent, wxID_ANY, title, wxDefaultPosition, dimensions)
{
	switch (itemid) {
	case 51:
		newDatabase();
		break;

	case 52:
		newTable();
		break;

	case 53:
		newRecord();
		break;

	default:
		wxStaticText* errorLabel = new wxStaticText(this, wxID_ANY, _T("Error: Given ID is undefined! ID given: " + std::to_string(itemid)));
		return;
	}

	wxButton* okButton = new wxButton(this, wxID_OK, _T("OK"), wxPoint(this->GetSize().x - (91 + margin), this->GetSize().y - (62 + 2 * margin / 3)));
}

void tbDialogNew::newDatabase()
{
	wxStaticText* nameLabel = new wxStaticText(this, wxID_ANY, _T("Database name: "), wxPoint(margin, 20));

	int const textCtrlWidth = this->GetSize().x - (nameLabel->GetPosition().x + nameLabel->GetSize().x) - 2 * margin;
	wxTextCtrl* nameTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
												wxPoint(nameLabel->GetPosition().x + nameLabel->GetSize().x + 5, nameLabel->GetPosition().y - 3),
												wxSize(textCtrlWidth, nameLabel->GetSize().y * 1.5));
}

void tbDialogNew::newTable()
{

}

void tbDialogNew::newRecord()
{

}

tbDialogNew::~tbDialogNew()
{
}

