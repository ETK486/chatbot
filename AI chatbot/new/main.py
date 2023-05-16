import random
from tkinter import *

greetres = [
    "Hello! How can I help you today?",
    "What's on your mind?",
    "I'm here to assist you. What do you need?",
    "How can I assist you?",
    "What can I help you with?",
]
nameres = [
    "Hi, I am AMC Bot.",
    "You can call me AMC Bot.",
    "Myself AMC Bot.",
]
locationres = [
    "Our College is situated near the Thamukkam Ground.",
    "You can see our college opposite to the Rajaji Government Hospital.",
    "The American college is situated on Thallakulam.",
]
semres = [
    "You'll have two semesters per year.",
    "Every course has a total of 2 semesters per year.",
    "2 semesters per year.",
]
semdurres = [
    "Each semester takes a time of 4 to 6 months to complete.",
    "It takes 4 to 6 months for each semester.",
    "The duration is 4 to 6 months for each semester to complete",
]
stureqres = [
    "Students need to complete HSC and SSLC with a minimum of 60%",
    "The qualification of the student is to complete HSC and SSLC with a minimum of 60%",
    "The students must need to have a percentage of 60% in both HSC and SSLC",
]
classres = [
    "There will be 5 classes per day, Each of 45 minutes",
    "5 classes per day each of 45 minutes",
    "There will 45 minutes duration classes. There will be 5 classes per day",
]
deptres = [
    "There are 2 Campuses in our college.\n 1. Satellite Campus\n 2. Main Campus\nThere are Several departments in "
    "both the campus.\nFor details contact the main office in Main Campus", ]

examres = [
    "There will be Quiz for 10 marks,Assignment for 10 marks and Test for 30 marks for the internals.\nThe Students "
    "who obtained pass mark in the internal exam are allowed to attend the External Exam.\nThe External exam will "
    "take place for 100 marks for Major Subjects and 70 marks for Non-Major Subjects",
]

feeres = [
    "Its based on the Course You are going to select. The details are available in main office.",
]

goodbyeres = [
    "Thank You",
    "It's a pleasure to meet you",
    "Thank you. I am always here to assist you.",
    "Sayonara",
    "See You soon",
]

invalidres = [
    "Sorry can't understand you",
    "Please give me more info",
    "Not sure I understand you.",
]


def chatbot_response(user_input):
    user_input = user_input.lower()

    if "hello" or "hi" in user_input:
        return random.choice(greetres)
    elif "name" in user_input:
        return random.choice(nameres)
    elif "location" in user_input:
        return random.choice(locationres)
    elif "semester" and "many" or "semester" and "per year" in user_input:
        return random.choice(semres)
    elif "semester" and "duration" in user_input:
        return random.choice(semdurres)
    elif "student" and "requirements" in user_input:
        return random.choice(stureqres)
    elif "class" or "duration" in user_input:
        return random.choice(classres)
    elif "department" or "dept" in user_input:
        return deptres
    elif "exam" in user_input:
        return examres
    elif "fees" or "college fees" or "fee" in user_input:
        return feeres
    else:
        return random.choice(invalidres)


root = Tk()
root.title("AMC bot")

# text area
text_area = Text(root, bg="white", width=50, height=20)
text_area.pack()

# input field
input_field = Entry(root, width=50)
input_field.pack()

# send button
send_button = Button(root, text="Send", command=lambda: send_message())
send_button.pack()


def send_message():
    # To get the input
    user_input = input_field.get()

    # To clear the input field
    input_field.delete(0, END)

    # To get response
    res = chatbot_response(user_input)

    # Response of chatbot
    text_area.insert(END, f"User: {user_input}\n")
    text_area.insert(END, f"AMC bot: {res}\n")


root.mainloop()
