// TUGAS BESAR PRAKTIKUM ALGORITMA DAN PEMROGRAMAN
// KELOMPOK : 9
// KELAS    : EL-45-03
// JUDUL    : D'GAME

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user {
	char fname[50], lname[50], username[50], password[30];
	int balance;
} seller, buyer, upd;

struct product {
	char game_name[50], seller[50], buyer[50];
	int game_price, stock;	
} gameSeller, gameBuyer, order, refund, buy, gsort[255], tmp;

char username[50], password[30], find[50], str[255], game[50], choose;
int add,amount,i,j,n,o,s,temp, x;
long int offset_byte;
FILE *ptr;
FILE *ptr2;

void Home();
void loadingBar();
void gameSort();
void adminLogin();
void adminMenu();
void adminGame();
void adminSeller();
void adminSeller_find();
void adminRefund();
void buyerSignup();
void buyerLogin(int l);
void buyerMenu(char* Mbuyer);
void buyerBeli(char* Bbuyer);
void buyerRefund(char* Rbuyer);
void sellerSignup();
void sellerLogin(int l);
void sellerMenu(char* Mseller);
void sellerConfirm(char* Cseller);

/* ================================================= MAIN ======================================= */
void main(){
	printf("\n");
	printf(" ==================================================================================== \n");
	printf("                                   SELAMAT DATANG                                     \n");
	printf(" ==================================================================================== \n\n");
	printf("     O)))))       O))      O))))            O)          O))       O))   O))))))))     \n");
	printf("     O))   O))     O)    O)    O))         O) ))        O) O))   O)))   O))           \n");
	printf("     O))    O))         O))               O)  O))       O)) O)) O O))   O))           \n");
	printf("     O))    O))         O))              O))   O))      O))  O))  O))   O))))))       \n");
	printf("     O))    O))         O))   O))))     O)))))) O))     O))   O)  O))   O))           \n");
	printf("     O))   O))           O))    O)     O))       O))    O))       O))   O))           \n");
	printf("     O)))))               O)))))      O))         O))   O))       O))   O))))))))     \n\n");
	printf(" ==================================================================================== \n");
	printf(" ==================================================================================== \n\n");
	loadingBar(); system("cls");
	Home();
}

void loadingBar()
{
	char a = 177, b = 219;
	for (i = 0; i < 85; i++){
		printf("%c", a);
	}
	printf("\r ");
	for (i = 0; i < 84; i++) {
		printf("%c", b);
		Sleep(50);
	}
}

void dgame_header(){
	printf("\n");
	printf(" ==================================================================================== \n");
	printf("                                   DGAME                                              \n");
	printf(" ==================================================================================== \n\n");
}
void line(){
	printf("\n ==================================================================================== \n\n");
}
void Home(){
	printf("\n");
	printf(" ==================================================================================== \n");
	printf("                                   SELAMAT DATANG                                     \n");
	printf(" ==================================================================================== \n\n");
	printf(" [1] Masuk    \n");
	printf(" [2] Daftar   \n"); 
	printf(" [3] ADMIN    \n");
	printf(" [0] Keluar   \n");line();
	printf(" Pilih : "); scanf("%d", &n); getchar();
	if(n == 1){
		Home_login:
		system("cls");
		dgame_header();
		printf(" [1] Pembeli \n");
		printf(" [2] Penjual \n");
		printf(" [0] Kembali \n"); line();
		printf(" Pilih : "); scanf("%d", &o); getchar();
		switch(o){
			case 0:
				system("cls");
				Home();
				break;
			case 1:
				system("cls");
				buyerLogin(3);
				break;
			case 2:
				system("cls");
				sellerLogin(3);
				break;
			default:
				printf("\n Pilihan yang dimasukan salah ! \n\n");
				system("pause"); system("cls");
				goto Home_login;
		}
	} else if (n == 2){
		Home2:
		system("cls");
		dgame_header();
		printf(" [1] Pembeli \n");
		printf(" [2] Penjual \n");
		printf(" [0] Kembali \n"); line();
		printf(" Pilih : "); scanf("%d", &o); getchar();
		switch(o){
			case 0:
				system("cls");
				Home();
				break;
			case 1:
				system("cls");
				buyerSignup();
				break;
			case 2: 
				system("cls");
				sellerSignup();
				break;
			default:
			printf("\n Pilihan yang dimasukan salah ! \n\n");
			system("pause"); system("cls");
			goto Home2;
		}
	} else if(n == 3) {
		system("cls");
		adminLogin();
	} else if(n == 0){
		system("cls");
		printf("\n"); line();
		printf("                                   SAMPAI JUMPA                                       \n\n");
		printf("                      Terima Kasih telah menggunakan DGAME :)                         \n"); line();
	} else {
		printf("\n Pilihan yang dimasukan salah ! \n\n");
		system("pause"); system("cls");
		Home();
	}
}

void gameBuyerSort(){
	ptr = fopen("DGAME-GameBuyer.dat","rb");
	ptr2 = fopen("DGAME-GameBuyer_sort.dat","wb");
	n = 0;
	while(fread(&gameBuyer, sizeof(gameBuyer), 1, ptr) == 1){
		strcpy(gsort[n].game_name, gameBuyer.game_name);
		strcpy(gsort[n].seller, gameBuyer.seller);
		strcpy(gsort[n].buyer, gameBuyer.buyer);
		gsort[n].game_price = gameBuyer.game_price;
		gsort[n].stock = gameBuyer.stock;
		n++;
	}
	for(i=n-1; i>=1; i--){
		for(j=1; j<=i; j++){
			if(strcmp(gsort[j-1].game_name, gsort[j].game_name) > 0){
				tmp = gsort[j-1];
				gsort[j-1] = gsort[j];
				gsort[j] = tmp;
			}
		}
	}
	for(i=0; i<=n-1; i++){
		strcpy(gameBuyer.game_name, gsort[i].game_name);
		strcpy(gameBuyer.seller, gsort[i].seller);
		strcpy(gameBuyer.buyer, gsort[i].buyer);
		gameBuyer.game_price = gsort[i].game_price;
		gameBuyer.stock = gsort[i].stock;
		fwrite(&gameBuyer, sizeof(gameBuyer), 1, ptr2);
	}
	fclose(ptr);
	fclose(ptr2);
	remove("DGAME-GameBuyer.dat");
	rename("DGAME-GameBuyer_sort.dat","DGAME-GameBuyer.dat");
}

void gameSellerSort(){
	ptr = fopen("DGAME-GameSeller.dat","rb");
	ptr2 = fopen("DGAME-GameSeller_sort.dat","wb");
	n = 0;
	while(fread(&gameSeller, sizeof(gameSeller), 1, ptr) == 1){
		strcpy(gsort[n].game_name, gameSeller.game_name);
		strcpy(gsort[n].seller, gameSeller.seller);
		strcpy(gsort[n].buyer, gameSeller.buyer);
		gsort[n].game_price = gameSeller.game_price;
		gsort[n].stock = gameSeller.stock;
		n++;
	}
	for(i=n-1; i>=1; i--){
		for(j=1; j<=i; j++){
			if(strcmp(gsort[j-1].game_name, gsort[j].game_name) > 0){
				tmp = gsort[j-1];
				gsort[j-1] = gsort[j];
				gsort[j] = tmp;
			}
		}
	}
	for(i=0; i<=n-1; i++){
		strcpy(gameSeller.game_name, gsort[i].game_name);
		strcpy(gameSeller.seller, gsort[i].seller);
		strcpy(gameSeller.buyer, gsort[i].buyer);
		gameSeller.game_price = gsort[i].game_price;
		gameSeller.stock = gsort[i].stock;
		fwrite(&gameSeller, sizeof(gameSeller), 1, ptr2);
	}
	fclose(ptr);
	fclose(ptr2);
	remove("DGAME-GameSeller.dat");
	rename("DGAME-GameSeller_sort.dat","DGAME-GameSeller.dat");
}

/* ================================================= ADMIN ======================================= */
void adminLogin(){
	dgame_header();
	printf("\t\t ADMIN LOGIN \n\n");
	printf(" username : "); gets(username);
	printf(" password : "); gets(password);
	if(strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0){
		system("cls");
		adminMenu();
	} else {
		printf("\n\n username dan password salah. \n\n");
		system("pause"); system("cls");
		adminLogin();
	}
}
void adminMenu(){
	dgame_header();
	printf("\t\t ADMIN MENU \n\n");
	printf(" [1] Daftar Game       \n"); 
	printf(" [2] Daftar Penjual    \n");
	printf(" [3] Refund Game       \n"); 
	printf(" [0] Logout            \n"); line();
	printf(" Pilih: "); scanf("%d", &n);
	switch(n){
		case 0:
			system("cls");
			Home();
			break;
		case 1:
			system("cls");
			adminGame();
			break;
		case 2:
			system("cls");
			adminSeller();
			break;
		case 3:
			system("cls");
			adminRefund();
			break;
		default:
			printf("Pilihan yang dimasukan salah");
			system("pause"); system("cls");
			adminMenu();
	}
}
void adminGame(){
	gameSellerSort();
	dgame_header();
	printf("\t\t DAFTAR GAME \n\n");
	ptr = fopen("DGAME-GameSeller.dat","rb");
	s = 1;
	while(fread(&gameSeller, sizeof(gameSeller), 1, ptr) == 1){
		printf(" %d. Nama Game : %s \n", s, gameSeller.game_name);
		printf("    Harga     : Rp%d \n", gameSeller.game_price);
		printf("    Stok      : %d \n", gameSeller.stock);
		printf("    Penjual   : %s \n\n", gameSeller.seller);
		s++;
	}
	fclose(ptr);
	line();
	printf(" [1] Hapus Game \n [0] Kembali \n\n Pilih: "); scanf("%d", &n);
	switch(n){
		case 0:
			system("cls");
			adminMenu();
			break;
		case 1:
			line();
			ptr = fopen("DGAME-GameSeller.dat","rb");
			ptr2 = fopen("DGAME-GameSeller_new.dat","wb");
			printf(" Masukan nama game yang ingin dihapus: "); getchar();
			gets(find);
			while(fread(&gameSeller, sizeof(gameSeller), 1, ptr)==1){
				if(strcmp(gameSeller.game_name, find)!=0){
					fwrite(&gameSeller, sizeof(gameSeller), 1, ptr2);
				} else {
					printf("\n Game berhasil dihapus. \n\n");
				}
			}
			fclose(ptr);
			fclose(ptr2);
			remove("DGAME-GameSeller.dat");
			rename("DGAME-GameSeller_new.dat","DGAME-GameSeller.dat");
			system("pause"); system("cls");
			adminGame();
			break;
		default:
			system("cls");
			adminMenu();	
	}
}
void adminSeller(){
	dgame_header();
	printf("\t\t ADMIN - Daftar Seller \n\n");
	ptr = fopen("DGAME-Seller.dat", "rb");
	s = 1;
	while(fread(&seller, sizeof(seller), 1, ptr) == 1){
		printf(" %d. Nama Lengkap    : %s %s \n", s, seller.fname, seller.lname);
		printf("    Nama Pengguna   : %s \n", seller.username);
		printf("    Saldo Penjualan : Rp%d \n\n", seller.balance);
		s++;
	}
	fclose(ptr);
	line();
	printf(" [1] Cari Penjual \n [0] Kembali \n\n");
	printf(" Pilih : "); scanf("%d", &n);
	switch(n){
		case 0:
			system("cls");
			adminMenu();
			break;
		case 1:
			system("cls");
			adminSeller_find();
			break;
		default:
			system("pause"); system("cls");
			adminSeller();
	}
}
void adminSeller_find(){
	dgame_header();
	printf("\t\t ADMIN - Cari Penjual \n\n");
	ptr = fopen("DGAME-Seller.dat", "rb");
	ptr2 = fopen("DGAME-Seller_find.dat", "wb");
	getchar();
	printf("\n Silahkan masukkan username penjual yang dicari : \n "); gets(find);
	while(fread(&seller, sizeof(seller), 1, ptr) == 1){
		if(strcmp(seller.username, find) == 0){
			fwrite(&seller, sizeof(seller), 1, ptr2);
		}
	}
	fclose(ptr);
	fclose(ptr2);
	gameSellerSort();
	ptr = fopen("DGAME-Seller_find.dat", "rb");
	ptr2 = fopen("DGAME-GameSeller.dat", "rb");
	if(fread(&seller, sizeof(seller), 1, ptr) == 1){
		printf("\n  Nama Lengkap    : %s %s \n", seller.fname, seller.lname);
		printf("  Nama Pengguna   : %s \n", seller.username);
		printf("  Saldo Penjualan : Rp%d \n\n", seller.balance);
		printf("  Daftar game yang dijual: \n");
		s = 1;
		while(fread(&gameSeller, sizeof(gameSeller), 1, ptr2) == 1){
			if(strcmp(gameSeller.seller, seller.username) == 0){
				printf("  %d. Nama Game : %s \n", s, gameSeller.game_name);
				printf("     Harga     : Rp%d \n", gameSeller.game_price);
				printf("     Stok      : %d \n", gameSeller.stock);
				s++;
			}
		}
	} else if(fgets(str,255,ptr) == NULL){
		printf("\n  Penjual tidak ditemukan. \n");
	}
	fclose(ptr);
	remove("DGAME-Seller_find.dat");
	line();
	findx:
	printf(" [1] Cari Penjual lain \n [0] Kembali \n\n");
	printf(" Pilih : "); scanf("%d", &n);
	switch(n){
		case 0:
			system("cls");
			adminMenu();
			break;
		case 1:
			system("cls");
			adminSeller_find();
			break;
		default:
			goto findx;
	}	
}
void adminRefund(){
	FILE *tp;
	dgame_header();
	printf("\t\t KONFIRMASI REFUND \n\n");
	//Melihat daftar Refund
	ptr = fopen("DGAME-Refund.dat", "rb");
	s = 1;
	while(fread(&refund, sizeof(refund), 1, ptr) == 1){
		printf(" %d. Nama Game   : %s \n", s, refund.game_name);
		printf("    Jumlah      : %d \n", refund.stock);
		printf("    Total Harga : Rp%d \n", refund.game_price*refund.stock);
		printf("    Pembeli     : %s \n", refund.buyer);
		printf("    Penjual     : %s \n\n", refund.seller);
		s++;
	}
	fclose(ptr);
	line();
	// memilih refund yang akan di konfirmasi dan menyalin ke temp
	printf(" [1] Konfirmasi refund \n [0] Kembali \n Pilih: "); scanf("%d", &o);
	switch(o){
		case 0:
			system("cls");
			adminMenu();
			break;
		case 1:
			tp = fopen("Temp.dat","wb");
			ptr = fopen("DGAME-Refund.dat", "rb");
			printf("\n Masukan nomor urut : "); scanf("%d", &n);
				offset_byte = (n - 1) * sizeof(refund);
		    	fseek(ptr, offset_byte, SEEK_SET);
		    	if (fread(&refund, sizeof(refund), 1, ptr) != 0){
			        strcpy(tmp.game_name, refund.game_name);
			        strcpy(tmp.seller, refund.seller);
			        strcpy(tmp.buyer, refund.buyer);
			        tmp.game_price = refund.game_price;
			        tmp.stock = refund.stock;
			        fwrite(&tmp, sizeof(tmp), 1, tp);
			    }
			fclose(tp);
			fclose(ptr);
			// update data refund
			tp = fopen("Temp.dat","rb");
			ptr = fopen("DGAME-Refund.dat","rb");
			ptr2 = fopen("DGAME-Refund_new.dat","wb");
			while(fread(&tmp, sizeof(tmp), 1, tp) == 1){
				while(fread(&refund, sizeof(refund), 1, ptr) == 1){
					if(strcmp(refund.game_name, tmp.game_name) != 0 && refund.stock != tmp.stock){
						fwrite(&refund, sizeof(refund), 1, ptr2);
					}
				}
			}
			fclose(tp);
			fclose(ptr);
			fclose(ptr2);
			remove("DGAME-Refund.dat");
			rename("DGAME-Refund_new.dat","DGAME-Refund.dat");
			
			tp = fopen("Temp.dat","rb");
			while(fread(&tmp, sizeof(tmp), 1, tp) == 1){
				// Menambahakan ke data gameSeller
				ptr = fopen("DGAME-Seller.dat","rb");
				while(fread(&seller, sizeof(seller), 1, ptr) == 1){
					if(strcmp(tmp.seller, seller.username) == 0){
						x = 1;
					}
				} 
				fclose(ptr);
				ptr = fopen("DGAME-GameSeller.dat", "rb");
				ptr2 = fopen("DGAME-GameSeller_new.dat", "wb");
				while(fread(&gameSeller, sizeof(gameSeller), 1, ptr) == 1){
					if(strcmp(gameSeller.game_name, tmp.game_name) == 0){
						strcpy(gameSeller.game_name, tmp.game_name);
						strcpy(gameSeller.seller, tmp.seller);
						strcpy(gameSeller.buyer, tmp.buyer);
						temp = gameSeller.stock;
						gameSeller.stock = temp + tmp.stock;
						fwrite(&gameSeller, sizeof(gameSeller), 1, ptr2);
					}
				}
				fclose(ptr);
				fclose(ptr2);
				remove("DGAME-GameSeller.dat");
				rename("DGAME-GameSeller_new.dat","DGAME-GameSeller.dat");
				// update Data Game buyer
				ptr = fopen("DGAME-GameBuyer.dat","rb");
				ptr2 = fopen("DGAME-GameBuyer_new.dat","wb");
				while(fread(&gameBuyer, sizeof(gameBuyer), 1, ptr) == 1){
					if(strcmp(gameBuyer.game_name, tmp.game_name)==0 && x == 1){
						gameBuyer.stock -= tmp.stock;
					} else if(strcmp(gameBuyer.game_name, tmp.game_name)==0 && gameBuyer.stock > 0){
						fwrite(&gameBuyer, sizeof(gameBuyer), 1, ptr2);
					} else {
						fwrite(&gameBuyer, sizeof(gameBuyer), 1, ptr2);
					}
				}
				fclose(ptr);
				fclose(ptr2);
				remove("DGAME-GameBuyer.dat");
				rename("DGAME-GameBuyer_new.dat","DGAME-GameBuyer.dat");
				// update Buyer 
				ptr = fopen("DGAME-Buyer.dat","rb");
				ptr2 = fopen("DGAME-Buyer_new.dat","wb");
				while(fread(&buyer, sizeof(buyer), 1, ptr) == 1){
					if(strcmp(buyer.username, tmp.buyer)==0 && x == 1){
						buyer.balance += tmp.game_price;
						fwrite(&buyer, sizeof(buyer), 1, ptr2);
					} else {
						fwrite(&buyer, sizeof(buyer), 1, ptr2);
					}
				}
				fclose(ptr);
				fclose(ptr2);
				remove("DGAME-Buyer.dat");
				rename("DGAME-Buyer_new.dat","DGAME-Buyer.dat");
				// update seller 
				ptr = fopen("DGAME-Seller.dat","rb");
				ptr2 = fopen("DGAME-Seller_new.dat","wb");
				while(fread(&seller, sizeof(seller), 1, ptr) == 1){
					if(strcmp(seller.username, tmp.seller)==0 && x == 1){
						seller.balance -= tmp.game_price;
						fwrite(&seller, sizeof(seller), 1, ptr2);
					} else {
						fwrite(&seller, sizeof(seller), 1, ptr2);
					}
				}
				fclose(ptr);
				fclose(ptr2);
				remove("DGAME-Seller.dat");
				rename("DGAME-Seller_new.dat","DGAME-Seller.dat");
			}
			fclose(tp);
			remove("Temp.dat");
			if(x == 1){
				printf("\n\n Konfirmasi Refund Berhasil. \n\n\n");
			} else {
				printf("\n\n Konfirmasi Refund Gagal. \n\n\n");
			}
			system("pause"); system("cls");
			adminMenu();
			break;
		default:
			system("pause"); system("cls");
			adminMenu();
	}
}
/* ================================================= BUYER ======================================= */
void buyerSignup(){
	dgame_header();
	printf("\t\t BUYER - SIGNUP \n\n");
	printf(" Buat username         : "); gets(username);
	ptr = fopen("DGAME-Buyer.dat", "rb");
	ptr2 = fopen("DGAME-BuyerSignup.dat", "wb");
	while(fread(&buyer, sizeof(buyer), 1, ptr) == 1){
		if(strcmp(buyer.username, username) == 0){
			fwrite(&buyer, sizeof(buyer), 1, ptr2);
		}
	}
	fclose(ptr);
	fclose(ptr2);
	ptr = fopen("DGAME-Buyer.dat", "ab");
	ptr2 = fopen("DGAME-BuyerSignup.dat", "rb");
	if(fgets(str,255,ptr2) != NULL){
		n = 0;
	} else if(fgets(str,255,ptr2) == NULL){
		strcpy(buyer.username, username);
		printf(" Buat password         : "); gets(buyer.password);
		printf(" Masukan Nama Depan    : "); gets(buyer.fname);
		printf(" Masukan Nama Belakang : "); gets(buyer.lname);
		buyer.balance = 0;
		fwrite(&buyer, sizeof(buyer), 1, ptr);
		n = 1;
	}
	fclose(ptr);
	fclose(ptr2);
	remove("DGAME-BuyerSignup.dat");
	switch(n){
		case 0:
			printf("\n username telah digunakan. \n");
			system("pause"); system("cls");
			buyerSignup();
			break;
		case 1:
			printf("\n Pendaftaran Berhasil. \n\n");
			printf(" [1] Login \n");
			printf(" [0] Kembali \n\n");
			printf(" Pilih : "); scanf("%d", &o); getchar();
			if(o == 1){
				system("cls");
				buyerLogin(3);
			} else {
				system("cls");
				Home();
			}
			break;
	}
}
void buyerLogin(int l){
	dgame_header();
	ptr = fopen("DGAME-Buyer.dat", "rb");
	ptr2 = fopen("DGAME-BuyerLogin.dat", "wb");
	printf("\t\t BUYER - LOGIN \n\n");
	printf(" username      : "); gets(username);
	printf(" password      : "); gets(password);
	if(l >= 1){
		while (fread(&buyer,sizeof(buyer),1, ptr) == 1){
			if (strcmp(buyer.username, username)==0){
				fwrite(&buyer, sizeof(buyer), 1, ptr2);
			} 
		} 
		while (fgets(str,255,ptr2) == NULL){
			fwrite(&buyer, sizeof(buyer), 1, ptr2);
		}
	} 
	fclose(ptr);
	fclose(ptr2);
	ptr = fopen("DGAME-Buyer.dat", "rb");
	ptr2 = fopen("DGAME-BuyerLogin.dat", "rb");
	if(l > 1){
		while (fread(&buyer, sizeof(buyer), 1, ptr2) == 1){
			if(strcmp(username, buyer.username) != 0){
				printf("\n username salah \n\n");
				system("pause"); system("cls");
				n = 1;
				break;
			}else if(strcmp(password, buyer.password) != 0){
				printf("\n password salah \n\n");
				system("pause"); system("cls");
				n = 1;
				break;
			} else if(strcmp(username, buyer.username) == 0 && strcmp(password, buyer.password) == 0){
				printf("\n Login berhasil \n\n");
				system("pause"); system("cls");
				n = 2;
				break;
			}
		}
	} else if(l == 1){
		while (fread(&buyer,sizeof(buyer),1, ptr2) == 1){
			if (strcmp(username, buyer.username) != 0 && strcmp(password, buyer.password) != 0){
				printf("\n username dan password salah \n\n");
				system("pause"); system("cls");
				n = 3;
				break;
			} else if(strcmp(username, buyer.username) == 0 && strcmp(password, buyer.password) == 0){
				printf("\n Login berhasil \n\n");
				system("pause"); system("cls");
				n = 2;
				break;
			}
		}
	} 
	fclose(ptr);
	fclose(ptr2);
	remove("DGAME-BuyerLogin.dat");
	switch(n){
		case 1:
			buyerLogin(l-1);
			break;
		case 2:
			buyerMenu(username);
			break;
		case 3:
			Home();
			break;
	}
}
void buyerMenu(char* Mbuyer){
	dgame_header();
	printf("\n\t\t BUYER MENU                  \n\n");
	printf(" [1] Informasi Akun                \n");
	printf(" [2] Membeli Game                  \n"); 
	printf(" [3] Top Up Saldo                  \n");
	printf(" [4] Refund Game                   \n");
	printf(" [5] Daftar Game Dibeli            \n");
	printf(" [0] Logout                        \n"); line();
	printf(" Pilih = "); scanf("%d",&n);
	switch(n){
		case 0:
			system("cls");
			Home();
			break;
		case 1:
			system("cls");
			dgame_header();
			printf("\t\t INFO AKUN \n\n");
			ptr = fopen("DGAME-Buyer.dat","rb");
			while(fread(&buyer, sizeof(buyer), 1, ptr) == 1){
				if(strcmp(buyer.username, Mbuyer) == 0){
					printf(" Nama Lengkap  : %s %s \n", buyer.fname, buyer.lname);
					printf(" Nama pengguna : %s \n", buyer.username);
					printf(" Kata sandi    : %s \n", buyer.password);
					printf(" Saldo         : Rp%d \n", buyer.balance); line();
				}
			}
			fclose(ptr);
			system("pause"); system("cls");
			buyerMenu(Mbuyer);
			break;
		case 2:
			system("cls");
			buyerBeli(Mbuyer);
			break;
		case 3:
			system("cls");
			dgame_header();
			printf("\t\t TOP UP SALDO \n\n");
			ptr = fopen("DGAME-Buyer.dat", "rb");
			ptr2 = fopen("DGAME-BuyerUpd.dat", "wb");
			printf(" Masukan jumlah top up : Rp"); scanf("%d", &add);
			while(fread(&buyer, sizeof(buyer), 1, ptr)==1){
				if(strcmp(buyer.username, Mbuyer)==0){
					strcpy(upd.username, buyer.username);
					strcpy(upd.password, buyer.password);
					strcpy(upd.fname, buyer.fname);
					strcpy(upd.lname, buyer.lname);
					upd.balance = buyer.balance + add;
					fwrite(&upd, sizeof(upd), 1, ptr2);
				} else if(strcmp(buyer.username, Mbuyer)!=0) {
					strcpy(upd.username, buyer.username);
					strcpy(upd.password, buyer.password);
					strcpy(upd.fname, buyer.fname);
					strcpy(upd.lname, buyer.lname);
					upd.balance = buyer.balance;
					fwrite(&upd, sizeof(upd), 1, ptr2);
				}
			}
			fclose(ptr);
			fclose(ptr2);
			remove("DGAME-Buyer.dat");
			rename("DGAME-BuyerUpd.dat","DGAME-Buyer.dat");
			printf("\n Top up saldo berhasil. \n"); line();
			system("pause");
			system("cls");
			buyerMenu(Mbuyer);			
			break;
		case 4:
			system("cls");
			buyerRefund(Mbuyer);
			break;
		case 5:
			system("cls");	
			gameBuyerSort();
			dgame_header();
			printf("\t\t DAFTAR GAME YANG DIBELI \n\n");
			ptr = fopen("DGAME-GameBuyer.dat","rb");
			s = 1;
			while(fread(&gameBuyer, sizeof(gameBuyer), 1, ptr) == 1){
				if(strcmp(gameBuyer.buyer, Mbuyer) == 0){
					printf("\n %d. Nama Game    : %s \n", s, gameBuyer.game_name);
					printf("    Stok         : %d \n", gameBuyer.stock);
					printf("    Harga        : Rp%d \n", gameBuyer.game_price);
					printf("    Di beli dari : %s \n\n", gameBuyer.seller);
					s++;
				}
			}
			fclose(ptr);
			line();
			system("pause"); system("cls");
			buyerMenu(Mbuyer);
			break;
		default:
			printf("\nPilihan angka yang dimasukan salah. \n");
			system("pause"); system("cls");
			buyerMenu(Mbuyer);
	}
}
void buyerBeli(char *Bbuyer){
	gameSellerSort();
	dgame_header();
	printf("\t\t BELI GAME \n\n");
	ptr = fopen("DGAME-GameSeller.dat","rb");
	s = 1;
	while(fread(&gameSeller, sizeof(gameSeller), 1, ptr) == 1){
		if(gameSeller.stock > 0){
			printf(" %d. Nama Game : %s \n", s, gameSeller.game_name);
			printf("    Harga     : Rp%d \n", gameSeller.game_price);
			printf("    Stok      : %d \n", gameSeller.stock);
			printf("    Penjual   : %s \n\n", gameSeller.seller);
			s++;	
		}
	}
	fclose(ptr);
	line();
	ptr = fopen("DGAME-GameSeller.dat","rb");
	ptr2 = fopen("DGAME-Order.dat","ab");
	printf(" :: Beli Game :: \n"); getchar();
	printf(" Nama Game : "); gets(game);
	printf(" Jumlah    : "); scanf("%d", &amount);
	while(fread(&gameSeller, sizeof(gameSeller), 1, ptr) == 1){
		if(strcmp(game, gameSeller.game_name)==0 && (gameSeller.stock - amount) >= 0){
			strcpy(order.game_name, game);
			strcpy(order.seller, gameSeller.seller);
			strcpy(order.buyer, Bbuyer);
			order.game_price = gameSeller.game_price;
			order.stock = amount;
			fwrite(&order, sizeof(order), 1, ptr2);
			printf("\n ~ Silahkan menunggu konfirmasi pembelian dari penjual.");
			printf("\n ~ Jika saldo tidak mencukupi, maka pembelian tidak dapat dikonfirmasi.");
			printf("\n ~ Pembelian game yang telah di konfimasi, dapat di lihat pada bagian ");
			printf("\n   Daftar Game Dibeli \n\n\n");
			n = 1;
		} 
	}
	fclose(ptr);
	fclose(ptr2);
	switch(n){
		case 1:
			system("pause"); system("cls");
			buyerMenu(Bbuyer);
			break;
		default:
			printf("\n Stok game tidak mencukupi atau Game tidak ditemukan. \n\n"); 
			system("pause"); system("cls");
			buyerMenu(Bbuyer);
	}
}
void buyerRefund(char* Rbuyer){
	gameSellerSort();
	dgame_header();
	printf("\t\t REFUND GAME \n\n");
	ptr = fopen("DGAME-GameBuyer.dat","rb");
	s = 1; n = 0;
	while(fread(&gameBuyer, sizeof(gameBuyer), 1, ptr) == 1){
		if(strcmp(gameBuyer.buyer, Rbuyer) == 0){
			printf(" %d. Nama Game       : %s \n", s, gameBuyer.game_name);
			printf("    Harga           : Rp%d \n", gameBuyer.game_price);
			printf("    Stok            : %d \n", gameBuyer.stock);
			printf("    Di beli dari    : %s \n\n", gameBuyer.seller);
			s++;	
		}
	}
	fclose(ptr);
	line();
	ptr = fopen("DGAME-GameBuyer.dat","rb");
	ptr2 = fopen("DGAME-Refund.dat","ab");
	printf(" :: Refund Game :: \n"); getchar();
	printf(" Nama Game : "); gets(game);
	printf(" Jumlah    : "); scanf("%d", &amount);
	while(fread(&gameBuyer, sizeof(gameBuyer), 1, ptr) == 1){
		if(strcmp(game, gameBuyer.game_name)==0 && (gameBuyer.stock - amount) >= 0){
			strcpy(refund.game_name, game);
			strcpy(refund.seller, gameBuyer.seller);
			strcpy(refund.buyer, Rbuyer);
			refund.game_price = gameBuyer.game_price;
			refund.stock = amount;
			fwrite(&refund, sizeof(refund), 1, ptr2);
			printf("\n ~ Silahkan menunggu konfirmasi pengembalian dari Admin.");
			printf("\n ~ Jika pengembalian (refund) disetujui oleh Admin, ");
			printf("\n   maka saldo pengembalian akan ditambahkan ke saldo Anda.\n\n");
			n = 1;
			break;
		}
	}
	fclose(ptr);
	fclose(ptr2);
	if( n != 1){
		printf("\n Anda tidak memiliki game yang dimasukan atau stok tidak cukup. \n\n");
	}
	system("pause"); system("cls");
	buyerMenu(Rbuyer);
}
/* ================================================= SELLER ====================================== */
void sellerSignup(){
	dgame_header();
	printf("\t\t SELLER - SIGNUP \n\n");
	printf(" Buat username         : "); gets(username);
	ptr = fopen("DGAME-Seller.dat", "rb");
	ptr2 = fopen("DGAME-SellerSignup.dat", "wb");
	while(fread(&seller, sizeof(seller), 1, ptr) == 1){
		if(strcmp(seller.username, username) == 0){
			fwrite(&seller, sizeof(seller), 1, ptr2); 
		}
	}
	fclose(ptr);
	fclose(ptr2);
	ptr = fopen("DGAME-Seller.dat", "ab");
	ptr2 = fopen("DGAME-SellerSignup.dat", "rb");
	if(fgets(str,255,ptr2) != NULL){
		n = 0;
	} else if(fgets(str,255,ptr2) == NULL){
		strcpy(seller.username, username);
		printf(" Buat password         : "); gets(seller.password);
		printf(" Masukan Nama Depan    : "); gets(seller.fname);
		printf(" Masukan Nama Belakang : "); gets(seller.lname);
		seller.balance = 0;
		fwrite(&seller, sizeof(seller), 1, ptr);
		n = 1;
	}
	fclose(ptr);
	fclose(ptr2);
	remove("DGAME-SellerSignup.dat");
	switch(n){
		case 0:
			printf("\n username telah digunakan. \n");
			system("pause"); system("cls");
			sellerSignup();
			break;
		case 1:
			printf("\n Pendaftaran Berhasil. \n\n");
			printf(" [1] Login \n");
			printf(" [0] Kembali \n\n");
			printf(" Pilih : "); scanf("%d", &o); getchar();
			if(o == 1){
				system("cls");
				sellerLogin(3);
			} else {
				system("cls");
				Home();
			}
			break;
	}
}
void sellerLogin(int l){
	dgame_header();
	ptr = fopen("DGAME-Seller.dat", "rb");
	ptr2 = fopen("DGAME-SellerLogin.dat", "wb");
	printf("\t\t SELLER - LOGIN \n\n");
	printf(" username      : "); gets(username);
	printf(" password      : "); gets(password);
	if(l >= 1){
		while (fread(&seller,sizeof(seller),1, ptr) == 1){
			if (strcmp(seller.username, username)==0){
				fwrite(&seller, sizeof(seller), 1, ptr2);
			} 
		} 
		while (fgets(str,255,ptr2) == NULL){
			fwrite(&seller, sizeof(seller), 1, ptr2);
		}
	} 
	fclose(ptr);
	fclose(ptr2);
	ptr = fopen("DGAME-Seller.dat", "rb");
	ptr2 = fopen("DGAME-SellerLogin.dat", "rb");
	if(l > 1){
		while (fread(&seller, sizeof(seller), 1, ptr2) == 1){
			if(strcmp(username, seller.username) != 0){
				printf("\n username salah \n\n");
				system("pause"); system("cls");
				n = 1;
				break;
			}else if(strcmp(password, seller.password) != 0){
				printf("\n password salah \n\n");
				system("pause"); system("cls");
				n = 1;
				break;
			} else if(strcmp(username, seller.username) == 0 && strcmp(password, seller.password) == 0){
				printf("\n Login berhasil \n\n");
				system("pause"); system("cls");
				n = 2;
				break;
			}
		}
	} else if(l == 1){
		while (fread(&seller,sizeof(seller),1, ptr2) == 1){
			if (strcmp(username, seller.username) != 0 && strcmp(password, seller.password) != 0){
				printf("\n username dan password salah \n\n");
				system("pause"); system("cls");
				n = 3;
				break;
			} else if(strcmp(username, seller.username) == 0 && strcmp(password, seller.password) == 0){
				printf("\n Login berhasil \n\n");
				system("pause"); system("cls");
				n = 2;
				break;
			}
		}
	} 
	fclose(ptr);
	fclose(ptr2);
	remove("DGAME-SellerLogin.dat");
	switch(n){
		case 1:
			sellerLogin(l-1);
			break;
		case 2:
			sellerMenu(username);
			break;
		case 3:
			Home();
			break;
	}
}
void sellerMenu(char* Mseller){
	dgame_header();
	printf("\t\t SELLER MENU  \n\n");
	printf(" [1] Informasi Akun           \n"); 
	printf(" [2] Upload Game              \n"); 
	printf(" [3] Lihat Game               \n"); 
	printf(" [4] Konfirmasi Pembelian     \n");
	printf(" [5] Cek Saldo Penjualan      \n");
	printf(" [0] Logout                   \n"); line();
	printf(" Pilih = "); scanf("%d",&n);
	switch(n){
		case 0:
			system("cls");
			Home();
			break;
		case 1:
			system("cls");
			dgame_header();
			printf("\t\t INFO AKUN \n\n");
			ptr = fopen("DGAME-Seller.dat","rb");
			while(fread(&seller, sizeof(seller), 1, ptr) == 1){
				if(strcmp(seller.username, Mseller) == 0){
					printf(" Nama Lengkap  : %s %s \n", seller.fname, seller.lname);
					printf(" Nama pengguna : %s \n", seller.username);
					printf(" Kata sandi    : %s \n", seller.password);
					printf(" Saldo         : Rp%d \n", seller.balance); line();
				}
			}
			fclose(ptr);
			system("pause"); system("cls");
			sellerMenu(Mseller);
			break;
		case 2:
			system("cls");			
			dgame_header();
			printf("\t\t UPLOAD GAME \n\n");
			ptr = fopen("DGAME-GameSeller.dat","ab");
			printf(" Banyak game yang akan di upload : "); scanf("%d", &o);
			for(i=0; i<o; i++){
				getchar();
				printf("\n %d. Nama Game   : ", i+1); gets(gameSeller.game_name);
				printf("    Harga       : "); scanf("%d", &gameSeller.game_price);
				printf("    Stok        : "); scanf("%d", &gameSeller.stock);
				strcpy(gameSeller.seller, Mseller);
				fwrite(&gameSeller, sizeof(gameSeller), 1, ptr);
			}
			fclose(ptr);
			printf("\n Game berhasil di upload.\n"); line();
			system("pause"); system("cls");
			sellerMenu(Mseller);
			break;
		case 3:
			system("cls");	
			gameSellerSort();
			dgame_header();
			printf("\t\t DAFTAR GAME \n\n");
			ptr = fopen("DGAME-GameSeller.dat","rb");
			s = 1;
			while(fread(&gameSeller, sizeof(gameSeller), 1, ptr) == 1){
				if(strcmp(gameSeller.seller, Mseller) == 0){
					printf(" %d. Nama Game : %s \n", s, gameSeller.game_name);
					printf("    Harga      : Rp%d \n", gameSeller.game_price);
					printf("    Stok       : %d \n\n", gameSeller.stock);
					s++;
				}
			}
			fclose(ptr);
			line();
			system("pause"); system("cls");
			sellerMenu(Mseller);
			break;
		case 4:
			system("cls");
			sellerConfirm(Mseller);
			break;
		case 5:
			system("cls");
			dgame_header();
			printf("\t\t SALDO PENJUALAN \n\n");
			ptr = fopen("DGAME-Seller.dat","rb");
			while(fread(&seller, sizeof(seller), 1, ptr) == 1){
				if(strcmp(seller.username, Mseller) == 0){
					printf("\t Total Saldo Penjualan : Rp%d \n", seller.balance); line();
				}
			}
			fclose(ptr);
			system("pause"); system("cls");
			sellerMenu(Mseller);
			break;
		default:
			printf("\nPilihan angka yang dimasukan salah. \n");
			system("pause"); system("cls");
			sellerMenu(Mseller);
	}
}

void sellerConfirm(char* Cseller){
	FILE *tp;
	dgame_header();
	printf("\t\t KONFIRMASI ORDERAN \n\n");
	//Melihat daftar orderan
	ptr = fopen("DGAME-Order.dat", "rb");
	s = 1;
	while(fread(&order, sizeof(order), 1, ptr) == 1){
		if(strcmp(order.seller, Cseller) == 0){
			printf(" %d. Nama Game   : %s \n", s, order.game_name);
			printf("    Jumlah      : %d \n", order.stock);
			printf("    Total Harga : Rp%d \n", order.game_price*order.stock);
			printf("    Pembeli     : %s \n\n", order.buyer);
			s++;
		}
	}
	fclose(ptr);
	line();
	// memilih orderan yang akan di konfirmasi dan menyalin ke temp
	printf(" [1] Konfirmasi orderan \n [0] Kembali \n Pilih: "); scanf("%d", &o);
	switch(o){
		case 0:
			system("cls");
			sellerMenu(Cseller);
			break;
		case 1:
			tp = fopen("Temp.dat","wb");
			ptr = fopen("DGAME-Order.dat", "rb");
			printf("\n Masukan nomor urut : "); scanf("%d", &n);
				offset_byte = (n - 1) * sizeof(order);
		    	fseek(ptr, offset_byte, SEEK_SET);
		    	if (fread(&order, sizeof(order), 1, ptr) != 0){
			        strcpy(tmp.game_name, order.game_name);
			        strcpy(tmp.seller, order.seller);
			        strcpy(tmp.buyer, order.buyer);
			        tmp.game_price = order.game_price*order.stock;
			        tmp.stock = order.stock;
			        fwrite(&tmp, sizeof(tmp), 1, tp);
			    }
			fclose(tp);
			fclose(ptr);
			// update data order
			tp = fopen("Temp.dat","rb");
			ptr = fopen("DGAME-Order.dat","rb");
			ptr2 = fopen("DGAME-Order_new.dat","wb");
			while(fread(&tmp, sizeof(tmp), 1, tp) == 1){
				while(fread(&order, sizeof(order), 1, ptr) == 1){
					if(strcmp(order.game_name, tmp.game_name) != 0 && order.stock != tmp.stock){
						fwrite(&order, sizeof(order), 1, ptr2);
					}
				}
			}
			fclose(tp);
			fclose(ptr);
			fclose(ptr2);
			remove("DGAME-Order.dat");
			rename("DGAME-Order_new.dat","DGAME-Order.dat");
			
			tp = fopen("Temp.dat","rb");
			while(fread(&tmp, sizeof(tmp), 1, tp) == 1){
				// menambahkan data ke game buyer
				ptr = fopen("DGAME-Buyer.dat","rb");
				while(fread(&buyer, sizeof(buyer), 1, ptr) == 1){
					if(strcmp(tmp.buyer, buyer.username) == 0 && (buyer.balance - tmp.game_price) >= 0){
						x = 1;
					}
				} 
				fclose(ptr);
				ptr = fopen("DGAME-GameBuyer.dat","ab");
					if(x == 1){
						strcpy(gameBuyer.game_name, tmp.game_name);
						strcpy(gameBuyer.seller, tmp.seller);
						strcpy(gameBuyer.buyer, tmp.buyer);
						gameBuyer.game_price = tmp.game_price;
						gameBuyer.stock = tmp.stock;
						fwrite(&gameBuyer, sizeof(gameBuyer), 1, ptr);
					}
				fclose(ptr);
				// update Data Game seller
				ptr = fopen("DGAME-GameSeller.dat","rb");
				ptr2 = fopen("DGAME-GameSeller_new.dat","wb");
				while(fread(&gameSeller, sizeof(gameSeller), 1, ptr) == 1){
					if(strcmp(gameSeller.game_name, tmp.game_name)==0 && x == 1){
						gameSeller.stock -= tmp.stock;
						fwrite(&gameSeller, sizeof(gameSeller), 1, ptr2);
					} else {
						fwrite(&gameSeller, sizeof(gameSeller), 1, ptr2);
					}
				}
				fclose(ptr);
				fclose(ptr2);
				remove("DGAME-GameSeller.dat");
				rename("DGAME-GameSeller_new.dat","DGAME-GameSeller.dat");
				// update Buyer 
				ptr = fopen("DGAME-Buyer.dat","rb");
				ptr2 = fopen("DGAME-Buyer_new.dat","wb");
				while(fread(&buyer, sizeof(buyer), 1, ptr) == 1){
					if(strcmp(buyer.username, tmp.buyer)==0 && x == 1){
						buyer.balance -= tmp.game_price;
						fwrite(&buyer, sizeof(buyer), 1, ptr2);
					} else {
						fwrite(&buyer, sizeof(buyer), 1, ptr2);
					}
				}
				fclose(ptr);
				fclose(ptr2);
				remove("DGAME-Buyer.dat");
				rename("DGAME-Buyer_new.dat","DGAME-Buyer.dat");
				// update seller 
				ptr = fopen("DGAME-Seller.dat","rb");
				ptr2 = fopen("DGAME-Seller_new.dat","wb");
				while(fread(&seller, sizeof(seller), 1, ptr) == 1){
					if(strcmp(seller.username, tmp.seller)==0 && x == 1){
						seller.balance += tmp.game_price;
						fwrite(&seller, sizeof(seller), 1, ptr2);
					} else {
						fwrite(&seller, sizeof(seller), 1, ptr2);
					}
				}
				fclose(ptr);
				fclose(ptr2);
				remove("DGAME-Seller.dat");
				rename("DGAME-Seller_new.dat","DGAME-Seller.dat");
			}
			fclose(tp);
			remove("Temp.dat");
			if(x == 1){
				printf("\n\n Konfirmasi Pembelian Berhasil. \n\n\n");
			} else {
				printf("\n\n Konfirmasi Pembelian Gagal. \n\n\n");
			}
			
			system("pause"); system("cls");
			sellerMenu(Cseller);
			break;
		default:
			system("pause"); system("cls");
			sellerMenu(Cseller);
	}
}
/* =============================================================================================== */
