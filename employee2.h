#pragma once
#include <iostream>
#define ListPtr Employee*
using namespace std;

enum EmployeeType {
	Staff,
	Freelance
};

class Employee {
private:
	string full_name;
	int year_of_hiring;
	int current_year;
	EmployeeType type;
	int basic_rate_for_month;
	int basic_rate_for_hour;
	double percent_of_individual_allowance;
	int number_of_hours_in_month;
public:
	void set_full_name(string full_name);
	void set_year_of_hiring(int year_of_hiring);
	void set_current_year (int current_year);
	void set_type (EmployeeType type);
	void set_basic_rate_for_month(int basic_rate_for_month);
	void set_basic_rate_for_hour(int basic_rate_for_hour);
	void set_percent_of_individual_allowance(double percent_of_individual_allowance);
	void set_number_of_hours_in_month(int number_of_hours_in_month);
	string get_full_name() const;
	int get_year_of_hiring() const;
	int get_current_year() const;
	EmployeeType get_type() const;
	int get_basic_rate_for_month() const;
	int get_basic_rate_for_hour() const;
	double get_percent_of_individual_allowance() const;
	int get_number_of_hours_in_month() const;
	int compute_salary() const;

    Employee();
	Employee(string full_name, int year_of_hiring, EmployeeType type, int basic_rate_for_month, int current_year);
	Employee(string full_name, int year_of_hiring, EmployeeType type, int basic_rate_for_hour, double percent_of_individual_allowance, int number_of_hours_in_month);
	Employee(const Employee& employer);

	void Swap(Employee& other) noexcept;
	Employee& operator=(Employee other);
	friend istream& operator>>(istream& in, Employee& item);
	friend ostream& operator<<(ostream& out, const Employee& item);
};

bool operator==(const Employee& item, const Employee& other);
bool operator!=(const Employee& item, const Employee& other);

class EmployeeList {
	ListPtr* _employee;
    size_t _size;

public:
	EmployeeList();
	EmployeeList(ListPtr* _employee, size_t _size);
	EmployeeList(ListPtr* _employee, size_t _size, int);
	~EmployeeList();

	ListPtr get_employee_by_index(int i);
	int get_size();
	void set_size(size_t size);

	ListPtr operator[](int index) const;
	ListPtr& operator[](int index);
	EmployeeList& operator=(EmployeeList other);

	void add_item(int index, Employee employer);
	void del_item(int index);
	void clear();
	void print_current(int index);
	void show_all();
	void Swap(EmployeeList& other) noexcept;
	int find_with_max_salary();
};
