#include "List.h"

void List::print() const
{
    cout << "[ ";
    ListNode* tmp = head;
    while(tmp!=nullptr)
    {
        tmp->data->print();
        cout << " ";
        tmp = tmp->next;
    }
    cout << " ]" << endl;
}

ostream& operator<< (ostream& os, const List& list)
{
    list.print();
    return os;
}

List& List::insert(const Data& data, insertion val)
{
    Data* newdata = data.clone();
    if (val == List::End && head!=nullptr)
    {
        ListNode* tmp = head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new ListNode(newdata, nullptr);
    }
    else
        head = new ListNode (newdata, head);
    
    return *this;
}

List::~List()
{
    clear();
}

List::List(): head(nullptr)
{}

List::ListNode* List::copyList(List::ListNode* otherlist)
{
    List::ListNode* head_ = nullptr;

    if (otherlist)
    {
        Data* cloned = otherlist->data->clone();
        head_ = new ListNode (cloned, nullptr);
        ListNode* nxt = otherlist->next;
        ListNode* tmp = head_;
        
        while (nxt)
        {
            cloned = nxt->data->clone();
            ListNode* newnode = new ListNode (cloned, nullptr);
            tmp->next = newnode;
            tmp = tmp->next;
            nxt=nxt->next;
        }
    }
    return head_;
}

List::List(const List& other)
{
    head = List::copyList(other.head);
}

List& List::operator= (const List& other)
{
   if (this!=&other)
   {
    clear();
    head = List::copyList(other.head);
   }
   return *this;
}

void List::clear()
{
     while (head!=nullptr)
    {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }
}

List::ListNode::~ListNode()
{
  delete data;
}

List::ListNode::ListNode(Data* d, ListNode* n): data(d), next(n)
{}

List& List::reverse()
{
    ListNode* tmp = head;
    ListNode* nxt = nullptr;
    ListNode* prev = nullptr;
    while (tmp)
    {
        nxt = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp=nxt;
    }
    head=prev;
    return *this;
}

Data* List::find(const Data& data) const
{
    ListNode* tmp = head;
    //Data* result = nullptr;
   
    while (tmp)
    {
        if (tmp->data->check(data))
            return tmp->data;
        tmp = tmp->next;
    }
    return nullptr;
}

vector<double> List::eval() const
{
    vector<double> wektor;
    ListNode* tmp = head;
    while(tmp)
    {
        wektor.push_back(tmp->data->eval());
        tmp=tmp->next;
    }
    return wektor;
}

List List::copy_if(bool flag) const
{
    List newlist;
    ListNode* tmp = head;
    while (tmp)
    {
        
        if (flag)
        {
            if ((dynamic_cast<StringData*>(tmp->data)!=nullptr) || (dynamic_cast<CharData*>(tmp->data)!=nullptr))
                newlist.insert(*(tmp->data));
        }
        else
        {
            if (dynamic_cast<Fraction*>(tmp->data)!=nullptr)
                newlist.insert(*(tmp->data));
        }
        tmp = tmp->next;
    }
    return newlist;
}


