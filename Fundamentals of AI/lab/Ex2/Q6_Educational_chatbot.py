from nltk.chat.util import Chat, reflections

# Educational Institution chatbot: 20+ questions and answers
pairs = [
    [
        r"hi|hello|hey",
        ["Hello! Welcome to our educational institution. How can I help you?"]
    ],
    [
        r"what courses do you offer ?",
        ["We offer undergraduate, postgraduate and professional courses in various fields."]
    ],
    [
        r"how can I apply for admission ?",
        ["You can apply for admission through our official admission portal."]
    ],
    [
        r"what is the admission process ?",
        ["The admission process includes application, document verification, eligibility checking and fee payment."]
    ],
    [
        r"what are the eligibility criteria ?",
        ["Eligibility criteria depend on the course. Please check the requirements for your desired program."]
    ],
    [
        r"what documents are required for admission ?",
        ["Common documents include marksheets, identity proof, photographs and required certificates."]
    ],
    [
        r"what is the fee structure ?",
        ["The fee structure varies according to the course and program."]
    ],
    [
        r"are scholarships available ?",
        ["Yes, scholarships may be available for eligible students based on merit and other criteria."]
    ],
    [
        r"how can I apply for a scholarship ?",
        ["You can apply for scholarships through the institution's scholarship or student portal."]
    ],
    [
        r"when does the academic year start ?",
        ["The academic year generally begins after the admission process is completed."]
    ],
    [
        r"where is the college located ?",
        ["The institution is located on its main campus. Please contact the administration for the exact location."]
    ],
    [
        r"do you provide hostel facilities ?",
        ["Yes, hostel facilities are available for eligible students, subject to availability."]
    ],
    [
        r"do you have a library ?",
        ["Yes, the institution has a library with academic books and other learning resources."]
    ],
    [
        r"do you have a computer lab ?",
        ["Yes, computer laboratories are available for students and academic activities."]
    ],
    [
        r"what are the class timings ?",
        ["Class timings depend on the course and semester timetable."]
    ],
    [
        r"how can I check my timetable ?",
        ["Students can check their timetable through the student portal or notice board."]
    ],
    [
        r"how can I check my results ?",
        ["You can check your examination results through the student portal."]
    ],
    [
        r"when are the examinations conducted ?",
        ["Examinations are conducted according to the academic calendar."]
    ],
    [
        r"do you provide placement assistance ?",
        ["Yes, the institution provides placement assistance and career guidance to eligible students."]
    ],
    [
        r"which companies visit for placement ?",
        ["Companies visiting for placement vary from year to year depending on the placement schedule."]
    ],
    [
        r"do you provide internships ?",
        ["Internship opportunities may be provided through the institution and its industry connections."]
    ],
    [
        r"how can I contact the college ?",
        ["You can contact the administration through the official phone number or email address."]
    ],
    [
        r"who can I contact for admission queries ?",
        ["You can contact the admission office for admission-related queries."]
    ],
    [
        r"can I get a transfer certificate ?",
        ["Yes, eligible students can request a transfer certificate through the appropriate administrative office."]
    ],
    [
        r"thank you|thanks",
        ["You're welcome! Best wishes for your studies."]
    ],
    [
        r"quit",
        ["Thank you for contacting us. Goodbye!"]
    ]
]


def educational_chatbot():
    print("==============================================")
    print("   Educational Institution Chatbot")
    print("==============================================")
    print("Ask me about admissions, courses, fees,")
    print("scholarships, exams, hostel, placements, etc.")
    print("Type 'quit' to exit.\n")

    chat = Chat(pairs, reflections)
    chat.converse()


if __name__ == "__main__":
    educational_chatbot()