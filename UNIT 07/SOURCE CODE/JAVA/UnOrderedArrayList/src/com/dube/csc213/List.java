
package com.dube.csc213;

/**
 *
 * @author Enock Lukhetfo Dube <lukhetfomzomba@gmail.com>
 */

public  class List { 
        
    int maxsize = 15;
    private int size;
    private int[] Item;

    public List () { 
        this.size = 0;
        this.Item = new int[maxsize];    
    }
   
   public int GetSize () { return size; }
   public boolean IsEmpty () { return size==0;}
   
 
   public boolean IsFull () {
       return (this.size == maxsize); 
   }
   
 
   public void Insert (int e)
   {
     if (!(this.IsFull()))
     {    this.Item[this.size] = e;
          this.size++;
     }
   }
 
   
   private void Swap (int i, int j)
   {                                
      int Temp = this.Item[i];
      this.Item[i] = this.Item[j];
      this.Item[j] = Temp;
    } 
   
 
   public void Delete (int e)
    { 
      int index = 0;    
    if  (!(this.IsEmpty()))
      {
        while ((index  < this.size) && (this.Item[index] != e) )
           index++;
        if ((this.Item[index] == e) && (index  <= this.size-1))
        {  
         Swap (index, this.size-1);
            
         this.size--;
        }
      }
    }
  
    public void ShowData ()
    { for (int index = 0; index < this.size; index++)
        System.out.format("%d\t", this.Item[index]);
      //System.out.println();   
    }   
  }

