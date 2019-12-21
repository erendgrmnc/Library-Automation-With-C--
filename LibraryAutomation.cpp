#include "iostream"
#include "fstream"
#include "string"

using namespace std;





int main()
{
	int eklenenKitapSayi = 0; //kaç adet verinin girildiðini tutan sayaç deðeri.
	int counter = 0; //Verileri text dosyasaýndan okurken sýradaki veriye geçmek için kullanýlan sayaç deðeri
	ifstream dosya;//dosyadan okuma islemlerini gerçeklestirmeye yarayan deðisken.
	ofstream dosyaYaz;// dosyaya veri yazmamýzý saðlayan deðiþken.
	
	dosya.open("kayitlar.txt");//"kayit.txt" dosyasýnýn açýlmasý.
	
	string kayitAl;//kayitlari dosyadan aldýktan sonra tutacaðýmýz deðiþken.

	string kayitlar[500];//Bütün kayýtlarý program çalýþma süresince tutacak dizi.

	while (dosya >> kayitAl)//dosyadaki verileri kelime kelime oku ve kayýtlar dizisine aktar.
	{
		
			kayitlar[counter] = kayitAl;
			
			counter++;
		eklenenKitapSayi++;
	}

	dosya.close();


	//Alinacak Verilerin Tanimlanmasi.
	
	string tc = { NULL };
	string kitapAdi = { NULL };
	string yazarAdi = { NULL };
	string sayfaSayi = { NULL };
	string kayitTarihi = { NULL };

	string bulunacakKisiTc = { NULL };
	bool Kontrol;


	int islem = 0;

	do
	{
		cout << "---------ISLEMLER-----------" << endl;
		cout << "1-)Kayit Ekle" << endl;
		cout << "2-)Kayit Ara" << endl;
		cout << "3-)Kayit Sil" << endl;
		cout << "4-)Kayit Duzenle" << endl;
		cout << "5-)Kayit Listele" << endl;
		cout << "6-)Cikis" << endl;
		cout << "Yapilacak islemin numarasini giriniz : " << endl;
		cin >> islem;

		

		switch (islem)
		{
		case 1:

			cout << "Kisinin TC'sini Giriniz :"; cin >> tc;
			cout << "Kitap Adi Giriniz :"; cin >> kitapAdi;
			cout << "Kitabin Yazarini Giriniz : "; cin >> yazarAdi;
			cout << "Sayfa Sayisini Giriniz :"; cin >> sayfaSayi;
			cout << "Basim Tarihini Giriniz :"; cin >> kayitTarihi;

			for (int i = eklenenKitapSayi; i < eklenenKitapSayi+1; i++)//alýnan verileri dizi içine her 5 elemanýn bir kayýdý tutacaðý þekilde yerleþtir.
			{
				kayitlar[i] = tc;
				kayitlar[i + 1] = kitapAdi;
				kayitlar[i + 2] = yazarAdi;
				kayitlar[i + 3] = sayfaSayi;
				kayitlar[i + 4] = kayitTarihi;
			}
			
			eklenenKitapSayi+=5;


		
			break;
			
		case 2:
			Kontrol = true;
			cout << "Buluncaka Kisinin Tc'sini Giriniz : "; cin >> bulunacakKisiTc;

			for (int i = 0; i < eklenenKitapSayi; i++)//Verilen tc deðerini kayitlar dizisinde bul ve o kayýda ait verileri yazdýr.
			{
				if (kayitlar[i] == bulunacakKisiTc)
				{
					cout << "Kitap Adi : " << kayitlar[i + 1] << endl;
					cout << "Yazar Adi : " << kayitlar[i + 2] << endl;
					cout << "Sayfa Sayisi : " << kayitlar [i + 3] << endl;
					cout << "Basim Tarihi : " << kayitlar[i + 4] << endl;
					Kontrol = false;

				}
			}
			if (Kontrol == true)
			{
				cout << "Kayit Bulunamadi..." << endl;
			}


			break;
		case 3:
			
			Kontrol = true;
			cout << "Silincek Kayidin Tc'sini Giriniz : " << endl;
			cin >> bulunacakKisiTc;
			for (int i = 0; i < eklenenKitapSayi; i++)//silinecek kaydý tc'sine göre bul ve kaydýn elemanlarýný NULL yap.
			{
				if (kayitlar[i] == bulunacakKisiTc)
				{
					kayitlar[i] = { NULL };
					kayitlar[i + 1] = { NULL };
					kayitlar[i + 2] = { NULL };
					kayitlar[i + 3] = { NULL };
					kayitlar[i + 4] = { NULL };
					Kontrol = false;
				}
			}

			if (Kontrol == true)
			{
				cout << "Kayit Bulunamadi ..." << endl;
			}

			break;

		  case 4:

			Kontrol = true;
			cout << "Duzenlenecek Kisinin TC'sini Giriniz : "; cin >> bulunacakKisiTc;

			for (int i = 0; i < eklenenKitapSayi; i++) //Tcsi alinan kaydin dizide denk gelen indisini bulur ve kaydin verilerini yazdýrýr.Ardýndan teker teker yeni verileri alýr.
			{
				if (kayitlar[i] == bulunacakKisiTc)
				{
					cout << "Kitap Adi : " << kayitlar[i+1] << endl;
					cout << "Kitabin Yazari :" << kayitlar[i+2] << endl;
					cout << "Sayfa Sayisi : " << kayitlar[i + 3] << endl;
					cout << "Basim Tarihi Giriniz : " << kayitlar[i+4] << endl;
					cout << "-----------------DUZENLENECEK DEGERLERI GIRINIZ ---------------" << endl;

					cout << "Kitap Adi Giriniz :"; cin >> kitapAdi;
					cout << "Yazar Adi Giriniz : "; cin >> yazarAdi;
					cout << "Sayfa Sayisini Giriniz :"; cin >> sayfaSayi;
					cout << "Basim Tarihini Giriniz :"; cin >> kayitTarihi;

					kayitlar[i + 1] = kitapAdi;
					kayitlar[i + 2] = yazarAdi;
					kayitlar[i + 3] = sayfaSayi;
					kayitlar[i + 4] = kayitTarihi;

					Kontrol = false;
				}
			}

			if (Kontrol == true)
			{
				cout << "Kayit Bulunamadi ..." << endl;
			}
			break;

		 case 5:
			for (int i = 0; i < eklenenKitapSayi; i++)//Her 5 eleman bir kayýda denk gelir.Bu yüzden indislerin 5 ' e göre modu alýnýr ve her bir kayýda ait veriler sýrayla yazdýrýlýr.
			{
				if (i % 5 == 0)
				{
					cout << "Kisinin TC'si : " << kayitlar[i] << endl;
				}

				else if (i % 5 == 1)
				{
					cout << "Kitap Adi : " << kayitlar[i] << endl;
				}

				else if(i % 5 == 2)
				{
					cout << "Yazar Adi : " << kayitlar[i] << endl;
					
				}
				else if (i % 5 == 3)
				{
					cout << "Sayfa Sayisi : " << kayitlar[i] << endl;
				}
				else if (i % 5 == 4)
				{
					cout << "Kayit Tarihi : " << kayitlar[i] << endl;
					cout << endl;
				}
				
			}
			break;





		}







	} while (islem != 6);
	//Istenen islem 6 olana kadar program çalýþýr.

	

	dosyaYaz.open("kayitlar.txt");//Kayitlar dizisindeki verilerin text dosyasýna yazýlmasý.

	for (int i = 0; i < eklenenKitapSayi; i++)
	{
		dosyaYaz << kayitlar[i] << " ";
	}
	dosyaYaz.close();

	
	

	return 0;
}