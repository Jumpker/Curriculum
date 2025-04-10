package src.exp3.Account;

import java.util.Date;

public class Account {
        private int id;
        private double balance;
        private double annualInterestRate;
        private Date dateCreated;
//构造函数=======================================================
        public Account(){
            this.id = 0;
            this.balance = 0;
            this.annualInterestRate = 0;
            this.dateCreated = new Date();
        }
        public Account(int id, double balance, double annualInterestRate){
            this.id = id;
            this.balance = balance;
            this.annualInterestRate = annualInterestRate;
            this.dateCreated = new Date();
        }
//访问器=====================================================
        public int get_id(){
            return this.id;
        }
        public double get_balance(){
            return this.balance;
        }
        public double get_annualInterestRate(){
            return this.annualInterestRate;
        }
        public Date get_dateCreated(){
            return this.dateCreated;
        }
//修改器=========================================================
        public void change_id(int a){
            this.id = a;
        }
        public void change_balance(double a){
            this.balance=a;
        }
        public void change_annualInterestRate(double a) {
            this.annualInterestRate = a;
        }
//其他=================================================================
        public double getMonthlyInterestRate(){
            return (this.annualInterestRate/12);
        }
        public void withdraw(double amount){
            this.balance-=amount;
        }
        public void deposit(double amount) {
            this.balance += amount;
        }
}
