import java.util.Scanner;

public class reverseList {

    static class Node {
        int val;
        Node next;

        Node(int val) {
            this.val = val;
            this.next = null;
        }
    }

    public static Node reverse(Node head) {
        if (head == null || head.next == null) {
            return head;
        }

        Node newHead = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
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

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        Node head = null;
        Node tail = null;

        System.out.println("Enter the elements:");

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

        head = reverse(head);

        System.out.println("Reversed List:");
        print(head);

        sc.close();
    }
}
