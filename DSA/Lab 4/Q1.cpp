#include<iostream>
#include<unistd.h>
#include<vector>
using namespace std;


class Queue{

 public:

  int rear, front, size;
  vector<int> qu;

Queue(){

  rear = -1;
  front = 0;
  
  cout << "Enter the maximum size for the queue." << endl;
  cin >> size;
  
  qu.resize(size);

}


void makeEmpty(){

  rear =-1;
  front = 0;
  
  cout << "The queue has been made empty." << endl;

}

bool isFull(){

   if(rear == size-1){
      return true;
   }else{
       return false;
	 }
}


bool isEmpty(){

    if(front > rear){
	   return true;
	}else{ 
	return false;
	}
}

  void enqueue(){
  
     if(!isFull()){
	    ++rear;
	    int choice;
	    cout << "Enter the element to be placed in the queue." << endl;
	    cin >> choice;
	    qu[rear] = choice;
	    cout << "Element has been placed in the Queue." << endl;
	 }else{
	     cout << "Queue is full."  << endl;
	   }
  }


  
   void dequeue(){
  
       if(!isEmpty()){	   
	       if(rear >= front){ 
		       cout << qu[front] << " ";
			     ++front;
		}
		cout<< endl;
	   }else{ 
	    cout << "Queue is empty." << endl; 
		}
  
  }

  void traverse(){
     
        for(int i=front; i<size; ++i){
		
		   cout << qu[i] << " ";
		
		}
       cout << endl;
  }


};


int main(){
	
	 	 Queue q1;
	 
	 
	 char ch = 'A', choice;
	 
	 while(ch == 'A' || ch == 'a'){
	 

	       cout << "A. Make Queue Empty." << endl;
	       cout << "B. Is Queue full?" << endl;
	       cout << "C. Is Queue empty?" << endl;
	       cout << "D. Enqueue " << endl;
	       cout << "E. Dequeue " << endl;
	       cout << "F. Traverse elements of Queue. " << endl;

        cin >> choice;
	 
	 
	 
	      switch(choice){
		  
		  
		     case 'A':
		     case 'a':
		     {
			     q1.makeEmpty();
			     sleep(2);
			     system("CLS");
			     break;
			     
			 }
			 
			 
			 case 'B':
			 case 'b':
			 {
			    if(q1.isFull()){
				   cout << "Queue is full." << endl;
				 }else{
				    cout << "You can add elements in the Queue." << endl;
				  }
				  
				  sleep(2);
				  system("CLS");
				  break;
			 }
		  
		     case 'C':
		     case 'c':
		     {
			 
			     if(q1.isEmpty()){
				    cout << "Queue is empty." << endl;
				 }else{ 
				   cout << "Queue is not empty." << endl;
				 }
				 sleep(2);
				 system("CLS");
				 break;
			 }
			 
			 
			 case 'D':
			 case 'd':
			 {
			    q1.enqueue();
			    sleep(2);
			    system("CLS");
			     break;
			 }
			 
			 
			 case 'E':
			 case 'e':
			 {
			   q1.dequeue();
			   sleep(2);
			   system("CLS");
			   break;
			 }
		  
		  
		     case 'F':
		     case 'f':
		     {
			     q1.traverse();
                 sleep(2);
                 system("CLS");
			     break;
			 }
			 
			  default:
			   cout << "Enter a valid choice " << endl;
			   break;
		  }
	 
	    cout << "Do you want to continue?" << endl;
        cout << "A. Yes" <<endl;
        cout << "B. No" << endl;
	    cin >> ch;
	    
	    system("CLS");
	 

	 }
	
	return 0;
}
