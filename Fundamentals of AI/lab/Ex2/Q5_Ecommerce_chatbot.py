from nltk.chat.util import Chat, reflections

# E-commerce chatbot: 20+ questions and answers
pairs = [
    [
        r"hi|hello|hey",
        ["Hello! Welcome to our online store. How can I help you?"]
    ],
    [
        r"what products do you sell ?",
        ["We sell electronics, clothing, shoes, accessories and home products."]
    ],
    [
        r"how can I place an order ?",
        ["Select a product, add it to your cart, and proceed to checkout."]
    ],
    [
        r"how can I cancel my order ?",
        ["You can cancel your order from the 'My Orders' section before it is shipped."]
    ],
    [
        r"what payment methods do you accept ?",
        ["We accept UPI, credit cards, debit cards, net banking and cash on delivery."]
    ],
    [
        r"do you accept cash on delivery ?",
        ["Yes, cash on delivery is available for selected locations."]
    ],
    [
        r"how can I track my order ?",
        ["Go to 'My Orders' and select your order to view its tracking status."]
    ],
    [
        r"how long does delivery take ?",
        ["Normally, delivery takes 3 to 7 business days."]
    ],
    [
        r"do you provide free delivery ?",
        ["Yes, free delivery is available on eligible orders."]
    ],
    [
        r"what is your return policy ?",
        ["Most products can be returned within 7 days of delivery, subject to the product's return policy."]
    ],
    [
        r"how can I return a product ?",
        ["Go to 'My Orders', select the product, and choose the 'Return' option."]
    ],
    [
        r"how can I get a refund ?",
        ["After the returned product is approved, the refund will be processed to your original payment method."]
    ],
    [
        r"how long does a refund take ?",
        ["Refunds normally take 5 to 7 business days after approval."]
    ],
    [
        r"can I exchange a product ?",
        ["Yes, exchanges are available for eligible products depending on stock availability."]
    ],
    [
        r"how can I contact customer support ?",
        ["You can contact our customer support through email, phone or live chat."]
    ],
    [
        r"do you have discounts ?",
        ["Yes, we regularly offer discounts and special deals on selected products."]
    ],
    [
        r"how can I use a coupon ?",
        ["Enter your coupon code in the coupon section during checkout."]
    ],
    [
        r"can I change my delivery address ?",
        ["Yes, you can change the delivery address before the order is shipped."]
    ],
    [
        r"is my personal information safe ?",
        ["Yes, we use security measures to protect your personal information."]
    ],
    [
        r"do you provide warranty ?",
        ["Warranty is available for selected products according to the manufacturer's warranty policy."]
    ],
    [
        r"what if I receive a damaged product ?",
        ["Please contact customer support immediately and provide photos of the damaged product."]
    ],
    [
        r"what if I receive the wrong product ?",
        ["Contact customer support and request a return or replacement."]
    ],
    [
        r"can I order from my mobile ?",
        ["Yes, you can place orders using our website or mobile application."]
    ],
    [
        r"thank you|thanks",
        ["You're welcome! Happy shopping!"]
    ],
    [
        r"quit",
        ["Thank you for visiting our store. Goodbye!"]
    ]
]


def ecommerce_chatbot():
    print("==========================================")
    print("   Welcome to Our E-Commerce Chatbot")
    print("==========================================")
    print("Ask me about products, orders, delivery,")
    print("returns, payments, refunds, and more.")
    print("Type 'quit' to exit.\n")

    chat = Chat(pairs, reflections)
    chat.converse()


if __name__ == "__main__":
    ecommerce_chatbot()