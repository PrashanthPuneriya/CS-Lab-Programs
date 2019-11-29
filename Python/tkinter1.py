from tkinter import *
"""
We have to pack the widget to display it.

l->label, b->button, t->text, f->frame, 
By Default all the widgets are stacked on each other
"""
root = Tk()
root.title("Colors....")
root.geometry("500x300")
topFrame = Frame(root)
bottomFrame = Frame(root)
topFrame.pack() # Default side = TOP
bottomFrame.pack(side = BOTTOM)

l1 = Label(root, text = "MARK 1.0", bg = 'red', fg = 'white') # Appears in the middle since its in root frame
l2 = Label(root, text = "HELLO", bg = 'green', fg = 'black')
l3 = Label(root, text = "Prashanth!", bg = 'blue', fg = 'white')
b1 = Button(bottomFrame, text = "Hey!", activebackground = 'yellow', activeforeground = 'red')
b2 = Button(bottomFrame, text = "Bye!", activebackground = 'yellow', activeforeground = 'red')

l1.pack()
l2.pack(fill = X)
l3.pack(side = LEFT, fill = Y)
b1.pack(side = LEFT)
b2.pack(side = LEFT)



root.mainloop()