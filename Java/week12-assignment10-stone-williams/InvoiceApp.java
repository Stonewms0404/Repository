public class InvoiceApp {

    public static Invoice invoice = new Invoice();

    public static void main(String args[]) {
        System.out.println("Welcome to the Invoice application\n");
        getLineItems();
        displayInvoice();
    }

    public static void getLineItems() {
        String choice = "y";
        while (choice.equalsIgnoreCase("y")) {
            Console.displayLine("Product Codes: Java, MySQL, & JSP.");
            String productCode = Console.getString("Enter product code: ");
            int quantity = Console.getInt("Enter quantity:     ");

            Product product = ProductDB.getProduct(productCode);
            invoice.addItem(new LineItem(product, quantity));

            choice = Console.getString("Another line item? (y/n): ");
            System.out.println();
        }
    }

    public static void displayInvoice() {
        System.out.println("Invoice date: " + 
                invoice.getDateFormatted());
        System.out.println("Due Date:     " + invoice.getDueDateFormatted() + "\n");
        
        String spec = "%-35s%7s%7s%12s%n";
        System.out.printf(spec, "Description", "Price", "Qty", "Total");
        System.out.printf(spec, "-----------", "-----", "---", "-----");
        
        var lineItems = invoice.getLineItems();
        
        for (LineItem lineItem : lineItems) {
            Product product = lineItem.getProduct();
            System.out.printf("%-35s", product.getDescription()); 
            System.out.printf("%7s", product.getPriceFormatted()); 
            System.out.printf("%7d", lineItem.getQuantity()); 
            System.out.printf("%12s%n", lineItem.getTotalFormatted());
        }
        System.out.printf("%nINVOICE TOTAL:%47s%n%n",
                invoice.getTotalFormatted());
    }
}