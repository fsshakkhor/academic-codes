#include<bits/stdc++.h>

using namespace std;

char char_customer = 'A';
char char_menu = 'a';
class Menu{
    string name;
    long long itemid;
    float price;
public:
    Menu(){
        name = char_menu++;
        itemid = rand()%100;
        float price = (10* (rand()%10) ) + 10;
    }
    Menu(string _name,long long _item,float _price){
        name = _name;
        itemid = _item;
        price = _price;
        cout << "Menu Created\n\tName: " << name << "\n\tItemid: " << itemid << "\n\tprice: " << price<< endl;
    }
    set_name(string s){
        name = s;
    }
    set_itemid(long long _cr){
        itemid = _cr;
    }
    set_price(float _price){
        price = _price;
    }
    string get_name(){
        return name;
    }
    long long get_itemid(){
        return itemid;
    }
    float get_price(){
        return price;
    }
    void set_all(string _name,long long _item,float _price){
        name = _name;
        itemid = _item;
        price = _price;
    }
};
Menu menu[5];

class Order{
    int no;
public:
    Menu order[5];
    void get_order(){
        cout << "Enter The Number of Orders : ";
        cin >> no;
        for(int i = 0;i<5;i++)cout << i+1 << ": " << menu[i].get_name() << "\tID: " << menu[i].get_itemid() << "\tBill: " << menu[i].get_price() << endl << endl;
        for(int i =0;i<no;i++){
            int id;
            cin >> id;
            for(int j = 0;j<5;j++){
                if(id==menu[j].get_itemid()){
                    order[i] = menu[j];
                    break;
                }
            }
        }
    }
    int get_no(){
        return no;
    }

};

class Customer{
    string name;
    long long credit_no;
    float bill;
    Order order;
public:
    Customer(){
        name = char_customer++;
        credit_no = rand()%1000;
        bill=0;
    }
    Customer(string _name,long long _cr,float _bill){
        name = _name;
        credit_no = _cr;
        bill=_bill;
        cout << "Customer Created\n\tName: " << name << endl;
        cout << "\tCredit_No: " << credit_no << endl;
        cout << "\tBill: " << bill << endl;
    }
    ~Customer(){
        cout << "Customer " << name << " Going out with bill " << bill << " taka\n\n\n";
    }
    set_name(string s){
        name = s;
    }
    set_credit_no(long long _cr){
        credit_no = _cr;
    }
    set_bill(float _bill){
        bill = _bill;
    }
    string get_name(){
        return name;
    }
    long long get_credit_no(){
        return credit_no;
    }
    float get_bill(){
        return bill;
    }
    void set_all(string _name,long long _cr,float _bill){
        name = _name;
        credit_no = _cr;
        bill=_bill;
    }
    void get_order(){
        cout << "Taking Orders For Customer : " << name << endl << endl;
        Order od; od.get_order();
        order = od;
    }
    Order pass_order(){
        return order;
    }
};

Customer cus[3];

class Service{
public:
    void CalculateBill(Customer *A){
        Order X = A->pass_order();
        float tot = 0;
        for(int i = 0;i<X.get_no();i++){
            tot += X.order[i].get_price();
        }
        A->set_bill(tot);
    }
};
int main()
{

    cus[0].set_all("Ahsan",1001,0);
    cus[1].set_all("Malik",1002,0);
    cus[2].set_all("Fardin",1003,0);

    menu[0].set_all("Pizza",11,70);
    menu[1].set_all("Burger",12,50);
    menu[2].set_all("Noodles",13,20);
    menu[3].set_all("Bread",14,10);
    menu[4].set_all("Set Menu",15,100);

    Service Manager;
    for(int c = 0;c<3;c++){
        Customer temp = cus[c];
        temp.get_order();

        Manager.CalculateBill(&temp);
    }
}
