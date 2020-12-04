#include <iostream>
#include <fstream>
using namespace std;

class BookRecord{
    int examScores;
public:
    void input(){
        ofstream file;
        string name;
        file.open("scores.txt");
        int numOfStudents;
        cout<<"How many students do you want to capture their marks?"<<endl;
        cin>>numOfStudents;
        cout<<"Please Enter a name of a student and the score they have got e.g Sihle 81"<<endl;
        for(int i=0; i < numOfStudents; i++){
           cin>>name>>examScores;
           file<< name<< " "<<examScores<<endl;
        }
        file.close();
        cout<<"A file has been created with the information you provide. It can be located in the root folder."<<endl;

    }

    int calculateTotalScore(string name){
        ifstream inFile;
        inFile.open("scores.txt");
        string tempName;
        while(inFile>>tempName>>examScores){
            if(tempName==name){
                return examScores;
            }
        }
        return 0;
    }
};
int main()
{
    BookRecord record;
    record.input();
    string studentName;
    cout<<"Please Enter the name of the student that you want to get their marks "<<endl;
    cin>>studentName;
    int marks = record.calculateTotalScore(studentName);
    cout<<studentName<<" got "<<marks <<endl;
    return 0;
}
