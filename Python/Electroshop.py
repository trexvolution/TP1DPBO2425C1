# Saya Nur Abdillah dengan NIM 2408515 mengerjakan Tugas Praktikum 1
# dalam mata kuliah Desain Pemrograman Berorientasi Objek untuk keberkahan-Nya 
# maka saya tidak akan melakukan kecurangan seperti yang telah di spesifikasikan

class Electroshop:
    
    # Konstruktor: inisialisasi atribut barang (id, nama, kategori, brand, harga)
    def __init__(self, id=None, nama=None, kategori=None, brand=None, harga=None):
        self.id = id
        self.nama = nama
        self.kategori = kategori
        self.brand = brand
        self.harga = harga

    # Bagian Setter dan Getter
    def set_id(self, id):
        self.id = id

    def get_id(self):
        return self.id

    def set_nama(self, nama):
        self.nama = nama

    def get_nama(self):
        return self.nama

    def set_kategori(self, kategori):
        self.kategori = kategori

    def get_kategori(self):
        return self.kategori

    def set_brand(self, brand):
        self.brand = brand

    def get_brand(self):
        return self.brand

    def set_harga(self, harga):
        self.harga = harga

    def get_harga(self):
        return self.harga

    # Method untuk menghitung panjang string setiap atribut
    def id_length(self):
        return len(self.id) if self.id else 0

    def nama_length(self):
        return len(self.nama) if self.nama else 0

    def kategori_length(self):
        return len(self.kategori) if self.kategori else 0

    def brand_length(self):
        return len(self.brand) if self.brand else 0

    def harga_length(self):
        return len(str(self.harga)) if self.harga is not None else 0

    # Method untuk mengedit data barang
    def edit_data(self, nama, kategori, brand, harga):
        self.nama = nama
        self.kategori = kategori
        self.brand = brand
        self.harga = harga

    # Method pencarian berdasarkan ID
    def search_id(self, id):
        if self.id == id:
            return self
        else:
            return None