class Electroshop:
    def __init__(self, id=None, nama=None, kategori=None, brand=None, harga=None):
        self.id = id
        self.nama = nama
        self.kategori = kategori
        self.brand = brand
        self.harga = harga

    # Setters and Getters
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

    # Length methods
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

    # Edit data
    def edit_data(self, nama, kategori, brand, harga):
        self.nama = nama
        self.kategori = kategori
        self.brand = brand
        self.harga = harga

    # Search ID
    def search_id(self, id):
        if self.id == id:
            return self
        else:
            return None
