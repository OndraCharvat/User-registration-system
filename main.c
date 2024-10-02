#include <stdio.h>
#include <string.h>

typedef struct {
    char firstName[50];
    char lastName[50];
    char email[100];
} User;

void addUser(User users[], int *userCount);

void removeUser(User users[], int *userCount);

void listUsers(User users[], int userCount);

void showMenu();

int main() {
    User users[30];
    int userCount = 0;
    int choice;

    for (;;) {
        showMenu();
        printf("Vyberte možnost: ");
        scanf("%d", &choice);
        getchar(); // Odstranění nového řádku ze vstupu

        if (choice == 1) {
            addUser(users, &userCount);
        } else if (choice == 2) {
            removeUser(users, &userCount);
        } else if (choice == 3) {
            listUsers(users, userCount);
        } else if (choice == 4) {
            printf("Konec programu \n");
            break;
        } else {
            printf("Neplatná možnost\n");
        }
    }

    return 0;
}


void addUser(User users[], int *userCount) {
    if (*userCount >= 30) {
        printf("Pole je plné \n");
        return;
    }

    User newUser;

    printf("Zadejte jméno: ");
    fgets(newUser.firstName, 50, stdin);
    newUser.firstName[strcspn(newUser.firstName, "\n")] = 0;
    printf("Zadejte příjmení: ");
    fgets(newUser.lastName, 50, stdin);
    newUser.lastName[strcspn(newUser.lastName, "\n")] = 0;

    printf("Zadejte e-mail: ");
    fgets(newUser.email, 100, stdin);
    newUser.email[strcspn(newUser.email, "\n")] = 0;

    users[*userCount] = newUser;
    (*userCount)++;
    printf("Uživatel přidán \n");
}

void removeUser(User users[], int *userCount) {
    if (*userCount == 0) {
        printf("žádní uživatelé \n");
        return;
    }

    int index;
    printf("Zadejte číslo uživatele, kterého chcete odebrat ");
    scanf("%d", &index);
    getchar();

    if (index < 0 || index >= *userCount) {
        printf("Neplatný uživatel \n");
        return;
    }

    for (int i = index; i < *userCount - 1; i++) {
        users[i] = users[i + 1];
    }
    (*userCount)--;
    printf("Uživatel odebrán \n");
}

void listUsers(User users[], int userCount) {
    if (userCount == 0) {
        printf("Žádní uživatelé \n");
        return;
    }

    printf("Seznam uživatelů:\n");
    for (int i = 0; i < userCount; i++) {
        printf("%d %s %s %s\n", i, users[i].firstName, users[i].lastName, users[i].email);
    }
}

void showMenu() {
    printf("1. Přidat uživatele\n");
    printf("2. Odebrat uživatele\n");
    printf("3. Vypsat uživatele\n");
    printf("4. Konec\n");
}
