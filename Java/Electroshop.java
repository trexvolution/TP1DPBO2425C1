public class Electroshop {
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

    // Setter & Getter for id
    public void setId(String id) {
        this.id = id;
    }

    public String getId() {
        return this.id;
    }

    // Setter & Getter for nama
    public void setNama(String nama) {
        this.nama = nama;
    }

    public String getNama() {
        return this.nama;
    }

    // Setter & Getter for kategori
    public void setKategori(String kategori) {
        this.kategori = kategori;
    }

    public String getKategori() {
        return this.kategori;
    }

    // Setter & Getter for brand
    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getBrand() {
        return this.brand;
    }

    // Setter & Getter for harga
    public void setHarga(int harga) {
        this.harga = harga;
    }

    public int getHarga() {
        return this.harga;
    }

    // Methods to get length of fields
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
        return String.valueOf(harga).length();
    }

    // Edit multiple data fields at once
    public void editData(String nama, String kategori, String brand, int harga) {
        this.nama = nama;
        this.kategori = kategori;
        this.brand = brand;
        this.harga = harga;
    }

    // Search by id
    public Electroshop searchId(String id) {
        if (this.id != null && this.id.equals(id)) {
            return this;
        } else {
            return null;
        }
    }

}
