import java.text.NumberFormat;

public abstract class Account
{
    private static int id;
    private static double balance;
    private static String accountHolder;
    private static AccountType type;
    protected static NumberFormat currency;
    
    public Account() {}
    
    public static void setId(int Aid)
    {
        id = Aid;
    }
    
    public static int getId()
    {
        return id;
    }
    
    public static void setBalance(double Abalance)
    {
        balance = Abalance;
    }
    
    public static double getBalance()
    {
        return balance;
    }
    
    public static String getFormatted(double item)
    {
        currency = NumberFormat.getCurrencyInstance();
        return currency.format(item);
    }
    
    public static String getBalanceFormatted()
    {
        currency = NumberFormat.getCurrencyInstance();
        return currency.format(balance);
    }
    
    public static void setAccountHolder(String name)
    {
        accountHolder = name;
    }
    
    public static String getAccountHolder()
    {
        return accountHolder;
    }
    
    public static void setType(AccountType Atype)
    {
        type = Atype;
    }
    
    public static String getType()
    {
        return "" + type;
    }
    
    public static void deposit(double amount)
    {
        balance += amount;
        logTransaction("$" + amount + " was deposited to " + accountHolder +
            "'s account. The new balance is " + getBalanceFormatted());
        Checkings.deductFees();
    }
    
    public static void withdrawl(double amount)
    {
        if (balance > amount)
        {
            balance -= amount;
            logTransaction("$" + amount + " was withdrawn from " + accountHolder +
            "\'s account. The new balance is " + getBalanceFormatted());
            Checkings.deductFees();
        }
        else
        {
            logTransaction("Not enough funds to withdrawl: $" + amount +
            ". The current balance is " + getBalanceFormatted());
        }
    }
    
    public static void interest()
    {
        Savings.addInterest();
    }
    
    public static void logTransaction(String transaction)
    {
        System.out.println(transaction);
    }
}
