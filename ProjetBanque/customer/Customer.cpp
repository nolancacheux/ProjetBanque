#include "Customer.hpp"

Customer::Customer() {}

Customer::Customer(const int& nombre, 
    const int& banque,
    std::string&& nom,
    std::string&& prenom,
    std::string&& adresse,
    std::string&& mail,
    std::string&& telephone,
    std::string&& mot_de_passe,

    std::vector<int>&& comptes)
    :

    nombre_(nombre),
    banque_(banque),
    nom_(nom),
    prenom_(prenom),
    adresse_(adresse),
    mail_(mail),
    telephone_(telephone),
    mot_de_passe_(mot_de_passe),
    comptes_(comptes) {}

std::ostream& operator<<(std::ostream& os, const Customer& customer) {
    os << "Nombre " << customer.nombre_ << std::endl;
    os << "Banque " << customer.banque_ << std::endl;
    os << "Nom " << customer.nom_ << std::endl;
    os << "Prenom " << customer.prenom_ << std::endl;
    os << "Adresse " << customer.adresse_ << std::endl;
    os << "Mail " << customer.mail_ << std::endl;
    os << "Telephone " << customer.telephone_ << std::endl;
    os << "Mot de passe " << customer.mot_de_passe_ << std::endl;
    //os << "Nombre " << customer.nombre_ << std::endl;
    for (auto& compte : customer.comptes_) {
        std::cout << "Comptes : " << compte << std::endl;
    }
    return os;
}




Operation::Operation() {}

Operation::Operation(const int& nombre,
    std::string&& DateOperation,
    std::string&& montant,
    std::string&& type,
    std::string&& emetteur,
    std::string&& recepteur,
    std::string&& motif)
    :

    nombre_(nombre),
    DateOperation_(DateOperation),
    montant_(montant),
    type_(type),
    emetteur_(emetteur),
    recepteur_(recepteur),
    motif_(motif) {}

std::ostream& operator<<(std::ostream& os, const Operation& Operation) {
    os << "Nombre " << Operation.nombre_ << std::endl;
    os << "DateOperation " << Operation.DateOperation_ << std::endl;
    os << "montant_ " << Operation.montant_ << std::endl;
    os << "type_ " << Operation.type_ << std::endl;
    os << "emetteur_ " << Operation.emetteur_ << std::endl;
    os << "recepteur_ " << Operation.recepteur_ << std::endl;
    os << "motif_ " << Operation.motif_ << std::endl;
    return os;
}


Compte::Compte() {}

Compte::Compte(const int& nombre,
    std::string&& solde,
    std::string&& typeCompte,
    std::vector<int>&& operations)

    :
    nombre_(nombre),
    solde_(solde),
    typeCompte_(typeCompte),
    operations_(operations)
{}

std::ostream& operator<<(std::ostream& os, const Compte& Compte) {
    os << "Nombre " << Compte.nombre_ << std::endl;
    os << "Solde " << Compte.solde_ << std::endl;
    os << "TypeCompte " << Compte.typeCompte_ << std::endl;
    for (auto& operation : Compte.operations_) {
        std::cout << "Opérations : " << operation << std::endl;
    }
    return os;
}


/*
Compte::Compte() {}

Compte::Compte(const int& nombre,
    std::string&& solde,
    std::string&& typeCompte,
    ptree& operations)

    :
    nombre_(nombre),
    solde_(solde),
    typeCompte_(typeCompte),
    operations_(operations)
{}

std::ostream& operator<<(std::ostream& os, const Compte& Compte) {
    os << "Solde " << Compte.solde_ << std::endl;
    os << "TypeCompte " << Compte.typeCompte_ << std::endl;
    /*for (auto& operation : Compte.operations_) {
        std::cout << "Opérations : " << operation << std::endl;
    }*/
    /*return os;
}
*/