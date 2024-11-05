import java.util.Scanner;

public class TextAdventure {

    private static class Node {
        String storyline;
        Node left;
        Node right;

        Node(String storyline) {
            this.storyline = storyline;
            left = null;
            right = null;
        }
    }

    private static Node createGameplay() {
        Node root = new Node("\n\nYou find yourself lost while scuba diving. You're underwater, visibility is limited and you're not sure which direction to go. Do you go west or east?");

        root.left = new Node("\nYou choose west and come across a mysterious underwater cave. Do you enter the cave to explore further or ignore the cave and continue swimming?");
        root.right = new Node("\nYou choose east and encounter a school of colurful fish. Do you follow the fish to see where they lead or ignore the fish and continue swimming?");

        root.left.left = new Node("\nYou enter the cave and find yourself in a network of tunnels. As you navigate through the twists and turns, you stumble upon an ancient treasure chest. Do you open the chest and see what's inside or leave the chest alone and continue exploring the cave?");
        root.left.right = new Node("\nYou swim past the cave and eventually surface near a remote island. Do you swim to the island to take help or stay in the water and continue searching for other signs of civilization?");

        root.right.left = new Node("\nYou follow the fish and they guide you to a hidden underwater grotto filled with bioluminescent creatures. Do you explore the grotto to admire the beauty of the creatures or leave the grotto and continue following the fish?");
        root.right.right = new Node("\nYou ignore the fish and come across a pod of dolphins swimming playfully. Do you interact with the dolphins or continue swimming?");

        root.left.left.left = new Node("\nYou open the chest and find ancient artifacts and jewels. However, as you reach for them, the cave begins to collapse! You end up buried in the cave, forever lost to the seas.");
        root.left.left.right = new Node("\nYou leave the chest alone and wind up in a tunnel leading up, up, up which opens into a sea cave near the beach. You reach home.");

        root.left.right.left = new Node("\nYou reach the island and find help. With the assistance of the locals, you're able to return safely to the surface, relieved to be back on dry land.");
        root.left.right.right = new Node("\nYou keep swimming in the water looking for other signs of civilization, when suddenly you're surrounded by multiple sharks. You get eaten and die.");

        root.right.left.left = new Node("\nYou explore the grotto to find a hidden exit that leads to the surface. You emerge, finding yourself close to your dive boat, which had been searching for you. You're reunited with your crew.");
        root.right.left.right = new Node("\nYou keep following the fish just to end up getting stuck in a fishnet. You eventually run out of oxygen and die.");

        root.right.right.left = new Node("\nYou interact with the dolphins and have fun playing with them. They lead you back towards the beach, and you're found by the officials looking for you.");
        root.right.right.right = new Node("\nYou continue swimming, and continue swimming, and continue swimming, until you run out of oxygen.");
        
        return root;
    }

    private static void play(Node current) {
        Scanner sc = new Scanner(System.in);

        while (current != null) {
            clearScreen(); // Clear screen for better presentation
            System.out.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            System.out.println(current.storyline);
            System.out.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

            if (current.left == null && current.right == null) {
                System.out.println("End of story.");
                break;
            }

            System.out.println("Enter your choice:");
            System.out.println("1. Go left");
            System.out.println("2. Go right");
            System.out.print("Choice: ");

            String choice = sc.nextLine().trim().toLowerCase();
            System.out.println(); // Add some space for better readability

            if (choice.equals("1") || choice.equals("left")) {
                current = current.left;
            } else if (choice.equals("2") || choice.equals("right")) {
                current = current.right;
            } else {
                System.out.println("Invalid choice. Please choose again.");
            }
        }
        sc.close();
    }

    private static void clearScreen() {
        System.out.print("\033[H\033[2J"); // ANSI escape code to clear console
        System.out.flush();
    }

    public static void main(String[] args) {
        Node story = createGameplay();
        play(story);
    }
}
