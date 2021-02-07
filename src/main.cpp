
#include <iostream>
#include <fstream>
#include "Node.h"
#include "CircularDoublyLinkedList.h"

using namespace std;

int getCountOfLists();
void cross(CircularDoublyLinkedList& max, CircularDoublyLinkedList& min);

int main(){

	string str;
	int sizeOfList;
	int countOfLists;
	int i, k,j=0;

	countOfLists = getCountOfLists();	

	ifstream readingFile;
	readingFile.open("../doc/Sayilar.txt");   // opening the file
	
	
	if(!readingFile.is_open()){       // error checking for file is not opened
       exit(-1);                      // exit the program
   }

   CircularDoublyLinkedList* cdll = new CircularDoublyLinkedList[countOfLists];

	int maxValue ;
	int indexOfMax ;
	int minValue ;
	int indexOfMin ;

   for(k = 0; k < countOfLists; k++){

	   	getline(readingFile, str);//read data from file object and put it into string.

	   		sizeOfList = 0;

	   		for(i=0; i<str.length(); i++){
	   			if(str[i] == ' '){
	   				sizeOfList++;
	   			}           
	   		}

	   		sizeOfList++;
	        cdll[k].setSizeOfList(sizeOfList);      
	        int *arrayNumbers = new int[sizeOfList];

	        for(int i = 0; i < sizeOfList; i++)
	        	arrayNumbers[i] = 0;

	        for (i = 0; i<str.length(); i++) { 

	        	if (str[i] == ' '){ 	               
	        		j++; 
	        	} 
	        	else { 

	               // subtract str[i] by 48 to convert it to int 
	               // Generate number by multiplying 10 and adding 
	               // (int)(str[i]) 
	        		arrayNumbers[j] = arrayNumbers[j] * 10 + (str[i] - 48); 
	        	} 
	        } 	       	

	        cdll[k].Add(arrayNumbers);   

	        if(k==0){
	        	maxValue = cdll[0].MiddleData();
				indexOfMax = 0;
				minValue = cdll[0].MiddleData();
				indexOfMin = 0;
	        }

	        else{

		        if(cdll[k].MiddleData() > maxValue){
		        	maxValue = cdll[k].MiddleData();
		        	indexOfMax = k; 
		        }

		        if(cdll[k].MiddleData() < minValue){
		        	minValue = cdll[k].MiddleData();
		        	indexOfMin = k; 
		        }

	    	}

	        delete [] arrayNumbers;   

	        j=0;     
	    
	}    	

	cross(cdll[indexOfMax], cdll[indexOfMin]);

	cout << "En buyuk liste orta dugum adres: " ;
	cout << &cdll[indexOfMax] << endl;
	cout << "En buyuk liste degerler: " << endl;
	cdll[indexOfMax].printList() ;
	

	cout << endl << endl;

	cout << "En kucuk liste orta dugum adres: " ;
	cout << &cdll[indexOfMin] << endl;
	cout << "En kucuk liste degerler: " << endl;
	cdll[indexOfMin].printList();
	
	cout << endl;
	
   	readingFile.close();  // closing the opened file

   	
   	return 0;
}

int getCountOfLists(){

   	int i;
   	int countOfLists = 0;

   	ifstream readingFile;
    readingFile.open("../doc/Sayilar.txt");   // opening the file
    string str;
    while(getline(readingFile, str)){ //read data from file object and put it into string.      

    	countOfLists++;
    	
    }  

    readingFile.close();  // closing the opened file

    return countOfLists;
}

void cross(CircularDoublyLinkedList &max, CircularDoublyLinkedList &min){

	int i;
	int tempSize;

	int sizeOfMax = max.getSizeOfList();
	int sizeOfMin = min.getSizeOfList();

	Node* leftOfMax = max.getMiddleOfList()->prev;
	Node* rightOfMax = max.getMiddleOfList()->next;

	Node* maxCopy = new Node();	
	Node* maxWalker = maxCopy;		
	Node* maxWalkerR = maxCopy;

	for(i=0; i<(sizeOfMax-1)/2; i++){

		Node* t = new Node();
        t->data = leftOfMax->data;
        maxWalker->next = t;

        Node* t2 = new Node();
        t2->data = rightOfMax->data;
        maxWalkerR->prev = t2;

        leftOfMax = leftOfMax->prev;
        rightOfMax = rightOfMax->next;

        maxWalker=maxWalker->next;
        maxWalkerR = maxWalkerR->prev;

	}

	Node* rightOfMin = min.getMiddleOfList()->next;
	Node* leftOfMin = min.getMiddleOfList()->prev;


	Node* minCopy = new Node();	
	Node* minWalker = minCopy;	
	Node* minWalkerR = minCopy;

	for(i=0; i<(sizeOfMin-1)/2; i++){

		Node* t = new Node();
        t->data = rightOfMin->data;
        minWalker->prev = t;

        Node* t2 = new Node();
        t2->data = leftOfMin->data;
        minWalkerR->next = t2;

        rightOfMin = rightOfMin->next;
        leftOfMin = leftOfMin->prev;

        minWalker=minWalker->prev;
        minWalkerR = minWalkerR->next; 

	}

	
	//after coppies, we delete the originals
	Node* temp = max.getMiddleOfList()->next;
	Node* temp1 = max.getMiddleOfList()->prev;

	Node* temp2 = temp->next;
	Node* temp3 = temp1->prev;

	for(i=0; i<(sizeOfMax-1)/2; i++){
		delete temp;
		delete temp1;

		temp = temp2;
		temp1 = temp3;

		temp2 = temp2->next;
		temp3 = temp3->prev;
	}


	maxWalker = maxCopy;  	//this goes to next...
	maxWalkerR = maxCopy;	//this goes to prev...

	temp = maxWalker;		//maxWalker için bağlama...
	maxWalker = maxWalker->next;

	temp1 = maxWalkerR;		//maxWalkerR için bağlama...
	maxWalkerR = maxWalkerR->prev; 

	for(i=0; i<(sizeOfMax-1)/2; i++){
		maxWalker->prev = temp;
		temp = temp->next;
		maxWalker = maxWalker->next;	

		maxWalkerR->next = temp1;
		temp1 = temp1->prev;
		maxWalkerR = maxWalkerR->prev;	
		
	}

	minWalker = minCopy;
	minWalkerR = minCopy;

	temp = minWalker;
	minWalker = minWalker->next;

	temp1 = minWalkerR;
	minWalkerR = minWalkerR->prev; 

	for(i=0; i<(sizeOfMin-1)/2; i++){

		minWalker->prev = temp;
		temp = temp->next;
		minWalker = minWalker->next;	

		minWalkerR->next = temp1;
		temp1 = temp1->prev;
		minWalkerR = minWalkerR->prev;	
		
	}

	max.getMiddleOfList()->next = minCopy->next;
	max.getMiddleOfList()->prev = minCopy->prev;
	minCopy->next->prev = max.getMiddleOfList();
	minCopy->prev->next = max.getMiddleOfList();

	min.getMiddleOfList()->next = maxCopy->next;
	min.getMiddleOfList()->prev = maxCopy->prev;
	maxCopy->next->prev = min.getMiddleOfList();
	maxCopy->prev->next = min.getMiddleOfList();

	min.setSizeOfList(sizeOfMax);
	max.setSizeOfList(sizeOfMin);

}