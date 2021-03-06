#include "QLPhongChieu.h"
#include<string>


void QLPhongChieu::TieuDeCot()
{
    int t_color=1;
    int b_color=0;
    int x=whereX();
    int y=whereY();
  	cout<<endl;
    CanLe();
    cout << setw(26) << left << " Ma Phong Chieu" <<char(179);
    cout << setw(20) << left << " So Ghe:" <<char(179);
    cout << setw(20) << left << " May Chieu:" <<char(179);
    cout << setw(20) << left << " Am Thanh:" <<char(179);
    cout << setw(20) << left << " Dien Tich:" <<char(179);
    cout << setw(20) << left << " Tinh Trang:" <<char(179);
    cout << setw(20) << left << " Ma Bao Ve:";
    int x1=whereX();
    box(x,y,x1-5,2,t_color,b_color);
    cout<<endl;  
}
void QLPhongChieu::Show(){
    GoTo(5,3);
    TieuDeCot();
    CanLe();
    int x1=whereX();
    int y1=whereY();
    cout<<endl;
    for (int i = 0; i < this->n; i++)
    {
        CanLe();
        (p + i)->Display();
    } 
    int y=whereY();
    box(x1,y1,152,y-5,1,0);
    GoTo(x1,y+1); 
}

int QLPhongChieu::CheckMS(string s)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (s == (this->p + i)->getMaPhongChieu())
        {
            index = i;
            break;
        }
    }
    return index;
}

void QLPhongChieu::Update(string m)
{
    int i = CheckMS(m);
    if(i >= 0){
        if (m == (this->p + i)->getMaPhongChieu())
        {
            string a,c,d,f,g;
            int b;
            float e;
            system("cls");
            (this->p + i)->Display();
            CanLe();
            cout << "Nhap Ma Phong Chieu: ";
            fflush(stdin);
            getline(cin, a);
            CanLe();
            cout << "Nhap So Ghe: ";
            cin >> b;
            CanLe();
            cout << "Nhap Loai May Chieu: ";
            fflush(stdin);
            getline(cin, c);
            CanLe();
            cout << "Nhap Loai Am Thanh: ";
            fflush(stdin);
            getline(cin, c);
            CanLe();
            cout << "Nhap Dien Tich Phong Chieu: ";
            cin >> e;
            CanLe();
            cout << "Nhap Tinh Trang: ";
            fflush(stdin);
            getline(cin, f);
            CanLe();
            cout << "Nhap Ma Bao Ve: ";
            fflush(stdin);
            getline(cin, g);
            (this->p + i)->setMaPhongChieu(a);
            (this->p + i)->setSoCho(b);
            (this->p + i)->setMayChieu(c);
            (this->p + i)->setAmThanh(d);
            (this->p + i)->setDienTich(e);
            (this->p + i)->setTinhTrang(f);
            (this->p + i)->setMaBaoVe(g);
        }
    }
    else{
        return;
    }
    cout << endl;
}

// Menu


void QLPhongChieu::Menu(){
    system("cls");
    vector<string> m2={
        "1.Nhap Lai",
        "2.Tro ve"
    };
    vector<string> m={
     "1.Xem Danh Sach Phong Chieu",
     "2.Them Phong Chieu",
     "3.Xoa Phong Chieu",
     "4.Cap Nhat Phong Chieu",
     "5.Tro Ve Menu Chinh"};
    int chon=menu(m);
    switch (chon)
    {
    case 1:
        system("cls");
        this->Show();
        int chon2;
        SetColor(0,3);
        chon2 = menu2(m2);
            switch (chon2)
            {
            case 1:
                XemThongTinPhongChieu();
                break;
            case 2:
                this->Menu();
            default:
            system("cls");
                break;
            }
        break;
    case 2:
        this->ThemPhongChieu();
        break;
    case 3:
        this->XoaPhongChieu();
        break;
    case 4:
        this->CapNhatPhongChieu();
        break;
    default:
        break;
    }
}

void QLPhongChieu::ThemPhongChieu(){
    system("cls");
    this->Show();
    SetColor(0,3);
    CanLe();
    cout << "Them Mot PhongChieu: " << endl;
    PhongChieu temp;
    SetColor(0,5);
    cin >> temp;
    this->Add(temp); 
    SetColor(0,14);
    CanLe();   
    cout << "Them Thanh Cong" << endl;
    int chon;
    SetColor(0,15);
    vector<string> m2={
        "Them Phong Chieu",
        "Tro ve"
    };
    chon = menu2(m2);
    switch (chon)
    {
    case 1:
        ThemPhongChieu();
        break;
    case 2:
        this->Menu();
        break;
    default:
        this->Menu();
        break;
    }
}

void QLPhongChieu::CapNhatPhongChieu(){
    system("cls");
    this->Show();
    string ma;
    vector<string> m2={
        "Nhap Lai",
        "Tro ve"
    };
    SetColor(0,3);
    CanLe();   
    cout << "Nhap Ma Phong hieu Ban Muon Cap Nhat: ";
    SetColor(0,5);
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        SetColor(0,4);
        CanLe();   
        cout << "Khong Co Ma Phong Chieu Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
        chon2 = menu2(m2);
        if(chon2 == 1){
            this->CapNhatPhongChieu();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Update(ma);
        SetColor(0,14);
        CanLe();   
        cout << "Cap Nhat Phong Chieu Thanh Cong!!\n" << endl;
        int chon3;
        SetColor(0,15);
        chon3 = menu2(m2);
        if(chon3 == 1){
            this->CapNhatPhongChieu();
        }
        else{
            this->Menu();
        }
    }
}


void QLPhongChieu::XoaPhongChieu(){
    system("cls");
    this->Show();
    string ma;vector<string> m2={
        "Nhap Lai",
        "Tro ve"
    };
    SetColor(0,3);
    CanLe();   
    cout << "Nhap Ma Phong Chieu Ban Muon Xoa: ";
    SetColor(0,8);
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        SetColor(0,14);
        CanLe();   
        cout << "Khong Co Ma Phong Chieu Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
        chon2 = menu2(m2);
        if(chon2 == 1){
            this->XoaPhongChieu();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Delete(ma);
        SetColor(0,14);
        CanLe();   
        cout << "Xoa PhongChieu Thanh Cong!!\n" << endl;
        int chon3;
        SetColor(0,15);
        chon3 = menu2(m2);
        if(chon3 == 1){
            this->XoaPhongChieu();
        }
        else{
            this->Menu();
        }
    }
}
void QLPhongChieu::XemThongTinPhongChieu(){
    system("cls");
    this->Show();
    string ma;
    vector<string> m2={
        "Nhap Lai",
        "Tro ve"
    };
    SetColor(0,3);
    CanLe();
    cout << "Nhap Ma Phong Chieu Ban Muon Xem: ";
    SetColor(0,8);
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        SetColor(0,4);
        CanLe();
        cout << "Khong Co Ma Phong Chieu Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
        chon2 = menu2(m2);
        if(chon2 == 1){
            this->XemThongTinPhongChieu();
        }
        else if(chon2 == 2){
            this->Menu();
        }
    }
    else {
        (this->p + index)->Display2();
        int chon3;
        SetColor(0,15);
        chon3 = menu2(m2);
        if(chon3 == 1){
            this->XemThongTinPhongChieu();
        }
        else if(chon3 == 2){
            this->Menu();
        }
    }
}