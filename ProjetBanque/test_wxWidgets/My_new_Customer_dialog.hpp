
#pragma once
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/event.h>
#include <wx/valnum.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include"Customer.hpp"

class My_new_Customer_dialog : public wxDialog
{
public:

	My_new_Customer_dialog(wxWindow* parent, wxWindowID id, const wxString& title);


	wxString get_customer_firstname();
	wxString get_customer_surname();
	wxString get_customer_adress();
	wxString get_customer_mail();
	wxString get_customer_phone();
	wxString get_customer_password();

private:

	wxTextCtrl* edit_customer_firstname_;
	wxTextCtrl* edit_customer_surname_;
	wxTextCtrl* edit_customer_adress_;
	wxTextCtrl* edit_customer_mail_;
	wxTextCtrl* edit_customer_phone_;
	wxTextCtrl* edit_customer_password_;
};

class My_new_Compte_dialog : public wxDialog
{
public:

	My_new_Compte_dialog(wxWindow* parent, wxWindowID id, const wxString& title);


	wxString get_compte_solde();
	wxString get_compte_typecompte();

private:

	wxTextCtrl* edit_compte_solde;
	wxRadioButton* choice1;
	wxRadioButton* choice2;
	wxRadioButton* choice3;
};

class My_virement_dialog : public wxDialog
{
public:

	My_virement_dialog(wxWindow* parent, wxWindowID id, const wxString& title);


	wxString get_virement_emetteur();
	wxString get_virement_recepteur();
	wxString get_virement_montant();

private:

	wxTextCtrl* edit_compte_emetteur;
	wxTextCtrl* edit_compte_recepteur;
	wxTextCtrl* edit_compte_montant;

};

class My_new_Operation_dialog : public wxDialog
{
public:

	My_new_Operation_dialog(wxWindow* parent, wxWindowID id, const wxString& title);


	wxString get_operation_dateOperation();
	wxString get_operation_Montant();
	wxString get_operation_Type();
	wxString get_operation_Emetteur();
	wxString get_operation_Recepteur();
	wxString get_operation_Motif();

private:

	wxTextCtrl* edit_operation_dateOperation_;
	wxTextCtrl* edit_operation_Montant_;
	wxTextCtrl* edit_operation_Type_;
	wxTextCtrl* edit_operation_Emetteur_;
	wxTextCtrl* edit_operation_Recepteur_;
	wxTextCtrl* edit_operation_Motif_;
};
