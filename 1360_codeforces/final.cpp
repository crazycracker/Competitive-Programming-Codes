#include <iostream>
#include <stdio.h>

using namespace std;

class Staff {
    public:
    int id;
    string name;
    string gender;
    string designation;
    double basic_salary;
    double gross_pay;

    public:
    double calculate_gross_pay();
    double calculate_pf();
    double calculate_netpay();
};

class TotalDeductions{
    public:
    double home_loan, tuition_fees, lic_paid;

    public:
    double getTotalDeductions();
};
class Payslip: public Staff{
    public:
    double calculate_gross_pay(){
        if(basic_salary <= 20000){
            gross_pay = 2 * basic_salary;
        }else if(basic_salary <= 40000){
            gross_pay = 2.15 * basic_salary;
        }else if(basic_salary > 40000){
            gross_pay = 2.25 * basic_salary;
        }
        return gross_pay;
    }

    double calcualte_pf(){
        return 0.1 * calculate_gross_pay();
    }
    public:
    double calculate_netpay(){
        return 0.9 * calculate_gross_pay();
    }
};

class Deduction: public TotalDeductions{
    public:
    double getHomeLoan(){
        return home_loan;
    }
    public:
    double getTuitionFees(){
        return tuition_fees;
    }
    public:
    double getLicPaid(){
        return lic_paid;
    }
    public:
    double getTotalDeductions(){
        if(getHomeLoan() > 200000){
            printf("Invalid");
        }
        return getHomeLoan() + getTuitionFees() + getLicPaid();
    }
};

class TaxPaid: public Payslip, public Deduction{
    public:
    double calculate_taxable_to_be_paid(){
        double taxable_income = calculate_taxable_income();

        if(taxable_income <= 300000){
            return 0;
        }else if(taxable_income <= 500000){
            return 0.1 * (taxable_income - 300000);
        }else if(taxable_income <= 1000000){
            return 20000 + 0.2 * (taxable_income - 500000);
        }
        return 120000 + 0.3 * (taxable_income - 1000000);
    }
    public:
    double calculate_taxable_income(){
        return Payslip::calculate_netpay() - Deduction::getTotalDeductions();
    }
};

int main(){
    int id;
    string name;
    string gender;
    string designation;
    double basic_salary;
    double home_loan;
    double tuition_fees;
    double lic_paid;

    TaxPaid taxpaid;
    cin>>id>>name>>gender>>designation>>basic_salary>>home_loan>>tuition_fees>>lic_paid;

    taxpaid.name = name;
    taxpaid.id = id;
    taxpaid.gender = gender;
    taxpaid.designation = designation;
    taxpaid.basic_salary = basic_salary;
    taxpaid.home_loan = home_loan;
    taxpaid.tuition_fees = tuition_fees;
    taxpaid.lic_paid = lic_paid;

    cout<<(int)taxpaid.getTotalDeductions()<<'\n';
    cout<<(int)taxpaid.calculate_taxable_to_be_paid()<<'\n';
    cout<<(int)taxpaid.calculate_taxable_income()<<'\n';

    return 0;
}
