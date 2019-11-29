from tkinter import Tk, Menu, messagebox

root = Tk()
root.geometry("500x300")
menu_bar = Menu(root)
root.config(menu = menu_bar)
# Sub-Menu
file_menu = Menu(menu_bar, tearoff = 0)

menu_bar.add_cascade(label = "Quit", menu = file_menu)

file_menu.add_command(label = "Stop", command = root.destroy)
file_menu.add_command(label = "Kill", command = root.destroy)

reply = messagebox.askquestion("Exit Confirmation", "Is your intention to exit?")
if reply == 'yes':
    root.destroy()
else:
    pass


root.mainloop()