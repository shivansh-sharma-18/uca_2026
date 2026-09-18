import java.util.Scanner;

public class SearchLinkedList {
    static class Node {
        int val;
        Node next;

        Node(int val) {
            this.val = val;
            this.next = null;
        }
    }

    public static boolean isPresent(Node list1, Node list2) {

        if (list1 == null) {
            return true;
        }

        while (list2 != null) {

            Node p1 = list1;
            Node p2 = list2;

            while (p1 != null && p2 != null && p1.val == p2.val) {
                p1 = p1.next;
                p2 = p2.next;
            }

            if (p1 == null) {
                return true;
            }

            list2 = list2.next;
        }

        return false;
    }

    public static Node createList(Scanner sc, int n) {

        Node head = null;
        Node tail = null;

        for (int i = 0; i < n; i++) {

            int value = sc.nextInt();
            Node newNode = new Node(value);

            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        return head;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes in list1: ");
        int n1 = sc.nextInt();

        System.out.println("Enter elements of list1:");
        Node list1 = createList(sc, n1);

        System.out.print("Enter number of nodes in list2: ");
        int n2 = sc.nextInt();

        System.out.println("Enter elements of list2:");
        Node list2 = createList(sc, n2);

        if (isPresent(list1, list2)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        sc.close();
    }
}
