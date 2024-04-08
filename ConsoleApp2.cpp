#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class product {
public:
	int product_id;
	int price;
	string product_name;
	int quantity;
	float rating;
	string material;
	string availability;
	string category;

	void addnew(int p1, int p2, int p3, float p4, string p5, string p6, string p7, string p8) {
		product_id = p1;
		price = p2;
		quantity = p3;
		rating = p4;
		product_name = p5;
		material = p6;
		availability = p7;
		category = p8;
	}
};

class orders {
public:
	int tot;
	map<string, string> det;
};

vector<orders> os;
vector<product> products_all;
map<int, product> mp;
map<int,product> request;
map<int, product> all;

class seller {
public:
	int seller_id;
	string seller_name;
	product p1;
	void add_product() {
		cout << "Enter Product Id : ";
		cin >> p1.product_id;
		cout << "Enter Product Name : ";
		cin >> p1.product_name;
		cout << "Enter Product Price : ";
		cin >> p1.price;
		cout << "Enter Product Quantity : ";
		cin >> p1.quantity;
		cout << "Enter Product Category : ";
		cin >> p1.category;
		cout << "Enter Product Material : ";
		cin >> p1.material;
		if (p1.quantity > 0) {
			p1.availability = "Yes";
		}
		else {
			p1.availability = "No";
		}
		request[p1.product_id]=p1;
	}
	void update_count(int id,int  ct) {
		auto dummy = &all[id];
		dummy->quantity += ct;
	}
};
const int super_pass = 10540;
class admin {
public:
	int admin_id;
	int admin_pass;
	void view_request() {
		for (auto i : request) {
			auto k = i.second;
			cout << "Product Id : " <<  k.product_id << endl;
			cout << "Product Name : " << k.product_name << endl;
			cout << "Product Price : " << k.price << endl;
			cout << "Product Quantity : " << k.quantity << endl;
			cout << "Product Category : " << k.category << endl;
			cout << "Product Material : " << k.material << endl;
			cout << "-----------------------------------------------------" << endl;
		}
	}
	void approve(int req_id) {
		all[req_id] = request[req_id];
		request.erase(req_id);	
		cout << "Product Added Successfully" << endl;
	}
	void show_purchases() {
		for (int ik = 0;ik<os.size();ik++) {
			auto i = os[ik];
			auto j = i.det;
			cout << "Order ID : " << ik + 1 << endl;
			cout << "Total Amount : " << i.tot << endl;
			for (auto g : j) {
				cout << g.first << g.second << endl;
			}
		}
	}
};

class cart {
public:
	map<int, product> tm;
	long total_amnt=0;
}mine;


class customer {
public:
	int usrid=os.size();
	void add_product(int prid,int q) {
		if (all[prid].quantity > 0) {
			mine.tm[prid] = all[prid];
			mine.tm[prid].quantity = q;
			mine.total_amnt += all[prid].price;
			cout << mine.tm[prid].product_name << " added to the cart" << endl;
			all[prid].quantity -= q;
			if (all[prid].quantity <= 0) {
				all[prid].availability = "No";
			}
		}
		else {
			cout << "Product unavailable" << endl;
		}
	}
	void remove_product(int prid) {
		mine.tm.erase(prid);
		mine.total_amnt -= mp[prid].price;
	}
	void view_cart() {
		//cout << mine.tm.size() << endl;
		for (auto y : mine.tm) {
			cout << y.second.product_name<<"-----" << y.second.price << endl;
		}
		cout << "Total Price : " << mine.total_amnt;
	}
	void empty_cart() {
		mine.tm.empty();
	}
	void purcharse() {
		int o;
		cout << "Enter mode of payment from below " <<endl;
		cout << "1.Cash On Delivery" << endl << "2.Mobile Banking" << endl << "3.Net Banking" << endl << "4.Quit";
		cin >> o;
		string sx;
		bool b = false;
		switch (o) {
		case 1:
		{
			cout << "Oder Placed Successfully" << endl;
			cout << "-----------------------------------------------------" << endl;
			sx = "Cash on delivery";
			b = true;
			break;
		}
		case 2:
		{
			cout << "Transcation Completed Successfully" << endl;
			cout << "Oder Placed Successfully" << endl;
			cout << "-----------------------------------------------------" << endl;
			sx = "Mobile banking";
			b = true;
			break;
		}
		case 3:
		{
			cout << "Transcation Completed Successfully" << endl;
			cout << "Oder Placed Successfully" << endl;
			cout << "-----------------------------------------------------" << endl;
			sx = "Net Banking";
			b = true;
			break;
		}
		case 4:
		{
			cout << "-----------------------------------------------------" << endl;
			return;
		}
		default:
		{
			cout << "Invalid option" << endl;
			cout << "-----------------------------------------------------" << endl;
		}
		}
		if (b) {
			orders o;
			o.tot = mine.total_amnt;
			map<int, product>::iterator it;
			for (it = mine.tm.begin(); it != mine.tm.end(); it++) {
				product k = it->second;
				o.det["User ID : "] = to_string(usrid);
				o.det["Product Name : "] = k.product_name;
				o.det["Product Price : "] = to_string(k.price);
				o.det["Product Quantity : "] = to_string(k.quantity);
				os.push_back(o);
			}
			mine.tm.empty();
			mine.total_amnt = 0;
		}
	}
	void view_product() {
		for (auto y : all) {
			auto k = y.second;
			cout << "Product Id : " << k.product_id << endl;
			cout << "Product Name : " << k.product_name << endl;
			cout << "Product Price : " << k.price << endl;
			cout << "Product Quantity : " << k.quantity << endl;
			cout << "Product Category : " << k.category << endl;
			cout << "Product Material : " << k.material << endl;
			cout << "Product Availability : " << k.availability << endl;
			cout << "Product Rating : " << k.rating << endl;
			cout << "-----------------------------------------------------" << endl;
		}
	}
};

int main()
{
	product i1, i2, i3, i4, i5, i6, i7;
	i1.addnew(11, 2000, 100, 5, "Casio-Analog-1", "Steel", "Yes", "Watches");
	i2.addnew(22, 7000, 10, 4.5, "Fossil-Digital-1", "Silica", "Yes", "Watches");
	i3.addnew(33, 350, 0, 3, "TupperWare-Bottle", "PET", "No", "Containers");
	i4.addnew(44, 780, 30, 4, "EuroGames-Mouse", "Plastic", "Yes", "Gadgets");
	i5.addnew(55, 2500, 80, 3.5, "WoodLand-Sandals-1", "Leather", "Yes", "Footwears");
	i6.addnew(66, 590, 35, 5, "Sirt-Buttons", "Plastic", "Yes", "Fassion");
	i7.addnew(77, 120, 300, 2, "Sensodyne-Brush", "Silica", "Yes", "Daily");
	all[i1.product_id] = i1;
	all[i2.product_id] = i2;
	all[i3.product_id] = i3;
	all[i4.product_id] = i4;
	all[i5.product_id] = i5;
	all[i6.product_id] = i6;
	all[i7.product_id] = i7;
	bool b = true;
	cout << "WELCOME TO H-CART" << endl;
	while (b) {
		cout << "select your role : " << endl;
		cout << "1.Customer" << endl << "2.Seller" << endl << "3.Admin" << endl << "4.Quit" << endl;
		int h;
		cin >> h;
		switch (h)
		{
		case 1:
		{
			int inop;
			cout << "What do you want to do ?" << endl;
			cout << "1.View Products" << endl << "2.Add Product To Cart" << endl << "3.View Cart" << endl << "4.Remove Product" << endl << "5.Empty Cart" << endl << "6.Purchase" << endl << "7.Quit" << endl;
			cin >> inop;
			customer c1;
			switch (inop) {
			case 1:
			{
				c1.view_product();
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			case 2:
			{
				int pdi, qy;
				cout << "Enter the product id : ";
				cin >> pdi;
				cout << "Enter the quantity : ";
				cin >> qy;
				c1.add_product(pdi, qy);
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			case 3:
			{
				c1.view_cart();
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			case 4:
			{
				int pr;
				cout << "Enter product id to remove : ";
				cin >> pr;
				c1.remove_product(pr);
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			case 5:
			{
				c1.empty_cart();
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			case 6:
			{
				c1.purcharse();
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			case 7:
			{
				b = false;
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			default :
			{
				cout << "Enter valid input" << endl;
				cout << "-----------------------------------------------------" << endl;
			}
			}
			break;
		}
		case 2:
		{
			cout << "Hi Seller" << endl;
			cout << "What operation to perform : " << endl;
			cout << "1.Request addition of product" << endl << "2.Update product cout" << endl << "3.Quit" << endl;
			int hop;
			cin >> hop;
			seller s1;
			switch (hop)
			{
			case 1:
			{
				s1.add_product();
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			case 2:
			{
				int hpd,hq;
				cout << "Enter product id : ";
				cin >> hpd;
				cout << "Enter quantity to add : ";
				cin >> hq;
				s1.update_count(hpd, hq);
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			case 3:
			{
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			default:
				cout << "Enter valid input" << endl;
				cout << "-----------------------------------------------------" << endl;
			}
			break;
		}
		case 3:
		{
			int an;
			cout << "Heloo Admin" << endl;
			cout << "Enter operation to perform : " << endl;
			cout << "1.View Product Request" << endl << "2.Aprove Product Request" << endl << "3.View Purchases" << endl << "4.Quit" << endl;
			cin >> an;
			admin a1;
			switch(an){
			case 1:
			{
				a1.view_request();
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			case 2:
			{
				int apid;
				cout << "Enter request id : ";
				cin >> apid;
				a1.approve(apid);
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			case 3:
			{
				a1.show_purchases();
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			case 4:
			{
				cout << "-----------------------------------------------------" << endl;
				break;
			}
			default:
			{
				cout << "Enter valid input" << endl;
				cout << "-----------------------------------------------------" << endl;
			}
			}
			break;
		}
		case 4:
		{
			b = false;
			break;
		}
		default:
			cout << "Enter valid input" << endl;
			cout << "-----------------------------------------------------" << endl;
			break;
		}
	}
}
