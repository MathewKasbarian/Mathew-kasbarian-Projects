package ExpressionTree;
public class ExpressionTree{


    private OpNode node;
/*
* constructor for my opNode that just declares the variable given to it and stores it in node
*/
	public ExpressionTree(OpNode node) {
       this.node = node;
   }
/*
* function for printing my depth for the node
*/
   public void print() {
       int depth = 0;

       node.print(depth);

   }
/*
* function for evaluating my node and returning it in the variable value after evaluating it
*/
   public double evaluate() {
       double value = node.evaluate();
       return value;
   }

}

