#include "My_new_Customer_dialog.hpp"

My_new_Customer_dialog::My_new_Customer_dialog(wxWindow* parent, wxWindowID id, const wxString& title)

	: wxDialog(parent, id, title)
{
	auto text_customer_firstname = new wxStaticText(this, -1, "Firstname : ", wxPoint(10, 20), wxSize(180, 20));
	auto text_customer_surname = new wxStaticText(this, -1, "Surname : ", wxPoint(10, 50), wxSize(180, 20));
	auto text_customer_adress = new wxStaticText(this, -1, "Adress : ", wxPoint(10, 80), wxSize(180, 20));
	auto text_customer_mail = new wxStaticText(this, -1, "Mail : ", wxPoint(10, 110), wxSize(180, 20));
	auto text_customer_phone = new wxStaticText(this, -1, "Phone Number : ", wxPoint(10, 140), wxSize(180, 20));
	auto text_customer_password = new wxStaticText(this, -1, "Password : ", wxPoint(10, 140), wxSize(180, 20));


	edit_customer_firstname_ = new wxTextCtrl(this, -1, "", wxPoint(160, 20), wxSize(100, 20));
	edit_customer_surname_ = new wxTextCtrl(this, -1, "", wxPoint(160, 50), wxSize(100, 20));
	edit_customer_adress_ = new wxTextCtrl(this, -1, "", wxPoint(160, 80), wxSize(100, 20));
	edit_customer_mail_ = new wxTextCtrl(this, -1, "", wxPoint(160, 110), wxSize(100, 20));
	edit_customer_phone_ = new wxTextCtrl(this, -1, "", wxPoint(160, 140), wxSize(100, 20));
	edit_customer_password_ = new wxTextCtrl(this, -1, "", wxPoint(160, 140), wxSize(100, 20));


	wxButton* b = new wxButton(this, wxID_OK, _("OK"), wxPoint(10, 180), wxDefaultSize);
	wxButton* c = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(100, 180), wxDefaultSize);

}

wxString My_new_Customer_dialog::get_customer_firstname() {
	return edit_customer_firstname_->GetValue();
}

wxString My_new_Customer_dialog::get_customer_surname() {
	return edit_customer_surname_->GetValue();
}

wxString My_new_Customer_dialog::get_customer_adress() {
	return edit_customer_adress_->GetValue();
}

wxString My_new_Customer_dialog::get_customer_mail() {
	return edit_customer_mail_->GetValue();
}

wxString My_new_Customer_dialog::get_customer_phone() {
	return edit_customer_phone_->GetValue();
}


wxString My_new_Customer_dialog::get_customer_password() {
	return edit_customer_password_->GetValue();
}




My_new_Compte_dialog::My_new_Compte_dialog(wxWindow* parent, wxWindowID id, const wxString& title)

	: wxDialog(parent, id, title)
{
	auto text_compte_solde = new wxStaticText(this, -1, "Solde : ", wxPoint(10, 20), wxSize(180, 20));
	auto text_compte_typecompte = new wxStaticText(this, -1, "Account Type : ", wxPoint(10, 50), wxSize(180, 20));


	edit_compte_solde = new wxTextCtrl(this, -1, "", wxPoint(160, 20), wxSize(100, 20));
	edit_compte_typecompte = new wxTextCtrl(this, -1, "", wxPoint(160, 50), wxSize(100, 20));


	wxButton* b = new wxButton(this, wxID_OK, _("OK"), wxPoint(10, 180), wxDefaultSize);
	wxButton* c = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(100, 180), wxDefaultSize);

}

wxString My_new_Compte_dialog::get_compte_solde() {
	return edit_compte_solde->GetValue();
}

wxString My_new_Compte_dialog::get_compte_typecompte() {
	return edit_compte_typecompte->GetValue();
}


My_new_Operation_dialog::My_new_Operation_dialog(wxWindow* parent, wxWindowID id, const wxString& title)

	: wxDialog(parent, id, title)
{
	auto text_operation_dateOperation = new wxStaticText(this, -1, "Operation Date : ", wxPoint(10, 20), wxSize(180, 20));
	auto text_operation_Montant = new wxStaticText(this, -1, "Montant : ", wxPoint(10, 50), wxSize(180, 20));
	auto text_operation_Type = new wxStaticText(this, -1, "Type : ", wxPoint(10, 80), wxSize(180, 20));
	auto text_operation_Emetteur = new wxStaticText(this, -1, "Emetteur : ", wxPoint(10, 110), wxSize(180, 20));
	auto text_operation_Recepteur = new wxStaticText(this, -1, "Recepteur : ", wxPoint(10, 140), wxSize(180, 20));
	auto text_operation_Motif = new wxStaticText(this, -1, "Motif : ", wxPoint(10, 140), wxSize(180, 20));


	edit_operation_dateOperation_ = new wxTextCtrl(this, -1, "", wxPoint(160, 20), wxSize(100, 20));
	edit_operation_Montant_ = new wxTextCtrl(this, -1, "", wxPoint(160, 50), wxSize(100, 20));
	edit_operation_Type_ = new wxTextCtrl(this, -1, "", wxPoint(160, 80), wxSize(100, 20));
	edit_operation_Emetteur_ = new wxTextCtrl(this, -1, "", wxPoint(160, 110), wxSize(100, 20));
	edit_operation_Recepteur_ = new wxTextCtrl(this, -1, "", wxPoint(160, 140), wxSize(100, 20));
	edit_operation_Motif_= new wxTextCtrl(this, -1, "", wxPoint(160, 140), wxSize(100, 20));


	wxButton* b = new wxButton(this, wxID_OK, _("OK"), wxPoint(10, 180), wxDefaultSize);
	wxButton* c = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(100, 180), wxDefaultSize);

}

wxString My_new_Operation_dialog::get_operation_dateOperation() {
	return edit_operation_dateOperation_->GetValue();
}

wxString My_new_Operation_dialog::get_operation_Montant() {
	return edit_operation_Montant_->GetValue();
}

wxString My_new_Operation_dialog::get_operation_Type() {
	return edit_operation_Type_->GetValue();
}

wxString My_new_Operation_dialog::get_operation_Emetteur() {
	return edit_operation_Emetteur_->GetValue();
}

wxString My_new_Operation_dialog::get_operation_Recepteur() {
	return edit_operation_Recepteur_->GetValue();
}

wxString My_new_Operation_dialog::get_operation_Motif() {
	return edit_operation_Motif_->GetValue();
}
