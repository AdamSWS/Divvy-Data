# Divvy Bike Ride Data Analysis

## Overview
This C++ program is designed to analyze Divvy bike ride information. It processes data from CSV files to provide insights into various aspects of bike rides, such as total mileage, member vs. casual riders, weekday vs. weekend usage, and identifying the closest station based on user input.

## Features
- **Data Import and Cleaning**: Reads ride data from CSV files and cleans the data for analysis.
- **Mileage Calculation**: Calculates total and average trip distances, and identifies the longest trip.
- **User Classification**: Analyzes the percentage of rides taken by members versus casual riders.
- **Usage Analysis**: Compares bike usage between weekdays and weekends.
- **Proximity Finder**: Finds the closest Divvy station to a given latitude and longitude.
- **Interactive Menu**: Provides a user-friendly menu for navigating different functionalities.

## How to Run
1. **Compile the Program**: Use a C++ compiler to compile the source code.
2. **Run the Executable**: Start the program to interact with the menu.
3. **Choose Options**: Select from the menu to import data, analyze rides, etc.
4. **Input Data**: When prompted, input relevant data such as file paths or coordinates.

## Menu Options
- **1**: Import data from a CSV file and display ride totals.
- **2**: Display overall trip information including mileage.
- **3**: Show percentage distribution of members vs. casual riders.
- **4**: Analyze and compare weekday vs weekend usage.
- **5**: Find the closest Divvy station to a specified location.
- **6**: Exit the program.

## Installation
Ensure you have a C++ compiler installed (like g++). Compile the source code using a command like `g++ -o divvyanalysis divvyanalysis.cpp`. Run the compiled executable.

## Dependencies
- C++ Standard Library
- A C++11 (or newer) compliant compiler

## Contributing
Feel free to fork the repository, make improvements, and submit pull requests. Open issues for any bugs or feature requests.

## License
This project is open source and available under the MIT License.

## Acknowledgments
- Developer: Adam Saad Walid Shaar
- Data Source: Divvy Bikes
