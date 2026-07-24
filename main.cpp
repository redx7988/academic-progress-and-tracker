#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class student{
    public:
    string name ;
    string subject ;
    int credit ;
    int classes_held ;
    int classes_attended ;

    //create point
    student(string name,string subject, int credit, int classes_held, int classes_attended){
        this->name = name ;
        this->subject = subject ;
        this->credit = credit ;
        this->classes_held = classes_held ;
        this->classes_attended = classes_attended ;
    }
    //read point
    void print(){
        cout << "Name: " << name << endl;
        cout << "subject "<< subject <<endl;
        cout << "Credit: " << credit << endl;
        cout << "Classes Held: " << classes_held << endl;
        cout << "Classes Attended: " << classes_attended << endl;
    }
    //update point
    void update(string name , string subject,int credit, int classes_held, int classes_attended){
        this->name = name ;
        this->subject = subject ;
        this->credit = credit ;
        this->classes_held = classes_held ;
        this->classes_attended = classes_attended ;
    }

    ~student(){
        cout << "Destructor called for " << name << endl;
    }
};

// logger feature to track daily attendance
class logger{
    public :
    int present ;
    int absent ;
    int cancelled ;
    float attendance ;
    
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
    
    float percentage (){
        int total = present + absent ;
        if (total == 0) return 0.0f; // Fix: Prevent division by zero
        attendance = ((float)present/total)*100 ; // Fix: Cast to float to prevent integer division
        return attendance; // Fix: Return the value instead of printing it
    }

    ~logger(){
        cout<< "Attendence list deleted sucessfully" << endl;
    }
};

int main(){
    
    // INITIALIZE VARIABLES
    int choice;
    string temp_name ;
    string temp_subject ;
    int temp_credit ;
    int temp_classes_held ;
    int temp_classes_attended ;

    student* s1 = nullptr ;
    // kept it here so that it can be accessed in the dashboard section
    logger* l1 = nullptr;

    bool program_running = true;

    while(program_running){
        cout<<setfill('-')<<setw(80)<<""<<endl;
        cout<<right<<setfill(' ')<<setw(65)<<"===Welcome to the Academic Progress Tracker!===" << endl;
        cout<<setfill('-')<<setw(80)<<""<<endl;
        cout<< "please select the option you want to perform" << endl;
        cout<< "1. Create a new student record" << endl;
        cout<< "2. Read a student record" << endl;
        cout<< "3. Update a student record" << endl;
        cout<< "4. Delete a student record" << endl;
        cout<< "5. Daily logger" << endl;
        cout<< "6. Show dashboard "<<endl ;
        cout<< "7. Exit" << endl;
        cout<< "\n" << endl<< "Enter your choice (1 to 6): "<< endl;
        cin>> choice;

        // FIX IF USER SEND SEND ANY THING OTHER THEN A NUMBER
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000 , '\n');
            cout<< " ERROR!! ,You must enter a number only" << endl;
            continue;
        }

        switch(choice){
            case 1 :
            if( s1 != nullptr){
                cout<< "A student record already exists. Please delete it before creating a new one." << endl;
            }else{
                cout<< "Enter student name: ";
                cin>> temp_name ;
                cout<< "Enter the subject name:" ;
                cin>> temp_subject ;
                cout<< "Enter student credit: ";
                cin>> temp_credit ;
                cout<< "Enter classes held: ";
                cin>> temp_classes_held ;
                cout<< "Enter classes attended: ";
                cin>> temp_classes_attended ;
                s1 = new student(temp_name, temp_subject , temp_credit, temp_classes_held, temp_classes_attended);
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
                cout<< " Enter the updated subject name" ;
                cin>> temp_subject ;
                cout<< "Enter updated student credit: ";
                cin>> temp_credit ;
                cout<< "Enter updated classes held: ";
                cin>> temp_classes_held ;
                cout<< "Enter updated classes attended: ";
                cin>> temp_classes_attended ;
                s1->update(temp_name, temp_subject, temp_credit, temp_classes_held, temp_classes_attended);
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
            
            // ---------------------------------------------------logger feature to track daily attendance---------------------------------------------------
            case 5 :{
                int temp_present ;
                int temp_absent ;
                int temp_cancelled ;

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
                        cout<< " ERROR!! ,You must enter a number only" << endl;
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
                            cout<< "No attendance list found. Please create a list first." << endl;
                        }else{
                            l1->print();
                        }
                        break;

                        case 3 :
                        if(l1 == nullptr){
                            cout<< "No attendance list found. Please create a record first." << endl;
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
                            cout<< "No attendance list found. Please create a record first." << endl;
                        }else{
                            // Fix: Properly print the float returned from percentage()
                            cout<< " your current attandence is " << l1->percentage() << "%" << endl;
                        }
                        break;
                        
                        case 5 :
                        if( l1== nullptr){
                            cout<< "No attendance list found. Please create a record first." << endl;
                        }
                        else{
                            delete l1;
                            l1 = nullptr;
                            cout<< "Attendance list deleted successfully!" << endl;
                        }
                        break;

                        case 6 :
                        running = false;
                        break;
                    }        
                }
            }
            break;
            //---------------------------------------------------logger feature to track daily attendance ends here--------------------------------------------

            case 6 :
            if(s1 == nullptr){
                cout<<"Please create a student list "<<endl ;
            }else if(l1 == nullptr){
                cout<<"Please create a attendance list "<<endl ;
            }else{
                cout<<setfill('=')<<setw(80)<<""<<endl;
                cout<<right<<setfill(' ')<<setw(65)<<"STUDENT DASHBOARD " <<endl;
                cout<<setfill('=')<<setw(80)<<""<<endl;
                cout<<left<<setfill(' ')<<setw(20)<<"subject"
                    <<right<<setw(15)<<"credit"
                    <<right<<setw(15)<<"attendance"
                    <<right<<setw(15)<<"progress bar"
                    <<right<<setw(15)<<"status"<<endl;
                cout<<setfill('-')<<setw(80)<<""<<endl ;
                cout<<left<<setfill(' ')<<setw(20)<<s1->subject
                    <<right<<setw(15)<< s1->credit
                    <<right<<setw(15)<<l1->percentage() << "%"
                    <<right<<setw(15)<< "||||||||||"
                    <<right<<setw(15) ; 
                    if (l1->percentage() >= 75) {
                        cout << "[On track]" << endl;
                    } else {
                        cout << "[Warn]" << endl;
                    }
                cout<<setfill('-')<<setw(80)<<""<<endl ;
                cout<< "Note: The progress bar is a visual representation of your attendance percentage. Each '|' represents 10% attendance." << endl;
                cout<< "Status: [On track] indicates that your attendance is above or equal to 75%, while [Warn] indicates that your attendance is below 75%." << endl;
                cout<<setfill('=')<<setw(80)<<""<<endl;
            }
            break;
            
            case 7 :
            if( s1!=nullptr){
                delete s1;
                s1 = nullptr;
            }
            // Fix: Delete the logger pointer on exit to prevent memory leaks
            if( l1!=nullptr){
                delete l1;
                l1 = nullptr;
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