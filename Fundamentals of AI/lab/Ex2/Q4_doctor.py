from nltk.chat.util import Chat, reflections

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
        r"Have you (.*)",
        ["I never %1"]
    ],
    [
        r"quit",
        [
            "BBye take care. See you soon :)",
            "It was nice talking to you. See you soon :)"
        ]
    ]
]


def chatty():
    print("Hi, I'm Chatty and I chat alot ;)")
    print("Please type lowercase English language to start a conversation.")
    print("Type quit to leave")

    chat = Chat(pairs, my_dummy_reflections)
    chat.converse()


if __name__ == "__main__":
    chatty()