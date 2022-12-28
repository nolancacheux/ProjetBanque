#include "My_new_Customer_dialog.hpp"

My_new_Customer_dialog::My_new_Customer_dialog(wxWindow* parent, wxWindowID id, const wxString& title)

	: wxDialog(parent, id, title)
{
	auto text_customer_firstname = new wxStaticText(this, -1, "Firstname : ", wxPoint(10, 20), wxSize(180, 20));
	auto text_customer_surname = new wxStaticText(this, -1, "Surname : ", wxPoint(10, 50), wxSize(180, 20));
	auto text_customer_adress = new wxStaticText(this, -1, "Address : ", wxPoint(10, 80), wxSize(180, 20));
	auto text_customer_mail = new wxStaticText(this, -1, "Mail : ", wxPoint(10, 110), wxSize(180, 20));
	auto text_customer_phone = new wxStaticText(this, -1, "Phone Number : ", wxPoint(10, 140), wxSize(180, 20));
	auto text_customer_password = new wxStaticText(this, -1, "Password : ", wxPoint(10, 170), wxSize(180, 20));


	edit_customer_firstname_ = new wxTextCtrl(this, -1, "", wxPoint(160, 20), wxSize(100, 20));
	edit_customer_surname_ = new wxTextCtrl(this, -1, "", wxPoint(160, 50), wxSize(100, 20));
	edit_customer_adress_ = new wxTextCtrl(this, -1, "", wxPoint(160, 80), wxSize(100, 20));
	edit_customer_mail_ = new wxTextCtrl(this, -1, "", wxPoint(160, 110), wxSize(100, 20));
	edit_customer_phone_ = new wxTextCtrl(this, -1, "", wxPoint(160, 140), wxSize(100, 20));
	edit_customer_password_ = new wxTextCtrl(this, -1, "", wxPoint(160, 170), wxSize(100, 20), wxTE_PASSWORD);


	wxButton* b = new wxButton(this, wxID_OK, _("OK"), wxPoint(10, 200), wxDefaultSize);
	wxButton* c = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(100, 200), wxDefaultSize);

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
	auto text_compte_solde = new wxStaticText(this, -1, "Amount : ", wxPoint(10, 20), wxSize(180, 20));
	auto text_compte_typecompte = new wxStaticText(this, -1, "Account Type : ", wxPoint(10, 50), wxSize(180, 20));

	// Crée les boutons de choix radio
	choice1 = new wxRadioButton(this, wxID_ANY, "Courant", wxPoint(160, 50), wxSize(180, 20), wxRB_GROUP);
	choice2 = new wxRadioButton(this, wxID_ANY, "Livret A", wxPoint(160, 80), wxSize(180, 20));
	choice3 = new wxRadioButton(this, wxID_ANY, "PEA", wxPoint(160, 110), wxSize(180, 20));


	edit_compte_solde = new wxTextCtrl(this, -1, "", wxPoint(160, 20), wxSize(100, 20));



	wxButton* b = new wxButton(this, wxID_OK, _("OK"), wxPoint(10, 140), wxDefaultSize);
	wxButton* c = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(100, 140), wxDefaultSize);

}

wxString My_new_Compte_dialog::get_compte_solde() {
	return edit_compte_solde->GetValue();
}









wxString My_new_Compte_dialog::get_compte_typecompte() {

	wxString retour = "ERROR";
	if (choice1->GetValue()) {
		std::string str = "Courant (Pas d'interet)";
		wxString retour(str);
		return retour;
	}
	else if (choice2->GetValue()) {
		std::string str = "Livret A (Interet : 3%)";
		wxString retour(str);
		return retour;
	}
	else if (choice3->GetValue()) {
		std::string str = "PEA (Interet : 15%)";
		wxString retour(str);
		return retour;
	}
	else {
		std::string str = "No type information";
		wxString retour(str);
		return retour;
	}
	
}



My_new_interet_dialog::My_new_interet_dialog(wxWindow* parent, wxWindowID id, const wxString& title)

	: wxDialog(parent, id, title)
{
	auto text_compte_typecompte = new wxStaticText(this, -1, "See in how many years : ", wxPoint(10, 50), wxSize(180, 20));

	// Crée les boutons de choix radio
	choice1 = new wxRadioButton(this, wxID_ANY, "+1 year", wxPoint(160, 50), wxSize(180, 20), wxRB_GROUP);
	choice2 = new wxRadioButton(this, wxID_ANY, "+5 years", wxPoint(160, 80), wxSize(180, 20));
	choice3 = new wxRadioButton(this, wxID_ANY, "+10 years", wxPoint(160, 110), wxSize(180, 20));

	wxButton* b = new wxButton(this, wxID_OK, _("OK"), wxPoint(10, 140), wxDefaultSize);
	wxButton* c = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(100, 140), wxDefaultSize);

}


wxString My_new_interet_dialog::get_interet_annees() {

	wxString retour = "ERROR";
	if (choice1->GetValue()) {
		std::string str = "1";
		wxString retour(str);
		return retour;
	}
	else if (choice2->GetValue()) {
		std::string str = "5";
		wxString retour(str);
		return retour;
	}
	else if (choice3->GetValue()) {
		std::string str = "10";
		wxString retour(str);
		return retour;
	}
	else {
		std::string str = "0";
		wxString retour(str);
		return retour;
	}

}

My_virement_dialog::My_virement_dialog(wxWindow* parent, wxWindowID id, const wxString& title)

	: wxDialog(parent, id, title)
{

	auto text_compte_emetteur = new wxStaticText(this, -1, "Transmitter : ", wxPoint(10, 20), wxSize(180, 20));
	auto text_compte_recepteur = new wxStaticText(this, -1, "Receiver : ", wxPoint(10, 50), wxSize(180, 20));
	auto text_compte_montant = new wxStaticText(this, -1, "Amount : ", wxPoint(10, 80), wxSize(180, 20));
	


	edit_compte_emetteur = new wxTextCtrl(this, -1, "", wxPoint(160, 20), wxSize(100, 20));
	edit_compte_recepteur = new wxTextCtrl(this, -1, "", wxPoint(160, 50), wxSize(100, 20));
	edit_compte_montant = new wxTextCtrl(this, -1, "", wxPoint(160, 80), wxSize(100, 20));


	wxButton* b = new wxButton(this, wxID_OK, _("OK"), wxPoint(10, 110), wxDefaultSize);
	wxButton* c = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(100, 110), wxDefaultSize);

}

wxString My_virement_dialog::get_virement_emetteur() {
	return edit_compte_emetteur->GetValue();
}

wxString My_virement_dialog::get_virement_recepteur() {
	return edit_compte_recepteur->GetValue();
}

wxString My_virement_dialog::get_virement_montant() {
	return edit_compte_montant->GetValue();
}

My_new_Operation_dialog::My_new_Operation_dialog(wxWindow* parent, wxWindowID id, const wxString& title)

	: wxDialog(parent, id, title)
{
	auto text_operation_dateOperation = new wxStaticText(this, -1, "Operation Date : ", wxPoint(10, 20), wxSize(180, 20));
	auto text_operation_Montant = new wxStaticText(this, -1, "Amount : ", wxPoint(10, 50), wxSize(180, 20));
	auto text_operation_Type = new wxStaticText(this, -1, "Type : ", wxPoint(10, 80), wxSize(180, 20));
	auto text_operation_Emetteur = new wxStaticText(this, -1, "Transmitter : ", wxPoint(10, 110), wxSize(180, 20));
	auto text_operation_Recepteur = new wxStaticText(this, -1, "Receiver : ", wxPoint(10, 140), wxSize(180, 20));
	auto text_operation_Motif = new wxStaticText(this, -1, "Amount : ", wxPoint(10, 170), wxSize(180, 20));


	edit_operation_dateOperation_ = new wxTextCtrl(this, -1, "", wxPoint(160, 20), wxSize(100, 20));
	edit_operation_Montant_ = new wxTextCtrl(this, -1, "", wxPoint(160, 50), wxSize(100, 20));
	edit_operation_Type_ = new wxTextCtrl(this, -1, "", wxPoint(160, 80), wxSize(100, 20));
	edit_operation_Emetteur_ = new wxTextCtrl(this, -1, "", wxPoint(160, 110), wxSize(100, 20));
	edit_operation_Recepteur_ = new wxTextCtrl(this, -1, "", wxPoint(160, 140), wxSize(100, 20));
	edit_operation_Motif_= new wxTextCtrl(this, -1, "", wxPoint(160, 170), wxSize(100, 20));


	wxButton* b = new wxButton(this, wxID_OK, _("OK"), wxPoint(10, 200), wxDefaultSize);
	wxButton* c = new wxButton(this, wxID_CANCEL, _("Cancel"), wxPoint(100, 200), wxDefaultSize);

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
