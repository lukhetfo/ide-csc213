
package com.dube.csc213;

/**
 *
 * @author Enock Lukhetfo Dube  <eldube@uniswa.sz>
 */
public class ComplexNumbersExample {

   public  static class  Complex {

	private float x;     //real part
	private float y;     //imaginary part

        public Complex() {}
	public Complex(float xp, float yp) { x = xp; y = yp; }
	public float Re() { return x; }
	public float Im() { return y; }


	//Java does not support operator overloading 
        //use methods instead
	public Complex add  (Complex Z)
	{
		x = x + Z.Re();
		y = y + Z.Im();
		return this;
	}

	public Complex multiply (Complex Z)
	{
		float temp = x;
		x = x * Z.Re() - y * Z.Im();
		y = temp * Z.Im() + y * Z.Re();
		return this;
	}
        
        //Java uses print/println method to write output
        // over-ride toString() method to use print/println for Complex numbers

        @Override
        public String toString() {
            return x + " + " + y + 'i';
        }   
     }
   
    public static void main(String[] args) {
        Complex Z1 = new Complex (5,10);
        Complex Z2 = new Complex(4,5);

        System.out.println(Z1);
        System.out.println(Z2);
        
        Z1.add(Z2);
        System.out.println(Z1);
        
        Complex Z3 = new Complex (5,10);
        Z3.multiply(Z2);
        System.out.println(Z3);    
    }
    
}
