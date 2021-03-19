package ExpressionTree;

public class OpNode implements TreeNode{
//declaring variables
   String operation;
   TreeNode left;
   TreeNode right;
  /*
  * this is my op node constructor that declares the operations, the right side and the left side and stores
  * them into their values in this class accordingly to be later used
  */
   public OpNode(TreeNode left,String operation,TreeNode right){
       this.left = left;
       this.operation = operation;
       this.right = right;
   }

   @Override
   /*
   * this is my print function that prints the operation after it goes throught its depth "i" amount of times
   * and outputs both the right and left values with the depth that is needed for each to sustain the shape of the tree
   */
   public void print(int depth) {
       //this prints the depth on the right side with one extra value
       right.print(depth+1);
       //this for loop runs through thre amount of times depth is and is what is used for the spacing of the tree
       for(int i =0; i<depth; i++){
           System.out.print("\t");
       }
       //printing the operation
       System.out.println(operation);

      //this prints the depth on the left side with one extra value
       left.print(depth+1);
    }

   @Override
   /*
   * this is my function that I use to evaluate the problem based on the operation
   * returns the value after the operation occurs to the left and right variables
   */
   public double evaluate() {
       double value = 0;
       //based on the type of operation it preforms the correct evaluation
       if(operation == "*"){
           value = right.evaluate() * left.evaluate();
       }else if(operation == "+"){
           value = right.evaluate() + left.evaluate();
       }else if(operation == "-"){
           value = left.evaluate() - right.evaluate();
       }else if(operation == "/"){

           value = left.evaluate() / right.evaluate();
       }
       return value;
   }

}