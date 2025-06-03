#include "menu.h"

void displayMenu() {
    clearScreen();
    printf("\n=== MENU UTAMA ===\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal LevelOrder\n");
    printf("5. Print All Binary Tree\n");
    printf("6. Search Node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level Node Tree\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Konversi String to Morse\n");
    printf("11. Konversi Morse to String\n");
    printf("12. Konversi File Text ke Morse\n");
    printf("0. Keluar\n");
    printf("Pilihan: ");
}

void binTreeLobby(BinTree T) {
    int choice;
    char input[256];
    char morseInput[256];

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Membersihkan newline
        
        switch(choice) {
            case 1:
                clearScreen();
                printf("PreOrder Traversal: ");
                PreOrder(T);
                printf("\n");

                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar(); 
                break;
                
            case 2:
                clearScreen();
                printf("InOrder Traversal: ");
                InOrder(T);
                printf("\n");

                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar();
                break;
                
            case 3:
                clearScreen();
                printf("PostOrder Traversal: ");
                PostOrder(T);
                printf("\n");

                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar(); 
                break;
                
            case 4:
                clearScreen();
                printf("LevelOrder Traversal: ");
                LevelOrder(T);
                printf("\n");

                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar(); 
                break;
                
            case 5:
                clearScreen();
                printf("Struktur Pohon Morse:\n");
                PrintTree(T, 0);

                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar(); 
                break;
                
            case 6: {
                clearScreen();
                printf("Masukkan karakter yang ingin dicari: ");
                char c;
                scanf("%c", &c);
                if (Search(T, c))
                    printf("Karakter '%c' ditemukan dalam pohon.\n", c);
                else
                    printf("Karakter '%c' tidak ditemukan dalam pohon.\n", c);

                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar(); getchar();
                break;
            }
                
            case 7:
                clearScreen();
                printf("Jumlah daun dalam pohon: %d\n", CountLeaves(T));

                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar(); 
                break;
                
            case 8: 
                clearScreen();
                printf("Masukkan karakter yang ingin dicari levelnya: ");
                char c;
                scanf("%c", &c);
                int level = NodeLevel(T, c, 0);
                if (level > 0)
                    printf("\nLevel dari '%c' adalah %d\n", c, level-1);
                else
                    printf("Karakter '%c' tidak ditemukan dalam pohon.\n", c);
                
                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar(); getchar();
                break;
                
            case 9:
                clearScreen();
                printf("Kedalaman pohon: %d\n", TreeDepth(T)-1);

                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar(); 
                break;
                
            case 10:
                clearScreen();
                printf("Masukkan string yang akan dikonversi (contoh: JTK): ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                printf("Kode Morse: ");
                StringToMorse(T, input);

                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar(); 
                break;
                
            case 11:
                clearScreen();
                printf("Masukkan kode morse yang akan dikonversi (contoh: <>>> <<<> <<>>): ");
                fgets(morseInput, sizeof(morseInput), stdin);
                morseInput[strcspn(morseInput, "\n")] = '\0';
                printf("Hasil konversi: ");
                MorseToString(T, morseInput);

                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar(); 
                break;
                
            case 12:
                clearScreen();
                printf("Konversi file input.txt ke output.txt\n");
                FileToMorse(T, "input.txt", "output.txt");

                printf("\nPress ENTER untuk melanjutkan!\n");
                getchar();
                break;
                
            case 0:
                printf("Keluar dari program.\n");
                break;
                
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 0);
}

void clearScreen() {
    system("cls");
}