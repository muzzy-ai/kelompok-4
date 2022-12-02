#include <stdio.h>
#include <iostream>
#include <cstring>
//kelompok muzzy,naufal,choirul
using namespace std;

void createFile(){ //membuat sebuah fungsu untuk membuat file
	char nama[30], npm[8]; //mendeklarasikan 3 character
	string namaF, namaFile;
	char charNama[20];
	int b;
	FILE *fileTemp;
	
	printf("\nMasukan Nama File Untuk dibuat : ");
	fflush(stdin);
	getline(cin, namaF);
	namaFile = namaF +".txt"; //menambahkan nama file dengan .txt agar file yang terbentuk berupa file.txt
	strcpy(charNama, namaFile.c_str());
	printf("\nMasukan banyak data : ");
	fflush(stdin);
	cin>>b;
	
	fileTemp = fopen(charNama, "w");//membuka file lalu menulsi di dalamnya dengan perintah W
	
	for (int i=0; i<b; i++){ //perulangan ini untuk memasukan banyaknya data sesuai inputan yang tersimpan didalam variabel b
		printf("\nMasukan Data Ke-%d: ", i+1);
		printf("\nMasukan Nama	: ");
		fflush(stdin);
		gets(nama);
		fprintf(fileTemp, "%s\n", nama);
		printf("Masukan NPM	: ");
		fflush(stdin);
		gets(npm);
		fprintf(fileTemp, "%s\n", npm);
	}
	fclose(fileTemp);
	
	printf("\n\nData berhasil dimasukan");
}

void readFile(){ // membuat sebuah fungsi lagi untuk membaca file .txt yang sudah di buat di fungsi createfile
	char nama[30], npm[30];
	int i = 1;
	string namaF, namaFile;
	char charNama[20];
	FILE *fileTemp;
	
	printf("\nMasukan Nama File Untuk dibaca : "); // memasukkan nama file yang akan di buka
	fflush(stdin);
	getline(cin, namaF);
	namaFile = namaF +".txt";
	strcpy(charNama, namaFile.c_str());
	
	fileTemp = fopen(charNama, "r"); // membuka file yang sudah ada dengan perintah R untuk membaca sebuah file
	printf("-----------------------------------------------------------\n");
	printf("+ 	No	|      Nama		|        NPM		| \n");
	printf("-----------------------------------------------------------\n");
	
	while((fgets(nama,30,fileTemp)&&(fgets(npm,30,fileTemp))!=NULL)){
		printf("+	%d	|", i);
		printf("\t %s					|", nama); 
		printf("\t %s							|", npm );   
		printf("\n");
		printf("-------------------------------------------------------- \n");
		i++;
	}
	fclose(fileTemp);
	
	printf("\n\nData berhasil dibaca");
}

void deleteFile(){ // membuat sebuah fungsi untuk menghapus file.txt yang sudah di buat sebelumnya
	int status;
    char fileName[20];
	cout<<"Masukan Nama File : ";
    cin>>fileName;
    status = remove(fileName);
    if(status==0)
        cout<<"\nFile Berhasil Dihapus!";
    else
        cout<<"\nError!";
    cout<<endl;
}

void menuFile(){ //pada fungsi ini menampilkan pilihan menu yang tersedia 
	int pilihan;
	cout<<"+---------------------------------------+ \n";
	cout<<"|              Pilih File	        |"<<endl;
	cout<<"|---------------------------------------|\n";
	cout<<"|1. membuat file dan memasukkan data	|"<<endl;
	cout<<"|2. Membaca file                  	|"<<endl;
	cout<<"|2. Hapus File                    	|"<<endl;
	cout<<"+---------------------------------------+ \n";
	cout<<"Masukan Pilihan : ";
	cin>>pilihan;
	 
	if(pilihan==1){ // jika pilihan 1 maka akan memanggil fungsi create file
		createFile();
	}
	if(pilihan==2){ // jika pilihan 2 maka akan memanggil fungsi read file
		readFile(); 
	}
	if(pilihan==3){  // jika pilihan 3 maka akan memanggil delete file
		deleteFile();
	}
}

int main(){ // pada fungsi ini merupakan fungsi utama dalam program di dalamnya terdapat perulangan do yang akan terus melooping sampai nilai ulang = 1
	int ulang;
	do{
		menuFile();
		cout << "\nkembali ke menu (ya=1/ tidak=2)? ";
		cin >> ulang;
		cout << endl;
	}while (ulang==1);
	
	cout << "Terimakasih...";
	
	cout << endl;
	return 0;
	
}
