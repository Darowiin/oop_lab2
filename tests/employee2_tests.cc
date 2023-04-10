#include <gtest/gtest.h>
#include <employee2/employee2.h>
#define ListPtr Employee*

TEST(EmployeeTests, EmployeeDefaultConstructorNameTest) {
    Employee person1 = Employee();
    EXPECT_EQ(person1.get_full_name(),"default");
}
TEST(EmployeeTests, EmployeeDefaultConstructorYearOfHiringTest) {
    Employee person1 = Employee();
    EXPECT_EQ(person1.get_year_of_hiring(), 0);
}
TEST(EmployeeTests, EmployeeDefaultConstructorBasicRateForMonthTest) {
    Employee person1 = Employee();
    EXPECT_EQ(person1.get_basic_rate_for_month(), 0);
}
TEST(EmployeeTests, EmployeeDefaultConstructorBasicRateForHourTest) {
    Employee person1 = Employee();
    EXPECT_EQ(person1.get_basic_rate_for_hour(), 0);
}
TEST(EmployeeTests, EmployeetConstructorTest) {
    Employee person1 = Employee("Vladimir Petrov",2020,Staff,45000,2023);
    EXPECT_EQ(person1.get_full_name(), "Vladimir Petrov");
}
TEST(EmployeeTests, EmployeetConstructorTest2) {
    Employee person1 = Employee("Vladimir Petrov", 2020, Staff, 45000, 2023);
    EXPECT_EQ(person1.get_current_year(), 2023);
}
TEST(EmployeeTests, EmployeetConstructorTest3) {
    Employee person1 = Employee("Sergey Smirnov", 2020, Freelance, 200, 2.5, 150);
    EXPECT_EQ(person1.get_type(), Freelance);
}
TEST(EmployeeTests, EmployeetConstructorTest4) {
    Employee person1 = Employee("Sergey Smirnov", 2020, Freelance, 200, 2.5, 150);
    EXPECT_EQ(person1.get_percent_of_individual_allowance(), 2.5);
}
TEST(EmployeeTests, EmployeeSetterTest) {
    Employee person1;
    person1.set_type(Staff);
    EXPECT_EQ(person1.get_type(),Staff);
}
TEST(EmployeeTests, EmployeeSetterTest2) {
    Employee person1;
    person1.set_year_of_hiring(2019);
    EXPECT_EQ(person1.get_year_of_hiring(), 2019);
}
TEST(EmployeeTests, EmployeeSetterTest3) {
    Employee person1;
    person1.set_basic_rate_for_month(37500);
    EXPECT_EQ(person1.get_basic_rate_for_month(), 37500);
}
TEST(EmployeeTests, EmployeeSetterTest4) {
    Employee person1;
    person1.set_full_name("Vitaliy Ivanov");
    EXPECT_EQ(person1.get_full_name(), "Vitaliy Ivanov");
}
TEST(EmployeeTests, EmployeeComputeSalaryTest) {
    Employee person1("Konstantin Jukov", 2021, Staff, 30000, 2023);
    EXPECT_EQ(person1.compute_salary(), 30300);
}
TEST(EmployeeTests, EmployeeComputeSalaryTest2) {
    Employee person1("Ivan Krilov", 2021, Freelance, 150, 2.7, 140);
    EXPECT_EQ(person1.compute_salary(), 21566);
}
TEST(EmployeeListTests, EmployeeListDefaultConstructorTest) {
    EmployeeList EL = EmployeeList();
    EXPECT_EQ(EL.get_size(), 5);
}
TEST(EmployeeListTests, EmployeeListDefaultConstructorTest2) {
    EmployeeList EL = EmployeeList();
    EXPECT_EQ(EL[0]->get_type(), Staff);
}
TEST(EmployeeListTests, EmployeeListAddEmployerTest) {
    EmployeeList EL = EmployeeList();
    Employee employer = Employee("Konstantin Jukov", 2021, Staff, 30000, 2023);
    EL.add_item(2, employer);
    EXPECT_EQ(EL.get_size(), 6);
    EXPECT_EQ(EL[2]->get_full_name(), "Konstantin Jukov");
    EXPECT_EQ(EL[0]->compute_salary(), 0);
    EXPECT_EQ(EL[0]->get_basic_rate_for_month(), 0);
    EXPECT_EQ(EL[2]->compute_salary(), 30300);
}
TEST(EmployeeListTests, EmployeeListDelEmployerTest) {
    EmployeeList EL = EmployeeList();
    EL.del_item(0);
    EXPECT_EQ(EL.get_size(), 4);
    EXPECT_EQ(EL[0]->compute_salary(), 0);
    EXPECT_EQ(EL[1]->get_basic_rate_for_month(), 0);
}
TEST(EmployeeListTests, EmployeeListClearTest) {
    EmployeeList EL = EmployeeList();
    EL.clear();
    EXPECT_EQ(EL.get_size(), 0);
}
TEST(EmployeeListTests, EmployeeListMaxSalaryTest) {
    EmployeeList EL;
    ListPtr employee = new Employee[5];
    EL.add_item(0, employee[0] = Employee("John Manning", 2021, Staff, 30000, 2023));
    EL.add_item(1, employee[1] = Employee("Leroy Williams", 2018, Freelance, 400, 2.5,250));
    EL.add_item(2, employee[2] = Employee("Matthew Cooper", 2015, Staff, 40000, 2023));
    EL.add_item(3, employee[3] = Employee("Anthony Miller", 2017, Freelance, 350, 3.5, 200));
    EL.add_item(4, employee[4] = Employee("Peter Manning", 2019, Staff, 50000, 2023));
    EXPECT_EQ(EL.find_with_max_salary(), 1);
    delete[] employee;
}
TEST(EmployeeListTests, EmployeeListCtorAndOPCpyTest) {
    EmployeeList EL = EmployeeList();
    EmployeeList EL2(EL);
    EmployeeList EL3 = EL;
    EXPECT_EQ(EL, EL2);
    EXPECT_EQ(EL, EL3);
}
TEST(ExceptionTests, ExeptionIndexOutTest) {
    EmployeeList EL = EmployeeList();
    EXPECT_THROW(EL[-1]->compute_salary(), std::runtime_error);
    EXPECT_THROW(EL[10]->compute_salary(), std::runtime_error);
}
TEST(ExceptionTests, ExeptionEmptyTest) {
    EmployeeList EL = EmployeeList();
    EL.set_size(0);
    EXPECT_THROW(EL.del_item(1), std::runtime_error);
}
