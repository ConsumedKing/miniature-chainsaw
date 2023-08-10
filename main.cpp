#include<bits/stdc++.h>
using namespace std;
class Faculty;
class department;
class University;
class course;

class person {
	public:
		string name;
		int age;
		int id;
		virtual void role() = 0;
};

class student : public person {
	public:
		float gpa;
		void role() {
			cout << "I'm  a student" << endl;
		}
};

class instructor : public person {
	public:
		void role() {
			cout << "I'm  an instructor" << endl;
		}
};

class employee : public person {
	public:
		int salary;
		void role() {
			cout << "I'm an employee" << endl;
		}
};

class manager : public person {
	public:
		static manager* instance;
		void role() {
			cout << "I'm a manager" << endl;
		}
		static manager *make() {
			if (instance == nullptr)
				instance = new manager();
			return instance;
		}
	private:
		int salary;
		void setSalary(int toSet) {
			manager::salary = toSet;
		}
		int getSalary() {
			return manager::salary;
		}
		manager() {}
};

manager *manager::instance = nullptr;

class course {
	public :
		string title;
		int icourse_id;

		void details() {
			cout << "course name : " << course  :: title << endl;
			cout << "icourse_id is : " << course::icourse_id << endl;
		}
};

class department {
	public:
		string title;
		vector <course> Courses;

		void details() {
			cout << "course name : " << department::title << endl;
			for (auto i : department::Courses) {
				cout << i.title << endl;
			}
		}
		void addcourse() {
			string title;
			cout << "Enter The name of Course" << endl;
			cin >> title;

			ofstream file("courses.txt", ios::app);
			file << title << endl;

			course new_course;
			new_course.title = title;
			department::Courses.push_back(new_course);
		}
};

class Faculty {
public:
	string title;
	vector <student> Students;
	vector <instructor> Instructors;
	vector <employee> Employees;
	vector <department> Departments;

	void details(){
		cout << "University name is :  " << Faculty:: title << endl;

		cout << "Do you want to list Students, Instructors, Employess and Departments ? Press y to list them " << endl;

		char input_select; cin >> input_select; 
		if (input_select == 'y'){
			cout << "-------------------Students---------------------------" << endl;
			ifstream infile;
			infile.open("students.txt");
			string name_student;
			while(getline(infile, name_student)){
				cout << name_student << endl;
			}
			cout << "-------------------Instructors---------------------------" << endl;
			ifstream infile1;
			infile1.open("Instructors.txt");
			string name_instructor;
			while(getline(infile1, name_instructor)){
				cout << name_instructor << endl;
			}
			cout << "-------------------Employees---------------------------" << endl;
			ifstream infile2;
			infile2.open("Employees.txt");
			string name_employee;
			while(getline(infile2, name_employee)){
				cout << name_employee << endl;
			}
			cout << "-------------------Departments---------------------------" << endl;
			ifstream infile3;
			infile3.open("Departments.txt");
			string name_department;
			while(getline(infile3, name_department)){
				cout << name_department << endl;
			}
		}

	}
	void addStudent(){
		string name;
		cout << "Enter The name of Student" << endl;
		cin >> name;

		ofstream file("students.txt", ios::app);
		file << name << endl;

		student new_student;
		new_student.name = name;
		Faculty::Students.push_back(new_student);
	};
	void addInstructor(){
		string name;
		cout << "Enter The name of Instructor" << endl;
		cin >> name;

		ofstream file("Instructors.txt", ios::app);
		file << title << endl;

		instructor new_ins;
		new_ins.name = name;
		Faculty::Instructors.push_back(new_ins);
	};
	void addEmployee(){
		string name;
		cout << "Enter The name of Employee" << endl;
		cin >> name;

		ofstream file("Employees.txt", ios::app);
		file << title << endl;

		employee new_emp;
		new_emp.name = name;
		Faculty::Employees.push_back(new_emp);
	};
	void addDepartments(){
		string name;
		cout << "Enter The name of Departments" << endl;
		cin >> name;

		ofstream file("Departments.txt", ios::app);
		file << title << endl;

		department new_emp;
		new_emp.title = name;
		Faculty::Departments.push_back(new_emp);
	};
};

class University {
public:
	string title;
	vector<Faculty>faculties;
	// don't forget to put the instance in the main file
	manager* manageri = manager::instance;
	void detials() {
		cout << "University name : " << University::title << endl;
		cout << "Manager name : " << University::manageri->name << endl;
		cout << "All Faculties : " << endl;
		for (auto i : faculties) {
			cout << i.title << endl;
		}
	}
	void addFaculty() {
		string input;
		cout << "Enter The name of the faculty" << endl;
		cin >> input;

		ofstream file("faculties.txt", ios::app);
		file << input << endl;

		Faculty new_faculty;
		new_faculty.title = input;
		University::faculties.push_back(new_faculty);
	}

};

int main() {
	manager * manager_ptr = manager::make();
	University university;
	university.title = "Sohag";
	manager_ptr->name = "Eng/Ahmed";
	university.manageri = manager_ptr;
	university.detials();
	university.addFaculty();
	university.detials();
	Faculty fac;
	fac.addStudent();
	fac.addStudent();
	fac.title = "Computer Science";
	fac.details();
	

	return 0;
}
