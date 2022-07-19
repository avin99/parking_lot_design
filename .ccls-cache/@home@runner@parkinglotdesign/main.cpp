#include <bits/stdc++.h>
using namespace std;

class Vehicle {
public:
  string registrationNumber;
  int driverAge;
  Vehicle(string registrationNumber, int driverAge) {
    this->registrationNumber = registrationNumber;
    this->driverAge = driverAge;
  }
  int getDriverAge() { return this->driverAge; }
  string getRegistrationNumber() { return this->registrationNumber; }
};

class ParkingLot {
public:
  int noOfSlots;

  vector<int> availableSlots;

  map<int, Vehicle *> mapSlotAndvehicle;

  map<string, int> mapRegNoAndSlot;

  map<int, vector<string>> mapAgeAndRegNo;

  ParkingLot() { this->noOfSlots = 0; }
  void createParkingLot(int slots) {
    noOfSlots = slots;
    for (int i = 1; i <= noOfSlots; i++) {
      availableSlots.push_back(i);
    }
    cout << "Created parking of " << noOfSlots << " slots";
  }

  void park(string reg_No, int age) {
    if (noOfSlots == 0) {
      cout << "The Parking Lot is not Created";
    } else if (mapSlotAndvehicle.size() == noOfSlots) {
      cout << "The Parking Lot is currently full";
    } else if (mapRegNoAndSlot.find(reg_No) != mapRegNoAndSlot.end()) {
      cout << "Some Vehicle alreday Present in the Parking Lot";
    } else {
      sort(availableSlots.begin(), availableSlots.end());
      int nearestAvailableSlot = availableSlots[0];

      Vehicle *vehicle = new Vehicle(reg_No, age);

      mapSlotAndvehicle[nearestAvailableSlot] = vehicle;
      mapRegNoAndSlot[reg_No] = nearestAvailableSlot;

      if (mapAgeAndRegNo.find(age) != mapAgeAndRegNo.end()) {
        vector<string> registrationList = mapAgeAndRegNo[age];
        registrationList.push_back(reg_No);
        mapAgeAndRegNo[age] = registrationList;

      } else {
        vector<string> registrationList;
        registrationList.push_back(reg_No);
        mapAgeAndRegNo[age] = registrationList;
      }
      availableSlots.erase(availableSlots.begin());
      cout << "Car with vehicle registration number" << reg_No
           << " has been parked at slot number " << nearestAvailableSlot;
    }
  }

  void leave(int slot) {
    if (noOfSlots == 0) {
      cout << "The Parking Lot is not Created";
    } else if (availableSlots.size() == noOfSlots) {
      cout << "The Parking Lot is Empty";
    } else {
      Vehicle *vehicleToLeave = mapSlotAndvehicle[slot];
      if (vehicleToLeave == NULL) {
        cout << "There is no vehicle in that slot";
      } else {
        mapSlotAndvehicle.erase(slot);
        mapRegNoAndSlot.erase(vehicleToLeave->getRegistrationNumber());

        vector<string> regNoList =
            mapAgeAndRegNo[vehicleToLeave->getDriverAge()];

        if (find(regNoList.begin(), regNoList.end(),
                 vehicleToLeave->getRegistrationNumber()) != regNoList.end()) {
          for (auto regNo = regNoList.begin(); regNo != regNoList.end();
               regNo++) {
            if (*regNo == vehicleToLeave->getRegistrationNumber()) {
              regNoList.erase(regNo);
              break;
            }
          }
          mapAgeAndRegNo[vehicleToLeave->getDriverAge()] = regNoList;
        }
        availableSlots.push_back(slot);
        cout << "Slot number " << slot
             << " vacated, the car with vehicle registration number "
             << vehicleToLeave->getRegistrationNumber()
             << "left the space, the driver of the car was of age "
             << vehicleToLeave->getDriverAge();
      }
    }
  }
  void getSlotNumberFromVehicleRegistrationPlate(string regi_No) {
    if (noOfSlots == 0) {
      cout << "The Parking Lot is not Created";
    } else if (mapRegNoAndSlot.find(regi_No) != mapRegNoAndSlot.end()) {
      cout << mapRegNoAndSlot[regi_No];
    } else {
      cout << "The Vehicle with registration number " << regi_No
           << " not found in Parking Lot";
    }
  }

  void getSlotNumbersFromDriverAge(int age) {
    if (noOfSlots == 0) {
      cout << "The Parking Lot is not Created";
    } else if (mapAgeAndRegNo.find(age) != mapAgeAndRegNo.end() &&
               mapAgeAndRegNo[age].size() > 0) {
      string slots = "";
      for (string reg_No : mapAgeAndRegNo[age]) {
        slots = slots + to_string(mapRegNoAndSlot[reg_No]) + ",";
      }
      cout << slots.substr(0, slots.length() - 1);
    } else {
      cout << " ";
    }
  }

  void getVehicleRegistrationNumbersFromAge(int age) {
    if (noOfSlots == 0) {
      cout << "The Parking Lot is not Created";
    } else if (mapAgeAndRegNo.find(age) != mapAgeAndRegNo.end() &&
               mapAgeAndRegNo[age].size() > 0) {
      string register_Numbers = "";
      for (string reg_No : mapAgeAndRegNo[age]) {
        register_Numbers = register_Numbers + reg_No + ",";
      }
      cout << register_Numbers.substr(0, register_Numbers.length() - 1);
    } else {
      cout << " ";
    }
  }
};

int main() {
  string filename("input.txt");
  vector<string> lines;
  string line;

  ifstream input_file(filename);
  if (!input_file.is_open()) {
    cerr << "Could not open the file - '" << filename << "'" << endl;
    return EXIT_FAILURE;
  }

  while (getline(input_file, line)) {
    lines.push_back(line);
  }
  ParkingLot *p1 = new ParkingLot;
  for (int i = 0; i < lines.size(); i++) {
    string newLine = lines[i];
    vector<string> input;
    stringstream ss(newLine);
    string word;
    while (ss >> word) {
      input.push_back(word);
    }
    cout << endl;

    switch (input.size()) {
    case 0:
    case 1:
    case 3:
      cout << "invalid Command";
      break;

    case 2:
      if (input[0] == "Create_parking_lot")
        p1->createParkingLot(stoi(input[1]));
      else if (input[0] == "Leave")
        p1->leave(stoi(input[1]));

      else if (input[0] == "Slot_numbers_for_driver_of_age") {
        int age = stoi(input[1]);
        p1->getSlotNumbersFromDriverAge(age);
      } else if (input[0] == "Slot_number_for_car_with_number") {
        string reg_No = input[1];
        p1->getSlotNumberFromVehicleRegistrationPlate(reg_No);
      } else if (input[0] == "Vehicle_registration_number_for_driver_of_age") {
        int age = stoi(input[1]);
        p1->getVehicleRegistrationNumbersFromAge(age);
      } else {
        cout << "invalid Command";
      }
      break;

    case 4:
      if (input[0] == "Park" && input[2] == "driver_age" &&
          input[1].length() == 13) {
        int age = stoi(input[3]);
        string reg_No = input[1];
        p1->park(reg_No, age);
      }

      break;
    }
  }
}