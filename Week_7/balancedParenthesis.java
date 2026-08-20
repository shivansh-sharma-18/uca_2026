import java.util.Scanner;
import java.util.Stack;

public class balancedParenthesis {

    public static boolean isBalanced(String s) {
        Stack<Character> st = new Stack<>();

        for (char c : s.toCharArray()) {

            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else if (c == ')' || c == '}' || c == ']') {

                if (st.empty()) {
                    return false;
                }

                char top = st.pop();
                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                    return false;
                }

            }

        }

        return st.isEmpty();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();

        System.out.println(isBalanced(s));

        sc.close();
    }
}