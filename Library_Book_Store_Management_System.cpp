#include<bits/stdc++.h>
#include<fstream>
#include<string.h>

using namespace std;

class date{public:
	int d, m, y;
};

class CompareString
{
public:
    string a;
    int l;
    int operator==(CompareString& b)
    {
        if(l!=(b.l))
		return 0;
	else{
		for(int i=0;i<b.l;i++){
			if(toupper(a[i])!=toupper(b.a[i]))
				return 0;
		}
	}
	return 1;
    }
};

inline int Search(char a[], char b[]){
//	if(strlen(a)!=strlen(b))
//		return 1;
//	else{
		for(int i=0;i<strlen(b);i++){
			if(toupper(a[i])!=toupper(b[i]))
				return 1;
		}
//	}
	return 0;
}

class Book{
    public:
	int cp, sp, yop, edition, quantity, shelfNo, bookId;
	char name[100], author[100], category[100];
	date prev_arr, next_arr;
	Book()
	{
	}
	Book(char s[],int t)
	{
	    if(t==1)
        {
            for(int i=0;i<strlen(s);i++)
                this->name[i]=s[i];
        }
        if(t==2)
        {
            for(int i=0;i<strlen(s);i++)
                this->author[i]=s[i];
        }
	}
	void getdata();
	Book getdata(int tempid);
	Book update_msg();
	void calcSP();
	//void purchase();
	void showDetails();
	//friend void findBook();
	friend int Search(Book, Book, int);
};

void Book::getdata(){
	cin.ignore(256,'\n');
	cout<<"Enter category of the Book: ";
	gets(category);
	cout<<"Enter name of the Book: ";
	//cin.ignore(256,'\n');
	gets(name);
	//cin.ignore(256,'\n');
	cout<<"Enter the Author's name: ";
	gets(author);
	cout<<"Enter Book Id: ";
	cin>>bookId;
	cout<<"Enter the year of publication: ";
	cin>>yop;
	cout<<"Enter the edition: ";
	cin>>edition;
	cout<<"Enter the cost price: ";
	cin>>cp;
	cout<<"Enter the selling price: ";
	cin>>sp;
	cout<<"Enter the shelf no.: ";
	cin>>shelfNo;
	cout<<"Enter the quantity: ";
	cin>>quantity;
	cout<<"Enter the Stock arrival date in the format dd mm yy: ";
	cin>>prev_arr.d>>prev_arr.m>>prev_arr.y;
	cout<<"Enter the next stock arrival date in the format dd mm yy: ";
	cin>>next_arr.d>>next_arr.m>>next_arr.y;
	cin.ignore(256,'\n');
}


Book Book::getdata(int tempid){
	cin.ignore(256,'\n');
	cout<<"Enter category of the Book: ";
	gets(category);
	cout<<"Enter name of the Book: ";
	//cin.ignore(256,'\n');
	gets(name);
	//cin.ignore(256,'\n');
	cout<<"Enter the Author's name: ";
	gets(author);
//	cout<<"Enter Book Id: ";
//	cin>>bookId;
	bookId=tempid;
	cout<<"Enter the year of publication: ";
	cin>>yop;
	cout<<"Enter the edition: ";
	cin>>edition;
	cout<<"Enter the cost price: ";
	cin>>cp;
	cout<<"Enter the selling price: ";
	cin>>sp;
	cout<<"Enter the shelf no.: ";
	cin>>shelfNo;
	cout<<"Enter the quantity: ";
	cin>>quantity;
	cout<<"Enter the previous stock arrival date in the format dd mm yy: ";
	cin>>prev_arr.d>>prev_arr.m>>prev_arr.y;
	cout<<"Enter the next stock arrival date in the format dd mm yy: ";
	cin>>next_arr.d>>next_arr.m>>next_arr.y;
	cout<<"\n";
	cin.ignore(256,'\n');
	return *this;
}

Book Book::update_msg()
{
    cout<<"New Book Details:\n\n";
    return *this;
}

void Book::showDetails(){
	cout<<"Category of the Book: ";
	cout<<category<<endl;
	cout<<"Name of the Book: ";
	cout<<name<<endl;
	cout<<"Author's name: ";
	cout<<author<<endl;
	cout<<"Book Id: ";
	cout<<bookId<<endl;
	cout<<"Cost price: ";
	cout<<cp<<endl;
	cout<<"Selling price: ";
	cout<<sp<<endl;
	cout<<"Year of publication: ";
	cout<<yop<<endl;
	cout<<"Edition: ";
	cout<<edition<<endl;
	cout<<"Shelf no.: ";
	cout<<shelfNo<<endl;
	cout<<"Quantity: ";
	cout<<quantity<<endl;
	cout<<"Previous stock arrival date: ";
	cout<<prev_arr.d<<"-"<<prev_arr.m<<"-"<<prev_arr.y<<endl;
	cout<<"Next stock arrival date: ";
	cout<<next_arr.d<<"-"<<next_arr.m<<"-"<<next_arr.y<<endl;
}

inline int Search(Book a, Book b, int t){
//	if(strlen(a)!=strlen(b))
//		return 1;
//	else{
        if(t==1)
        {
		for(int i=0;i<strlen(b.name);i++){
			if(toupper(a.name[i])!=toupper(b.name[i]))
				return 1;
		}
        }
        if(t==2)
        {
          for(int i=0;i<strlen(b.author);i++){
			if(toupper(a.author[i])!=toupper(b.author[i]))
				return 1;
		}
        }
//	}
	return 0;
}

//	Class Book Function Definition
// 1. list book function
// 2. Sell Book function
// 3. Find book function
// 4. Refill stock function

//1. list book function
class ListBooks{
	public:
		void listBooks(){
			fstream f;
			f.open("book_info1.dat",ios::binary|ios::in);
			int i=1;
			Book b;
			while(f.read((char*)&b,sizeof(b))){
				//cout<<i<<".  "<<"Book id: "<<b1.bookId<<endl<<"      Name: "<<b1.name<<endl<<"      Author: "<<b1.author<<endl<<"      Category: "<<b1.category<<endl<<"      Shelf No. : "<<b1.shelfNo<<endl<<"      Price: "<<b1.sp<<endl<<"\n"<<endl;
				i++;
			}
			f.close();
			f.open("book_info1.dat",ios::binary|ios::in);
			Book b1[i];
			i=1;
			cout<<"\nBooks available: \n\n";
			for(int j=0;j<i;j++)
            {
               while(f.read((char*)&b1[j],sizeof(b1[j]))){
				cout<<i++<<".  "<<"Book id: "<<b1[j].bookId<<endl<<"      Name: "<<b1[j].name<<endl<<"      Author: "<<b1[j].author<<endl<<"      Category: "<<b1[j].category<<endl<<"      Shelf No. : "<<b1[j].shelfNo<<endl<<"      Price: "<<b1[j].sp<<endl<<"\n"<<endl;
			}
            }
		}
};

// 2. Sell Book function
class Sell
{
public:
    virtual void sellBook()=0;
};

class SellBook: public Sell
{
	public:
	    int total;
	    static int sold_books_count;
	    SellBook()
	    {
	        total=0;
	    }
	    static void book_no(int n)
    {
        SellBook::sold_books_count=n;
    }
		virtual void sellBook(){
			int n,id;
			cout<<"How many books you want to sell: ";
			cin>>n;
			SellBook::book_no(n);
			for(int i=1;i<=n;i++){
				cout<<"Enter Id of book no. "<<i<<": ";
				cin>>id;
				fstream f1,f2;
				Book b1;
				f1.open("book_info1.dat",ios::binary|ios::in);
				f2.open("temp.dat",ios::binary|ios::out);
				while(f1.read((char*)&b1,sizeof(b1))){
					if(b1.bookId==id){
						if(b1.quantity<1){
							cout<<"  Empty Stock\n";
							id=-1;
							cout<<"  Next arrival date: "<<b1.next_arr.d<<"-"<<b1.next_arr.m<<"-"<<b1.next_arr.y<<endl<<endl;
						}
						else{
							b1.quantity-=1;
							cout<<"\nUpdated details of "<<"'"<<b1.name<<"'"<<": "<<endl;
							cout<<"Quantitly left: "<<b1.quantity<<endl;
							cout<<"Selling Price: "<<b1.sp<<endl<<endl;
							total+=b1.sp;
							id=-1;
						}
					}

					f2.write((char*)&b1,sizeof(b1));
				}
				f1.close();
				f2.close();
				remove("book_info1.dat");
				rename("temp.dat","book_info1.dat");
				if(id!=-1){
					cout<<"\n<Error> This Book Id doesn't exist\n\n";
					i--;
				}
			}
			cout<<"Total amount of "<<n<<" books: "<<total<<endl;
			//cout<<"GST: "<<0.12*(float)total<<endl;
			//cout<<"Total payable amount: "<<total+(0.12*(float)total)<<endl<<endl;
		}
};
int SellBook::sold_books_count=0;
//2.1 Billing
class Bill:private SellBook
{
public:
    float gst;
    float *ptr;
    Bill()
    {
        total=0;
        gst=0.12*(float)total;
        ptr=new float(total+gst);
    }
    Bill(int t)
    {
        total=t;
        gst=0.12*(float)total;
        ptr=new float(total+gst);
    }
    Bill(Bill& B)
    {
        this->total=B.total;
        this->gst=B.gst;
        ptr=new float(*(B.ptr));
    }
    ~Bill ()
    {
        delete ptr;
    }
    void display()
    {
        cout<<"\n\n--------------Customer Bill---------------\n\n";
        cout<<"Total amount of "<<SellBook::sold_books_count<<" books: "<<total<<endl;
        cout<<"GST: "<<0.12*(float)total<<endl;
        cout<<"Total payable amount: "<<total+gst<<endl<<endl;
        cout<<"\n----------------------------------------------\n\n";
    }
};


//3 Find Book

//3.1 using category..
class FindCat{
	public:
		vector<string> cat;
		/*FindCat()
		{
		}*/
		/*FindCat(char* s)
		{
		    if(s=="undefined")
              cat.push_back(s);
		}*/

		void listcat(){
			fstream f;
			CompareString s,s1;
			Book b1;
			f.open("book_info1.dat",ios::binary|ios::in);
			while(f.read((char*)&b1,sizeof(b1))){
				s.a=b1.category;
				s.l=(s.a).length();
				int flag=0;
				for(int i=0;i<cat.size();i++){
                    s1.a=cat[i];
                    s1.l=cat[i].length();
					if(s==s1){
						flag=1;
						break;
					}
				}
				if(flag==0){
                    //cat.clear();
					cat.push_back(s.a);
				}
			}
			sort(cat.begin(),cat.end());
		}

		void findCat(char s[]){
			Book b1;
			int count=0;
			fstream f1;
			f1.open("book_info1.dat",ios::binary|ios::in);
			cout<<endl<<"Books available: \n\n";
			while(f1.read((char*)&b1,sizeof(b1))){
				if((!Search(b1.category,s))&&b1.quantity!=0){
					count++;
					cout<<count<<".  "<<"Name: "<<b1.name<<endl<<"     Author: "<<b1.author<<endl<<"     Category: "<<b1.category<<endl<<"     Shelf No. : "<<b1.shelfNo<<endl<<"     Price: "<<b1.sp<<endl<<"\n"<<endl;

				}
			}
			if(count==0)
				cout<<"<Empty set>\n"<<endl;
			f1.close();
		}

};


//3.2 using name..
class FindName{
	public:
	void findName(char s[]){
		//public:
		Book b1;
		fstream f1;
		int count=0;
		f1.open("book_info1.dat",ios::binary|ios::in);
		cout<<endl<<"Books available: \n\n";
		while(f1.read((char*)&b1,sizeof(b1))){
			if(!Search(b1.name,s)){
				count++;
				cout<<count<<".  "<<"Name: "<<b1.name<<endl<<"      Author: "<<b1.author<<endl<<"      Category: "<<b1.category<<endl<<"      Shelf No. : "<<b1.shelfNo<<endl<<"      Price: "<<b1.sp<<endl<<"\n"<<endl;
				if(b1.quantity==0){
					cout<<"      Next arrival date: "<<b1.next_arr.d<<"-"<<b1.next_arr.m<<"-"<<b1.next_arr.y<<endl<<endl;
				}
			}
		}
		if(count==0)
			cout<<"Not found\n\n";
		f1.close();
	}
};


//3.3 using author..
class FindAuthor{
	public:
		vector<string> auth;
		/*FindAuthor()
		{}*/
		/*FindAuthor(char* s)
		{
		    if (s=="Author not mentioned")
		    auth.push_back(s);
		}*/
		void listauth(){
			fstream f;
			CompareString s,s1;
			Book b1;
			f.open("book_info1.dat",ios::binary|ios::in);
			while(f.read((char*)&b1,sizeof(b1))){
				s.a=b1.author;
				s.l=(s.a).length();
				int flag=0;
				for(int i=0;i<auth.size();i++){
                    s1.a=auth[i];
                    s1.l=(s1.a).length();
					if(s==s1){
						flag=1;
						break;
					}
				}
				if(flag==0){
                    //auth.clear();
					auth.push_back(s.a);
				}
			}
			sort(auth.begin(),auth.end());
		}
		void findAuthor(char s[]){
			Book b1;
			int count=0;
			fstream f1;
			f1.open("book_info1.dat",ios::binary|ios::in);
			cout<<endl<<"Books available: \n\n";
			while(f1.read((char*)&b1,sizeof(b1))){
				if((!Search(b1.author,s))&&b1.quantity!=0){
					count++;
					cout<<count<<".  "<<"Name: "<<b1.name<<endl<<"    Author: "<<b1.author<<endl<<"    Category: "<<b1.category<<endl<<"    Shelf No. : "<<b1.shelfNo<<endl<<"    Price: "<<b1.sp<<endl<<"\n"<<endl;
				}
			}
			if(count==0)
				cout<<"<Empty set>\n\n";
			f1.close();
		}
};


//3.4 using shelfNo..
class FindShelf{
	public:
		void findShelf(int i){
			Book b1;
			int count=0;
			fstream f1;
			f1.open("book_info1.dat",ios::binary|ios::in);
			cout<<"Books available in shelf "<<i<<" are: \n\n";
			while(f1.read((char*)&b1,sizeof(b1))){
				if(b1.shelfNo==i&&b1.quantity!=0){
					count++;
					cout<<count<<".  "<<"Name: "<<b1.name<<endl<<"    Author: "<<b1.author<<endl<<"    Category: "<<b1.category<<endl<<"    Price: "<<b1.sp<<endl<<"\n"<<endl;
				}
			}
			if(count==0)
				cout<<"<Empty set>\n\n";
			f1.close();
		}
};


//3. Find book function
class FindBook: public FindCat, private FindName, protected FindAuthor, public FindShelf{
	public:
//		vector<string> cat,auth;
        FindBook():FindShelf(),FindAuthor(),FindName(),FindCat()
        {
            //cout<<"To Find you the right book, help me out with few details: \n\n";
        }
		void findBook(){
			int c,i;
			char s[100];
			cout<<"1. Find book by Category\n2. Find book by Name\n3. Find book by Author's Name\n4. Find book by shelf no.\n";
			cin>>c;
			switch(c){
				case 1:{
					cout<<"Categories:\n";
					for(int i=0;i<cat.size();i++){
						cout<<"  "<<cat[i]<<endl;
					}
					cout<<"\nEnter category of the book: ";
					cin>>s;
					findCat(s);
					break;
				}
				case 2:{
					cin.ignore(256,'\n');
					cout<<"Enter name of the book: ";
					gets(s);
					findName(s);
					break;
				}
				case 3:{
//					cout<<"Authors:\n\n";
//					for(int i=0;i<auth.size();i++){
//						cout<<i<<") "<<auth[i]<<endl;
//					}
					cin.ignore(256,'\n');
					cout<<"\nEnter the Author's name: ";
					gets(s);
					findAuthor(s);
					break;
				}
				case 4:{
					cout<<"Enter Shelf No. : ";
					cin>>i;
					findShelf(i);
					break;
				}
				default:{
					cout<<"Enter a valid choice.\n";
					//findBook();
					break;
				}
			}
		}

};

//4 refill stock

//4.1 addold..
class AddOld{
	public:
		int addOld(int id){
			int q,flag=0;
			cout<<"Enter quantity of the book: ";
			cin>> q;
			fstream f1,f2;
			f1.open("book_info1.dat",ios::binary|ios::in);
			f2.open("temp.dat",ios::binary|ios::out);
			Book b1;
			while(f1.read((char*)&b1,sizeof(b1))){
				if(b1.bookId==id){
					flag=1;
					b1.quantity+=q;
					cout<<"\nUpdated details of "<<"'"<<b1.name<<"'"<<": "<<endl;
					cout<<"Quantitly left: "<<b1.quantity<<endl;
					cout<<"Cost Price of the stock: "<<b1.cp*q<<endl<<endl;
				}
				f2.write((char*)&b1,sizeof(b1));
			}
			f1.close();
			f2.close();
			remove("book_info1.dat");
			rename("temp.dat","book_info1.dat");
			if(flag==0){
				cout<<"\nThis book is not already listed.\nFirst list the book.\n\n";
			}
			return flag;
		}

};


//4.2 addNew..
class AddNew{
	public:
		int addNew(int temp){
			Book b1;
			int error=0;
			fstream f;
			f.open("book_info1.dat",ios::binary|ios::in);
			while(f.read((char*)&b1,sizeof(b1))){
				if(b1.bookId==temp){
					error=1;
					break;
				}
			}
			f.close();
			try{
			    if(error==1)
                    throw 0;
				b1.getdata(temp).update_msg().showDetails();  // Cascaded Function Call
				f.open("book_info1.dat",ios::binary|ios::app);
				f.write((char*)&b1,sizeof(b1));
				//b1.showDetails();
				cout<<endl;
				f.close();
//				listcat();
//				listauth();
			}
			catch(int i)
			{
			    if(i==0)
                cout<<"\nThis id already exist.\n\n";
			}
			return error;
		}
};


//4 Refill stock function
class RefillStock: protected AddOld, private AddNew{
	public:
		void refillStock(){
			int x,n,id,cost=0;
			cout<<"Enter no. of Lotts: ";
			cin>>n;
			while(n--){

				cout<<"1. For already listed book\n2. For new listing\n";
				cin>>x;
				switch(x){
					case 1:{
						cout<<"Enter book id: ";
						cin>>id;
						int temp = addOld(id);
						if(temp==0)
							n++;
						break;
					}
					case 2:{
						int temp;
						cout<<"Enter book id:\n";
						cin>>temp;
						addNew(temp);
						if(temp==1)
							n++;
						break;
					}
					default:{
						cout<<"Enter a valid choice.\n";
						n++;
						break;
					}
				}
			}
		}
};

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
		cout<<"Welcome,\n\n";
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

int main(){
	Options a;
	a.run();
}


