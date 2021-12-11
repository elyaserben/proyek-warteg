#include<stdio.h>
#include<stdlib.h>

int print_header(int a) {
	printf("\t================================================================\n");
	printf("\t===| |=| |=| |====/   |====| __  |==|__  __|==| ___|==| ____|===\n");
	printf("\t===| |=| |=| |===/ /| |====| |/ /=====| |=====| |__===| |____===\n");
	printf("\t===| |_| |/ /===/ __  |====| _ \\======| |=====|  __|==| |=| |===\n");
	printf("\t====\\ \\| / /===/ /==| |====| |\\ \\=====| |=====| |=====| |_/ /===\n");
	printf("\t=====\\____/===/_/===|_|====|_|=\\_\\====|_|=====|____|==|____/====\n");
	printf("\t================================================================\n");
	printf("\t________________________________________________________________\n");
	printf("\t------------------------WARTEG DIGITAL--------------------------\n");
	printf("\t--------------------------Created by----------------------------\n");
	printf("\t------------Elyaser Ben Guno -&- Muhammad Ayyasy----------------\n");
	printf("\n");
	printf("\t                Selamat datang di Program Kami                  \n"); 
	printf("\n");             
	printf("\t          ______________________                                \n");
	printf("\t         /_/_/_/_/_/_/_/_/_/_/_/\\       Silahkan pilih:         \n");
	printf("\t        /_/_/_/_/_/_/_/_/_/_/_/_/\\      1. Jalankan program     \n");
	printf("\t       /_/_/_/_/_/_/_/_/_/_/_/_/_/\\     2. Bantuan              \n");
	printf("\t         |  ___    ____________ |       selain 1 & 2. Keluar    \n");
	printf("\t         | |   |  |___________| |                               \n");
	printf("\t         | |   |  WARTEG DIGITAL|                               \n");
	printf("\t_________|_|___|________________|_______________________________\n");
	printf("\t----------------------------------------------------------------\n");
	printf("\t--------------------------------------------------------pilih: ");
	scanf("%d", &a);
	return a;
}

int bantuan() {
	system("cls");
	printf("\n");
	printf("\t                          BANTUAN                              \n\n");
	printf("\t|Program ini dapat memesan makanan dan/atau minuman dari warteg |\n");
	printf("\t|yang dipilih oleh user . Program ini akan memunculkan 5 warteg |\n");
	printf("\t|yg dapat dipilih oleh user beserta jarak & ratingnya. Angka da-|\n");
	printf("\t|ri jarak & rating warteg di-generate secara random. Lalu, User |\n");
	printf("\t|dapat memfilter pilihan warteg tersebut berdasar rentang jarak |\n");
	printf("\t|dan juga ratingnya.                                            |\n\n");
	printf("\t|Proses filter yang dilakukan pada program ini menggunakan algo-|\n");
	printf("\t|ritma sequential searching . Setelah user memfilter, maka user |\n"); 
	printf("\t|dapat memilih warteg mana yang akan dipesan. Lalu user memesan |\n");
	printf("\t|makanan dan/atau minuman dari warteg tersebut.                 |\n\n"); 
	printf("\t|Setelah user selesai memesan , maka akan tercetak struk pesan- | \n");
	printf("\t|an dngn harga pesanan yang diurutkan dari terbesar ke terkecil |\n");
	printf("\t|dengan menggunakan algoritma bubble sort. Lalu, harga pesanan, |\n");
	printf("\t|ongkir, dan juga total harga juga akan dicetak pada struk tsb. |\n");
	printf("\t|Nilai dari ongkir merupakan jarak warteg dikalikan dgn Rp2000. |\n");
	printf("\n");
	printf("\tpress ANY KEY to continue program ... ");
	getch();
	return 1;
}

int pilih_menu(int a) {
	if(a == 1) {
		return 1;
	}
	else if(a == 2) {
		bantuan();
	}
	else {
		abort();
	}
}

int strip_line() {
	printf("\t----------------------------------------------------------------\n");
	return 1;
}

int header_bahari() {
	system("cls");
	printf("\n\t        xxxxxxxxxx   ______________________                     \n");
	printf("\t       xxxxxxxxxxxxx/_/_/_/_/_/_/_/_/_/_/_/\\                   \n");
	printf("\t      xxxxxxxxxxxxx/_/_/_/_/_/_/_/_/_/_/_/_/\\                  \n");
	printf("\t       xxxxxxxxxxx/_/_/_/_/_/_/_/_/_/_/_/_/_/\\    ___________   \n");
	printf("\t         xxxxxxxx   |  ___    ____________ |     /_  _   ___ |  \n");
	printf("\t           | |      | |   |  |___________| |    /_| | | |___||  \n");
	printf("\t           | |      | |   |  WARTEG BAHARI |   |    |_|      |  \n");
	printf("\t___________|_|______|_|___|________________|___|_( )_____( )_|__\n");
	printf("\t______________________________________________________________\n");
	printf("\t------------------------ MENU BAHARI ---------------------------\n");
	return 1;
}

int header_shinta() {
	system("cls");
	printf("\n\t          xxxxxxxxxx ______________________|-------------------|\n");
	printf("\t       xxxxxxxxxxxxx/_/_/_/_/_/_/_/_/_/_/_/\\                   |\n");
	printf("\t      xxxxxxxxxxxxx/_/_/_/_/_/_/_/_/_/_/_/_/\\   BARBERSHOP     |\n");
	printf("\t       xxxxxxxxxxx/_/_/_/_/_/_/_/_/_/_/_/_/_/\\   __________ _  |\n");
	printf("\t         xxxxxxxx   |  ___    ____________ |    _/_|__|__|__|\\ |\n");
	printf("\t     _O    | |      | |   |  |___________| |   |  | |______|   |\n");
	printf("\t    /_||/  | |      | |   |  WARTEG SHINTA |   |  |            |\n");
	printf("\t___()==()__|_|______|_|___|________________|___|__|____________|\n");
	printf("\t________________________________________________________________\n");
	printf("\t------------------------ MENU SHINTA ---------------------------\n");
	return 1;
}

int header_samudra() {
	system("cls");
	printf("\n\t    _______________________________________|-------------------|\n");
	printf("\t   /_/_/_/_/_/_/_/_//_/_/_/_/_/_/_/_/_/_/_/\\                   |\n");
	printf("\t  /_/_/_/_/_/_/_/_//_/_/_/_/_/_/_/_/_/_/_/_/\\   KANTOR POS     |\n");
	printf("\t /_/_/_/_/_/_/_/_//_/_/_/_/_/_/_/_/_/_/_/_/_/\\   ___________   |\n");
	printf("\t |  _____BENGKEL_   |  ___    ____________ |    _/_|__|__|__|\\ |\n");
	printf("\t | |-------------|  | |   |  |___________| |   |  | |______|   |\n");
	printf("\t | |-------------|  | |   | WARTEG SAMUDRA |   |  |            |\n");
	printf("\t_|_|-------------|__|_|___|________________|___|__|____________|\n");
	printf("\t________________________________________________________________\n");
	printf("\t------------------------ MENU SAMUDRA --------------------------\n");
	return 1;
}

int header_tegal() {
	system("cls");
	printf("\n\t    _______________________________________|-------------------|\n");
	printf("\t   /_/_/_/_/_/_/_/_//_/_/_/_/_/_/_/_/_/_/_/\\                   |\n");
	printf("\t  /_/_/_/_/_/_/_/_//_/_/_/_/_/_/_/_/_/_/_/_/\\   TOKO KUE ABC   |\n");
	printf("\t /_/_/_/_/_/_/_/_//_/_/_/_/_/_/_/_/_/_/_/_/_/\\   ___________   |\n");
	printf("\t |       WARNET _   |  ___    ____________ |    _/_|__|__|__|\\ |\n");
	printf("\t |   _O    | | |_|  | |   |  |___________| |   |  | |______|   |\n");
	printf("\t |  /_||/  | |      | |   | WARTEG TEGAL   |   |  |            |\n");
	printf("\t_|_()==()__|_|______|_|___|________________|___|__|____________|\n");
	printf("\t________________________________________________________________\n");
	printf("\t------------------------ MENU TEGAL ----------------------------\n");
	return 1;
}

int header_makmur() {
	system("cls");
	printf("\n\t                     ______________________                     \n");
	printf("\t   _________________/_/_/_/_/_/_/_/_/_/_/_/\\                    \n");
	printf("\t  /_/_/_/_/_/_/_/_//_/_/_/_/_/_/_/_/_/_/_/_/\\                   \n");
	printf("\t /_/_/_/_/_/_/_/_//_/_/_/_/_/_/_/_/_/_/_/_/_/\\                  \n");
	printf("\t |  __TOKO JAHIT_   |  ___    ____________ |     ______  O      \n");
	printf("\t | |____|  | | |_|  | |   |  |___________| |    |bakso |=[]     \n");
	printf("\t |         | |      | |   | WARTEG MAKMUR  |    |______| []     \n");
	printf("\t_|_________|_|______|_|___|________________|_____()--()/_||_____\n");
	printf("\t________________________________________________________________\n");
	printf("\t------------------------ MENU MAKMUR ---------------------------\n");
	return 1;
}
