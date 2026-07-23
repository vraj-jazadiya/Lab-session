
class InvoiceItem:

    def __init__(self, item_id, description, quantity, unit_price):
        self.item_id = item_id
        self.description = description
        self.quantity = quantity
        self.unit_price = unit_price

    def getTotal(self):
        return self.quantity * self.unit_price


item = InvoiceItem(101, "Laptop", 2, 50000)

print("Item ID:", item.item_id)
print("Description:", item.description)
print("Quantity:", item.quantity)
print("Unit Price:", item.unit_price)

print("Total Invoice:", item.getTotal())

