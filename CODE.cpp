#include<iostream>
#include<conio.h>
#include<string>
#include<list>
using namespace std;

//The hash table hashes a string key and stores an integer value at the hashed location in the table
class HTable
{
    list< pair<string,int> > table[127];

    public:
        int hash(string);
        void add(string,int);
        void find(string);
        void remove(string);
        void modify(string);
};

//hashes the string and returns the index value to store in the table
int HTable::hash(string str)
{
    int n=str.size();
    int sum=0,val,index;
    for(int i=0;i<n;i++)
    {
        val=(int)str[i];
        sum+=val<<4;
    }
    index=sum%127;
    return index;
}

//adds the index value to the table after hashing the string key
void HTable::add(string str,int id)
{
    int index=hash(str);
    table[index].push_back(make_pair(str,id));
}

//searches for the given string key in the table
void HTable::find(string str)
{
    int id=hash(str);
    list< pair<string,int> >::iterator itr=table[id].begin();
    if(!table[id].empty())
    {
        while(itr!=table[id].end())
        {
            if( (*itr).first==str )
                cout<<"String : "<<(*itr).first<<" ID : "<<(*itr).second<<endl;
            itr++;
        }
    }
    else
    cout<<"No data found\n";
    system("pause");
}

//removing an entry from the hashtable
void HTable::remove(string str)
{
    int id=hash(str);
    list< pair<string,int> >::iterator itr=table[id].begin();
    if(!table[id].empty())
    {
        while(itr!=table[id].end())
        {
            if( (*itr).first==str )
            {
                char ch;
                cout<<"Element found: \n";
                cout<<(*itr).first<<" "<<(*itr).second<<endl;
                cout<<"confirm deletion? (y/n)";
                cin>>ch;
                if(ch=='y'||ch=='Y')
                {
                    table[id].erase(itr);
                    break;
                }
            }
            itr++;
        }
    }
    else
    cout<<"No data found\n";
    system("pause");
}

//modifies the id of the pair
void HTable::modify(string str)
{
    int id=hash(str);
    list< pair<string,int> >::iterator itr=table[id].begin();
    if(!table[id].empty())
    {
        while(itr!=table[id].end())
        {
            if( (*itr).first==str )
            {
                char ch;
                cout<<"Element found: \n";
                cout<<(*itr).first<<" "<<(*itr).second<<endl;
                cout<<"confirm modification? (y/n)";
                cin>>ch;
                if(ch=='y'||ch=='Y')
                {
                    int t;
                    cout<<"Enter new id: ";
                    cin>>t;
                    (*itr).second=t;
                    break;
                }
            }
            itr++;
        }
    }
    else
    cout<<"No data found\n";
    system("pause");
}
int main()
{
    HTable ht;
    int choice,id;
    string str;
    while(true)
    {
        cout<<"1. Add\n";
        cout<<"2. Find\n";
        cout<<"3. Remove\n";
        cout<<"4. Modify\n";
        cout<<"5. Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter string\n";
                fflush(stdin);
                getline(cin,str);
                cout<<"Enter id\n";
                cin>>id;

                //conversion to lower case to avoid case sensitivity
                for(int i=0;i<str.size();i++)
                str[i]=tolower(str[i]);

                //adding to the hashtable
                ht.add(str,id);
                break;
            case 2:
                cout<<"Enter string to find\n";
                fflush(stdin);
                getline(cin,str);

                //conversion to lower case
                for(int i=0;i<str.size();i++)
                str[i]=tolower(str[i]);

                ht.find(str);
                break;
            case 3:
                cout<<"Enter string to remove\n";
                fflush(stdin);
                getline(cin,str);

                //conversion to lower case
                for(int i=0;i<str.size();i++)
                str[i]=tolower(str[i]);

                ht.remove(str);
                break;
            case 4:
                cout<<"Enter string to modify\n";
                fflush(stdin);
                getline(cin,str);

                //conversion to lower case
                for(int i=0;i<str.size();i++)
                str[i]=tolower(str[i]);

                ht.modify(str);
                break;
            case 5:
                exit(0);
        }
        system("cls");
    }
    return 0;
}
