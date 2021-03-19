package ExpressionTree;

public class ValueNode implements TreeNode {
   double value;

   
   /*
   * Constructor for value node sets the value stored in the node n the variable "value"
   */
   public ValueNode(double value){
       this.value = value;
   }

   
   /*
   * outputs tabs for the spacing of the tree according to its depth "i" amount of times
   * and prints out the value that was previously stored in the valueNode class
   */
   public void print(int depth) {
       for(int i =0; i<depth; i++){
           System.out.print("\t");
       }
       System.out.println(value);

   }
/*
* evaluate function that returns the value after being called
*/
   @Override
   public double evaluate() {
       return value;
   }

}