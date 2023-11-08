public class Fibonacci {
    public static  int count=0;
    public static int[] fibo(int n){
        int arr[]=new int[n];
        arr[0]=0;
        arr[1]=1;
        int stepCount=1;
        for (int i = 2; i < arr.length; i++) {
            arr[i]=arr[i-1]+arr[i-2];
            stepCount++;
        }
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
        System.out.println("Step Count:"+stepCount);
        return arr;
    }
    static int fib(int n)
    {
        // Base Case
       count++;
        if (n <= 1)
            return n;
       
        // Recursive call
        return fib(n - 1) + fib(n - 2);
    
    }
 

    public static void main(String[] args) {
        int n=8;
        fibo(8);
       for (int i = 0; i <n ; i++) {
            System.out.println(fib(i));
            
       }
       System.out.println(count);
    }
}
