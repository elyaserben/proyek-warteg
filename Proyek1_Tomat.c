//Kelompok Tomat
//Elyaser Ben Guno & Muhammad Ayyasy
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include"user_friendly_baru.h"

	int a, i, j, k = 0, l, swap, pilih_f, pilih_w, x, ongkir, total = 0;  
	int jarak_baru[5] = {0}, rating_baru[5] = {0}, memilih(); 
	int f_jarak_a, f_jarak_b, f_rating, ada, fharga[20], jumlah[100]; 
	int random_rating(int rat[5]), random_jarak(int jar[5]), print_list_warteg(char war[5][30], int jar[5], int rat[5]), pilih_filter(char war[5][30], int jar[5], int rat[5]), filter_jarak(char war2[5][30], int jar2[5], int rat2[5]), filter_rating(char war2[5][30], int jar2[5], int rat2[5]), pilih_warteg();
	int print_menu_bahari(), print_menu_shinta(), print_menu_samudra(), print_menu_tegal(), print_menu_makmur(), pembuka();
	
	char menu[20][100]={"ayam goreng", "telur balado", "sop jamur", "es jeruk", "ikan tongkol", "telur ceplok", "sop tahu", "es teh  ", "rendang ", "telur dadar", "sayur nangka", "jus mangga", "ayam balado", "tempe orek", "kangkung", "air putih", "sate    ", "tahu    ", "tongseng", "boba    "};
	int harga[20]={7000, 3000, 4000, 4500, 6000, 4000, 3000, 2000, 10000, 5500, 2500, 8000, 9500, 2000, 2000, 0, 15000, 2000, 13000, 20000};
	char fmenu[20][100], temp[100], warteg_baru[5][30];
	
	int pilihAwal;
	char warteg[5][30]={"bahari","shinta","samudra","tegal","makmur"};
	int jarak[5], rating[5];

int main() {
	
	pilihAwal = print_header(pilihAwal);
	pilih_menu(pilihAwal);
	random_rating(rating);
	random_jarak(jarak);		
	pembuka();
	return 0;
}
	int pembuka(){
		print_list_warteg(warteg, jarak, rating);
		pilih_filter(warteg, jarak, rating);
		pilih_warteg();
		ulang();
	}

	int random_rating(int rat[5]) {
		srand(time(NULL));
		for(i=0; i<5; i++) {
			rat[i] = (rand()%5) + 1;
		}
		return 1;	
	}
	
	int random_jarak(int jar[5]) {
		srand(time(NULL));
		for(i=0; i<5; i++) {
			jar[i] = (rand()%8) + 1;
		}
		return 1;
	}
	
	int print_list_warteg(char war[5][30], int jar[5], int rat[5]) {
		system("cls");
		strip_line();
		printf("\tWarteg yang ada di sekitarmu: \n");
		printf("\n\t|no|warteg\t|jarak(km)\t|rating\t\t|");
		printf("\n\t|--|------------|---------------|---------------|");
		for(i=0; i<5; i++) {
			printf("\n\t|%d |%.7s\t|\t%d\t|\t%d\t|", i+1, war[i], jar[i], rat[i]);
		}
		return 1;
	}
	
	int pilih_filter(char war[5][30], int jar[5], int rat[5]) {
		printf("\n\n\tfilter warteg berdasar: \n\t(1) jarak\n\t(2) rating\n\n\tpilih: ");
		scanf("%d", &pilih_f);
		strip_line();
		if(pilih_f == 1){
			filter_jarak(war, jar, rat);
		}
		else if(pilih_f == 2) {
			filter_rating(war, jar, rat);
		}
		else { 
			printf("\n\tinput invalid, harus (1) atau (2)");
			return pilih_filter(war, jar, rat);
		}
	}
	
	int filter_jarak(char war2[5][30], int jar2[5], int rat2[5]) {
		printf("\n\tinput jarak terdekat\t: ");
		scanf("%d", &f_jarak_a);
		printf("\tinput jarak terjauh\t: ");
		scanf("%d", &f_jarak_b);
		for(j=0; j<5; j++) {
			for(i=0; i<5; i++) {
				if ((jar2[i] >= f_jarak_a) && (jar2[i] <= f_jarak_b)) {
					ada = ada + 1;
					strcpy(warteg_baru[i], war2[i]);
					jarak_baru[i] = jar2[i];
					rating_baru[i] = rat2[i];
				}
			}
		}
		if(ada == 0) {
			printf("\twarteg dengan range jarak dari %d km sampai %d km tidak ditemukan", f_jarak_a, f_jarak_b);
			return filter_jarak(war2, jar2, rat2);
		}
		system("cls");
		printf("\n\tList warteg setelah difilter:\n");
		printf("\n\t|no|warteg\t|jarak(km)\t|rating\t\t|");
		printf("\n\t|--|------------|---------------|---------------|");
		for(i=0; i<5; i++) {
			if((jarak_baru[i] > 0) && (rating_baru[i] > 0)) {
				printf("\n\t|%d |%.7s\t|\t%d\t|\t%d\t|", i+1, warteg_baru[i], jarak_baru[i], rating_baru[i]);
			}
		}
		return 1;
	}
	
	int filter_rating(char war2[5][30], int jar2[5], int rat2[5]) {
		printf("\n\tinput rating warteg yang ingin dicari: ");
  		scanf("%d", &f_rating);
  		for(j=0; j<5; j++) {
	  		for(i=0; i<5; i++) {
	    		if (rat2[i] == f_rating) {
	      			ada = ada + 1;
	      			strcpy(warteg_baru[i], war2[i]);
	      			jarak_baru[i] = jar2[i];
	      			rating_baru[i] = rat2[i];
	    		}
	  		}
	  	}
	  	if(ada == 0) {
	    	printf("\twarteg dengan rating %d tidak ditemukan\n", f_rating);
	    	strip_line();
	    	return filter_rating(war2, jar2, rat2);
	  	}
	  	system("cls");
	  	printf("\n\tList warteg setelah difilter:\n");
	  	printf("\n\t|no|warteg\t|jarak(km)\t|rating\t\t|");
	  	printf("\n\t|--|------------|---------------|---------------|");
	  	for(i=0; i<5; i++) {	
			if((jarak_baru[i] > 0) && (rating_baru[i] > 0)) {
				printf("\n\t|%d |%.7s\t|\t%d\t|\t%d\t|", i+1, warteg_baru[i], jarak_baru[i], rating_baru[i]);
			}
		}
	  	return 1;
	}
	
	int pilih_warteg() {
		printf("\n\n\tpilih warteg yang ingin dipesan: ");
		scanf("%d", &pilih_w);
		x = pilih_w-1;
		ongkir = 2000*jarak_baru[x];
		if((jarak_baru[x] == 0) && (rating_baru[x] == 0)) {
			printf("\tinput invalid, silahkan pilih salah satu warteg yang telah difilter");
			return pilih_warteg();
		}
		else {
			strip_line();
			if(strcmp(warteg_baru[x],"bahari") == 0) {
				header_bahari();
				print_menu_bahari();
			}
			else if(strcmp(warteg_baru[x],"shinta") == 0) {
				header_shinta();
				print_menu_shinta();
			}
			else if(strcmp(warteg_baru[x],"samudra") == 0) {
				header_samudra();
				print_menu_samudra();
			}
			else if(strcmp(warteg_baru[x],"tegal") == 0) {
				header_tegal();
				print_menu_tegal();
			}
			else if(strcmp(warteg_baru[x],"makmur") == 0) {
				header_makmur();
				print_menu_makmur();
			}
		}
	}
	
	int print_menu_bahari() {
		printf("\n\tmenu bahari:\t\tharga: \n");
		for(i=0; i<4; i++) {
			printf("\t%d. %.12s\t\t%d\n", i+1, menu[i], harga[i]);
		}
		printf("\n\tPilih menu yang ingin dipesan\t: ");
		scanf("%d", &x);
		if((x>0) && (x<5)) {
			strcpy(fmenu[k], menu[x-1]);
			fharga[k] = harga[x-1];
			
			printf("\tJumlah pemesanan\t\t: ");
			scanf("%d", &jumlah[k]);
			printf("\n\t1. Pesan menu lain\n\t2. Masuk ke Pembayaran");
			memilih();
			total = jumlah[k]*fharga[k]+total;
			//variabel k digunakan untuk melakukan iterasi rekursif
			if(j == 1) {
				k=k+1;
				strip_line();
				print_menu_bahari();
			}
			else if(j == 2) {
				for(i = 0; i < k+1; i++) {
					for(l = 0; l < k+1; l++) {
						if(jumlah[l]*fharga[l]<jumlah[l+1]*fharga[l+1]) {
							strcpy(temp, fmenu[l]);
							strcpy(fmenu[l], fmenu[l+1]);
							strcpy(fmenu[l+1], temp);
							
							swap = fharga[l];
							fharga[l] = fharga[l+1];
							fharga[l+1] = swap;
							
							swap = jumlah[l];
							jumlah[l] = jumlah[l+1];
							jumlah[l+1] = swap;
						}
					}
				}
				system("cls");
				strip_line();
				printf("\n\tCetak struk: ");
				printf("\n\n\t               WARTEG BAHARI               ");
				printf("\n\t===========================================\n");
				for(i = 0; i<k+1; i++) {
					printf("\t%.12s\t%d\t%d\t%d\n", fmenu[i], jumlah[i], fharga[i], jumlah[i]*fharga[i]);
				}
				printf("\n\t===========================================\n");
				printf("\tTotal Pesanan\t\t\t%d\n", total);
				printf("\tOngkos Kirim\t\t\t%d", ongkir);
				printf("\n\t===========================================\n");
				printf("\tTotal\t\t\t\t%d", total+ongkir);
			}
			return 1;
		}
		else {
			printf("\n\tinput invalid, silahkan pesan lagi\n");
			strip_line();
			return print_menu_bahari();
		}
	}
	
	int print_menu_shinta() {
		printf("\n\tmenu shinta:\t\tharga: \n");
		for(i = 4; i < 8; i++) {
			printf("\t%d. %.12s\t\t%d\n", i-3, menu[i], harga[i]);
		}
		printf("\n\tPilih menu yang ingin dipesan\t: ");
		scanf("%d", &x);
		if((x>0) && (x<5)) {
			strcpy(fmenu[k], menu[x+3]);
			fharga[k] = harga[x+3];
			
			printf("\tJumlah pemesanan\t\t: ");
			scanf("%d", &jumlah[k]);
			printf("\n\t1. Pesan menu lain\n\t2. Masuk ke Pembayaran");
			memilih();
			total = jumlah[k]*fharga[k]+total;
			//variabel k digunakan untuk melakukan iterasi rekursif
			if(j == 1) {
				k=k+1;
				strip_line();
				print_menu_shinta();
			}
			else if(j == 2) {
				for(i = 0; i < k+1; i++) {
					for(l = 0; l < k+1; l++) {
						if(jumlah[l]*fharga[l]<jumlah[l+1]*fharga[l+1]) {
							strcpy(temp, fmenu[l]);
							strcpy(fmenu[l], fmenu[l+1]);
							strcpy(fmenu[l+1], temp);
							
							swap = fharga[l];
							fharga[l] = fharga[l+1];
							fharga[l+1] = swap;
							
							swap = jumlah[l];
							jumlah[l] = jumlah[l+1];
							jumlah[l+1] = swap;
						}
					}
				}
				system("cls");
				strip_line();
				printf("\n\tCetak struk: ");
				printf("\n\n\t               WARTEG SHINTA               ");
				printf("\n\t===========================================\n");
				for(i = 0; i<k+1; i++) {
					printf("\t%.12s\t%d\t%d\t%d\n", fmenu[i], jumlah[i], fharga[i], jumlah[i]*fharga[i]);
				}
				printf("\n\t===========================================\n");
				printf("\tTotal Pesanan\t\t\t%d\n", total);
				printf("\tOngkos Kirim\t\t\t%d", ongkir);
				printf("\n\t===========================================\n");
				printf("\tTotal\t\t\t\t%d", total+ongkir);
			}
			return 1;
		}
		else {
			printf("\n\tinput invalid, silahkan pesan lagi\n");
			strip_line();
			return print_menu_shinta();
		}
	}
	
	int print_menu_samudra() {
		printf("\n\tmenu samudra:\t\tharga: \n");
		for(i = 8; i < 12; i++) {
			printf("\t%d. %.13s\t\t%d\n", i-7, menu[i], harga[i]);
		}
		printf("\n\tPilih menu yang ingin dipesan\t: ");
		scanf("%d", &x);
		if((x>0) && (x<5)) {
			strcpy(fmenu[k], menu[x+7]);
			fharga[k] = harga[x+7];
			
			printf("\tJumlah pemesanan\t\t: ");
			scanf("%d", &jumlah[k]);
			printf("\n\t1. Pesan menu lain\n\t2. Masuk ke Pembayaran");
			memilih();
			total = jumlah[k]*fharga[k]+total;
			//variabel k digunakan untuk melakukan iterasi rekursif
			if(j == 1) {
				k=k+1;
				strip_line();
				print_menu_samudra();
			}
			else if(j == 2) {
				for(i = 0; i < k+1; i++) {
					for(l = 0; l < k+1; l++) {
						if(jumlah[l]*fharga[l]<jumlah[l+1]*fharga[l+1]) {
							strcpy(temp, fmenu[l]);
							strcpy(fmenu[l], fmenu[l+1]);
							strcpy(fmenu[l+1], temp);
							
							swap = fharga[l];
							fharga[l] = fharga[l+1];
							fharga[l+1] = swap;
							
							swap = jumlah[l];
							jumlah[l] = jumlah[l+1];
							jumlah[l+1] = swap;
						}
					}
				}
				system("cls");
				strip_line();
				printf("\n\tCetak struk: ");
				printf("\n\n\t               WARTEG SAMUDRA              ");
				printf("\n\t===========================================\n");
				for(i = 0; i<k+1; i++) {
					printf("\t%.13s\t%d\t%d\t%d\n", fmenu[i], jumlah[i], fharga[i], jumlah[i]*fharga[i]);
				}
				printf("\n\t===========================================\n");
				printf("\tTotal Pesanan\t\t\t%d\n", total);
				printf("\tOngkos Kirim\t\t\t%d", ongkir);
				printf("\n\t===========================================\n");
				printf("\tTotal\t\t\t\t%d", total+ongkir);
			}
			return 1;
		}
		else {
			printf("\n\tinput invalid, silahkan pesan lagi\n");
			strip_line();
			return print_menu_samudra();
		}
	}
	
	int print_menu_tegal() {
		printf("\n\tmenu tegal:\t\tharga: \n");
		for(i = 12; i < 16; i++) {
			printf("\t%d. %.12s\t\t%d\n", i-11, menu[i], harga[i]);
		}
		printf("\n\tPilih menu yang ingin dipesan\t: ");
		scanf("%d", &x);
		if((x>0) && (x<5)) {
			strcpy(fmenu[k], menu[x+11]);
			fharga[k] = harga[x+11];
			
			printf("\tJumlah pemesanan\t\t: ");
			scanf("%d", &jumlah[k]);
			printf("\n\t1. Pesan menu lain\n\t2. Masuk ke Pembayaran");
			memilih();
			total = jumlah[k]*fharga[k]+total;
			//variabel k digunakan untuk melakukan iterasi rekursif
			if(j == 1) {
				k=k+1;
				strip_line();
				print_menu_tegal();
			}
			else if(j == 2) {
				for(i = 0; i < k+1; i++) {
					for(l = 0; l < k+1; l++) {
						if(jumlah[l]*fharga[l]<jumlah[l+1]*fharga[l+1]) {
							strcpy(temp, fmenu[l]);
							strcpy(fmenu[l], fmenu[l+1]);
							strcpy(fmenu[l+1], temp);
							
							swap = fharga[l];
							fharga[l] = fharga[l+1];
							fharga[l+1] = swap;
							
							swap = jumlah[l];
							jumlah[l] = jumlah[l+1];
							jumlah[l+1] = swap;
						}
					}
				}
				system("cls");
				strip_line();
				printf("\n\tCetak struk: ");
				printf("\n\n\t               WARTEG TEGAL                ");
				printf("\n\t===========================================\n");
				for(i = 0; i<k+1; i++) {
					printf("\t%.12s\t%d\t%d\t%d\n", fmenu[i], jumlah[i], fharga[i], jumlah[i]*fharga[i]);
				}
				printf("\n\t===========================================\n");
				printf("\tTotal Pesanan\t\t\t%d\n", total);
				printf("\tOngkos Kirim\t\t\t%d", ongkir);
				printf("\n\t===========================================\n");
				printf("\tTotal\t\t\t\t%d", total+ongkir);
			}
			return 1;
		}
		else {
			printf("\n\tinput invalid, silahkan pesan lagi\n");
			strip_line();
			return print_menu_tegal();
		}
	}
	
	int print_menu_makmur() {
		printf("\n\tmenu makmur:\t\tharga: \n");
		for(i = 16; i < 20; i++) {
			printf("\t%d. %.12s\t\t%4d\n", i-15, menu[i], harga[i]);
		}
		printf("\n\tPilih menu yang ingin dipesan\t: ");
		scanf("%d", &x);
		if((x>0) && (x<5)) {
			strcpy(fmenu[k], menu[x+15]);
			fharga[k] = harga[x+15];
			
			printf("\tJumlah pemesanan\t\t: ");
			scanf("%d", &jumlah[k]);
			printf("\n\t1. Pesan menu lain\n\t2. Masuk ke Pembayaran");
			memilih();
			total = jumlah[k]*fharga[k]+total;
			//variabel k digunakan untuk melakukan iterasi rekursif
			if(j == 1) {
				k=k+1;
				strip_line();
				print_menu_makmur();
			}
			else if(j == 2) {
				for(i = 0; i < k+1; i++) {
					for(l = 0; l < k+1; l++) {
						if(jumlah[l]*fharga[l]<jumlah[l+1]*fharga[l+1]) {
							strcpy(temp, fmenu[l]);
							strcpy(fmenu[l], fmenu[l+1]);
							strcpy(fmenu[l+1], temp);
							
							swap = fharga[l];
							fharga[l] = fharga[l+1];
							fharga[l+1] = swap;
							
							swap = jumlah[l];
							jumlah[l] = jumlah[l+1];
							jumlah[l+1] = swap;
						}
					}
				}
				system("cls");
				strip_line();
				printf("\n\tCetak struk: ");
				printf("\n\n\t               WARTEG MAKMUR               ");
				printf("\n\t===========================================\n");
				for(i = 0; i<k+1; i++) {
					printf("\t%.12s\t%d\t%d\t%d\n", fmenu[i], jumlah[i], fharga[i], jumlah[i]*fharga[i]);
				}
				printf("\n\t===========================================\n");
				printf("\tTotal Pesanan\t\t\t%d\n", total);
				printf("\tOngkos Kirim\t\t\t%d", ongkir);
				printf("\n\t===========================================\n");
				printf("\tTotal\t\t\t\t%d", total+ongkir);
			}
			return 1;
		}
		else {
			printf("\n\tinput invalid, silahkan pesan lagi\n");
			strip_line();
			return print_menu_makmur();
		}
	}
	
	int ulang(){
		printf("\n\n");
		strip_line();
		printf("\tProgram telah selesai\n");
		printf("\t1. Lakukan pembayaran dan memesan lagi\n");
		printf("\t2. Lakukan pembayaran dan tutup program\n");
		printf("\tPilih: ");
		scanf("%d", &a);
		if(a == 1) {
			printf("\tPembayaran selesai\n\n");
			strip_line();
			if(a == 1) {
				k = 0; total = 0; ada = 0;;
				for(i = 0; i<5; i++){
					jarak_baru[i] = 0;
					rating_baru[i] = 0;
				}
				return pembuka();
			}
		}
		else if(a == 2) {
			strip_line();
			printf("\n\n");
			return 0;
		}
		else {
			printf("\n\tInput invalid, harus 1 atau 2\n");
			return ulang();
		}
	}
	
	int memilih() {
		printf("\n\tMasukan pilihan\t\t\t: ");
		scanf("%d", &j);
		if(j<1 || j>2) {
			printf("\n\tinput invalid, silahkan masukan input 1 atau 2\n");
			return memilih();
		}
		return j;
	}
