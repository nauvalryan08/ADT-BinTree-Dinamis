#include "bintree.h"

/***************************/
/*  S P E S I F I K A S I  */
/***************************/

// Fungsi bantu untuk membuat node baru
address createNode(infotype info) {
    address newNode = (address)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->info = info;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void createMorseTree(BinTree *T) {
    // Buat root node
    *T = createNode(' ');
    if (*T == NULL) return;  // Handle allocation failure
    
    // Level 1
    (*T)->left = createNode('A');   // A = <
    (*T)->right = createNode('B');  // B = >
    
    // Level 2
    (*T)->left->left = createNode('C');    // C = <<
    (*T)->left->right = createNode('D');   // D = <>
    
    (*T)->right->left = createNode('E');   // E = ><
    (*T)->right->right = createNode('F');  // F = >>
    
    // Level 3
    (*T)->left->left->left = createNode('G');    // G = <<<
    (*T)->left->left->right = createNode('H');   // H = <<>
    
    (*T)->left->right->left = createNode('I');   // I = <><
    (*T)->left->right->right = createNode('J');  // J = <>>
    
    (*T)->right->left->left = createNode('K');   // K = ><<
    (*T)->right->left->right = createNode('L');  // L = ><>
    
    (*T)->right->right->left = createNode('M');  // M = >><
    (*T)->right->right->right = createNode('N'); // N = >>>
    
    // Level 4
    (*T)->left->left->left->left = createNode('O');    // O = <<<<
    (*T)->left->left->left->right = createNode('P');   // P = <<<>
    
    (*T)->left->left->right->left = createNode('Q');   // Q = <<><
    (*T)->left->left->right->right = createNode('R');  // R = <<>>
    
    (*T)->left->right->left->left = createNode('S');   // S = <><<
    (*T)->left->right->left->right = createNode('T');  // T = <><>
    
    (*T)->left->right->right->left = createNode('U');  // U = <>><
    (*T)->left->right->right->right = createNode('V'); // V = <>>>
    
    (*T)->right->left->left->left = createNode('W');   // W = ><<<
    (*T)->right->left->left->right = createNode('X');  // X = ><<>
    
    (*T)->right->left->right->left = createNode('Y');  // Y = ><><
    (*T)->right->left->right->right = createNode('Z'); // Z = ><>>
    
    (*T)->right->right->left->left = createNode('0');  // 0 = >><<
    (*T)->right->right->left->right = createNode('1'); // 1 = >><>
    
    (*T)->right->right->right->left = createNode('2'); // 2 = >>><
    (*T)->right->right->right->right = createNode('3');// 3 = >>>>
    
    // Level 5 - For numbers and special characters
    (*T)->left->left->left->left->right = createNode('4');  // 4 = <<<<>
    (*T)->left->left->left->right->right = createNode('5'); // 5 = <<<>>
    
    (*T)->left->right->left->left->left = createNode('6');  // 6 = <><<<
    (*T)->left->right->left->left->right = createNode('7'); // 7 = <>><<
    
    (*T)->left->right->right->right->left = createNode('8'); // 8 = <>>><
    (*T)->right->left->left->left->left = createNode('9');   // 9 = ><<<<
    
    // Special characters
    (*T)->right->right->left->left->right = createNode('-'); // - = >><><
    (*T)->right->right->right->left->left = createNode('?'); // ? = >>><<
    (*T)->right->right->right->right->left = createNode('!'); // ! = >>>><
    (*T)->right->right->right->right->right = createNode(','); // , = >>>>>
}

boolean isEmpty(BinTree T) {
	return (T == nil);
}

/***************************/
/*        TRAVERSAL        */
/***************************/
void PreOrder(BinTree T) {
	if (!isEmpty(T)) {
        printf("%c - ", T->info);
        PostOrder(T->left);
        PostOrder(T->right);
    }
}

void InOrder(BinTree T) {
	if (!isEmpty(T)) {
        PostOrder(T->left);
        printf("%c - ", T->info);
        PostOrder(T->right);
    }
}

void PostOrder(BinTree T) {
	if (!isEmpty(T)) {
        PostOrder(T->left);
        PostOrder(T->right);
        printf("%c - ", T->info);
    }
}

void LevelOrder(BinTree T) {
	if (isEmpty(T)) return;
    
    BinTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    
    while (front < rear) {
        BinTree current = queue[front++];
        printf("%c ", current->info);
        
        if (current->left != nil)
            queue[rear++] = current->left;
        if (current->right != nil)
            queue[rear++] = current->right;
    }
}

/***************************/
/*       FUNGSI LAIN       */
/***************************/
void PrintTree(BinTree T, int depth) {
    if (isEmpty(T)) {
        printf("Tree kosong!\n");
        return;
    }

    // Cetak root terlebih dahulu
    printf("%c\n", T->info);
    
    // Cetak subtree kiri dan kanan
    printRecursive(T->left, 1);
    printRecursive(T->right, 1);
}

// Implementasi fungsi rekursif helper
static void printRecursive(BinTree node, int level) {
    if (node == NULL) return;
    
    // Cetak indentasi
    for (int i = 0; i < level; i++) {
        if (i == level - 1) {
            printf("|--> ");
        } else {
            printf("|    ");
        }
    }
    
    // Cetak informasi node
    printf("%c\n", node->info);
    
    // Rekursi ke anak kiri dan kanan
    printRecursive(node->left, level + 1);
    printRecursive(node->right, level + 1);
}

boolean Search(BinTree T, infotype X) {
	if (isEmpty(T)) {
        return false;
    }

    if (toupper(T->info) == toupper(X)) {
        return true;
    }

    return Search(T->left, X) || Search(T->right, X);
}

int CountLeaves(BinTree T){
	if (isEmpty(T)) {
        return 0;
    }

    if (T->left == nil && T->right == nil) {
        return 1;
    }

    int LeavesCounted = CountLeaves(T->left) + CountLeaves(T->right);
    return LeavesCounted;
}

int NodeLevel(BinTree T, infotype X, int level) {
	if (isEmpty(T)) {
        return 0;
    }

    if (toupper(T->info) == toupper(X)) {
        return level;
    }

    int downLevel = NodeLevel(T->left, X, level+1);
    if (downLevel != 0) {
        return downLevel;
    }

    int lowerLevel = NodeLevel(T->right, X, level+1);
    return lowerLevel;
}

int TreeDepth(BinTree T) {
	if (isEmpty(T)) {
        return 0;
    } 

    int leftDepth = TreeDepth(T->left);
    int rightDepth = TreeDepth(T->right);

    int depthResult = (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);    
    return depthResult;
} 

/***************************/
/*      KONVERSI MORSE     */
/***************************/
void FindMorseCode(BinTree T, char c, char *path, int level, char *result) {
    if (T == nil) return;
    
    if (toupper(T->info) == toupper(c)) {
        path[level] = '\0';
        strcpy(result, path);
        return;
    }
    
    path[level] = '<'; // Representasi untuk titik (.)
    FindMorseCode(T->left, c, path, level + 1, result);
    
    path[level] = '>'; // Representasi untuk strip (-)
    FindMorseCode(T->right, c, path, level + 1, result);
}

void StringToMorse(BinTree T, char *str) {
	int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            printf("  "); // 2 spasi untuk pemisah kata
            continue;
        }
        
        char path[morseMaxLength];
        char result[morseMaxLength] = "";
        FindMorseCode(T, str[i], path, 0, result);
        
        if (strlen(result) > 0) {
            printf("%s", result);
            if (i < len - 1 && str[i+1] != ' ') 
                printf("."); // 1 titik untuk pemisah huruf
        }
    }
    printf("\n");
}

void MorseToChar(BinTree T, char *morse, char *result) {
    BinTree current = T;
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == '<') { // Titik (.)
            current = current->left;
        } else if (morse[i] == '>') { // Strip (-)
            current = current->right;
        }
        
        if (current == nil) {
            *result = '?';
            return;
        }
    }
    *result = current->info;
}

void MorseToString(BinTree T, char *morseCode) {
	char *token = strtok(morseCode, " ");
    while (token != NULL) {
        if (strcmp(token, " ") == 0) {
            printf(" ");
        } else {
            char result;
            MorseToChar(T, token, &result);
            printf("%c", result);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

void FileToMorse(BinTree T, char *inputFile, char *outputFile) {
	FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");
    
    if (in == NULL || out == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), in)) {
        int len = strlen(line);
        if (line[len-1] == '\n') line[len-1] = '\0';
        
        for (int i = 0; i < len; i++) {
            if (line[i] == ' ') {
                fprintf(out, "  ");
                continue;
            }
            
            char path[morseMaxLength];
            char result[morseMaxLength] = "";
            FindMorseCode(T, line[i], path, 0, result);
            
            if (strlen(result) > 0) {
                fprintf(out, "%s", result);
                if (i < len - 1 && line[i+1] != ' ' && line[i+1] != '\n') 
                    fprintf(out, " ");
            }
        }
        fprintf(out, "\n");
    }
    
    fclose(in);
    fclose(out);
    printf("Konversi berhasil disimpan di %s\n", outputFile);
}
