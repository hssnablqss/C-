/* This program will calculate and display the bill for each customer of TSB.
The list of customers will be displayed according to the type of usage 
and the number of customers for each type.
The program will also display the ID of the customer with the highest and lowest bill.
Programmer:
Amirah Najihah Binti Amirudin (2022454884)
Norkhairun Hariana Binti Abdul Rahman (2022857932)
Nur Alisa Yasmin Binti Muhammad Faiz (2022491548)
Wan Nur Husna Balqis Binti Wan Yusoff (2022680858)
Date: 12/2/2023 */

#include<iostream>
#include <string>
#include<iomanip>
#include<cmath>
using namespace std;

//////////////////////////////////////////////////////
// Two dimensional array, maximum 100 customers
// customerId | type of usage | unit used | total bill
string arrayCustomers[100][4];

// Total customers
int totalCustomers = 0;

// Highest bill value
float highestBillResidential = 0, highestBillLVI = 0, highestBillMVI = 0;

// Lowest bill value
float lowestBillResidential = 0, lowestBillLVI = 0, lowestBillMVI = 0;

// Highest bill customer ID
string highestCustomerIdResidential = "", highestCustomerIdLVI = "", highestCustomerIdMVI = "";

// Lowest bill customer ID
string lowestCustomerIdResidential = "", lowestCustomerIdLVI = "", lowestCustomerIdMVI = "";

  /////////////////////////////////
  // PROCESS: Calculate bill (function)
  float calculateBill(string customerId, string typeOfUsage, int unitUsed)
  {
    float total = 0;
    cout<<"\n============================================="<<endl;
    cout<<"                BILLING RECEIPT"<<endl;
    cout << "-------------------------------------------" << endl;
    cout << "        TENAGA SELATAN BERHAD (TSB)        " << endl;
    cout << " Type of Usage : " << typeOfUsage << endl;
    cout << " Customer ID   : " << customerId << endl;
    cout << "-------------------------------------------" << endl;

    // PROCESS: Calculation for total bill
    if (typeOfUsage == "Residential") {
      // initialize variables for residential type of usage
      int first100 = 0;
      int next100 = 0;
      int unitThereafter = 0;
      
      if (unitUsed <= 100) { // First 100 kW
        first100 = unitUsed;
        cout << " - First " << first100 << " x 0.30 : RM" << (first100 * 0.30) << endl;
      } else if (unitUsed > 100 && unitUsed <= 200){ // Next 100 kW
        first100 = 100;
        next100 = unitUsed - 100;
        cout << " - First " << first100 << " x 0.30 : RM" << (first100 * 0.30) << endl;
        cout << " - Next " << next100 << " x 0.50 : RM" << (next100 * 0.50) << endl;
      } else if (unitUsed > 200){   // Each kW therafter
        first100 = 100;
        next100 = 100;
        unitThereafter = unitUsed - 200;
        cout << " - First " << first100 << " x 0.30 : RM" << (first100 * 0.30) << endl;
        cout << " - Next " << next100 << " x 0.50 : RM" << (next100 * 0.50) << endl;
        cout << " - " << unitThereafter << " x 1.00 : RM" << (unitThereafter * 1.00) << endl;
      }

      // PROCESS: Calculate bill
      total = (first100 * 0.30) + (next100 * 0.50) + (unitThereafter * 1.00);

      // Minimum charge is RM10.00
      if (total < 10.00) {  
        total = 10.00;
        cout << " *** Minimum charge is RM" << total << endl;
      }

      // Subsidy is RM15.00
      cout << "-------------------------------------------" << endl;
      cout << " Total                            : " << total << endl;
      cout << " - Subsidy by Malaysian Government: -RM15.00" << endl;
      cout << "-------------------------------------------" << endl;
      if (total > 15.00) {  
        total = total - 15.00;
      } else {
        total = 0;
      }

      // Check highest bill for residential
      if (highestBillResidential == 0 || total > highestBillResidential) {
        highestBillResidential = total;
        highestCustomerIdResidential = customerId;
      }

      // Check lowest bill for residential
      if (lowestBillResidential == 0 || total < lowestBillResidential) {
        lowestBillResidential = total;
        lowestCustomerIdResidential = customerId;
      }

    } else if (typeOfUsage == "Low Voltage Industrial") {
      // initialize variables for Low Voltage Industrial
      int first200 = 0;
      int unitThereafter = 0;
      
      if (unitUsed <= 200) { // First 200 kW
        first200 = unitUsed;
        cout << " - First " << first200 << " x 2.50 : RM" << (first200 * 2.50) << endl;
      } else if (unitUsed > 200){   // Each kW therafter
        first200 = 200;
        unitThereafter = unitUsed - 200;
        cout << " - First " << first200 << " x 2.50 : RM" << (first200 * 2.50) << endl;
        cout << " - " << unitThereafter << " x 3.90 : RM" << (unitThereafter * 3.90) << endl;
      }

      // PROCESS: Calculate bill
      total = (first200 * 2.50) + (unitThereafter * 3.90);
      if (total < 30.00) {  // Minimum charge is RM30.00
        total = 30.00;
        cout << " *** Minimum charge is RM" << total << endl;
      } 

      // Check highest bill for Low Voltage Industrial
      if (highestBillLVI == 0 || total > highestBillLVI) {
        highestBillLVI = total;
        highestCustomerIdLVI= customerId;
      }

      // Check lowest bill for Low Voltage Industrial
      if (lowestBillLVI == 0 || total < lowestBillLVI) {
        lowestBillLVI = total;
        lowestCustomerIdLVI = customerId;
      }

    } else if (typeOfUsage == "Moderate Voltage Industrial") {

      // PROCESS: Calculate bill
      total = unitUsed * 6.50;
      cout << " - " << unitUsed << " x 6.50 : RM" << total << endl;
      if (total < 100.00) {  // Minimum charge is RM100.00
        total = 100.00;
        cout << " *** Minimum charge is RM" << total << endl;
      } 

      // Check highest bill for Medium Voltage Industrial
      if (highestBillMVI == 0 || total > highestBillMVI) {
        highestBillMVI = total;
        highestCustomerIdMVI= customerId;
      }

      // Check lowest bill for Medium Voltage Industrial
      if (lowestBillMVI == 0 || total < lowestBillMVI) {
        lowestBillMVI = total;
        lowestCustomerIdMVI = customerId;
      }

    }
    cout << "-------------------------------------------" << endl;
    cout << "TOTAL BILL                     : RM  " << total << endl;
    cout << "===========================================" << endl;

    return total;
  }

  /////////////////////////////////
  // INPUT: Customer info & unit user
  void readSingleCustomer(int idx)
  {
    string customerId, typeOfUsage;
    int unitUsed, choice;
    float totalBill;

    /////////////////////////////////
    // INPUT: Customer ID
    cout<<"\n\nPlease enter customer ID:  ";
    getline(cin, customerId);
    cout << "Customer ID: " << customerId << endl;

    /////////////////////////////////
    // INPUT: Type of usage
    cout<<"Please select type of usage:  " << endl;
    cout<<"   1 - Residential" << endl;
    cout<<"   2 - Low Voltage Industrial" << endl;
    cout<<"   3 - Moderate Voltage Industrial" << endl;
    cout<<"Your choice : " << endl;
    cin>>choice;
    cin.ignore(); 
    if(choice == 1) {
      typeOfUsage = "Residential";
    } else if(choice == 2) {
      typeOfUsage = "Low Voltage Industrial";
    } else if(choice == 3) {
      typeOfUsage = "Moderate Voltage Industrial";
    } 
    cout << "Type of usage: " << typeOfUsage << endl;

    /////////////////////////////////
    // INPUT: Unit used
    cout<<"Please enter unit used:  ";
    cin>>unitUsed;
    cin.ignore();   
    cout<<"Unit used (kW/kWj): " << unitUsed << endl;


    float total = calculateBill(customerId, typeOfUsage, unitUsed);
    /////////////////////////////////
    // Store customer's infos into arrays
    arrayCustomers[idx][0] = customerId;
    arrayCustomers[idx][1] = typeOfUsage;
    arrayCustomers[idx][2] = to_string(unitUsed);
    arrayCustomers[idx][3] = to_string(total);
  }

  /////////////////////////////////
  // INPUT: Read all customers
  void readAllCustomers()
  {
    /////////////////////////////////
    // INPUT: Total customers
    cout<<"Please enter total customers (1-100):  ";
    cin>>totalCustomers;
    
    if (totalCustomers < 0 || totalCustomers > 100) {
      totalCustomers = 100;
      cout << "Invalid, set to maximum 100 customers." << endl;
    } else {
      cout << "Total customers: " << totalCustomers << endl;
    }
    cin.ignore();   

    // read data
    for (int idx = 0; idx < totalCustomers; idx++) {
      readSingleCustomer(idx);
    }
  }

  ////////////////////////////////////////
  // INPUT: Display HIGHEST&LOWEST (each type of usage)& list of customers (with their detailed info) for each type of usage
  void displayAllCustomers(string typeOfUsage)
  {
    int total = 0;

    cout << "\n\n                " << typeOfUsage << " " << endl;
    cout << "-------------------------------------------------------------------" << endl;
    if (typeOfUsage == "Residential") {
      cout << " > Highest Bill, Customer ID : " << highestCustomerIdResidential << " (RM " << highestBillResidential << ")" << endl;
      cout << " > Lowest Bill,  Customer ID : " << lowestCustomerIdResidential << " (RM " << lowestBillResidential << ")" << endl;
    } else if (typeOfUsage == "Low Voltage Industrial") {
      cout << " > Highest Bill, Customer ID : " << highestCustomerIdLVI << " (RM " << highestBillLVI << ")" << endl;
      cout << " > Lowest Bill,  Customer ID : " << lowestCustomerIdLVI << " (RM " << lowestBillLVI << ")" << endl;
    } else if (typeOfUsage == "Moderate Voltage Industrial") {
      cout << " > Highest Bill, Customer ID : " << highestCustomerIdMVI << " (RM " << highestBillMVI << ")" << endl;
      cout << " > Lowest Bill,  Customer ID : " << lowestCustomerIdMVI << " (RM " << lowestBillMVI << ")" << endl;
    }
    cout << "-------------------------------------------------------------------" << endl;

    // print data
    for (int idx = 0; idx < totalCustomers; idx++) {
      if (typeOfUsage == arrayCustomers[idx][1]) {
        cout<<"ID : " <<arrayCustomers[idx][0] << "|" << arrayCustomers[idx][1] << "| unit used (kW/kWj): " << arrayCustomers[idx][2] << "| total Bill: RM " <<fixed<<setprecision(2)<<stof(arrayCustomers[idx][3]) << endl; //stof-to convert from string to float
        total++;
      }
    }
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Total Customers : " << total << endl;
    cout << "-------------------------------------------------------------------" << endl;
  }

  /////////////////////////////////
  // SEARCH: Search customer facility
  void searchCustomer()
  {
    string customerId;

    /////////////////////////////////
    // INPUT: Total customers
    cout<<"Please enter customer ID to search their detailed information:  ";
    cin>>customerId;
    cout << "Customer ID: " << customerId << endl;
    cin.ignore(); 

    // read data
    for (int idx = 0; idx < totalCustomers; idx++) {
      if (customerId == arrayCustomers[idx][0]) {
        cout<<"\nID : " << arrayCustomers[idx][0] << "|" << arrayCustomers[idx][1] << "|unit used(kW/kWj) : " << arrayCustomers[idx][2] << "|total Bill : RM "<<fixed<<setprecision(2)<<stof(arrayCustomers[idx][3])<< endl; //stof-to convert from string to float
        float total = calculateBill(customerId, arrayCustomers[idx][1], stoi(arrayCustomers[idx][2])); //stoi-to convert from string to integer
        break;
      }
    }
  }

int main()
{
    int choice;
    string enterData = "yes";
    
    cout<<"Do you want to enter data (yes/no)?  : ";
    getline(cin,enterData);
    
    if(enterData == "yes" || enterData == "Yes")
    {
        readAllCustomers();

  /////////////////////////////////
  // MENU PAGE: Infinite loop
  for (; true; ) {
    cout<<"\n\n**************************************" << endl;
    cout<<"**    TENAGA SELATAN BERHAD (TSB)   **" << endl;
    cout<<"**   -----------------------------  **" << endl;
    cout<<"**          MAIN MENU               **" << endl;
    cout<<"**   1 - DISPLAY HIGHEST & LOWEST   **" << endl;
    cout<<"**   2 - SEARCH CUSTOMER BILL       **" << endl;
    cout<<"**   0 - EXIT                       **" << endl;
    cout<<"**************************************" << endl;
    cout<<"Your choice : " << endl;
    cin>>choice;
    cin.ignore();   
    if(choice == 1) {
      displayAllCustomers("Residential");
      displayAllCustomers("Low Voltage Industrial");
      displayAllCustomers("Moderate Voltage Industrial");
    } else if(choice == 2) {
      searchCustomer();
    } else if(choice == 0) {
      cout<<"you have exited the program.." << endl;
      exit(0);
    } else {
      cout<<"Invalid choice.." << endl;
    }
  }
  return 0;
    }  
}