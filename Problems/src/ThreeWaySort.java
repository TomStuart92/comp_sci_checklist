class ThreeWaySort {
    public enum colors {
        RED, WHITE, BLUE
    }

    public static colors[] threeWaySort(colors[] array) {
        int lo = 0;
        int hi = array.length - 1;
        int mid = 0;
        colors temp;

        while(mid <= hi) {
            switch (array[mid]) {
                case RED:
                    temp = array[lo];
                    array[lo] = array[mid];
                    array[mid] = temp;
                    lo++;
                    mid++;
                    break;
                case WHITE:
                    mid++;
                    break;
                case BLUE:
                    temp = array[mid];
                    array[mid] = array[hi];
                    array[hi] = temp;
                    hi--;
                    break;
            }
        }
        return array;
    }
}