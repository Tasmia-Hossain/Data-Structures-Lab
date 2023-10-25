#include<bits/stdc++.h>
using namespace std;

struct Student
{
    string id,name;
    double cgpa;

    Student()
    {
        id=name=" ";
        cgpa=0.0;
    }
    Student(string id,string name,double cgpa)
    {
        this->id = id;
        this->name = name;
        this->cgpa = cgpa;
    }
};
int Partition(vector<Student>& A,int low,int hi)
{
    double pivot=A[low].cgpa;
    int i=low;
    int j=hi;
    while(i<j)
    {
        while(A[i].cgpa>=pivot)
        {
            if (A[i].cgpa == pivot && (A[i].name)>(A[low].name))
                break;
            i++;
        }
        while(A[j].cgpa<pivot)
        {
            if (A[j].cgpa == pivot && (A[j].name)<(A[low].name))
                break;
            j--;
        }
        if(i<j)
        {
            swap(A[i],A[j]);
        }
    }
    swap(A[low],A[j]);
    return j;
}

void quicksort(vector<Student>& A,int low,int hi)
{
    if(low<hi)
    {
        int pos=Partition(A,low,hi);
        quicksort(A,low,pos-1);
        quicksort(A,pos+1,hi);
    }
}

int main()
{
     int n;
    cout << "Enter the number of students: ";
    cin >> n;

    string id, name;
    double cgpa;
    vector<Student>students;

    for(int i=0;i<n;i++)
    {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "CGPA: ";
        cin >> cgpa;
        students.push_back(Student(id, name, cgpa));
    }
    quicksort(students, 0, students.size() - 1);

    cout << "After Quick Sort: " << endl;
    for (int i = 0; i <n; i++)
    {
        cout << "ID: " << students[i].id << ", Name: " << students[i].name << ", CGPA: " << students[i].cgpa << endl;
    }

    return 0;
}

//Output:
/*
Enter the number of students: 3
Enter details for student 1:
ID: 38
Name: Kashfia
CGPA: 3.80
Enter details for student 2:
ID: 48
Name: Rima
CGPA: 3.25
Enter details for student 3:
ID: 15
Name: Sreya
CGPA: 3.99
After Quick Sort:
ID: 15, Name: Sreya, CGPA: 3.99
ID: 38, Name: Kashfia, CGPA: 3.80
ID: 48, Name: Rima, CGPA: 3.25
*/
