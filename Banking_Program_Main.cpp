#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

void showbalance(double balance);
double deposit();
double withdraw(double balance);

int main(){

   double balance;
   int choice = 0;
    
    std::ifstream ibalfilestream;
    std::ofstream obalfilestream;

    std::string fileName = "Balance.txt";

    
    ibalfilestream.open("balance.txt");
    ibalfilestream >> balance;
    ibalfilestream.close();

    do{
        std::cout << "*****************\n";
        std::cout << "enter you choice\n";
        std::cout << "*****************\n";
        std::cout << "1. Show balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw money\n";
        std::cout << "4. exit\n";
        std::cin >> choice;
        std::cout << "*****************\n";        

        std::cin.clear();
        fflush(stdin);

    switch(choice){
        case 1: showbalance(balance);
            break;
        case 2: balance += deposit();
            showbalance(balance);            
            break;
        case 3: balance -= withdraw(balance);
            showbalance(balance);
            break;
        case 4: std::cout << "CYA Later";
                std::cout << "*****************\n";        
            break;
        default: std::cout << "invalid choice";
                std::cout << "*****************\n";
        }
    }while(choice != 4);
   
    int stBal;


    obalfilestream.open("balance.txt");
    obalfilestream << balance;
    obalfilestream.close();

}
void showbalance(double balance){
        std::cout << "your balance is: $" << std::setprecision(2) << std::fixed << balance << '\n';
}

double deposit(){
    double amount= 0;
    
    std::cout << "Enter amount to be DEPOSITED: ";
    std::cin >> amount;

    if(amount > 0){
    return amount;
    }
    else{
        std::cout << "that is not a valid amount\n";
        return 0;
    }

}

double withdraw(double balance){
    double amount = 0;

    std::cout << "enter amount to be withdrawn: ";
    std::cin >> amount;

    if(amount <= balance && amount >= 0){
        return amount;
    }
    else{
        std::cout << "that is not a valid amount\n";
    }
    return 0;

}
    
