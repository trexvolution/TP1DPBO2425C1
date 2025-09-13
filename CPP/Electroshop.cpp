#include <bits/stdc++.h>

using namespace std;

class Electroshop{

    private:

        string id[100];
        string nama[100];
        string kategori[100];
        string brand[100];
        int harga[100];

    public:

    Electroshop(string id, string nama, string kategori, string brand, int harga){
        int limit = 0;
        int flag = 0;
        while (flag != 1 || limit != 99){
            if(this->id[limit] == ""){
                this->id[limit] = id;
                this->nama[limit] = nama;
                this->kategori[limit] = kategori;
                this->brand[limit] = brand;
                this->harga[limit] = harga;
                flag = 1;
            }
            limit++;
        }
    }

    int getData(string data){
        int limit = 0;
        int flag = 0;
        while (flag != 1 || limit != 100){
            if(this->id[limit] == data){
                flag = 1;
            }else{
                limit++;
            }
        }
        if(flag == 1){
            return limit;
        }else{
            return 0;
        }
    }

    string getId(int number){
        return this->id[number];
    }

    string getName(int number){
        return this->nama[number];
    }

    string getKategori(int number){
        return this->kategori[number];
    }

    string getBrand(int number){
        return this->brand[number];
    }

    int getHarga(int number){ 
        return this->harga[number];
    }

    void editData(int nomor, string nama, string kategori, string brand, int harga){
        this->nama[nomor] = nama;
        this->kategori[nomor] = kategori;
        this->brand[nomor] = brand;
        this->harga[nomor] = harga;
    }

    void hapusData(int number){
        for (int i = number; i < 100; i++){
            this->id[i] = this->id[i + 1];
            this->nama[i] = this->nama[i + 1];
            this->kategori[i] = this->kategori[i + 1];  
            this->brand[i] = this->brand[i + 1];
            this->harga[i] = this->harga[i + 1];
        }
    }

    ~Electroshop(){
    }
};


