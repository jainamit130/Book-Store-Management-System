#include "Book_Funs.cpp"

class Options: protected FindBook , public ListBooks, private RefillStock{
	public:
	Options(){
		listauth();
		listcat();
	}
	void run(){

		Book b;
		int x=1;
		char c;
		cout<<"\nBOOK STORE MANAGEMENT SYSYTEM\n\n";
		cout<<"Welcome Ma'am,\n\n";
		while(x){
			listcat();
			listauth();
			cout<<"1. Sell a book\n2. Find a book\n3. Refill Stock\n4. To list all books\n5. To exit\n";
	//		cin.ignore(256,'\n');

			cin>>c;
			switch(c){
				case '1':{
				    Sell *s;
				    SellBook sellers_copy;
				    s=&sellers_copy;
					s->sellBook();
					Bill sellers_bill(sellers_copy.total);
					Bill customer_bill(sellers_bill);
					customer_bill.display();
					break;
				}
				case '2':{
					findBook();
					break;
				}
				case '3':{
					refillStock();
					break;
				}
				case '4':{
					listBooks();
					break;
				}
				case '5':{
					x=0;
					break;
				}
				default:{
					cout<<"Enter a valid choice.\n";
					break;
				}
			}
		}
	}
};
