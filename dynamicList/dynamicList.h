#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include <iostream>

using namespace std;

struct listItem{
   int item;
   listItem *next;
};

class dynamicList
{
    public:
        dynamicList();
        void insertItemDesc(int item); //Insert an item in a descending manner (buyukten kucuge dogru eleman ekleme)
        void insertItemAsc(int givenItem); //Insert an item in an ascending manner (kucukten buyuge dogru eleman ekleme)
        void removeItem(int givenItem); //remove the items with the given value. (verilen degerdeki butun elemanlari sil)
        listItem* searchItem(int givenItem); //find the first occurance of the item. item ile verilen ilk degeri listede bul.
        void printList();
        virtual ~dynamicList();

    protected:

    private:
        void removeList(); //remove the entire list (butun listeyi sil)
        listItem *listHead;
};

dynamicList::dynamicList()
{
    listHead = NULL;
    //ctor
}

void dynamicList::insertItemDesc(int item){

   if(listHead == NULL) {
     listHead = new listItem;
     listHead->item = item;
     listHead->next = NULL;

   } else {
      listItem *newItem = new listItem;
      newItem->item = item;

      listItem *currentListItem = listHead;
      if(currentListItem->next == NULL) { //we have one item in the list
         if(currentListItem->item < item){
            newItem->next = currentListItem;
            listHead = newItem;
         } else {
             currentListItem->next = newItem;
         }
         return;
      }

      //Move the currentItem pointer until the correct item is found
      //currentItem pointeri dogru noktaya tasi
      while(currentListItem->next != NULL && currentListItem->next->item > item ){
        currentListItem = currentListItem->next;
      }

      //Eger hala liste basindaysan liste basina ekle ve liste basi pinterini guncelle
      if(currentListItem->item <= item && currentListItem == listHead){
        newItem->next = currentListItem;
        listHead = newItem;
      } else{
        if(currentListItem->next != NULL){//Check if we are at the end of the list, if not insert in the middle.
           newItem->next = currentListItem->next;
        }
        currentListItem->next = newItem;
      }
   }
}

void dynamicList::insertItemAsc(int givenItem){
    listItem* temp = new listItem;
    temp->item = givenItem;
    if(this->listHead == NULL){
        temp->next = NULL;
        this->listHead = temp;
    } else {
        listItem* currentItem = this->listHead;

        if(currentItem->next == NULL){ // listede tek item varsa
            if(currentItem->item > givenItem) {
                temp->next = this->listHead;
                this->listHead = temp;
            } else {
                this->listHead->next = temp;
                temp->next = NULL;
            }
            return;
        }

        while((currentItem->next != NULL) && (givenItem > currentItem->next->item)){ //kendinden daha buyuk bir sayi bulana kadar ilerle
            currentItem = currentItem->next;
        }

        if(this->listHead == currentItem && givenItem < this->listHead->item){ //ilerleyememissen head pointerini yeni item'e ata
            temp->next = this->listHead;
            this->listHead = temp;
        } else {
            temp->next = currentItem->next;
            currentItem->next = temp;
        }
    }
    
}

void dynamicList::removeItem(int givenItem){
    listItem* currentItem = this->listHead;
    while(currentItem->next != NULL){
        if(currentItem->next->item == givenItem){
            listItem* temp = currentItem->next->next;
            delete currentItem->next;
            currentItem->next = temp;
            return;
        }
        currentItem = currentItem->next;
    }
}

listItem* dynamicList::searchItem(int givenItem){
    listItem* currentItem = this->listHead;
    while(currentItem->next != NULL){
        if(currentItem->next->item == givenItem){
            return currentItem->next;
        }
        currentItem = currentItem->next;
    }
}

void dynamicList::printList(){
    listItem* currentItem = this->listHead;
    while(currentItem != NULL){
        cout << currentItem->item << endl;
        currentItem = currentItem->next;
    }
}

void dynamicList::removeList(){
    listItem* currentItem = this->listHead;
    while(currentItem->next != NULL){
        currentItem = this->listHead->next;
        delete listHead;
        listHead = currentItem;
    }
}

dynamicList::~dynamicList()
{
    removeList();   
    //Butun listeyi sil Burada!!!
    //dtor
}

#endif // DYNAMICLIST_H
