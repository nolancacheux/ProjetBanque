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
    MyFrame0* frame0 = new MyFrame0();
    // SetTopWindow(frame);
    frame0->Show(true);
    return true;
}
MyFrame0::MyFrame0()
    : wxFrame(nullptr, wxID_ANY, "Bank Agency", wxPoint(30, 30), wxSize(800, 600))
{

    SetBackgroundColour(wxColour(32, 32, 32));


    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to Bank agency!");


    wxPanel* panel = new wxPanel(this);
    wxButton* bank1 = new wxButton(panel, 5, "Bank no.1", wxPoint(290, 100), wxSize(160, 50));
    bank1->Bind(wxEVT_BUTTON, &MyFrame0::OnChoix1, this);
    design_bouton(bank1);

    wxButton* bank2 = new wxButton(panel, 6, "Bank no.2", wxPoint(290, 175), wxSize(160, 50));
    bank2->Bind(wxEVT_BUTTON, &MyFrame0::OnChoix2, this);
    design_bouton(bank2);

    wxButton* bank3 = new wxButton(panel, 7, "Bank no.3", wxPoint(290, 250), wxSize(160, 50));
    bank3->Bind(wxEVT_BUTTON, &MyFrame0::OnChoix3, this);
    design_bouton(bank3);

    wxButton* bank4 = new wxButton(panel, 8, "Bank no.4", wxPoint(290, 325), wxSize(160, 50));
    bank4->Bind(wxEVT_BUTTON, &MyFrame0::OnChoix4, this);
    design_bouton(bank4);

    wxStaticText* text = new wxStaticText(panel, wxID_ANY, " Bank management system", wxPoint(225, 50));
    design_grandtitre(text);

    wxButton* interet = new wxButton(panel, 9, "Time Simulation - Interests", wxPoint(250, 400), wxSize(250, 35));
    interet->Bind(wxEVT_BUTTON, &MyFrame0::OnInterets, this);
    interet->SetBackgroundColour(wxColour(62, 62, 62));
    interet->SetForegroundColour(*wxWHITE);
    wxFont fond = interet->GetFont();
    //fond.SetPointSize(20);
    fond.SetFaceName("Verdana");
    interet->SetFont(fond);
}


int banque = 0;

void MyFrame0::OnChoix1(wxCommandEvent& event) {
    banque = 1;
    MyFrame* frame = new MyFrame(banque);
    frame->Show(true);
    Close(true);
}
void MyFrame0::OnChoix2(wxCommandEvent& event) {
    banque = 2;
    MyFrame* frame = new MyFrame(banque);
    frame->Show(true);
    Close(true);
}
void MyFrame0::OnChoix3(wxCommandEvent& event) {
    banque = 3;
    MyFrame* frame = new MyFrame(banque);
    frame->Show(true);
    Close(true);
}
void MyFrame0::OnChoix4(wxCommandEvent& event) {
    banque = 4;
    MyFrame* frame = new MyFrame(banque);
    frame->Show(true);
    Close(true);
}



MyFrame::MyFrame(int banque)
    : wxFrame(nullptr, wxID_ANY, "Bank Agency", wxPoint(30, 30), wxSize(800, 600))
{
    this->banque = banque;
    SetBackgroundColour(wxColour(32, 32, 32));
    /*switch (banque) {
        case 1 :
            SetBackgroundColour(wxColour(60, 151, 105));
            break;
        case 2:
            SetBackgroundColour(wxColour(89, 60, 151));
            break;
        case 3:
            SetBackgroundColour(wxColour(172, 40, 40));
            break;
        case 4:
            SetBackgroundColour(wxColour(122, 113, 89));
            break;
        default:
            SetBackgroundColour(wxColour(51, 65, 94));
            break;
    }*/

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to Bank agency!");

    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);/*
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MyFrame::OnSaveCustomers, this, static_cast<int>(My_class_client::ID_Customers_save));*/

    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, 5, "Log in", wxPoint(340, 250), wxSize(130, 35));
    button->Bind(wxEVT_BUTTON, &MyFrame::OnConnexion, this);
    design_petit_bouton(button);

    wxButton* button2 = new wxButton(panel, 6, "Sign up", wxPoint(340, 70), wxSize(140, 35));
    button2->Bind(wxEVT_BUTTON, &MyFrame::OnAdd_Customer, this);
    design_petit_bouton(button2);

    // wxButton* button2 = new wxButton(panel, 5, "Inscription", wxPoint(340, 140), wxSize(100, 35));


    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Welcome to the Bank No." + std::to_string(this->banque) + " ! ", wxPoint(250, 10));

    wxStaticText* Account = new wxStaticText(panel, wxID_ANY, "Client Numbers : ", wxPoint(275, 180), wxSize(180, -1));
    wxStaticText* password = new wxStaticText(panel, wxID_ANY, "Password : ", wxPoint(275, 210), wxSize(180, -1));

    design_grandtitre(text);
    design_texte(Account);
    design_texte(password);

    account_numbers = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(405, 180), wxSize(120, -1));
    password_ = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(405, 210), wxSize(120, -1), wxTE_PASSWORD);


    wxButton* Back = new wxButton(panel, 7, "Back", wxPoint(350, 310), wxSize(110, 35));
    Back->Bind(wxEVT_BUTTON, &MyFrame::Back, this);
    design_petit_bouton(Back);

    wxStaticText* text2 = new wxStaticText(panel, wxID_ANY, " OR ", wxPoint(390, 130));
    design_grandtitre(text2);

}

void MyFrame::Back(wxCommandEvent& event) {
    MyFrame0* frame = new MyFrame0();
    // SetTopWindow(frame);
    frame->Show(true);
    Close(true);

}

int client = 0;
void MyFrame::OnConnexion(wxCommandEvent& event) {
    connexion = true;
    if (connexion == true) {

        numero.Append(account_numbers->GetValue());
        // wxMessageBox(numero);

        ptree pt_write;
        std::ifstream file_in("data.json");
        read_json(file_in, pt_write);
        file_in.close();

        int nbr = atoi(numero);

        if ((verif_customer_exists(pt_write, nbr, banque) == 1) && (verif_password_customer(pt_write, nbr, password_->GetValue().ToStdString()) == 1)) {
            client = nbr;
            MyFrame2* frame2 = new MyFrame2(nbr);
            frame2->Show(true);
            Close(true);
        }
        else {
            if (verif_customer_exists(pt_write, nbr, banque) == 1) {
                wxMessageBox("The password you entered is incorrect, please try again");
            }
            else {
                wxMessageBox("This number does not exist in our data");
                numero = " ";
            }
            //auto Lombre_compte = std::to_string(nbr);
            //wxMessageBox(wxT("Votre numéro de client est le suivant : ") + wxT(ombre_compte));
        }

    }
}

MyFrame2::MyFrame2(int nbr)
    : wxFrame(nullptr, wxID_ANY, "Bank Agency", wxPoint(30, 30), wxSize(800, 600))
{

    SetBackgroundColour(wxColour(32, 32, 32));
    this->nombre = nbr;

    wxMenu* menuHelp2 = new wxMenu;
    menuHelp2->Append(wxID_ABOUT);

    wxMenuBar* menuBar2 = new wxMenuBar;
    menuBar2->Append(menuHelp2, "&Help");

    SetMenuBar(menuBar2);

    CreateStatusBar();
    SetStatusText("Welcome to Bank agency!");


    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, 10, "VIEW", wxPoint(470, 330), wxSize(100, 35));
    design_petit_bouton(button);
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Your information :", wxPoint(10, 20), wxSize(250, 50));
    design_grandtitre(text);


    wxStaticText* text0 = new wxStaticText(panel, wxID_ANY, "Manage your accounts :", wxPoint(400, 20), wxSize(250, 50));
    design_grandtitre(text0);

    wxButton* button2 = new wxButton(panel, 5, "Create a new account", wxPoint(420, 80), wxSize(200, 35));
    button2->Bind(wxEVT_BUTTON, &MyFrame2::OnAdd_Account, this);
    design_petit_bouton(button2);

    wxStaticText* text2 = new wxStaticText(panel, wxID_ANY, " OR ", wxPoint(490, 130));
    design_grandtitre(text2);


    wxButton* button3 = new wxButton(panel, 6, "Transfer to", wxPoint(470, 180), wxSize(100, 35));
    button3->Bind(wxEVT_BUTTON, &MyFrame2::OnVirement, this);
    design_petit_bouton(button3);

    wxStaticText* text3 = new wxStaticText(panel, wxID_ANY, " OR ", wxPoint(490, 230));
    design_grandtitre(text3);

    wxStaticText* Account = new wxStaticText(panel, wxID_ANY, "Account Number : ", wxPoint(400, 282), wxSize(180, -1));
    account_numbers = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(540, 280), wxSize(120, -1));
    design_texte(Account);

    ptree pt_write;
    std::ifstream file_in("data.json");
    read_json(file_in, pt_write);
    file_in.close();

    //auto L = std::to_string(nbr);
    //wxMessageBox(wxT());

    Customer clientvalue = get_a_customer(pt_write, nbr);

    wxStaticText* nom = new wxStaticText(panel, -1, "Name : ", wxPoint(10, 70), wxSize(250, 50));
    wxStaticText* nom_ = new wxStaticText(panel, -1, clientvalue.nom_, wxPoint(30, 100), wxSize(180, 20));

    design_titre(nom); design_texte(nom_);

    wxStaticText* prenom = new wxStaticText(panel, -1, "First name : ", wxPoint(10, 130), wxSize(180, 20));
    wxStaticText* prenom_ = new wxStaticText(panel, -1, clientvalue.prenom_, wxPoint(30, 160), wxSize(180, 20));
    design_titre(prenom); design_texte(prenom_);

    wxStaticText* adresse = new wxStaticText(panel, -1, "Address : ", wxPoint(10, 190), wxSize(180, 20));
    wxStaticText* adresse_ = new wxStaticText(panel, -1, clientvalue.adresse_, wxPoint(30, 220), wxSize(180, 20));
    design_titre(adresse); design_texte(adresse_);

    wxStaticText* mail = new wxStaticText(panel, -1, "Mail : ", wxPoint(10, 250), wxSize(180, 20));
    wxStaticText* mail_ = new wxStaticText(panel, -1, clientvalue.mail_, wxPoint(30, 280), wxSize(180, 20));
    design_titre(mail); design_texte(mail_);

    wxStaticText* telephone = new wxStaticText(panel, -1, "Phone Number : ", wxPoint(10, 310), wxSize(180, 20));
    wxStaticText* telephone_ = new wxStaticText(panel, -1, clientvalue.telephone_, wxPoint(30, 340), wxSize(180, 20));
    design_titre(telephone); design_texte(telephone_);

    std::stringstream ss;
    copy(clientvalue.comptes_.begin(), clientvalue.comptes_.end(), ostream_iterator<int>(ss, " - "));
    string s = ss.str();
    s = s.substr(0, s.length() - 1);

    wxStaticText* compte = new wxStaticText(panel, -1, "Account Numbers : ", wxPoint(10, 370), wxSize(180, 20));
    wxStaticText* compte_ = new wxStaticText(panel, -1, s, wxPoint(30, 400), wxSize(180, 100));
    design_titre(compte); design_texte(compte_);



    Bind(wxEVT_BUTTON, &MyFrame2::OnConnexion2, this, 10);


    wxButton* Back = new wxButton(panel, 7, "Back", wxPoint(240, 430), wxSize(100, 35));
    Back->Bind(wxEVT_BUTTON, &MyFrame2::Back, this);
    design_petit_bouton(Back);


}

void MyFrame2::Back(wxCommandEvent& event) {
    MyFrame* frame = new MyFrame(banque);
    // SetTopWindow(frame);
    frame->Show(true);
    Close(true);

}

int compte = 0;
void MyFrame2::OnConnexion2(wxCommandEvent& event) {
    connexion2 = true;
    if (connexion2 == true) {

        numero.Append(account_numbers->GetValue());
        // wxMessageBox(numero);

        ptree pt_write;
        std::ifstream file_in("data.json");
        read_json(file_in, pt_write);
        file_in.close();

        int nbr = atoi(numero);

        if (verif_account_exists(pt_write, nbr) == 1) {
            compte = nbr;
            MyFrame3* frame3 = new MyFrame3(nbr);
            frame3->Show(true);
            Close(true);
        }
        else {


            wxMessageBox("Ce numéro n'existe pas dans nos données");
            numero = " ";

            /* auto Lombre_compte = std::to_string(nbr);
             wxMessageBox(wxT("Votre numéro de client est le suivant : ") + wxT(ombre_compte));*/

        }

    }
}

void MyFrame2::OnVirement(wxCommandEvent& event) {

    auto new_account = new My_virement_dialog(this, wxID_ANY, "Test_Dialog");

    if (new_account->ShowModal() == wxID_OK)
    {
        auto virement_emetteur = new_account->get_virement_emetteur();
        auto virement_recepteur = new_account->get_virement_recepteur();
        auto virement_montant = new_account->get_virement_montant();

        std::string emetteur = std::string(virement_emetteur);
        std::string recepteur = std::string(virement_recepteur);
        std::string montant = std::string(virement_montant);
        //long account_numbers; // Only one at this time

        //srand(time(NULL));
        //auto account_numbers = rand(); // Only one at this time
        //auto Lombre_compte = std::to_string(account_numbers);
        ////wxMessageBox(wxT("Votre numéro de compte est le suivant : ") + wxT(ombre_compte));

        /*Compte account(account_numbers, std::move(solde), std::move(typeCompte), {});
        accounts_.push_back(account);
        delete new_account;*/

        int compte_emetteur = std::stoi(emetteur);
        int compte_recepteur = std::stoi(recepteur);
        int compte_montant = std::stoi(montant);

        ptree pt_write;
        ptree pt_accounts;
        try
        {

            std::ifstream file_in("data.json");
            read_json(file_in, pt_write);
            file_in.close();

            if ((verif_account_exists(pt_write, compte_emetteur) == 1) && (verif_account_exists(pt_write, compte_recepteur) == 1)) {

                pt_write = edit_solde_of_an_account(pt_write, compte_emetteur, -compte_montant); // On soustrait à l'émetteur le montant d'où le signe - 
                pt_write = edit_solde_of_an_account(pt_write, compte_recepteur, compte_montant); // On ajoute au recepteur le montant

                //On ajoute ces opérations dans chacun des comptes


                //Operation operation(operations_numbers, std::move(dateOperation), std::move(Montant), std::move(Type), std::move(Emetteur), std::move(Recepteur), std::move(Motif));

                srand(time(NULL));
                int num = rand();

                Operation operation1(num,
                    "23/12/2022",
                    std::move(std::to_string(compte_montant)),
                    "Transfer ",
                    std::move(std::to_string(compte_emetteur)),
                    std::move(std::to_string(compte_recepteur)),
                    "Money sent from our account");

                srand(time(NULL));
                int num2 = rand();

                Operation operation2(num2,
                    "23/12/2022",
                    std::move(std::to_string(compte_montant)),
                    "Transfer",
                    std::move(std::to_string(compte_emetteur)),
                    std::move(std::to_string(compte_recepteur)),
                    "Money received to our account");

                pt_write = write_an_operation(pt_write, operation1, get_an_account(pt_write, compte_emetteur));
                pt_write = write_an_operation(pt_write, operation2, get_an_account(pt_write, compte_recepteur));

                std::ofstream file_out2("data.json");
                write_json(file_out2, pt_write);
                file_out2.close();

                std::ifstream file_in2("data.json");
                read_json(file_in2, pt_write);
                file_in2.close();


                auto Lcompte = std::to_string(compte_emetteur);
                auto Lcompte2 = std::to_string(compte_recepteur);
                auto Lmontant = std::to_string(compte_montant);

                wxMessageBox(wxT("Transfer of an amount of ") + wxT(montant) + wxT(" euros from your account no.") + wxT(compte) + wxT(" to account no.") + wxT(compte2) + wxT(" successfully completed"));
            }
            else {

                if (verif_account_exists(pt_write, compte_emetteur) == 1) {
                    wxMessageBox("The receiver account number does not exist in our data, please try again by changing the receiver number");
                    numero = " ";
                }
                else {
                    wxMessageBox("Your transmitter account number does not exist in our data, please try again with another number or create an account");
                    numero = " ";
                }
            }


            MyFrame2* frame2 = new MyFrame2(this->nombre);
            // SetTopWindow(frame);
            frame2->Show(true);
            Close(true);

        }
        catch (std::exception& e)
        {
            // Other errors
            std::cout << "Error :" << e.what() << std::endl;
        }
    }
}



MyFrame3::MyFrame3(int nbr)
    : wxFrame(nullptr, wxID_ANY, "Bank Agency", wxPoint(30, 30), wxSize(800, 600))
{
    SetBackgroundColour(wxColour(32, 32, 32));
    this->nombre = nbr;

    wxMenu* menuHelp2 = new wxMenu;
    menuHelp2->Append(wxID_ABOUT);

    wxMenuBar* menuBar2 = new wxMenuBar;
    menuBar2->Append(menuHelp2, "&Help");

    SetMenuBar(menuBar2);

    CreateStatusBar();
    SetStatusText("Welcome to Bank agency!");


    wxPanel* panel = new wxPanel(this);

    wxButton* button = new wxButton(panel, 10, "VIEW", wxPoint(470, 230), wxSize(100, 35));
    design_petit_bouton(button);
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Your account information:", wxPoint(10, 20), wxSize(250, 50));
    design_grandtitre(text);
    wxStaticText* text0 = new wxStaticText(panel, wxID_ANY, "Manage your operations :", wxPoint(400, 20), wxSize(250, 50));
    design_grandtitre(text0);

    text->SetForegroundColour(wxColour(255, 255, 255));

    wxButton* button3 = new wxButton(panel, 6, "New Operation", wxPoint(470, 80), wxSize(130, 35));
    button3->Bind(wxEVT_BUTTON, &MyFrame3::OnAdd_Operation, this);
    design_petit_bouton(button3);

    wxStaticText* text3 = new wxStaticText(panel, wxID_ANY, " OR ", wxPoint(500, 130));
    design_grandtitre(text3);

    wxStaticText* Account = new wxStaticText(panel, wxID_ANY, "Operation Number : ", wxPoint(395, 182), wxSize(180, -1));
    account_numbers = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(540, 180), wxSize(120, -1));
    design_texte(Account);
    Account->SetForegroundColour(wxColour(255, 255, 255));

    ptree pt_write;
    std::ifstream file_in("data.json");
    read_json(file_in, pt_write);
    file_in.close();



    Compte Valuecompte = get_an_account(pt_write, nbr);
    //wxStaticText* numero = new wxStaticText(panel, -1, "Numero de compte : ", wxPoint(10, 20), wxSize(250, 20));
    //wxStaticText* numero_ = new wxStaticText(panel, -1, Valuecompte.nombre_, wxPoint(30, 40), wxSize(180, 20));
    wxStaticText* solde = new wxStaticText(panel, -1, "Amount : ", wxPoint(10, 70), wxSize(250, 50));
    wxStaticText* solde_ = new wxStaticText(panel, -1, Valuecompte.solde_, wxPoint(30, 100), wxSize(180, 20));
    wxStaticText* type = new wxStaticText(panel, -1, "Type : ", wxPoint(10, 130), wxSize(180, 20));
    wxStaticText* type_ = new wxStaticText(panel, -1, Valuecompte.typeCompte_, wxPoint(30, 160), wxSize(180, 20));

    design_titre(solde); design_texte(solde_);
    design_titre(type); design_texte(type_);

    wxStaticText* ope = new wxStaticText(panel, -1, "Operations : ", wxPoint(10, 190), wxSize(180, 20));

    std::stringstream ss;
    copy(Valuecompte.operations_.begin(), Valuecompte.operations_.end(), ostream_iterator<int>(ss, " - "));
    string s = ss.str();
    s = s.substr(0, s.length() - 1);
    wxStaticText* ope_ = new wxStaticText(panel, -1, s, wxPoint(30, 220), wxSize(180, 100));
    ope->SetForegroundColour(wxColour(255, 255, 255));
    ope_->SetForegroundColour(wxColour(255, 255, 255));

    Bind(wxEVT_BUTTON, &MyFrame3::OnConnexion3, this, 10);

    design_titre(ope); design_texte(ope_);

    wxButton* Back = new wxButton(panel, 7, "Back", wxPoint(240, 330), wxSize(100, 35));
    Back->Bind(wxEVT_BUTTON, &MyFrame3::Back, this);
    design_petit_bouton(Back);
}

void MyFrame3::Back(wxCommandEvent& event) {
    Close(true);
    MyFrame2* frame2 = new MyFrame2(client);
    // SetTopWindow(frame);
    frame2->Show(true);
    /* auto Lombre_compte = std::to_string(client);
     wxMessageBox(wxT("Votre numéro de client est le suivant : ") + wxT(ombre_compte));*/
}

void MyFrame3::OnConnexion3(wxCommandEvent& event) {
    connexion3 = true;
    if (connexion3 == true) {

        numero.Append(account_numbers->GetValue());
        // wxMessageBox(numero);

        ptree pt_write;
        std::ifstream file_in("data.json");
        read_json(file_in, pt_write);
        file_in.close();

        int nbr = atoi(numero);

        if (verif_operation_exists(pt_write, nbr) == 1) {
            MyFrame4* frame4 = new MyFrame4(nbr);
            frame4->Show(true);
            Close(true);
        }
        else {

            wxMessageBox("Ce numéro n'existe pas dans nos données");
            numero = " ";

            /*auto Lombre_compte = std::to_string(nbr);
            wxMessageBox(wxT("Votre numéro de client est le suivant : ") + wxT(ombre_compte));*/
        }

    }
}


MyFrame4::MyFrame4(int nbr)
    : wxFrame(nullptr, wxID_ANY, "Bank Agency", wxPoint(30, 30), wxSize(800, 600))
{
    SetBackgroundColour(wxColour(32, 32, 32));
    this->nombre = nbr;
    wxPanel* panel = new wxPanel(this);
    ptree pt_write;
    std::ifstream file_in("data.json");
    read_json(file_in, pt_write);
    file_in.close();
    Operation Valueoperation = get_an_operation(pt_write, nbr);
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Operation Informations :", wxPoint(10, 20), wxSize(250, 50));
    design_grandtitre(text);

    wxButton* Back = new wxButton(panel, 7, "Back", wxPoint(240, 430), wxSize(100, 35));
    Back->Bind(wxEVT_BUTTON, &MyFrame4::Back, this);
    design_petit_bouton(Back);






    //wxStaticText* numero = new wxStaticText(panel, -1, "Numero operation : ", wxPoint(10, 20), wxSize(180, 20));
    //wxStaticText* numero_ = new wxStaticText(panel, -1, Valueoperation.nombre_, wxPoint(30, 40), wxSize(180, 20));
    wxStaticText* date = new wxStaticText(panel, -1, "Date of the operation : : ", wxPoint(10, 70), wxSize(250, 50));
    wxStaticText* date_ = new wxStaticText(panel, -1, Valueoperation.DateOperation_, wxPoint(30, 100), wxSize(180, 20));
    wxStaticText* montant = new wxStaticText(panel, -1, "Amount : ", wxPoint(10, 130), wxSize(180, 20));
    wxStaticText* montant_ = new wxStaticText(panel, -1, Valueoperation.montant_, wxPoint(30, 160), wxSize(180, 20));
    wxStaticText* type = new wxStaticText(panel, -1, "Type : ", wxPoint(10, 190), wxSize(180, 20));
    wxStaticText* type_ = new wxStaticText(panel, -1, Valueoperation.type_, wxPoint(30, 220), wxSize(180, 20));
    wxStaticText* emetteur = new wxStaticText(panel, -1, "Transmitter : ", wxPoint(10, 250), wxSize(180, 20));
    wxStaticText* emetteur_ = new wxStaticText(panel, -1, Valueoperation.emetteur_, wxPoint(30, 280), wxSize(180, 20));
    wxStaticText* recepteur = new wxStaticText(panel, -1, "Receiver : ", wxPoint(10, 310), wxSize(180, 20));
    wxStaticText* recepteur_ = new wxStaticText(panel, -1, Valueoperation.recepteur_, wxPoint(30, 340), wxSize(180, 20));
    wxStaticText* motif = new wxStaticText(panel, -1, "Pattern : ", wxPoint(10, 370), wxSize(180, 20));
    wxStaticText* motif_ = new wxStaticText(panel, -1, Valueoperation.motif_, wxPoint(30, 400), wxSize(180, 20));

    design_titre(date); design_texte(date_);
    design_titre(montant); design_texte(montant_);
    design_titre(type); design_texte(type_);
    design_titre(emetteur); design_texte(emetteur_);
    design_titre(recepteur); design_texte(recepteur_);
    design_titre(motif); design_texte(motif_);

}

void MyFrame4::Back(wxCommandEvent& event) {
    Close(true);
    MyFrame3* frame3 = new MyFrame3(compte);
    // SetTopWindow(frame);
    frame3->Show(true);
    /*auto Lombre_compte = std::to_string(compte);
    wxMessageBox(wxT("Votre numéro de compte est le suivant : ") + wxT(ombre_compte));*/
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

        srand(time(NULL));
        auto client_numbers = rand(); // Only one at this time
        auto Lombre_compte = std::to_string(client_numbers);
        wxMessageBox(wxT("Your customer number is  : ") + wxT(ombre_compte));


        Customer customer(client_numbers, this->banque, std::move(fisrtname), std::move(surnname), std::move(adress), std::move(mail), std::move(phone), std::move(password), {});
        customers_.push_back(customer);
        delete new_customer;

        ptree pt_write;
        ptree pt_accounts;
        try
        {

            std::ifstream file_in("data.json");
            read_json(file_in, pt_write);
            file_in.close();

            pt_write = write_a_customer(pt_write, customer);

            std::ofstream file_out2("data.json");
            write_json(file_out2, pt_write);
            file_out2.close();

            std::ifstream file_in2("data.json");
            read_json(file_in2, pt_write);
            file_in2.close();

            MyFrame* frame = new MyFrame(banque);
            // SetTopWindow(frame);
            frame->Show(true);
            Close(true);
        }
        catch (std::exception& e)
        {
            // Other errors
            std::cout << "Error :" << e.what() << std::endl;
        }
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

        srand(time(NULL));
        auto account_numbers = rand(); // Only one at this time
        auto Lombre_compte = std::to_string(account_numbers);
        wxMessageBox(wxT("Your account number is : ") + wxT(ombre_compte));

        Compte account(account_numbers, std::move(solde), std::move(typeCompte), {});
        accounts_.push_back(account);
        delete new_account;

        ptree pt_write;
        ptree pt_accounts;
        try
        {

            std::ifstream file_in("data.json");
            read_json(file_in, pt_write);
            file_in.close();

            auto custom = get_a_customer(pt_write, this->nombre);

            pt_write = write_an_account(pt_write, account, custom);

            std::ofstream file_out2("data.json");
            write_json(file_out2, pt_write);
            file_out2.close();

            std::ifstream file_in2("data.json");
            read_json(file_in2, pt_write);
            file_in2.close();



            MyFrame2* frame2 = new MyFrame2(this->nombre);
            // SetTopWindow(frame);
            frame2->Show(true);
            Close(true);

        }
        catch (std::exception& e)
        {
            // Other errors
            std::cout << "Error :" << e.what() << std::endl;
        }
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

        srand(time(NULL));
        auto operations_numbers = rand();; // Only one at this time
        auto Lombre_compte = std::to_string(operations_numbers);
        wxMessageBox(wxT("Your operation number is as follows : ") + wxT(ombre_compte));



        Operation operation(operations_numbers, std::move(dateOperation), std::move(Montant), std::move(Type), std::move(Emetteur), std::move(Recepteur), std::move(Motif));
        operations_.push_back(operation);
        delete new_operation;

        ptree pt_write;
        ptree pt_accounts;
        try
        {

            std::ifstream file_in("data.json");
            read_json(file_in, pt_write);
            file_in.close();

            auto account = get_an_account(pt_write, this->nombre);

            pt_write = write_an_operation(pt_write, operation, account);

            std::ofstream file_out2("data.json");
            write_json(file_out2, pt_write);
            file_out2.close();

            std::ifstream file_in2("data.json");
            read_json(file_in2, pt_write);
            file_in2.close();

            MyFrame3* frame3 = new MyFrame3(this->nombre);
            // SetTopWindow(frame);
            frame3->Show(true);
            Close(true);

        }
        catch (std::exception& e)
        {
            // Other errors
            std::cout << "Error :" << e.what() << std::endl;
        }
    }
}
void MyFrame0::OnInterets(wxCommandEvent& event)
{

    auto new_interet = new My_new_interet_dialog(this, wxID_ANY, "Test_Dialog");

    if (new_interet->ShowModal() == wxID_OK)
    {

        auto interets_annees = new_interet->get_interet_annees();
        int annees = wxAtoi(interets_annees);

        ptree pt_write;
        try
        {

            std::ifstream file_in("data.json");
            read_json(file_in, pt_write);
            file_in.close();

            pt_write = edit_solde_of_all_account_interets(pt_write, annees);

            std::ofstream file_out2("data.json");
            write_json(file_out2, pt_write);
            file_out2.close();

            std::ifstream file_in2("data.json");
            read_json(file_in2, pt_write);
            file_in2.close();



            MyFrame0* frame0 = new MyFrame0();
            // SetTopWindow(frame);
            frame0->Show(true);
            Close(true);

            wxMessageBox("Compound interest has been successfully applied to all your accounts");

        }
        catch (std::exception& e)
        {
            // Other errors
            std::cout << "Error :" << e.what() << std::endl;
            wxMessageBox(e.what());
        }
    }
}

