public class BinarySearch {
    public static int search(int[] data, int target) {    
        int lo = 0;
        int hi = data.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if      (target < data[mid]) hi = mid - 1;
            else if (target > data[mid]) lo = mid + 1;
            else return mid;
        }
        return -1;
    }

    public static int recursiveBinarySearch(int[] data, int target) {
        return binarySearch(data, 0, data.length-1, target);
    }
    
    private static int binarySearch(int[] data, int low, int high, int target) {
        int middle = low + (high - low) / 2;
        if(high < low) {
            return -1;
        } 
    
        if(target == data[middle]) {
            return middle;
        } else if(target < data[middle]) {
            return binarySearch(data, low, middle - 1, target);
        } else {
            return binarySearch(data, middle + 1, high, target);
        }
    }
}