//Sorting and Searching Student Names

//This program reads in a list of student names from a file, allows the user to search
//for specific name using linear search, and then sorts the name in ascending or descending order using bubble sort


//Files Required:
//1. StudentNames.txt- names of 10 students

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

void readNames(ifstream &inputFile, string names[],int numNames);
void displayNames(const string names[],int numNames);
int searchNames(const string names[],int numNames,const string &name);
void displaySearchNames(const string names[],int numNames,const string &name);
void swapValues(string &a,string &b);
void bubbleSort(string names[],int numNames);
void bubbleSortDescending(string names[],int numNames);

int main(){
    const int NUM_Names=10;
    string names[NUM_Names];
    string name;
    ifstream inputFile("StudentNames.txt");

    readNames(inputFile,names,NUM_Names);
    inputFile.close();

    cout<<"-------------------------\n"
    <<"\t Student Name\n"
    <<"-----------------------"<<endl;
    
    displayNames(names,NUM_Names);
    cout<<"\nFind a STudent place in the List\n"
    <<"Enter Student name(e.g ,.last name,first name):"<<endl;
    getline(cin,name);

    searchNames(names,NUM_Names,name);
    displaySearchNames(names,NUM_Names,name);

    cout<<"\nFina a Students place in the list\n"
    << "Enter Student name(e.g., last name,first name):"<<endl;
    getline(cin,name);

    searchNames(names,NUM_Names,name);
    displaySearchNames(names,NUM_Names,name);
    searchNames(names, NUM_Names, name);
    displaySearchNames(names, NUM_Names, name);

    cout << "\n---------------------------------\n"
         << " Student Names: Ascending Order\n"
         << "---------------------------------" << endl;

    bubbleSort(names, NUM_Names);
    displayNames(names, NUM_Names);

    searchNames(names, NUM_Names, name);
    displaySearchNames(names, NUM_Names, name);

    cout << "\n---------------------------------\n"
         << " Student Names: Descending Order\n"
         << "---------------------------------" << endl;

    bubbleSortDescending(names, NUM_Names);
    displayNames(names, NUM_Names);

    searchNames(names, NUM_Names, name);
    displaySearchNames(names, NUM_Names, name);

    return 0;



}

void readNames(ifstream &inputFile,string names[],int numNames){
    if(inputFile.is_open())
    for(int nameNumber=0; nameNumber<numNames; ++nameNumber)
    getline(inputFile,names[nameNumber]);
else
   cerr<<"Error: Unable to open file\n";
}

void displayNames(const string names[],int numNames){
    for(int nameNumber=0; nameNumber<numNames;++nameNumber)
    cout<<"\t"<<nameNumber+1<<""<<names[nameNumber]<<endl;
}

int searchNames(const string names[],int numNames,const string &name){
    int index=0,
    position=-1;
    bool found=false;
    while((index<numNames)&& !found){
        if(names[index]==name){
            found=true;
            position=index+1;
        }
        index++;
    }
    return position;
}

void displaySearchNames(const string names[],int numNames,const string &name){
    int position=searchNames(names,numNames,name);

    if(position==-1)
    cerr<<position<<"\n Name Not Found\n";
    else
    cout<<"\nName Found:"<<position<<endl;
}

void swapValues(string &a, string &b){
    string temp=a;
    a=b;
    b=temp;
}

//Bubble Sort algorithm (time complexity:0(n^2))

void bubbleSort(string names[],int numNames){
    bool swap;
    string temp;
    do{
        swap=false;
        for(int count=0; count<(numNames-1);++count){
            if(names[count]>names[count+1]){
                swapValues(names[count],names[count+1]);
                swap=true;
            }
        }
    }while(swap);
}

void bubbleSortDescending(string names[],int numNames){
    bool swap;
    string temp;

    do{
        swap=false;
        for(int count=0; count<(numNames-1);++count){
          if (names[count] < names[count + 1]) {
                swapValues(names[count], names[count + 1]);
                swap=true;
            }
        }
    }while(swap);
}