#include "Supermarket.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include "JiYoung.h"
#define NOMINMAX
using namespace std;

extern JiYoung ojy;

// Supermarket implentation
string Supermarket::getStoreName() { return name; }
double Supermarket::getStoreCash() { return cash; }
int Supermarket::getStoreStock() { return stock; }


void Supermarket::buyItem() { //Basic stuff might be completed. Need more testing
	
	ojy.clrscr();
	cout << name << " Shop" << endl  << endl << "Items in store" << endl << endl;
	cout << "Item Name"; ojy.setw("Item Name", 15); cout << "Price"; ojy.setw("Price", 10);
	cout << "Quantity"; cout << endl;

	for (int x = 0; x < itemInStore; x++) {
		// Print menu 
		//DO NOT CALL THE listAllStock FUNCTION, this menu is slightly differernt
		// I SAID DO NOT! 
		cout << x + 1 << ". " << item[x].getItemName();
		ojy.setw(item[x].getItemName(), 12);
		cout << "RM" << item[x].getPrice();
		ojy.setw(to_string(item[x].getPrice()), 12);
		cout << item[x].getQuantity();
		ojy.setw(to_string(item[x].getQuantity()), 12);
		if (item[x].getQuantity() == 0) {
			cout << "     NOTE - Out Of Stock!";
		}
		cout << endl;
	}
	
	cout << "Press 0 (zero) to exit.\nEnter Selection To Purchase Item: ";
	int selBuy = NULL;
	int amount = NULL; //AMOUNT VALIDATION Done, need further testing
	bool isValidItem = false;
	bool amntCheckPass = false;
	while (isValidItem == false) {
		selBuy = ojy.isValidInt();
		if (selBuy > 0 && selBuy <= itemInStore) { //buy item
			if (item[selBuy - 1].getQuantity() == 0) {
				cout << "Item out of stock! No transection is made. Please retry later" << endl;
				break;
			}
			isValidItem = true;
			do {
				cout << "Enter the amount of items wanted :";
				amount = ojy.isValidInt();
				if (amount > item[selBuy - 1].getQuantity()) {
					cout << "Shop have only " << item[selBuy - 1].getQuantity() << " item left. Please enter value lower than available quanitity." << endl;
				}
				else if (amount < 0) {
					cout << "Amount cannot be negative." << endl;
				}
				else {
					amntCheckPass = true;
				}
			} while (amntCheckPass == false);
			//after enter the amount, it needs to deduct the total quantity from the stock.txt
			cout << amount << " "<< item[selBuy - 1].getItemName() << " sold RM" << item[selBuy - 1].getPrice()*amount << endl;
			item[selBuy - 1].setQuantity(item[selBuy - 1].getQuantity() - amount);
			cash = cash + item[selBuy - 1].getPrice()*amount; 
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else if (selBuy == 0) { //Exit
			isValidItem = true; //Exit and return to menu
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else{ //Error message for invalid input
			cout << "Error 404 Item Not Found, Please Retry With a Different input: " << endl;
		}
	}//end while
}

void Supermarket::finaceReport() {//DONE
	ojy.clrscr();
	cout << name << " Financial Report" << endl << endl;
	double assetValue=0;
	for (int x = 0; x < itemInStore; x++) {
		assetValue = assetValue + (item[x].getQuantity() * item[x].getPrice());
	}
	//TODO: list store cash
	cout << "Total Stock Value: RM" << assetValue << endl;
	cout << "Available cash: RM" << cash << endl << endl;
	cout << "Total Combined Asset Value (Stock + Cash): RM" << cash + assetValue << endl;
	cout << "Press any key to return to menu";
	ojy.getch();
}

void Supermarket::stockReport() {
	ojy.clrscr();
	cout << name << " Stock Report" << endl;
	listAllStock();
	cout << "Press any key to return to menu";
	ojy.getch();
}

void Supermarket::stockMaintance() {
	ojy.clrscr();
	int selMain = NULL;
	int selEditItem = NULL;
	bool isValidItem = false;
	//After selecting the item it can choose which section to edit 
	//and from there enter the edited amount or info to replace the old data
	
	//TODO: print a menu to do - edit item or add new item or add stock - ojy
	cout << "Choose from these 2 selections" << endl;
	cout << "1. Add New Item" << endl << "2. Edit Current Stock" << endl << "3. Delete An Item" << endl;
	cout << "Press 0 to return to menu: ";
	while (isValidItem == false) {
		selMain = ojy.isValidInt();
		if (selMain == 1) { //Edit information of the items
			isValidItem = true;
			string iName, iDesc;
			int iQuan, iWeight;
			double iPrice ;
			//TODO : PRICE AND STOCK CANNOT BE LOWER THAN 0
			cout << "Enter the New Item's Name : ";
			getline(cin, iName);
			cout << "Enter the New Item's Quantity : ";
			iQuan = ojy.largerThanZeroInt();
			cout << "Enter the New Item's Price : ";
			iPrice = ojy.largerThanZeroDouble();
			cout << "Enter the New Item's Weight : ";
			iWeight = ojy.largerThanZeroInt();
			cout << "Enter the New Item's Description : ";
			getline(cin, iDesc);
			string confirmItem;
			
			confirmItem = "Are you sure you want to add the following item?\nItem Name: " + iName + "\nItem Quantity: " + to_string(iQuan) + "\nItem Price: "
				+ ojy.doubleToStrPrecis(iPrice,2) + "\nItem Weight: " + ojy.doubleToStrPrecis(iWeight,2) + "\nItem Description: " + iDesc
				+ "\nNote: This Operation Could Not Be Undo";
			
			//convert String to LPCWSTR
						
			wstring To(confirmItem.begin(), confirmItem.end());
			LPCWSTR msgConfmMsg = To.c_str();

			
			int response= MessageBox(NULL, msgConfmMsg, L"Confirmation", MB_YESNO | MB_ICONQUESTION);
			//6 is yes , 7 is no
			if (response == 6) {
				// itemInStore is new Index Val
				item[itemInStore].setItemName(iName);
				item[itemInStore].setQuantity(iQuan);
				item[itemInStore].setWeight(iWeight);
				item[itemInStore].setPrice(iPrice);
				item[itemInStore].setDescript(iDesc);
				itemInStore++;
				MessageBox(NULL, L"The Operation Completed Sucessfully", L"Information", MB_OK | MB_ICONINFORMATION);
			}
			else if(response==7){
				MessageBox(NULL, L"The Item is not added to the inventory", L"Information", MB_OK | MB_ICONEXCLAMATION);
			}
			else {
				cout << "This Wont Happen Just To Make Sure ";
			}
			
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else if (selMain == 2) {
			int selEdit;
			listAllStock();
			//Choose which specific information to edit
			cout << "Enter the number for which you wish to edit the information of the item" << endl;
			cout << "Enter 0 to return to menu: ";
			while (isValidItem == false) {
				selEdit = ojy.isValidInt();
				if (selEdit > 0 && selEdit <= itemInStore) { //edit item
					bool doneEdit = false;
					isValidItem = true;
					string iName = item[selEdit - 1].getItemName(), iDesc = item[selEdit - 1].getDescript();
					int iQuan = item[selEdit - 1].getQuantity(), iWeight = item[selEdit - 1].getWeight();
					double iPrice = item[selEdit - 1].getPrice();
					while (doneEdit == false) {
						ojy.clrscr();
						cout << "What do you want to edit?" << endl;
						cout << "1. Item Name       : " << iName << endl;
						cout << "2. Item Quantity   : " << iQuan << endl;
						cout << "3. Item Price      : " << iPrice << endl;
						cout << "4. Item Weight     : " << iWeight << endl;
						cout << "5. Item Description: " << iDesc << endl;
						cout << "Any changes will be reflected above\nPress 0 to exit edit mode: ";
						int selection;
						cin >> selection; //Input Validation
						ojy.clrBuffer();
						switch (selection)
						{
						case 1:
							cout << "Enter New Name: ";
							getline(cin, iName);
							break;
						case 2:
							cout << "Enter New Quantity: ";
							iQuan = ojy.largerThanZeroInt();
							break;
						case 3:
							cout << "Enter New Price: ";
							iPrice = ojy.largerThanZeroDouble();
							break;
						case 4:
							cout << "Enter New Weight: ";
							iWeight = ojy.largerThanZeroInt();
							break;
						case 5:
							cout << "Enter New Description" << endl;
							getline(cin, iDesc);
							break;
						case 0:
							doneEdit = true; //exit
							break;
						default:
							//cout << "Invalid Entry" << endl; -replace with popup Error Message 
							MessageBox(NULL, L"Invalid Entry\nPlease Try Again!", L"Error", MB_OK | MB_ICONERROR);
							break;
						}//end switch
						
					}//end while

					//give confirmation
					string confirmMsg = "Confirm To Commit Changes?\nPrevious Item\t\t\tEditied Item\nItem Name: " + item[selEdit - 1].getItemName() + "\t\t\t" + iName +
						"\nItem Quantity: " + to_string(item[selEdit - 1].getQuantity()) + "\t\t\t" + to_string(iQuan) + "\nItem Price: "
						+ ojy.doubleToStrPrecis(item[selEdit - 1].getPrice(), 2) + "\t\t\t" + ojy.doubleToStrPrecis(iPrice, 2) +
						"\nItem Weight: " + ojy.doubleToStrPrecis(item[selEdit - 1].getWeight(), 2) + "\t\t\t" + ojy.doubleToStrPrecis(iWeight, 2)
						+ "\nItem Description: " + item[selEdit - 1].getDescript() + "\t\t" + iDesc
						+ "\n\nNote: This Operation Could Not Be Undo";
					wstring To(confirmMsg.begin(), confirmMsg.end());
					LPCWSTR msgConfmMsg = To.c_str();
					int response = MessageBox(NULL, msgConfmMsg, L"Confirmation", MB_YESNO | MB_ICONQUESTION);
					//6 is yes , 7 is no
					if (response == 6) {
						// itemInStore is new Index Val
						item[selEdit - 1].setItemName(iName);
						item[selEdit - 1].setQuantity(iQuan);
						item[selEdit - 1].setWeight(iWeight);
						item[selEdit - 1].setPrice(iPrice);
						item[selEdit - 1].setDescript(iDesc);
						MessageBox(NULL, L"The Operation Completed Sucessfully", L"Information", MB_OK | MB_ICONINFORMATION);
					}
					else if (response == 7) {
						MessageBox(NULL, L"The Item is not edited", L"Information", MB_OK | MB_ICONEXCLAMATION);
					}
				}
				else if (selEdit == 0) { //Exit
					isValidItem = true; //Exit and return to menu
				}
				else { //Error message for invalid input
					cout << "Error 404 Item Not Found, Please Retry With a Different input: " << endl;
				}
			}//end while

			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else if (selMain == 3) {
			int selDelete;
			listAllStock();
			cout << "Enter the number for which you wish to delete the item" << endl;
			cout << "Enter 0 to return to menu: ";
			while (isValidItem == false) {
				selDelete = ojy.isValidInt();
				if (selDelete > 0 && selDelete <= itemInStore) { //edit item
					bool doneEdit = false;
					isValidItem = true;
					ojy.clrscr();
					//give confirmation
					string confirmMsg = "Confirm To Delete This Item?\nItem Name\t: " + item[selDelete - 1].getItemName()
						+ "\nItem Quantity\t: " + to_string(item[selDelete - 1].getQuantity()) + 
						  "\nItem Price \t: " + ojy.doubleToStrPrecis(item[selDelete - 1].getPrice(),2) +
						  "\nItem Weight\t: " + ojy.doubleToStrPrecis(item[selDelete - 1].getWeight(),2) + 
						  "\nItem Description\t: " + item[selDelete - 1].getDescript()
						+"\n\nNote: This item will be gone forever";
						
					wstring To(confirmMsg.begin(), confirmMsg.end());
					LPCWSTR msgConfmMsg = To.c_str();
					int response = MessageBox(NULL, msgConfmMsg, L"Confirmation", MB_YESNO | MB_ICONQUESTION);
					//6 is yes , 7 is no
					if (response == 6) {
						for (int i = selDelete-1; i < itemInStore; ++i)
							item[i] = item[i + 1];
						itemInStore--;
						MessageBox(NULL, L"The Item is deleted sucessfully, you wont be seeing this item anymore", L"Information", MB_OK | MB_ICONINFORMATION);
					}
					else if (response == 7) {
						MessageBox(NULL, L"The Item is not deleted", L"Information", MB_OK | MB_ICONEXCLAMATION);
					}
				}
				else if (selDelete == 0) { //Exit
					isValidItem = true; //Exit and return to menu
				}
				else { //Error message for invalid input
					cout << "Error 404 Item Not Found, Please Retry With a Different input: " << endl;
				}
			}//end while

			cout << "Press any key to return to Menu";
			ojy.getch();
			
		}
		else if (selMain == 0) { //exit
			isValidItem = true; //exit and return to menu
			cout << "Press any key to return to Menu";
			ojy.getch();
		}
		else { //Invalid Input Message
			cout << "Invalid Entry, Please Retry: ";
		}
	}//end while
}

void Supermarket::listAllStock() {
	cout << "Item Name"; ojy.setw("Item Name", 15); cout << "Quantity"; ojy.setw("Quantity", 12);
	cout << "Price"; ojy.setw("Price", 10); cout << "Weight"; ojy.setw("Weight", 10);
	cout << "Description" << endl;

	for (int x = 0; x < itemInStore; x++) {
		// Print menu
		cout << x + 1 << ". " << item[x].getItemName();
		ojy.setw(item[x].getItemName(), 12);
		cout << item[x].getQuantity();
		ojy.setw(to_string(item[x].getQuantity()), 12);
		cout << "RM" << item[x].getPrice();
		ojy.setw(to_string(item[x].getPrice()), 12);
		cout << item[x].getWeight() << "g";
		ojy.setw(to_string(item[x].getWeight()), 9);
		cout << item[x].getDescript();
		ojy.setw(item[x].getDescript(), 10);
		if (item[x].getQuantity() == 0) {
			cout << " NOTE - This item is out of stock!";
		}
		cout << endl;
	}
}

void Supermarket::errormsg() {
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);//Make Full screen
	system("color 9F");
	//DONT ASK ME TO EXPLAIN THIS -- I only know its works to change font
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtain the Console handle
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX); // set the size of the CONSOLE_FONT_INFOEX
	GetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx); // get the current value
																  // set size to be 8x18, the default size is 8x16
	lpConsoleCurrentFontEx->dwFontSize.X = 8;
	lpConsoleCurrentFontEx->dwFontSize.Y = 22;

	SetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx);// submit the settings
																 //change font size
	cout << "\nA problem has been detected and this program has been shut down to prevent damage to your computer.\n"
		<< "\nFILE_IRQL_NOT_FOUND_OR_MISSING"
		<< "\n\nIf this is the first time you've seen this error screen,\nrestart your computer. If this screen appears again, follow\nthese steps:"
		<< "\n\nCheck to be sure you have the \"Stock.txt\" file in the same directory. \nIf the file is located in the same directory,\ndisable the Read-Only mode.\nTry to delete and recreate \"Stock.txt\" file. "
		<< "\n\nIf problems continue, disable or remove any newly installed source code.\nIf you need to use Safe Mode to remove or disable components, restart\nyour computer, press F8 to select Advanced Startup options, and then\nselect Safe Mode.";
	cout << "\n\nTechnical Information:\n\n ***STOP: 0x034404404 (0x0404F403, 0x0E340400, 0x00000404)\n\n\n";
	cout << "Press any key to exit the program as this program cannot be continue";
}

Supermarket::Supermarket() {
	name = "NULL";
	cash = NULL;
	stock = NULL;
	cout << "Please Wait.... Loading Data" << endl;
	ifstream fileIn;
	fileIn.open("Stock.txt");
	if (fileIn.is_open()) {
		//TODO : Need to seperate the string and put into correct var =.= 
		string line;
		//First Line
		getline(fileIn, line, ':');//read name
		name = line;
		getline(fileIn, line, ':');//number of different items stocked 
		stock = stoi(line);
		getline(fileIn, line, ':');//cash on hand
		cash = stod(line);

		//end of first line

		int x = 0; //array need x 
		try
		{
			while (!fileIn.eof()) { //Stock array - read until EOF
				getline(fileIn, line, '\n'); //eat newline
				getline(fileIn, line, ':'); //itemname
				item[x].setItemName(line);
				getline(fileIn, line, ':'); //number
				item[x].setQuantity(stoi(line));
				getline(fileIn, line, ':'); //unit price
				item[x].setPrice(stod(line));
				getline(fileIn, line, ':');//unit weight
				item[x].setWeight(stoi(line));
				getline(fileIn, line, ':');//unit descp
				item[x].setDescript(line);
				//cout << item[x].getItemName(); //TODO: remove after done
				//cout << item[x].getPrice() << item[x].getQuantity() << item[x].getWeight() << item[x].getDescript() <<endl;
				x++;
			}
			itemInStore = x;
		}
		catch (const std::exception &exc)
		{
			string buffer;
			buffer = exc.what();
			string errormsg = "Something wrong with \"Stock.txt\" file!\n Error Code: " + buffer;
			wstring To(errormsg.begin(), errormsg.end());
			LPCWSTR finalErrMsg = To.c_str();
			MessageBox(NULL, finalErrMsg , L"Error", MB_OK | MB_ICONERROR); //make sure last EOF dont have the ':'
		}

	}
	else 
	{
		//error message - MUST BE TERMINATED
		MessageBox(NULL, L"Unable to read or open file.\n Please make sure \"Stock.txt\" is accessible and in the same directory", L"Error", MB_OK | MB_ICONERROR);
		errormsg();
		ojy.getch();
		exit(1);
	}
	fileIn.close();
	string title = "title " + name + " Sales System";
	system(title.c_str());
}
//TODO: SAVE STOCK TO STOCK.TXT
Supermarket::~Supermarket(){
	ojy.clrscr();
	cout << "Saving Data... Please Wait" << endl;
	ofstream fileOut;
	fileOut.open("Stock.txt");
	if (fileOut.is_open()) {
		fileOut << fixed << showpoint << setprecision(2);
		//Save to txt
		string line;
		//First Line
		fileOut << name << ":" << stock << ":" << cash << ":" << endl;
		int x = 0;
		while (x < itemInStore) {
			fileOut << item[x].getItemName() << ":" << item[x].getQuantity() << ":" << item[x].getPrice() << ":" << item[x].getWeight() << ":" << item[x].getDescript();
			if (x < itemInStore - 1)
				fileOut << ":" << endl;
			x++;
		}
	}
	else {
		MessageBox(NULL, L"Exception opening/reading file. File might be locked or inused.", L"Error", MB_OK | MB_ICONERROR);
		errormsg();
	}

} //destructor