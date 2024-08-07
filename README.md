# Mastermind Homebrew for Nintendo 3DS

Welcome to the Mastermind Homebrew project! This project is a homebrew application for the Nintendo 3DS that recreates the classic logic game "Mastermind."

## About

Mastermind is a classic code-breaking game where the player must guess a secret combination of digits. The game provides feedback on each guess, indicating how many digits are in the correct position and how many are correct but in the wrong position.

This homebrew application brings the Mastermind experience to your Nintendo 3DS console, allowing you to enjoy this engaging puzzle game directly on your handheld device.

## Features

- **Guessing Game**: Enter a 4-digit combination to guess the secret code.
- **Feedback System**: Receive feedback on each guess with information on correct digits and their positions.
- **Simple Interface**: A user-friendly numeric keypad for input.

## Installation

To install this homebrew application on your Nintendo 3DS, follow these steps:

### Option 1: Using the `.3dsx` File

1. **Download the `.3dsx` File**: Obtain the compiled `.3dsx` file from the [Releases page](https://github.com/KaliLugu/Mastermind-3ds/releases) (replace with your actual repository URL).

2. **Place the `.3dsx` File**:
   - Copy the `.3dsx` file to the `3ds` folder on your SD card. This folder should be located in the root directory of your SD card.

3. **Launch the Application**:
   - Use a homebrew launcher such as Homebrew Launcher or TWiLight Menu++ to find and launch the Mastermind game from the menu.

### Option 2: Compiling from Source

1. **Clone the Repository**:
   - Clone this repository using Git:
     ```sh
     git clone https://github.com/KaliLugu/Mastermind-3ds.git
     ```

2. **Install Dependencies**:
   - Ensure you have the necessary tools and libraries for compiling 3DS homebrew applications. This typically includes devkitPro and its associated tools.

3. **Build the Project**:
   - Navigate to the project directory and compile the source code:
     ```sh
     cd Mastermind-3ds
     make
     ```
   - This will generate the `.3dsx` file

4. **Transfer the `.3dsx` File**:
   - Copy the generated `.3dsx` file to the `3ds` folder on your SD card.

5. **Launch the Application**:
   - Use a homebrew launcher to find and launch the Mastermind game from the menu.

## Usage

1. **Start the Game**: Launch the Mastermind homebrew from your 3DS homebrew launcher.
2. **Enter Your Guess**: Press the "B" button to enter a 4-digit guess using the numeric keypad.
3. **Receive Feedback**: The game will display feedback on your guess, indicating how many digits are correctly placed and how many are correct but misplaced.
4. **Guess Again**: Continue guessing until you find the correct combination or exhaust your attempts.

## Acknowledgements

- **Mastermind Game**: Original concept and rules.
- **3DS Homebrew Community**: For providing the tools and support for developing homebrew applications.

## Contact

If you have any questions or need further assistance, feel free to contact [contact.kalilugu@gmail.com](mailto:contact.kalilugu@gmail.com).

Enjoy the game and have fun breaking codes!
