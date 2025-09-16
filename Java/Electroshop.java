// Saya Nur Abdillah dengan NIM 2408515 mengerjakan Tugas Praktikum 1
// dalam mata kuliah Desain Pemrograman Berorientasi Objek untuk keberkahan-Nya 
// maka saya tidak akan melakukan kecurangan seperti yang telah di spesifikasikan

public class Electroshop {

    // Atribut / properti untuk menyimpan data barang elektronik
    private String id;
    private String nama;
    private String kategori;
    private String brand;
    private int harga;

    // Default constructor
    public Electroshop() {
    }

    // Parameterized constructor
    public Electroshop(String id, String nama, String kategori, String brand, int harga) {
        this.id = id;
        this.nama = nama;
        this.kategori = kategori;
        this.brand = brand;
        this.harga = harga;
    }

    // Setter & Getter untuk data
    public void setId(String id) {
        this.id = id;
    }

    public String getId() {
        return this.id;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public String getNama() {
        return this.nama;
    }

    public void setKategori(String kategori) {
        this.kategori = kategori;
    }

    public String getKategori() {
        return this.kategori;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getBrand() {
        return this.brand;
    }

    public void setHarga(int harga) {
        this.harga = harga;
    }

    public int getHarga() {
        return this.harga;
    }

    // Method tambahan untuk menghitung panjang karakter dari masing-masing atribut
    public int idLength() {
        return id != null ? id.length() : 0;
    }

    public int namaLength() {
        return nama != null ? nama.length() : 0;
    }

    public int kategoriLength() {
        return kategori != null ? kategori.length() : 0;
    }

    public int brandLength() {
        return brand != null ? brand.length() : 0;
    }

    public int hargaLength() {
        return String.valueOf(harga).length(); // konversi harga ke String lalu hitung jumlah digit
    }


    // Edit semua data sekaligus
    public void editData(String nama, String kategori, String brand, int harga) {
        this.nama = nama;
        this.kategori = kategori;
        this.brand = brand;
        this.harga = harga;
    }

    // Pencarian berdasarkan ID
    public Electroshop searchId(String id) {
        if (this.id != null && this.id.equals(id)) {
            return this;    // jika ID cocok, kembalikan objek ini
        } else {
            return null;    // jika tidak cocok, kembalikan null
        }
    }
}