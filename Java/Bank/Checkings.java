public class Checkings extends Account
{
    private static int FREE_TRANSACTIONS;
    private static final int FEE_AMOUNT = 5;
    private static int transactions = 0;
    
    public Checkings(int id, double balance, String name, AccountType type, int freeTransactions)
    {
        setId(id);
        setBalance(balance);
        setAccountHolder(name);
        setType(type);
        FREE_TRANSACTIONS = freeTransactions;
    }
    
    public static void deductFees()
    {
        if(transactions == FREE_TRANSACTIONS)
        {
            setBalance(getBalance() - FEE_AMOUNT);
            logTransaction(FEE_AMOUNT + " fee was deducted. The new balance is: " + getBalance());
        }else if (getType().equals(AccountType.SAVINGS))
        {
            logTransaction("No fees due to Savings Account.");
        }else
        {
            logTransaction(--FREE_TRANSACTIONS + "/3 free transactions have been used.");
        }
    }
    
    public static void logTransaction(String transaction)
    {
        System.out.println(transaction);
    }
}
