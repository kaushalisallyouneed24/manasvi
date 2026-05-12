import tkinter as tk
from tkinter import messagebox
import pandas as pd
import os
from datetime import datetime
import matplotlib.pyplot as plt

FILE = "fitness_data.csv"

# ==============================
# Initialize File [cite: 32, 41]
# ==============================
if not os.path.exists(FILE):
    df = pd.DataFrame(columns=["Date", "Calories", "Weight", "Workout"])
    df.to_csv(FILE, index=False)


# ==============================
# FUNCTIONS [cite: 34, 35]
# ==============================

def add_data():
    """Captures calories, weight, and workout time, appending them to fitness_data.csv[cite: 36]."""
    try:
        date = datetime.now().strftime("%Y-%m-%d")  # Automatically timestamps each entry [cite: 26]
        calories = float(entry_calories.get())
        weight = float(entry_weight.get())
        workout = float(entry_workout.get())

        df = pd.read_csv(FILE)
        df.loc[len(df)] = [date, calories, weight, workout]
        df.to_csv(FILE, index=False)

        messagebox.showinfo("Success", "Data Added Successfully!")
        clear_fields()

    except:
        # Runtime error handling to manage invalid numeric inputs [cite: 26, 41]
        messagebox.showerror("Error", "Enter valid numbers!")


def clear_fields():
    entry_calories.delete(0, tk.END)
    entry_weight.delete(0, tk.END)
    entry_workout.delete(0, tk.END)
    entry_height.delete(0, tk.END)


def show_data():
    """Display all logs in the text area[cite: 46]."""
    df = pd.read_csv(FILE)

    if df.empty:
        messagebox.showwarning("No Data", "No data available!")
        return

    text_box.delete(1.0, tk.END)
    text_box.insert(tk.END, df.to_string(index=False))


def analyze_data():
    """Computes weekly averages and provides progress feedback[cite: 38]."""
    df = pd.read_csv(FILE)

    if len(df) < 2:
        messagebox.showwarning("Not Enough Data", "Add more entries!")
        return

    df["Date"] = pd.to_datetime(df["Date"])
    weekly_avg = df.groupby(df["Date"].dt.isocalendar().week).mean(numeric_only=True)

    msg = f"Weekly Avg Calories: {weekly_avg['Calories'].mean():.2f}\n"
    msg += f"Weekly Avg Weight: {weekly_avg['Weight'].mean():.2f}\n"
    msg += f"Total Workout: {df['Workout'].sum()} mins\n"

    # Feedback logic [cite: 38]
    if df["Weight"].iloc[-1] < df["Weight"].iloc[0]:
        msg += "\n🔥 Great progress! Weight decreasing!"
    else:
        msg += "\n⚠️ Weight increasing, check diet!"

    messagebox.showinfo("Analysis", msg)


def plot_graph():
    """Uses Matplotlib to render a line plot of weight changes over time[cite: 39]."""
    df = pd.read_csv(FILE)

    if len(df) < 2:
        # Condition check with warning box if entries < 2 [cite: 41]
        messagebox.showwarning("Not Enough Data", "Add more entries to see trends!")
        return

    df["Date"] = pd.to_datetime(df["Date"])

    plt.figure()
    plt.plot(df["Date"], df["Weight"], marker='o')
    plt.title("Weight Progress")
    plt.xlabel("Date")
    plt.ylabel("Weight (kg)")
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()


def calculate_bmi():
    """Calculates Body Mass Index based on user height and weight[cite: 37]."""
    try:
        weight = float(entry_weight.get())
        height = float(entry_height.get())

        # ZeroDivisionError check [cite: 41]
        if height <= 0:
            messagebox.showerror("Error", "Height must be greater than zero!")
            return

        bmi = weight / (height ** 2)

        if bmi < 18.5:
            status = "Underweight"
        elif bmi < 25:
            status = "Normal"
        else:
            status = "Overweight"

        messagebox.showinfo("BMI", f"BMI: {bmi:.2f}\nStatus: {status}")

    except ValueError:
        # Handle non-numeric inputs [cite: 41]
        messagebox.showerror("Error", "Enter valid height & weight!")


# ==============================
# GUI DESIGN [cite: 26, 43]
# ==============================

root = tk.Tk()
root.title("MY FITNESS PAL")  # Updated window title
root.geometry("600x600")
root.config(bg="#1e1e2f")

# Header Label
title = tk.Label(root, text="MY FITNESS PAL", font=("Arial", 22, "bold"), bg="#1e1e2f",
                 fg="white")  # Updated header text
title.pack(pady=10)

frame = tk.Frame(root, bg="#2c2c3e", padx=20, pady=20)
frame.pack(pady=10)

# Labels & Entries [cite: 44]
tk.Label(frame, text="Calories", bg="#2c2c3e", fg="white").grid(row=0, column=0, pady=5)
entry_calories = tk.Entry(frame)
entry_calories.grid(row=0, column=1)

tk.Label(frame, text="Weight (kg)", bg="#2c2c3e", fg="white").grid(row=1, column=0, pady=5)
entry_weight = tk.Entry(frame)
entry_weight.grid(row=1, column=1)

tk.Label(frame, text="Workout (min)", bg="#2c2c3e", fg="white").grid(row=2, column=0, pady=5)
entry_workout = tk.Entry(frame)
entry_workout.grid(row=2, column=1)

tk.Label(frame, text="Height (m)", bg="#2c2c3e", fg="white").grid(row=3, column=0, pady=5)
entry_height = tk.Entry(frame)
entry_height.grid(row=3, column=1)

# Buttons [cite: 45, 47, 48, 49]
btn_frame = tk.Frame(root, bg="#1e1e2f")
btn_frame.pack(pady=10)

tk.Button(btn_frame, text="Add Data", command=add_data, bg="#4CAF50", fg="white", width=12).grid(row=0, column=0,
                                                                                                 padx=5)
tk.Button(btn_frame, text="Show Data", command=show_data, bg="#2196F3", fg="white", width=12).grid(row=0, column=1,
                                                                                                   padx=5)
tk.Button(btn_frame, text="Analyze", command=analyze_data, bg="#FF9800", fg="white", width=12).grid(row=0, column=2,
                                                                                                     padx=5)

tk.Button(btn_frame, text="Graph", command=plot_graph, bg="#9C27B0", fg="white", width=12).grid(row=1, column=0, padx=5,
                                                                                                pady=5)
tk.Button(btn_frame, text="BMI", command=calculate_bmi, bg="#E91E63", fg="white", width=12).grid(row=1, column=1,
                                                                                                 padx=5, pady=5)
tk.Button(btn_frame, text="Clear", command=clear_fields, bg="#f44336", fg="white", width=12).grid(row=1, column=2,
                                                                                                  padx=5, pady=5)

# Text Box for Logs [cite: 46]
text_box = tk.Text(root, height=10, width=70)
text_box.pack(pady=10)

root.mainloop()