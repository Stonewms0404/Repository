public class Savings extends Account
{
    private static double INTEREST_RATE;
    public Savings(int id, double balance, String name, AccountType type, double interestRate)
    {
        setId(id);
        setBalance(balance);
        setAccountHolder(name);
        setType(type);
        INTEREST_RATE = interestRate;
    }
    
    public static void addInterest()
    {
        double interest = (INTEREST_RATE / 12) * getBalance();
        setBalance(getBalance() + Double.parseDouble(getFormatted(interest)));
        logTransaction(getFormatted(interest) + " of interest was added to " + getAccountHolder() +
        "'s account. The new balance is: " + getBalanceFormatted() + ".");
    }
    
    public static void logTransaction(String transaction)
    {
        System.out.print(transaction);
    }
}
