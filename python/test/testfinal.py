import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

class FitnessTracker:
    def __init__(self, filename='fitness_activities.csv'):
        self.filename = filename
        try:
            self.data = pd.read_csv(filename)
        except FileNotFoundError:
            self.data = pd.DataFrame(columns=['Date', 'Activity Type', 'Duration (Minutes)', 'Calories Burned'])

    def log_activity(self, date, activity_type, duration, calories):
        if duration <= 0 or calories <= 0:
            print("Error: Duration and Calories must be positive numbers.")
            return

        new_activity = pd.DataFrame([{
            'Date': date,
            'Activity Type': activity_type,
            'Duration (Minutes)': duration,
            'Calories Burned': calories
        }])
        self.data = pd.concat([self.data, new_activity], ignore_index=True)
        self.data.to_csv(self.filename, index=False)
        print("Activity logged successfully.")

    def calculate_metrics(self):
        total_calories = self.data['Calories Burned'].sum()
        avg_duration = self.data['Duration (Minutes)'].mean()
        freq_by_activity = self.data['Activity Type'].value_counts()
        print("\n--- Fitness Metrics ---")
        print(f"Total Calories Burned: {total_calories}")
        print(f"Average Duration (Minutes): {avg_duration:.2f}")
        print("Activity Frequency:\n", freq_by_activity)

    def filter_activities(self, condition):
        filtered_data = self.data.query(condition)
        print("\n--- Filtered Activities ---")
        print(filtered_data)
        return filtered_data

    def generate_report(self):
        print("\n--- Fitness Report ---")
        print(self.data.describe(include='all'))
        print("\nSample Data:\n", self.data.head())

    def visualize_data(self):
        plt.figure(figsize=(14, 8))
        
        plt.subplot(2, 2, 1)
        sns.barplot(x='Activity Type', y='Duration (Minutes)', data=self.data, estimator=np.sum)
        plt.title('Total Time Spent per Activity')

        plt.subplot(2, 2, 2)
        self.data['Date'] = pd.to_datetime(self.data['Date'])
        daily_calories = self.data.groupby('Date')['Calories Burned'].sum()
        plt.plot(daily_calories.index, daily_calories.values, marker='o')
        plt.title('Calories Burned Over Time')
        plt.xticks(rotation=90)

        plt.subplot(2, 2, 3)
        activity_counts = self.data['Activity Type'].value_counts()
        plt.pie(activity_counts, labels=activity_counts.index, autopct='%1.1f%%')
        plt.title('Activity Distribution')

        plt.subplot(2, 2, 4)
        correlation = self.data[['Duration (Minutes)', 'Calories Burned']].corr()
        sns.heatmap(correlation, annot=True, cmap='coolwarm')
        plt.title('Correlation Heatmap')

        plt.tight_layout()
        plt.show()

def main():
    tracker = FitnessTracker()

    while True:
        print("\n--- Personal Fitness Tracker ---")
        print("1. Log Activity")
        print("2. View Metrics")
        print("3. Filter Activities")
        print("4. Generate Report")
        print("5. Visualize Data")
        print("6. Exit")
        
        choice = input("Enter your choice: ")        
        if choice == '1':
            date = input("Enter date (YYYY-MM-DD): ")
            activity_type = input("Enter activity type: ")
            duration = float(input("Enter duration (minutes): "))
            calories = float(input("Enter calories burned: "))
            tracker.log_activity(date, activity_type, duration, calories)

        elif choice == '2':
            tracker.calculate_metrics()

        elif choice == '3':
            condition = input("Enter filter condition (e.g., `Duration (Minutes)` > 30): ")
            tracker.filter_activities(condition)

        elif choice == '4':
            tracker.generate_report()

        elif choice == '5':
            tracker.visualize_data()

        elif choice == '6':
            print("Exiting")
            break

        else:
            print("Invalid choice. Try again.")

if __name__ == "__main__":
    main()