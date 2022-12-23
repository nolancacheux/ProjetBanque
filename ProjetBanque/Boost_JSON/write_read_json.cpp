#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif


#include "../customer/Customer_for_JSON.hpp"


using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;



int main(int argc, char** argv) {
    ptree pt_write;
    ptree pt_accounts;

    ptree pt_write2;
    ptree pt_accounts2;

    ptree pt_write3;
    ptree pt_accounts3; 

    try {


        Operation operation1(1001, "2019-01-01", "1000", "Versement", "123456789", "123456789", "mami virement");

        Operation operation2(1002, "2019-01-01", "1000", "Versement", "123456789", "123456789", "mami virement");


        pt_accounts3.push_back({ std::to_string(operation1.nombre_), get_a_ptree_from_an_operation(operation1) });
        pt_accounts3.push_back({ std::to_string(operation2.nombre_), get_a_ptree_from_an_operation(operation2) });
        pt_write3.add_child("Operations", pt_accounts3);

        /*std::ofstream file_out3("operations.json");
        write_json(file_out3, pt_write3);
        file_out3.close();

        std::ifstream file_in3("operations.json");
        read_json(file_in3, pt_write3);
        file_in3.close();

        for (ptree::value_type& operation : pt_write3.get_child("Operations")) {
            auto custom = get_an_operation_from_a_ptree(operation.second);

            std::cout << custom << std::endl;
        }
        */

        Compte Compte1(1001111, "1000", "PEA (Interet : 15%)", { operation1.nombre_ });

        Compte Compte2(1012111, "1001", "PEA (Interet : 15%)", { operation2.nombre_ });

        //Compte Compte2(1012, "1001", "Courant", pt_accounts3);


        pt_accounts2.push_back({ std::to_string(Compte1.nombre_), get_a_ptree_from_an_account(Compte1) });
        pt_accounts2.push_back({ std::to_string(Compte2.nombre_), get_a_ptree_from_an_account(Compte2) });
        pt_accounts2.push_back({ "Operations", pt_accounts3 });
        //pt_accounts2.add_child("Operations", pt_accounts3);
        pt_write2.add_child("Comptes", pt_accounts2);
        /*

        std::ofstream file_out2("account.json");
        write_json(file_out2, pt_write2);
        file_out2.close();

        std::ifstream file_in2("account.json");
        read_json(file_in2, pt_write2);
        file_in2.close();

        for (ptree::value_type& Compte : pt_write2.get_child("Comptes")) {
            auto custom = get_an_account_from_a_ptree(Compte.second);

            std::cout << custom << std::endl;
        }*/

        Customer customer1(100222221,1, "Montuori", "Milo", "1 rue de la liberte Paris", "milo.montuori@student.junia.com", "06 23 67 82 00", "1234567890",
            { Compte1.nombre_ });

        Customer customer2(100222222,1, "Hoste", "Matthieu", "1 rue de la liberte Paris", "matthieu.hoste@student.junia.com", "06 23 67 82 00", "0987654321",
            { Compte2.nombre_ });

        pt_accounts.push_back({ std::to_string(customer1.nombre_), get_a_ptree_from_a_customer(customer1) });
        pt_accounts.push_back({ std::to_string(customer2.nombre_), get_a_ptree_from_a_customer(customer2) });
        pt_accounts.add_child("Comptes", pt_accounts2);
        pt_write.add_child("Customers", pt_accounts);


        std::ofstream file_out("data.json");
        write_json(file_out, pt_write);
        file_out.close();

        std::ifstream file_in("data.json");
        read_json(file_in, pt_write);
        file_in.close();

        std::cout << get_an_operation(pt_write, 1001) << std::endl;

        std::cout << get_an_account(pt_write, 1001111) << std::endl;

        std::cout << get_a_customer(pt_write, 100222221) << std::endl;


        Operation operation3(99999, "20AAA19-01-01", "1000", "AAAAAAA", "1234AAAAAA56789", "1234567AAA89", "mami vAAAAAirement");

        Customer customer3(8888888,1, "Montuori", "Milo", "1 rue de la liberte Paris", "milo.montuori@student.junia.com", "06 23 67 82 00", "1234567890",
            { 0 });

        Compte compte3(333333, "1000", "Livret A (Interet : 3%)", { 0 });

        pt_write = write_a_customer(pt_write, customer3);

        pt_write = write_an_account(pt_write, compte3, get_a_customer(pt_write, 8888888));

        pt_write = write_an_operation(pt_write, operation3, get_an_account(pt_write, 333333));

        
        int montant = 10;
        pt_write = edit_solde_of_an_account(pt_write, 1001111, -montant); // On soustrait à l'émetteur le montant d'où le signe - 
        pt_write = edit_solde_of_an_account(pt_write, 333333, montant); // On ajoute au recepteur le montant


        std::ofstream file_out111("data.json");
        write_json(file_out111, pt_write);
        file_out111.close();


        std::ifstream file_in11("data.json");
        read_json(file_in11, pt_write);
        file_in11.close();

        pt_write = edit_solde_of_all_account_interets(pt_write, 5); // Après 10 ans 


        std::ofstream file_out2("data.json");
        write_json(file_out2, pt_write);
        file_out2.close();

        std::ifstream file_in2("data.json");
        read_json(file_in2, pt_write);
        file_in2.close();

    }
    catch (std::exception& e) {
        // Other errors
    }
}


