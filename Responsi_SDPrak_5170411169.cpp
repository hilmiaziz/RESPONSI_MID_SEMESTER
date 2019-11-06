// NAMA 	:  M. HILMI AZIZ. S
// NIM		: 5170411169
// KELAS 	: TEKNIK INFORMATIKA C
// DOSEN 	: MUCHAMAD KUKUH TRI HARYANTO M.Kom, C.EH, C,HFI

//library
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#define max 10

using namespace std;

//Struct Yang Berisi Info Mahasiswa
struct mahasiswa {
	int id;
	string nama;
	string nim;
	string sbd;
	string apti;
	string jarkom;
};
//Stack Berisi Mahasiswa
struct StackMAHA {
	int top;
	struct mahasiswa mahasiswa[max];
}MAHA;
//inisialisasi semua fungsi
void beranda();
void tampil_data();
int isEmptyKA();
void input_data(string nama, string nim, string sbd, string apti, string jarkom);
void urut_data();
void init_data();
void cari_data();
void keluar();

void beranda()
{
	int pilih;
	string nama, nim, sbd,apti, jarkom;
	do 
	{
		cout<<" ========================= "<<endl;
		cout<<"   RESPONSI MID SEMESTER   "<<endl;
		cout<<"  ------------------------- "<<endl;
		cout<<" Nama   : M. HILMI AZIZ.S  "<<endl;
		cout<<" NIM    : 5170411184       "<<endl;
		cout<<"  ========================= "<<endl;
		cout<<""<<endl;
		cout<<"1. Input Data"<<endl
			<<"2. Menampilkan Data"<<endl
			<<"3. Mengurutkan Data"<<endl
			<<"4. Mencari Data"<<endl
			<<"5. Keluar"<<endl
			<<"Masukan Pilihan anda :";
		cin>>pilih;
		
		switch(pilih)
		{
			case 1:
				system ("CLS");
				cout<<"Lengkapi Data Berikut ini !"<<endl<<"-------------------------"<<endl;
				cout<<"NIM  : "; cin >> nim;
				cout<<"NAMA : "; cin >> nama;
				cout<<"================== "<<endl;
				cout<<"NILAI MATAKULIAH : "<<endl;
				cout<<"================== "<<endl;
				cout<<"Nilai SBD : "; cin >>sbd;
				cout<<"APTI I    : "; cin >>apti;
				cout<<"JARKOM    : "; cin >>jarkom;
				input_data(nim,nama,sbd,apti,jarkom);
				break;
			case 2:
				
				tampil_data();
				break;
			case 3:
				system("CLS");
				urut_data();
				break;
			case 4:
				system("CLS");
				cari_data();
			break;
			case 5:
				keluar();
				
		}
			
	} while(pilih!=6);
	{
		cout<<"PILIHAN ANDA SALAH, PILIHLAH YANG BENAR !!!";
	}
}
//Inilisiasi stack Mahasiswa
void init_data()
{
	MAHA.top = -1;
}
//Mengisi STack dan Info Mahasiswa
void input_data(string nim, string nama, string sbd, string apti, string jarkom)
{
	MAHA.top++;
	MAHA.mahasiswa[MAHA.top].id =MAHA.top;
	MAHA.mahasiswa[MAHA.top].nim = nim;
	MAHA.mahasiswa[MAHA.top].nama = nama;
	MAHA.mahasiswa[MAHA.top].sbd = sbd;
	MAHA.mahasiswa[MAHA.top].apti = apti;
	MAHA.mahasiswa[MAHA.top].jarkom = jarkom;
	system("CLS");
	cout<<""<<endl;
	
	cout<<"     DATA BERHASIL DI TAMBAHKAN ...    "<<endl;
	Sleep(400);
	system("CLS");

	
}
//menampilkan seluruh Mahasiswa
void tampil_data()
{
		system("CLS");
	
		cout << "__________________________________________________________________________" << endl;
		cout << "|                            DAFTAR NAMA MAHASISWA                        |" << endl;
		cout << "|                       UNIVERSITAS TEKNOLOGI YOGYAKATA                   |" << endl;
		cout << "|_________________________________________________________________________|" << endl;
		cout<<"-----------------------------------------------------------------------\n";
		cout<<"No.	|Nama	|NIM		|SBD		|APTI I		|JARKOM"<<endl;
		for(int i = 1; i<=MAHA.top;i++)
		{
			cout<<i<<"\t|"<<MAHA.mahasiswa[i].nama<<"\t|"<<MAHA.mahasiswa[i].nim<<"\t|"<<MAHA.mahasiswa[i].sbd<<"\t\t|"<<MAHA.mahasiswa[i].apti<<"\t\t|"<<MAHA.mahasiswa[i].jarkom<<endl;
		}	
		cout<<"_____________________________________________________________________"<<endl;
		char yt;
		cout<<"Press any key to continue (y/t) : ";
		cin>>yt;
    cout<<endl;
    if(yt=='Y'||yt=='y'){
    	system("CLS");
        beranda();
    }else
    system("CLS");
        beranda();


}
//menyorting mahasiswa menurut NIM
void urut_data()
{
	StackMAHA tempMAHA;
	
	//coppy data dari struct ke temporary
	tempMAHA.top = -1;
	for (int i = 0; i<= MAHA.top;i++)
	{
		tempMAHA.top++;
		tempMAHA.mahasiswa[i].id = MAHA.mahasiswa[i].id;
		tempMAHA.mahasiswa[i].nama = MAHA.mahasiswa[i].nama;
		tempMAHA.mahasiswa[i].nim = MAHA.mahasiswa[i].nim;
		tempMAHA.mahasiswa[i].sbd = MAHA.mahasiswa[i].sbd;
		tempMAHA.mahasiswa[i].apti = MAHA.mahasiswa[i].apti;
		tempMAHA.mahasiswa[i].jarkom = MAHA.mahasiswa[i].jarkom;
		
	}
	string nama[max],nim[max],sbd[max],apti[max],jarkom[max];
	
	//short menggunakan bubble short
	for (int i=1;i<=MAHA.top;i++)
	{
		for(int j = 0; j <=MAHA.top - i; j++)
		{
			if(tempMAHA.mahasiswa[j].nim < tempMAHA.mahasiswa[j+1].nim)
			{
			
			//Proses Pertukaran Data
				nama[j]=tempMAHA.mahasiswa[j].nama;
				nim[j]=tempMAHA.mahasiswa[j].nim;
				sbd[j]=tempMAHA.mahasiswa[j].sbd;
				apti[j]=tempMAHA.mahasiswa[j].apti;
				jarkom[j]=tempMAHA.mahasiswa[j].jarkom;
			
				tempMAHA.mahasiswa[j].nama = tempMAHA.mahasiswa[j+1].nama;
				tempMAHA.mahasiswa[j].nim = tempMAHA.mahasiswa[j+1].nim;
				tempMAHA.mahasiswa[j].sbd = tempMAHA.mahasiswa[j+1].sbd;
				tempMAHA.mahasiswa[j].apti = tempMAHA.mahasiswa[j+1].apti;
				tempMAHA.mahasiswa[j].jarkom = tempMAHA.mahasiswa[j+1].jarkom;
			
				tempMAHA.mahasiswa[j+1].nama = nama[j];
				tempMAHA.mahasiswa[j+1].nim = nim[j];
				tempMAHA.mahasiswa[j+1].sbd = sbd[j];
				tempMAHA.mahasiswa[j+1].apti = apti [j];
				tempMAHA.mahasiswa[j+1].jarkom = jarkom[j];
			}
		}
	}
	//menampilkan hasil sorting
	cout<<"HASIL MENGURUTKAN BERDASARKAN NIM"<<endl;
	cout<<"Nama		NIM			SBD		APTI I		JARKOM"<<endl;
	for (int i = MAHA.top; i >= 0; i--)
	{
		cout<<tempMAHA.mahasiswa[i].nama<<"\t\t";
		cout<<tempMAHA.mahasiswa[i].nim<<"\t\t";
		cout<<tempMAHA.mahasiswa[i].sbd<<"\t\t";
		cout<<tempMAHA.mahasiswa[i].apti<<"\t\t";
		cout<<tempMAHA.mahasiswa[i].jarkom<<"\t\t";
		cout<<endl;
		
		
	}
	char yt;
	cout<<endl;
		cout<<"Press any key to continue (y/t) : ";
		cin>>yt;
    cout<<endl;
    if(yt=='Y'||yt=='y'){
    	system("CLS");
        beranda();
    }else
    system("CLS");
        beranda();
	
}
//Searching 
void cari_data()
{
	string nim;
	int j = 0;
	int index [max];
	
	cout<<"MASUKAN NIM YANG AKAN DICARI  :"<<endl;
	cin >>nim;
	for (int pr = 0; pr <=MAHA.top;pr++)
	{
		if (MAHA.mahasiswa[pr].nim == nim)
		{
			index[j]=pr;
			j++;
		}
	}
	if (j>0)
	{
		cout<<"Terdapat "<<j<<" orang " <<endl;
		cout<<"Nama		Nim			SBD			APTI		JARKOM"<<endl;
		for (int pr = 0;pr<j;pr++)
		{
				cout<<MAHA.mahasiswa[index[pr]].nama<<"\t\t";
				cout<<MAHA.mahasiswa[index[pr]].nim<<"\t\t";
				cout<<MAHA.mahasiswa[index[pr]].sbd<<"\t\t";
				cout<<MAHA.mahasiswa[index[pr]].apti<<"\t\t";
				cout<<MAHA.mahasiswa[index[pr]].jarkom<<"\t\t\t";
		}
	
		
	}
	cout<<endl;
	char yt;
		cout<<"Press any key to continue (y/t) : ";
		cin>>yt;
    cout<<endl;
    if(yt=='Y'||yt=='y'){
    	system("CLS");
        beranda();
    }else
    system("CLS");
        beranda();
}
//fungsi keluar
void keluar()
{
	system("CLS");
	cout<<endl<<endl;
	cout<<"---- TERIMA KASIH ---- ";
	Sleep(400);
		
	exit(0);
	
}
//fungsi main
int main()
{

	beranda();

}
