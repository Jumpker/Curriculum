package src.exp3.Account;

public class Main {
    public static void main(String[] args) {
        Account account = new Account(1122, 20000, 0.045);
        account.withdraw(2500);
        account.deposit(3000);
        System.out.println("余额为："+account.get_balance());
        System.out.println("月利率为："+account.getMonthlyInterestRate());
        System.out.println("账户开户日期为："+ account.get_dateCreated());
    }
}
