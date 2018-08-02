#include<iostream>
#include<math.h>
#include<sstream>
#include<iomanip>

using namespace std;

string toBinary(long double number, int n);

string toBinary(long double low, long double high);

int index_of(char gia_tri, char * a, int n);

char find_symblol(char * a, long double * pc, long double * p, int n, long double v, long double * low, long double * range);

int main()
{
    system("color f0");
    cout << "-----------------------------------------" << endl;
    cout << "            ARITHMEIC CODING             " << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    // Nhap du lieu
    cout << "NHAP DU LIEU" << endl;
    int n, k, i,l,lTest,lTong,ltb;
    char thoat;
    cout << "Nhap so luong tin: " ;
    cin >> n;
    char a[n];
    double Hx[n];
    int L[n];
    long double p[n];
    long double pc[n+1];
    double tongXacSuat = 0.0;
    double test = 0;
    double H = 0;
    long double code;
    long double low = 0.0;
    long double range = 1.0;
    pc[0] = 0.0;
    do
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Tin " << i+1 <<": ";
            cin >> a[i];
            cout << "Xac suat tin " << i+1 << ": ";
            cin >> p[i];
            Hx[i] = - 1 / (log2(p[i]));
            tongXacSuat = tongXacSuat + p[i];
            pc[i+1] = pc[i] + p[i];
        }
        if (tongXacSuat != 1)
            cout << "Khong hop le,nhap lai !!!" << endl;
            test = tongXacSuat;
            tongXacSuat = 0.0;
    }
    while (test !=1 );
    for (i = 0;i < n;i++){
    for (lTest = 0; lTest < 10000000; lTest++){
        if (lTest > Hx[i] && lTest < (Hx[i] + 1)) L[i] = lTest;
    }
    }
    for (i = 0; i < n; i++){
        lTong = lTong + L [i];
        ltb = lTong / (i + 1);
    }
    for (i = 0; i < n; i++)
    {
        H = H - p[i] * (1 / log2(p[i]) );
    }
    cout << "Entrophy cua nguon: " << H << endl;
    cout << "He so nen thong ke: " << H / ltb <<endl;
    cout << "MA HOA" << endl;
    // Ma hoa
        do
        {
            cout << "Nhap do dai tin nhan: ";
            cin >> k;
            cout << "Nhap tin nhan: ";
            char m[k];
            for (int i = 0; i < k; i++)
            {
                cin >> m[i];
            }
            for (int i = 0; i < k; i++)
            {
                //range = high - low;
                int j = index_of(m[i], a, n);
                low = low + pc[j] * range;
                range = range * p[j];
                //low = low + range * pc[j];
                //high = low + range * p[j];
                //range = high - low;
            }
            cout << "Ma hoa dang thap phan: ";
            cout << setprecision(20) << low + range / 2 << endl;
            cout << "Ma hoa dang nhi phan: ";
            cout<< toBinary(low,low + range) << endl;
            cout << "Chuyen sang giai ma (c): ";
            cin >> thoat;
        }
        while (thoat != 'c');
        // Giai ma
        cout << "GIAI MA" << endl;
        do
        {
            cout << "Nhap ma: ";
            cin >> code;
            cout << "Nhap do dai doan ma: ";
            cin >> k;
            cout << "Tin nhan duoc: ";

            stringstream ss;
            low = 0.0;
            range = 1.0;
            for (int i = 0; i < k; i++)
            {
                ss << find_symblol(a, pc, p, n, code, &low, &range);
                code = (code - low) / range;
            }
            cout << ss.str() << endl;
            cout << "Thoat chuong trinh (c): ";
            cin >> thoat;
        }
        while (thoat != 'c');
}
        char find_symblol(char * a, long double * pc, long double * p, int n, long double v, long double * low, long double * range)
        {
            for (int i = 0; i < n; i++)
            {
                if (v > pc[i] && v < pc[i+1])
                {
                    * low = pc[i];
                    * range = p[i];
                    return a[i];
                }
            }
            return '\0';
        }

        int index_of(char gia_tri, char * a, int n)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == gia_tri)
                    return i;
            }
            return -1;
        }
        string toBinary(long double number, int n)
        {
            stringstream s;
            for (int i = 0; i < n; i++)
            {
                s << int(number * 2);
                number = number * 2 - int(number * 2);
            }
            return s.str();
        }
        string toBinary(long double low, long double high)
        {
            double mid = (low + high) / 2;
            string low_bin, high_bin, mid_bin;
            int i = 0;
            do
            {
                i++;
                low_bin = toBinary(low, i + 1);
                high_bin = toBinary(high, i + 1);
                mid_bin = toBinary(mid, i);
            }
            while (!(mid_bin + "0" > low_bin && mid_bin + "1" < high_bin));
            return mid_bin;
        }

