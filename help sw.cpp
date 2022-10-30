///////////////////////////////////////////////////////////////////
//                  文件名：“你帮我助”物品交换软件                    //
//功能说明：可以实现添加物品的信息，删除物品的信息，显示物品列表，查找物品的信息//
//                         作者：赵鹏飞                            //
//                       日期：2022.10.3                          //
///////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

//物品交换表以类的形式实现，表中记录物品、物品数量
//物品以链表形式存储
class ItemList
{
private:
    struct Item
    {
        string userName, phoneNumber, itemName, itemWant;
        int itemQuantity;
        Item* next;
        Item(const string& uN, const string& pN, const string& iN,
             const string& iW, const int iQ, Item* p = NULL){
            userName = uN;
            phoneNumber = pN;
            itemName = iN;
            itemWant = iW;
            itemQuantity = iQ;
            next = p;
        }
        Item():next(NULL){}
        ~Item(){}
    };

    int itemNumber;
    Item* head;

public:
    ItemList(int initSize = 10){head = new Item; itemNumber = 0;}
    ~ItemList(){clear(); delete head;}
    void add_item(const string& uN, const string& pN, const string& iN,
                  const string& iW, int iQ);//添加物品功能，参数分别为物品持有人、电话、物品名称、想要交换的物品和持有物品数量。
    void delete_item(int number);//删除物品功能，参数为想要删除的物品的编号。
    void itemlist_display() const;//展示现有表格，新的物品在最上方，编号最大，旧的物品反之。
    void item_search(const string& iN) const;//查找物品功能，将展示所有与参数同名的物品，并给出记录数量。
    void clear();
};


void ItemList::add_item(const string& uN, const string& pN, const string& iN,
                        const string& iW, const int iQ) {
    Item* p = head;
    if(!p) return;
    Item* tmp = new Item(uN, pN, iN, iW, iQ, head->next);
    p->next = tmp;

    ++itemNumber;
}

void ItemList::delete_item(const int number) {
    Item* p = head;
    for(int i = 0; i < itemNumber-number; ++i) p = p->next;
    if(!p || !p->next) return;
    Item* tmp = p->next;
    p->next = tmp->next;
    delete tmp;

    --itemNumber;
}

void ItemList::itemlist_display() const {
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"|                                  Item List                                    |"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"| number |usernames|  phone numbers  |   item names   |   items want   |quantity|"<<endl;

    Item* p = head;
    if(!p) return;
    for(int i = itemNumber; i > 0; --i){
        p = p->next;
        cout<<"---------------------------------------------------------------------------------"<<endl;
        cout<<"| "<<i;
        cout<<" |  "<<p->userName;
        cout<<"  |   "<<p->phoneNumber;
        cout<<"   |   "<<p->itemName;
        cout<<"   |   "<<p->itemWant;
        cout<<"   | "<<p->itemQuantity;
        cout<<" |"<<endl;
    }
    cout<<"---------------------------------------------------------------------------------"<<endl;
}

void ItemList::item_search(const string& iN) const {
    Item* p = head->next;
    if(!p) return;
    int itemCount = 0;
    while(p){
        if(p->itemName == iN){
            cout<< "Item found:";
            cout<<"username:"<< p->userName <<"  ";
            cout<<"phone number:"<< p->phoneNumber <<"  ";
            cout<<"item quantity:"<< p->itemQuantity <<"  ";
            cout<<"items want:"<< p->itemWant <<endl;
            ++itemCount;
        }
        p = p->next;
    }
    cout<<itemCount<<" items found."<<endl;
}

void ItemList::clear() {
    Item* p = head->next;
    if(!p) return;
    head->next = NULL;
    while(p){
        Item* q = p->next;
        delete p;
        p = q;
    }
}

/*
int main()
{
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"|                           Welcome to 'HELPS'!                          |"<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;

    ItemList a;
    string uN, pN, iN, iW, itemname;
    int iQ, delnumber;

    //实现功能页面循环展示，直至退出系统、删除表格
    while(true) {
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "|                         Please select a function:                      |" << endl;
        cout << "|              1:add an item  2:delete an item  3:display all            |" << endl;
        cout << "|             4:search for an item  5:exit and delete the list           |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;

        int func;
        cin >> func;
        if (func == 5) break;

        switch (func) {
            case 1:
                cout << "Please input the information listed in order, using space to separate:";
                cout << "User's name, User's phone number, Item names, Items want, Item quantity:" << endl;
                cin >> uN >> pN >> iN >> iW >> iQ;
                a.add_item(uN, pN, iN, iW, iQ);
                break;
            case 2:
                cout << "Please input the number of the item you want to delete";
                cout << "(tip:you'd better confirm the number by using function 3 first):" << endl;
                cin >> delnumber;
                a.delete_item(delnumber);
                break;
            case 3:
                a.itemlist_display();
                break;
            case 4:
                cout << "Please input the item you want to search:" << endl;
                cin >> itemname;
                a.item_search(itemname);
                break;
            default:
                cout << "Invalid choice, please input again:" << endl;
                break;
        }
    }
    cout<<"Exit successfully, have a great day!"<<endl;
    return 0;
}
 */