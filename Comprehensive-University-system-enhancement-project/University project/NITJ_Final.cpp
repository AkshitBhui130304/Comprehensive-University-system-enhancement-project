#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class HOD
{
    public:
    HOD()
    {
    cout << "--------------------------------" <<endl;
    cout << "***ADMIN INFORMATION:***" << endl;
        ifstream file("Admin.txt");

    if (!file.is_open())
    {
    cout << "Unable to open the file!" << endl;
        return;
    }
    string line;
    while (getline(file, line,'#'))
    {
        cout << line <<endl;
    }
    file.close();
    cout << "--------------------------------" <<endl;
    }

    ~HOD() {
        cout<<endl<<"THANKS FOR VISITING HOD CLASS :) ";
    }

};

class Admin
{
public:
    string name;
    string address;
    int aadhar;
    char sect;
    friend class HOD;

    ~Admin()
    {}

    void get_data() 
	{
        cin.ignore();
        cout << "Enter your name ";
        getline(cin, name);
        cout << endl;
        cin.ignore();
        cout << "Enter your address. Press | if you have completed typing address ";
        getline(cin, address, '|');
        cout << endl;
        cin.ignore();
        cout << "Enter your aadhar number ";
        cin >> aadhar;
        cout << endl;
    }

    virtual void display()=0;

   void update(string id, string updatedLine)
{
    ifstream infile("Admin.txt");
    ofstream tempfile("temp1.txt", ios::out);

    if (infile.is_open() && tempfile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            size_t pos = line.find(updatedLine);
            if (pos != string::npos)
            {
                tempfile << id << endl;
                cout << "Record updated successfully!" << endl;
            }
            else
            {
                tempfile << line << endl;
            }
        }

        infile.close();
        tempfile.close();

        // Rename the temporary file to the original file
        remove("Admin.txt");
        rename("temp1.txt", "Admin.txt");
    }
    else
    {
        cout << "Error opening the file!" << endl;
    }
}

};

	class CSE_Studs : virtual public Admin
	{
		public:
	 	static int no;
	    int studs_ID;
        friend class HOD;

	    CSE_Studs() {}

        ~CSE_Studs() {}
	    
	    CSE_Studs(char l) 
		{
	        
	        sect = l;
	        get_data();
	        cout << "Enter Your ID ";
	        cin >> studs_ID;
	    }
	
	    static int no_of_studs() {
	        return ++no;
	    }
	
	void display()
	{
        cout << "---------------------------------------------" <<endl;
        
	    cout << "***STUDENT INFORMATION:***" << endl;
        ifstream file("Students.txt");

    if (!file.is_open())
    {
    cout << "Unable to open the file!" << endl;
        return;
    }
    string line;
    while (getline(file, line,'#'))
    {
        cout << line <<endl;
    }
    file.close();
    cout << "---------------------------------------------" <<endl;
    }
	
	    class Students
	    {
	    	private:
	        int no;            //no. of subjects
	        float* midsem;
	        float* endsem;
	        char* grade;
	
	    public:
	    	Students(){}

            ~Students() {}
	    	
	        Students(int a)
		   {
	            cout << "Enter Number of subjects ";
	            cin >> no;
	            midsem = new float[no];
	            endsem = new float[no];
                grade = new char[no];
	            marks();
	        }
	         
	        void marks() 
			{
	            cout << "Enter your mid sem marks " << endl;
	            for (int i = 0; i < no; i++) {
	                cout << "Enter marks of Subject " << i + 1 << " ";
	                cin >> midsem[i];
	            }
	            cout << "Enter your end sem marks " << endl;
	            for (int i = 0; i < no; i++) {
	                cout << "Enter marks of Subject " << i + 1 << " ";
	                cin >> endsem[i];
	            }
	            
	       for (int i = 0; i < no; i++)
			 {
	        float totalMarks = midsem[i] + endsem[i];
	        if (totalMarks >= 91 && totalMarks <= 100) {
	            grade[i] = 'A';
	        } else if (totalMarks >= 81 && totalMarks <= 90) {
	            grade[i] = 'B';
	        } else if (totalMarks >= 71 && totalMarks <= 80) {
	            grade[i] = 'C';
	        } else if (totalMarks >= 61 && totalMarks <= 70) {
	            grade[i] = 'D';
	        } else if (totalMarks >= 51 && totalMarks <= 60) {
	            grade[i] = 'E';
	        } else {
	            grade[i] = 'F';
	        }
	         }
	      }
	
	        void insert()    //insert in student file and admin file
			{
	            ofstream sfout("Students.txt", ios::app);
	            ofstream afout("Admin.txt", ios::app);
	
	            cout << "Enter your section ";
	            char c;
				cin >> c;
	            CSE_Studs a(c);
	            
	            sfout<<"# Name:- " << a.name <<"# Student ID:- "<< a.studs_ID << "# Section:- " << a.sect << " ";
	            
	            
	            afout << " #Name:- "<<a.name << "# Student ID:- "<< a.studs_ID << "# Adhaar:- " << a.aadhar << "# Address:- " << a.address << "# Section:- " << a.sect;
	            
	            sfout << "#Mid Sem Marks:-         ";
	            for (int i = 0; i < no; i++)
	            sfout << midsem[i] << ' ';
	            
	            sfout << "#End Sem Marks:-         ";
	            for (int i = 0; i < no; i++)
	            sfout << endsem[i] << ' ';
	            
	            sfout << "#Grade in each subject:- ";
	            for(int i = 0; i < no; i++)
	            sfout << grade[i] << ' ';
	            
			    sfout << "\n";
	            afout << "\n";
	            sfout.close();
	            afout.close();
	        }
	
void supdate()
{
    string id, line;
    cout << "Enter Student's name to update: ";
    cin >> id;
    cout << "Enter your section ";
	            char c;
				cin >> c;
	            CSE_Studs a(c);
    ifstream infile("Students.txt");
    ofstream tempfile("temp.txt", ios::out);

    if (infile.is_open() && tempfile.is_open())
    {
        while (getline(infile, line))
        {
            size_t pos = line.find(id);
            if (pos != string::npos)
            {

                // Update the common Admin attributes
            

                // Update the specific CSE_Studs attributes (midsem, endsem, grade)
                Students s(1);

                tempfile << "# Name:- " << a.name << "# Student ID:- " << a.studs_ID << "# Section:- " << a.sect << " ";
                tempfile << "# No. of students entered:- " << no_of_studs;

                tempfile << "#\t Mid Sem Marks:- ";
                for (int i = 0; i < s.no; i++)
                {                    
                    tempfile << s.midsem[i] << ' ';
                }

                tempfile << "#\t End Sem Marks:- ";
                for (int i = 0; i < s.no; i++)
                {   
                    tempfile << s.endsem[i] << ' ';
                }

                tempfile << "#\t Grade in each subject:- ";
                for (int i = 0; i < s.no; i++)
                    tempfile << s.grade[i] << ' ';

                tempfile << "\n";

                cout << "Record updated successfully!" << endl;
            }
            else
            {
                tempfile << line << endl;
            }
        }
      string studs_id = to_string(a.studs_ID);
line = "# Name:- " + a.name + "# Student ID:- " + studs_id + "# Adhaar:- " + to_string(a.aadhar) + "# Address:- " + a.address + "# Section:- " + a.sect;
tempfile.close();
        a.update(line,id);
        infile.close();
        

        // Rename the temporary file to the original file
        remove("Students.txt");
        rename("temp.txt", "Students.txt");
    }
    else
    {
        cout << "Error opening the file!" << endl;
    }
    }
    };
	};
	int CSE_Studs::no = 0;

class CSE_Faculty : virtual public Admin
 {
 	private:
    static int no;   //number of faculty
    int facs_ID;
    int choice;
    float salary;
    string designation;
    friend class HOD;

public:
    static int no_of_facs() {
        return ++no;
    }

    CSE_Faculty() {}

    ~CSE_Faculty() {}
    
    CSE_Faculty(char l) 
	{
        sect = l;
        no_of_facs();
        cout << "Enter Your ID ";
        cin >> facs_ID;
        get_data();
    }
    
         void faculty_details(int a=0)
	       {
                cout << "Enter your salary/stipend ";
                cin >> salary;
                cout << endl;
                cin.ignore();
                cout << "Enter your designation ";
                getline(cin, designation, '\n');
                cout << endl;
               
            }
  
     void display()    //display faculty records
	{
        cout << "----------------------------------------" <<endl;
        cout << "***Faculty Information:***" << endl;
        ifstream file("Faculty.txt");

    if (!file.is_open())
    {
    cout << "Unable to open the file!" << endl;
        return;
    }
    string line;
    while (getline(file, line,'#'))
    {
        cout << line <<endl;
    }
    file.close();
    cout << "----------------------------------------" <<endl;
        
    }

    void insert()   //insert into faculty and admin file
   {
        ofstream sfout("Faculty.txt", ios::app);
        ofstream afout("Admin.txt", ios::app);

        afout << "# faculty ID:- "<< facs_ID << "# Name:- " << name << "# Address:- " << address << "# Adhaar:- " << aadhar << "# Section:- " << sect<<"\n";
        
        sfout  << "# Name:-" << name << "# faculty ID:-" << facs_ID;
        
        cout << "Press 1 if you want to enter extra details ";
        cin >> choice;
        if (choice == 1){
        faculty_details();
        sfout << "# Salary of faculty:- " << salary << " # Designation:- " << designation << "\n";}
        sfout<<"\n";
        afout.close();
        sfout.close();
    }

void fupdate()
{
    int choices;
    ifstream infile("Faculty.txt");
    ofstream tempfile("temp1.txt", ios::out);
    string nameToUpdate;
    cin.ignore();
    cout << "Enter name to update: ";
    getline(cin,nameToUpdate,'\n');
    char section;
    cout << "Enter section: ";
    cin >> section;
    CSE_Faculty updatedFaculty(section);
    bool recordFound = false;
    if (infile.is_open() && tempfile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            size_t pos = line.find(nameToUpdate);
            if (pos != string::npos)
            {
                recordFound = true;
                tempfile<< "# Name:- " << updatedFaculty.name << "# faculty ID:- " << updatedFaculty.facs_ID;
                cout << "Do you want to enter extra information? Press 1: ";
                cin >> choices;
                if (choices == 1)
                {
                    updatedFaculty.faculty_details(1);
                

                tempfile << "# Salary of faculty:- " << updatedFaculty.salary << " # Designation:- " << updatedFaculty.designation << "\n";
                }
                tempfile<<"\n";
                cout << "Record updated successfully!" << endl;
            }
            else
            {
                tempfile << line << endl;
            }
        }
 string studs_id = to_string(updatedFaculty.facs_ID);
line = " Name:- " + updatedFaculty.name + "# Faculty ID:- " + studs_id + "# Adhaar:- " + to_string(updatedFaculty.aadhar) + "# Address:- " + updatedFaculty.address + "# Section:- " + updatedFaculty.sect;
        tempfile.close();
        
        // Close the files
        infile.close();
        //tempfile.close();

        if (!recordFound)
        {
            cout << "Record not found!" << endl;
            remove("temp1.txt");
        }
        else
        {
            remove("Faculty.txt");
            rename("temp1.txt", "Faculty.txt");
        }
        update(line,nameToUpdate);
    }
    else
    {
        cout << "Error opening the file!" << endl;
    }
    
}
};

int CSE_Faculty::no = 0;

class PHD : public CSE_Studs, public CSE_Faculty
{
public:
    int ID;
    friend class HOD;

    PHD() 
	{
        get_data();         //get name,address,aadhar,section
        cout << "Enter your ID ";
        cin >> ID;
    }

    void display() 
	{
        cout << "--------------------------------" <<endl;
        cout << "*** PHD Information: ***" << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Aadhar: " << aadhar << endl;
        cout << "Section: " << sect << endl;
        cout << "Student ID: " << studs_ID << endl;
        cout << "PHD ID: " << ID << endl;
        cout << "--------------------------------" <<endl;
    }
};

inline int menu()
 {
    int choice;
    cout << "\nNITJ CSE DEPARTMENT RECORD:";
    cout << "\n1.Insert Student record";
    cout << "\n2.Insert Faculty record";
    cout << "\n3.Update Student record";
    cout << "\n4.Update Faculty record";
    cout << "\n5.Display Student Information";
    cout << "\n6.Display Faculty Information";
    cout << "\n7.Display PHD Information";
    cout << "\n8.Display HOD Information";
    cout << "\n9.Enter any other key to exit";
    cout << "\nEnter your choice : "<<endl;
    cin >> (choice);
    return (choice);
}

int main()
 {
 	cout<<"*******WELCOME TO NITJ MANAGEMENT SYSTEM*******"<<endl<<endl;
    while (true) 
	{
        switch (menu()) 
		{
        case 1: {
            CSE_Studs::Students s(1);
            s.insert();
            break;
        }
        case 2: {
            char c;
            cout << "Enter the section ";
            cin >> c;
            CSE_Faculty f(c);
            f.insert();
            break;
        }
        case 3: {
            CSE_Studs::Students s;
            s.supdate();
            break;
        }
        case 4: {
            CSE_Faculty f;
            f.fupdate();
            break;
        }
        case 5: {
            CSE_Studs s;
            s.display();
            break;
        }
        case 6: {
            CSE_Faculty f;
            f.display();
            break;
        }
        case 7: {
            PHD p;
            p.display();
            break;
        }
        case 8: {
            HOD hod;
            cout<<endl;
            break;
        }
        default:
            exit(1);
        }
    }
    return 0;
}