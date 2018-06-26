//#include "Node.h"
//
//
//Node::Node()
//{
//}
//
//Node::~Node()
//{
//}
//
//Node::Node(People * p)
//{
//	Data = p;
//}
//
//Node::Node(const Node & a)
//{
//	type type = a.Data->Getinstance();
//	switch (type)
//	{
//	case people:
//		Data = new People(*a.Data);
//		pnext = NULL;
//		break;
//	case staff:
//		Data = new Staff(*static_cast<Staff*>(a.Data));
//		pnext = NULL;
//		break;
//	case teacher:
//		Data = new Teacher(*static_cast<Teacher*>(a.Data));
//		pnext = NULL;
//		break;
//	case student:
//		Data = new Student(*static_cast<Student*>(a.Data));
//		pnext = NULL;
//		break;
//	}
//}
//
//void Node::Input(List &L)
//{
//	bool cont = true;
//	int choice;
//	List temp = NULL;
//
//	while (cont) {
//		temp = new Node;
//		do {
//			cout << "1.Staff" << setw(10)
//				<< "1.Student" << setw(10) << "3.Teacher" << endl;
//			cin >> choice;
//			switch (choice)
//			{
//			case 1:
//				temp->Data = new Staff;
//				break;
//			case 2:
//				temp->Data = new Student;
//				break;
//			case 3:
//				temp->Data = new Teacher;
//				break;
//			default:
//				cout << "don't have this choice !" << endl;
//				break;
//			}
//		} while (choice < 1 || choice >3);
//
//		temp->Data->input();
//
//		if (!L) {
//			L = temp;
//		}
//		else {
//			static List q = L;
//			while (q->pnext) q = q->pnext;
//			q->pnext = temp;
//		}
//
//		cout << "continue (y/n)?" << endl;
//		cin.clear();
//		rewind(stdin);
//		if (getchar() == 'n') cont = false;
//	}
//}
//
//void Node::Show()
//{
//	Node *p = this;
//	while (p) {
//		p->Data->PrintInfo();
//		p = p->pnext;
//		cout << endl;
//	}
//}
//
//void Node::Add(List & L, Node * p)
//{
//	if (!L) {
//		L = p;
//	}
//	else {
//		Node* q = L;
//		while (q->pnext) q = q->pnext;
//		q->pnext = p;
//	}
//}
//
//void Node::Avrthan5()
//{
//	List l = this;
//	while (l) {
//		if (l->Data->Getinstance() == student) {
//			Student *p = static_cast<Student*>(l->Data);
//			if (p->GetAvrScore() > 5) {
//				l->Data->PrintInfo();
//				cout << endl;
//			}
//		}
//		l = l->pnext;
//	}
//}
//
//void Node::SortbyType(List &L)
//{
//	if (L) {
//		if (L->pnext) {//co nhieu hon 1 node moi can sap xep
//			List p = L, end = NULL;
//			while (p->pnext) p = p->pnext;
//			end = p;//giu lai node cuoi cung cua danh sach duoc dau vao
//			
//			p = L;
//			while (p != end) {
//				if (p->Data->Getinstance() == teacher) {
//					List temp = p;
//					p = p->pnext;
//					if (temp == L) {		//neu la node dau thi 
//						L = L->pnext;		//tro head tro tiep toi pnext
//						List ptail = L;
//						while (ptail&&ptail->pnext) {
//							ptail = ptail->pnext;
//						}
//						ptail->pnext = temp;
//						temp->pnext = NULL;		//node dua xuong cuoi =>pnext=NULL
//					}
//					else {
//						List pretemp = L;
//						while (pretemp->pnext != temp) pretemp = pretemp->pnext;
//						pretemp->pnext = pretemp->pnext->pnext;
//						List ptail = L;
//						while (ptail&&ptail->pnext) ptail = ptail->pnext;
//						ptail->pnext = temp;
//						temp->pnext = NULL;		//node dua xuong cuoi =>pnext=NULL
//					}
//				}
//				else {
//					p = p->pnext;
//				}
//			}
//			p = L;
//			// sap xep cac node hoc sinh ve cuoi.
//			while (p != end) {
//				if (p->Data->Getinstance() == student) {
//					List temp = p;
//					p = p->pnext;
//					if (temp == L) {		//neu la node dau thi 
//						L = L->pnext;		//tro head tro tiep toi pnext
//						List ptail = L;
//						while (ptail&&ptail->pnext) {
//							ptail = ptail->pnext;
//						}
//						ptail->pnext = temp;
//						temp->pnext = NULL;		//node dua xuong cuoi =>pnext=NULL
//					}
//					else {
//						List pretemp = L;
//						while (pretemp->pnext != temp) pretemp = pretemp->pnext;
//						pretemp->pnext = pretemp->pnext->pnext;
//						List ptail = L;
//						while (ptail&&ptail->pnext) ptail = ptail->pnext;
//						ptail->pnext = temp;
//						temp->pnext = NULL;		//node dua xuong cuoi =>pnext=NULL
//					}
//				}
//				else {
//					p = p->pnext;
//				}
//			}
//			if (p->Data->Getinstance() == student) {
//				List pretemp = L;
//				while (pretemp->pnext != p) pretemp = pretemp->pnext;
//				pretemp->pnext = pretemp->pnext->pnext;
//				List ptail = L;
//				while (ptail&&ptail->pnext) {
//					ptail = ptail->pnext;
//				}
//				ptail->pnext = p;
//				p->pnext = NULL;
//			}
//		}
//	}
//}
//
//List Node::Clone()
//{
//	List list = NULL;
//	if (this) {
//		List temp = this;
//		while (temp) {
//			if (list) {
//				static Node *p = list;
//				while (p->pnext) p = p->pnext;
//				p->pnext = new Node(*temp);
//			}
//			else {
//				list = new Node(*temp);
//			}
//			temp = temp->pnext;
//		}
//	}
//	return list;
//}
//
//void Node::Remove(Node *& p)
//{
//	//delete p->Data;
//	//p = NULL;
//
//	switch (p->Data->Getinstance())
//	{
//	case staff:
//		delete static_cast<Staff*>(p->Data);
//		break;
//	case teacher:
//		delete static_cast<Teacher*>(p->Data);
//		break;
//	case student:
//		delete static_cast<Student*>(p->Data);
//		break;
//	}
//	p = NULL;
//}
//
//void Node::RemoveList(List & p)
//{
//	while (p) {
//		List temp = p;
//		p = p->pnext;
//		Node::Remove(temp);
//	}
//}
//
//void Node::WritetoFile(ofstream &f)
//{
//	List l = this;
//	while (l) {
//		switch (l->Data->Getinstance())
//		{
//		case student:
//			f << 3 << " ";
//			static_cast<Student*>(l->Data)->WtoF(f);
//			f << endl;
//			break;
//		case staff:
//			f << 1 << " ";
//			static_cast<Student*>(l->Data)->WtoF(f);
//			f << endl;
//			break;
//		case teacher:
//			f << 2 << " ";
//			static_cast<Student*>(l->Data)->WtoF(f);
//			f << endl;
//			break;
//		default:
//			break;
//		}
//		l = l->pnext;
//	}
//}
//
//List Node::ReadfromFile(ifstream & f)
//{
//	List l = NULL, temp = NULL;
//	int is;
//	while (f >> is) {
//		
//		temp = new Node;
//		switch (is)
//		{
//		case 1:
//			temp->Data = new Staff;
//			temp->Data->RfromF(f);
//			temp->Add(l, temp);
//			break;
//		case 2:
//			temp->Data = new Teacher;
//			temp->Data->RfromF(f);
//			temp->Add(l, temp);
//			break;
//		case 3:
//			temp->Data = new Student;
//			temp->Data->RfromF(f);
//			temp->Add(l, temp);
//			break;
//		default:
//			static int i = 0;
//			cout << "loi doc thu " << ++i;
//			delete temp;
//			break;
//		}
//		is = 0;
//	}
//	return l;
//}
//
