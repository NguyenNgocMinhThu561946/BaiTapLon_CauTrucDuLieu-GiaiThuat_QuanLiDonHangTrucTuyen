#include <iostream>
#include <string>

#include "OrderManager.h"
#include "InputUtils.h"

using namespace std;

// ===== KHAI BAO MENU =====

void displayMainMenu();
void displayCRUDMenu();
void displayProcessingMenu();
void displaySearchMenu();
void displayStatisticsMenu();

void CRUDMenu(OrderManager& manager);
void ProcessingMenu(OrderManager& manager);
void SearchMenu(OrderManager& manager);
void StatisticsMenu(OrderManager& manager);

// ===== MAIN =====

int main()
{
    OrderManager manager;
    int choice;

    do
    {
        displayMainMenu();
        choice = inputInt("Nhap lua chon: ");

        switch (choice)
        {
            case 1:
                CRUDMenu(manager);
                break;

            case 2:
                ProcessingMenu(manager);
                break;

            case 3:
                SearchMenu(manager);
                break;

            case 4:
                StatisticsMenu(manager);
                break;

            case 0:
                cout << "Thoat chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}

// ===== MENU CHINH =====

void displayMainMenu()
{
    cout << "\n";
    cout << "====================================\n";
    cout << "     LOGISTICS ORDER MANAGEMENT\n";
    cout << "====================================\n";
    cout << "1. Order Management (CRUD)\n";
    cout << "2. Order Processing\n";
    cout << "3. Order Search\n";
    cout << "4. Order Statistics\n";
    cout << "0. Exit\n";
    cout << "====================================\n";
}

// ===== MENU CRUD =====

void displayCRUDMenu()
{
    cout << "\n";
    cout << "========== ORDER MANAGEMENT ==========\n";
    cout << "1. Add new order\n";
    cout << "2. Delete order\n";
    cout << "3. Find order by ID\n";
    cout << "4. Display all orders\n";
    cout << "0. Back\n";
    cout << "==================================\n";
}

void CRUDMenu(OrderManager& manager)
{
    int choice;
    string id;

    do
    {
        displayCRUDMenu();
        choice = inputInt("Nhap lua chon: ");

        switch (choice)
        {
            case 1:
                cout << "Chuc nang them don hang se duoc ket noi "
                     << "voi module OrderCRUD.\n";
                break;

            case 2:
                id = inputString("Nhap ma don hang can xoa: ");

                if (manager.deleteOrder(id))
                    cout << "Xoa don hang thanh cong!\n";
                else
                    cout << "Khong tim thay don hang!\n";
                break;

            case 3:
                id = inputString("Nhap ma don hang can tim: ");
                manager.displayOrder(id);
                break;

            case 4:
                manager.displayAllOrders();
                break;

            case 0:
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}

// ===== MENU PROCESSING =====

void displayProcessingMenu()
{
    cout << "\n";
    cout << "========== ORDER PROCESSING =========\n";
    cout << "1. Process next order\n";
    cout << "2. Approve order\n";
    cout << "3. Cancel order\n";
    cout << "4. Complete order\n";
    cout << "0. Back\n";
    cout << "==================================\n";
}

void ProcessingMenu(OrderManager& manager)
{
    int choice;
    string id;

    do
    {
        displayProcessingMenu();
        choice = inputInt("Nhap lua chon: ");

        switch (choice)
        {
            case 1:
                manager.processNext();
                break;

            case 2:
                id = inputString("Nhap ma don hang can phe duyet: ");

                if (manager.approveOrder(id))
                    cout << "Phe duyet don hang thanh cong!\n";
                else
                    cout << "Khong the phe duyet don hang!\n";
                break;

            case 3:
                id = inputString("Nhap ma don hang can huy: ");

                if (manager.cancelOrder(id))
                    cout << "Huy don hang thanh cong!\n";
                else
                    cout << "Khong the huy don hang!\n";
                break;

            case 4:
                id = inputString("Nhap ma don hang can hoan thanh: ");

                if (manager.completeOrder(id))
                    cout << "Hoan thanh don hang thanh cong!\n";
                else
                    cout << "Khong the hoan thanh don hang!\n";
                break;

            case 0:
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}

// ===== MENU SEARCH =====

void displaySearchMenu()
{
    cout << "\n";
    cout << "============= ORDER SEARCH ==========\n";
    cout << "1. Search orders by date\n";
    cout << "2. Search orders by status\n";
    cout << "0. Back\n";
    cout << "==================================\n";
}

void SearchMenu(OrderManager& manager)
{
    int choice;
    string date;
    int status;

    do
    {
        displaySearchMenu();
        choice = inputInt("Nhap lua chon: ");

        switch (choice)
        {
            case 1:
                date = inputString("Nhap ngay (dd/mm/yyyy): ");
                manager.displayByDate(date);
                break;

            case 2:
                cout << "\n===== ORDER STATUS =====\n";
                cout << "0. Cho phe duyet\n";
                cout << "1. Da duyet\n";
                cout << "2. Huy\n";
                cout << "3. Hoan thanh\n";

                status = inputInt("Nhap trang thai: ");

                if (status >= 0 && status <= 3)
                {
                    manager.displayByStatus((Status)status);
                }
                else
                {
                    cout << "Trang thai khong hop le!\n";
                }
                break;

            case 0:
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}

// ===== MENU STATISTICS =====

void displayStatisticsMenu()
{
    cout << "\n";
    cout << "========== ORDER STATISTICS ========\n";
    cout << "1. View statistics\n";
    cout << "0. Back\n";
    cout << "=================================\n";
}

void StatisticsMenu(OrderManager& manager)
{
    int choice;

    do
    {
        displayStatisticsMenu();
        choice = inputInt("Nhap lua chon: ");

        switch (choice)
        {
            case 1:
                manager.getStatistics();
                break;

            case 0:
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}
