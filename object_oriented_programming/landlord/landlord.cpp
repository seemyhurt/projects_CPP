// landlord.cpp
// ���������� ������� ��� ������ ����
#include "landlord.h" // ��� ���������� ������, � �.�.
#include <algorithm> // ��� sort()
#include <numeric> // ��� accumulate()
//////////////////////global functions////////////////////
void getaLine(string & inStr) // ��������� ������ ������
{
	char temp[21];
	cin.get(temp, 20, '\n');
	cin.ignore(20, '\n');
	inStr = temp;
}
//---------------------------------------------------------
char getaChar() // ��������� �������
{
	char ch = cin.get();
	cin.ignore(80, '\n');
	return ch;
}
//---------------------------------------------------------
////////////////������ ������ tenant///////////////////////
tenant::tenant(string n, int aNo) : name(n), aptNumber(aNo)
{ /* ��� ����� */
}
//---------------------------------------------------------
tenant::~tenant()
{ /* ��� ���� ����� */
}
//---------------------------------------------------------
int tenant::getAptNumber()
{
	return aptNumber;
}
//---------------------------------------------------------
bool operator<(const tenant& t1, const tenant& t2)
{
	return t1.name < t2.name;
}
//---------------------------------------------------------
bool operator==(const tenant& t1, const tenant& t2)
{
	return t1.name == t2.name;
}
//---------------------------------------------------------
ostream& operator<<(ostream& s, const tenant& t)
{
	s << t.aptNumber << '\t' << t.name << endl; return s;
}
//---------------------------------------------------------
///////////����� ������ tenantInputScreen//////////////////
void tenantInputScreen::getTenant() // ��������� ������ �
{ // �������
	cout << "������� ��� ������ (���� �����): ";
	getaLine(tName);
	cout << "������� ����� ������� (101): ";
	cin >> aptNo;
	cin.ignore(80, '\n'); // ������� ������
	tenant* ptrTenant = new tenant(tName, aptNo);
	ptrTenantList->insertTenant(ptrTenant); // ������� �
	// ������ �������
}
///////////////////////////////////////////////////////////
bool compareTenants::operator()(tenant* ptrT1,
	tenant* ptrT2) const
{
	return *ptrT1 < *ptrT2;
}
//---------------------------------------------------------
////////////////������ ������ tenantList///////////////////
tenantList::~tenantList() // ����������
{
	while (!setPtrsTens.empty()) // �������� ���� �������,
	{ // �������� ���������� ��
	// ���������
		iter = setPtrsTens.begin();
		delete* iter;
		setPtrsTens.erase(iter);
	}
} // end ~tenantList()
//---------------------------------------------------------
void tenantList::insertTenant(tenant* ptrT)
{
	setPtrsTens.insert(ptrT); // �������
}
//---------------------------------------------------------
int tenantList::getAptNo(string tName) // ��� ������������
// � ������?
{
	int aptNo;
	tenant dummy(tName, 0);
	iter = setPtrsTens.begin();
	while (iter != setPtrsTens.end())
	{
		aptNo = (*iter)->getAptNumber(); // ����� ������
		if (dummy == **iter++) // � ������?
			return aptNo; // ��
	}
	return -1; // ���
}
//---------------------------------------------------------
void tenantList::display() // ����� ������ �������
{
	cout << "\nApt#\t��� ������\n-------------------\n";
	if (setPtrsTens.empty())
		cout << "***��� �������***\n";
	else
	{
		iter = setPtrsTens.begin();
		while (iter != setPtrsTens.end())
			cout << **iter++;
	}
} // end display()
//---------------------------------------------------------
/////////////////������ ������ rentRow/////////////////////
rentRow::rentRow(int an) : aptNo(an) // 1-���. �����������
{
    fill(&rent[0], &rent[12], 0.f);
}
//---------------------------------------------------------
void rentRow::setRent(int m, float am)
{
	rent[m] = am;
}
//---------------------------------------------------------
float rentRow::getSumOfRow() // ����� �������� ��������
// � ������
{
    return accumulate(&rent[0], &rent[12], 0.f);
}
//---------------------------------------------------------
bool operator<(const rentRow& t1, const rentRow& t2)
{
	return t1.aptNo < t2.aptNo;
}
//---------------------------------------------------------
bool operator==(const rentRow& t1, const rentRow& t2)
{
	return t1.aptNo == t2.aptNo;
}
//---------------------------------------------------------
ostream& operator<<(ostream& s, const rentRow& an)
{
	s << an.aptNo << '\t'; // ������� ����� �������
	for (int j = 0; j < 12; j++) // ������� 12 ��������
		// ��������
	{
		if (an.rent[j] == 0)
			s << " 0 ";
		else
			s << an.rent[j] << " ";
	}
	s << endl;
	return s;
}
///////////////////////////////////////////////////////////
bool compareRows::operator()(rentRow* ptrR1,
	rentRow* ptrR2) const
{
	return *ptrR1 < *ptrR2;
}
/////////////////������ ������ rentRecord//////////////////
rentRecord::~rentRecord() // ����������
{
	while (!setPtrsRR.empty()) // ������� ������
		// � ���������,
	{ // ������� ��������� �� ���������
		iter = setPtrsRR.begin();
		delete* iter;
		setPtrsRR.erase(iter);
	}
}
//---------------------------------------------------------
void rentRecord::insertRent(int aptNo, int month, float amount)
{
	rentRow searchRow(aptNo); // ��������� ������
	// � ��� �� aptNo
	iter = setPtrsRR.begin(); // ����� setPtrsRR
	while (iter != setPtrsRR.end())
	{
		if (searchRow == **iter) // rentRow ������?
		{ // ��, �������
			(*iter)->setRent(month, amount); // ������ �
			// ������
			return;
		}
		else
			iter++;
	} // �� ������
	rentRow* ptrRow = new rentRow(aptNo);// ����� ������
	ptrRow->setRent(month, amount); // ������� � ��� ������
	setPtrsRR.insert(ptrRow); // ������� ������ �
	// ������
} // ����� insertRent()
//---------------------------------------------------------
void rentRecord::display()
{
	cout << "\nAptNo\t��� ��� ��� ��� ��� ��� "
		<< "��� ��� ��� ��� ��� ���\n"
		<< "---------------------------------"
		<< "---------------------------------\n";
	if (setPtrsRR.empty())
		cout << "***��� ��������!***\n";
	else
	{
		iter = setPtrsRR.begin();
		while (iter != setPtrsRR.end())
			cout << **iter++;
	}
}
//---------------------------------------------------------
float rentRecord::getSumOfRents() // ����� ���� ��������
{
	float sumRents = 0.0;
	iter = setPtrsRR.begin();
	while (iter != setPtrsRR.end())
	{
		sumRents += (*iter)->getSumOfRow();
		iter++;
	}
	return sumRents;
}
//---------------------------------------------------------
/////////////////������ ������ rentInputScreen/////////////
void rentInputScreen::getRent()
{
	cout << "������� ��� ������: ";
	getaLine(renterName);
	aptNo = ptrTenantList->getAptNo(renterName);
	if (aptNo > 0) // ���� ��� �������,
	{ // �������� ����� �������
		cout << "������� ����� ������� (345.67): ";
		cin >> rentPaid;
		cin.ignore(80, '\n');
		cout << "������� ����� ������ ������ (1-12): ";
		cin >> month;
		cin.ignore(80, '\n');
		month--; // (���������� ��������� 0-11)
		ptrRentRecord->insertRent(aptNo, month, rentPaid);
	}
	else // �������
		cout << "������ ������ ���.\n";
} // end getRent()
//---------------------------------------------------------
///////////////////������ ������ expense///////////////////
bool operator<(const expense& e1, const expense& e2)
{ // ���������� ����
	if (e1.month == e2.month) // ���� ��� �� �����,
		return e1.day < e2.day; // �������� ���
	else // �����,
		return e1.month < e2.month; // �������� ������
}
//---------------------------------------------------------
bool operator==(const expense& e1, const expense& e2)
{
	return e1.month == e2.month && e1.day == e2.day;
}
//---------------------------------------------------------
ostream& operator<<(ostream& s, const expense& exp)
{
	s << exp.month << '/' << exp.day << '\t' << exp.payee << '\t';
	s << exp.amount << '\t' << exp.category << endl;
	return s;
}
//---------------------------------------------------------
///////////////////////////////////////////////////////////
bool compareDates::operator()(expense* ptrE1,
	expense* ptrE2) const
{
	return *ptrE1 < *ptrE2;
}
//---------------------------------------------------------
///////////////////////////////////////////////////////////
bool compareCategories::operator()(expense* ptrE1,
	expense* ptrE2) const
{
	return ptrE1->category < ptrE2->category;
}
//---------------------------------------------------------
//////////////////������ ������ expenseRecord//////////////
expenseRecord::~expenseRecord() // ����������
{
	while (!vectPtrsExpenses.empty()) // ������� �������
		// expense
	{ // �������
	// ��������� �� ������
		iter = vectPtrsExpenses.begin();
		delete* iter;
		vectPtrsExpenses.erase(iter);
	}
}
//---------------------------------------------------------
void expenseRecord::insertExp(expense* ptrExp)
{
	vectPtrsExpenses.push_back(ptrExp);
}
//---------------------------------------------------------
void expenseRecord::display()
{
	cout << "\n����\t����������\t\t�����\t���������\n"
		<< "----------------------------------------\n";
	if (vectPtrsExpenses.size() == 0)
		cout << "***�������� ���***\n";
	else
	{
		sort(vectPtrsExpenses.begin(), // ���������� �� ����
			vectPtrsExpenses.end(), compareDates());
		iter = vectPtrsExpenses.begin();
		while (iter != vectPtrsExpenses.end())
			cout << **iter++;
	}
}
//---------------------------------------------------------
float expenseRecord::displaySummary() // ������������ ���
// �����������
// �������� ������
{
	float totalExpenses = 0; // �����, ���
	// ���������
	if (vectPtrsExpenses.size() == 0)
	{
		cout << "\t��� ���������\t0\n";
		return 0;
	}
	// ����������� �� ���������
	sort(vectPtrsExpenses.begin(),
		vectPtrsExpenses.end(), compareCategories());
	// �� ������ ��������� ����� �������
	iter = vectPtrsExpenses.begin();
	string tempCat = (*iter)->category;
	float sumCat = 0.0;
	while (iter != vectPtrsExpenses.end())
	{
		if (tempCat == (*iter)->category)
			sumCat += (*iter)->amount; // �� �� ���������
		else
		{ // ������
			cout << '\t' << tempCat << '\t' << sumCat << endl;
			totalExpenses += sumCat; // ��������� ����������
			// ���������
			tempCat = (*iter)->category;
			sumCat = (*iter)->amount;// ��������� ��������
			// �������� �����
		}
		iter++;
	} // end while
	totalExpenses += sumCat; // ��������� �����
	// ��������
   // ���������
	cout << '\t' << tempCat << '\t' << sumCat << endl;
	return totalExpenses;
} // ����� displaySummary()
//--------------------------------------------------------
//////////////������ ������ expenseInputScreen/////////////
expenseInputScreen::expenseInputScreen(expenseRecord* per) :
	ptrExpenseRecord(per)
{ /*�����*/
}
//------------------------------------------------------
void expenseInputScreen::getExpense()
{
	int month, day;
	string category, payee;
	float amount;
	cout << "������� ����� (1-12): ";
	cin >> month;
	cin.ignore(80, '\n');
	cout << "������� ���� (1-31): ";
	cin >> day;
	cin.ignore(80, '\n');
	cout << "������� ��������� �������� (������, ������): ";
	getaLine(category);
	cout << "������� ���������� "
		<< "(������������������������): ";
	getaLine(payee);
	cout << "������� ����� (39.95): ";
	cin >> amount;
	cin.ignore(80, '\n');
	expense* ptrExpense = new
		expense(month, day, category, payee, amount);
	ptrExpenseRecord->insertExp(ptrExpense);
}
//---------------------------------------------------------
////////////////������ ������ annualReport/////////////////
annualReport::annualReport(rentRecord* pRR,
	expenseRecord* pER) : ptrRR(pRR), ptrER(pER)
{ /* ����� */
}
//---------------------------------------------------------
void annualReport::display()
{
	cout << "������� �����\n--------------\n";
	cout << "������\n";
	cout << "\t�������� �����\t\t";
	rents = ptrRR->getSumOfRents();
	cout << rents << endl;
	cout << "�������\n";
	expenses = ptrER->displaySummary();
	cout << "\n������\t\t\t" << rents - expenses << endl;
}
//---------------------------------------------------------
////////////////������ ������ userInterface//////////////
userInterface::userInterface()
{
	// ��� �������� ����� ��� ���������
	ptrTenantList = new tenantList;
	ptrRentRecord = new rentRecord;
	ptrExpenseRecord = new expenseRecord;
}
//---------------------------------------------------------
userInterface::~userInterface()
{
	delete ptrTenantList;
	delete ptrRentRecord;
	delete ptrExpenseRecord;
}
//---------------------------------------------------------
void userInterface::interact()
{
	while (true)
	{
		cout << "��� ����� ������ ������� 'i', \n"
			<< " 'd' ��� ������ ������, \n"
			<< " 'q' ��� ������: ";
		ch = getaChar();
		if (ch == 'i') // ���� ������
		{
			cout << " 't' ��� ���������� ������, \n"
				<< " 'r' ��� ������ �������� �����, \n"
				<< " 'e' ��� ������ ��������: ";
			ch = getaChar();
			switch (ch)
			{
				// ������ ����� ���������� ������ �� ����� ��
				// �������������
			case 't': ptrTenantInputScreen =
				new tenantInputScreen(ptrTenantList);
				ptrTenantInputScreen->getTenant();
				delete ptrTenantInputScreen;
				break;
			case 'r': ptrRentInputScreen =
				new rentInputScreen(ptrTenantList, ptrRentRecord);
				ptrRentInputScreen->getRent();
				delete ptrRentInputScreen;
				break;
			case 'e': ptrExpenseInputScreen =
				new expenseInputScreen(ptrExpenseRecord);
				ptrExpenseInputScreen->getExpense();
				delete ptrExpenseInputScreen;
				break;
			default: cout << "����������� �������\n";
				break;
			} // ����� ������ switch
		} // ����� ������� if
		else if (ch == 'd') // ����� ������
		{
			cout << " 't' ��� ������ �������, \n"
				<< " 'r' ��� ������ �������� �����\n"
				<< " 'e' ��� ������ ��������, \n"
				<< " 'a' ��� ������ �������� ������: ";
			ch = getaChar();
			switch (ch)
			{
			case 't': ptrTenantList->display();
				break;
			case 'r': ptrRentRecord->display();
				break;
			case 'e': ptrExpenseRecord->display();
				break;
			case 'a':
				ptrAnnualReport = new annualReport(ptrRentRecord, ptrExpenseRecord);
				ptrAnnualReport->display();
				delete ptrAnnualReport;
				break;
			default: cout << "����������� ������� ������\n";
				break;
			} // ����� switch
		} // ����� elseif
		else if (ch == 'q')
			return; // �����
		else
			cout << "����������� �������. ��������� ������ 'i', 'd' ��� 'q'\n";
	} // ����� while
} // ����� interact()
//////////////////����� ����� landlord.cpp//////////////////
