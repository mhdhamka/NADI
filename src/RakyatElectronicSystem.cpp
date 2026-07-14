#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cctype>
using namespace std;

struct Receipt
{
	int ReceiptNo;
	string ModelType;
	float Price;
	int Quantity;
	float SubtotalPrice;
	Receipt *next;
};

void PresetReceipt(struct Receipt *top, int ReceiptCounter, int ItemCounter);
int MainMenu(int OptionMenu);
int OrderMenu(int OptionOrder, int EmptyReceipt);
void AddItem(struct Receipt *top, int ReceiptCounter, int ItemCounter);
void EditItem(struct Receipt *top, int ReceiptCounter, int ItemCounter);
void DeleteItem(struct Receipt **top, int ReceiptCounter, int ItemCounter);
void ViewReceipt(struct Receipt *top, int ReceiptCounter, int ItemCounter);
void ViewSelectedReceipt(struct Receipt *top, int ReceiptCounter, int ItemCounter);
void ViewSummary(struct Receipt *top, int ReceiptCounter);

int MainMenu(int OptionMenu)
{
	int WrongInput;

	do
	{
		system("cls");
		cout << "\n      Rakyat Electronics Sales Tracker\n"
			 << "                 Main Menu\n\n"
			 << "                 Option:\n"
			 << "          1. Make an order.\n"
			 << "          2. View selected receipt.\n"
			 << "          3. View daily sales summary.\n"
			 << "          4. Exit.\n"
			 << "\nPlease enter an option: "; //User prompt to enter input for the main menu
		cin >> OptionMenu;
		fflush(stdin);
		if (OptionMenu < 1 || OptionMenu > 4)
		{
			MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
			WrongInput = 1;
			cin.clear();
		}
		else if (cin.fail())
	    {
	        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
	        WrongInput = 1;
	        cin.clear();
	    }
	    else
	    {
	    	WrongInput = 0; //To exit do-while loop condition (line 885)
	    	return OptionMenu;
		}
	}while(WrongInput == 1);
}

int OrderMenu(int OptionOrder, int EmptyReceipt)
{
	int WrongInput;

	do
	{
		system("cls");
		cout << "\n               Category:\n"
			 << "            a. Mobile Phones\n"
			 << "            b. Computer & Desktops\n"
			 << "            c. Home Entertainment\n"
			 << "            d. Kitchen Appliances\n"
			 << "            e. Health & Beauty\n"
			 << "\nAny items in categories above can be added.\n"
			 << "\n   Option:\n"
			 << "1. Add item details.\n"
			 << "2. Edit item details.\n"
			 << "3. Delete selected item.\n"
			 << "4. View receipt.\n";
			 if (EmptyReceipt == 1)
			 {
			 	cout << "5. Return to main menu.\n";
			 }
			 else if (EmptyReceipt == 0)
			 {
			 	cout << "5. Finalize order and return to main menu.\n";
			 }
		cout << "\nPlease enter an option: ";
		cin >> OptionOrder;
		fflush(stdin);
		if (OptionOrder < 1 || OptionOrder > 5)
		{
			WrongInput = 1;
			cin.clear();
			MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
		}
		else if (cin.fail())
	    {
	    	WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
	    }
	    else
	    {
	    	WrongInput = 0; //To exit do-while loop condition (line 885)
	    	return OptionOrder;
		}
	}while(WrongInput == 1);
}

void AddItem(struct Receipt *top, int ReceiptCounter, int ItemCounter)
{
	Receipt *newReceipt = new Receipt;
	Receipt *current = top;

	int Continue;
	int WrongInput;
	char Input;
	
	newReceipt->ReceiptNo = ReceiptCounter;
	
	cout << "\nEnter model type: "; //User prompt to input model type of added item
	getline(cin, newReceipt->ModelType); //Copies user input into variable InputModelType
	fflush(stdin);
	
	do
	{								
		cout << "Enter item price: "; //user prompt to input price of added item
		cin >> newReceipt->Price; //Stores user input into variable InputPrice
		fflush(stdin);
		if (newReceipt->Price < 1)
		{
			WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
		}
		else if (cin.fail())
	    {
	    	WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
	    }
	    else
	    {
	    	WrongInput = 0; //To exit do-while loop condition (line 589)
		}
	}while(WrongInput == 1); //Repeats do-while loop (line 568) if user's input is invalid
								
	do
	{
		cout << "Enter item quantity: "; //User prompt to enter quantity of added item
		cin >> newReceipt->Quantity; //Stores user input into variable InputQuantity
		fflush(stdin);
		if (newReceipt->Quantity < 1)
		{
			WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
		}
		else if (cin.fail())
	    {
	    	WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
	    }
	    else
	    {
	    	WrongInput = 0;
	    	newReceipt->SubtotalPrice = (newReceipt->Price)*(newReceipt->Quantity);
		}
	}while(WrongInput == 1);
	
	newReceipt->next = NULL;
	while(current)
	{
		if(current->next == NULL)
		{
			current->next = newReceipt;
			return;
		}
		current = current->next;
	}
}

void EditItem(struct Receipt *top, int ReceiptCounter, int ItemCounter)
{
	Receipt *temp, *editItem;  //pointer to indicate Node to be deleted
	int TotalItem;
	int tempCounter = 1;
	int InputEdit;
	int InputDetail;
	int WrongInput;
	int SameReceipt = 0;
	float TotalPrice;

	TotalItem = ItemCounter-1;

	temp = top;
	
	if (top == NULL)	
	{
		cout << "The list is empty!" << endl << endl;
	}
	
	while (SameReceipt == 0)
	{
		if (temp->ReceiptNo != ReceiptCounter)
		{
			editItem = temp;
			temp = temp->next;
			SameReceipt = 0;
		}
		else if (temp->ReceiptNo == ReceiptCounter)
		{
			SameReceipt = 1;
		}
	}

	do
	{
		InputEdit = 0;
		cout << "\nEnter no. of item to be edited: ";
		cin >> InputEdit;
		fflush(stdin);
		if (InputEdit > TotalItem)
		{
			WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "No existing item in the slot, please retry.", "Warning!", MB_OK);
		}
		else if (InputEdit < 1 || InputEdit > 5)
		{
			WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
		}
		else
		{
			WrongInput = 0;
		}
	}while(WrongInput == 1);
	
	for (int tempCounter = 1; editItem != NULL && tempCounter <= InputEdit; tempCounter++)
	{
		editItem = editItem->next;
	}
	
	do
	{
		InputDetail = 0;
		cout << "\nEdit option:\n"
			 << "1. Model Type.\n"
			 << "2. Price.\n"
			 << "3. Quantity.\n"
			 << "4. All of the above.\n"
			 << "\nPlease enter an option: ";
		cin >> InputDetail;
		fflush(stdin);
		if (InputDetail < 1 || InputDetail > 5)
		{
			WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
		}
		else
		{
			WrongInput = 0;
		}
	}while(WrongInput == 1);
	
	if (InputDetail == 1)
	{
		cout << "\nEnter model type: "; //User prompt to input model type of added item
		getline(cin, editItem->ModelType); //Copies user input into variable InputModelType
		fflush(stdin);
		InputDetail = 0;
	}
	else if (InputDetail == 2)
	{
		do
		{								
			cout << "Enter item price: "; //user prompt to input price of added item
			cin >> editItem->Price; //Stores user input into variable InputPrice
			fflush(stdin);
			if (editItem->Price < 1)
			{
				WrongInput = 1;
		        cin.clear();
		        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
			}
			else if (cin.fail())
		    {
		    	WrongInput = 1;
		        cin.clear();
		        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
		    }
		    else
		    {
		    	WrongInput = 0; //To exit do-while loop condition (line 589)
		    	editItem->SubtotalPrice = (editItem->Price)*(editItem->Quantity);
			}
		}while(WrongInput == 1); //Repeats do-while loop (line 568) if user's input is invalid
	}
	else if (InputDetail == 3)
	{
		do
		{
			cout << "Enter item quantity: "; //User prompt to enter quantity of added item
			cin >> editItem->Quantity; //Stores user input into variable InputQuantity
			fflush(stdin);
			if (editItem->Quantity < 1)
			{
				WrongInput = 1;
		        cin.clear();
		      	MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
			}
			else if (cin.fail())
		    {
		    	WrongInput = 1;
		        cin.clear();
		        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
		    }
		    else
		    {
		    	WrongInput = 0;
		    	editItem->SubtotalPrice = (editItem->Price)*(editItem->Quantity);
			}
		}while(WrongInput == 1);
	}
	else if (InputDetail == 4)
	{
		cout << "\nEnter model type: "; //User prompt to input model type of added item
		getline(cin, editItem->ModelType); //Copies user input into variable InputModelType
		fflush(stdin);
		
		do
		{								
			cout << "Enter item price: "; //user prompt to input price of added item
			cin >> editItem->Price; //Stores user input into variable InputPrice
			fflush(stdin);
			if (editItem->Price < 1)
			{
				WrongInput = 1;
		        cin.clear();
		        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
			}
			else if (cin.fail())
		    {
		    	WrongInput = 1;
		        cin.clear();
		        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
		    }
		    else
		    {
		    	WrongInput = 0; //To exit do-while loop condition (line 589)
			}
		}while(WrongInput == 1); //Repeats do-while loop (line 568) if user's input is invalid
									
		do
		{
			cout << "Enter item quantity: "; //User prompt to enter quantity of added item
			cin >> editItem->Quantity; //Stores user input into variable InputQuantity
			fflush(stdin);
			if (editItem->Quantity < 1)
			{
				WrongInput = 1;
		        cin.clear();
		        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
			}
			else if (cin.fail())
		    {
		    	WrongInput = 1;
		        cin.clear();
		        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
		    }
		    else
		    {
		    	WrongInput = 0;
		    	editItem->SubtotalPrice = (editItem->Price)*(editItem->Quantity);
			}
		}while(WrongInput == 1);
	}
}

void DeleteItem(struct Receipt **top, int ReceiptCounter, int ItemCounter)
{
	Receipt *temp, *deleteItem;  //pointer to indicate Node to be deleted
	int TotalItem;
	int tempCounter = 1;
	int InputDelete;
	int WrongInput;
	int SameReceipt = 0;
	float TotalPrice;

	TotalItem = ItemCounter-1;
	temp = *top;
	
	if (top == NULL)	
	{
		cout << "The list is empty!" << endl << endl;
	}
	
	while (SameReceipt == 0)
	{
		if (temp->ReceiptNo != ReceiptCounter)
		{
			deleteItem = temp;
			temp = temp->next;
			SameReceipt = 0;
		}
		else if (temp->ReceiptNo == ReceiptCounter)
		{
			SameReceipt = 1;
		}
	}

	do
	{
		ViewReceipt(*top, ReceiptCounter, ItemCounter);
		cout << "\nEnter no. of item to be deleted: ";
		cin >> InputDelete;
		fflush(stdin);
		if (InputDelete > TotalItem)
		{
			WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "No existing item in the slot, please retry.", "Warning!", MB_OK);
		}
		else if (InputDelete < 1 || InputDelete > 5)
		{
			WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
		}
		else
		{
			WrongInput = 0;
		}
	}while(WrongInput == 1);
	
	for (int tempCounter = 1; deleteItem != NULL && tempCounter <= InputDelete-1; tempCounter++)
	{
		deleteItem = deleteItem->next;
	}
    temp = deleteItem->next->next;
    free(deleteItem->next); 
    deleteItem->next = temp;  
}

void ViewReceipt(struct Receipt *top, int ReceiptCounter, int ItemCounter)
{
	Receipt *temp;
	temp = top;
	int SameReceipt = 1;
	int TotalItem = ItemCounter;
	int tempCounter = 1;
	int Remaining = 5;
	float TotalPrice = 0;
	
	if (top == NULL)
	{
		cout << "The list is empty!" << endl<<endl;
	}
	
	while (temp->ReceiptNo != ReceiptCounter)
	{
		temp = temp->next;
		
		if (temp == NULL)
		{
			system("cls");
			cout << "\n--------------------------------------------------------------------------------------------\n";
			cout << "                                   Rakyat Electronics\n                                        Receipt";
			cout << "\nReceipt No: " << ReceiptCounter;
			cout << "\n--------------------------------------------------------------------------------------------\n";
			cout << " No.  Model Type                              Price (RM)     Quantity     Subtotal (RM)";
			cout << "\n--------------------------------------------------------------------------------------------\n";
			cout << "  " << setw(4) << left << tempCounter;
			cout << "\n--------------------------------------------------------------------------------------------\n";
			cout << setw(72) << right << "Total (RM):" << setw(11) << right << setprecision(2) << fixed << TotalPrice;
			cout << "\n--------------------------------------------------------------------------------------------\n";
			cout << "Receipt currently have no existing items.\n";
			return;
		}
		else if (temp->ReceiptNo == ReceiptCounter)
		{
			system("cls");
			cout << "\n--------------------------------------------------------------------------------------------\n";
			cout << "                                   Rakyat Electronics\n                                        Receipt";
			cout << "\nReceipt No: " << temp->ReceiptNo;
			cout << "\n--------------------------------------------------------------------------------------------\n";
			cout << " No.  Model Type                              Price (RM)     Quantity     Subtotal (RM)";
			cout << "\n--------------------------------------------------------------------------------------------\n";
			while (SameReceipt == 1)
			{
				cout << "  " << setw(4) << left << tempCounter
					 << setw(40) << left << temp->ModelType
					 << setw(8) << right << setprecision(2) << fixed << temp->Price
					 << setw(11) << right << temp->Quantity
					 << setw(18) << right << setprecision(2) << fixed << temp->SubtotalPrice;
				cout << "\n--------------------------------------------------------------------------------------------\n";
				TotalPrice = TotalPrice + temp->SubtotalPrice;
				Remaining = Remaining-1;
				tempCounter++;
				SameReceipt = 1;
				temp = temp->next;
				if (temp == NULL)
				{
					SameReceipt = 0;
					cout << setw(72) << right << "Total (RM):" << setw(11) << right << setprecision(2) << fixed << TotalPrice;
					cout << "\n--------------------------------------------------------------------------------------------\n";
					cout << "Receipt have " << Remaining << " remaining item(s).\n";
					return;	
				}
			}
		}
	}
}

void ViewSelectedReceipt(struct Receipt *top, int ReceiptCounter, int ItemCounter)
{
	Receipt *temp;
	temp = top;
	int SameReceipt = 1;
	int TotalReceipt = ReceiptCounter;
	int tempCounter = 1;
	int InputReceipt;
	int WrongInput;
	float TotalPrice = 0;
	
	if (top == NULL)
	{
		cout << "The list is empty!" << endl<<endl;
	}
	
	do
	{
		cout << "\nEnter the receipt no.: ";
		cin >> InputReceipt;
		fflush(stdin);
		if (InputReceipt > TotalReceipt)
		{
			WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "Receipt no. entered does not exist, please retry.", "Warning!", MB_OK);
		}
		else if (InputReceipt < 1)
		{
			WrongInput = 1;
	        cin.clear();
	        MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
		}
		else
		{
			WrongInput = 0;
		}
	}while(WrongInput == 1);
	
	while (temp->ReceiptNo != InputReceipt)
	{
		temp = temp->next;
	}
	
	system("cls");
	if (temp->ReceiptNo == InputReceipt)
	{
		cout << "\n--------------------------------------------------------------------------------------------\n";
		cout << "                                   Rakyat Electronics\n                                        Receipt";
		cout << "\nReceipt No: " << temp->ReceiptNo;
		cout << "\n--------------------------------------------------------------------------------------------\n";
		cout << " No.  Model Type                              Price (RM)     Quantity     Subtotal (RM)";
		cout << "\n--------------------------------------------------------------------------------------------\n";
		while (SameReceipt == 1)
		{
			cout << "  " << setw(4) << left << tempCounter
				 << setw(40) << left << temp->ModelType
				 << setw(8) << right << setprecision(2) << fixed << temp->Price
				 << setw(11) << right << temp->Quantity
				 << setw(18) << right << setprecision(2) << fixed << temp->SubtotalPrice
				 << "\n--------------------------------------------------------------------------------------------\n";
			TotalPrice = TotalPrice + temp->SubtotalPrice;
			tempCounter++;
			SameReceipt = 1;
			if (temp->next == NULL)
			{
				SameReceipt = 0;
				cout << setw(72) << right << "Total (RM):" << setw(11) << right << setprecision(2) << fixed << TotalPrice
					 << "\n--------------------------------------------------------------------------------------------\n";
				return;	
			}
			else
			{
				temp = temp->next;
				if (temp->ReceiptNo != InputReceipt)
				{
					SameReceipt = 0;
					cout << setw(72) << right << "Total (RM):" << setw(11) << right << setprecision(2) << fixed << TotalPrice
						 << "\n--------------------------------------------------------------------------------------------\n";
					return;	
				}
				else
				{
					SameReceipt = 1;
				}
			}
		}
	}
}

void ViewSummary(struct Receipt *top, int ReceiptCounter)
{
	Receipt *temp1, *temp2;
	int tempCounter;
	int tempCounter2;
	int InputSummary;
	int TotalItem;
	int WrongInput;
	float TotalPrice;
	
	InputSummary = 1;
	
	do
	{
		TotalItem = 0;
		TotalPrice = 0;
		temp1 = top;
		temp2 = top;
		
		while(temp1)
		{
			TotalItem = TotalItem+1;
			temp1 = temp1->next;
		}
		
		Receipt Copy[TotalItem];
		tempCounter = 0;
		while (temp2)
		{
			Copy[tempCounter].ModelType = temp2->ModelType;
			Copy[tempCounter].Price = temp2->Price;
			Copy[tempCounter].Quantity = temp2->Quantity;
			Copy[tempCounter].SubtotalPrice = temp2->SubtotalPrice;
			tempCounter++;
			temp2 = temp2->next;	
		}
		
		Receipt Placeholder;
		tempCounter = 0;
		tempCounter2 = 0;
		if (InputSummary == 1)
		{
			for (tempCounter2 = 0; tempCounter2 < TotalItem; tempCounter2++)
			{
				for (tempCounter = 0; tempCounter < TotalItem; tempCounter++)
				{
					if (Copy[tempCounter].ModelType > Copy[tempCounter2].ModelType)
					{
						Placeholder = Copy[tempCounter];
						Copy[tempCounter] = Copy[tempCounter2];
						Copy[tempCounter2] = Placeholder;
					}
				}
			}
		}
		else if (InputSummary == 2)
		{
			for (tempCounter2 = 0; tempCounter2 < TotalItem; tempCounter2++)
			{
				for (tempCounter = 0; tempCounter < TotalItem; tempCounter++)
				{
					if (Copy[tempCounter+1].SubtotalPrice > Copy[tempCounter].SubtotalPrice)
					{
						Placeholder = Copy[tempCounter];
						Copy[tempCounter] = Copy[tempCounter+1];
						Copy[tempCounter+1] = Placeholder;
					}
				}
			}
		}
		else if (InputSummary == 3)
		{
			return;
		}
		
		do
		{	
			system("cls");
			tempCounter = 0;
			tempCounter2 = 0;
			cout << "\n--------------------------------------------------------------------------------------------\n";
			cout << "                                   Rakyat Electronics\n                                  Daily Sales Summary";
			cout << "\n--------------------------------------------------------------------------------------------\n";
			cout << " No.  Model Type                              Price (RM)     Quantity     Subtotal (RM)";
			cout << "\n--------------------------------------------------------------------------------------------\n";
			while (tempCounter < TotalItem)
			{
				cout << "  " << setw(4) << left << tempCounter+1
					 << setw(40) << left << Copy[tempCounter].ModelType
					 << setw(8) << right << setprecision(2) << fixed << Copy[tempCounter].Price
					 << setw(11) << right << Copy[tempCounter].Quantity
					 << setw(18) << right << setprecision(2) << fixed << Copy[tempCounter].SubtotalPrice << endl;
				TotalPrice = TotalPrice + Copy[tempCounter].SubtotalPrice;
				tempCounter++;
			}
			cout << "--------------------------------------------------------------------------------------------\n"
				 << setw(63) << right << "Total (RM):" << setw(20) << right << setprecision(2) << fixed << TotalPrice
			 	 << "\n--------------------------------------------------------------------------------------------\n";
		 	 
			cout << "\nOption:\n"
				 << "1. Sort by Model Type.\n"
				 << "2. Sort by Subtotal Price.\n"
				 << "3. Return to main menu.\n"
				 << "\nPlease enter an option: ";
			cin >> InputSummary;
			fflush(stdin);
			if (InputSummary < 1 || InputSummary > 3)
			{
				cin.clear();
				WrongInput = 1;
				MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
			}
			else if (cin.fail())
			{
				cin.clear();
				WrongInput = 1;
				MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
			}
			else
			{
				WrongInput = 0;
				
			}
		}while(WrongInput == 1);
	}while(InputSummary != 3);
}

int main()
{
	int ReceiptCounter;
	int ItemCounter;
	int OptionMenu;
	int OptionOrder;
	int Continue;
	int ContinueUse;
	int ReturnOrder;
	int ReturnMenu;
	int EmptyReceipt;
	int InputSummary;
	int WrongInput;
	char InputContinue;
	char ContinueAdd;
	char ContinueDelete;
	
	struct Receipt *top = new Receipt;
	
	for (ReceiptCounter = 1; ReceiptCounter <= 5; ReceiptCounter++)
	{
		for (ItemCounter = 1; ItemCounter <= 5; ItemCounter++)
		{		
			PresetReceipt(top, ReceiptCounter, ItemCounter);
		}
	}
	ReceiptCounter--;
	ItemCounter = 1;
	
	do
	{
		do
		{
			EmptyReceipt = 1;
			OptionMenu = MainMenu(OptionMenu);
			if (OptionMenu == 1)
			{
				do
				{
					OptionOrder = OrderMenu(OptionOrder, EmptyReceipt);
					if (OptionOrder == 1)
					{
						if (EmptyReceipt == 1)
						{
							ReceiptCounter++;
							EmptyReceipt = 0;
						}
						
						if (ItemCounter <= 5)
						{
							do
							{
								ViewReceipt(top, ReceiptCounter, ItemCounter);
								AddItem(top, ReceiptCounter, ItemCounter);
								ViewReceipt(top, ReceiptCounter, ItemCounter);
								if (ItemCounter < 5)
								{
									do
									{
										cout << "\nContinue adding items? (Y/N): ";
										cin >> InputContinue;
										fflush(stdin);
										if (toupper(InputContinue) != 'Y' && toupper (InputContinue) != 'N')
										{
											MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
											ViewReceipt(top, ReceiptCounter, ItemCounter);
										}
										else if (toupper(InputContinue) == 'Y')
										{
											ItemCounter++;
											Continue = 1;
										}
										else if (toupper(InputContinue) == 'N')
										{
											ItemCounter++;
											Continue = 0;
											ReturnOrder = 1;
										}
									}while(toupper(InputContinue) != 'Y' && toupper (InputContinue) != 'N');
								}
								else if (ItemCounter == 5)
								{
									cout << "\nReceipt have reached maximum amount of items.\n";
									system("pause");
									ItemCounter++;
									Continue = 0;
									ReturnOrder = 1;
								}
							}while(Continue == 1);
						}
						else if (ItemCounter > 5)
						{
							cout << "\nReceipt have reached maximum amount of items.\n";
							system("pause");
							ReturnOrder = 1;
						}
					}
					else if (OptionOrder == 2)
					{
						if (EmptyReceipt == 1)
						{
							ReceiptCounter++;
							ViewReceipt(top, ReceiptCounter, ItemCounter);
							ReceiptCounter--;
							system("pause");
							ReturnOrder = 1;
						}
						else if (EmptyReceipt == 0)
						{
							do
							{
								ViewReceipt(top, ReceiptCounter, ItemCounter);
								EditItem(top, ReceiptCounter, ItemCounter);
								ViewReceipt(top, ReceiptCounter, ItemCounter);
			
								cout << "\nContinue editing items? (Y/N): ";
								cin >> InputContinue;
								fflush(stdin);
								if (toupper(InputContinue) != 'Y' && toupper (InputContinue) != 'N')
								{
									MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
									ViewReceipt(top, ReceiptCounter, ItemCounter);
								}
								else if (toupper(InputContinue) == 'Y')
								{
									Continue = 1;
								}
								else if (toupper(InputContinue) == 'N')
								{
									Continue = 0;
									ReturnOrder = 1;
								}
							}while(Continue == 1);
						}
					}
					else if (OptionOrder == 3)
					{
						if (EmptyReceipt == 1)
						{
							ReceiptCounter++;
							ViewReceipt(top, ReceiptCounter, ItemCounter);
							ReceiptCounter--;
							system("pause");
							ReturnOrder = 1;
						}
						else if (EmptyReceipt == 0)
						{
							if (ItemCounter > 0)
							{
								do
								{
									if (ItemCounter > 0)
									{
										ViewReceipt(top, ReceiptCounter, ItemCounter);
										DeleteItem(&top, ReceiptCounter, ItemCounter);
										ItemCounter--;
										ViewReceipt(top, ReceiptCounter, ItemCounter);
										if (ItemCounter > 1)
										{
											do
											{
												cout << "\nContinue deleting items? (Y/N): ";
												cin >> InputContinue;
												fflush(stdin);
												if (toupper(InputContinue) != 'Y' && toupper (InputContinue) != 'N')
												{
													MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
													ViewReceipt(top, ReceiptCounter, ItemCounter);
												}
												else if (toupper(InputContinue) == 'Y')
												{
													Continue = 1;
												}
												else if (toupper(InputContinue) == 'N')
												{
													Continue = 0;
													ReturnOrder = 1;
												}
											}while(toupper(InputContinue) != 'Y' && toupper (InputContinue) != 'N');
										}
										else
										{
											ItemCounter = 1;
											EmptyReceipt = 1;
											Continue = 0;
											ReturnOrder = 1;
											ViewReceipt(top, ReceiptCounter, ItemCounter);
											system("pause");
											ReceiptCounter--;
										}
									}
									else if (ItemCounter == 1)
									{
										ItemCounter = 1;
										EmptyReceipt = 1;
										Continue = 0;
										ReturnOrder = 1;
										ViewReceipt(top, ReceiptCounter, ItemCounter);
										system("pause");
										ReceiptCounter--;
									}
								}while(Continue == 1);
							}
							else
							{
								ViewReceipt(top, ReceiptCounter, ItemCounter);
								system("pause");
							}
						}
					}
					else if (OptionOrder == 4)
					{
						if (EmptyReceipt == 1)
						{
							ReceiptCounter++;
							ViewReceipt(top, ReceiptCounter, ItemCounter);
							ReceiptCounter--;
							system("pause");
						}
						else
						{
							ViewReceipt(top, ReceiptCounter, ItemCounter);
							system("pause");
						}
						ReturnOrder = 1;
					}
					else if (OptionOrder == 5)
					{
						ReturnOrder = 0;
						ReturnMenu = 1;
						ItemCounter = 1;
					}
				}while(ReturnOrder == 1);
			}
			else if (OptionMenu == 2)
			{
				do
				{
					ViewSelectedReceipt(top, ReceiptCounter, ItemCounter);
					cout << "\nContinue viewing receipts? (Y/N): ";
					cin >> InputContinue;
					fflush(stdin);
					if (toupper(InputContinue) != 'Y' && toupper (InputContinue) != 'N')
					{
						MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
					}
					else if (toupper(InputContinue) == 'Y')
					{
						Continue = 1;
					}
					else if (toupper(InputContinue) == 'N')
					{
						Continue = 0;
						ReturnOrder = 1;
					}
				}while(Continue == 1);
			}
			else if (OptionMenu == 3)
			{
				ViewSummary(top, ReceiptCounter);
				ReturnMenu = 1;
			}
			else if (OptionMenu == 4)
			{
				ReturnMenu = 0;
				ContinueUse = 0;
			}
		}while(ReturnMenu == 1);
		
		if (OptionMenu != 4)
		{
			cout << "\nContinue to main menu? ";
			cin >> InputContinue;
			fflush(stdin);
			if (toupper(InputContinue) != 'Y' && toupper(InputContinue) != 'N')
			{
				MessageBox(0, "Invalid input, please retry.", "Warning!", MB_OK);
			}
			else if (toupper(InputContinue) == 'Y')
			{
				ContinueUse = 1;
			}
			else if (toupper(InputContinue) == 'N')
			{
				ContinueUse = 0;
			}
		}
	}while(ContinueUse == 1);
}

/*
=========================================================================================================================================================
																	Preset Receipt
=========================================================================================================================================================
*/

void PresetReceipt(struct Receipt *top, int ReceiptCounter, int ItemCounter)
{
	Receipt *current = top;
	Receipt *newItem = new Receipt;
	
	if (ReceiptCounter == 1)
	{
		if (ItemCounter == 1)
		{
			top->ReceiptNo = ReceiptCounter;
			top->ModelType = "iPhone 12 Pro";
			top->Price = 4899;
			top->Quantity = 3;
			top->SubtotalPrice = (top->Price)*(top->Quantity);
			top->next = NULL;
		}
		else if (ItemCounter == 2)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Acer Nitro 5";
			newItem->Price = 2999;
			newItem->Quantity = 2;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 3)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Huawei Vision S";
			newItem->Price = 2999;
			newItem->Quantity = 4;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 4)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Pensonic Electric Oven";
			newItem->Price = 299;
			newItem->Quantity = 8;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 5)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Khind Hairdryer HD1400";
			newItem->Price = 39;
			newItem->Quantity = 5;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
	}
	else if (ReceiptCounter == 2)
	{
		if (ItemCounter == 1)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Samsung Galaxy S20";
			newItem->Price = 3399;
			newItem->Quantity = 4;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 2)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Asus TUF Gaming";
			newItem->Price = 3499;
			newItem->Quantity = 2;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 3)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "LG UN74 Series";
			newItem->Price = 4249;
			newItem->Quantity = 3;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 4)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Kenwood Sandwich Maker";
			newItem->Price = 149;
			newItem->Quantity = 9;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 5)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Panasonic Shaver";
			newItem->Price = 69;
			newItem->Quantity = 7;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
	}
	else if (ReceiptCounter == 3)
	{
		if (ItemCounter == 1)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Asus ROG Phone 5";
			newItem->Price = 3199;
			newItem->Quantity = 7;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 2)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Apple MacBook Pro";
			newItem->Price = 5599;
			newItem->Quantity = 2;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 3)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Samsung AU9000 4K UHD";
			newItem->Price = 4999;
			newItem->Quantity = 2;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 4)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Philip Rice Cooker";
			newItem->Price = 379;
			newItem->Quantity = 5;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 5)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Philips Essential Curler";
			newItem->Price = 69;
			newItem->Quantity = 3;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
	}
	else if (ReceiptCounter == 4)
	{
		if (ItemCounter == 1)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Google Pixel 4A";
			newItem->Price = 2199;
			newItem->Quantity = 2;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 2)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Lenovo Legion 5i 15";
			newItem->Price = 4449;
			newItem->Quantity = 4;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 3)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Apple TV";
			newItem->Price = 899;
			newItem->Quantity = 2;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 4)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Panasonic Blender";
			newItem->Price = 159;
			newItem->Quantity = 3;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 5)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Pensonic Hair Straightener";
			newItem->Price = 279;
			newItem->Quantity = 3;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
	}
	else if (ReceiptCounter == 5)
	{
		if (ItemCounter == 1)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Xiaomi Mi 11";
			newItem->Price = 2999;
			newItem->Quantity = 2;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 2)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "MSI GF63 Thin";
			newItem->Price = 3499;
			newItem->Quantity = 1;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 3)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Sony PlayStation 5";
			newItem->Price = 9999;
			newItem->Quantity = 1;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 4)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Midea Jug Kettle";
			newItem->Price = 119;
			newItem->Quantity = 2;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
		else if (ItemCounter == 5)
		{
			newItem->ReceiptNo = ReceiptCounter;
			newItem->ModelType = "Oral-B Power Toothbrush";
			newItem->Price = 39;
			newItem->Quantity = 4;
			newItem->SubtotalPrice = (newItem->Price)*(newItem->Quantity);
			while(current)
			{
				if (current->next == NULL)
				{
					current->next = newItem;
					return;
				}
				current = current->next;
			}
		}
	}
}
