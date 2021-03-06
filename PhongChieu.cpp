#include"PhongChieu.h"

PhongChieu::PhongChieu(string MaPhongChieu, int SoCho, string MayChieu, string AmThanh, float DienTich, string TinhTrang, string MaBaoVe){
    this->MaPhongChieu = MaPhongChieu;
    this->SoCho = SoCho;
    this->MayChieu = MayChieu;
    this->AmThanh = AmThanh;
    this->DienTich = DienTich;
    this->TinhTrang = TinhTrang;
    this->MaBaoVe = MaBaoVe;
}

PhongChieu::~PhongChieu(){}

void PhongChieu::setMaPhongChieu(string MaPhongChieu){
    this->MaPhongChieu = MaPhongChieu;    
}
void PhongChieu::setSoCho(int SoCho){
    this->SoCho = SoCho;    
}
void PhongChieu::setMayChieu(string MayChieu){
    this->MayChieu = MayChieu;    
}
void PhongChieu::setAmThanh(string AmThanh){
    this->AmThanh = AmThanh;    
}
void PhongChieu::setDienTich(float DienTich){
    this->DienTich = DienTich;    
}
void PhongChieu::setTinhTrang(string TinhTrang){
    this->TinhTrang = TinhTrang;    
}
void PhongChieu::setMaBaoVe(string MaBaoVe){
    this->MaBaoVe = MaBaoVe;    
}

string PhongChieu::getMaPhongChieu(){
    return this->MaPhongChieu;
}
int PhongChieu::getSoCho(){
    return this->SoCho;
}
string PhongChieu::getMayChieu(){
    return this->MayChieu;
}
string PhongChieu::getAmThanh(){
    return this->AmThanh;
}
float PhongChieu::getDienTich(){
    return this->DienTich;
}
string PhongChieu::getTinhTrang(){
    return this->TinhTrang;
}
string PhongChieu::getMaBaoVe(){
    return this->MaBaoVe;
}


PhongChieu::PhongChieu(const PhongChieu& p){
    this->MaPhongChieu = p.MaPhongChieu;
    this->SoCho = p.SoCho;
    this->MayChieu = p.MayChieu;
    this->AmThanh = p.AmThanh;
    this->DienTich = p.DienTich;
    this->TinhTrang = p.TinhTrang;
    this->MaBaoVe = p.MaBaoVe;
}

void PhongChieu::Display2(){
    cout << "Ma Phong Chieu: " << this->MaPhongChieu << endl;
    CanLe();
    cout << "So Ghe: " << this->SoCho << endl;
    CanLe();
    cout << "Loai May Chieu: " << this->MayChieu << endl;
    CanLe();
    cout << "Loai Am Thanh: " << this->AmThanh << endl;
    CanLe();
    cout << "Dien Tich: " << this->DienTich << "met vuong" << endl;
    CanLe();
    cout << "Tinh Trang: "  << this->TinhTrang << endl;
    CanLe();
    cout << "Ma Bao Ve: " << this->MaBaoVe << endl;
}

void PhongChieu::Display(){
    cout<<char(179)<< setw(25) << left << this->MaPhongChieu <<char(179);
    cout << setw(20) << left << this->SoCho << char(179);
    cout << setw(20) << left << this->MayChieu << char(179);
    cout << setw(20) << left << this->AmThanh << char(179);
    cout << setw(20) << left << this->DienTich << char(179);
    cout << setw(20) << left << this->TinhTrang << char(179);
    cout << setw(20) << left << this->MaBaoVe<<char(179)<< endl;
}

void PhongChieu::DocFileDatGhe(vector<int>& A,string xuatchieu){
    ifstream ip2;
    ip2.open("./LichChieu/" + xuatchieu + "/" + this->getMaPhongChieu() + ".txt", ios::in);
    int check;
    while(ip2.peek()!= EOF){
        ip2 >> check;
        A.push_back(check);
    }
    ip2.close();
}
void PhongChieu::DatGhe(int n,string xuatchieu){
    for(int i = 0; i < n; i++){
        CanLe();
        cout << "Nhap Ghe Ma Ban Muon Dat: ";
        int ghe;
        cin >> ghe;
        while(i < 0 || i > this->SoCho){
            CanLe();
            cout << "Vui Long Nhap Lai: ";
            cin >> ghe;
        }
        this->GhiFileDatGhe(ghe,xuatchieu);
    }
}
void PhongChieu::GhiFileDatGhe(int ghe,string xuatchieu){
    fstream ip1;
    ip1.open("./LichChieu/" + xuatchieu + "/" + this->getMaPhongChieu() + ".txt", ios::app);
    if(ip1.is_open()){
        ip1.seekp(0,ios::end);
        ip1 << endl;
        ip1 << ghe;
        ip1.close();
    }
}

bool PhongChieu::isReserved(vector<int>& A, int k){
    for (int  i = 0; i < A.size(); i++)
    {
        if(k == A[i]){
            return true;
            break;
        }
    }
    return false;
}

void PhongChieu::DisplayTable(string xuatchieu){
    vector<int> A;
    DocFileDatGhe(A,xuatchieu);
    int Ghe[1000];
    for (int i = 1; i <= this->SoCho; i++)
    {   
        Ghe[i] = i;
    }
    GoTo(60,whereY());
    cout <<"\t\t  Man Hinh Chieu" << endl;
    cout << "       ";
    GoTo(60,whereY());
    for(int i = 0; i < 6; i++) cout << "________";
    GoTo(60,whereY()+3);
    for(int i = 0; i < this->SoCho/10; i++){
            GoTo(60,whereY());
        for(int j = 1; j <= 10; j++){
            if(this->isReserved(A,i*10 + j)){
                SetColor(0,5);
                cout << setw(5) << Ghe[i*10 + j];
                SetColor(0,7);
            }
            else {
                cout << setw(5) << Ghe[i*10 + j];
            }
        }
        cout << endl;
        cout << endl;
    }
    GoTo(5,10);
    SetColor(0,7);
    cout << "Mau Trang: Co The Dat Ghe" << endl;
    GoTo(5,11);
    SetColor(0,5);
    cout << "Mau Tim: Da Dat Truoc" << endl;
    SetColor(0,7);
    cout << endl;
    
}

istream& operator>>(istream& i, PhongChieu& e){
    CanLe();
    cout << "Nhap Ma Phong Chieu: ";
    fflush(stdin);
    getline(i,e.MaPhongChieu);
    CanLe();
    cout << "Nhap So Ghe: "; i >> e.SoCho;
    CanLe();
    cout << "Nhap Loai May Chieu: ";
    fflush(stdin);
    getline(i,e.MayChieu);
    CanLe();
    cout << "Nhap Loai Am Thanh: ";
    fflush(stdin);
    getline(i,e.AmThanh);
    CanLe();
    cout << "Nhap Dien Tich Phong Chieu:"; i >> e.DienTich;
    CanLe();
    cout << "Nhap Tinh Trang Phong Chieu:";
    fflush(stdin);
    getline(i,e.TinhTrang);
    CanLe();
    cout << "Nhap Ma Bao Ve: ";
    fflush(stdin);
    getline(i,e.MaBaoVe);
    return i;
}