#include <iostream>
#include <string>

class Go {
public:
    std::string loai_go;
    int chieu_dai;

    Go() : loai_go(""), chieu_dai(0) {}
    Go(std::string loai, int dai) : loai_go(loai), chieu_dai(dai) {}
};

int dem_loai_go(Go ds_go[], int kich_thuoc, const std::string &loai) {
    int dem = 0;
    for (int i = 0; i < kich_thuoc; i++) {
        if (ds_go[i].loai_go == loai) {
            dem++;
        }
    }
    return dem;
}

void nhap_danh_sach_go(Go ds_go[], int &kich_thuoc) {
    std::cout << "Nhap so luong go: ";
    std::cin >> kich_thuoc;
    std::cin.ignore();

    for (int i = 0; i < kich_thuoc; i++) {
        std::cout << "Nhap loai go thu " << i + 1 << ": ";
        std::getline(std::cin, ds_go[i].loai_go);
        std::cout << "Nhap chieu dai go thu " << i + 1 << ": ";
        std::cin >> ds_go[i].chieu_dai;
        std::cin.ignore();
    }
}

int main() {
    const int MAX_GO = 100;
    Go ds_go[MAX_GO];
    int kich_thuoc;

    nhap_danh_sach_go(ds_go, kich_thuoc);

    std::cout << "Danh sach go: " << std::endl;
    for (int i = 0; i < kich_thuoc; i++) {
        std::cout << "Loai go: " << ds_go[i].loai_go << ", Chieu dai: " << ds_go[i].chieu_dai << std::endl;
    }

    std::string loai_dem = "Cam xe";
    int so_luong = dem_loai_go(ds_go, kich_thuoc, loai_dem);
    std::cout << "So luong thanh phan cung loai go \"" << loai_dem << "\": " << so_luong << std::endl;

    return 0;
}