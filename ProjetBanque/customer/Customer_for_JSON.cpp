#include "Customer_for_JSON.hpp"
#include <cmath>

//Compte compte1 = get_a_ptree_from_a_account(const Compte & compte)

ptree get_a_ptree_from_an_operation(const Operation& operation) {

    ptree pt;
    pt.put("Nombre", operation.nombre_);
    pt.put("DateOperation", operation.DateOperation_);
    pt.put("Montant", operation.montant_);
    pt.put("Type", operation.type_);
    pt.put("Emetteur", operation.emetteur_);
    pt.put("Recepteur", operation.recepteur_);
    pt.put("Motif", operation.motif_);
    return pt;
}


Operation get_an_operation_from_a_ptree(ptree& pt) {

    int nombre = pt.get<int>("Nombre", 0);

    std::string dateOperation = pt.get<std::string>("DateOperation");
    std::string montant = pt.get<std::string>("Montant");
    std::string type = pt.get<std::string>("Type");
    std::string emetteur = pt.get<std::string>("Emetteur");
    std::string recepteur = pt.get<std::string>("Recepteur");
    std::string motif = pt.get<std::string>("Motif");


    Operation op(nombre, std::move(dateOperation), std::move(montant), std::move(type), std::move(emetteur), std::move(recepteur), std::move(motif));

    return op;
}


ptree get_a_ptree_from_an_account(const Compte& account) {
    ptree pt;
    ptree operations;

    pt.put("Nombre", account.nombre_);
    pt.put("Solde", account.solde_);
    pt.put("TypeCompte", account.typeCompte_);
    for (auto& operation : account.operations_) {
        ptree dummy_tree;
        //   dummy_tree.put(account_number.first, account_number.second);
        dummy_tree.put_value(operation);
        operations.push_back({ "", dummy_tree });
    }
    pt.add_child("Operations", operations);
    return pt;
}


Compte get_an_account_from_a_ptree(ptree& pt) {

    int nombre = pt.get<int>("Nombre", 0);

    std::string solde = pt.get<std::string>("Solde");
    std::string typeCompte = pt.get<std::string>("TypeCompte");
    std::vector<int> operations;

    for (ptree::value_type& operation : pt.get_child("Operations")) {
        operations.push_back(operation.second.get_value<int>());
    }

    Compte compte(nombre, std::move(solde), std::move(typeCompte), std::move(operations));
    return compte;
}

ptree get_a_ptree_from_a_customer(const Customer& customer) {
    ptree pt;
    ptree numero_de_comptes;

    pt.put("Nombre", customer.nombre_);
    pt.put("Banque", customer.banque_);
    pt.put("Nom", customer.nom_);
    pt.put("Prenom", customer.prenom_);
    pt.put("Adresse", customer.adresse_);
    pt.put("Mail", customer.mail_);
    pt.put("Telephone", customer.telephone_);
    pt.put("Mot_de_passe", customer.mot_de_passe_);
    for (auto& numero_de_compte : customer.comptes_) {
        ptree dummy_tree;
        //   dummy_tree.put(account_number.first, account_number.second);
        dummy_tree.put_value(numero_de_compte);
        numero_de_comptes.push_back({ "", dummy_tree });
    }
    pt.add_child("Comptes", numero_de_comptes);
    return pt;
}


Customer get_a_customer_from_a_ptree(ptree& pt) {

    int nombre = pt.get<int>("Nombre", 0);
    int banque = pt.get<int>("Banque", 0);
    std::string nom = pt.get<std::string>("Nom");
    std::string prenom = pt.get<std::string>("Prenom");
    std::string adresse = pt.get<std::string>("Adresse");
    std::string mail = pt.get<std::string>("Mail");
    std::string telephone = pt.get<std::string>("Telephone");
    std::string mot_de_passe = pt.get<std::string>("Mot_de_passe");
    std::vector<int> comptes;

    for (ptree::value_type& compte : pt.get_child("Comptes")) {
        comptes.push_back(compte.second.get_value<int>());
    }

    Customer customer(nombre, banque, std::move(nom), std::move(prenom), std::move(adresse), std::move(mail), std::move(telephone), std::move(mot_de_passe), std::move(comptes));
    return customer;
}


bool verif_operation_exists(ptree& pt_write, int nombre) {

    Operation retour;
    try {

        for (ptree::value_type& operation : pt_write.get_child("Customers").get_child("Comptes").get_child("Operations")) {
            auto custom = get_an_operation_from_a_ptree(operation.second);

            if (custom.nombre_ == nombre) { retour = custom; return 1; }
        }

    }

    catch (std::exception& e) {
        // Other errors
    }
    return 0;
}


bool verif_account_exists(ptree& pt_write, int nombre) {

    Compte retour;
    try {

        for (ptree::value_type& Compte : pt_write.get_child("Customers").get_child("Comptes")) {
            auto custom2 = get_an_account_from_a_ptree(Compte.second);
            if (custom2.nombre_ == nombre) { retour = custom2; return 1; }
        }

    }
    catch (std::exception& e) {
        // Other errors
    }
    return 0;
}

bool verif_customer_exists(ptree& pt_write, int nombre, int banque) {

    Customer retour;
    try {

        for (ptree::value_type& customer : pt_write.get_child("Customers")) {
            auto custom3 = get_a_customer_from_a_ptree(customer.second);
            std::cout << custom3 << std::endl;
            if ((custom3.nombre_ == nombre) && (custom3.banque_ == banque)) { retour = custom3; return 1; }
        }

    }
    catch (std::exception& e) {
        // Other errors

    }
    return 0;

}


Operation get_an_operation(ptree& pt_write, int nombre) {

    Operation retour;
    try {

        for (ptree::value_type& operation : pt_write.get_child("Customers").get_child("Comptes").get_child("Operations")) {
            auto custom = get_an_operation_from_a_ptree(operation.second);

            if (custom.nombre_ == nombre) { retour = custom; }
        }

    }

    catch (std::exception& e) {
        // Other errors
        std::cout << "Cette opération n'existe pas frérot" << std::endl;
    }
    return retour;
}


Compte get_an_account(ptree& pt_write, int nombre) {

    Compte retour;
    try {

        for (ptree::value_type& Compte : pt_write.get_child("Customers").get_child("Comptes")) {
            auto custom2 = get_an_account_from_a_ptree(Compte.second);
            if (custom2.nombre_ == nombre) { retour = custom2; }
        }

    }
    catch (std::exception& e) {
        // Other errors
        std::cout << "Ce compte n'existe pas frérot" << std::endl;
    }
    return retour;
}



ptree edit_solde_of_an_account(ptree& pt_write, int nombre, int montant) {

    try {
        /* for (ptree::value_type& compt : pt_write.get_child("Customers").get_child("Comptes")) {
             compt.second.push_back({ std::to_string(compte.nombre_), get_a_ptree_from_an_account(compte) });
         }*/

        float old_montant = pt_write.get_child("Customers").get_child("Comptes").get_child(std::to_string(nombre)).get<float>("Solde", 0);

        float nouveau_montant = old_montant + montant;

        pt_write.get_child("Customers").get_child("Comptes").get_child(std::to_string(nombre)).put("Solde", nouveau_montant);;

        auto pt = pt_write.get_child("Customers").get_child("Comptes").get_child("Operations");

        pt_write.get_child("Customers").get_child("Comptes").erase("Operations");

        pt_write.get_child("Customers").get_child("Comptes").put_child("Operations", pt);

    }
    catch (std::exception& e) {
        // Other errors
    }
    return pt_write;
}

ptree edit_solde_of_all_account_interets(ptree& pt_write, int annees) {

    try {
        /* for (ptree::value_type& compt : pt_write.get_child("Customers").get_child("Comptes")) {
             compt.second.push_back({ std::to_string(compte.nombre_), get_a_ptree_from_an_account(compte) });
         }*/

        auto nbrcomptes = get_all_nbcompte(pt_write);

        int n = 12;
        annees *= n;

        //n est le nombre de fois où les intérêts sont composés par période de temps 
        //Géneralement dans une banque , les intérets sont composes mensuellement donc n = 12;

        for (auto i = nbrcomptes.begin(); i != nbrcomptes.end(); ++i) {
            //std::cout << *i << std::endl;


            float old_montant = pt_write.get_child("Customers").get_child("Comptes").get_child(std::to_string(*i)).get<float>("Solde", 0);

            std::string interet = pt_write.get_child("Customers").get_child("Comptes").get_child(std::to_string(*i)).get<std::string>("TypeCompte");

            //std::cout << interet << std::endl;

            float nouveau_montant = old_montant;

            float multby = 1;

            // FUTUR MONTANT : P(1 + r / n) ^ (nt), où P est le solde initial du capital, r est le taux d’intérêt, n est le nombre de fois où les intérêts sont composés par période de temps

            if (interet == "Livret A (Interet : 3%)") {

                for (int i = 0; i < annees; i++) {
                    multby *= (1 + 0.03 / n);
                }
                nouveau_montant = old_montant * multby;
                std::cout << "Livret A (Interet : 3%)" << " - Ancien Montant :" << old_montant << " - Nouveau Montant :" << nouveau_montant << std::endl;
            }
            else {
                if (interet == "PEA (Interet : 15%)") {
                    for (int i = 0; i < annees; i++) {
                        multby *= (1 + 0.15 / n);
                    }
                    nouveau_montant = old_montant * multby;
                    std::cout << "PEA (Interet : 15%)" << " - Ancien Montant :" << old_montant << " - Nouveau Montant :" << nouveau_montant << std::endl;
                }
            }
            float rounded = round(nouveau_montant * 100) / 100;

            pt_write.get_child("Customers").get_child("Comptes").get_child(std::to_string(*i)).put("Solde", rounded);

            auto pt = pt_write.get_child("Customers").get_child("Comptes").get_child("Operations");

            pt_write.get_child("Customers").get_child("Comptes").erase("Operations");

            pt_write.get_child("Customers").get_child("Comptes").put_child("Operations", pt);
        }

    }
    catch (std::exception& e) {
        // Other errors
    }
    return pt_write;
}


Customer get_a_customer(ptree& pt_write, int nombre) {

    Customer retour;
    try {

        for (ptree::value_type& customer : pt_write.get_child("Customers")) {
            auto custom3 = get_a_customer_from_a_ptree(customer.second);
            std::cout << custom3 << std::endl;
            if (custom3.nombre_ == nombre) { retour = custom3; }
        }

    }
    catch (std::exception& e) {
        // Other errors
        std::cout << "Ce client n'existe pas frérot" << std::endl;
    }
    return retour;

}


ptree write_an_operation(ptree& pt_write, Operation op, Compte account) {
    try {

        /*for (ptree::value_type& operation : pt_write.get_child("Customers").get_child("Comptes").get_child("Operations")) {
            operation.second.push_back({ std::to_string(op.nombre_), get_a_ptree_from_an_operation(op) });

        }*/

        pt_write.get_child("Customers").get_child("Comptes").get_child("Operations").put_child(std::to_string(op.nombre_), get_a_ptree_from_an_operation(op));

        //ptree arbre = pt_write.get_child("Customers").get_child("Comptes").get_child(std::to_string(account.nombre_));
        //std::vector<int> vecteur = arbre.get<std::vector<int>>("Operations");
        //vecteur.push_back(op.nombre_);


        for (ptree::value_type& compte : pt_write.get_child("Customers").get_child("Comptes")) {
            auto custom2 = get_an_account_from_a_ptree(compte.second);
            if (custom2.nombre_ == account.nombre_) {
                custom2.operations_.push_back(op.nombre_);
                pt_write.get_child("Customers").get_child("Comptes").put_child(std::to_string(account.nombre_), get_a_ptree_from_an_account(custom2));
            }
            //ptree retour = get_a_ptree_from_an_account(custom2);

        }
    }
    catch (std::exception& e) {
        // Other errors
    }
    return pt_write;

}
ptree write_an_account(ptree& pt_write, Compte compte, Customer customers) {
    try {

        /* for (ptree::value_type& compt : pt_write.get_child("Customers").get_child("Comptes")) {
             compt.second.push_back({ std::to_string(compte.nombre_), get_a_ptree_from_an_account(compte) });
         }*/
        pt_write.get_child("Customers").get_child("Comptes").put_child(std::to_string(compte.nombre_), get_a_ptree_from_an_account(compte));

        auto pt = pt_write.get_child("Customers").get_child("Comptes").get_child("Operations");

        pt_write.get_child("Customers").get_child("Comptes").erase("Operations");

        pt_write.get_child("Customers").get_child("Comptes").put_child("Operations", pt);

        for (ptree::value_type& customer : pt_write.get_child("Customers")) {
            auto custom2 = get_a_customer_from_a_ptree(customer.second);
            custom2.comptes_.push_back(compte.nombre_);
            if (custom2.nombre_ == customers.nombre_) {
                pt_write.get_child("Customers").put_child(std::to_string(customers.nombre_), get_a_ptree_from_a_customer(custom2));

            }
        }

    }
    catch (std::exception& e) {
        // Other errors
    }
    return pt_write;

}
ptree write_a_customer(ptree& pt_write, Customer customers) {

    try {

        /*for (ptree::value_type& customer : pt_write.get_child("Customers")) {
            customer.second.push_back({ std::to_string(customers.nombre_), get_a_ptree_from_a_customer(customers) });
        }*/



        pt_write.get_child("Customers").put_child(std::to_string(customers.nombre_), get_a_ptree_from_a_customer(customers));

        auto pt = pt_write.get_child("Customers").get_child("Comptes");

        pt_write.get_child("Customers").erase("Comptes");

        pt_write.get_child("Customers").put_child("Comptes", pt);

    }
    catch (std::exception& e) {
        // Other errors
    }
    return pt_write;
}

std::vector <Operation> get_all_operations(ptree& pt_write) {
    std::vector<Operation> retour;
    try {

        for (ptree::value_type& operation : pt_write.get_child("Customers").get_child("Comptes").get_child("Operations")) {
            auto custom2 = get_an_operation_from_a_ptree(operation.second);
            retour.push_back(custom2);
            //std::cout << custom2;
        }

    }
    catch (std::exception& e) {
        // Other errors
        std::cout << "pas d'ope" << std::endl;
    }
    return retour;
}

std::vector <Compte> get_all_accounts(ptree& pt_write) {
    // ON S'EN FOU DE CELLE LA
    std::vector<Compte> retour;
    try {

        for (ptree::value_type& operation : pt_write.get_child("Customers").get_child("Comptes")) {

            //std::cout << operation.first;
            auto custom2 = get_an_account_from_a_ptree(operation.second);
            retour.push_back(custom2);
            //std::cout << custom2;
        }
    }
    catch (std::exception& e) {
        // Other errors
        std::cout << "pas d'ope" << std::endl;
    }
    return retour;
}

std::vector <int> get_all_nbcompte(ptree& pt_write) {
    std::vector<int> retour;
    try {

        for (ptree::value_type& operation : pt_write.get_child("Customers").get_child("Comptes")) {
            auto custom2 = get_an_account_from_a_ptree(operation.second);
            retour.push_back(custom2.nombre_);
            //std::cout << custom2;
        }

    }
    catch (std::exception& e) {
        // Other errors
        std::cout << e.what() << std::endl;
    }
    return retour;
}
