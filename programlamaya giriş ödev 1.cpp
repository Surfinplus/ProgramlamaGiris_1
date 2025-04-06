/*****************************************************************************************************************************************
**                                             SAKARYA ÜNİVERSİTESİ
*                                    BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
*                                          BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**                                            PROGRAMLAMAYA GİRİŞ DERSİ
**                     
**    ÖDEV NUMARASI :1
**    ÖĞRENCİ ADI: EREN ÇOBAN
**    ÖĞRENCİ NUMARASI:g211210090
**    DERS GRUBU:A
**
*********************************************************************************************************************************************/


#include <iomanip>
#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;
float enbuyuk;
float enkucuk;
float toplam;
float standartsapma;
float standartsapmatoplam;
int ogrencisayaci;
struct ogrenci {

    string adi;
    string soyadi;
    int No;
    float kisasinav1;
    float kisasinav2;
    float odev1;
    float odev2;
    float proje;
    float vize;
    float final;
    float yiliciNotu;
    float basariNotu;

    struct ogrenciDogumTarihi {

        string gun;
        string ay;
        int yil;


    };


};

string OgrenciIsim[30]{

   "Eren","Semih","Leyla","Sabri","Mete","Ada","Meryem","Enes","Yavuz","Emirhan","Yunus","Sude","Esat","Beyza","Yaren","Ceyhun","Elif","Hikmet",
   "Ege","Sezin","Demir","Resul","Ziya","Melih","Ceyda","Taylan","Gamze","Batuhan","Ahmet","Aysu"


};

string OgrenciSoyad[30]{

    "MESTAN","AKIN","KISA","UZUN","UMUR","SOBAT","COBAN","OZYURT","SOMAY","BULUT","YILDIZ","TURK","KAYA","KURU","CINEL","ALAF","OZTURK","KUSCU",
    "ACAR","ALTUN","BOZ","AVCI","BOLATLI","BUDAK","DURAK","ALKAN","KILIC","ARSLAN","KARA","YILDIRIM"
    // türkçe karakter kılıçta sıkıntı yaratıyor mu kontrol etmek için burda bir düzenleme yaptım kendime not . eğer kod çalışmazsa kılıç kılıc olarak düzeltilecek.



};
// ad soyadı mevcut olan öğrenciler dizisi
    ogrenci ogrenciler[100];                    

 float NotuHarfYap(float OgrenciNot);//girilen notu harfe çeviren fonksiyon
 float NotuKontrolEt(float OgrenciNot);//girilen notun doğruluğunu kontrol eden fonksiyon 
 float NotlarınOrtalamasınıHesapla();//öğrencilere atanan notların ortalamasını hesaplayan fonksiyon
 float StandartSapmaHesapla(int ogrencisayisi);//öğrencilere girilen notlarla orantılı olarak standart sapma hesaplayan fonksiyon
 float Aralıkbelirle(float min, float max);//menüdeki seçeneklerde kullanmak için yazdığım aralık belirleyip o aralıktaki notları sıralayan fonksiyon
 float Aralıkbelirle2(float max);//menüdeki seçeneklerde kullanmak için yazdığım aralık üst sınırı belirleyip o üst sınıra kadar olan notları gösteren fonksiyon
 float Aralıkbelirle3(float min);//menüdeki seçeneklerde kullanmak için yazdığım aralık alt sınırı belirleyip o alt sınıra kadar olan notları gösteren fonksiyon 
 

 int main()
 {

     char ch;
     setlocale(LC_ALL, "Turkish");

     int secenek{}, anamenu{};

     cout << "Öğrencilerin rasgele ve istenilen oranlarda girilmesi için 1 e basınız." << endl;
     cout << "Eğer rasgele değil manuel müdahale ile belirlemek istiyorsanız 2 ye basınız." << endl;
     cout << "Gireceğiniz değerlerin float olmasına dikkat ediniz." << endl;
     cin >> secenek;

     switch (secenek) 
     {

     case 1://öğrenciler dizisine otomatik atama yapan bölüm .

         srand(time(NULL));
         ogrencisayaci = 0;
         //öğrenci sayısı kadar rasgele isim soy isim yapmak üzere döngü
         for (int a = 0; a < 100; a++) 
         {



             ogrenciler[a].adi = OgrenciIsim[rand() % 30];
             ogrenciler[a].soyadi = OgrenciSoyad[rand() % 30];


             ogrencisayaci++;






         }
         //öğrenci kısa sınav odev proje vize final gibi notları istenilen oranlarda gerçekleştirmek için yazılan döngüler 

         //bu döngüde ilk 10 öğrenci için 40 bandına kadar rasgele not atanıyor ve bu değerlere göre yıliçi ve başarı notu hesaplanıyor.
         for (int b = 0; b < 10; b++) 
         {


             ogrenciler[b].kisasinav1 = rand() % 40;
             ogrenciler[b].kisasinav2 = rand() % 40;
             ogrenciler[b].odev1 = rand() % 40;
             ogrenciler[b].odev2 = rand() % 40;
             ogrenciler[b].proje = rand() % 40;
             ogrenciler[b].final = rand() % 40;
             ogrenciler[b].vize = rand() % 40;

             ogrenciler[b].yiliciNotu = (ogrenciler[b].vize * 0.5)
                 + (ogrenciler[b].kisasinav1 * 0.07)
                 + (ogrenciler[b].kisasinav2 * 0.07)
                 + (ogrenciler[b].odev1 * 0.10)
                 + (ogrenciler[b].odev2 * 0.10)
                 + (ogrenciler[b].proje * 0.16);


             ogrenciler[b].basariNotu = (ogrenciler[b].yiliciNotu * 0.55) + (ogrenciler[b].final * 0.45);


         }
         //bu döngüde öğrenciler 50 öğrenci için rasgele 40 70 bandı arası not atanıyor ve atanan notlar doğrultusunda başarı ve yıliçi notu hesaplanıyor.
         for (int c = 10; c < 60; c++) 
         {


             ogrenciler[c].kisasinav1 = 40 + (rand() % 30);
             ogrenciler[c].kisasinav2 = 40 + (rand() % 30);
             ogrenciler[c].odev1 = 40 + (rand() % 30);
             ogrenciler[c].odev2 = 40 + (rand() % 30);
             ogrenciler[c].proje = 40 + (rand() % 30);
             ogrenciler[c].final = 40 + (rand() % 30);
             ogrenciler[c].vize = 40 + (rand() % 30);

             ogrenciler[c].yiliciNotu = (ogrenciler[c].vize * 0.5)
                 + (ogrenciler[c].kisasinav1 * 0.07)
                 + (ogrenciler[c].kisasinav2 * 0.07)
                 + (ogrenciler[c].odev1 * 0.10)
                 + (ogrenciler[c].odev2 * 0.10)
                 + (ogrenciler[c].proje * 0.16);


             ogrenciler[c].basariNotu = (ogrenciler[c].yiliciNotu * 0.55) + (ogrenciler[c].final * 0.45);


         }

         //bu döngüde 15 öğrenci için rasgele sınav değerleri 70 80 bandı arasında atanıyor ve atanan değerlerle yıliçi ve başarı notu hesaplanıyor.
         for (int d = 60; d < 75; d++) 
         {


             ogrenciler[d].kisasinav1 = 70 + (rand() % 10);
             ogrenciler[d].kisasinav2 = 70 + (rand() % 10);
             ogrenciler[d].odev1 = 70 + (rand() % 10);
             ogrenciler[d].odev2 = 70 + (rand() % 10);
             ogrenciler[d].proje = 70 + (rand() % 10);
             ogrenciler[d].final = 70 + (rand() % 10);
             ogrenciler[d].vize = 70 + (rand() % 10);

             ogrenciler[d].yiliciNotu = (ogrenciler[d].vize * 0.5)
                 + (ogrenciler[d].kisasinav1 * 0.07)
                 + (ogrenciler[d].kisasinav2 * 0.07)
                 + (ogrenciler[d].odev1 * 0.10)
                 + (ogrenciler[d].odev2 * 0.10)
                 + (ogrenciler[d].proje * 0.16);


             ogrenciler[d].basariNotu = (ogrenciler[d].yiliciNotu * 0.55) + (ogrenciler[d].final * 0.45);



         }
         //bu döngüde 25 öğrenci için rasgele sınav değerleri atanıp bu değerler doğrultusunda yıliçi ve başarı notu hesaplanıyor.
         for (int e = 75; e < 100; e++) 
         {


             ogrenciler[e].kisasinav1 = 80 + (rand() % 20);
             ogrenciler[e].kisasinav2 = 80 + (rand() % 20);
             ogrenciler[e].odev1 = 80 + (rand() % 20);
             ogrenciler[e].odev2 = 80 + (rand() % 20);
             ogrenciler[e].proje = 80 + (rand() % 20);
             ogrenciler[e].final = 80 + (rand() % 20);
             ogrenciler[e].vize = 80 + (rand() % 20);

             ogrenciler[e].yiliciNotu = (ogrenciler[e].vize * 0.5)
                 + (ogrenciler[e].kisasinav1 * 0.07)
                 + (ogrenciler[e].kisasinav2 * 0.07)
                 + (ogrenciler[e].odev1 * 0.10)
                 + (ogrenciler[e].odev2 * 0.10)
                 + (ogrenciler[e].proje * 0.16);


             ogrenciler[e].basariNotu = (ogrenciler[e].yiliciNotu * 0.55) + (ogrenciler[e].final * 0.45);



         }
         //bu döngüde 100 öğrenci için 1000 e kadar rasgele öğrenci numaraları atanıyor.
         for (int f = 0; f < 100; f++) 
         {


             ogrenciler[f].No = rand() % 1000;



         }






         break;

         //bu case de manuel öğrenci girme işlemi gerçekleştiriliyor.
     case 2:
         do 
         {
             
              ogrencisayaci = 0;

             for (int x = 0; x < 100; x++) 
             {

                 cout << x + 1 << ". Öğrencinin Adını giriniz:" << endl;
                 cin >> ogrenciler[x].adi;


                 cout << x + 1 << ". Öğrencinin Soyadını giriniz: " << endl;
                 cin >> ogrenciler[x].soyadi;


                 cout << x + 1 << ". Öğrencinin Numarasını giriniz: " << endl;
                 cin >> ogrenciler[x].No;


                 cout << x + 1 << ". Öğrencinin 1. Kısa Sınav notunu giriniz: " << endl;
                 cin >> ogrenciler[x].kisasinav1;
                 NotuKontrolEt(ogrenciler[x].kisasinav1);

                 cout << x + 1 << ". Öğrencinin 2. Kısa Sınav notunu giriniz: " << endl;
                 cin >> ogrenciler[x].kisasinav2;
                 NotuKontrolEt(ogrenciler[x].kisasinav2);

                 cout << x + 1 << ". Öğrencinin 1. Ödev notunu giriniz: " << endl;
                 cin >> ogrenciler[x].odev1;
                 NotuKontrolEt(ogrenciler[x].odev1);


                 cout << x + 1 << ". Öğrencinin 2. Ödev notunu giriniz: " << endl;
                 cin >> ogrenciler[x].odev2;
                 NotuKontrolEt(ogrenciler[x].odev2);


                 cout << x + 1 << ". Öğrencinin Proje notunu giriniz:" << endl;
                 cin >> ogrenciler[x].proje;
                 NotuKontrolEt(ogrenciler[x].proje);


                 cout << x + 1 << ". Öğrencinin Vize notunu giriniz: " << endl;
                 cin >> ogrenciler[x].vize;
                 NotuKontrolEt(ogrenciler[x].vize);

                 cout << x + 1 << ". Öğrencinin Final notunu giriniz: " << endl;
                 cin >> ogrenciler[x].final;
                 NotuKontrolEt(ogrenciler[x].final);

                 ogrencisayaci ++;
                 
                 
                 ogrenciler[x].yiliciNotu = (ogrenciler[x].vize * 0.5)
                     + (ogrenciler[x].kisasinav1 * 0.07)
                     + (ogrenciler[x].kisasinav2 * 0.07)
                     + (ogrenciler[x].odev1 * 0.10)
                     + (ogrenciler[x].odev2 * 0.10)
                     + (ogrenciler[x].proje * 0.16);


                 ogrenciler[x].basariNotu = (ogrenciler[x].yiliciNotu * 0.55) + (ogrenciler[x].final * 0.45);

                 cout <<"Öğrencinin yıl içi notu: " << ogrenciler[x].yiliciNotu << endl;
                 cout <<"Öğrencinin başarı notu: " << ogrenciler[x].basariNotu << endl;

                 system("pause");
                 system("CLS");
                 
                 do 
                 {


                     cout << "başka bir öğrenci hakkında bilgi girmek ister misiniz?(e/h)" << endl;

                     cin >> ch;


                     system("CLS");





                 } while (!(ch == 'e' || ch == 'h'));
                    
                
                 if (ch == 'h')
                   break;
             
             }




         } while (ch == 'e');






     }
     do
     {
        system("pause");
        system("CLS");
     
        cout << setw(20) << "Menü" << endl;
        cout << "1) Sınıf listesi" << endl;
        cout << "2) Sınıfın En Yüksek Başarı Notu" << endl;
        cout << "3) Sınıfın En Düşük Başarı Notu" << endl;
        cout << "4) Sınıfın Ortalaması ve standart sapması " << endl;
        cout << "5) Başarı notu ortalaması istediğimiz değerler arasında olan öğrencilerin listesi" << endl;
        cout << "6) Başarı notu ortalaması istediğimiz değerin altında olan öğrencilerin listesi " << endl;
        cout << "7) Başarı notu ortalaması istediğimiz değerin üstünde olan öğrencilerin listesi " << endl;

        cout << "\n\n";

        cout << "Yapmak istediğiniz işlemin numarasını giriniz: " << endl;
        cin >> anamenu;
        system("CLS");
        
        switch (anamenu)

        {
         //bu case de öğrenci listesi hazırlanıyor her sayfada 20 öğrenci olmak şartıyla ve bekletilerek .
        case 1:
            //ilk 20 öğrencinin isim soy ismi sayfaya yazdırılıyor 
            for (int a = 0; a < 20; a++) 
            {

                cout << ogrenciler[a].adi << " " << ogrenciler[a].soyadi << endl;




            }
            system("PAUSE");
            system("CLS");
            //20-40 arası öğrencilerin isim soy isimleri sayfaya yazdırılıyor
            for (int a = 20; a < 40; a++) 
            {

                cout << ogrenciler[a].adi << " " << ogrenciler[a].soyadi << endl;



            }
            system("PAUSE");
            system("CLS");

            //40-60 arası öğrencilerin isim soy isimleri sayfaya yazdırılıyor
            for (int a = 40; a < 60; a++) 
            {

                cout << ogrenciler[a].adi << " " << ogrenciler[a].soyadi << endl;



            }

            system("PAUSE");
            system("CLS");

            //60-80 arası öğrencilerin isim soy isimleri sayfaya yazdırılıyor
            for (int a = 60; a < 80; a++) 
            {

                cout << ogrenciler[a].adi << " " << ogrenciler[a].soyadi << endl;

            }

            system("PAUSE");
            system("CLS");

            //80-100 arası öğrencilerin isim soy isimleri sayfaya yazdırılıyor
            for (int a = 80; a < 100; a++) 
            {

                cout << ogrenciler[a].adi << " " << ogrenciler[a].soyadi << endl;



            }
            break;
            system("PAUSE");
             system("CLS");
             //bu case de başarı notu en büyük öğrencinin başarı notu saptanıp ekrana yazdırılıyor 
        case 2:

            //ilk öğrenci için başarı notu en büyük olarak tanımlanıyor 
            enbuyuk = ogrenciler[0].basariNotu;
            //döngüde tanımlanan en büyük değer diğer öğrencilerin değerleri için test ediliyor 
            for (int x = 1; x < 100; x++) 
            {
             
                //burada değer test edilirken daha büyük bir değer çıkarsa en büyük değer olarak atama yapılıyor
                if (ogrenciler[x].basariNotu > enbuyuk) 
                {


                    enbuyuk = ogrenciler[x].basariNotu;
                 

                }
             

            }
                cout << "En büyük başarı notu: " << enbuyuk<<endl;

            break;

            //bu case de başarı notu en küçük öğrencinin başarı notu ekrana yazdırılıyor
        case 3:
     
            // ilk öğrenci için başarı notu en küçük olarak tanımlanıyor 
            enkucuk = ogrenciler[0].basariNotu;
            //döngüde tanımlanan en küçük değer diğer öğrencilerin değerleri için test ediliyor 
                for (int a = 1; a < 100; a++) 
                {

                    if (ogrenciler[a].basariNotu < enkucuk) 
                    {

                        enkucuk = ogrenciler[a].basariNotu;



                    }

                }
                        cout << "En küçük başarı notu:" << enkucuk<<endl;
     
            break;
     
            //case 4 ve case 5 için tek seçenek oluşturdum ve bu yeni oluşan case 4 not ortalaması ve standart sapmayı ekrana yazdırıyor  
        case 4:

            toplam = 0.0;
            //öğrencilerin başarı notlarını toplayan döngü
                for (int a = 0; a < 100; a++) 
                {

                    toplam += ogrenciler[a].basariNotu;



                }
                        cout <<"Başarı notu ortalaması: " << NotlarınOrtalamasınıHesapla()<< endl;
                            StandartSapmaHesapla(ogrencisayaci);

                     break;
               //bu case öğrencilerin başarı notlarından istediğimiz aralıkta olanı yazdırır
        case 5:
            float altdeger;
            float ustdeger;

                cout << "İstediğiniz aralığın alt değerini giriniz:  " << endl;
                cin >> altdeger;
                cout << "İstediğiniz aralığın üst değerini giriniz: " << endl;
                cin >> ustdeger;
                Aralıkbelirle(altdeger, ustdeger);






            break;
            //bu case öğrencilerin başarı notlarından seçtiğimiz üst değere kadar olanları yazdırır
        case 6 :

            float ustdeger2;
         
                cout << "İstediğiniz üst değeri giriniz: " << endl;
                cin >> ustdeger2;
                Aralıkbelirle2(ustdeger2);

                break;
            // bu case öğrencilerin başarı notlarından seçtiğimiz alt değere kadar olanları yazdırır
        case 7: 

            float altdeger2;

            cout << "İstediğiniz alt değeri giriniz: " << endl;
            cin >> altdeger2;
            Aralıkbelirle3(altdeger2);


            break;


        default:
                cout << "Hatalı seçim yaptınız" << endl;

            

        }
        
        do 
        {
            system("PAUSE");
            system("CLS");
            cout << "menuye donmek ister misiniz?(e/h)" << endl;

            cin >> ch;


            system("CLS");


        } while (!(ch == 'e' || ch == 'h'));
        if (ch == 'h')
            break;




   

     }   while (ch == 'e');


















 
















 }



   //not degerini harfe çeviren fonksiyon 
 float NotuHarfYap(float OgrenciNot)
 {
     if (OgrenciNot <= 100.0 && OgrenciNot > 85.0)

         cout << "A";

     else if (OgrenciNot <= 85.0 && OgrenciNot > 70.0)

         cout << "B";

     else if (OgrenciNot <= 70.0 && OgrenciNot > 59.0)

         cout << "C";

     else if (OgrenciNot <= 59.0 && OgrenciNot > 49.0)
         cout << "D";

     else if (OgrenciNot <= 49.0 && OgrenciNot >= 0.0)
         cout << "F";
     else
         cout << "Hatalı not girisi yaptınız" << endl;

     return 0;

 };

   // notu kontrol edip eğer 100 ile 0 arasındaysa yani bizim için doğruysa yazdıran doğru değilse ise hatasız olana kadar tekrar soran fonksiyon.
   
 float NotuKontrolEt(float OgrenciNot)
 {
       if (OgrenciNot >= 0.0 && OgrenciNot <= 100.0);

       
       else {
           
        
           for (; OgrenciNot < 0.0 || OgrenciNot > 100.0;) {

               
               cout << "Hatali not girdiniz" << endl;
               cout << "Tekrar not giriniz" << endl;
               cin >> OgrenciNot;
               
               
           }
           
           
       }
       return OgrenciNot;
      
       
 };

 //not ortalaması hesaplayan fonksiyon 

   float NotlarınOrtalamasınıHesapla() 
   {

       return toplam /ogrencisayaci;

   };
 
   
  

   float StandartSapmaHesapla(int ogrencisayisi) 
   {
       standartsapma = 0;
       standartsapmatoplam = 0;
       for (int m = 0; m < ogrencisayaci; m++) {

           standartsapmatoplam += pow(ogrenciler[m].basariNotu - NotlarınOrtalamasınıHesapla(), 2);

       }
         
       standartsapma = sqrt(standartsapmatoplam / (ogrencisayisi - 1));
       cout << "Standart Sapma: " << standartsapma << endl;


       return standartsapma;


   }
   float Aralıkbelirle(float min, float max)
   {
       for (int i = 0; i < 100; i++) {

           if (ogrenciler[i].basariNotu<max && ogrenciler[i].basariNotu>min) {

            cout <<"-->> Başarı Notunun Harf Karşılığı "<<"\t || " << ogrenciler[i].adi << "\t" << ogrenciler[i].soyadi << "||" << "Başarı notu: "
                 << ogrenciler[i].basariNotu<<NotuHarfYap(ogrenciler[i].basariNotu) << endl;
               

           }



       }



       return 0;


   };

   float Aralıkbelirle2(float max)

   {
       for (int i = 0; i < 100; i++) {

           if (ogrenciler[i].basariNotu < max)
               
               cout << ogrenciler[i].adi << "\t" << ogrenciler[i].soyadi << "||" << ogrenciler[i].basariNotu << endl;
              


       }
       
      
       return 0;


   };
   
   float Aralıkbelirle3(float min)
   {

       for (int i = 0; i < 100; i++) {

           if (ogrenciler[i].basariNotu > min)

               cout << ogrenciler[i].adi << "\t" << ogrenciler[i].soyadi << "||" << ogrenciler[i].basariNotu << endl;
           

       }

       return 0;

   };
   

