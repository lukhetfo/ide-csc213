
package com.dube.csc213;

/**
 *
 * @author Enock Lukhetfo Dube  <eldube@uniswa.sz>
 */
public class LinkedListExample_Generic {

   //define node structure
   public static class Node<T> {
   T data;
   Node next; 

    public Node() {
    }

    public Node(T data, Node next) {
        this.data = data;
        this.next = next;
    }

    public Node(T data) {
        this.data = data;
        this.next = null;} 
}

    //define generic list
 public static class MyLinkedList<T> { 
 Node<T> head;

public  MyLinkedList() {head = null;}
 
public boolean IsEmpty () {return (head == null); }
public boolean IsFull () {return false; }
public void Insert (T e){
  Node<T> NewNode = new Node(e,head);
  head = NewNode;
}   

public void Delete (T e)
{  Node CurrNode = head;
   Node PrevNode = null;
 
    while ((CurrNode != null) && (CurrNode.data != e) ) {
     // searching for node to delete 
     PrevNode = CurrNode;
     CurrNode = CurrNode.next;  }  
     if ((CurrNode != null) && (CurrNode.data == e ))
     { 
          if  (PrevNode == null)  // deleting first node
              head = CurrNode.next;
         else
              PrevNode.next = CurrNode.next;
     }
}

public void ShowData ()
{   Node CurrNode = this.head;
    while ( CurrNode != null)  {                 
           System.out.print("\t" + CurrNode.data);                                 
           CurrNode = CurrNode.next;
     }  
    System.out.println();
}
 }
   
    public static void main(String[] args) {
        
       MyLinkedList<Integer> L = new MyLinkedList();
	
	L.Insert(10); L.Insert(15); L.Insert(20);
	L.ShowData();
	L.Delete(15);
	L.ShowData();
	L.Insert(30); L.Insert(50); L.Delete(10);
	L.ShowData();
    }
    
}
