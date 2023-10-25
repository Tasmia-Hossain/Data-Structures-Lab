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

void Merge(vector<Student>& A, int low, int mid, int hi)
{
    int m = mid - low + 1;
    int n = hi - mid;
    vector<Student> L(m);
    vector<Student> R(n);
    int i, j;
    for (i = 0; i < m; i++)
    {
        L[i] = A[low + i];
    }
    for (j = 0; j < n; j++)
    {
        R[j] = A[mid + j + 1];
    }
    i = j = 0;
    int k = low;
    while (i < m && j < n)
    {
        if (L[i].cgpa > R[j].cgpa || (L[i].cgpa == R[j].cgpa && L[i].name < R[j].name))
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < m)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}


void Merge_sort(vector<Student>& A,int low,int hi)
{
    if(low<hi)
    {
        int mid=(low+hi)/2;
        Merge_sort(A,low,mid);
        Merge_sort(A,mid+1,hi);
        Merge(A,low,mid,hi);
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
    Merge_sort(students, 0, students.size() - 1);

    cout << "After Merge Sort: " << endl;
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
After Merge Sort:
ID: 15, Name: Sreya, CGPA: 3.99
ID: 38, Name: Kashfia, CGPA: 3.80
ID: 48, Name: Rima, CGPA: 3.25
*/
