#include <LiquidCrystal.h>  // Include the LiquidCrystal library

// Button pins
const int buttonA = 2; // Button for Candidate A
const int buttonB = 3; // Button for Candidate B
const int buttonC = 4; // Button to display results

// Vote counters
int votesA = 0; // Counter for Candidate A
int votesB = 0; // Counter for Candidate B

// Initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Set button pins as input
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(buttonC, INPUT_PULLUP);

  // Initialize the LCD
  lcd.begin(16, 2);

  // Display welcome message
  lcd.setCursor(0, 0);
  lcd.print("  WELCOME TO  ");
  lcd.setCursor(0, 1);
  lcd.print(" EVM MACHINE  ");
  delay(2000); // Display for 2 seconds

  // Clear the LCD and show project info
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("3RD YEAR");
  lcd.setCursor(0, 1);
  lcd.print("PROJECT DEMO");
  delay(2000); // Display for 2 seconds

  // Show voting prompt
  showVotePrompt();
}

void loop() {
  // Check if Button A is pressed
  if (digitalRead(buttonA) == LOW) {
    delay(50); // Debounce delay
    if (digitalRead(buttonA) == LOW) {
      votesA++; // Increment vote for Candidate A
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Voted for A");
      delay(1000); // Display confirmation for 1 second
      showVotePrompt(); // Show voting prompt again
      while (digitalRead(buttonA) == LOW); // Wait for button release
    }
  }

  // Check if Button B is pressed
  if (digitalRead(buttonB) == LOW) {
    delay(50); // Debounce delay
    if (digitalRead(buttonB) == LOW) {
      votesB++; // Increment vote for Candidate B
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Voted for B");
      delay(1000); // Display confirmation for 1 second
      showVotePrompt(); // Show voting prompt again
      while (digitalRead(buttonB) == LOW); // Wait for button release
    }
  }

  // Check if Button C is pressed
  if (digitalRead(buttonC) == LOW) {
    delay(50); // Debounce delay
    if (digitalRead(buttonC) == LOW) {
      showResults(); // Show results
      while (digitalRead(buttonC) == LOW); // Wait for button release
    }
  }
}

void showResults() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A: ");
  lcd.print(votesA); // Display votes for Candidate A
  lcd.print(" B: ");
  lcd.print(votesB); // Display votes for Candidate B
  delay(3000); // Display for 3 seconds

  lcd.clear();
  lcd.setCursor(0, 0);
  // Determine and display the winner
  if (votesA > votesB) {
    lcd.print("A WINS!");
  } else if (votesB > votesA) {
    lcd.print("B WINS!");
  } else {
    lcd.print("IT'S A TIE!");
  }
  delay(2000); // Display result for 2 seconds

  // Reset votes
  votesA = 0;
  votesB = 0;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Votes Reset");
  delay(1000); // Display reset message for 1 second

  showVotePrompt(); // Show voting prompt again
}

void showVotePrompt() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vote A or B"); // Display voting prompt
}
