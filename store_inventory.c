#include <stdio.h>
#include <string.h>

#define INVENTORY_FILE "store_inventory.txt"
#define MAX_ITEMS 200

int itemIDs[MAX_ITEMS];
char itemNames[MAX_ITEMS][100];
float itemPrices[MAX_ITEMS];
int itemQuantities[MAX_ITEMS];
char categories[MAX_ITEMS][50];
int itemCount = 0;

void LoadStoreInventory() {
    FILE *file = fopen(INVENTORY_FILE, "r");
    if (!file) {
        return;
    }
    while (fscanf(file, "%d,%[^,],%f,%d,%s\n",
                  &itemIDs[itemCount],
                  itemNames[itemCount],
                  &itemPrices[itemCount],
                  &itemQuantities[itemCount],
                  categories[itemCount]) != EOF) {
        itemCount++;
    }
    fclose(file);
}

void SaveStoreInventory() {
    FILE *file = fopen(INVENTORY_FILE, "w");
    if (!file) {
        printf("Failed to save inventory.\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d,%s,%.2f,%d,%s\n",
                itemIDs[i],
                itemNames[i],
                itemPrices[i],
                itemQuantities[i],
                categories[i]);
    }
    fclose(file);
}

void AddItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    printf("Enter item ID: ");
    if (scanf("%d", &itemIDs[itemCount]) != 1) {
        printf("Invalid input for item ID.\n");
        return; // Return early if the input is not an integer.
    }

    printf("Enter item name: ");
    if (scanf("%99s", itemNames[itemCount]) != 1) {
        printf("Invalid input for item name.\n");
        return; // Return early if the input is not valid.
    }

    printf("Enter item price: ");
    if (scanf("%f", &itemPrices[itemCount]) != 1) {
        printf("Invalid input for item price.\n");
        return; // Return early if the input is not a float.
    }

    printf("Enter item quantity: ");
    if (scanf("%d", &itemQuantities[itemCount]) != 1) {
        printf("Invalid input for item quantity.\n");
        return; // Return early if the input is not an integer.
    }

    printf("Enter item category: ");
    if (scanf("%49s", categories[itemCount]) != 1) {
        printf("Invalid input for item category.\n");
        return; // Return early if the input is not valid.
    }

    itemCount++;
    printf("Item added successfully.\n");
}

void DisplayAllItems() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    printf("ID\tName\tPrice\tQuantity\tCategory\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t%.2f\t%d\t%s\n",
               itemIDs[i], itemNames[i], itemPrices[i], itemQuantities[i], categories[i]);
    }
}

int FindItemIndexById(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (itemIDs[i] == id) {
            return i;
        }
    }
    return -1;
}

void UpdateItemDetails(int *id) {
    int index = FindItemIndexById(*id);
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    printf("Enter new item name: ");
    if (scanf("%99s", itemNames[index]) != 1) {
        printf("Invalid input for item name.\n");
        return; // Return early if the input is not valid.
    }

    printf("Enter new price: ");
    if (scanf("%f", &itemPrices[index]) != 1) {
        printf("Invalid input for item price.\n");
        return; // Return early if the input is not a float.
    }

    printf("Enter new quantity: ");
    if (scanf("%d", &itemQuantities[index]) != 1) {
        printf("Invalid input for item quantity.\n");
        return; // Return early if the input is not an integer.
    }

    printf("Enter new category: ");
    if (scanf("%49s", categories[index]) != 1) {
        printf("Invalid input for item category.\n");
        return; // Return early if the input is not valid.
    }

    printf("Item updated successfully.\n");
}

void DisplayItemDetails(int *id) {
    int index = FindItemIndexById(*id);
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    printf("ID\tName\tPrice\tQuantity\tCategory\n");
    printf("%d\t%s\t%.2f\t%d\t%s\n",
           itemIDs[index], itemNames[index], itemPrices[index], itemQuantities[index], categories[index]);
}

void DeleteItem(int *id) {
    int index = FindItemIndexById(*id);
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    for (int i = index; i < itemCount - 1; i++) {
        itemIDs[i] = itemIDs[i + 1];
        strcpy(itemNames[i], itemNames[i + 1]);
        itemPrices[i] = itemPrices[i + 1];
        itemQuantities[i] = itemQuantities[i + 1];
        strcpy(categories[i], categories[i + 1]);
    }
    itemCount--;

    printf("Item deleted successfully.\n");
}

int main() {
    LoadStoreInventory();
    int choice, id;

    while (1) {
        printf("\n*********************************************************\n");
        printf("*           Store Inventory Management System           *\n");
        printf("*********************************************************\n");
        printf("* 1. Add Item >>                                        *\n");
        printf("---------------------------------------------------------\n");
        printf("* 2. Display Item Details >>                            *\n");
        printf("---------------------------------------------------------\n");
        printf("* 3. Update Item Details >>                             *\n");
        printf("---------------------------------------------------------\n");
        printf("* 4. Display All Items >>                               *\n");
        printf("---------------------------------------------------------\n");
        printf("* 5. Delete Item >>                                     *\n");
        printf("---------------------------------------------------------\n");
        printf("* 6. Exit >>                                            *\n");
        printf("*********************************************************\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddItem();
                SaveStoreInventory();
                break;
            case 2:
                printf("\nEnter item ID to search: ");
                scanf("%d", &id);
                DisplayItemDetails(&id);
                break;
            case 3:
                printf("\nEnter item ID to update: ");
                scanf("%d", &id);
                UpdateItemDetails(&id);
                SaveStoreInventory();
                break;
            case 4:
                DisplayAllItems();
                break;
            case 5:
                printf("\nEnter item ID to delete: ");
                scanf("%d", &id);
                DeleteItem(&id);
                SaveStoreInventory();
                break;
            case 6:
                printf("\nExiting the system. Thank you for using our service.\n");
                return 0;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}
