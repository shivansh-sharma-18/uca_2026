import java.util.Scanner;

public class listIntersection {
    static class Node {
        int val;
        Node next;

        Node(int val) {
            this.val = val;
            this.next = null;
        }
    }

    public static Node intersection(Node head1, Node head2) {
        Node dummy = new Node(0);
        Node tail = dummy;

        while (head1 != null && head2 != null) {

            if (head1.val == head2.val) {

                tail.next = new Node(head1.val);
                tail = tail.next;

                head1 = head1.next;
                head2 = head2.next;

            } else if (head1.val < head2.val) {

                head1 = head1.next;

            } else {

                head2 = head2.next;
            }
        }

        return dummy.next;
    }

    public static void print(Node head) {
        Node node = head;
        while (node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes in first list: ");
        int n1 = sc.nextInt();

        Node head1 = null;
        Node tail1 = null;

        System.out.println("Enter elements of first list:");

        for (int i = 0; i < n1; i++) {

            int value = sc.nextInt();
            Node newNode = new Node(value);

            if (head1 == null) {
                head1 = newNode;
                tail1 = newNode;
            } else {
                tail1.next = newNode;
                tail1 = newNode;
            }
        }

        System.out.print("Enter number of nodes in second list: ");
        int n2 = sc.nextInt();

        Node head2 = null;
        Node tail2 = null;

        System.out.println("Enter elements of second list:");

        for (int i = 0; i < n2; i++) {

            int value = sc.nextInt();
            Node newNode = new Node(value);

            if (head2 == null) {
                head2 = newNode;
                tail2 = newNode;
            } else {
                tail2.next = newNode;
                tail2 = newNode;
            }
        }

        Node result = intersection(head1, head2);

        System.out.println("Intersection List:");
        print(result);

        sc.close();
    }

}
