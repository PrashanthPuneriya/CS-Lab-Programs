from tkinter import *
"""
e->entry, c->checkbox, 
default column is 0
"""
class LabelCreation:
    def __init__(self, master): # master = root
        l1 = Label(master, text = "Name") # Appears in the middle if we won't use sticky=E in the grid. Since, its in root frame
        l2 = Label(master, text = "Password")
        e1 = Entry(master)
        e2 = Entry(master)

        l1.grid(row = 0, column = 0, sticky = E)
        l2.grid(row = 1, sticky = E)
        e1.grid(row = 0, column = 1)
        e2.grid(row = 1, column = 1)


class ButtonsCreation:
    def __init__(self, master): # master = root
        c1 = Checkbutton(master, text = "Keep me Signed in")
        b1 = Button(master, text = "Login")
        b1.bind("<Button-1>", self.Success)
        b1.bind("<Button-3>", self.notAllowed) # Button-2 is middle click
        # b1 = Button(root, text = "Login", command = Success)
        b2 = Button(master, text = "Quit", command = master.destroy)

        c1.grid(columnspan = 2)
        b1.grid(columnspan = 2)
        b2.grid(columnspan = 2)

    def Success(self, event):
        print("Login Successful")

    def notAllowed(self, event):
        print("Right Click is not ALLOWED")



root = Tk()
root.title("Login Window...")
root.geometry("300x200")
l = LabelCreation(root)
b = ButtonsCreation(root)

root.mainloop()