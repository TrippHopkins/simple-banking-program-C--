#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

void showbalance(double balance);
double deposit();
double withdraw(double balance);
double PlatSub(double balance);

int main(){

    double balance;
    int choice = 0;
    int PlatPay;
    
    std::ifstream ifilestream;
    std::ofstream ofilestream;
    
    std::string filename2 = "RewardsYN.txt";
    std::string fileName = "Balance.txt";



    ifilestream.open("balance.txt");
    ifilestream >> balance;
    ifilestream.close();

    ifilestream.open("RewardsYN.txt");
    ifilestream >> PlatPay;
    ifilestream.close();

    do{
       if(PlatPay == 0){
        std::cout << "*****************\n";
        std::cout << "enter you choice\n";
        std::cout << "*****************\n";
        std::cout << "1. Show balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw money\n";
        std::cout << "4. Enroll in Platinum Pay Rewards ($25 fee)\n";
        std::cout << "6. exit\n";
        std::cin >> choice;
        std::cout << "*****************\n";
       }
        else if(PlatPay == 1){
        std::cout << "****************************************************\n";
        std::cout << "WELCOME PLATINUM MEMBER, HOW MAY I ASSIST YOU TODAY\n";
        std::cout << "****************************************************\n";
        std::cout << "1. Show balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw money\n";
        std::cout << "5. Cancle Platinum Membership\n";
        std::cout << "6. exit\n";
        std::cin >> choice;
        std::cout << "*****************************************************\n";
        }
        

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
        case 4: PlatPay = 1  ;       
                std::cout << "Welcome to the PLATINUM REWARDS membership\n";
                balance -= PlatSub(balance);
                showbalance(balance);
            break;
        case 5: PlatPay = 0  ;
                std::cout << "goodbye previous rewards member :( \n";        
            break;
        case 6: std::cout << "CYA Later\n";
                std::cout << "*****************\n";        
            break;
        default: std::cout << "invalid choice\n";
                std::cout << "*****************\n";
        }
    }while(choice != 6);
   
    int stBal;


    ofilestream.open("balance.txt");
    ofilestream << balance;
    ofilestream.close();

    ofilestream.open("RewardsYN.txt");
    ofilestream << PlatPay;
    ofilestream.close();    

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

double PlatSub(double balance){
    double fee = 25;

    if(fee <= balance && fee >= 0){
        return fee;
    }
    else{
        std::cout << "that is not a valid amount\n";
    }
    return 0;
}
    
