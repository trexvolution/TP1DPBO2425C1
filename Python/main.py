from Electroshop import Electroshop  # pastikan file Electroshop.py ada

def main():
    ListBarang = []
    choice = 0

    while choice != 6:
        print("+-------------------+")
        print("|   Menu Perintah   |")
        print("+-------------------+")
        print("| 1. Tambahkan Data |")
        print("| 2. Tampilkan Data |")
        print("| 3. Update Data    |")
        print("| 4. Hapus Data     |")
        print("| 5. Cari Data      |")
        print("| 6. Exit           |")
        print("+-------------------+")
        choice = int(input("Perintah apa yang ingin anda lakukan : "))

        if choice == 1:
            # Tambah data
            print("Silahkan masukkan data berikut:")
            id_ = input("ID : ")
            nama = input("Nama : ")
            kategori = input("Kategori : ")
            brand = input("Brand : ")
            harga = int(input("Harga : "))
            temp = Electroshop(id_, nama, kategori, brand, harga)
            ListBarang.append(temp)

        elif choice == 2:
            # Tampilkan data
            if not ListBarang:
                print("Data Masih Kosong")
            else:
                id_len = 2
                name_len = 4
                kate_len = 8
                brand_len = 5
                harga_len = 5

                for e in ListBarang:
                    id_len = max(id_len, e.id_length())
                    name_len = max(name_len, e.nama_length())
                    kate_len = max(kate_len, e.kategori_length())
                    brand_len = max(brand_len, e.brand_length())
                    harga_len = max(harga_len, e.harga_length())

                # header
                print("+" + "-"*id_len +
                      "+" + "-"*name_len +
                      "+" + "-"*kate_len +
                      "+" + "-"*brand_len +
                      "+" + "-"*harga_len + "+")
                print("|" + "ID".ljust(id_len) +
                      "|" + "Name".ljust(name_len) +
                      "|" + "Kategori".ljust(kate_len) +
                      "|" + "Brand".ljust(brand_len) +
                      "|" + "Harga".ljust(harga_len) + "|")
                print("+" + "-"*id_len +
                      "+" + "-"*name_len +
                      "+" + "-"*kate_len +
                      "+" + "-"*brand_len +
                      "+" + "-"*harga_len + "+")

                # isi
                for e in ListBarang:
                    print("|" + e.get_id().ljust(id_len) +
                          "|" + e.get_nama().ljust(name_len) +
                          "|" + e.get_kategori().ljust(kate_len) +
                          "|" + e.get_brand().ljust(brand_len) +
                          "|" + str(e.get_harga()).ljust(harga_len) + "|")

                print("+" + "-"*id_len +
                      "+" + "-"*name_len +
                      "+" + "-"*kate_len +
                      "+" + "-"*brand_len +
                      "+" + "-"*harga_len + "+")

        elif choice == 3:
            # Update data
            id_ = input("Masukkan ID yang ingin diupdate : ")
            pointer_edit = None
            for e in ListBarang:
                if e.search_id(id_):
                    pointer_edit = e
                    break

            if pointer_edit:
                print("Berikut data dengan ID tersebut:")
                print("Nama :", pointer_edit.get_nama())
                print("Kategori :", pointer_edit.get_kategori())
                print("Brand :", pointer_edit.get_brand())
                print("Harga :", pointer_edit.get_harga())
                print()

                nama = input("Masukkan Nama : ")
                kategori = input("Masukkan Kategori : ")
                brand = input("Masukkan Brand : ")
                harga = int(input("Masukkan Harga : "))
                pointer_edit.edit_data(nama, kategori, brand, harga)
            else:
                print("Data yang anda cari tidak ditemukan")

        elif choice == 4:
            # Hapus data
            id_ = input("Masukkan ID data yang ingin dihapus : ")
            found = False
            for i, e in enumerate(ListBarang):
                if e.get_id() == id_:
                    del ListBarang[i]
                    print("Data telah dihapus")
                    found = True
                    break
            if not found:
                print("Data tidak ditemukan")

        elif choice == 5:
            # Cari data
            id_ = input("Masukkan ID yang ingin dicari : ")
            pointer_edit = None
            for e in ListBarang:
                if e.search_id(id_):
                    pointer_edit = e
                    break

            if pointer_edit:
                print(f"Berikut data dengan ID {id_} tersebut :")
                print("Nama :", pointer_edit.get_nama())
                print("Kategori :", pointer_edit.get_kategori())
                print("Brand :", pointer_edit.get_brand())
                print("Harga :", pointer_edit.get_harga())
                print()
            else:
                print("Data yang anda cari tidak ditemukan")

    print("Program selesai.")


if __name__ == "__main__":
    main()
