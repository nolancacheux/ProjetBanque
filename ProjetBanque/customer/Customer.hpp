#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;


#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>


struct Customer {
    Customer();
    Customer(const int& nombre, const int& banque, std::string&& nom, std::string&& prenom, std::string&& adresse, std::string&& mail, std::string&& telephone, std::string&& mot_de_passe, std::vector<int>&& comptes);
    int nombre_ = 0;
    int banque_ = 0;
    std::string nom_;
    std::string prenom_;
    std::string adresse_;
    std::string mail_;
    std::string telephone_;
    std::string mot_de_passe_;
    std::vector<int> comptes_;
    friend std::ostream& operator<<(std::ostream& os, const Customer& customer);
    template <class Archive>
    void serialize(Archive& ar, unsigned int version)
    {
        ar& nombre_& nom_& prenom_& adresse_& mail_& telephone_& mot_de_passe_& comptes_;
    }
};


struct Operation {
    Operation();
    Operation(const int& nombre, std::string&& DateOperation, std::string&& montant, std::string&& type, std::string&& emetteur, std::string&& recepteur, std::string&& motif);

    int nombre_ = 0;
    std::string DateOperation_;
    std::string montant_;
    std::string type_;
    std::string emetteur_;
    std::string recepteur_;
    std::string motif_;

    friend std::ostream& operator<<(std::ostream& os, const Operation& Operation);
    template <class Archive>
    void serialize(Archive& ar, unsigned int version)
    {
        ar& DateOperation_& montant_& type_& emetteur_& recepteur_& motif_& nombre_;
    }
};

struct Compte {
    Compte();
    Compte(const int& nombre, std::string&& solde, std::string&& typeCompte, std::vector<int>&& operations);
    int nombre_ = 0;
    std::string solde_;

    std::string typeCompte_;
    std::vector<int> operations_;

    friend std::ostream& operator<<(std::ostream& os, const Compte& Compte);
    template <class Archive>
    void serialize(Archive& ar, unsigned int version)
    {
        ar& solde_& typeCompte_& operations_& nombre_;
    }
};


/*
struct Compte {
    Compte();
    Compte(const int& nombre, std::string&& solde, std::string&& typeCompte, ptree & operations);
    int nombre_ = 0;
    std::string solde_;

    std::string typeCompte_;
    ptree operations_;

    friend std::ostream& operator<<(std::ostream& os, const Compte& Compte);
    template <class Archive>
    void serialize(Archive& ar, unsigned int version)
    {
        ar& solde_& typeCompte_& operations_& nombre_;
    }
};
*/
