#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


void gotoxy(int x, int y){
    COORD coord = {X:0, Y:0};
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int saldo,saldoPlus;
char nama[20];

void Inputan(){
    system("cls");
        if(strcmp(nama,"")==0){
            gotoxy(50,3);printf("Masukan nama :");
            gets(nama);
            gotoxy(50,5);printf("Masukan saldo :");
            scanf("%d",&saldo);
            fflush(stdin);
        }
        else{
            gotoxy(50,3);printf("Masukan saldo :");
            scanf("%d",&saldoPlus);
            saldo=saldo+saldoPlus;
        }
}


int bintang(){
        int i, j, n;
        system("cls");
        printf("Masukkan lebar jam : ");
        scanf("%d",&n);
        for (i = 0; i < n-1; i++)
        {
                for (j = 0; j < n; j++)
                {
                    if ( i == n - 2||i == 0 || j==0 || j == n-1){printf("*");
                    }else if ( i + j + 1 == n-1  || i == j ){
                            printf("*");
                    }else if ((i > n/2-1) &&  ((j == n/2-1 || ((j==n/2 && n%2==1)) || ((j < i && j > n-i-2) && n < 10) || (((j < i && j > n-i-2) && i>(n/3+n)/2) && n >= 10))))
                    {
                        printf("*");
                    }else if ((i<n/2 && (i>n/9 && n<9 || (i>n/6 && n > 8))) && (j>=i && j < n-i-2))
                    {
                        printf("*");
                    }
                    else{
                            printf(" ");
                    }
                }
                printf("\n");
        }
}



int Login(){
    char username[20],pass[20],ch,a,verified;
    int i=0;
    system("cls");
    gotoxy(40,4);printf("*************************");
    gotoxy(48,5);printf("L O G I N\n");
    gotoxy(40,6);printf("*************************");
    gotoxy(40,8);printf("Username :");
    gets(username);
    gotoxy(40,10);printf("Password :");
    while((ch = getch())!=13){
    if(ch == 8){
        if(i>0){
        printf("\b \b");
        pass[i-1];
        i--;
        }
        else{
            printf("");
        }
    }
    else{
        pass[i]=ch;
        i++;
        printf("*");
        }
    }
    pass[i]='\0';
    if(strcmp(username,"fti")== 0 && strcmp(pass,"fti") == 0){
            return 1;
    }
    else{
        system("color E0");
        gotoxy(40,12);printf("EROR!");
        gotoxy(40,13);printf("Username dan Password salah\n");
        getch();
        if(a==2){
            gotoxy(40,15);printf("Maaf anda sudah memasukan username dan password sebanyak 3 kali!\n");
            getch();
            exit(0);
        }
        else{
            a++;
            i=0;
            return 0;
    }
}
}

int main()
{
    char b,menu,verified;
    int pilih,nominal,harga1=10000,harga2=8000,harga3=12000,harga4=10000,harga5=8000,harga,totalbeli=0,kembalian;

    //Loading bar

    system("color E0");
    system("cls");
    gotoxy(50,3);printf("SABAR CUYYY....\n");
    gotoxy(40,5);for(int i=0;i<32;i++){
        printf("%c",219);
        Sleep(100);
    }
    gotoxy(51,7);printf("KUYY LAH!");
    getch();

    //login
    while(verified == 0){
    verified=Login();
    }

    ulang:

    system("cls");
    gotoxy(50,3);printf("%c",201);for(int j=0;j<30;j++){
    printf("%c",205);}printf("%c",187);gotoxy(81,4);printf("%c\n",186);gotoxy(81,5);printf("%c",185);gotoxy(81,6);printf("%c",186);gotoxy(81,7);printf("%c",185);
    gotoxy(81,8);printf("%c\n",186);gotoxy(81,9);printf("%c\n",186);gotoxy(81,10);printf("%c\n",186);gotoxy(81,11);printf("%c\n",186);
    gotoxy(81,12);printf("%c\n",186);gotoxy(81,13);printf("%c\n",186);gotoxy(81,14);printf("%c\n",188);

    gotoxy(50,4);for(int i=0;i<1;i++){
    printf("%c\n",186);
    }
    gotoxy(50,4);printf("\tCUYY RESTO\n");

    gotoxy(50,6);printf("%c\n",186);gotoxy(51,7);for(int j=0;j<30;j++){
    printf("%c",205);}gotoxy(50,8);printf("%c\n",186);gotoxy(50,9);printf("%c\n",186);gotoxy(50,10);printf("%c\n",186);gotoxy(50,11);printf("%c\n",186);gotoxy(50,12);printf("%c\n",186);gotoxy(50,13);printf("%c\n",186);gotoxy(50,14);printf("%c",200);
    gotoxy(51,14);for(int j=0;j<30;j++){printf("%c",205);}gotoxy(50,7);printf("%c",204);gotoxy(50,5);printf("%c",204);for(int j=0;j<30;j++){
    printf("%c",205);}

    gotoxy(52,6);printf("Menu :");
    gotoxy(53,8); printf("1. Tambah isi dompet");
    gotoxy(53,9); printf("2. Total saldo");
    gotoxy(53,10);printf("3. Menu makanan");
    gotoxy(53,11);printf("4. Cetak jam pasir");
    gotoxy(53,12);printf("5. Pesan dan kesan");
    gotoxy(53,13);printf("6. Keluar");
    gotoxy(50,15);printf("Pilih: ");
    scanf("%d",&pilih);
    fflush(stdin);


    switch(pilih)
    {
    case 1:
        Inputan();
        gotoxy(50,7);printf("Ingin mengulang program? [Y/N] :");
        scanf("%s",&b);
        fflush(stdin);

        if(b == 'Y'|| b == 'y'){
            goto ulang;
        }
        else if(b == 'N' || b == 'n'){
            exit(0);
        }
        else{
            gotoxy(50,9);printf("Inputan tidak dikenali");
        }
        break;

    case 2:
        system("cls");
        if(saldo==0){
            gotoxy(50,3);printf("Anda tidak memiliki saldo!");
        }
        else{
            gotoxy(50,3);printf("Isi saldo atas nama %s sejumlah Rp. %d",nama,saldo);

        }
        gotoxy(50,6);printf("ingin mengulang program? [Y/N] :");
        scanf("%s",&b);
        if(b =='Y' || b == 'y'){
            goto ulang;
        }
        else if(b == 'N' || b == 'n'){
            exit(0);
        }
        else{
            printf("Inputan tidak dikenali");
        }
        break;

    case 3:
        menu:
        system("cls");
        gotoxy(50,3);printf("LIST MENU MAKANAN");
        gotoxy(50,4);printf("1. Nasi goreng\tRp. %d",harga1);
        gotoxy(50,5);printf("2. Nasi rames\t\tRp. %d",harga2);
        gotoxy(50,6);printf("3. Nasi ayam geprek\tRp. %d",harga3);
        gotoxy(50,7);printf("4. Nasi ayam bali\tRp. %d",harga4);
        gotoxy(50,8);printf("5. Nasi uduk\t\tRp. %d",harga5);
        gotoxy(50,10);printf("Pilihan menu : ");
        scanf("%d",&menu);
        fflush(stdin);

            if(menu==1)
            {
                harga = 10000;
                gotoxy(50,12);printf("menu berhasil ditambahkan");
                totalbeli=totalbeli+harga;
                gotoxy(50,13);printf("total tagihan : %i", totalbeli);

            }
            else if(menu==2)
            {
                harga = 8000;
                gotoxy(50,12);printf("menu berhasil ditambahkan");
                totalbeli=totalbeli+harga;
                gotoxy(50,13);printf("total tagihan : %i", totalbeli);
            }
            else if(menu==3)
            {
                harga = 12000;
                gotoxy(50,12);printf("menu berhasil ditambahkan\n\n");
                totalbeli=totalbeli+harga;
                gotoxy(50,13);printf("total tagihan : %i", totalbeli);
            }
            else if(menu==4)
            {
                harga = 10000;
                gotoxy(50,12);printf("menu berhasil ditambahkan\n\n");
                totalbeli=totalbeli+harga;
                gotoxy(50,13);printf("total tagihan : %i", totalbeli);
            }
            else if(menu==5)
            {
                harga = 8000;
                gotoxy(50,12);printf("menu berhasil ditambahkan\n\n");
                totalbeli=totalbeli+harga;
                gotoxy(50,13);printf("total tagihan : %i", totalbeli);
            }
            else
            {
                gotoxy(50,12);printf("Pilihan tidak tersedia");
            }
            gotoxy(50,16);printf("Ingin memesan lagi? [Y/N]:");
            scanf("%s",&b);
            fflush(stdin);

        if (b =='Y' || b == 'y'){
            goto menu;
        }
        else{
        kasir:
        system("cls");
        }
        gotoxy(50,3);printf("KASIR");
        gotoxy(50,5);printf("Tagihan yang harus dibayar : Rp. %d ",totalbeli );
        gotoxy(50,6);printf("Total saldo : Rp. %d",saldo);
        gotoxy(50,8);printf("Masukan nominal: ");
        scanf("%d",&nominal);
        fflush(stdin);


        if(nominal > saldo){
            gotoxy(50,10);printf("Saldo anda tidak cukup");
            getch();
            goto ulang;
        }
        else if(nominal < totalbeli){
            gotoxy(50,10);printf("uang tidak cukup");
            getch();
            goto kasir;

        }
        else if(nominal > totalbeli && totalbeli >= 20000){
            gotoxy(50,10);printf("Pembayaran Sukses");
            gotoxy(50,11);printf("Kembalian: Rp.%d", kembalian=nominal-totalbeli);
            gotoxy(50,12);printf("Saldo Anda Sekarang Adalah: Rp.%d\n",saldo=saldo-totalbeli);
            gotoxy(50,13);printf("Bonus dapat es teh");
            getch();
            totalbeli=0;
        }
        else if(nominal == totalbeli && totalbeli >= 20000){
            gotoxy(50,10);printf("Pembayaran Sukses");
            gotoxy(50,12);printf("Saldo Anda Sekarang Adalah: Rp.%d\n",saldo=saldo-totalbeli);
            gotoxy(50,13);printf("Bonus dapat es teh");
            getch();
            totalbeli=0;
        }
        else if(nominal > totalbeli){
            gotoxy(50,10);printf("Pembayaran Sukses");
            gotoxy(50,11);printf("Kembalian: Rp.%d", kembalian=nominal-totalbeli);
            gotoxy(50,12);printf("Saldo Anda Sekarang Adalah: Rp.%d\n",saldo=saldo-totalbeli);
            getch();
            totalbeli=0;
        }
        else if(nominal == totalbeli){
            gotoxy(50,10);printf("Pembayaran Sukses");
            gotoxy(50,12);printf("Saldo Anda Sekarang Adalah: Rp.%d\n",saldo=saldo-totalbeli);
            getch();
            totalbeli=0;
        }
        fflush(stdin);
        gotoxy(50,15);printf("ingin mengulang program? [Y/N] :");
        scanf("%s",&b);
        if(b =='Y' || b == 'y'){
            goto ulang;
        }
        else if(b == 'N' || b == 'n'){
            exit(0);
        }
        else{
            printf("Inputan tidak dikenali");
        }
        break;

    case 4:
        bintang();
        printf("Ingin mengulang program? [Y/N]:");
        scanf("%s",&b);
        if(b =='Y' || b == 'y'){
            goto ulang;
        }
        else if(b == 'N' || b == 'n'){
            exit(0);
        }
        else{
            printf("\nInputan tidak dikenali");
        }
        break;

    case 5:
        system("cls");
        printf("\nPesan dan Kesan Untuk Asdos Tercinta:\n");
        printf("1. Linggar\n");
        printf("Pesan:\n");
        printf(" - Kak Adit: Tidak bisa berkata kata, pokoknya Sehat dan Sukses selalu.\n");
        printf(" - Kak Agung: Semoga menjadi asdos yang bisa berguna untuk adik-adiknya.\n");
        printf("Kesan:\n");
        printf(" - Kak Adit: First Impression nya cool banget\n");
        printf(" - Kak Agung: Ngajarnya santai tapi tidak lalai\n");
        printf("2. Ronan\n");
        printf("Pesan:\n");
        printf(" - Kak Adit: Terimakasih sudah mau memberi ilmu yang bermanfaat ini.\n");
        printf(" - Kak Agung: Terimakasih sudah mau mendampingi dan sabar dengan kami.\n");
        printf("Kesan:\n");
        printf(" - Kak Adit: Orangnya asik tapi sering bikin quiz dadakan.\n");
        printf(" - Kak Agung: Orangnya kelihatan cuek tapi aslinya ramah.\n");
        printf("3. Vino\n");
        printf("Pesan:\n");
        printf(" - Kak Adit: Terimakasih sudah mau mendampingi dan sabar dengan kami.\n");
        printf(" - Kak Agung: Pokoknya Sehat dan Sukses selalu.\n");
        printf("Kesan:\n");
        printf(" - Kak Adit: Ngajarnya asik.\n");
        printf(" - Kak Agung: Asik dan santai ngajarnya.\n");
        printf("4. Dhika\n");
        printf("Pesan:\n");
        printf(" - Kak Adit: Semoga menjadi asdos yang bisa berguna untuk adik-adiknya.\n");
        printf(" - Kak Agung: Semoga sukses dan tetap semangat\n");
        printf("Kesan:\n");
        printf(" - Kak Adit: Mudah paham sama materinya\n");
        printf(" - Kak Agung: Ngajarnya asik tapi terkadang kecepetan\n");
        printf("5. Kefli\n");
        printf("Pesan:\n");
        printf(" - Kak Adit: Semoga menjadi asdos yang bisa berguna untuk adik-adiknya.\n");
        printf(" - Kak Agung: Terimakasih sudah mau memberi ilmu yang bermanfaat ini.\n");
        printf("Kesan:\n");
        printf(" - Kak Adit: Orangnya asik\n");
        printf(" - Kak Agung: Orangnya asik\n");
        printf("\nIngin mengulang program? [Y/N]:");
        scanf("%s",&b);
        if(b =='Y'|| b == 'y'){
            goto ulang;
        }
        else if(b == 'N' || b == 'n'){
            exit(0);
        }
        else{
            printf("Inputan tidak dikenali");
        }
        break;

    case 6:
        exit(0);

    default:
        gotoxy(50,16);printf("Pilihan tidak ada");
        getch();
        goto ulang;

    }
}
