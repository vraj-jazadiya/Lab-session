
class AxisBank:

    def __init__(self, customer_name, amount):
        self.customer_name = customer_name
        self.bank_name = "Axis Bank"
        self.amount = amount

    def deposit(self):
        deposit_amount = float(input("Enter amount to deposit: "))

        self.amount = self.amount + deposit_amount

        print("Amount deposited successfully.")
        print("Current balance:", self.amount)

    def withdraw(self):
        withdraw_amount = float(input("Enter amount to withdraw: "))

        if withdraw_amount <= self.amount:
            self.amount = self.amount - withdraw_amount
            print("Amount withdrawn successfully.")
            print("Current balance:", self.amount)
        else:
            print("Insufficient balance.")

    def display(self):
        print("\n----- Account Details -----")
        print("Customer Name:", self.customer_name)
        print("Bank Name:", self.bank_name)
        print("Amount:", self.amount)


customer_name = input("Enter customer name: ")
amount = float(input("Enter initial amount: "))

customer = AxisBank(customer_name, amount)


while True:

    print("\n===== AXIS BANK =====")
    print("1. Deposit")
    print("2. Withdraw")
    print("3. Display")
    print("4. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        customer.deposit()

    elif choice == 2:
        customer.withdraw()

    elif choice == 3:
        customer.display()

    elif choice == 4:
        print("Thank you for using Axis Bank.")
        break

    else:
        print("Invalid choice. Please try again.")
