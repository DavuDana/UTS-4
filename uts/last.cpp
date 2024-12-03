#include <iostream>
#include <vector>
#include <string>

using namespace std;


void showMenu() {
    cout << "\n=== Aplikasi Data Management ===\n";
    cout << "1. Tambah Data\n";
    cout << "2. Tampilkan Data\n";
    cout << "3. Cari Data\n";
    cout << "4. Hapus Data\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}


int searchData(const vector<string>& dataList, const string& target) {
    for (int i = 0; i < dataList.size(); i++) {
        if (dataList[i] == target) {
            return i;
        }
    }
    return -1;

int main() {
    vector<string> dataList;
    int choice;
    bool isRunning = true;

    while (isRunning) {
        showMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string newData;
                cout << "Masukkan data yang ingin ditambahkan: ";
                getline(cin, newData);
                dataList.push_back(newData);
                cout << "Data berhasil ditambahkan.\n";
                break;
            }
            case 2: {
                if (dataList.empty()) {
                    cout << "Data masih kosong.\n";
                } else {
                    cout << "Data saat ini:\n";
                    for (int i = 0; i < dataList.size(); i++) {
                        cout << i + 1 << ". " << dataList[i] << "\n";
                    }
                }
                break;
            }
            case 3: {
                string target;
                cout << "Masukkan data yang ingin dicari: ";
                getline(cin, target);
                int index = searchData(dataList, target);
                if (index != -1) {
                    cout << "Data ditemukan di indeks ke-" << index + 1 << ".\n";
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            }
            case 4: {
                string target;
                cout << "Masukkan data yang ingin dihapus: ";
                getline(cin, target);
                int index = searchData(dataList, target);
                if (index != -1) {
                    dataList.erase(dataList.begin() + index);
                    cout << "Data berhasil dihapus.\n";
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            }
            case 5: {
                cout << "Terima kasih telah menggunakan aplikasi ini.\n";
                isRunning = false;
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            }
        }
    }

    return 0;
}
