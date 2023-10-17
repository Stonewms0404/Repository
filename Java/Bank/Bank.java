import java.util.ArrayList;
import java.util.Scanner;
import java.util.Iterator;

public class Bank
{
    public static ArrayList<Account> accountsList = new ArrayList<Account>();
    public static Scanner sc = new Scanner(System.in);
    public static void start()
    {
        System.out.println("Welcome to the banking application\n\n");
        options();
    }
    
    public static void options()
    {
        System.out.println("\n\nEnter the number related to the action you want to preform:");
        System.out.println("\n1: Add account");
        System.out.println("2: Remove account");
        System.out.println("3: Show all accounts");
        System.out.println("4: Check balance");
        System.out.println("5: Withdrawl");
        System.out.println("6: Deposit");
        System.out.println("7: Apply interest");
        System.out.println("0: Quit banking app");
        System.out.println("help: Shows options\n\n");
        
        while (true)
        {
            String sel = sc.nextLine();
            switch (sel.toLowerCase())
            {
                case "1": addAccount(); break;
                case "2": removeAccount(); break;
                case "3": showAllAccounts(); break;
                case "4": checkBalance(); break;
                case "5": withdrawAccount(); break;
                case "6": depositAccount(); break;
                case "7": applyInterest(); break;
                case "0": System.out.println("Quitting Banking App..."); System.exit(0); break;
                case "help": options(); break;
                 default: System.out.print("Please try again: "); continue;
            }
        }
    }
    
    public static boolean isDouble(String strNum)
    {
        if (strNum == null) {
            return false;
        }
        try {
            double d = Double.parseDouble(strNum);
        } catch (NumberFormatException nfe) {
            return false;
        }
        return true;
    }
    
    public static boolean isInt(String strNum)
    {
        if (strNum == null) {
            return false;
        }
        try {
            int d = Integer.parseInt(strNum);
        } catch (NumberFormatException nfe) {
            return false;
        }
        return true;
    }
    
    public static void addAccount()
    {
        int id = 0; double balance = 0; String name = ""; AccountType type = AccountType.NULL;
        String input = ""; boolean a = true; int transactions = 0; double interestRate = 0;
        System.out.print("\n\nEnter account holders first and last name: ");
        while (a)
        {
            input = sc.nextLine();
            if (input.contains(" "))
            {
                name = input;
                a = false;
            } else
            {
                System.out.print("Please print first and last name: ");
                continue;
            }
        }
        a = true;
        System.out.print("\n\nEnter a three digit Account Number (Example \"567\"): ");
        while (a)
        {
            input = sc.nextLine();
            if (input.length() == 3 && isInt(input))
            {
                id = Integer.parseInt(input);
                a = false;
            } else
            {
                System.out.print("\nPlease print a three digit account ID: ");
                continue;
            }
        }
        a = true;
        System.out.print("\n\nEnter starting account balance (Example \"125\"): ");
        while (a)
        {
            input = sc.nextLine();
            if (isDouble(input))
            {
                balance = Double.parseDouble(input);
                a = false;
            } else
            {
                System.out.println("Please print a starting balance: ");
                continue;
            }
        }
        a = true;
        System.out.print("\n\nEnter c for Checking or s for Savings: ");
        while (a)
        {
            input = sc.nextLine();
            if (input.toLowerCase().charAt(0) == 's' && input != null)
            {
                type = AccountType.SAVINGS;
                a = false;
            }else if (input.toLowerCase().charAt(0) == 'c' && input != null)
            {
                type = AccountType.CHECKINGS;
                a = false;
            }else
            {
                System.out.print("\nPlease print a \"c\" or an \"s\": ");
                continue;
            }
        }
        a = true;
        if (type.equals(AccountType.CHECKINGS))
        {
            System.out.print("\n\nEnter amount of free transactions 1-3: ");
            while (a)
            {
                input = sc.nextLine();
                if (!isInt(input))
                {
                    System.out.print("\nPlease print a number between 1 and 3: ");
                    continue;
                }
                if (Integer.parseInt(input) <= 3.0 && Integer.parseInt(input) >= 1.0 && isInt(input))
                {
                    transactions = Integer.parseInt(input);
                    a = false;
                } else
                {
                    System.out.print("\nPlease print a number between 1 and 3: ");
                    continue;
                }
            }
            Account cheAccount = new Checkings(id, balance, name, type, transactions);
            accountsList.add(accountsList.size(), cheAccount);
        }else if (type.equals(AccountType.SAVINGS))
        {
            System.out.print("\n\nEnter interest amount 1.0-3.0: ");
            while (a)
            {
                input = sc.nextLine();
                if (!isDouble(input))
                {
                    System.out.print("\nPlease print a number between 1.0 and 3.0: ");
                    continue;
                }
                if (Double.parseDouble(input) <= 3 && Double.parseDouble(input) >= 1 && isDouble(input))
                {
                    interestRate = Integer.parseInt(input);
                    a = false;
                } else
                {
                    System.out.print("\nPlease print a number between 1.0 and 3.0: ");
                    continue;
                }
            }
            Account savAccount = new Savings(id, balance, name, type, interestRate);
            accountsList.add(accountsList.size(), savAccount);
        }
        a = true;
        System.out.println("\nAccount with ID " + id + " was added successfully.");
        options();
    }
    
    public static void removeAccount()
    {
        System.out.println("Enter account number to remove (Example 456): ");
        while(true)
        {
            String input = sc.nextLine();
            if (isInt(input))
            {
                Account a = getAccountHelper(Integer.parseInt(input));
                accountsList.remove(a);
                System.out.println("Account with ID " + input + " was removed successfully.");
                break;
            }else
            {
                System.out.print("\nPrint a valid ID: ");
                continue;
            }
        }
        options();
    }
    
    public static Account getAccountHelper(int id)
    {
        for (Account a: accountsList)
        {
            if (a.getId() == id)
            {
                return a;
            }
            else
            {
                continue;
            }
        }
        return null;
    }
    
    public static void showAllAccounts()
    {
        System.out.println("\nAccounts:");
        for (Account a: accountsList)
        {
            System.out.println("ID: " + a.getId() + ", Account Type: " + a.getType() +
            ", Name: " + a.getAccountHolder() + ", Balance: " + a.getBalanceFormatted());
        }
        options();
    }
    
    public static void checkBalance()
    {
        System.out.print("\nEnter account number (Example 456): ");
        while(true)
        {
            String input = sc.nextLine();
            if (isInt(input))
            {
                Account a = getAccountHelper(Integer.parseInt(input));
                System.out.println("\nAccount with ID " + input + " has a balance of " + a.getBalanceFormatted());
                break;
            }else
            {
                System.out.print("\nPrint a valid ID: ");
                continue;
            }
        }
        options();
    }
    
    public static void withdrawAccount()
    {
        System.out.print("\nEnter account number (Example 456): ");
        while(true)
        {
            String input = sc.nextLine();
            if (isInt(input))
            {
                System.out.print("\nEnter amount to withdraw: ");
                String input2 = sc.nextLine();
                Account a = getAccountHelper(Integer.parseInt(input));
                a.withdrawl(Integer.parseInt(input2));
                break;
            }else
            {
                System.out.print("\nPrint a valid ID: ");
                continue;
            }
        }
        options();
    }
    
    public static void depositAccount()
    {
        System.out.print("\nEnter account number (Example 456): ");
        while(true)
        {
            String input = sc.nextLine();
            Account a = getAccountHelper(Integer.parseInt(input));
            if (isInt(input))
            {
                System.out.print("\nEnter amount to deposit: ");
                String input2 = sc.nextLine();
                a.deposit(Integer.parseInt(input2));
                break;
            }else
            {
                System.out.print("\nPrint a valid ID: ");
                continue;
            }
        }
        options();
    }
    
    
    public static void applyInterest()
    {
        System.out.println("Enter account number (Example 456): ");
        while(true)
        {
            String input = sc.nextLine();
            if (isInt(input))
            {
                Account a = getAccountHelper(Integer.parseInt(input));
                a.interest();
                break;
            }else
            {
                System.out.print("\nPrint a valid ID: ");
                continue;
            }
        }
        options();
    }
}
