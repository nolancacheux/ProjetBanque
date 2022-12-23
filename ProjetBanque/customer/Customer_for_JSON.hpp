#pragma once

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

#include "Customer.hpp"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

enum class Account_type
{
  Checking,
  Savings
};

struct Account
{
  int number;
  Account_type account_type;
};

ptree get_a_ptree_from_an_operation(const Operation& operation);

Operation get_an_operation_from_a_ptree(ptree& pt);

Compte get_an_account_from_a_ptree(ptree& pt);

ptree get_a_ptree_from_an_account(const Compte& account);

ptree get_a_ptree_from_a_customer(const Customer& customer);

Customer get_a_customer_from_a_ptree(ptree& pt);

Operation get_an_operation(ptree& pt_write, int nombre);

Compte get_an_account(ptree& pt_write, int nombre);

ptree edit_solde_of_an_account(ptree& pt_write, int nombre, int montant);

Customer get_a_customer(ptree& pt_write, int nombre);

ptree write_an_operation(ptree& pt_write, Operation op, Compte account);

ptree write_an_account(ptree& pt_write, Compte compte, Customer customers);

ptree write_a_customer(ptree& pt_write, Customer customers);

bool verif_operation_exists(ptree& pt_write, int nombre);

bool verif_account_exists(ptree& pt_write, int nombre);

bool verif_customer_exists(ptree& pt_write, int nombre, int banque);