import java.util.Random;

public class BubbleSort {

    public static void bubbleSort(int[] arr, int size) {

        for (int i = 0; i < size - 1; i++) {

            for (int j = 0; j < size - i - 1; j++) {

                if (arr[j] > arr[j + 1]) {

                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static int[] generateNumbers(int[] arr, int size) {

        Random random = new Random();

        for (int i = 0; i < size; i++) {

            arr[i] = random.nextInt(100000);
        }

        return arr;
    }

    public static void main(String[] args) {

        int size1 = 40000;
        int size2 = 80000;

        int[] arr1 = new int[size1];
        int[] arr2 = new int[size2];

        generateNumbers(arr1, size1);

        long start1 = System.nanoTime();

        bubbleSort(arr1, size1);

        long end1 = System.nanoTime();

        double time1 = (end1 - start1) / 1_000_000_000.0;

        generateNumbers(arr2, size2);

        long start2 = System.nanoTime();

        bubbleSort(arr2, size2);

        long end2 = System.nanoTime();

        double time2 = (end2 - start2) / 1_000_000_000.0;

        System.out.printf("Ratio : %.2f%n", time2 / time1);
    }
}
