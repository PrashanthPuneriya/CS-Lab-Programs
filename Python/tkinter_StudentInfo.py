from tkinter import *

root = Tk()
root.title("Student Information")
root.geometry("600x300")

def Reset():
    nameEntry.delete(0, END)
    emailEntry.delete(0, END)
    phoneEntry.delete(0, END)
    Malevar.set(0)
    Femalevar.set(0)
    hobbiesEntry.delete(1.0, END)
    languagevar.set('Select')

def Submit():
    print("Submitted your data successfully")

nameLabel = Label(root, text = "Name")
nameEntry = Entry(root, width = 30, fg = 'darkgreen')
emailLabel = Label(root, text = "EmailID")
emailEntry = Entry(root, width = 30, fg = 'green')
phoneLabel = Label(root, text = "PhoneNo")
phoneEntry = Entry(root, width = 30, fg = 'red')
hobbiesLabel = Label(root, text = "Hobbies")
hobbiesEntry = Text(root, height = 3, width = 30, fg = 'green')

genderLabel = Label(root, text = "Gender")
Malevar = IntVar()
Femalevar = IntVar()
MaleCheckBox = Checkbutton(root, text = "Male", variable = Malevar)
FemaleCheckBox = Checkbutton(root, text = "Female", variable = Femalevar)

nameLabel.grid(row = 0, column = 0, sticky = E)
nameEntry.grid(row = 0, column = 1)
emailLabel.grid(row = 1, column = 0, sticky = E)
emailEntry.grid(row = 1, column = 1)
phoneLabel.grid(row = 2, column = 0, sticky = E)
phoneEntry.grid(row = 2, column = 1)
genderLabel.grid(row = 3,column = 0, sticky = E)
MaleCheckBox.grid(row = 3, column = 1)
FemaleCheckBox.grid(row = 3, column = 2)
hobbiesLabel.grid(row = 4, column = 0, sticky = E)
hobbiesEntry.grid(row = 4, column = 1)

languageChoices = ['C', 'C++', 'Python', 'Java', 'R']
languagevar = StringVar()
languagevar.set('Select')

programmingLabel = Label(root, text = "Programming Language")
programmingLabel.grid(row = 5, column = 0, sticky = E)
popupMenu = OptionMenu(root, languagevar, *languageChoices)
popupMenu.grid(row = 5, column = 1)

submitButton = Button(root, text = "Submit", command = Submit)
resetButton = Button(root, text = "Reset", command = Reset)

submitButton.grid(row = 6, column = 0)
resetButton.grid(row = 6, column = 2)

root.mainloop()