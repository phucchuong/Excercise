
#include"Node.h"
#include"People.h"
#include"Staff.h"
#include"Student.h"
#include"Teacher.h"

int main() {
	Date b(2, 2, 1999);
	float sc[] = { 9 };

	/*{
		Teacher *a = new Teacher;
		a->SetID(1);
		a->SetBirthday(1, 1, 1991);
		a->SetClass(11);
		a->SetDepartmentID(3);
		a->SetJoinedDate(6, 6, 2018);
		a->SetLevel(5);
		a->SetName("Nguyen Phuc Chuong");
		a->SetSubject1(MATHS);
		a->SetSubject2(ENGLISH);


		// cast to staff;
		cout << "Static_cast a pointer" << endl;
		Staff *staff = static_cast<Staff*>(a);
		staff->PrintInfo();

		cout << "\nDynamic_cast a pointer" << endl;
		Staff *staff2 = dynamic_cast<Staff*>(a);
		staff2->PrintInfo();
		//hai cai tren y nhau

		cout << "\nStatic_cast to staff" << endl;
		Staff staffi = static_cast<Staff>(*a);
		staffi.PrintInfo();
		//cout << "\ndynamic_cast to staff" << endl;
		//Staff staffd = dynamic_cast<Staff>(*a);
		//staffd.PrintInfo();
		// loi => dynamic_cast dung cho con tro.

		cout << "\nStatic_cast to people" << endl;
		People staffp = static_cast<People>(*a);
		staffp.PrintInfo();

		Teacher teacher = *a;
		delete a;
		teacher.PrintInfo();

		People people = static_cast<People>(teacher);
		people.PrintInfo();
	}*/

	//student cast to people
	Student *studentp = NULL;
	studentp = new Student;
	studentp->SetID(1);
	studentp->SetName("Chuong nguyen");
	studentp->SetBirthday(9, 5, 1997);
	studentp->SetGrade(12);
	studentp->SetNumofProject(2);
	studentp->SetScore(new float[2]{ 9,8 });
	studentp->PrintInfo();

	const Student* studentpc = studentp;

	Student * studentpnc = const_cast<Student*>(studentpc);

	People *people = dynamic_cast<People*>(studentpnc);
	people->PrintInfo();

	Teacher *teacher = dynamic_cast<Teacher*>(studentp);
	//teacher->PrintInfo();// gay ra loi do student ko co vung nho nhu cua teacher.

	//Teacher *teacher = static_cast<Teacher*>(studentp);
	//=> loi

	Student student = *studentp;
	delete studentp;
	
	People peo = static_cast<People>(student);
	peo.PrintInfo();

	//Teacher teacher = static_cast<Teacher>(student);
	//=> khong duoc phep ?

	return 0;
}