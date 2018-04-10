package src;// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i. Solve it without using division and in O(n) time.

// For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

class IndexProduct
{
    void productArray(int arr[])
    {
        int i, temp = 1;

        /* Allocate memory for the product array { , , , , } */
        int prod[] = new int[arr.length];
 
        /* Initialize the product array as 1 {1, 1, 1, 1, 1}*/
        for(int j=0;j<arr.length;j++)
            prod[j]=1;
 
        /* In this loop, temp variable contains product of
           elements on left side excluding arr[i] */
        for (i = 0; i < arr.length; i++)
        {
            prod[i] = temp;
            temp *= arr[i];
        }

        /* Initialize temp to 1 for product on right side */
        temp = 1;
 
        /* In this loop, temp variable contains product of
           elements on right side excluding arr[i] */
        for (i = arr.length - 1; i >= 0; i--)
        {
            prod[i] *= temp;
            temp *= arr[i];
        }
 
        /* print the constructed prod array */
        for (i = 0; i < prod.length; i++)
            System.out.print(prod[i] + " ");
 
        return;
    }
 
    /* Driver program to test above functions */
    public static void main(String[] args) {
        IndexProduct test = new IndexProduct();
        int arr[] = {1, 2, 3, 4, 5};
        test.productArray(arr);
    }
}