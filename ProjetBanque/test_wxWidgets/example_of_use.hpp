#pragma once
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/event.h>
#include <wx/valnum.h>
#include <string>
#include <iostream>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Customer.hpp"
#include "My_new_Customer_dialog.hpp"
#include "Customer_for_JSON.hpp"

class MyFrame_Add_Customer : public wxFrame
{
public:
    MyFrame_Add_Customer();

private:
};


class MyFrame_Add_Account : public wxFrame
{
public:
    MyFrame_Add_Account();

private:
};


class MyFrame_Add_Operation : public wxFrame
{
public:
    MyFrame_Add_Operation();

private:
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame();
    wxString numero = " ";
    int nombre = 0;
    bool connexion = false;
    wxTextCtrl* account_numbers;

private:
    void OnAdd_Customer(wxCommandEvent& event);

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    std::vector<Customer> customers_;
    std::vector<Compte> accounts_;
    std::vector<Operation> operations_;


    void OnConnexion(wxCommandEvent& event);


};

class MyFrame2 : public wxFrame
{
public:
    MyFrame2(int nbr);
    wxString numero = " ";
    int nombre = 0;
    bool connexion2 = false;
    wxTextCtrl* account_numbers;

private:

    void OnAdd_Account(wxCommandEvent& event);


    std::vector<Customer> customers_;
    std::vector<Compte> accounts_;
    std::vector<Operation> operations_;

    void OnConnexion2(wxCommandEvent& event);


};

class MyFrame3 : public wxFrame
{
public:
    MyFrame3(int nbr);
    int nombre = 0;
    wxString numero = " ";
    bool connexion3 = false;
    wxTextCtrl* account_numbers;

private:

    void OnAdd_Operation(wxCommandEvent& event);

    std::vector<Customer> customers_;
    std::vector<Compte> accounts_;
    std::vector<Operation> operations_;

    void OnConnexion3(wxCommandEvent& event);


};

class MyFrame4 : public wxFrame
{
public:
    MyFrame4(int nbr);
    wxString numero = " ";
    int nombre = 0;
    bool connexion4 = false;
    wxTextCtrl* account_numbers;

private:


    std::vector<Customer> customers_;
    std::vector<Compte> accounts_;
    std::vector<Operation> operations_;

    void OnConnexion4(wxCommandEvent& event);


};

enum class My_class_client : int
{
    ID_Add_Customer = 1,
    ID_Customer_field = 2,
    ID_Customers_save = 3
};

enum class My_class_compte : int
{
    ID_Add_Account = 1,
    ID_Account_field = 2,
    ID_Accounts_save = 3
};

enum class My_class_operation : int
{
    ID_Add_Operation = 1,
    ID_Operation_field = 2,
    ID_Operations_save = 3
};
