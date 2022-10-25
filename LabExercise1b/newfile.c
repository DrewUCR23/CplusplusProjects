/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */



 // If a lower-case status is entered, convert it to upper case.
  customerStatus = toupper(customerStatus);
  // Get the amount spent by the customer from the cashier
  cout << "Enter amount spent: ";
  cin >> amountSpent;
  // Calculation for discount
  
  if (customerStatus == 'N'); {
      
     // discount = amountSpent*NORMAL_Discount;
      cout<<"Normal discount"<<amountSpent*NORMAL_DISCOUNT<<endl;  
  }
   else if (customerStatus == 'R') {
      
     //  discount = amountSpent * RETIREE_VETERAN_DISCOUNT;
      cout<<"Senior Discount:"<<amountSpent*RETIREE_VETERAN_DISCOUNT<<endl;      
   }
  
  else if (customerStatus == 'S') {
      
     // discount = amountSpent * STUDENT_DISCOUNT; 
      cout<<"Senior Discount:"<<amountSpent*STUDENT_DISCOUNT<<endl;
  else if (customerStatus == 'V') {
      
      //discount = amountSpent * RETIREE_VETERAN_DISCOUNT; 
      cout<<"Senior Discount:"<<amountSpent*RETIREE_VETERAN_DISCOUNT<<endl;
  }
  else 
      cout<<"Invalid Customer status"<<customer_Status<<endl;
  
  //Discount difference
   
  //difference = amountPaid - discount; 