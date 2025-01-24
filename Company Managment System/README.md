# Company Management System

## Description
This program is designed to create and maintain a Company Management System to keep track of employees in a company. It provides functionalities for adding, searching, modifying, deleting, and organizing employee information, ensuring efficient management of employee data.

---

## Features
The program offers the following features:
1. **Add New Employee**: Input details like ID, last name, first name, salary, date of birth (dd/mm/yyyy), address, phone number, and email.
2. **Save Changes**: Save all modifications to the file.
3. **Search Employee**: Search for employees by their last name.
4. **Delete Employee**: Remove an employee by entering their first and last name.
5. **Modify Employee Information**: Edit employee details using their unique ID.
6. **Print Sorted Employee List**: Sort and display employees by last name, salary, or date of birth.
7. **Exit Program**: Exit the system with a warning if unsaved changes exist.

---

## Getting Started

### Prerequisites
- A C compiler (e.g., GCC).
- Basic knowledge of running C programs.

### Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/yasserM2001/Company-Management-System.git
   ```
2. Navigate to the project directory:
   ```bash
   cd "Company Management System"
   ```
3. Compile the program:
   ```bash
   gcc main.c -o company_management
   ```

4. Run the program:
   ```bash
   ./company_management
   ```

---

## User Manual

After running the program, the following options are available:

### 1. Add New Employee
- Enter `1`.
- Input the employee details:
  - ID
  - Last Name
  - First Name
  - Salary
  - Date (dd/mm/yyyy)
  - Address
  - Phone Number
  - Email
- After finishing, you can add another employee or perform other actions.

### 2. Save Changes
- Enter `2` to save all changes made to the employee records.

### 3. Search for an Employee
- Enter `3`.
- Input the last name of the employee.
- All employees with the specified last name will be displayed with details.

### 4. Delete an Employee
- Enter `4`.
- Input the first name and last name of the employee.
- The employee with the matching name will be deleted from the file.

### 5. Modify Employee Information
- Enter `5`.
- Input the ID of the employee to modify.
- Edit any of the following details:
  - Last Name
  - First Name
  - Salary
  - Date (dd/mm/yyyy)
  - Address
  - Phone Number
  - Email
- Enter `0` to finish modifying.

### 6. Print Sorted Employee List
- Enter `6`.
- Choose the sorting criteria:
  - Last Name
  - Salary
  - Date of Birth

### 7. Exit
- Enter `0`.
- The program will notify you if there are unsaved changes before exiting.

---

## File Structure
- `main.c`: The source code for the program.
- `Company.txt`: A file storing employee data.
- `test.txt`: A test file (optional, can be removed if not necessary).

---

