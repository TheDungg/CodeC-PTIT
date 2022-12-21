#include <iostream>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <sstream>
using namespace std;
#define a() a
class SinhVien
{
private:
    string name, lop, dob;
    float gpa;

public:
    SinhVien();
    ~SinhVien();
    friend istream &operator>>(istream &is, SinhVien &a)
    {
        scanf("\n");
        getline(is, a.name);
        is >> a.lop >> a.dob >> a.gpa;
        return is;
    }
    friend ostream &operator<<(ostream &os, SinhVien &a)
    {
        a.solve_dob(a);
        os << "B20DCCN001 " << a.name << " " << a.lop << " " << a.dob << " ";
        os << fixed << setprecision(2) << a.gpa << endl;
        return os;
    }
    void solve_dob(SinhVien &a);
};

SinhVien::SinhVien()
{
    name = {}, lop = {}, dob = {};
    gpa = 0;
}

SinhVien::~SinhVien()
{
}

void SinhVien::solve_dob(SinhVien &a)
{
    if (a.dob[2] != '/')
        a.dob.insert(0, "0");
    if (a.dob[5] != '/')
        a.dob.insert(3, "0");
}
int main()
{
    SinhVien a();
    cin >> a;
    cout << a;
    return 0;
}