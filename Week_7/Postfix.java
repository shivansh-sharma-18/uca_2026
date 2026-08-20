import java.util.Scanner;
import java.util.Stack;

public class Postfix {

    public static int calculatePostfix(String s) {

        Stack<Integer> st = new Stack<>();

        String[] tokens = s.trim().split("\\s+");
        
        for (String token : tokens) {

            if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
                int a = st.pop();
                int b = st.pop();

                switch (token) {
                    case "+":
                        st.push(a + b);
                        break;
                    case "-":
                        st.push(b - a);
                        break;
                    case "*":
                        st.push(a * b);
                        break;
                    case "/":
                        st.push(b / a);
                        break;
                    default:
                        break;
                }
            } 
            else {
                st.push(Integer.parseInt(token));
            }
        }
        return st.pop();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();

        System.out.println(calculatePostfix(s));

        sc.close();
    }
}