# Data Management System Application

## Project Requirements
Develop a Data Management System allowing users to manage and track information for different entities. 
The system can be based on varied interests like Inventory Management, Patient Management, Banking, or Grade Tracking.

### Key Features:

#### 1. Entity Database 
- Implement an array data structure to store entity information, accommodating relevant attributes.

#### 2. User Interface 
- Develop a text-based, menu-driven interface for user interactions. Include options for adding, updating, deleting entities, and viewing current data.

#### 3. Data Input and Validation 
- Create functions for adding new data entities with proper input validation.

#### 4. Data Modification 
- Allow users to update information for existing entities, modifying attributes or values.

#### 5. Data Listing 
- Develop functions to list all entities, allowing users to view the entire dataset or filter by specific attributes.

#### 6. File Processing 
- Implement file processing to save and load the current state of the dataset. Utilize file I/O functions for this purpose.

#### 7. Documentation 
- Include clear code documentation to explain complex sections or key decisions.

## Submission Instructions


# Store Inventory Management System

## Overview
The Store Inventory Management System is a console-based application developed in C, designed to help manage and track inventory items for a store. 
It enables the storekeepers to perform essential inventory operations such as adding new items, updating existing item details, deleting items, and displaying all items in the inventory.

## Key Features

- **Entity Database:** Utilizes parallel arrays to store and manage item details, including item IDs, names, prices, quantities, and categories.
  
- **User Interface:** Provides a user-friendly, menu-driven interface allowing seamless interaction with the system for performing various inventory operations.
  
- **Data Input and Validation:** Includes input validation to ensure accurate and consistent data entry for item attributes.
  
- **Data Modification:** Allows users to update information about existing items, enabling modifications to item attributes such as name, price, quantity, and category.
  
- **Data Listing:** Offers the functionality to list all items in the inventory, providing a comprehensive view of the current stock.
  
- **File Processing:** Implements file I/O operations for persisting the inventory state, allowing data to be saved to and loaded from a file, ensuring data persistence across sessions.

- **Documentation:** Contains well-commented code explaining complex sections and key decisions, enhancing code readability and maintainability.

## Getting Started
To run the program, compile the C file and execute the binary. Ensure that you have a C compiler installed on your system.

## Sample Output

Below is a sample interaction with the Store Inventory Management System, demonstrating the updated menu interface and some basic operations:

```plaintext
*********************************************************
*           Store Inventory Management System           *
*********************************************************
* 1. Add Item >>                                        *
---------------------------------------------------------
* 2. Display Item Details >>                            *
---------------------------------------------------------
* 3. Update Item Details >>                             *
---------------------------------------------------------
* 4. Display All Items >>                               *
---------------------------------------------------------
* 5. Delete Item >>                                     *
---------------------------------------------------------
* 6. Exit >>                                            *
*********************************************************
>> 1

Enter item ID: 101
Enter item name: ExampleItem
Enter item price: 19.99
Enter item quantity: 100
Enter item category: Electronics

Item added successfully.
*********************************************************
```
## Source Code

The complete source code for the Store Inventory Management System can be found at the following GitHub repository:

[Store Inventory Management System Source Code](https://github.com/altmemy/c-project/blob/main/store_inventory.c)


