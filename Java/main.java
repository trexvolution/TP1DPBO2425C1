// Saya Nur Abdillah dengan NIM 2408515 mengerjakan Tugas Praktikum 1
// dalam mata kuliah Desain Pemrograman Berorientasi Objek untuk keberkahan-Nya 
// maka saya tidak akan melakukan kecurangan seperti yang telah di spesifikasikan

import java.util.*; // Import semua class dari java.util (Scanner, List, LinkedList, Iterator, dll.)

// Kelas utama program
public class main {
    public static void main(String[] args) {

        // List untuk menyimpan data barang, menggunakan LinkedList
        List<Electroshop> listBarang = new LinkedList<>();  // Scanner untuk input dari user
        Scanner scanner = new Scanner(System.in);   // Variabel untuk pilihan menu

        // Perulangan akan terus berjalan sampai user memilih 6 (Exit)
        int choice = 0;

        while (choice != 6) {
            // Menampilkan menu
            System.out.println("+-------------------+");
            System.out.println("|   Menu Perintah   |");
            System.out.println("+-------------------+");
            System.out.println("| 1. Tambahkan Data |");
            System.out.println("| 2. Tampilkan Data |");
            System.out.println("| 3. Update Data    |");
            System.out.println("| 4. Hapus Data     |");
            System.out.println("| 5. Cari Data      |");
            System.out.println("| 6. Exit           |");
            System.out.println("+-------------------+");
            System.out.print("Perintah apa yang ingin anda lakukan : ");
            choice = scanner.nextInt(); 
            scanner.nextLine(); // Mengkonsumsi newline agar input berikutnya tidak lompat

            // Pilihan 1 untuk menambahkan data
            if (choice == 1) {

                // Input data baru
                System.out.println("Silahkan masukkan data berikut:");
                System.out.print("ID: ");
                String id = scanner.nextLine();
                System.out.print("Nama: ");
                String nama = scanner.nextLine();
                System.out.print("Kategori: ");
                String kategori = scanner.nextLine();
                System.out.print("Brand: ");
                String brand = scanner.nextLine();
                System.out.print("Harga: ");
                int harga = scanner.nextInt();
                scanner.nextLine();

                // Buat objek Electroshop dan tambahkan ke list
                Electroshop temp = new Electroshop(id, nama, kategori, brand, harga);
                listBarang.add(temp);

            // Pilihan 2 untuk menampilkan semua data
            } else if (choice == 2) {
                if (listBarang.isEmpty()) {
                    System.out.println("Data Masih Kosong");
                } else {
                    // Hitung panjang maksimum tiap kolom supaya tabel rapi
                    int idLen = 2, nameLen = 4, kateLen = 8, brandLen = 5, hargaLen = 5;
                    for (Electroshop e : listBarang) {
                        idLen = Math.max(idLen, e.idLength());
                        nameLen = Math.max(nameLen, e.namaLength());
                        kateLen = Math.max(kateLen, e.kategoriLength());
                        brandLen = Math.max(brandLen, e.brandLength());
                        hargaLen = Math.max(hargaLen, e.hargaLength());
                    }

                    // Buat header tabel
                    String border = "+" + "-".repeat(idLen) +
                                    "+" + "-".repeat(nameLen) +
                                    "+" + "-".repeat(kateLen) +
                                    "+" + "-".repeat(brandLen) +
                                    "+" + "-".repeat(hargaLen) + "+";

                    System.out.println(border);
                    System.out.printf("|%-" + idLen + "s|%-" + nameLen + "s|%-" + kateLen + "s|%-" + brandLen + "s|%-" + hargaLen + "s|\n",
                                      "ID", "Name", "Kategori", "Brand", "Harga");
                    System.out.println(border);

                    // Cetak isi tabel (data barang)
                    for (Electroshop e : listBarang) {
                        System.out.printf("|%-" + idLen + "s|%-" + nameLen + "s|%-" + kateLen + "s|%-" + brandLen + "s|%-" + hargaLen + "d|\n",
                                          e.getId(), e.getNama(), e.getKategori(), e.getBrand(), e.getHarga());
                    }

                    // Cetak footer tabel
                    System.out.println(border);
                }

            // Pilihan 3 untuk mengubah isi data
            } else if (choice == 3) {
                System.out.print("Masukkan ID yang ingin diupdate: ");
                String id = scanner.nextLine();
                Electroshop pointerEdit = null;

                // Cari data berdasarkan ID
                for (Electroshop e : listBarang) {
                    pointerEdit = e.searchId(id);
                    if (pointerEdit != null) break;
                }

                if (pointerEdit != null) {

                    // Tampilkan data lama
                    System.out.println("Berikut data dengan ID tersebut:");
                    System.out.println("Nama: " + pointerEdit.getNama());
                    System.out.println("Kategori: " + pointerEdit.getKategori());
                    System.out.println("Brand: " + pointerEdit.getBrand());
                    System.out.println("Harga: " + pointerEdit.getHarga());

                    // Input data baru untuk update
                    System.out.print("Masukkan Nama: ");
                    String nama = scanner.nextLine();
                    System.out.print("Masukkan Kategori: ");
                    String kategori = scanner.nextLine();
                    System.out.print("Masukkan Brand: ");
                    String brand = scanner.nextLine();
                    System.out.print("Masukkan Harga: ");
                    int harga = scanner.nextInt();
                    scanner.nextLine();

                    // Update data
                    pointerEdit.editData(nama, kategori, brand, harga);
                } else {
                    System.out.println("Data yang anda cari tidak ditemukan");
                }

            // Pilihan 4 untuk menghapus data 
            } else if (choice == 4) {
                System.out.print("Masukkan ID data yang ingin dihapus: ");
                String id = scanner.nextLine();
                boolean removed = false;

                // Cari data lalu hapus jika ditemukan
                Iterator<Electroshop> it = listBarang.iterator();
                while (it.hasNext()) {
                    Electroshop e = it.next();
                    if (e.getId().equals(id)) {
                        it.remove();    // Hapus data dari list
                        System.out.println("Data telah dihapus");
                        removed = true;
                        break;
                    }
                }

                if (!removed) {
                    System.out.println("Data tidak ditemukan");
                }

            // Pilihan 5 untuk mencari data
            } else if (choice == 5) {
                System.out.print("Masukkan ID yang ingin dicari: ");
                String id = scanner.nextLine();
                Electroshop pointerEdit = null;

                // Cari data berdasarkan ID
                for (Electroshop e : listBarang) {
                    pointerEdit = e.searchId(id);
                    if (pointerEdit != null) break;
                }

                if (pointerEdit != null) {
                    // Jika ditemukan, tampilkan data
                    System.out.println("Berikut data dengan ID " + id + " tersebut:");
                    System.out.println("Nama: " + pointerEdit.getNama());
                    System.out.println("Kategori: " + pointerEdit.getKategori());
                    System.out.println("Brand: " + pointerEdit.getBrand());
                    System.out.println("Harga: " + pointerEdit.getHarga());
                } else {
                    System.out.println("Data yang anda cari tidak ditemukan");
                }
            }
        }

        scanner.close();    // Tutup scanner setelah program selesai
    }
}
