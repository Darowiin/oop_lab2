#pragma warning(disable:6386)
#include <employee2/employee2.h>
#include <cmath>
#include <stdexcept>
#include <string>

//setters and getters
void Employee::set_full_name(string full_name) { this->full_name = full_name; }
void Employee::set_year_of_hiring(int year_of_hiring) { this->year_of_hiring = year_of_hiring; }
void Employee::set_current_year(int current_year) { this->current_year = current_year; }
void Employee::set_type(EmployeeType type) { this->type = type; }
void Employee::set_basic_rate_for_month(int basic_rate_for_month) { this->basic_rate_for_month = basic_rate_for_month; }
void Employee::set_basic_rate_for_hour(int basic_rate_for_hour) { this->basic_rate_for_hour = basic_rate_for_hour; }
void Employee::set_percent_of_individual_allowance(double percent_of_individual_allowance) { this->percent_of_individual_allowance = percent_of_individual_allowance; }
void Employee::set_number_of_hours_in_month(int number_of_hours_in_month) { this->number_of_hours_in_month = number_of_hours_in_month; }
string Employee::get_full_name() const { return full_name; }
int Employee::get_year_of_hiring() const { return year_of_hiring; }
int Employee::get_current_year() const { return current_year; }
EmployeeType Employee::get_type() const { return type; }
int Employee::get_basic_rate_for_month() const { return basic_rate_for_month; }
int Employee::get_basic_rate_for_hour() const { return basic_rate_for_hour; }
double Employee::get_percent_of_individual_allowance() const { return percent_of_individual_allowance; }
int Employee::get_number_of_hours_in_month() const { return number_of_hours_in_month;}
//c-tors and d-tors
Employee::Employee() {
	full_name = "default";
	year_of_hiring = 0;
	current_year = 0;
	type = Staff;
	basic_rate_for_month = 0;
	basic_rate_for_hour = 0;
	percent_of_individual_allowance = 0;
	number_of_hours_in_month = 0;
}
Employee::Employee(string full_name, int year_of_hiring, EmployeeType type, int basic_rate_for_month,int current_year) {
    this->full_name = full_name;
    this->year_of_hiring = year_of_hiring;
    this->type = type;
    this->basic_rate_for_month = basic_rate_for_month;
    this->current_year = current_year;
}
Employee::Employee(string full_name, int year_of_hiring, EmployeeType type, int basic_rate_for_hour,
    double percent_of_individual_allowance, int number_of_hours_in_month) {
    this->full_name = full_name;
    this->year_of_hiring = year_of_hiring;
    this->type = type;
    this->basic_rate_for_hour = basic_rate_for_hour;
    this->percent_of_individual_allowance = percent_of_individual_allowance;
    this->number_of_hours_in_month = number_of_hours_in_month;
}
Employee::Employee(const Employee& employer) {
	this->full_name = employer.full_name;
	this->year_of_hiring = employer.year_of_hiring;
	this->type = employer.type;
	if (type == Staff) {
		this->basic_rate_for_month = employer.basic_rate_for_month;
		this->current_year = employer.current_year;
	} else {
		this->basic_rate_for_hour = employer.basic_rate_for_hour;
		this->percent_of_individual_allowance = employer.percent_of_individual_allowance;
		this->number_of_hours_in_month = employer.number_of_hours_in_month;
	} 
}
EmployeeList::EmployeeList()
{
	this->_size = 5;
	_employee = new Employee * [_size];
	for (int i = 0; i < _size; ++i) _employee[i] = new Employee();
}
EmployeeList::EmployeeList(ListPtr* employees, size_t size) {
	this->_size = size;

	_employee = new Employee * [_size];
	for (int i = 0; i < size; ++i) {
		this->_employee[i] = new Employee();
		this->_employee[i]->set_full_name(employees[i]->get_full_name());
		this->_employee[i]->set_year_of_hiring(employees[i]->get_year_of_hiring());
		this->_employee[i]->set_type(employees[i]->get_type());
		this->_employee[i]->set_basic_rate_for_month(employees[i]->get_basic_rate_for_month());
		this->_employee[i]->set_current_year(employees[i]->get_current_year());
	}
}
EmployeeList::EmployeeList(ListPtr* employees, size_t size,int) {
	this->_size = size;

	_employee = new Employee * [_size];
	for (int i = 0; i < size; ++i) {
		this->_employee[i] = new Employee();
		this->_employee[i]->set_full_name(employees[i]->get_full_name());
		this->_employee[i]->set_year_of_hiring(employees[i]->get_year_of_hiring());
		this->_employee[i]->set_type(employees[i]->get_type());
		this->_employee[i]->set_basic_rate_for_hour(employees[i]->get_basic_rate_for_month());
		this->_employee[i]->set_percent_of_individual_allowance(employees[i]->get_percent_of_individual_allowance());
		this->_employee[i]->set_number_of_hours_in_month(employees[i]->get_number_of_hours_in_month());
	}
}
EmployeeList::EmployeeList(const EmployeeList& other):
	_employee(new ListPtr[other._size]),
	_size(other._size)
{
	for (int i = 0; i < _size; ++i) {
		_employee[i] = new Employee (*other._employee[i]);
	}
}
EmployeeList::~EmployeeList() {
	for (int i = 0; i < _size; ++i) { delete _employee[i]; }
	delete[] _employee;
}
//methods
int Employee::compute_salary() const {
    if (type == Staff) {
        int salary = basic_rate_for_month + ((current_year - year_of_hiring) * 0.005) * basic_rate_for_month;
        return salary;
    }
	if (type == Freelance) {
        int salary = ((1+(0.01*percent_of_individual_allowance)) * basic_rate_for_hour) * number_of_hours_in_month;
        return salary;
    }
}
int EmployeeList::find_with_max_salary() {
	int index = 0;
	double max_salary = _employee[0]->compute_salary();
	for (int i = 1; i <= _size - 1; ++i)
	{
		double cur_salary = _employee[i]->compute_salary();
		if (cur_salary > max_salary)
		{
			index = i;
			max_salary = cur_salary;
		}
	}
	return index;
}
//swaps and operators
void Employee::Swap(Employee& other) noexcept{
	swap(full_name, other.full_name);
	swap(year_of_hiring, other.year_of_hiring);
	swap(type, other.type);
	if (type == Staff) {
		swap(basic_rate_for_month, other.basic_rate_for_month);
		swap(current_year, other.current_year);
	}
	else if (type == Freelance){
		swap(basic_rate_for_hour, other.basic_rate_for_hour);
		swap(percent_of_individual_allowance, other.percent_of_individual_allowance);
		swap(number_of_hours_in_month, other.number_of_hours_in_month);
	}
}
void EmployeeList::Swap(EmployeeList& other) noexcept{
	swap(_employee, other._employee);
	swap(_size, other._size);
}
istream& operator>>(std::istream& in, EmployeeType& item_type) {
	int type;
	in >> type;
	switch (type) {
	case 0: 
		item_type = Staff;
		break;
	case 1:
		item_type = Freelance;
		break;
	default:
		throw std::runtime_error("Wrong type exception");
	}
	return in;
}
bool operator==(const Employee& item, const Employee& other) {
	if (item.get_type() == Staff)
		return (item.get_full_name() == other.get_full_name() && item.get_year_of_hiring() == other.get_year_of_hiring() && item.get_type() == other.get_type() && item.get_basic_rate_for_month() == other.get_basic_rate_for_month() && item.get_current_year() == other.get_current_year());
	else 
		return (item.get_full_name() == other.get_full_name() && item.get_year_of_hiring() == other.get_year_of_hiring() && item.get_type() == other.get_type() && item.get_basic_rate_for_hour() == other.get_basic_rate_for_hour() && item.get_percent_of_individual_allowance() == other.get_percent_of_individual_allowance() && item.get_number_of_hours_in_month() == other.get_number_of_hours_in_month());
}
bool operator!=(const Employee& item, const Employee& other) {
	return !(item == other);
}
bool operator==(const EmployeeList& list, const EmployeeList& other) {
	return (list._size == other._size && **(list._employee) == **(other._employee));
}
bool operator!=(const EmployeeList& list, const EmployeeList& other) {
	return !(list == other);
}
Employee& Employee::operator=(Employee other) {
	Swap(other);
	return *this;
}
EmployeeList& EmployeeList::operator=(EmployeeList other) {
	Swap(other);
	return *this;
}
ListPtr EmployeeList::operator[](int index) const {
	if (index < 0 || index >= _size)
	{
		throw runtime_error("Index out of range.");
	}
	return _employee[index];
}
ListPtr& EmployeeList::operator[](int index)
{
	if (index < 0 || index >= _size)
	{
		throw runtime_error("Index out of range.");
	}
	return _employee[index];
}
//getters and setter for list
ListPtr EmployeeList::get_employee_by_index(int index) { 
	return _employee[index]; 
}
int EmployeeList::get_size() { 
	return _size; 
}
void EmployeeList::set_size(size_t size) {
	_size = size;
}
//to change the array
void EmployeeList::add_item(int index, Employee employer) {
	if ((index < 0) || (index > _size)) {
		throw std::runtime_error("Index out of range.");
	}
	++_size;
	ListPtr* employees = new Employee * [_size];
	for (int i = 0; i < index; ++i) {
		employees[i] = new Employee(*this->_employee[i]);
	}
	employees[index] = new Employee(employer);
	for (int i = _size - 1; i > index; --i) {
		employees[i] = new Employee(*this->_employee[i - 1]);
	}
	swap(this->_employee, employees);
}
void EmployeeList::del_item(int index) {
	if (_size <= 0)
	{
		throw runtime_error("List is empty.");
	}
	for (int i = index; i < _size - 1; ++i) { _employee[i] = _employee[i + 1]; }
	--_size;
}
void EmployeeList::clear() {
	_employee = nullptr;
	_size = 0;
}
//for console
string string_employer_type(EmployeeType type) {
	switch (type) {
	case Staff:
		return "Staff";
	case Freelance:
		return "Freelance";
	default:
		throw std::runtime_error("Wrong type exception");
	}
	return "";
}
istream& operator>>(istream& in, Employee& item) {
	cout << "Choose employer type:\n 0 - Staff\n 1 - Freelance\n ";
	in >> item.type;
	if (item.type == Staff) {
		cout << "Enter name:\n ";
		in >> item.full_name;
		cout << "Enter year of hiring:\n ";
		in >> item.year_of_hiring;
		cout << "Enter basic rate for month:\n ";
		in >> item.basic_rate_for_month;
		cout << "Enter current year:\n ";
		in >> item.current_year;
		return in;
	}
	else {
		cout << "Enter name:\n ";
		in >> item.full_name;
		cout << "Enter year of hiring:\n ";
		in >> item.year_of_hiring;
		cout << "Enter basic rate for hour:\n ";
		in >> item.basic_rate_for_hour;
		cout << "Enter percent of individual allowance(0-5):\n ";
		in >> item.percent_of_individual_allowance;
		cout << "Enter number of hours in month:\n";
		in >> item.number_of_hours_in_month;
		return in;
	}
}
ostream& operator<<(ostream& out, const Employee& item) {
	if (item.type == Staff) {
		return out << "Staff(" << item.full_name << ',' << item.year_of_hiring << ',' << item.type << ',' << item.basic_rate_for_month << ',' << item.current_year << ')';
	}
	else {
		return out << "Freelance(" << item.full_name << ',' << item.year_of_hiring << ',' << item.type << ',' << item.basic_rate_for_hour << ',' << item.percent_of_individual_allowance << ',' << item.number_of_hours_in_month << ')';
	}
}
void EmployeeList::print_current(int index) {
	cout <<* _employee[index];
}
void EmployeeList::show_all() {
	cout << "Текущий список:\n";
	for (int i = 0; i < _size; ++i) {
		cout << i << ':';
		print_current(i);
		cout << endl;
	}
}