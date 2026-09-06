from nltk.chat.util import Chat

my_dummy_reflections = {
    "mr": "Doctor",
    "hello": "hey there",
    "play": "played"
}

pairs = [
    [
        r"my name is (.*)",
        ["Hello %1, How are you today?"]
    ],
    [
        r"quit",
        [
            "Bye! Take care. See you soon :)", #homoo
            "It was nice talking to you. See you soon :)"
        ]
    ],
]

def chatty():
    print(
        "Hi, I'm Chatty and I chat a lot and_u ;)\n"
        "Please type lowercase English language to start a conversation.\n"
        "Type quit to leave."
    )

if __name__ == "__main__":
    chatty()

