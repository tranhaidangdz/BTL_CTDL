#ifndef CONG_VIEC_CPP
#define CONG_VIEC_CPP
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CongViec
{
protected:
    int Gio;
    string Ten;
    string NoiDung;
    string TinhChat;

public:
    CongViec(int Gio = 0, string Ten = "", string NoiDung = "", string TinhChat = "");
    friend istream &operator>>(istream &in, CongViec &a);
    friend ostream &operator<<(ostream &out, CongViec a);
    int getGio()
    {
        return Gio;
    }
    string getTen()
    {
        return Ten;
    }
    string getTinhChat()
    {
        return TinhChat;
    }
};

CongViec::CongViec(int Gio, string Ten, string NoiDung, string TinhChat)
{
    this->Gio = Gio;
    this->Ten = Ten;
    this->NoiDung = NoiDung;
    this->TinhChat = TinhChat;
}
istream &operator>>(istream &in, CongViec &a)
{
    cout << "Gio bat dau:";
    in >> a.Gio;
    in.ignore();
    cout << "Ten cong viec:";
    getline(in, a.Ten);
    cout << "Noi dung:";
    getline(in, a.NoiDung);
    cout << "Tinh chat:";
    getline(in, a.TinhChat);
    return in;
}
ostream &operator<<(ostream &out, CongViec a)
{
    out << setw(6) << "Gio bat dau:" << setw(20) << "Ten cong viec:" << setw(22) << "Noi dung:" << setw(18) << "Tinh chat:\n";
    out << setw(6) << a.Gio << setw(20) << a.Ten << setw(22) << a.NoiDung << setw(18) << a.TinhChat;
    return out;
}
#endif