#include "Customer_for_JSON.hpp"
#include "example_of_use.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
using namespace std;

wxIMPLEMENT_APP(MyApp);



bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    // SetTopWindow(frame);
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Bank Agency", wxPoint(30, 30), wxSize(800, 600))
{

    SetBackgroundColour(wxColour(51, 65, 94));
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(static_cast<int>(My_class_client::ID_Add_Customer), "&Add_Customer...\tCtrl-A",
        "Add a customer");
    menuFile->AppendSeparator();


   /* menuFile->Append(static_cast<int>(My_class_compte::ID_Add_Account), "&Add_Account...\tCtrl-A",
        "Add an Account");
    menuFile->AppendSeparator();

    menuFile->Append(static_cast<int>(My_class_operation::ID_Add_Operation), "&Add_Operation...\tCtrl-A",
        "Add an Operation");
    menuFile->AppendSeparator();*/
    /*
    menuFile->Append(static_cast<int>(My_class_client::ID_Customers_save), "&Save all customers...\tCtrl-S",
        "Save customers");
    menuFile->AppendSeparator();*/
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&Customers Management");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to Bank agency!");

    Bind(wxEVT_MENU, &MyFrame::OnAdd_Customer, this, static_cast<int>(My_class_client::ID_Add_Customer)); // My_class_client::ID_Add_Customer

   /* Bind(wxEVT_MENU, &MyFrame::OnAdd_Account, this, static_cast<int>(My_class_compte::ID_Add_Account));

    Bind(wxEVT_MENU, &MyFrame::OnAdd_Operation, this, static_cast<int>(My_class_operation::ID_Add_Operation));*/

    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);/*
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MyFrame::OnSaveCustomers, this, static_cast<int>(My_class_client::ID_Customers_save));*/

    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, 5, "Connexion", wxPoint(340, 100), wxSize(100, 35));
    button->Bind(wxEVT_BUTTON, &MyFrame::OnConnexion, this);

    wxButton* button2 = new wxButton(panel, 5, "Inscription", wxPoint(340, 150), wxSize(100, 35));
    button2->Bind(wxEVT_BUTTON, &MyFrame::OnAdd_Customer, this);

   // wxButton* button2 = new wxButton(panel, 5, "Inscription", wxPoint(340, 140), wxSize(100, 35));


    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Bienvenue dans la BANQUE 1 !", wxPoint(300, 10));
    wxStaticText* Account = new wxStaticText(panel, wxID_ANY, "Client Numbers : ", wxPoint(270, 55), wxSize(180, -1));

    text->SetForegroundColour(wxColour(255, 255, 255));
    Account->SetForegroundColour(wxColour(255, 255, 255));

    account_numbers = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(380, 50), wxSize(120, -1));
}

void MyFrame::OnConnexion(wxCommandEvent& event) {
    connexion = true;
    if (connexion == true) {

        numero.Append(account_numbers->GetValue());
       // wxMessageBox(numero);
        int nbr = atoi(numero);
        MyFrame2* frame2 = new MyFrame2(nbr);
        frame2->Show(true);
        Close(true);
    }
}

MyFrame2::MyFrame2(int nbr)
    : wxFrame(nullptr, wxID_ANY, "Bank Agency", wxPoint(30, 30), wxSize(800, 600))
{
    this->nombre = nbr;
    SetBackgroundColour(wxColour(51, 65, 94));
    wxMenu* menuFile2 = new wxMenu;

    menuFile2->Append(static_cast<int>(My_class_compte::ID_Add_Account), "&Add_Account...\tCtrl-A",
        "Add an Account");
    menuFile2->AppendSeparator();

    /*menuFile2->Append(static_cast<int>(My_class_operation::ID_Add_Operation), "&Add_Operation...\tCtrl-A",
        "Add an Operation");
    menuFile2->AppendSeparator();*/
    /*
    menuFile->Append(static_cast<int>(My_class_client::ID_Customers_save), "&Save all customers...\tCtrl-S",
        "Save customers");
    menuFile->AppendSeparator();*/
    menuFile2->Append(wxID_EXIT);

    wxMenu* menuHelp2 = new wxMenu;
    menuHelp2->Append(wxID_ABOUT);

    wxMenuBar* menuBar2 = new wxMenuBar;
    menuBar2->Append(menuFile2, "&Customers Management");
    menuBar2->Append(menuHelp2, "&Help");

    SetMenuBar(menuBar2);

    CreateStatusBar();
    SetStatusText("Welcome to Bank agency!");


    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, 10, "VIEW", wxPoint(340, 100), wxSize(100, 35));
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Vos informations:", wxPoint(300, 10), wxSize(250, 50));
    wxStaticText* Account = new wxStaticText(panel, wxID_ANY, "Account Numbers : ", wxPoint(270, 55), wxSize(180, -1));
    account_numbers = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(380, 50), wxSize(120, -1));

    wxButton* button2 = new wxButton(panel, 5, "New Account", wxPoint(340, 150), wxSize(100, 35));
    button2->Bind(wxEVT_BUTTON, &MyFrame2::OnAdd_Account, this);

    text->SetForegroundColour(wxColour(255, 255, 255));
    Account->SetForegroundColour(wxColour(255, 255, 255));

    ptree pt_write;
    std::ifstream file_in("example_write_read.json");
    read_json(file_in, pt_write);
    file_in.close();

    //auto L = std::to_string(nbr);
    //wxMessageBox(wxT());

    Customer clientvalue = get_a_customer(pt_write, nbr);

    wxStaticText* nom = new wxStaticText(panel, -1, "Nom : ", wxPoint(10, 20), wxSize(250, 50));
    wxStaticText* nom_ = new wxStaticText(panel, -1, clientvalue.nom_, wxPoint(30, 40), wxSize(180, 20));

    nom->SetForegroundColour(wxColour(255, 255, 255));
    nom_->SetForegroundColour(wxColour(255, 255, 255)); 

    wxStaticText* prenom = new wxStaticText(panel, -1, "Prénom : ", wxPoint(10, 70), wxSize(180, 20));
    wxStaticText* prenom_ = new wxStaticText(panel, -1, clientvalue.prenom_, wxPoint(30, 90), wxSize(180, 20));
    prenom->SetForegroundColour(wxColour(255, 255, 255));
    prenom_->SetForegroundColour(wxColour(255, 255, 255));

    wxStaticText* adresse = new wxStaticText(panel, -1, "Adresse : ", wxPoint(10, 120), wxSize(180, 20));
    wxStaticText* adresse_ = new wxStaticText(panel, -1, clientvalue.adresse_, wxPoint(30, 140), wxSize(180, 20));
    adresse->SetForegroundColour(wxColour(255, 255, 255));
    adresse_->SetForegroundColour(wxColour(255, 255, 255));

    wxStaticText* mail = new wxStaticText(panel, -1, "Mail : ", wxPoint(10, 170), wxSize(180, 20));
    wxStaticText* mail_ = new wxStaticText(panel, -1, clientvalue.mail_, wxPoint(30, 190), wxSize(180, 20));
    mail->SetForegroundColour(wxColour(255, 255, 255));
    mail_->SetForegroundColour(wxColour(255, 255, 255));

    wxStaticText* telephone = new wxStaticText(panel, -1, "Telephone : ", wxPoint(10, 220), wxSize(180, 20));
    wxStaticText* telephone_ = new wxStaticText(panel, -1, clientvalue.telephone_, wxPoint(30, 240), wxSize(180, 20));
    telephone->SetForegroundColour(wxColour(255, 255, 255));
    telephone_->SetForegroundColour(wxColour(255, 255, 255));

    std::stringstream ss;
    copy(clientvalue.comptes_.begin(), clientvalue.comptes_.end(), ostream_iterator<int>(ss, " - "));
    string s = ss.str();
    s = s.substr(0, s.length() - 1);

    wxStaticText* compte = new wxStaticText(panel, -1, "Comptes : ", wxPoint(10, 220), wxSize(180, 20));
    wxStaticText* compte_ = new wxStaticText(panel, -1, s, wxPoint(30, 240), wxSize(180, 20));
    compte->SetForegroundColour(wxColour(255, 255, 255));
    compte_->SetForegroundColour(wxColour(255, 255, 255));



    Bind(wxEVT_BUTTON, &MyFrame2::OnConnexion2, this, 10);

}

void MyFrame2::OnConnexion2(wxCommandEvent& event) {
    connexion2 = true;
    if (connexion2 == true) {
        numero.Append(account_numbers->GetValue());
        //wxMessageBox(numero);
        int nbr = atoi(numero);
        MyFrame3* frame3 = new MyFrame3(nbr);
        frame3->Show(true);
        Close(true);
    }
}
MyFrame3::MyFrame3(int nbr)
    : wxFrame(nullptr, wxID_ANY, "Bank Agency", wxPoint(30, 30), wxSize(800, 600))
{
    this->nombre = nbr;
    SetBackgroundColour(wxColour(51, 65, 94));
    wxMenu* menuFile2 = new wxMenu;

    menuFile2->Append(static_cast<int>(My_class_compte::ID_Add_Account), "&Add_Account...\tCtrl-A",
        "Add an Account");
    menuFile2->AppendSeparator();

    /*menuFile2->Append(static_cast<int>(My_class_operation::ID_Add_Operation), "&Add_Operation...\tCtrl-A",
        "Add an Operation");
    menuFile2->AppendSeparator();*/
    /*
    menuFile->Append(static_cast<int>(My_class_client::ID_Customers_save), "&Save all customers...\tCtrl-S",
        "Save customers");
    menuFile->AppendSeparator();
    menuFile2->Append(wxID_EXIT);*/

    wxMenu* menuHelp2 = new wxMenu;
    menuHelp2->Append(wxID_ABOUT);

    wxMenuBar* menuBar2 = new wxMenuBar;
    menuBar2->Append(menuFile2, "&Customers Management");
    menuBar2->Append(menuHelp2, "&Help");

    SetMenuBar(menuBar2);

    CreateStatusBar();
    SetStatusText("Welcome to Bank agency!");


    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, 10, "VIEW", wxPoint(340, 100), wxSize(100, 35));
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Informations de votre compte:", wxPoint(300, 10));
    wxStaticText* Account = new wxStaticText(panel, wxID_ANY, "Operation Number : ", wxPoint(270, 55), wxSize(180, -1));
    account_numbers = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(380, 50), wxSize(120, -1));

    wxButton* button2 = new wxButton(panel, 5, "New Operation", wxPoint(340, 150), wxSize(100, 35));
    button2->Bind(wxEVT_BUTTON, &MyFrame3::OnAdd_Operation, this);

    text->SetForegroundColour(wxColour(255, 255, 255));
    Account->SetForegroundColour(wxColour(255, 255, 255));

    ptree pt_write;
    std::ifstream file_in("example_write_read.json");
    read_json(file_in, pt_write);
    file_in.close();
    Compte Valuecompte = get_an_account(pt_write, 1001111);
    //wxStaticText* numero = new wxStaticText(panel, -1, "Numero de compte : ", wxPoint(10, 20), wxSize(250, 20));
    //wxStaticText* numero_ = new wxStaticText(panel, -1, Valuecompte.nombre_, wxPoint(30, 40), wxSize(180, 20));
    wxStaticText* solde = new wxStaticText(panel, -1, "Solde : ", wxPoint(10, 70), wxSize(250, 20));
    wxStaticText* solde_ = new wxStaticText(panel, -1, Valuecompte.solde_, wxPoint(30, 90), wxSize(250, 20));
    wxStaticText* type = new wxStaticText(panel, -1, "Type : ", wxPoint(10, 120), wxSize(250, 20));
    wxStaticText* type_ = new wxStaticText(panel, -1, Valuecompte.typeCompte_, wxPoint(30, 140), wxSize(250, 20));

    solde->SetForegroundColour(wxColour(255, 255, 255));
    solde_->SetForegroundColour(wxColour(255, 255, 255));
    type->SetForegroundColour(wxColour(255, 255, 255));
    type_->SetForegroundColour(wxColour(255, 255, 255));
    wxStaticText* ope = new wxStaticText(panel, -1, "Operations : ", wxPoint(10, 170), wxSize(250, 20));

    std::stringstream ss; 
    copy(Valuecompte.operations_.begin(), Valuecompte.operations_.end(), ostream_iterator<int>(ss, " - "));
    string s = ss.str();
    s = s.substr(0, s.length() - 1);
    wxStaticText* ope_ = new wxStaticText(panel, -1, s, wxPoint(30, 190), wxSize(180, 20));
    ope->SetForegroundColour(wxColour(255, 255, 255));
    ope_->SetForegroundColour(wxColour(255, 255, 255));

    Bind(wxEVT_BUTTON, &MyFrame3::OnConnexion3, this, 10);

}

void MyFrame3::OnConnexion3(wxCommandEvent& event) {
    connexion3 = true;
    if (connexion3 == true) {
        numero.Append(account_numbers->GetValue());
        //wxMessageBox(numero);
        int nbr = atoi(numero);
        MyFrame4* frame4 = new MyFrame4(nbr);
        frame4->nombre = nbr;
        frame4->Show(true);
        Close(true);
    }
}
MyFrame4::MyFrame4(int nbr)
    : wxFrame(nullptr, wxID_ANY, "Bank Agency", wxPoint(30, 30), wxSize(800, 600))
{
    this->nombre = nbr;
    SetBackgroundColour(wxColour(51, 65, 94));
    wxPanel* panel = new wxPanel(this);
    ptree pt_write;
    std::ifstream file_in("example_write_read.json");
    read_json(file_in, pt_write);
    file_in.close();
    Operation Valueoperation = get_an_operation(pt_write, nbr);
    wxButton* button = new wxButton(panel, 10, "VIEW", wxPoint(340, 100), wxSize(100, 35));
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Informations de votre compte:", wxPoint(300, 10));


    text->SetForegroundColour(wxColour(255, 255, 255));

    //wxStaticText* numero = new wxStaticText(panel, -1, "Numero operation : ", wxPoint(10, 20), wxSize(180, 20));
    //wxStaticText* numero_ = new wxStaticText(panel, -1, Valueoperation.nombre_, wxPoint(30, 40), wxSize(180, 20));
    wxStaticText* date = new wxStaticText(panel, -1, "Date de l'operation : ", wxPoint(10, 70), wxSize(180, 20));
    wxStaticText* date_ = new wxStaticText(panel, -1, Valueoperation.DateOperation_, wxPoint(30, 90), wxSize(180, 20));
    wxStaticText* montant = new wxStaticText(panel, -1, "Montant : ", wxPoint(10, 120), wxSize(180, 20));
    wxStaticText* montant_ = new wxStaticText(panel, -1, Valueoperation.montant_, wxPoint(30, 140), wxSize(180, 20));
    wxStaticText* type = new wxStaticText(panel, -1, "Type : ", wxPoint(10, 170), wxSize(180, 20));
    wxStaticText* type_ = new wxStaticText(panel, -1, Valueoperation.type_, wxPoint(30, 190), wxSize(180, 20));
    wxStaticText* emetteur = new wxStaticText(panel, -1, "Emetteur : ", wxPoint(10, 220), wxSize(180, 20));
    wxStaticText* emetteur_ = new wxStaticText(panel, -1, Valueoperation.emetteur_, wxPoint(30, 240), wxSize(180, 20));
    wxStaticText* recepteur = new wxStaticText(panel, -1, "Recepteur : ", wxPoint(10, 270), wxSize(180, 20));
    wxStaticText* recepteur_ = new wxStaticText(panel, -1, Valueoperation.recepteur_, wxPoint(30, 290), wxSize(180, 20));
    wxStaticText* motif = new wxStaticText(panel, -1, "Motif : ", wxPoint(10, 320), wxSize(180, 20));
    wxStaticText* motif_ = new wxStaticText(panel, -1, Valueoperation.motif_, wxPoint(30, 340), wxSize(180, 20));

    date->SetForegroundColour(wxColour(255, 255, 255));
    date_->SetForegroundColour(wxColour(255, 255, 255));
    montant->SetForegroundColour(wxColour(255, 255, 255));
    montant_->SetForegroundColour(wxColour(255, 255, 255));
    type->SetForegroundColour(wxColour(255, 255, 255));
    type_->SetForegroundColour(wxColour(255, 255, 255));
    emetteur->SetForegroundColour(wxColour(255, 255, 255));
    emetteur_->SetForegroundColour(wxColour(255, 255, 255));
    recepteur->SetForegroundColour(wxColour(255, 255, 255));
    recepteur_->SetForegroundColour(wxColour(255, 255, 255));
    motif->SetForegroundColour(wxColour(255, 255, 255));
    motif_->SetForegroundColour(wxColour(255, 255, 255));

}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets demonstration for client management",
        "About Client Management", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnAdd_Customer(wxCommandEvent& event)
{

    auto new_customer = new My_new_Customer_dialog(this, wxID_ANY, "Test_Dialog");

    if (new_customer->ShowModal() == wxID_OK)
    {

        auto customer_firstname = new_customer->get_customer_firstname();
        auto customer_surname = new_customer->get_customer_surname();
        auto customer_adress = new_customer->get_customer_adress();
        auto customer_mail = new_customer->get_customer_mail();
        auto customer_phone = new_customer->get_customer_phone();
        auto customer_password = new_customer->get_customer_password();

        std::string fisrtname = std::string(customer_firstname);
        std::string surnname = std::string(customer_surname);
        std::string adress = std::string(customer_adress);
        std::string mail = std::string(customer_mail);
        std::string phone = std::string(customer_phone);
        std::string password = std::string(customer_password);

        srand(NULL);
        auto client_numbers = rand(); // Only one at this time
        auto Lombre_compte = std::to_string(client_numbers);
        wxMessageBox(wxT("Votre numéro de client est le suivant : ") + wxT(ombre_compte));


        Customer customer(client_numbers, std::move(fisrtname), std::move(surnname), std::move(adress), std::move(mail), std::move(phone), std::move(password), {});
        customers_.push_back(customer);
        delete new_customer;

        ptree pt_write;
        ptree pt_accounts;
        try
        {

            std::ifstream file_in("example_write_read.json");
            read_json(file_in, pt_write);
            file_in.close();

            pt_write = write_a_customer(pt_write, customer);

            std::ofstream file_out2("example_write_read.json");
            write_json(file_out2, pt_write);
            file_out2.close();

            std::ifstream file_in2("example_write_read.json");
            read_json(file_in2, pt_write);
            file_in2.close();
        }
        catch (std::exception& e)
        {
            // Other errors
            std::cout << "Error :" << e.what() << std::endl;
        }
        Refresh();
    }
    
}


void MyFrame2::OnAdd_Account(wxCommandEvent& event)
{

    auto new_account = new My_new_Compte_dialog(this, wxID_ANY, "Test_Dialog");

    if (new_account->ShowModal() == wxID_OK)
    {
        auto compte_solde = new_account->get_compte_solde();
        auto compte_typecompte = new_account->get_compte_typecompte();

        std::string solde = std::string(compte_solde);
        std::string typeCompte = std::string(compte_typecompte);
        //long account_numbers; // Only one at this time

        srand(NULL);
        auto account_numbers = rand(); // Only one at this time
        auto Lombre_compte = std::to_string(account_numbers);
        wxMessageBox(wxT("Votre numéro de compte est le suivant : ") + wxT(ombre_compte));

        Compte account(account_numbers, std::move(solde), std::move(typeCompte), {});
        accounts_.push_back(account);
        delete new_account;

        ptree pt_write;
        ptree pt_accounts;
        try
        {

            std::ifstream file_in("example_write_read.json");
            read_json(file_in, pt_write);
            file_in.close();

            auto custom = get_a_customer(pt_write, this->nombre);

            pt_write = write_an_account(pt_write, account, custom);

            std::ofstream file_out2("example_write_read.json");
            write_json(file_out2, pt_write);
            file_out2.close();

            std::ifstream file_in2("example_write_read.json");
            read_json(file_in2, pt_write);
            file_in2.close();
        }
        catch (std::exception& e)
        {
            // Other errors
            std::cout << "Error :" << e.what() << std::endl;
        }
        Refresh();
    }
}


void MyFrame3::OnAdd_Operation(wxCommandEvent& event)
{

    auto new_operation = new My_new_Operation_dialog(this, wxID_ANY, "Test_Dialog");

    if (new_operation->ShowModal() == wxID_OK)
    {

        auto operation_dateOperation = new_operation->get_operation_dateOperation();
        auto operation_Montant = new_operation->get_operation_Montant();
        auto operation_Type = new_operation->get_operation_Type();
        auto operation_Emetteur = new_operation->get_operation_Emetteur();
        auto operation_Recepteur = new_operation->get_operation_Recepteur();
        auto operation_Motif = new_operation->get_operation_Motif();

        std::string dateOperation = std::string(operation_dateOperation);
        std::string Montant = std::string(operation_Montant);
        std::string Type = std::string(operation_Type);
        std::string Emetteur = std::string(operation_Emetteur);
        std::string Recepteur = std::string(operation_Recepteur);
        std::string Motif = std::string(operation_Motif);


        auto operations_numbers = std::stoi(dateOperation); // Only one at this time
        auto Lombre_compte = std::to_string(operations_numbers);
        wxMessageBox(wxT("Votre date d'opération est la suivante : ") + wxT(ombre_compte));



        Operation operation(operations_numbers, std::move(dateOperation), std::move(Montant), std::move(Type), std::move(Emetteur), std::move(Recepteur), std::move(Motif));
        operations_.push_back(operation);
        delete new_operation;

        ptree pt_write;
        ptree pt_accounts;
        try
        {

            std::ifstream file_in("example_write_read.json");
            read_json(file_in, pt_write);
            file_in.close();

            auto account = get_an_account(pt_write, this->nombre);

            pt_write = write_an_operation(pt_write, operation, account);

            std::ofstream file_out2("example_write_read.json");
            write_json(file_out2, pt_write);
            file_out2.close();

            std::ifstream file_in2("example_write_read.json");
            read_json(file_in2, pt_write);
            file_in2.close();
        }
        catch (std::exception& e)
        {
            // Other errors
            std::cout << "Error :" << e.what() << std::endl;
        }
        Refresh();
    }
}
