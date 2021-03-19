package sorting;

public class InsertionSorter extends Sorter {
  /*
  * my sort method for insertion sort that requires the double[] list in order to work,
  * this method works by running through each variable of the list and changes the order of them by
  * comparing them to each other element in the list and changes the order of them accordingly from least to greatest
  */
    public void sort(double[] list) {
    //declaring variables used for insertion sort
    int i,j;
    double key;
    //running through the list i amount of times
    for( i=1;i<list.length;++i)
    {
        
    key = list[i];
    j=i-1;
     //while loop that runs through the list and compares values of the list and makes it sorted properly 
    while(j>=0 && list[j] > key)
    {
        //runs through the count op function and adds operations to the operation counter
    countOp();
    list[j+1] = list[j];
    j--;
    }
    
//runs through the count op function and adds operations to the operation counter
    countOp();
    list[j+1] = key;
    }
    }
    }
    
    