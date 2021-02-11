#include "commonDefines.HPP"
#include "UserManager.HPP"
#include "ExpenseManager.HPP"

int main()
{
    int choice;
    while(1)
    {
        cout<<"Please select an action to perform:"<<endl;
        cout<<"Enter 1 to register a new user"<<endl;
        cout<<"Enter 2 to add a create a new expense"<<endl;
        cout<<"Enter 3 to check expense for a user"<<endl;
        cout<<"Enter 4 to exit"<<endl;
        cin>>choice;
        switch ( choice )
        {
            case 1:
            {
                UserData *userData = new UserData;
                cout<<"Please enter the name of the user:"<<endl;
                cin>>userData->name;
                cout<<"Please enter the phone number of the user:"<<endl;
                cin>>userData->phoneNumber;
                cout<<"Please enter the emailId of the user:"<<endl;
                cin>>userData->emailId;
                if( UserManager::getInstance()->registerUser( userData ) )
                {
                    cout<<"User Registered Successfully!"<<endl;
                }
                else
                {
                    cout<<"Error: User registration unsuccessful, please try again!"<<endl;
                }
            }
            break;

            case 2:
            {
                string phoneNumber, description;
                int amount;
                cout<<"Please enter the phone number of the payer:"<<endl;
                cin>>phoneNumber;
                UserData *payerData = new UserData;
                payerData->phoneNumber = phoneNumber;
                cout<<"Please enter the total amount:"<<endl;
                cin>>amount;
                cout<<"Please enter a description(optional):"<<endl;
                cin>>description;
                int n;
                cout<<"Please enter number of payees:"<<endl;
                cin>>n;
                int splitType; 
                cout<<"Please split type:"<<endl;
                cout<<"'0' for Manual Split"<<endl;
                cout<<"'1' for Equal Split"<<endl;
                cout<<"'2' for Percentage Split"<<endl;
                cin>>splitType;
                vector<UserData*> payeeList;
                vector<int> splitParams;
                for ( int i = 1; i <= n; i++ )
                {
                    UserData *payeeUserData = new UserData;
                    cout<<"Please enter phone number for payee #"<<i<<":"<<endl;
                    cin>>payeeUserData->phoneNumber;
                    if ( splitType ==  SplitStrategyType::MANUAL || splitType ==  SplitStrategyType::PERCENTAGE )
                    {
                        int input;
                        if ( splitType ==  SplitStrategyType::MANUAL )
                            cout<<"Please enter split amount for payee #"<<i<<":"<<endl;
                        else if ( splitType ==  SplitStrategyType::PERCENTAGE )
                            cout<<"Please enter split percentage for payee #"<<i<<":"<<endl;    
                        
                        cin>>input;
                        splitParams.push_back( input );
                    }
                    payeeList.push_back( payeeUserData );
                }
                
//                if ( !ExpenseManager::getInstance()->createExpense( payerData, splitType, payeeList, amount, description ) )
//                {
//                    cout<<"Error: Unable to create expense!";
//                }
            }
            break;

            case 3:
            {
                string phoneNumber;
                cout<<"Please enter the phone number of the payer:"<<endl;
                cin>>phoneNumber;
                ExpenseManager::getInstance()->showBalanceForUser( phoneNumber );
            }
            break;
            
            case 4:
                return 0;

        }
    }
    return 0;
}