#include <iostream>
#include "E0202A.h"
using namespace std;

// int main_module();
// int climbing_module();
// int scuba_module();
// int skydive_module();

int main(int argc, char *argv[])
{
    int activity_selection, exit_condition = 1;
    
    while (exit_condition)
    {
        activity_selection = main_module();
        if (activity_selection == 0)
        {
            exit(0);
        }
        else
        {
            switch (activity_selection)
            {
            case 1:
                exit_condition = climbing_module();
                if (exit_condition == 0)
                {
                    exit(0);
                }
                break;

            case 2:
                exit_condition = scuba_module();
                if (exit_condition == 0)
                {
                    exit(0);
                }
                break;

            case 3:
                exit_condition = skydive_module();
                if (exit_condition == 0)
                {
                    exit(0);
                }
                break;
            }
        }
    }

    return 0;
}

// int main_module()
// {

//     int selection;
//     while (true)
//     {
//         cout << "\t\t =====================" << endl;
//         cout << "\t\t TRAVEL AGENCY MENU." << endl;
//         cout << "\t\t =====================" << endl;

//         cout << "\tSelect an activity you want to make reservation (0, 1, 2, or 3) " << endl
//              << endl;
//         cout << "\t0. Exit Program " << endl;
//         cout << "\t1. Climing " << endl;
//         cout << "\t2. Scuba " << endl;
//         cout << "\t3. Skydive " << endl;
//         cin >> selection;

//         if (selection > 3 || selection < 0)
//         {
//             cout << "You selected wrong option. " << selection << endl;
//             cout << "Select between 0 and 3. " << selection << endl;
//             continue;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return selection;
// }

// int climbing_module()
// {

//     const float base_charge = 350, instruction_charge = 100, equipment_rental = 40;
//     float num_party, num_instruction, num_advanced, num_equipment, num_rental_days;

//     int exit_condition;
//     while (true)
//     {
//         cout << "\t\t =====================" << endl;
//         cout << "\t\t CLIMING MENU." << endl;
//         cout << "\t\t =====================" << endl;

//         cout << "\tHow many people want instruction? ";
//         cin >> num_instruction;
//         cout << "\tHow many advanced clibmers? ";
//         cin >> num_advanced;
//         num_party = num_advanced + num_instruction;
//         cout << "\tHow many people want to rent equipment? ";
//         cin >> num_equipment;
//         cout << "\tHow many days they want to rent equipment? ";
//         cin >> num_rental_days;

//         cout << "\t============================================" << endl;
//         cout << "\tPayment Summary" << endl;
//         cout << "\t--------------------------------------------" << endl;
//         cout << "\tBase Charge: " << num_party * base_charge << endl;
//         if (num_party >= 5)
//         {
//             cout << "\tDiscount: -" << num_party * base_charge * 0.1 << endl;
//         }
//         cout << "\tInstruction Charge: " << num_instruction * instruction_charge << endl;
//         cout << "\tEquipment Rental Charge: " << num_equipment * num_rental_days * equipment_rental << endl;
//         cout << "\t--------------------------------------------" << endl;
//         if (num_party >= 5)
//         {
//             cout << "\tTotal: " << num_party * base_charge * 0.9 + num_instruction * instruction_charge + num_equipment * num_rental_days * equipment_rental << endl;
//             cout << "\tDeposit: " << (num_party * base_charge * 0.9 + num_instruction * instruction_charge + num_equipment * num_rental_days * equipment_rental) * 0.3 << endl;
//         }
//         else
//         {
//             cout << "\tTotal: " << num_party * base_charge + num_instruction * instruction_charge + num_equipment * num_rental_days * equipment_rental << endl;
//             cout << "\tDeposit: " << (num_party * base_charge + num_instruction * instruction_charge + num_equipment * num_rental_days * equipment_rental) * 0.3 << endl;
//         }

//         cout << "Do want another transaction? (1 - Yes, 0 - No)";
//         cin >> exit_condition;
//         return exit_condition;
//         // if(exit_condition == 0){
//         //     exit(0);
//         // }else{
//         //     return exit_condition;
//         // }
//     }
//     // return exit_condition;
// }

// int scuba_module()
// {

//     const float base_charge = 1000, instruction_charge = 100;
//     float num_party, num_instruction, num_advanced;

//     int exit_condition;
//     while (true)
//     {
//         cout << "\t\t =====================" << endl;
//         cout << "\t\t SCUBA MENU." << endl;
//         cout << "\t\t =====================" << endl;

//         cout << "\tHow many people want instruction? ";
//         cin >> num_instruction;
//         cout << "\tHow many advanced divers? " << endl;
//         cin >> num_advanced;
//         num_party = num_advanced + num_instruction;

//         cout << "\t============================================" << endl;
//         cout << "\tPayment Summary" << endl;
//         cout << "\t--------------------------------------------" << endl;
//         cout << "\tBase Charge: " << num_party * base_charge << endl;

//         if (num_party >= 5)
//         {
//             cout << "\tDiscount: -" << num_party * base_charge * 0.1 << endl;
//         }
//         cout << "\tInstruction Charge: " << num_instruction * instruction_charge << endl;
//         cout << "\t--------------------------------------------" << endl;
//         if (num_party >= 5)
//         {
//             cout << "\tTotal: " << num_party * base_charge * 0.9 + num_instruction * instruction_charge << endl;
//             cout << "\tDeposit: " << (num_party * base_charge * 0.9 + num_instruction * instruction_charge) * 0.3 << endl;
//         }
//         else
//         {
//             cout << "\tTotal: " << num_party * base_charge + num_instruction * instruction_charge << endl;
//             cout << "\tDeposit: " << (num_party * base_charge + num_instruction * instruction_charge) * 0.3 << endl;
//         }

//         cout << "Do want another transaction? (1 - Yes, 0 - No)";
//         cin >> exit_condition;
//         return exit_condition;
//         // if(exit_condition == 0){
//         //     exit(0);
//         // }else{
//         //     return exit_condition;
//         // }
//     }
//     // return exit_condition;
// }

// int skydive_module()
// {

//     const float base_charge = 400, wildness_lodge = 65, luxury_inn = 120;
//     float num_party, lodge_option, num_days;

//     int exit_condition;
//     while (true)
//     {
//         cout << "\t\t =====================" << endl;
//         cout << "\t\t SKYDIVE MENU." << endl;
//         cout << "\t\t =====================" << endl;

//         cout << "\tHow many people in the party? ";
//         cin >> num_party;
//         cout << "\tWhere do you want to stay at (1 - Wilderness Lodge, 2 - Luxury Inn )? ";
//         cin >> lodge_option;
//         cout << "\tHow many days they want to stay at the lodge? ";
//         cin >> num_days;

//         cout << "\t============================================" << endl;
//         cout << "\tPayment Summary" << endl;
//         cout << "\t--------------------------------------------" << endl;
//         cout << "\tBase Charge: " << num_party * base_charge << endl;

//         if (num_party >= 5)
//         {
//             cout << "\tDiscount: -" << num_party * base_charge * 0.1 << endl;
//         }

//         if (lodge_option == 1)
//         {
//             cout << "\tLodging Charge: " << num_party * wildness_lodge * num_days << endl;
//         }
//         else if (lodge_option == 2)
//         {
//             cout << "\tLodging Charge: " << num_party * luxury_inn * num_days << endl;
//         }

//         if (num_party >= 5 && lodge_option == 1)
//         {
//             cout << "\tTotal: " << num_party * (base_charge * 0.9 + wildness_lodge * num_days) << endl;
//             cout << "\tDeposit: " << (num_party * (base_charge * 0.9 + wildness_lodge * num_days)) * 0.3 << endl;
//         }
//         else if (num_party >= 5 && lodge_option == 2)
//         {
//             cout << "\tTotal: " << num_party * (base_charge * 0.9 + luxury_inn * num_days) << endl;
//             cout << "\tDeposit: " << (num_party * (base_charge * 0.9 + luxury_inn * num_days)) * 0.3 << endl;
//         }
//         else if (num_party < 5 && lodge_option == 1)
//         {
//             cout << "\tTotal: " << num_party * (base_charge + wildness_lodge * num_days) << endl;
//             cout << "\tDeposit: " << (num_party * (base_charge + wildness_lodge * num_days)) * 0.3 << endl;
//         }
//         else if (num_party < 5 && lodge_option == 2)
//         {
//             cout << "\tTotal: " << num_party * (base_charge + luxury_inn * num_days) << endl;
//             cout << "\tDeposit: " << (num_party * (base_charge + luxury_inn * num_days)) * 0.3 << endl;
//         }

//         cout << "Do want another transaction? (1 - Yes, 0 - No)";
//         cin >> exit_condition;
//         return exit_condition;
//         // if(exit_condition == 0){
//         //     exit(0);
//         // }else{
//         //     return exit_condition;
//         // }
//     }
//     // return exit_condition;
// }