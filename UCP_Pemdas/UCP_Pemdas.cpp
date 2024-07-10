#include <iostream>
using namespace std;

class MataKuliah {
private:
	float presensi;
	float activity;
	float exercise;
	float tugasAkhir;
public:
	MataKuliah(){
		presensi = 0.0;
		activity = 0.0;
		exercise = 0.0;
		tugasAkhir = 0.0;
	}
	virtual void namaMataKuliah() {
		return;
	}
	virtual void inputNilai() {
		return;
	}
	virtual void hitungNilaiAkhir() {
		return;
	}
	virtual void cekKelulusan() {
		return;
	}

	void setPresensi(float nilai) {
		this->presensi = nilai;
	}
	float getPresensi() {
		return presensi;
	}

	void setActivity(float nilai) {
		this->activity = nilai;
	}
	float getActivity() {
		return activity;
	}
	
	void setExercise(float nilai) {
		this->exercise = nilai;
	}
	float getExercise() {
		return exercise;
	}

	void setTugasAkhir(float nilai) {
		this->tugasAkhir = nilai;
	}
	float getTugasAkhir() {
		return tugasAkhir;
	}
};

class Pemrograman : public MataKuliah {
	void namaMataKuliah() {
		cout<< "Nama Mata Kuliah : Pemrograman";
	}
	void inputNilai() {
		float nilai;
		cout << "Masukkan nilai Presensi : ";
		cin >> nilai;
		setPresensi(nilai);
		
		cout << "Masukkan nilai Activity : ";
		cin >> nilai;
		setActivity(nilai);

		cout << "Masukkan Nilai Exercise : ";
		cin >> nilai;
		setExercise(nilai);

		cout << "Masukkan Nilai Tugas Akhir : ";
		cin >> nilai; 
		setTugasAkhir(nilai);
	}

	void hitungNilaiAkhir(float& rerata) {
		rerata = (getActivity() + getExercise() + getPresensi() + getTugasAkhir()) / 4.0f;
	}
	void cekKelulusan() {
		float avg;
		hitungNilaiAkhir(avg);

		if (avg >= 75) {
			cout << "Nilai Akhir anda adalah " << avg <<endl;
			cout << "Selamat Anda dinyatakan Lulus" << endl;
		}
		else {
			cout << "Nilai Akhir anda adalah " << avg << endl;
			cout << "Anda dinyatakan Tidak Lulus" << endl;
		}
	}
};

class Jaringan :public MataKuliah {
	void namaMataKuliah() {
		cout << "Nama Mata Kuliah : Jaringan";
	}
	void inputNilai() {
		float nilai;
		
		cout << "Masukkan nilai Activity : ";
		cin >> nilai;
		setActivity(nilai);
		cout << "Masukkan Nilai Exercise : ";
		cin >> nilai;
		setExercise(nilai);

	}
	void hitungNilaiAkhir(float& rerata) {
		rerata = (getActivity() + getExercise()) / 2.0f;
	}
	void cekKelulusan() {
		float avg;
		hitungNilaiAkhir(avg);
		if (avg >= 75) {
			cout << "Nilai Akhir anda adalah " << avg<<endl;
			cout << "Selamat Anda dinyatakan Lulus" << endl;
		}
		else {
			cout << "Nilai Akhir anda adalah " << avg << endl;
			cout << "Anda dinyatakan Tidak Lulus" << endl;
		}
	}
};

int main() {
	int pilih;
	MataKuliah* mataKuliah;
	Pemrograman pemrograman;
	Jaringan jaringan;

	do {
		cout << "\nPilih Mata Kuliah :" << endl;
		cout << "1. Pemrograman" << endl;
		cout << "2. Jaringan" << endl;
		cout << "3. Keluar" << endl;
		cout << "Pilih : " << endl;
		cin >> pilih;

		switch (pilih) {
		case 1:
			mataKuliah = &pemrograman;
			mataKuliah->inputNilai();
			mataKuliah->hitungNilaiAkhir();
			mataKuliah->cekKelulusan();
			break;

		case 2:
			mataKuliah = &jaringan;
			mataKuliah->inputNilai();
			mataKuliah->hitungNilaiAkhir();
			mataKuliah->cekKelulusan();
			break;
		case 3:
			break;
		default:
			cout << "Menu yang dipilih tidak tersedia, silahkan pilih lagi" << endl;
			system("pause");
			break;
		}
	} while (pilih != 3);
}