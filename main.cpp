#include<iostream>
#include<string>
using namespace std;
class student{
    public:
    string name ;
    int credit ;
    int classes_held ;
    int classes_attended ;

    //create point
    student(string name, int credit, int classes_held, int classes_attended){
        this->name = name ;
        this->credit = credit ;
        this->classes_held = classes_held ;
        this->classes_attended = classes_attended ;
    }
    //read point
    void print(){
        cout << "Name: " << name << endl;
        cout << "Credit: " << credit << endl;
        cout << "Classes Held: " << classes_held << endl;
        cout << "Classes Attended: " << classes_attended << endl;
    }
    //update point
    void update(string name , int credit, int classes_held, int classes_attended){
        this->name = name ;
        this->credit = credit ;
        this->classes_held = classes_held ;
        this->classes_attended = classes_attended ;
    }

    ~student(){
        cout << "Destructor called for " << name << endl;
    }

};

class logger{
    public :
    int present ;
    int absent ;
    int cancelled ;
    
    logger(int p , int a , int c){
        present = p ;
        absent = a ;
        cancelled = c;
    }

    void update(int p , int a , int c){
        present = p ;
        absent = a ;
        cancelled = c;
    }

    void print(){
        cout << " [+] You were present for "<< present <<" classes."<<endl ;
        cout << " [-] You were absent for "<< absent <<" classes."<<endl ;
        cout << " [X] Your " << cancelled << " were cancelled." <<endl ;
    }
    

    void percentage (){
        int total = present + absent ;
        cout<< ((float)present/total)*100 << "%" <<endl;
    }

    ~logger(){
        cout<< "Attendence list deleted sucessfully";
    }
};



int main(){
    

    // INITIALIZE VARIABLES
    int choice;
    string temp_name ;
    int temp_credit ;
    int temp_classes_held ;
    int temp_classes_attended ;

    student* s1 = nullptr ;

    bool program_running = true;

    while(program_running){
        cout<< "===Welcome to the Academic Progress Tracker!===" << endl;
    cout<< "please select the option you want to perform" << endl;
    cout<< "1. Create a new student record" << endl;
    cout<< "2. Read a student record" << endl;
    cout<< "3. Update a student record" << endl;
    cout<< "4. Delete a student record" << endl;
    cout<< "5. Daily logger" << endl;
    cout<< "6. Exit" << endl;
    cout<< "\n" << endl<< "Enter your choice (1 to 6): "<< endl;
    cin>> choice;

    // FIX IF USER SEND SEND ANY THING OTHER THEN A NUMBER
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000 , '\n');
        cout<< " ERROR!! ,You must enter a number only";
        continue;
    }

    switch(choice){
        case 1 :
        if( s1 != nullptr){
            cout<< "A student record already exists. Please delete it before creating a new one." << endl;
        }else{
        cout<< "Enter student name: ";
        cin>> temp_name ;
        cout<< "Enter student credit: ";
        cin>> temp_credit ;
        cout<< "Enter classes held: ";
        cin>> temp_classes_held ;
        cout<< "Enter classes attended: ";
        cin>> temp_classes_attended ;
        s1 = new student(temp_name, temp_credit, temp_classes_held, temp_classes_attended);
        cout<< "Student record created successfully!" << endl;
        }
        break;

        case 2 :
        if( s1== nullptr){
            cout<< "No student record found. Please create a record first." << endl;
        }
        else{
            s1->print();
        }
        break ;

        case 3 :
        if( s1== nullptr){
            cout<< "No student record found. Please create a record first." << endl;
        }
        else{
            cout<< "Enter updated student name: ";
            cin>> temp_name ;
            cout<< "Enter updated student credit: ";
            cin>> temp_credit ;
            cout<< "Enter updated classes held: ";
            cin>> temp_classes_held ;
            cout<< "Enter updated classes attended: ";
            cin>> temp_classes_attended ;
            s1->update(temp_name, temp_credit, temp_classes_held, temp_classes_attended);
            cout<< "Student record updated successfully!" << endl;
        }
        break;

        case 4 :
        if( s1== nullptr){
            cout<< "No student record found. Please create a record first." << endl;
        }
        else{
            delete s1;
            s1 = nullptr;
            cout<< "Student record deleted successfully!" << endl;
        }
        break;

        case 5 :{

        int temp_present ;
        int temp_absent ;
        int temp_cancelled ;

        logger* l1 = nullptr;
        bool running = true ;
        while(running){
            
        cout<< "===Welcome to the Daily Logger!===" << endl;
        cout << "1. Add attendence list " << endl;
        cout<< "2. Print current attendance " <<endl ;
        cout<< "3. Update the attendence list"<<endl;
        cout<< "4. Show current attendance percentage"<< endl;
        cout<< "5. Delete the attendence list " <<endl;
        cout<< "6. Go back " <<endl;
        cin >> choice;

        // FIX IF USER SEND SEND ANY THING OTHER THEN A NUMBER
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000 , '\n');
            cout<< " ERROR!! ,You must enter a number only";
            continue;
        }
        switch(choice){
            case 1 :
            if(l1 != nullptr){
                cout<< "A attendance list already exist . Please delete it first" << endl;
            }else{
                cout << "Enter the number of class you attended."<<endl;
                cin>>temp_present;
                cout<< "Enter the number of classes you were absent."<<endl;
                cin>>temp_absent;
                cout<< "Enter the number of class cancelled."<<endl;
                cin>> temp_cancelled;

                l1 = new logger(temp_present,temp_absent,temp_cancelled);
            }
            break;

            case 2 :
            if( l1 == nullptr){
                cout<< "No student record found. Please create a record first." << endl;
            }else{
                l1->print();
            }
            break;

            case 3 :
            if(l1 == nullptr){
                cout<< "No student record found. Please create a record first." << endl;
            }else{
                cout<<"Enter the update number of classes present"<<endl;
                cin>>temp_present;
                cout<<"Enter the update number of classes absent"<<endl;
                cin>>temp_absent;
                cout<<"Enter the update number of classes cancelled"<<endl;
                cin>>temp_cancelled;
                l1->update(temp_present,temp_absent,temp_cancelled);
            }
            break;

            case 4 :
            if(l1 == nullptr){
                cout<< "No student record found. Please create a record first." << endl;
            }else{
                cout<< " your current attandence is "<<endl;
                l1->percentage();
            }
            break;
            
            case 5 :
            if( l1== nullptr){
                cout<< "No student record found. Please create a record first." << endl;
            }
            else{
                delete l1;
                l1 = nullptr;
                cout<< "Attendance list deleted successfully!" << endl;
            }
            break;

            case 6 :
            if( l1!= nullptr){
                delete l1;
                l1 = nullptr;
            }
            running = false;
            break;

        }        
        }
        }
        break;


        case 6 :
        if( s1!=nullptr){
            delete s1;
            s1 = nullptr;
        }
        program_running = false;
        cout<< "Exiting the program. Goodbye!" << endl;
        break;

        default :
        cout<< "Invalid choice. Please try again." << endl;
        break;
    }
    }
    return 0;
}